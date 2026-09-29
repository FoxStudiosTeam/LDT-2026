//! rail_live_tuner.rs — Real-time RailOrt GUI Tuner with Triple Buffer, 50-frame History Scrubbing & Standalone Bag Dataset Streaming
//!
//! Запуск:
//!   cargo run --release --bin rail_live_tuner
//!   cargo run --release --bin rail_live_tuner -- D:\Projects\LDT-2026\dataset\doubleT_obstacle

use std::collections::VecDeque;
use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicBool, AtomicU64, Ordering};
use std::sync::{Arc, Mutex, RwLock};
use std::time::{Duration, Instant};

use eframe::egui::{self, Color32, ColorImage, Key, TextureOptions};
use rerun::{Color, Points3D, Radius, RecordingStream, RecordingStreamBuilder};
use rusqlite::OpenFlags;

use rust_listener::debug::helper::DebugStream;
use rust_listener::engine::types::{pin_ptr, pin_u16_ptr};
use rust_listener::ENV;

use shared::rail_detection::{LidarGeometry, ObstacleDetectionMode};
use shared::rail_ort::{DetectionResultOrt, RailOrtConfig, RailOrtDetector};
use shared::range_image::{Pandar128VerticalGeometry, RangeImage};
use shared::transport::PointCloud2;
use shared::types::{is_zero_point, AppPointCloud, ProcessingQueue, SIZE};

// ─────────────────────────────────────────────────────────────
// Color map and rasterization helpers
// ─────────────────────────────────────────────────────────────

fn turbo_rgb(val: f32) -> [u8; 3] {
    let x = val.clamp(0.0, 1.0);
    let r = 0.1357 + x * (4.61539 - x * (42.6603 - x * (132.131 - x * (161.076 - x * 65.0))));
    let g = 0.0914 + x * (2.19418 + x * (4.87492 - x * (14.106 - x * (4.672 - x * 10.0))));
    let b = 0.1067 + x * (12.5833 - x * (78.368 + x * (195.127 - x * (204.654 - x * 75.0))));
    [
        (r.clamp(0.0, 1.0) * 255.0) as u8,
        (g.clamp(0.0, 1.0) * 255.0) as u8,
        (b.clamp(0.0, 1.0) * 255.0) as u8,
    ]
}

fn draw_dot_rgb(
    rgb: &mut [u8],
    w: usize,
    h: usize,
    cx: i32,
    cy: i32,
    radius: i32,
    color: [u8; 3],
) {
    for dy in -radius..=radius {
        for dx in -radius..=radius {
            if dx * dx + dy * dy <= radius * radius {
                let px = cx + dx;
                let py = cy + dy;
                if px >= 0 && px < w as i32 && py >= 0 && py < h as i32 {
                    let idx = ((py as usize) * w + (px as usize)) * 3;
                    rgb[idx] = color[0];
                    rgb[idx + 1] = color[1];
                    rgb[idx + 2] = color[2];
                }
            }
        }
    }
}

fn draw_line_rgb(
    rgb: &mut [u8],
    w: usize,
    h: usize,
    pts: &[(i32, i32)],
    color: [u8; 3],
    thickness: i32,
) {
    if pts.len() < 2 {
        return;
    }
    for i in 0..pts.len() - 1 {
        let (mut x0, mut y0) = pts[i];
        let (x1, y1) = pts[i + 1];
        let dx = (x1 - x0).abs();
        let dy = -(y1 - y0).abs();
        let sx = if x0 < x1 { 1 } else { -1 };
        let sy = if y0 < y1 { 1 } else { -1 };
        let mut err = dx + dy;

        loop {
            draw_dot_rgb(rgb, w, h, x0, y0, thickness, color);
            if x0 == x1 && y0 == y1 {
                break;
            }
            let e2 = 2 * err;
            if e2 >= dy {
                err += dy;
                x0 += sx;
            }
            if e2 <= dx {
                err += dx;
                y0 += sy;
            }
        }
    }
}

fn draw_rect_rgb(
    rgb: &mut [u8],
    w: usize,
    h: usize,
    x0: i32,
    y0: i32,
    x1: i32,
    y1: i32,
    color: [u8; 3],
    thickness: i32,
) {
    let p0 = (x0, y0);
    let p1 = (x1, y0);
    let p2 = (x1, y1);
    let p3 = (x0, y1);
    draw_line_rgb(rgb, w, h, &[p0, p1, p2, p3, p0], color, thickness);
}

// ─────────────────────────────────────────────────────────────
// PointCloud2 Self-Contained Parser (Layout & Coordinates)
// ─────────────────────────────────────────────────────────────

#[derive(Debug, Clone, Copy)]
pub struct PointLayout {
    pub x_offset: usize,
    pub y_offset: usize,
    pub z_offset: usize,
    pub intensity_offset: Option<usize>,
    pub ring_offset: Option<usize>,
}

fn extract_point_layout(cloud: &PointCloud2) -> Result<PointLayout, String> {
    let find_field = |name: &str| cloud.fields.iter().find(|f| f.name == name);

    let x = find_field("x").ok_or("Field 'x' not found")?;
    let y = find_field("y").ok_or("Field 'y' not found")?;
    let z = find_field("z").ok_or("Field 'z' not found")?;

    let intensity = find_field("intensity").map(|f| f.offset as usize);
    let ring = find_field("ring")
        .or_else(|| find_field("channel"))
        .or_else(|| find_field("laser_id"))
        .map(|f| f.offset as usize);

    Ok(PointLayout {
        x_offset: x.offset as usize,
        y_offset: y.offset as usize,
        z_offset: z.offset as usize,
        intensity_offset: intensity,
        ring_offset: ring,
    })
}

fn parse_point_cloud_into_buffer(
    message: &PointCloud2,
    cloud: &Arc<RwLock<AppPointCloud>>,
    layout: &PointLayout,
) -> Result<(), String> {
    let width = message.width as usize;
    let height = message.height as usize;
    let point_step = message.point_step as usize;

    if width == 0 || height == 0 || message.data.is_empty() {
        return Ok(());
    }

    let mut cloud_guard = cloud.write().map_err(|e| e.to_string())?;
    if !cloud_guard.can_write {
        return Ok(());
    }

    let write_state = ProcessingQueue::WRITE;
    cloud_guard.clear(write_state);

    let total_points = (width * height).min(AppPointCloud::CAP);
    let is_bigendian = message.is_bigendian;
    let data = &message.data;
    let point_chunks = data.chunks_exact(point_step).take(total_points);

    let x_off = layout.x_offset;
    let y_off = layout.y_offset;
    let z_off = layout.z_offset;
    let vertical_geo = Pandar128VerticalGeometry::new();

    let mut i = 0;
    for point_buf in point_chunks {
        if point_buf.len() < point_step {
            break;
        }

        let x_bytes: [u8; 4] = point_buf[x_off..x_off + 4].try_into().unwrap_or_default();
        let y_bytes: [u8; 4] = point_buf[y_off..y_off + 4].try_into().unwrap_or_default();
        let z_bytes: [u8; 4] = point_buf[z_off..z_off + 4].try_into().unwrap_or_default();

        let px = u32::from_ne_bytes(x_bytes);
        let py = u32::from_ne_bytes(y_bytes);
        let pz = u32::from_ne_bytes(z_bytes);

        let (x, y, z) = if is_bigendian {
            (
                f32::from_bits(u32::from_be(px)),
                f32::from_bits(u32::from_be(py)),
                f32::from_bits(u32::from_be(pz)),
            )
        } else {
            (
                f32::from_bits(u32::from_le(px)),
                f32::from_bits(u32::from_le(py)),
                f32::from_bits(u32::from_le(pz)),
            )
        };

        let intensity = if let Some(i_off) = layout.intensity_offset {
            if i_off + 4 <= point_buf.len() {
                let i_bytes: [u8; 4] = point_buf[i_off..i_off + 4].try_into().unwrap_or_default();
                let pi = u32::from_ne_bytes(i_bytes);
                if is_bigendian {
                    f32::from_bits(u32::from_be(pi))
                } else {
                    f32::from_bits(u32::from_le(pi))
                }
            } else {
                0.0
            }
        } else {
            0.0
        };

        let ring = if let Some(r_off) = layout.ring_offset {
            if r_off + 2 <= point_buf.len() {
                let r_bytes: [u8; 2] = point_buf[r_off..r_off + 2].try_into().unwrap_or_default();
                let pr = u16::from_ne_bytes(r_bytes);
                if is_bigendian {
                    u16::from_be(pr)
                } else {
                    u16::from_le(pr)
                }
            } else {
                0
            }
        } else {
            let r2 = x * x + y * y + z * z;
            if r2 < 0.04 {
                0
            } else {
                let r = r2.sqrt();
                let pitch = (z / r).clamp(-1.0, 1.0).asin();
                vertical_geo.nearest_channel(pitch) as u16
            }
        };

        if x.is_finite() && y.is_finite() && z.is_finite() {
            cloud_guard.x[write_state][i] = x;
            cloud_guard.y[write_state][i] = y;
            cloud_guard.z[write_state][i] = z;
            cloud_guard.intensity[write_state][i] = intensity;
            cloud_guard.ring[write_state][i] = ring;
            cloud_guard.x[write_state].length += 1;
            cloud_guard.y[write_state].length += 1;
            cloud_guard.z[write_state].length += 1;
            cloud_guard.intensity[write_state].length += 1;
            cloud_guard.ring[write_state].length += 1;

            i += 1;
        }
    }

    cloud_guard.width[write_state] = message.width;
    cloud_guard.height[write_state] = message.height;
    cloud_guard.timestamp[write_state] =
        message.header.stamp.sec as i64 * 1_000_000_000 + message.header.stamp.nanosec as i64;

    cloud_guard.change_state(write_state, ProcessingQueue::NEXT);
    Ok(())
}

// ─────────────────────────────────────────────────────────────
// Layer & Painter configuration
// ─────────────────────────────────────────────────────────────

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ImageLayerMode {
    Depth,
    Intensity,
    Blend,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum IntensityColormap {
    Grayscale,
    Turbo,
}

#[derive(Clone, Copy, Debug)]
pub struct LayerViewConfig {
    pub mode: ImageLayerMode,
    pub intensity_colormap: IntensityColormap,
    pub contrast_depth: f32,
    pub contrast_intensity: f32,
    pub blend: f32,
}

impl Default for LayerViewConfig {
    fn default() -> Self {
        Self {
            mode: ImageLayerMode::Depth,
            intensity_colormap: IntensityColormap::Grayscale,
            contrast_depth: 200.0,
            contrast_intensity: 20.0,
            blend: 0.5,
        }
    }
}

struct EguiRangePainter {
    scale: usize,
}

impl EguiRangePainter {
    pub fn new(scale: usize) -> Self {
        Self { scale }
    }

    pub fn paint(
        &self,
        frame: &RangeImage,
        res: Option<&DetectionResultOrt>,
        geo: &LidarGeometry,
        layer_cfg: &LayerViewConfig,
    ) -> ColorImage {
        let w = frame.width;
        let h = frame.height;
        let out_w = w * self.scale;
        let out_h = h * self.scale;

        let mut rgb = vec![0u8; out_w * out_h * 3];
        let has_intensity = !frame.intensity.is_empty();

        // 1. Colorize pixels based on selected layer mode
        for r in 0..h {
            for c in 0..w {
                let depth_val = frame.data[r * w + c];
                let int_val = if has_intensity {
                    frame.get_intensity(r, c)
                } else {
                    0.0
                };

                let depth_color = if depth_val <= 0.0 {
                    [10, 12, 16]
                } else {
                    let norm = (depth_val / layer_cfg.contrast_depth.max(1.0)).clamp(0.0, 1.0);
                    turbo_rgb(norm)
                };

                let int_norm = (int_val / layer_cfg.contrast_intensity.max(0.1)).clamp(0.0, 1.0);
                let int_color = if int_val <= 0.0 {
                    [10, 12, 16]
                } else {
                    match layer_cfg.intensity_colormap {
                        IntensityColormap::Grayscale => {
                            let g = (int_norm * 255.0).round() as u8;
                            [g, g, g]
                        }
                        IntensityColormap::Turbo => turbo_rgb(int_norm),
                    }
                };

                let color = match layer_cfg.mode {
                    ImageLayerMode::Depth => depth_color,
                    ImageLayerMode::Intensity => {
                        if !has_intensity {
                            [25, 25, 30]
                        } else {
                            int_color
                        }
                    }
                    ImageLayerMode::Blend => {
                        if !has_intensity || (depth_val <= 0.0 && int_val <= 0.0) {
                            depth_color
                        } else if depth_val <= 0.0 {
                            int_color
                        } else if int_val <= 0.0 {
                            depth_color
                        } else {
                            let a = layer_cfg.blend.clamp(0.0, 1.0);
                            let inv_a = 1.0 - a;
                            [
                                (depth_color[0] as f32 * inv_a + int_color[0] as f32 * a).round()
                                    as u8,
                                (depth_color[1] as f32 * inv_a + int_color[1] as f32 * a).round()
                                    as u8,
                                (depth_color[2] as f32 * inv_a + int_color[2] as f32 * a).round()
                                    as u8,
                            ]
                        }
                    }
                };

                for sy in 0..self.scale {
                    for sx in 0..self.scale {
                        let idx = ((r * self.scale + sy) * out_w + (c * self.scale + sx)) * 3;
                        rgb[idx] = color[0];
                        rgb[idx + 1] = color[1];
                        rgb[idx + 2] = color[2];
                    }
                }
            }
        }

        // 2. Draw 2D track overlays for RailOrt
        if let Some(r) = res {
            let to_px = |xs: &[f32], ys: &[f32], zs: &[f32]| -> Vec<(i32, i32)> {
                let mut out = Vec::new();
                for i in 0..xs.len() {
                    let (row, col) = geo.xyz_to_row_col(-ys[i], xs[i], zs[i]);
                    if row >= 0 && (row as usize) < h && col >= 0 && (col as usize) < w {
                        out.push((
                            (col as usize * self.scale) as i32,
                            (row as usize * self.scale) as i32,
                        ));
                    }
                }
                out
            };

            let pts_c = to_px(&r.x_curve, &r.y_center, &r.z_center);
            let pts_l = to_px(&r.x_left, &r.y_left, &r.z_center);
            let pts_r = to_px(&r.x_right, &r.y_right, &r.z_center);

            // Left rail (Cyan)
            draw_line_rgb(&mut rgb, out_w, out_h, &pts_l, [30, 210, 255], 2);
            // Right rail (Orange)
            draw_line_rgb(&mut rgb, out_w, out_h, &pts_r, [255, 90, 30], 2);
            // Centerline (Bright Green)
            draw_line_rgb(&mut rgb, out_w, out_h, &pts_c, [0, 255, 60], 2);

            // Sleepers (Cross ties every 4 points)
            for i in (0..r.x_curve.len()).step_by(4) {
                let (row_l, col_l) = geo.xyz_to_row_col(-r.y_left[i], r.x_left[i], r.z_center[i]);
                let (row_r, col_r) = geo.xyz_to_row_col(-r.y_right[i], r.x_right[i], r.z_center[i]);
                if row_l >= 0
                    && (row_l as usize) < h
                    && col_l >= 0
                    && (col_l as usize) < w
                    && row_r >= 0
                    && (row_r as usize) < h
                    && col_r >= 0
                    && (col_r as usize) < w
                {
                    let p1 = (
                        (col_l as usize * self.scale) as i32,
                        (row_l as usize * self.scale) as i32,
                    );
                    let p2 = (
                        (col_r as usize * self.scale) as i32,
                        (row_r as usize * self.scale) as i32,
                    );
                    draw_line_rgb(&mut rgb, out_w, out_h, &[p1, p2], [180, 220, 180], 1);
                }
            }

            // Extrapolation (Magenta)
            if !r.x_ext.is_empty() {
                let ext_c = to_px(&r.x_ext, &r.y_ext, &r.z_ext);
                let ext_l = to_px(&r.x_ext_l, &r.y_ext_l, &r.z_ext);
                let ext_r = to_px(&r.x_ext_r, &r.y_ext_r, &r.z_ext);

                draw_line_rgb(&mut rgb, out_w, out_h, &ext_c, [255, 0, 255], 2);
                draw_line_rgb(&mut rgb, out_w, out_h, &ext_l, [200, 50, 200], 1);
                draw_line_rgb(&mut rgb, out_w, out_h, &ext_r, [200, 50, 200], 1);
            }

            // 3D Shapecast projected to 2D
            let shapecast_3d = r.shapecast_wireframe_3d();
            let shapecast_col = r.shapecast_color();
            for strip in shapecast_3d {
                let mut px_strip: Vec<(i32, i32)> = Vec::new();
                for pt in strip {
                    let (row, col) = geo.xyz_to_row_col(-pt[1], pt[0], pt[2]);
                    if row >= 0 && (row as usize) < h && col >= 0 && (col as usize) < w {
                        px_strip.push((
                            (col as usize * self.scale) as i32,
                            (row as usize * self.scale) as i32,
                        ));
                    }
                }
                draw_line_rgb(&mut rgb, out_w, out_h, &px_strip, shapecast_col, 1);
            }

            // Detected discrete points
            for p in &r.points {
                let (row_l, col_l) = geo.xyz_to_row_col(-p.y_left, p.x_left, p.z_left);
                let (row_r, col_r) = geo.xyz_to_row_col(-p.y_right, p.x_right, p.z_right);

                if row_l >= 0 && (row_l as usize) < h && col_l >= 0 && (col_l as usize) < w {
                    draw_dot_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        (col_l as usize * self.scale) as i32,
                        (row_l as usize * self.scale) as i32,
                        2,
                        [0, 255, 255],
                    );
                }
                if row_r >= 0 && (row_r as usize) < h && col_r >= 0 && (col_r as usize) < w {
                    draw_dot_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        (col_r as usize * self.scale) as i32,
                        (row_l as usize * self.scale) as i32,
                        2,
                        [255, 120, 0],
                    );
                }
            }

            // 7. Detected obstacles 2D bounding boxes
            for o in &r.obstacles {
                let col = if o.is_critical {
                    [255, 30, 30]
                } else {
                    [255, 170, 0]
                };
                let x0 = (o.bbox_2d[0] * self.scale) as i32;
                let y0 = (o.bbox_2d[1] * self.scale) as i32;
                let x1 = ((o.bbox_2d[2] + 1) * self.scale) as i32;
                let y1 = ((o.bbox_2d[3] + 1) * self.scale) as i32;

                draw_rect_rgb(&mut rgb, out_w, out_h, x0, y0, x1, y1, col, 2);
            }
        }

        ColorImage::from_rgb([out_w, out_h], &rgb)
    }
}

// ─────────────────────────────────────────────────────────────
// Frame Snapshot & 50-frame Ring History
// ─────────────────────────────────────────────────────────────

#[derive(Clone)]
pub struct SnapshotFrame {
    pub frame_idx: usize,
    pub timestamp_ns: i64,
    pub width: usize,
    pub height: usize,
    pub xs: Vec<f32>,
    pub ys: Vec<f32>,
    pub zs: Vec<f32>,
    pub intensity: Vec<f32>,
    pub ring: Vec<u16>,
    pub range_image: RangeImage,
    pub detection_result: Option<DetectionResultOrt>,
    pub cropped_tunnel: Vec<Vec<[f32; 3]>>,
}

pub struct HistoryBuffer {
    pub frames: VecDeque<SnapshotFrame>,
    pub max_capacity: usize,
}

impl HistoryBuffer {
    pub fn new(max_capacity: usize) -> Self {
        Self {
            frames: VecDeque::with_capacity(max_capacity),
            max_capacity,
        }
    }

    pub fn push(&mut self, frame: SnapshotFrame) {
        if self.frames.len() >= self.max_capacity {
            self.frames.pop_front();
        }
        self.frames.push_back(frame);
    }

    pub fn clear(&mut self) {
        self.frames.clear();
    }

    pub fn len(&self) -> usize {
        self.frames.len()
    }

    pub fn is_empty(&self) -> bool {
        self.frames.is_empty()
    }

    pub fn get(&self, idx: usize) -> Option<&SnapshotFrame> {
        self.frames.get(idx)
    }

    pub fn get_mut(&mut self, idx: usize) -> Option<&mut SnapshotFrame> {
        self.frames.get_mut(idx)
    }
}

// ─────────────────────────────────────────────────────────────
// Bag Dataset Streamer & Discovery
// ─────────────────────────────────────────────────────────────

#[derive(Clone, Debug)]
pub struct DatasetItem {
    pub name: String,
    pub path: PathBuf,
}

#[derive(Default, Clone, Debug)]
pub struct BagStreamerStatus {
    pub dataset_name: String,
    pub current_file_name: String,
    pub current_file_idx: usize,
    pub total_files: usize,
    pub frame_in_file: usize,
    pub total_frames_sent: u64,
}

pub struct BagStreamer {
    pub active_path: Arc<Mutex<Option<PathBuf>>>,
    pub is_paused: Arc<AtomicBool>,
    pub loop_bag: Arc<AtomicBool>,
    pub playback_fps: Arc<Mutex<f32>>,
    pub status: Arc<Mutex<BagStreamerStatus>>,
    pub new_path_signal: Arc<AtomicBool>,
    pub total_frames: Arc<AtomicU64>,
}

impl BagStreamer {
    pub fn new() -> Self {
        Self {
            active_path: Arc::new(Mutex::new(None)),
            // Starts PAUSED by default so user can select bag first!
            is_paused: Arc::new(AtomicBool::new(true)),
            loop_bag: Arc::new(AtomicBool::new(true)),
            playback_fps: Arc::new(Mutex::new(10.0)),
            status: Arc::new(Mutex::new(BagStreamerStatus::default())),
            new_path_signal: Arc::new(AtomicBool::new(false)),
            total_frames: Arc::new(AtomicU64::new(0)),
        }
    }

    pub fn spawn_playback_thread(
        streamer: Arc<Self>,
        live_cloud: Arc<RwLock<AppPointCloud>>,
        frame_counter: Arc<AtomicU64>,
    ) {
        std::thread::spawn(move || {
            let mut cached_layout: Option<PointLayout> = None;
            let mut current_path: Option<PathBuf> = None;

            loop {
                // Check if a new path was requested
                if streamer.new_path_signal.swap(false, Ordering::SeqCst) || current_path.is_none() {
                    let next = streamer.active_path.lock().unwrap().clone();
                    if next != current_path {
                        current_path = next;
                        cached_layout = None;
                    }
                }

                let Some(ref target_path) = current_path else {
                    std::thread::sleep(Duration::from_millis(50));
                    continue;
                };

                // Wait if paused before opening files
                while streamer.is_paused.load(Ordering::Relaxed) {
                    if streamer.new_path_signal.load(Ordering::Relaxed) {
                        break;
                    }
                    std::thread::sleep(Duration::from_millis(30));
                }

                if streamer.new_path_signal.load(Ordering::Relaxed) {
                    continue;
                }

                let files = resolve_db3_files(target_path);
                if files.is_empty() {
                    std::thread::sleep(Duration::from_millis(100));
                    continue;
                }

                let total_files = files.len();
                let ds_name = target_path
                    .file_name()
                    .map(|n| n.to_string_lossy().to_string())
                    .unwrap_or_else(|| "dataset".to_string());

                let mut should_restart = false;

                for (file_idx, db_path) in files.iter().enumerate() {
                    if streamer.new_path_signal.load(Ordering::Relaxed) {
                        should_restart = true;
                        break;
                    }

                    let file_name = db_path
                        .file_name()
                        .map(|n| n.to_string_lossy().to_string())
                        .unwrap_or_default();

                    let conn = match rusqlite::Connection::open_with_flags(
                        db_path,
                        OpenFlags::SQLITE_OPEN_READ_ONLY,
                    ) {
                        Ok(c) => c,
                        Err(e) => {
                            eprintln!("[BagPlayer] Failed to open {}: {:?}", db_path.display(), e);
                            continue;
                        }
                    };

                    let topic_id: i64 = match conn.query_row(
                        "SELECT id FROM topics WHERE type = 'sensor_msgs/msg/PointCloud2' OR type LIKE '%PointCloud2%' LIMIT 1",
                        [],
                        |row| row.get(0),
                    ) {
                        Ok(id) => id,
                        Err(e) => {
                            eprintln!("[BagPlayer] No PointCloud2 topic in {}: {:?}", db_path.display(), e);
                            continue;
                        }
                    };

                    let mut stmt = match conn.prepare("SELECT data FROM messages WHERE topic_id = ? ORDER BY id ASC") {
                        Ok(s) => s,
                        Err(e) => {
                            eprintln!("[BagPlayer] Failed to prepare statement: {:?}", e);
                            continue;
                        }
                    };

                    let mut rows = match stmt.query([topic_id]) {
                        Ok(r) => r,
                        Err(e) => {
                            eprintln!("[BagPlayer] Failed to query rows: {:?}", e);
                            continue;
                        }
                    };

                    let mut frame_in_file = 0;

                    while let Ok(Some(row)) = rows.next() {
                        if streamer.new_path_signal.load(Ordering::Relaxed) {
                            should_restart = true;
                            break;
                        }

                        while streamer.is_paused.load(Ordering::Relaxed) {
                            if streamer.new_path_signal.load(Ordering::Relaxed) {
                                should_restart = true;
                                break;
                            }
                            std::thread::sleep(Duration::from_millis(30));
                        }
                        if should_restart {
                            break;
                        }

                        let t_start = Instant::now();
                        frame_in_file += 1;

                        let raw: Vec<u8> = match row.get(0) {
                            Ok(b) => b,
                            Err(_) => continue,
                        };

                        let point_cloud: PointCloud2 = match cdr::deserialize(&raw) {
                            Ok(pc) => pc,
                            Err(e) => {
                                eprintln!("[BagPlayer] CDR deserialization error: {:?}", e);
                                continue;
                            }
                        };

                        let layout = match cached_layout {
                            Some(l) => l,
                            None => {
                                match extract_point_layout(&point_cloud) {
                                    Ok(l) => {
                                        cached_layout = Some(l);
                                        l
                                    }
                                    Err(e) => {
                                        eprintln!("[BagPlayer] Layout extraction error: {}", e);
                                        continue;
                                    }
                                }
                            }
                        };

                        if let Err(e) = parse_point_cloud_into_buffer(
                            &point_cloud,
                            &live_cloud,
                            &layout,
                        ) {
                            eprintln!("[BagPlayer] parse error: {}", e);
                            continue;
                        }

                        let f = streamer.total_frames.fetch_add(1, Ordering::SeqCst) + 1;
                        frame_counter.store(f, Ordering::Release);

                        {
                            let mut st = streamer.status.lock().unwrap();
                            st.dataset_name = ds_name.clone();
                            st.current_file_name = file_name.clone();
                            st.current_file_idx = file_idx + 1;
                            st.total_files = total_files;
                            st.frame_in_file = frame_in_file;
                            st.total_frames_sent = f;
                        }

                        let target_fps = *streamer.playback_fps.lock().unwrap();
                        let frame_time = Duration::from_secs_f32(1.0 / target_fps.max(0.1));
                        if let Some(delay) = frame_time.checked_sub(t_start.elapsed()) {
                            std::thread::sleep(delay);
                        }
                    }

                    if should_restart {
                        break;
                    }
                }

                if !streamer.loop_bag.load(Ordering::Relaxed) && !should_restart {
                    streamer.is_paused.store(true, Ordering::Relaxed);
                }
            }
        });
    }
}

fn resolve_db3_files(path: &Path) -> Vec<PathBuf> {
    if path.is_file() {
        if path.extension().and_then(|s| s.to_str()) == Some("db3") {
            return vec![path.to_path_buf()];
        }
        if path.file_name().and_then(|s| s.to_str()) == Some("metadata.yaml") {
            if let Some(parent) = path.parent() {
                return resolve_db3_from_dir(parent);
            }
        }
    } else if path.is_dir() {
        return resolve_db3_from_dir(path);
    }
    Vec::new()
}

fn resolve_db3_from_dir(dir: &Path) -> Vec<PathBuf> {
    let meta_path = dir.join("metadata.yaml");
    if meta_path.is_file() {
        if let Ok(content) = std::fs::read_to_string(&meta_path) {
            let files = parse_relative_file_paths_from_yaml(&content);
            if !files.is_empty() {
                let resolved: Vec<PathBuf> = files
                    .into_iter()
                    .map(|f| dir.join(&f))
                    .filter(|p| p.is_file())
                    .collect();
                if !resolved.is_empty() {
                    return resolved;
                }
            }
        }
    }

    let mut files = Vec::new();
    if let Ok(entries) = std::fs::read_dir(dir) {
        for entry in entries.flatten() {
            let p = entry.path();
            if p.is_file() && p.extension().and_then(|s| s.to_str()) == Some("db3") {
                files.push(p);
            }
        }
    }
    files.sort();
    files
}

fn parse_relative_file_paths_from_yaml(yaml: &str) -> Vec<String> {
    let mut result = Vec::new();
    let mut in_rel = false;
    for line in yaml.lines() {
        let trimmed = line.trim();
        if trimmed.starts_with("relative_file_paths:") {
            in_rel = true;
            continue;
        }
        if in_rel {
            if trimmed.starts_with("- ") {
                let p = trimmed[2..].trim().trim_matches('\'').trim_matches('"');
                if !p.is_empty() {
                    result.push(p.to_string());
                }
            } else if !trimmed.is_empty() && !trimmed.starts_with('#') {
                break;
            }
        }
    }
    result
}

fn scan_available_datasets() -> Vec<DatasetItem> {
    let mut items = Vec::new();
    let candidates = [
        PathBuf::from("dataset"),
        PathBuf::from("D:\\Projects\\LDT-2026\\dataset"),
        PathBuf::from("../dataset"),
    ];

    let mut scanned_paths = std::collections::HashSet::new();

    for base in candidates {
        if !base.is_dir() {
            continue;
        }
        if let Ok(canon) = base.canonicalize() {
            if !scanned_paths.insert(canon) {
                continue;
            }
        }

        if let Ok(entries) = std::fs::read_dir(&base) {
            for entry in entries.flatten() {
                let p = entry.path();
                if p.is_dir() {
                    let db3s = resolve_db3_from_dir(&p);
                    if !db3s.is_empty() {
                        let name = p.file_name().unwrap_or_default().to_string_lossy().to_string();
                        items.push(DatasetItem { name, path: p });
                    }
                } else if p.is_file() && p.extension().and_then(|s| s.to_str()) == Some("db3") {
                    let name = p.file_name().unwrap_or_default().to_string_lossy().to_string();
                    items.push(DatasetItem { name, path: p });
                }
            }
        }
    }

    items.sort_by(|a, b| a.name.cmp(&b.name));
    items
}

// ─────────────────────────────────────────────────────────────
// Profiling metrics
// ─────────────────────────────────────────────────────────────

#[derive(Clone, Default)]
pub struct PipelineProfiling {
    pub crop_ms: f32,
    pub rail_detect_ms: f32,
    pub obstacle_detect_ms: f32,
    pub total_ort_ms: f32,
    pub rerun_stream_ms: f32,
    pub egui_paint_ms: f32,
    pub texture_upload_ms: f32,
    pub total_pipeline_ms: f32,
    pub ema_total_ms: f32,
}

impl PipelineProfiling {
    pub fn update_ema(&mut self) {
        if self.ema_total_ms <= 0.0 {
            self.ema_total_ms = self.total_pipeline_ms;
        } else {
            self.ema_total_ms = self.ema_total_ms * 0.90 + self.total_pipeline_ms * 0.10;
        }
    }
}

// ─────────────────────────────────────────────────────────────
// Playback Mode
// ─────────────────────────────────────────────────────────────

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum PlaybackMode {
    Live,
    Freeze,
    Loop,
}

// ─────────────────────────────────────────────────────────────
// Main Application State
// ─────────────────────────────────────────────────────────────

pub struct RailLiveTunerApp {
    // Mode & Navigation
    mode: PlaybackMode,
    selected_history_idx: usize,
    loop_fps: f32,
    last_loop_tick: Instant,

    // Bag Streamer & Dataset Selection
    streamer: Arc<BagStreamer>,
    available_datasets: Vec<DatasetItem>,
    selected_dataset_name: String,

    // RailOrt Parameters
    z_min: f32,
    z_max: f32,
    y_min: f32,
    y_max: f32,
    ring_start: usize,
    ring_end: usize,
    intensity_jump_threshold: f32,
    intensity_max: f32,
    nominal_height_jump: f32,
    height_jump_tolerance: f32,
    min_point_distance: f32,
    min_track_length_m: f32,
    nominal_gauge: f32,
    gauge_tolerance: f32,
    max_rail_height_diff: f32,
    max_lateral_jump: f32,
    max_lateral_rail_jump: f32,
    max_longitudinal_jump: f32,
    extrapolate_m: f32,
    smooth_n: usize,
    min_longitudinal_jump: f32,

    intensity_score: f32,
    gauge_err_score: f32,
    delta_z_score: f32,
    continuity_score: f32,

    // Obstacle Parameters
    detect_obstacles: bool,
    obstacle_mode: ObstacleDetectionMode,
    clearance_width: f32,
    clearance_narrowing_width: f32,
    clearance_narrowing_height: f32,
    min_height_above_rail: f32,
    max_height_above_rail: f32,
    min_points: usize,
    max_distance_m: f32,
    depth_diff_thresh: f32,
    upward_curvature: f32,
    cluster_depth_thresh: f32,

    // Visualization & Layer
    painter: EguiRangePainter,
    layer_cfg: LayerViewConfig,
    texture: Option<egui::TextureHandle>,
    last_painted_frame_id: u64,
    copied_toast_time: Option<Instant>,

    // Shared pipeline state
    history: Arc<Mutex<HistoryBuffer>>,
    replay_cloud: Arc<RwLock<AppPointCloud>>,
    detector: RailOrtDetector,
    profiling: PipelineProfiling,
    rerun_stream: Arc<Mutex<Option<RecordingStream>>>,
    rerun_url: String,
    stream_to_rerun: Arc<AtomicBool>,
    worker_processed_frame: Arc<AtomicU64>,
    live_config: Arc<RwLock<RailOrtConfig>>,
    reset_epoch: Arc<AtomicU64>,
}

impl RailLiveTunerApp {
    pub fn new(
        history: Arc<Mutex<HistoryBuffer>>,
        replay_cloud: Arc<RwLock<AppPointCloud>>,
        rerun_stream: Arc<Mutex<Option<RecordingStream>>>,
        rerun_url: String,
        worker_processed_frame: Arc<AtomicU64>,
        streamer: Arc<BagStreamer>,
        available_datasets: Vec<DatasetItem>,
        initial_dataset_name: String,
        live_config: Arc<RwLock<RailOrtConfig>>,
        reset_epoch: Arc<AtomicU64>,
        stream_to_rerun: Arc<AtomicBool>,
    ) -> Self {
        let dummy_geo = LidarGeometry::new(128, 400, 15.0, -25.0, 40.0);
        let default_cfg = RailOrtConfig::default();
        let detector = RailOrtDetector::new(dummy_geo, default_cfg.clone());

        Self {
            mode: PlaybackMode::Freeze,
            selected_history_idx: 0,
            loop_fps: 10.0,
            last_loop_tick: Instant::now(),

            streamer,
            available_datasets,
            selected_dataset_name: initial_dataset_name,

            z_min: default_cfg.z_min,
            z_max: default_cfg.z_max,
            y_min: default_cfg.y_min,
            y_max: default_cfg.y_max,
            ring_start: default_cfg.ring_start,
            ring_end: default_cfg.ring_end,
            intensity_jump_threshold: default_cfg.intensity_jump_threshold,
            intensity_max: default_cfg.intensity_max,
            nominal_height_jump: default_cfg.nominal_height_jump,
            height_jump_tolerance: default_cfg.height_jump_tolerance,
            min_point_distance: default_cfg.min_point_distance,
            nominal_gauge: default_cfg.nominal_gauge,
            gauge_tolerance: default_cfg.gauge_tolerance,
            max_rail_height_diff: default_cfg.max_rail_height_diff,
            max_lateral_jump: default_cfg.max_lateral_jump,
            max_lateral_rail_jump: default_cfg.max_lateral_rail_jump,
            max_longitudinal_jump: default_cfg.max_longitudinal_jump,
            extrapolate_m: default_cfg.extrapolate_m,
            smooth_n: default_cfg.smooth_n,
            min_track_length_m: default_cfg.min_track_length_m,
            min_longitudinal_jump: default_cfg.min_longitudinal_jump,

            intensity_score: default_cfg.intensity_score,
            gauge_err_score: default_cfg.gauge_err_score,
            delta_z_score: default_cfg.delta_z_score,
            continuity_score: default_cfg.continuity_score,

            detect_obstacles: default_cfg.detect_obstacles,
            obstacle_mode: default_cfg.obstacle_config.mode,
            clearance_width: default_cfg.obstacle_config.clearance_width,
            clearance_narrowing_width: default_cfg.obstacle_config.clearance_narrowing_width,
            clearance_narrowing_height: default_cfg.obstacle_config.clearance_narrowing_height,
            min_height_above_rail: default_cfg.obstacle_config.min_height_above_rail,
            max_height_above_rail: default_cfg.obstacle_config.max_height_above_rail,
            min_points: default_cfg.obstacle_config.min_points,
            max_distance_m: default_cfg.obstacle_config.max_distance_m,
            depth_diff_thresh: default_cfg.obstacle_config.depth_diff_thresh,
            upward_curvature: default_cfg.obstacle_config.upward_curvature,
            cluster_depth_thresh: default_cfg.obstacle_config.cluster_depth_thresh,

            painter: EguiRangePainter::new(3),
            layer_cfg: LayerViewConfig::default(),
            texture: None,
            last_painted_frame_id: 0,
            copied_toast_time: None,

            history,
            replay_cloud,
            detector,
            profiling: PipelineProfiling::default(),
            rerun_stream,
            rerun_url,
            stream_to_rerun,
            worker_processed_frame,
            live_config,
            reset_epoch,
        }
    }

    pub fn try_connect_rerun(&mut self) {
        println!("[*] Connecting to Rerun at {}...", self.rerun_url);
        match RecordingStreamBuilder::new("rail_live_tuner").connect_grpc_opts(self.rerun_url.clone()) {
            Ok(s) => {
                println!("[+] Successfully connected to Rerun at {}", self.rerun_url);
                *self.rerun_stream.lock().unwrap() = Some(s);
                self.stream_to_rerun.store(true, Ordering::Relaxed);
            }
            Err(e) => {
                eprintln!("[-] Could not connect to Rerun at {}: {:?}", self.rerun_url, e);
            }
        }
    }

    pub fn select_dataset(&mut self, path: PathBuf, name: &str) {
        println!("[Dataset] Selected dataset: {} ({})", name, path.display());
        self.selected_dataset_name = name.to_string();
        *self.streamer.active_path.lock().unwrap() = Some(path);
        // Do NOT auto-play on select — wait for user to click Start
        self.streamer.is_paused.store(true, Ordering::Relaxed);
        self.streamer.new_path_signal.store(true, Ordering::SeqCst);
        self.detector.reset();
        self.reset_epoch.fetch_add(1, Ordering::SeqCst);
        {
            let mut lock = self.history.lock().unwrap();
            lock.clear();
        }
        self.selected_history_idx = 0;
        self.last_painted_frame_id = 0;
        self.texture = None;
    }

    pub fn start_playback(&mut self) {
        let has_path = self.streamer.active_path.lock().unwrap().is_some();
        if !has_path {
            if let Some(first) = self.available_datasets.first() {
                *self.streamer.active_path.lock().unwrap() = Some(first.path.clone());
                self.selected_dataset_name = first.name.clone();
            }
        }
        self.streamer.new_path_signal.store(true, Ordering::SeqCst);
        self.streamer.is_paused.store(false, Ordering::Relaxed);
        self.mode = PlaybackMode::Live;
    }

    pub fn pause_playback(&mut self) {
        self.streamer.is_paused.store(true, Ordering::Relaxed);
        self.mode = PlaybackMode::Freeze;
    }

    pub fn restart_dataset(&mut self) {
        self.streamer.new_path_signal.store(true, Ordering::SeqCst);
        self.streamer.is_paused.store(false, Ordering::Relaxed);
        self.detector.reset();
        self.reset_epoch.fetch_add(1, Ordering::SeqCst);
        {
            let mut lock = self.history.lock().unwrap();
            lock.clear();
        }
        self.selected_history_idx = 0;
        self.last_painted_frame_id = 0;
        self.mode = PlaybackMode::Live;
    }

    fn build_rail_ort_config(&self) -> RailOrtConfig {
        let mut cfg = RailOrtConfig::default();
        cfg.z_min = self.z_min;
        cfg.z_max = self.z_max;
        cfg.y_min = self.y_min;
        cfg.y_max = self.y_max;
        cfg.ring_start = self.ring_start;
        cfg.ring_end = self.ring_end;
        cfg.intensity_jump_threshold = self.intensity_jump_threshold;
        cfg.intensity_max = self.intensity_max;
        cfg.nominal_height_jump = self.nominal_height_jump;
        cfg.height_jump_tolerance = self.height_jump_tolerance;
        cfg.min_point_distance = self.min_point_distance;
        cfg.nominal_gauge = self.nominal_gauge;
        cfg.gauge_tolerance = self.gauge_tolerance;
        cfg.max_rail_height_diff = self.max_rail_height_diff;
        cfg.max_lateral_jump = self.max_lateral_jump;
        cfg.max_lateral_rail_jump = self.max_lateral_rail_jump;
        cfg.max_longitudinal_jump = self.max_longitudinal_jump;
        cfg.extrapolate_m = self.extrapolate_m;
        cfg.smooth_n = self.smooth_n;
        cfg.min_longitudinal_jump = self.min_longitudinal_jump;

        cfg.intensity_score = self.intensity_score;
        cfg.gauge_err_score = self.gauge_err_score;
        cfg.delta_z_score = self.delta_z_score;
        cfg.continuity_score = self.continuity_score;

        cfg.detect_obstacles = self.detect_obstacles;
        cfg.obstacle_config.enabled = self.detect_obstacles;
        cfg.obstacle_config.mode = self.obstacle_mode;
        cfg.obstacle_config.clearance_width = self.clearance_width;
        cfg.obstacle_config.clearance_narrowing_width = self.clearance_narrowing_width;
        cfg.obstacle_config.clearance_narrowing_height = self.clearance_narrowing_height;
        cfg.obstacle_config.min_height_above_rail = self.min_height_above_rail;
        cfg.obstacle_config.max_height_above_rail = self.max_height_above_rail;
        cfg.obstacle_config.min_points = self.min_points;
        cfg.obstacle_config.max_distance_m = self.max_distance_m;
        cfg.obstacle_config.depth_diff_thresh = self.depth_diff_thresh;
        cfg.obstacle_config.upward_curvature = self.upward_curvature;
        cfg.obstacle_config.cluster_depth_thresh = self.cluster_depth_thresh;

        cfg
    }

    /// Re-evaluates detection on a specific frame index in the history buffer
    fn rerun_detection_on_frame(&mut self, idx: usize) {
        let mut hist_lock = self.history.lock().unwrap();
        if hist_lock.is_empty() || idx >= hist_lock.len() {
            return;
        }
        let frame = &mut hist_lock.frames[idx];

        // 1. Populate replay cloud buffer with frame points
        let pts_len = frame.xs.len();
        {
            let mut cloud = self.replay_cloud.write().unwrap();
            let queue = ProcessingQueue::READ;

            cloud.x[queue][..pts_len].copy_from_slice(&frame.xs);
            cloud.y[queue][..pts_len].copy_from_slice(&frame.ys);
            cloud.z[queue][..pts_len].copy_from_slice(&frame.zs);
            cloud.intensity[queue][..pts_len].copy_from_slice(&frame.intensity);
            cloud.ring[queue][..pts_len].copy_from_slice(&frame.ring);

            cloud.x[queue].length = pts_len;
            cloud.y[queue].length = pts_len;
            cloud.z[queue].length = pts_len;
            cloud.intensity[queue].length = pts_len;
            cloud.ring[queue].length = pts_len;

            cloud.width[queue] = frame.width as u32;
            cloud.height[queue] = frame.height as u32;
            cloud.timestamp[queue] = frame.timestamp_ns;
        }

        // 2. Update detector config
        self.detector.config = self.build_rail_ort_config();

        let geo = LidarGeometry::new(
            frame.range_image.height,
            frame.range_image.width,
            15.0,
            -25.0,
            40.0,
        );
        self.detector.geometry = geo.clone();

        // 3. Run RailOrt detection
        let t_detect = Instant::now();
        let cloud_read = self.replay_cloud.read().unwrap();
        let mut cropped = self
            .detector
            .crop_tunnel_rings(&cloud_read, ProcessingQueue::READ);
        let res = self.detector.process_rings(
            &mut cropped,
            &cloud_read,
            ProcessingQueue::READ,
            frame.frame_idx,
            None,
        );
        let dur = t_detect.elapsed();

        // Save cropped tunnel 3D points
        let cropped_3d: Vec<Vec<[f32; 3]>> = cropped
            .iter()
            .map(|ring| {
                ring.iter()
                    .map(|p| p.get_xyz(&cloud_read, ProcessingQueue::READ))
                    .collect()
            })
            .collect();

        frame.detection_result = res;
        frame.cropped_tunnel = cropped_3d;

        self.profiling.total_ort_ms = dur.as_secs_f32() * 1000.0;
        if let Some(ref r) = frame.detection_result {
            self.profiling.rail_detect_ms = r.timing_rail_ms;
            self.profiling.obstacle_detect_ms = r.timing_obstacles_ms;
        }
    }

    /// Re-evaluates detection on ALL frames in the buffer with current slider settings
    fn rerun_detection_on_all_frames(&mut self) {
        let count = {
            let hist = self.history.lock().unwrap();
            hist.len()
        };
        for i in 0..count {
            self.rerun_detection_on_frame(i);
        }
    }

    /// Streams the currently selected frame's 3D result to Rerun
    fn stream_selected_frame_to_rerun(&self) {
        if !self.stream_to_rerun.load(Ordering::Relaxed) {
            return;
        }
        let rerun_lock = self.rerun_stream.lock().unwrap();
        let Some(ref rec) = *rerun_lock else {
            return;
        };
        let hist_lock = self.history.lock().unwrap();
        if hist_lock.is_empty() {
            return;
        }
        let idx = self.selected_history_idx.min(hist_lock.len() - 1);
        let frame = &hist_lock.frames[idx];

        rec.set_time_sequence("frame", frame.frame_idx as i64);

        let pts_len = frame.xs.len();
        let mut pts_real = Vec::with_capacity(pts_len);
        let mut colors = Vec::with_capacity(pts_len);
        for i in 0..pts_len {
            let (x, y, z) = (frame.xs[i], frame.ys[i], frame.zs[i]);
            if !is_zero_point(x, y, z) {
                pts_real.push([x, y, z]);
                let r = (x * x + y * y + z * z).sqrt();
                let norm = (r / 200.0).clamp(0.0, 1.0);
                let c = turbo_rgb(norm);
                colors.push(Color::from_rgb(c[0], c[1], c[2]));
            }
        }
        let _ = rec.log(
            "lidar/point_cloud",
            &Points3D::new(&pts_real)
                .with_colors(colors)
                .with_radii([Radius::new_ui_points(1.2)]),
        );

        let tunnel_flat: Vec<[f32; 3]> = frame.cropped_tunnel.iter().flatten().copied().collect();
        let _ = rec.log(
            "tracks_ort/tunnel_cropped",
            &Points3D::new(&tunnel_flat)
                .with_colors([Color::from_rgb(255, 255, 0)])
                .with_radii([Radius::new_ui_points(1.4)]),
        );

        rec.log_ort_detection_3d(frame.detection_result.as_ref());
    }

    /// Uploads latest preview texture to egui
    fn update_preview_texture(&mut self, ctx: &egui::Context) {
        let hist_lock = self.history.lock().unwrap();
        if hist_lock.is_empty() {
            return;
        }
        let idx = self.selected_history_idx.min(hist_lock.len() - 1);
        let frame = &hist_lock.frames[idx];

        let geo = LidarGeometry::new(
            frame.range_image.height,
            frame.range_image.width,
            15.0,
            -25.0,
            40.0,
        );

        let t_paint = Instant::now();
        let color_img = self.painter.paint(
            &frame.range_image,
            frame.detection_result.as_ref(),
            &geo,
            &self.layer_cfg,
        );
        self.profiling.egui_paint_ms = t_paint.elapsed().as_secs_f32() * 1000.0;

        let t_upload = Instant::now();
        self.texture = Some(ctx.load_texture("range_view", color_img, TextureOptions::LINEAR));
        self.profiling.texture_upload_ms = t_upload.elapsed().as_secs_f32() * 1000.0;

        self.profiling.total_pipeline_ms = self.profiling.total_ort_ms
            + self.profiling.egui_paint_ms
            + self.profiling.texture_upload_ms;
        self.profiling.update_ema();
    }
}

// ─────────────────────────────────────────────────────────────
// egui Application Implementation
// ─────────────────────────────────────────────────────────────

impl eframe::App for RailLiveTunerApp {
    fn ui(&mut self, ui: &mut egui::Ui, _frame: &mut eframe::Frame) {
        // Handle keyboard shortcuts
        let input = ui.input(|i| {
            (
                i.key_pressed(Key::Space),
                i.key_pressed(Key::ArrowLeft) || i.key_pressed(Key::A),
                i.key_pressed(Key::ArrowRight) || i.key_pressed(Key::D),
                i.key_pressed(Key::L),
            )
        });

        // Space: Toggle Live / Freeze
        if input.0 {
            match self.mode {
                PlaybackMode::Live => self.pause_playback(),
                PlaybackMode::Freeze | PlaybackMode::Loop => self.start_playback(),
            }
        }

        // L: Toggle Loop
        if input.3 {
            if self.mode == PlaybackMode::Loop {
                self.mode = PlaybackMode::Freeze;
            } else {
                self.mode = PlaybackMode::Loop;
                self.streamer.is_paused.store(true, Ordering::Relaxed);
                self.last_loop_tick = Instant::now();
            }
        }

        let history_len = {
            let lock = self.history.lock().unwrap();
            lock.len()
        };

        // Arrow navigation
        if input.1 && self.selected_history_idx > 0 {
            self.mode = PlaybackMode::Freeze;
            self.selected_history_idx -= 1;
            self.update_preview_texture(ui.ctx());
            self.stream_selected_frame_to_rerun();
        }
        if input.2 && self.selected_history_idx + 1 < history_len {
            self.mode = PlaybackMode::Freeze;
            self.selected_history_idx += 1;
            self.update_preview_texture(ui.ctx());
            self.stream_selected_frame_to_rerun();
        }

        // Mode handling: Live vs Loop vs Freeze
        match self.mode {
            PlaybackMode::Live => {
                let latest_processed = self.worker_processed_frame.load(Ordering::Acquire);
                // When new frame arrives, update texture immediately regardless of buffer fullness!
                if latest_processed != self.last_painted_frame_id && history_len > 0 {
                    self.last_painted_frame_id = latest_processed;
                    self.selected_history_idx = history_len - 1;
                    self.update_preview_texture(ui.ctx());
                }
                ui.ctx().request_repaint_after(Duration::from_millis(20));
            }
            PlaybackMode::Loop => {
                if history_len > 1 {
                    let interval = Duration::from_secs_f32(1.0 / self.loop_fps.max(1.0));
                    if self.last_loop_tick.elapsed() >= interval {
                        self.last_loop_tick = Instant::now();
                        self.selected_history_idx = (self.selected_history_idx + 1) % history_len;
                        self.update_preview_texture(ui.ctx());
                        self.stream_selected_frame_to_rerun();
                    }
                    ui.ctx().request_repaint_after(Duration::from_millis(15));
                }
            }
            PlaybackMode::Freeze => {
                // Static display on selected frame
            }
        }

        // ─── Row 1: Dataset Source & Playback Controls ───
        ui.horizontal(|ui| {
            ui.label(egui::RichText::new("📁 Датасет:").strong());

            let mut switched = false;
            let mut new_path = None;
            let mut new_name = String::new();

            egui::ComboBox::from_id_salt("dataset_select_combo")
                .width(220.0)
                .selected_text(if self.selected_dataset_name.is_empty() {
                    "Выберите датасет..."
                } else {
                    &self.selected_dataset_name
                })
                .show_ui(ui, |ui| {
                    for item in &self.available_datasets {
                        let is_selected = self.selected_dataset_name == item.name;
                        if ui.selectable_label(is_selected, &item.name).clicked() {
                            switched = true;
                            new_path = Some(item.path.clone());
                            new_name = item.name.clone();
                        }
                    }
                });

            if switched {
                if let Some(p) = new_path {
                    self.select_dataset(p, &new_name);
                }
            }

            if ui.button("📂 Обзор...").clicked() {
                if let Some(folder) = rfd::FileDialog::new()
                    .set_directory("D:\\Projects\\LDT-2026\\dataset")
                    .set_title("Выберите папку датасета (с .db3 или metadata.yaml)")
                    .pick_folder()
                {
                    let name = folder.file_name().unwrap_or_default().to_string_lossy().to_string();
                    self.select_dataset(folder, &name);
                }
            }

            ui.separator();

            // Big Play/Pause Button
            let is_streamer_paused = self.streamer.is_paused.load(Ordering::Relaxed);
            if is_streamer_paused {
                if ui
                    .button(egui::RichText::new("▶ СТАРТ").color(Color32::GREEN).strong())
                    .clicked()
                {
                    self.start_playback();
                }
            } else {
                if ui
                    .button(
                        egui::RichText::new("⏸ ПАУЗА")
                            .color(Color32::from_rgb(255, 190, 50))
                            .strong(),
                    )
                    .clicked()
                {
                    self.pause_playback();
                }
            }

            if ui.button("🔄 С начала").clicked() {
                self.restart_dataset();
            }

            ui.separator();
            ui.label("Скорость (FPS):");
            let mut fps = *self.streamer.playback_fps.lock().unwrap();
            if ui.add(egui::Slider::new(&mut fps, 1.0..=60.0).step_by(1.0)).changed() {
                *self.streamer.playback_fps.lock().unwrap() = fps;
            }

            // Streamer status summary
            let st = self.streamer.status.lock().unwrap().clone();
            if !st.current_file_name.is_empty() {
                ui.separator();
                ui.colored_label(
                    Color32::from_rgb(180, 220, 255),
                    format!(
                        "[{}/{}] {} (кадр {})",
                        st.current_file_idx, st.total_files, st.current_file_name, st.frame_in_file
                    ),
                );
            }
        });

        ui.separator();

        // ─── Row 2: Tuner Controls & Buffer Modes ───
        ui.horizontal(|ui| {
            ui.heading("🛠️ Tuner");
            ui.separator();

            // 3-way Mode Selector Tabs: LIVE / FREEZE / LOOP БУФЕРА
            let is_live = self.mode == PlaybackMode::Live;
            let is_freeze = self.mode == PlaybackMode::Freeze;
            let is_loop = self.mode == PlaybackMode::Loop;

            if ui.selectable_label(is_live, egui::RichText::new("🔴 LIVE").strong()).clicked() {
                self.mode = PlaybackMode::Live;
                self.streamer.is_paused.store(false, Ordering::Relaxed);
            }

            if ui.selectable_label(is_freeze, egui::RichText::new("⏸ FREEZE").strong()).clicked() {
                self.mode = PlaybackMode::Freeze;
            }

            if ui.selectable_label(is_loop, egui::RichText::new("🔁 LOOP БУФЕРА").strong()).clicked() {
                self.mode = PlaybackMode::Loop;
                // When looping the buffer, pause the incoming bag stream so buffer stays fixed!
                self.streamer.is_paused.store(true, Ordering::Relaxed);
                self.last_loop_tick = Instant::now();
            }

            ui.separator();

            // History buffer status
            let processed_f = self.worker_processed_frame.load(Ordering::Relaxed);
            ui.label(format!("Кадр: #{processed_f}"));
            ui.label(format!("Буфер: {}/50", history_len));

            // Scrub slider
            if history_len > 1 {
                let mut cur = self.selected_history_idx.min(history_len - 1);
                if ui
                    .add(egui::Slider::new(&mut cur, 0..=history_len - 1).text("Scrub"))
                    .changed()
                {
                    self.mode = PlaybackMode::Freeze;
                    self.selected_history_idx = cur;
                    self.update_preview_texture(ui.ctx());
                    self.stream_selected_frame_to_rerun();
                }
            }

            // Prev / Next buttons
            if ui.button("⏮").clicked() && self.selected_history_idx > 0 {
                self.mode = PlaybackMode::Freeze;
                self.selected_history_idx -= 1;
                self.update_preview_texture(ui.ctx());
                self.stream_selected_frame_to_rerun();
            }
            if ui.button("⏭").clicked() && self.selected_history_idx + 1 < history_len {
                self.mode = PlaybackMode::Freeze;
                self.selected_history_idx += 1;
                self.update_preview_texture(ui.ctx());
                self.stream_selected_frame_to_rerun();
            }

            if is_loop {
                ui.separator();
                ui.label("Loop FPS:");
                ui.add(egui::Slider::new(&mut self.loop_fps, 1.0..=60.0).step_by(1.0));
            }

            ui.with_layout(egui::Layout::right_to_left(egui::Align::Center), |ui| {
                if let Some(t) = self.copied_toast_time {
                    if t.elapsed() < Duration::from_secs(2) {
                        ui.colored_label(Color32::GREEN, "📋 Copied Rust Config!");
                    }
                }

                if ui.button("📋 Copy Rust Config").clicked() {
                    let cfg = format!(
                        "// Tuned RailOrt Config\n\n\
                         z_min : {:.2},\n\
                         z_max : {:.2},\n\
                         y_min : {:.2},\n\
                         y_max : {:.1},\n\
                         ring_start : {},\n\
                         ring_end : {},\n\
                         intensity_jump_threshold : {:.2},\n\
                         intensity_max : {:.1},\n\
                         nominal_height_jump : {:.2},\n\
                         height_jump_tolerance : {:.2},\n\
                         min_point_distance : {:.3},\n\
                         min_track_length_m: {:.3},\n\
                         nominal_gauge : {:.3},\n\
                         gauge_tolerance : {:.3},\n\
                         max_rail_height_diff : {:.3},\n\
                         max_lateral_jump : {:.2},\n\
                         max_lateral_rail_jump : {:.3},\n\
                         max_longitudinal_jump : {:.2},\n\
                         min_longitudinal_jump : {:.3},\n\
                         extrapolate_m : {:.1},\n\
                         smooth_n : {},\n\
                         detect_obstacles : {},\n\
                         intensity_score : {:.2},\n\
                         gauge_err_score : {:.2},\n\
                         delta_z_score : {:.2},\n\
                         continuity_score : {:.2},\n\
                         obstacle_config: ObstacleConfig{{\n\
                             enabled : {},\n\
                             mode : shared::rail_detection::ObstacleDetectionMode::{:?},\n\
                             clearance_width : {:.2},\n\
                             clearance_narrowing_width : {:.4},\n\
                             clearance_narrowing_height : {:.4},\n\
                             min_height_above_rail : {:.2},\n\
                             max_height_above_rail : {:.2},\n\
                             min_points : {},\n\
                             max_distance_m : {:.1},\n\
                             depth_diff_thresh : {:.2},\n\
                             upward_curvature : {:.5},\n\
                             cluster_depth_thresh : {:.2},\n\
                         }},",
                        self.z_min,
                        self.z_max,
                        self.y_min,
                        self.y_max,
                        self.ring_start,
                        self.ring_end,
                        self.intensity_jump_threshold,
                        self.intensity_max,
                        self.nominal_height_jump,
                        self.height_jump_tolerance,
                        self.min_point_distance,
                        self.min_track_length_m,
                        self.nominal_gauge,
                        self.gauge_tolerance,
                        self.max_rail_height_diff,
                        self.max_lateral_jump,
                        self.max_lateral_rail_jump,
                        self.max_longitudinal_jump,
                        self.min_longitudinal_jump,
                        self.extrapolate_m,
                        self.smooth_n,
                        self.detect_obstacles,
                        self.intensity_score,
                        self.gauge_err_score,
                        self.delta_z_score,
                        self.continuity_score,
                        self.detect_obstacles,
                        self.obstacle_mode,
                        self.clearance_width,
                        self.clearance_narrowing_width,
                        self.clearance_narrowing_height,
                        self.min_height_above_rail,
                        self.max_height_above_rail,
                        self.min_points,
                        self.max_distance_m,
                        self.depth_diff_thresh,
                        self.upward_curvature,
                        self.cluster_depth_thresh,
                    );
                    ui.ctx().copy_text(cfg.clone());
                    println!("\n{}\n", cfg);
                    self.copied_toast_time = Some(Instant::now());
                }

                let is_rerun_connected = self.rerun_stream.lock().unwrap().is_some();
                if is_rerun_connected {
                    let mut stream_flag = self.stream_to_rerun.load(Ordering::Relaxed);
                    if ui.checkbox(&mut stream_flag, "📡 Stream to Rerun").changed() {
                        self.stream_to_rerun.store(stream_flag, Ordering::Relaxed);
                    }
                    ui.colored_label(Color32::GREEN, "🟢 Rerun online");
                } else {
                    if ui.button("🔗 Подключить").clicked() {
                        self.try_connect_rerun();
                    }
                    ui.add(egui::TextEdit::singleline(&mut self.rerun_url).desired_width(170.0));
                    ui.colored_label(Color32::GRAY, "⚪ Rerun URL:");
                }
            });
        });

        ui.separator();

        // ─── Main 2-column layout: Left (~30% width) for Controls, Right (~70% width) for 2D Range Canvas ───
        let total_w = ui.available_width();
        let left_w = (total_w * 0.30).clamp(280.0, 460.0);
        let right_w = (total_w - left_w - 16.0).max(100.0);

        ui.horizontal_top(|ui| {
            // ─── LEFT COLUMN: Parameters & HUD (~30% width) ───
            ui.allocate_ui_with_layout(
                egui::vec2(left_w, ui.available_height()),
                egui::Layout::top_down(egui::Align::Min),
                |left_ui| {
                    left_ui.set_width(left_w);
                    egui::ScrollArea::vertical().id_salt("left_scroll").show(left_ui, |ui| {
                        let mut param_changed = false;

                        ui.group(|ui| {
                            ui.horizontal(|ui| {
                                ui.heading("🎛️ RailOrt Parameters");
                                ui.with_layout(egui::Layout::right_to_left(egui::Align::Center), |ui| {
                                    if ui.button("⚡ Применить ко всем кадрам").clicked() {
                                        let new_cfg = self.build_rail_ort_config();
                                        if let Ok(mut lock) = self.live_config.write() {
                                            *lock = new_cfg;
                                        }
                                        self.rerun_detection_on_all_frames();
                                        self.update_preview_texture(ui.ctx());
                                        self.stream_selected_frame_to_rerun();
                                    }
                                });
                            });

                            egui::CollapsingHeader::new("✂️ Tunnel 3D Crop (Z & Y)")
                                .default_open(true)
                                .show(ui, |ui| {
                                    ui.label("Z min (отсечение пола/балласта, м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.z_min, -30.50..=-0.50).step_by(0.05))
                                        .changed();

                                    ui.label("Z max (отсечение потолка/стен, м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.z_max, -1.80..=1.50).step_by(0.05))
                                        .changed();

                                    ui.label("Y min (дистанция вперёд от поезда, м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.y_min, 0.5..=10.0).step_by(0.1))
                                        .changed();

                                    ui.label("Y max (макс дистанция вперёд, м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.y_max, 20.0..=500.0).step_by(5.0))
                                        .changed();
                                });

                            egui::CollapsingHeader::new("🎯 Rings & Intensity Jumps")
                                .default_open(true)
                                .show(ui, |ui| {
                                    ui.label("Ring start (ближнее кольцо):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.ring_start, 0..=127))
                                        .changed();

                                    ui.label("Ring end (дальнее кольцо):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.ring_end, 0..=127))
                                        .changed();

                                    ui.label("Intensity jump (|ΔI| порог):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.intensity_jump_threshold, 1.0..=50.0).step_by(0.05))
                                        .changed();

                                    ui.label("Intensity max (0 = без ограничений):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.intensity_max, 0.0..=255.0).step_by(0.1))
                                        .changed();

                                    ui.label("Min point distance (фильтр, м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.min_point_distance, 0.0..=1.0).step_by(0.005))
                                        .changed();

                                    ui.label("Min track length (фильтр, м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.min_track_length_m, 0.0..=100.0).step_by(0.5))
                                        .changed();

                                    ui.label("Min jump between pairs (фильтр, м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.min_longitudinal_jump, 0.0..=10.0).step_by(0.01))
                                        .changed();
                                });

                            egui::CollapsingHeader::new("💯 Scoring")
                                .default_open(true)
                                .show(ui, |ui| {
                                    ui.label("Intensity:");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.intensity_score, 0.0..=10.0).step_by(0.01))
                                        .changed();

                                    ui.label("Gauge:");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.gauge_err_score, 0.0..=10.0).step_by(0.01))
                                        .changed();

                                    ui.label("Delta z:");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.delta_z_score, 0.0..=10.0).step_by(0.01))
                                        .changed();

                                    ui.label("Continuity:");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.continuity_score, 0.0..=10.0).step_by(0.01))
                                        .changed();
                                });

                                      egui::CollapsingHeader::new("📏 Track Gauge & Geometry")
                                .default_open(true)
                                .show(ui, |ui| {
                                    ui.label("Номинал колеи (м, 1.520):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.nominal_gauge, 1.400..=1.650).step_by(0.005))
                                        .changed();

                                    ui.label("Допуск колеи (± м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.gauge_tolerance, 0.02..=0.5).step_by(0.005))
                                        .changed();

                                    ui.label("Номинал скачка высоты рельса (м, 0 = выкл):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.nominal_height_jump, 0.0..=1.00).step_by(0.005))
                                        .changed();

                                    ui.label("Допуск высоты рельса (± м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.height_jump_tolerance, 0.01..=0.50).step_by(0.005))
                                        .changed();

                                    ui.label("Макс перекос по высоте (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.max_rail_height_diff, 0.02..=0.40).step_by(0.01))
                                        .changed();

                                    ui.label("Макс скачок центра (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.max_lateral_jump, 0.01..=5.0).step_by(0.01))
                                        .changed();

                                    ui.label("Макс скачок рельса (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.max_lateral_rail_jump, 0.05..=0.50).step_by(0.01))
                                        .changed();

                                    ui.label("Макс продольный скачок пары по Y (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.max_longitudinal_jump, 0.5..=10.0).step_by(0.1))
                                        .changed();

                                    ui.label("Экстраполяция пути (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.extrapolate_m, 0.0..=100.0).step_by(1.0))
                                        .changed();

                                    ui.label("Сглаживание (кадров):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.smooth_n, 1..=10))
                                        .changed();
                                });

                            egui::CollapsingHeader::new("🛑 Obstacle & Clearance")
                                .default_open(true)
                                .show(ui, |ui| {
                                    param_changed |= ui.checkbox(&mut self.detect_obstacles, "Детекция препятствий").changed();

                                    ui.horizontal(|ui| {
                                        ui.label("Режим детекции:");
                                        param_changed |= ui
                                            .selectable_value(
                                                &mut self.obstacle_mode,
                                                ObstacleDetectionMode::HybridGrid,
                                                "🚇 Тоннель (Габарит C)",
                                            )
                                            .changed();
                                        param_changed |= ui
                                            .selectable_value(
                                                &mut self.obstacle_mode,
                                                ObstacleDetectionMode::Boxcast3D,
                                                "🌲 Открытая местность",
                                            )
                                            .changed();
                                    });

                                    ui.label("Ширина габарита приближения (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.clearance_width, 1.0..=6.0).step_by(0.1))
                                        .changed();

                                    ui.label("Ширина сужения габарита снизу (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.clearance_narrowing_width, 0.0..=4.0).step_by(0.05))
                                        .changed();

                                    ui.label("Высота сужения снизу (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.clearance_narrowing_height, 0.0..=1.5).step_by(0.05))
                                        .changed();

                                    ui.label("Мин высота над рельсом (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.min_height_above_rail, -0.5..=0.5).step_by(0.02))
                                        .changed();

                                    ui.label("Макс высота над рельсом (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.max_height_above_rail, 1.0..=5.0).step_by(0.1))
                                        .changed();

                                    ui.label("Мин точек для препятствия:");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.min_points, 1..=50))
                                        .changed();

                                    ui.label("Дистанция проверки (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.max_distance_m, 10.0..=150.0).step_by(5.0))
                                        .changed();

                                    ui.label("Порог кластеризации (м):");
                                    param_changed |= ui
                                        .add(egui::Slider::new(&mut self.cluster_depth_thresh, 0.1..=3.0).step_by(0.1))
                                        .changed();
                                });
                        });

                        if param_changed {
                            let new_cfg = self.build_rail_ort_config();
                            if let Ok(mut lock) = self.live_config.write() {
                                *lock = new_cfg;
                            }
                            self.rerun_detection_on_frame(self.selected_history_idx);
                            self.update_preview_texture(ui.ctx());
                            self.stream_selected_frame_to_rerun();
                        }

                        ui.add_space(8.0);

                        // HUD / Telemetry Card for currently viewed frame
                        let hist_lock = self.history.lock().unwrap();
                        let current_frame = hist_lock.get(self.selected_history_idx.min(hist_lock.len().saturating_sub(1)));

                        if let Some(frame) = current_frame {
                            ui.group(|ui| {
                                ui.heading("📊 Telemetry");
                                ui.label(format!("Кадр ID: #{}", frame.frame_idx));
                                ui.label(format!("Точек лидара: {}", frame.xs.len()));
                                ui.label(format!("Точек тоннеля: {}", frame.cropped_tunnel.iter().map(|r| r.len()).sum::<usize>()));

                                if let Some(ref r) = frame.detection_result {
                                    ui.separator();
                                    ui.colored_label(Color32::GREEN, format!("Колея: {:.3} м (ном {:.3})", r.gauge, self.nominal_gauge));
                                    ui.colored_label(Color32::from_rgb(0, 215, 255), format!("Радиус: {:.1} м ({})", r.turn_radius, r.turn_direction));
                                    ui.label(format!("Точек рельса: {}", r.points.len()));
                                    ui.label(format!("Уверенность: {:.1}%", r.confidence * 100.0));

                                    ui.separator();
                                    let n_crit = r.obstacles.iter().filter(|o| o.is_critical).count();
                                    let n_warn = r.obstacles.len() - n_crit;

                                    if n_crit > 0 {
                                        ui.colored_label(Color32::RED, format!("🚨 ПРЕПЯТСТВИЯ НА ПУТИ: {} шт!", n_crit));
                                    } else if n_warn > 0 {
                                        ui.colored_label(Color32::from_rgb(255, 170, 0), format!("⚠️ Нарушение габарита: {} шт", n_warn));
                                    } else {
                                        ui.colored_label(Color32::GREEN, "🟢 ПУТЬ СВОБОДЕН");
                                    }

                                    for (i, obs) in r.obstacles.iter().enumerate() {
                                        let col = if obs.is_critical { Color32::RED } else { Color32::from_rgb(255, 170, 0) };
                                        ui.colored_label(
                                            col,
                                            format!(
                                                " • #{}: d={:.1}м, off={:.2}м, h={:.2}м, pts={}",
                                                i + 1,
                                                obs.distance_along_track,
                                                obs.lateral_offset,
                                                obs.height_above_rail,
                                                obs.points_count
                                            ),
                                        );
                                    }
                                } else {
                                    ui.separator();
                                    ui.colored_label(Color32::from_rgb(255, 100, 100), "❌ Пути не обнаружены");
                                }

                                ui.separator();
                                ui.heading("⏱️ Profiling");
                                ui.label(format!("Рельсы: {:.2} ms", self.profiling.rail_detect_ms));
                                ui.label(format!("Препятствия: {:.2} ms", self.profiling.obstacle_detect_ms));
                                ui.label(format!("RailOrt: {:.2} ms", self.profiling.total_ort_ms));
                                ui.label(format!("UI Render: {:.2} ms", self.profiling.egui_paint_ms));
                                ui.label(format!("EMA: {:.2} ms ({:.1} FPS)", self.profiling.ema_total_ms, 1000.0 / self.profiling.ema_total_ms.max(1.0)));
                            });
                        }
                    });
                },
            );

            ui.separator();

            // ─── RIGHT COLUMN: 2D Interactive Range Image (~70% width) ───
            ui.allocate_ui_with_layout(
                egui::vec2(right_w, ui.available_height()),
                egui::Layout::top_down(egui::Align::Min),
                |right_ui| {
                    right_ui.set_width(right_w);
                    egui::ScrollArea::vertical().id_salt("right_scroll").show(right_ui, |ui| {
                        ui.horizontal(|ui| {
                            ui.heading("📷 2D Range & Intensity Canvas");
                            ui.separator();

                            let mut layer_changed = false;
                            layer_changed |= ui.selectable_value(&mut self.layer_cfg.mode, ImageLayerMode::Depth, "🗺️ Depth").changed();
                            layer_changed |= ui.selectable_value(&mut self.layer_cfg.mode, ImageLayerMode::Intensity, "💡 Intensity").changed();
                            layer_changed |= ui.selectable_value(&mut self.layer_cfg.mode, ImageLayerMode::Blend, "🔀 Blend").changed();

                            ui.separator();
                            if self.layer_cfg.mode != ImageLayerMode::Depth {
                                layer_changed |= ui.selectable_value(&mut self.layer_cfg.intensity_colormap, IntensityColormap::Grayscale, "⚪ Gray").changed();
                                layer_changed |= ui.selectable_value(&mut self.layer_cfg.intensity_colormap, IntensityColormap::Turbo, "🌈 Turbo").changed();
                                ui.separator();
                            }

                            ui.label("Depth:");
                            layer_changed |= ui.add(egui::Slider::new(&mut self.layer_cfg.contrast_depth, 10.0..=300.0).text("m").step_by(5.0)).changed();

                            ui.separator();
                            ui.label("Int:");
                            layer_changed |= ui.add(egui::Slider::new(&mut self.layer_cfg.contrast_intensity, 5.0..=255.0).step_by(1.0)).changed();

                            ui.separator();
                            ui.label("Blend:");
                            layer_changed |= ui.add(egui::Slider::new(&mut self.layer_cfg.blend, 0.0..=1.0).text("D↔I").step_by(0.01)).changed();

                            if layer_changed {
                                self.update_preview_texture(ui.ctx());
                            }
                        });

                        ui.separator();

                        if let Some(ref tex) = self.texture {
                            let img_size = tex.size_vec2();
                            let max_w = (ui.available_width() - 20.0).max(100.0);
                            let aspect = img_size.y / img_size.x.max(1.0);
                            let final_size = egui::vec2(max_w, max_w * aspect);

                            ui.vertical_centered(|ui| {
                                ui.image((tex.id(), final_size));
                                ui.add_space(4.0);
                                ui.horizontal_wrapped(|ui| {
                                    match self.layer_cfg.mode {
                                        ImageLayerMode::Depth => ui.colored_label(Color32::from_rgb(180, 180, 240), "[🗺️ Depth]"),
                                        ImageLayerMode::Intensity => ui.colored_label(Color32::from_rgb(255, 230, 100), "[💡 Intensity]"),
                                        ImageLayerMode::Blend => ui.colored_label(Color32::from_rgb(120, 230, 180), "[🔀 Blend]"),
                                    };
                                    ui.colored_label(Color32::from_rgb(30, 210, 255), "■ Left Rail");
                                    ui.colored_label(Color32::from_rgb(255, 90, 30), "■ Right Rail");
                                    ui.colored_label(Color32::from_rgb(0, 255, 60), "■ Centerline");
                                    ui.colored_label(Color32::from_rgb(255, 0, 255), "■ Extrapolation");
                                    ui.colored_label(Color32::from_rgb(180, 220, 180), "■ Sleepers");
                                    ui.colored_label(Color32::from_rgb(0, 220, 220), "🔷 Shapecast");
                                    ui.colored_label(Color32::RED, "■ Critical Obstacle");
                                    ui.colored_label(Color32::from_rgb(255, 170, 0), "■ Clearance Intrusion");
                                });
                            });
                        } else {
                            ui.vertical_centered(|ui| {
                                ui.add_space(100.0);
                                ui.heading("🚆 RailOrt Live Tuner");
                                ui.add_space(12.0);
                                if self.selected_dataset_name.is_empty() {
                                    ui.label(egui::RichText::new("Выберите датасет из списка сверху или откройте папку").size(16.0));
                                } else {
                                    ui.label(egui::RichText::new(format!("Выбран датасет: {}", self.selected_dataset_name)).size(16.0).color(Color32::from_rgb(0, 215, 255)));
                                    ui.add_space(10.0);
                                    if ui.button(egui::RichText::new("▶ ЗАПУСТИТЬ ВОСПРОИЗВЕДЕНИЕ").size(18.0).color(Color32::WHITE).strong()).clicked() {
                                        self.start_playback();
                                    }
                                }
                            });
                        }
                    });
                },
            );
        });
    }
}

// ─────────────────────────────────────────────────────────────
// Application Entry Point
// ─────────────────────────────────────────────────────────────

fn main() -> Result<(), Box<dyn std::error::Error>> {
    println!("============================================================");
    println!("🛠️  RAIL LIVE TUNER — Standalone Bag Dataset & Tuner GUI");
    println!("============================================================");

    // 1. Scan available datasets in ./dataset and D:/Projects/LDT-2026/dataset
    let available_datasets = scan_available_datasets();
    println!("[*] Found {} datasets:", available_datasets.len());
    for ds in &available_datasets {
        println!("    - {} ({})", ds.name, ds.path.display());
    }

    // Check CLI argument or fallback to first available
    let cli_path = std::env::args().nth(1).map(PathBuf::from);
    let (initial_path, initial_name) = if let Some(p) = cli_path {
        let name = p.file_name().unwrap_or_default().to_string_lossy().to_string();
        (Some(p), name)
    } else if let Some(first) = available_datasets.first() {
        (Some(first.path.clone()), first.name.clone())
    } else {
        (None, String::new())
    };

    // 2. Allocate TripleBuffer PointCloud for live stream
    println!("[*] Allocating TripleBuffer PointCloud ({} points per queue)...", SIZE);
    let live_cloud = Arc::new(RwLock::new(AppPointCloud::new(
        pin_ptr(SIZE),
        pin_ptr(SIZE),
        pin_ptr(SIZE),
        pin_ptr(SIZE),
        pin_u16_ptr(SIZE),
    )));

    // 3. Allocate replay PointCloud for historical frame re-detection
    let replay_cloud = Arc::new(RwLock::new(AppPointCloud::new(
        pin_ptr(SIZE),
        pin_ptr(SIZE),
        pin_ptr(SIZE),
        pin_ptr(SIZE),
        pin_u16_ptr(SIZE),
    )));

    let history = Arc::new(Mutex::new(HistoryBuffer::new(50)));
    let last_incoming_frame = Arc::new(AtomicU64::new(0));
    let worker_processed_frame = Arc::new(AtomicU64::new(0));

    // 4. Initialize and spawn BagStreamer (starts PAUSED)
    let streamer = Arc::new(BagStreamer::new());
    if let Some(ref p) = initial_path {
        println!("[*] Ready dataset: {} ({}) [Paused, click Play to start]", initial_name, p.display());
        *streamer.active_path.lock().unwrap() = Some(p.clone());
    }

    BagStreamer::spawn_playback_thread(
        Arc::clone(&streamer),
        Arc::clone(&live_cloud),
        Arc::clone(&last_incoming_frame),
    );

    // 5. Connect to Rerun stream (do NOT spawn, just stream like rust_listener)
    let rerun_url = if !ENV.RERUN_URL.is_empty() {
        ENV.RERUN_URL.clone()
    } else {
        "rerun+http://127.0.0.1:9876".to_string()
    };
    println!("[*] Connecting to Rerun stream ({}) [no auto-spawn]...", rerun_url);
    let initial_rec = match RecordingStreamBuilder::new("rail_live_tuner")
        .connect_grpc_opts(rerun_url.clone())
    {
        Ok(s) => {
            println!("[+] Successfully connected to Rerun at: {}", rerun_url);
            Some(s)
        }
        Err(e) => {
            println!("[-] Note: Rerun not connected yet ({:?}). Running in standalone UI mode.", e);
            None
        }
    };
    let rerun_stream = Arc::new(Mutex::new(initial_rec));

    // Shared configuration between UI sliders and the Live background worker
    let live_config = Arc::new(RwLock::new(RailOrtConfig::default()));
    let reset_epoch = Arc::new(AtomicU64::new(0));
    let stream_to_rerun = Arc::new(AtomicBool::new(true));

    // 6. Spawn Background Worker thread for Live frame ingestion into 50-frame history
    let worker_live_cloud = Arc::clone(&live_cloud);
    let worker_history = Arc::clone(&history);
    let worker_counter = Arc::clone(&last_incoming_frame);
    let worker_processed_counter = Arc::clone(&worker_processed_frame);
    let worker_rerun = Arc::clone(&rerun_stream);
    let worker_live_config = Arc::clone(&live_config);
    let worker_reset_epoch = Arc::clone(&reset_epoch);
    let worker_stream_to_rerun = Arc::clone(&stream_to_rerun);

    std::thread::spawn(move || {
        let mut last_seen = 0u64;
        let mut last_reset_epoch = 0u64;
        let mut ort_detector = RailOrtDetector::new(
            LidarGeometry::new(128, 400, 15.0, -25.0, 40.0),
            RailOrtConfig::default(),
        );

        loop {
            let current = worker_counter.load(Ordering::Acquire);
            if current > last_seen {
                last_seen = current;

                // Check if detector reset was requested from UI
                let cur_epoch = worker_reset_epoch.load(Ordering::Relaxed);
                if cur_epoch != last_reset_epoch {
                    last_reset_epoch = cur_epoch;
                    ort_detector.reset();
                }

                // Dynamically sync detector config from UI sliders on every live frame
                if let Ok(cfg_guard) = worker_live_config.read() {
                    ort_detector.config = cfg_guard.clone();
                }

                // A. Swap NEXT -> READ under write lock
                {
                    let mut lock = worker_live_cloud.write().unwrap();
                    lock.change_state(ProcessingQueue::NEXT, ProcessingQueue::READ);
                }

                // B. Read frame under read lock
                let (snapshot, cropped_3d) = {
                    let lock = worker_live_cloud.read().unwrap();
                    let queue = ProcessingQueue::READ;
                    let len = lock.len(queue);
                    let w = lock.width[queue] as usize;
                    let h = lock.height[queue] as usize;
                    let ts = lock.timestamp[queue];

                    let xs = lock.x[queue][..len].to_vec();
                    let ys = lock.y[queue][..len].to_vec();
                    let zs = lock.z[queue][..len].to_vec();
                    let intensity = lock.intensity[queue][..len].to_vec();
                    let ring = lock.ring[queue][..len].to_vec();

                    let ri = RangeImage::from_pandar128_organized(&lock, queue, 1);
                    let crop_raw = ri.crop_fov(ENV.PREVIEW_FOV_X_DEG);
                    let geo = LidarGeometry::new(crop_raw.height, crop_raw.width, 15.0, -25.0, ENV.PREVIEW_FOV_X_DEG);

                    if ort_detector.geometry.height != crop_raw.height || ort_detector.geometry.width != crop_raw.width {
                        ort_detector.geometry = geo;
                    }

                    let mut cropped = ort_detector.crop_tunnel_rings(&lock, queue);
                    let res = ort_detector.process_rings(&mut cropped, &lock, queue, current as usize, Some(&crop_raw));

                    let cropped_3d: Vec<Vec<[f32; 3]>> = cropped
                        .iter()
                        .map(|r| r.iter().map(|p| p.get_xyz(&lock, queue)).collect())
                        .collect();

                    let snap = SnapshotFrame {
                        frame_idx: current as usize,
                        timestamp_ns: ts,
                        width: w,
                        height: h,
                        xs,
                        ys,
                        zs,
                        intensity,
                        ring,
                        range_image: crop_raw,
                        detection_result: res,
                        cropped_tunnel: cropped_3d.clone(),
                    };

                    (snap, cropped_3d)
                };

                // Stream to Rerun if connected and enabled
                if worker_stream_to_rerun.load(Ordering::Relaxed) {
                    let r_lock = worker_rerun.lock().unwrap();
                    if let Some(ref r_stream) = *r_lock {
                        r_stream.set_time_sequence("frame", current as i64);

                        let mut pts_real = Vec::with_capacity(snapshot.xs.len());
                        let mut colors = Vec::with_capacity(snapshot.xs.len());
                        for i in 0..snapshot.xs.len() {
                            let (x, y, z) = (snapshot.xs[i], snapshot.ys[i], snapshot.zs[i]);
                            if !is_zero_point(x, y, z) {
                                pts_real.push([x, y, z]);
                                let r = (x * x + y * y + z * z).sqrt();
                                let norm = (r / 200.0).clamp(0.0, 1.0);
                                let c = turbo_rgb(norm);
                                colors.push(Color::from_rgb(c[0], c[1], c[2]));
                            }
                        }
                        let _ = r_stream.log(
                            "lidar/point_cloud",
                            &Points3D::new(&pts_real)
                                .with_colors(colors)
                                .with_radii([Radius::new_ui_points(1.2)]),
                        );

                        let tunnel_flat: Vec<[f32; 3]> = cropped_3d.iter().flatten().copied().collect();
                        let _ = r_stream.log(
                            "tracks_ort/tunnel_cropped",
                            &Points3D::new(&tunnel_flat)
                                .with_colors([Color::from_rgb(255, 255, 0)])
                                .with_radii([Radius::new_ui_points(1.4)]),
                        );

                        r_stream.log_ort_detection_3d(snapshot.detection_result.as_ref());
                    }
                }

                // Push to 50-frame history buffer
                {
                    let mut hist = worker_history.lock().unwrap();
                    hist.push(snapshot);
                }

                // Signal that a new frame has been safely pushed to history
                worker_processed_counter.store(current, Ordering::Release);
            } else {
                std::thread::sleep(Duration::from_millis(10));
            }
        }
    });

    // 7. Launch eframe GUI on Main OS Thread
    let app = RailLiveTunerApp::new(
        history,
        replay_cloud,
        rerun_stream,
        rerun_url,
        worker_processed_frame,
        streamer,
        available_datasets,
        initial_name,
        live_config,
        reset_epoch,
        stream_to_rerun,
    );

    let native_options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_inner_size([1280.0, 840.0])
            .with_min_inner_size([850.0, 600.0])
            .with_title("RailOrt Live Tuner — Standalone Bag Dataset & Tuner"),
        ..Default::default()
    };

    eframe::run_native(
        "RailOrt Live Tuner",
        native_options,
        Box::new(|_cc| Ok(Box::new(app))),
    )?;

    Ok(())
}
