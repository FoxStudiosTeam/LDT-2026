//! rail_tuner_2d.rs — Interactive 2D Range Image Rail Detection & Extrapolation Tuner
//!
//! Features:
//! 1. Instant loading and scrubbing across all frames in `frames/` (or CLI directory).
//! 2. Interactive egui GUI for all 2D rail detection & extrapolation parameters:
//!    - Depth step thresholds (min / max)
//!    - Railway gauge constraints (nominal, min, max)
//!    - Scanline row search window (start %, end %)
//!    - Lateral jump continuity thresholds
//!    - Magenta polynomial extrapolation distance (m)
//!    - Temporal history smoothing window (N frames)
//! 3. Dual-window streaming to Rerun:
//!    - Window 1 (3D Scene): 3D Point cloud, 3D rail curves, 3D sleepers, 3D magenta extrapolation
//!    - Window 2 (2D Depth Map): 2D Range image, 2D rail curves, 2D sleepers, 2D magenta extrapolation
//! 4. Built-in interactive 2D Range view with Turbo colormap directly inside egui.
//! 5. Full player: Timeline scrubber, Play/Pause, Step forward/back, FPS control, Loop.
//! 6. Telemetry HUD: Gauge, Turn radius, Lateral shift, Point counts, Intensity, Latency.
//! 7. Config Export: One-click copy/print of tuned detector parameters as ready-to-paste Rust code.
//!
//! Usage:
//!   cargo run --bin rail_tuner_2d
//!   cargo run --bin rail_tuner_2d -- frames

use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicBool, AtomicUsize, Ordering};
use std::sync::{Arc, RwLock};
use std::time::{Duration, Instant};

use eframe::egui::{self, Color32, ColorImage, Key, TextureHandle, TextureOptions};
use rerun::{
    Boxes2D, Boxes3D, Color, LineStrips2D, LineStrips3D, Points2D, Points3D, Radius,
    RecordingStream, RecordingStreamBuilder,
};
use shared::rail_detection::{
    DetectionResult, LidarGeometry, ObstacleDetectionMode, RailTrackDetector,
};
use shared::range_image::RangeImage;

/// Google Turbo Colormap polynomial approximation
#[inline(always)]
fn turbo_rgb(x: f32) -> [u8; 3] {
    let x = x.clamp(0.0, 1.0);
    let r = 0.13572138
        + x * (4.61539260
            + x * (-42.66032258 + x * (132.13108234 + x * (-152.94239396 + x * 59.28637943))));
    let g = 0.09140261
        + x * (2.19418839
            + x * (4.84296658 + x * (-14.18503333 + x * (4.27729857 + x * 2.82956604))));
    let b = 0.10667330
        + x * (12.64194608
            + x * (-60.58204836 + x * (110.36276771 + x * (-89.90310912 + x * 27.34824973))));
    [
        (r.clamp(0.0, 1.0) * 255.0).round() as u8,
        (g.clamp(0.0, 1.0) * 255.0).round() as u8,
        (b.clamp(0.0, 1.0) * 255.0).round() as u8,
    ]
}

/// Находит все файлы frame_*.npy в директории
fn scan_npy_frames(dir: &Path) -> Vec<(usize, PathBuf)> {
    let mut files = Vec::new();
    if let Ok(entries) = std::fs::read_dir(dir) {
        for entry in entries.flatten() {
            let path = entry.path();
            if path.extension().and_then(|s| s.to_str()) == Some("npy") {
                if let Some(file_name) = path.file_stem().and_then(|s| s.to_str()) {
                    if file_name.starts_with("frame_") {
                        if let Ok(idx) = file_name["frame_".len()..].parse::<usize>() {
                            files.push((idx, path));
                        }
                    }
                }
            }
        }
    }
    files.sort_by_key(|&(idx, _)| idx);
    files
}

/// Распарсенный кадр для воспроизведения в тюнере
#[derive(Clone)]
pub struct TunerFrame {
    pub idx: usize,
    pub range_image: RangeImage,
}

/// Хранилище загруженных кадров
pub struct FrameDataset {
    pub frames: Arc<RwLock<Vec<TunerFrame>>>,
    pub is_loading: Arc<AtomicBool>,
    pub loaded_count: Arc<AtomicUsize>,
    pub total_count: usize,
}

impl FrameDataset {
    pub fn from_npy_paths(paths: Vec<(usize, PathBuf)>) -> Self {
        let total = paths.len();
        let frames = Arc::new(RwLock::new(Vec::with_capacity(total)));
        let is_loading = Arc::new(AtomicBool::new(true));
        let loaded_count = Arc::new(AtomicUsize::new(0));

        let bg_frames = Arc::clone(&frames);
        let bg_is_loading = Arc::clone(&is_loading);
        let bg_loaded_count = Arc::clone(&loaded_count);

        std::thread::spawn(move || {
            for (idx, path) in paths {
                if let Ok(ri) = RangeImage::load_npy(&path) {
                    let mut lock = bg_frames.write().unwrap();
                    lock.push(TunerFrame {
                        idx,
                        range_image: ri,
                    });
                    bg_loaded_count.fetch_add(1, Ordering::Relaxed);
                }
            }
            bg_is_loading.store(false, Ordering::SeqCst);
        });

        Self {
            frames,
            is_loading,
            loaded_count,
            total_count: total,
        }
    }
}

/// 2D визуализатор карты глубины для отображения текстуры в egui
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
        res: Option<&DetectionResult>,
        geo: &LidarGeometry,
        clearance_width: f32,
    ) -> ColorImage {
        let w = frame.width;
        let h = frame.height;
        let out_w = w * self.scale;
        let out_h = h * self.scale;

        let mut rgb = vec![0u8; out_w * out_h * 3];

        // 1. Colorize depth map with Turbo
        for r in 0..h {
            for c in 0..w {
                let val = frame.data[r * w + c];
                let color = if val <= 0.0 {
                    [10, 12, 16]
                } else {
                    let norm = (val / 200.0).clamp(0.0, 1.0);
                    turbo_rgb(norm)
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

        // 2. Draw 2D track overlays
        if let Some(r) = res {
            let to_px = |xs: &[f32], ys: &[f32], zs: &[f32]| -> Vec<(i32, i32)> {
                let mut out = Vec::new();
                for i in 0..xs.len() {
                    let (row, col) = geo.xyz_to_row_col(xs[i], ys[i], zs[i]);
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
                let (row_l, col_l) = geo.xyz_to_row_col(r.x_left[i], r.y_left[i], r.z_center[i]);
                let (row_r, col_r) = geo.xyz_to_row_col(r.x_right[i], r.y_right[i], r.z_center[i]);
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

            // Clearance boundary projection (subtle dashed amber/yellow lines)
            let half_w = clearance_width * 0.5;
            let mut clear_l = Vec::new();
            let mut clear_r = Vec::new();
            for i in (0..r.x_curve.len()).step_by(2) {
                let x = r.x_curve[i];
                let y = r.y_center[i];
                let z = r.z_center[i];
                let (r_l, c_l) = geo.xyz_to_row_col(x, y - half_w, z);
                let (r_r, c_r) = geo.xyz_to_row_col(x, y + half_w, z);
                if r_l >= 0 && (r_l as usize) < h && c_l >= 0 && (c_l as usize) < w {
                    clear_l.push(((c_l as usize * self.scale) as i32, (r_l as usize * self.scale) as i32));
                }
                if r_r >= 0 && (r_r as usize) < h && c_r >= 0 && (c_r as usize) < w {
                    clear_r.push(((c_r as usize * self.scale) as i32, (r_r as usize * self.scale) as i32));
                }
            }
            draw_line_rgb(&mut rgb, out_w, out_h, &clear_l, [240, 200, 50], 1);
            draw_line_rgb(&mut rgb, out_w, out_h, &clear_r, [240, 200, 50], 1);

            // Detected discrete points
            for p in &r.points {
                if p.row < h {
                    if p.col_left < w {
                        draw_dot_rgb(
                            &mut rgb,
                            out_w,
                            out_h,
                            (p.col_left * self.scale) as i32,
                            (p.row * self.scale) as i32,
                            2,
                            [0, 255, 255],
                        );
                    }
                    if p.col_right < w {
                        draw_dot_rgb(
                            &mut rgb,
                            out_w,
                            out_h,
                            (p.col_right * self.scale) as i32,
                            (p.row * self.scale) as i32,
                            2,
                            [255, 120, 0],
                        );
                    }
                }
            }

            // 7. Detected obstacles 2D bounding boxes (Red = Critical on-track, Amber = Clearance intrusion)
            for o in &r.obstacles {
                let col = if o.is_critical {
                    [255, 30, 30] // Red: in-gauge threat
                } else {
                    [255, 170, 0] // Amber: clearance envelope intrusion
                };
                let x0 = (o.bbox_2d[0] * self.scale) as i32;
                let y0 = (o.bbox_2d[1] * self.scale) as i32;
                let x1 = ((o.bbox_2d[2] + 1) * self.scale) as i32;
                let y1 = ((o.bbox_2d[3] + 1) * self.scale) as i32;

                draw_rect_rgb(&mut rgb, out_w, out_h, x0, y0, x1, y1, col, 2);

                // Corner bracket accents (White) for high visibility against turbo background
                let c_len = (6 * self.scale as i32 / 3).max(4).min((x1 - x0).abs() / 2).min((y1 - y0).abs() / 2);
                if c_len > 1 {
                    // Top-left
                    draw_line_rgb(&mut rgb, out_w, out_h, &[(x0, y0), (x0 + c_len, y0)], [255, 255, 255], 2);
                    draw_line_rgb(&mut rgb, out_w, out_h, &[(x0, y0), (x0, y0 + c_len)], [255, 255, 255], 2);
                    // Top-right
                    draw_line_rgb(&mut rgb, out_w, out_h, &[(x1, y0), (x1 - c_len, y0)], [255, 255, 255], 2);
                    draw_line_rgb(&mut rgb, out_w, out_h, &[(x1, y0), (x1, y0 + c_len)], [255, 255, 255], 2);
                    // Bottom-left
                    draw_line_rgb(&mut rgb, out_w, out_h, &[(x0, y1), (x0 + c_len, y1)], [255, 255, 255], 2);
                    draw_line_rgb(&mut rgb, out_w, out_h, &[(x0, y1), (x0, y1 - c_len)], [255, 255, 255], 2);
                    // Bottom-right
                    draw_line_rgb(&mut rgb, out_w, out_h, &[(x1, y1), (x1 - c_len, y1)], [255, 255, 255], 2);
                    draw_line_rgb(&mut rgb, out_w, out_h, &[(x1, y1), (x1, y1 - c_len)], [255, 255, 255], 2);
                }

                // If critical, fill top 3-pixel badge
                if o.is_critical {
                    for ty in y0..=(y0 + 3).min(y1) {
                        for tx in x0..=x1 {
                            if tx >= 0 && (tx as usize) < out_w && ty >= 0 && (ty as usize) < out_h {
                                let idx = (ty as usize * out_w + tx as usize) * 3;
                                rgb[idx] = 255;
                                rgb[idx + 1] = 30;
                                rgb[idx + 2] = 30;
                            }
                        }
                    }
                }
            }
        }

        ColorImage::from_rgb([out_w, out_h], &rgb)
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
    col: [u8; 3],
    thick: i32,
) {
    let min_x = x0.min(x1);
    let max_x = x0.max(x1);
    let min_y = y0.min(y1);
    let max_y = y0.max(y1);

    for t in 0..thick {
        for x in min_x..=max_x {
            for &y in &[min_y + t, max_y - t] {
                if x >= 0 && (x as usize) < w && y >= 0 && (y as usize) < h {
                    let idx = (y as usize * w + x as usize) * 3;
                    rgb[idx] = col[0];
                    rgb[idx + 1] = col[1];
                    rgb[idx + 2] = col[2];
                }
            }
        }
        for y in min_y..=max_y {
            for &x in &[min_x + t, max_x - t] {
                if x >= 0 && (x as usize) < w && y >= 0 && (y as usize) < h {
                    let idx = (y as usize * w + x as usize) * 3;
                    rgb[idx] = col[0];
                    rgb[idx + 1] = col[1];
                    rgb[idx + 2] = col[2];
                }
            }
        }
    }
}

fn draw_dot_rgb(rgb: &mut [u8], w: usize, h: usize, cx: i32, cy: i32, rad: i32, col: [u8; 3]) {
    for dy in -rad..=rad {
        for dx in -rad..=rad {
            if dx * dx + dy * dy <= rad * rad {
                let x = cx + dx;
                let y = cy + dy;
                if x >= 0 && (x as usize) < w && y >= 0 && (y as usize) < h {
                    let idx = (y as usize * w + x as usize) * 3;
                    rgb[idx] = col[0];
                    rgb[idx + 1] = col[1];
                    rgb[idx + 2] = col[2];
                }
            }
        }
    }
}

fn draw_line_rgb(rgb: &mut [u8], w: usize, h: usize, pts: &[(i32, i32)], col: [u8; 3], thick: i32) {
    if pts.len() < 2 {
        return;
    }
    for i in 0..pts.len() - 1 {
        let (mut x0, mut y0) = pts[i];
        let (x1, y1) = pts[i + 1];
        let dx = (x1 - x0).abs();
        let dy = (y1 - y0).abs();
        let sx = if x0 < x1 { 1 } else { -1 };
        let sy = if y0 < y1 { 1 } else { -1 };
        let mut err = dx - dy;

        let half = thick / 2;
        loop {
            for ty in -half..=half {
                for tx in -half..=half {
                    let px = x0 + tx;
                    let py = y0 + ty;
                    if px >= 0 && (px as usize) < w && py >= 0 && (py as usize) < h {
                        let idx = (py as usize * w + px as usize) * 3;
                        rgb[idx] = col[0];
                        rgb[idx + 1] = col[1];
                        rgb[idx + 2] = col[2];
                    }
                }
            }
            if x0 == x1 && y0 == y1 {
                break;
            }
            let e2 = 2 * err;
            if e2 > -dy {
                err -= dy;
                x0 += sx;
            }
            if e2 < dx {
                err += dx;
                y0 += sy;
            }
        }
    }
}

/// Интерактивное приложение RailTuner2D
pub struct RailTuner2DApp {
    dataset: FrameDataset,
    current_frame_idx: usize,
    is_playing: bool,
    fps: f32,
    last_tick: Instant,

    // Параметры детектора
    depth_step_thresh: f32,
    max_depth_step_thresh: f32,
    nominal_gauge: f32,
    min_gauge: f32,
    max_gauge: f32,
    row_start_pct: f32,
    row_end_pct: f32,
    max_lateral_jump: f32,
    max_lateral_rail_jump: f32,
    extrapolate_m: f32,
    smooth_n: usize,

    // Параметры детектора препятствий
    obstacle_enabled: bool,
    obstacle_mode: ObstacleDetectionMode,
    clearance_width: f32,
    min_height_above_rail: f32,
    max_height_above_rail: f32,
    min_points: usize,
    max_distance_m: f32,
    depth_diff_thresh: f32,

    // Rerun
    rec_stream: Option<RecordingStream>,
    stream_to_rerun: bool,

    // UI state
    detector: RailTrackDetector,
    last_res: Option<DetectionResult>,
    last_calc_dur: Duration,
    painter: EguiRangePainter,
    texture: Option<TextureHandle>,
    last_painted_frame: Option<usize>,
    copied_toast_time: Option<Instant>,
}

impl RailTuner2DApp {
    pub fn new(dataset: FrameDataset, rec_stream: Option<RecordingStream>) -> Self {
        let initial_geo = LidarGeometry::new(128, 140, 15.0, -25.0, 40.0);
        let detector = RailTrackDetector::new(initial_geo);

        Self {
            dataset,
            current_frame_idx: 0,
            is_playing: false,
            fps: 12.0,
            last_tick: Instant::now(),

            depth_step_thresh: detector.depth_step_thresh,
            max_depth_step_thresh: detector.max_depth_step_thresh,
            nominal_gauge: detector.nominal_gauge,
            min_gauge: detector.min_gauge,
            max_gauge: detector.max_gauge,
            row_start_pct: detector.row_start_pct,
            row_end_pct: detector.row_end_pct,
            max_lateral_jump: detector.max_lateral_jump,
            max_lateral_rail_jump: detector.max_lateral_rail_jump,
            extrapolate_m: detector.extrapolate_m,
            smooth_n: detector.smooth_n,

            obstacle_enabled: detector.obstacle_config.enabled,
            obstacle_mode: detector.obstacle_config.mode,
            clearance_width: detector.obstacle_config.clearance_width,
            min_height_above_rail: detector.obstacle_config.min_height_above_rail,
            max_height_above_rail: detector.obstacle_config.max_height_above_rail,
            min_points: detector.obstacle_config.min_points,
            max_distance_m: detector.obstacle_config.max_distance_m,
            depth_diff_thresh: detector.obstacle_config.depth_diff_thresh,

            rec_stream,
            stream_to_rerun: true,

            detector,
            last_res: None,
            last_calc_dur: Duration::ZERO,
            painter: EguiRangePainter::new(3),
            texture: None,
            last_painted_frame: None,
            copied_toast_time: None,
        }
    }

    fn sync_detector_params(&mut self) {
        self.detector.depth_step_thresh = self.depth_step_thresh;
        self.detector.max_depth_step_thresh = self.max_depth_step_thresh;
        self.detector.nominal_gauge = self.nominal_gauge;
        self.detector.min_gauge = self.min_gauge;
        self.detector.max_gauge = self.max_gauge;
        self.detector.row_start_pct = self.row_start_pct;
        self.detector.row_end_pct = self.row_end_pct;
        self.detector.max_lateral_jump = self.max_lateral_jump;
        self.detector.max_lateral_rail_jump = self.max_lateral_rail_jump;
        self.detector.extrapolate_m = self.extrapolate_m;
        self.detector.smooth_n = self.smooth_n;

        self.detector.obstacle_config.enabled = self.obstacle_enabled;
        self.detector.obstacle_config.mode = self.obstacle_mode;
        self.detector.obstacle_config.clearance_width = self.clearance_width;
        self.detector.obstacle_config.min_height_above_rail = self.min_height_above_rail;
        self.detector.obstacle_config.max_height_above_rail = self.max_height_above_rail;
        self.detector.obstacle_config.min_points = self.min_points;
        self.detector.obstacle_config.max_distance_m = self.max_distance_m;
        self.detector.obstacle_config.depth_diff_thresh = self.depth_diff_thresh;
    }

    fn process_current_frame(&mut self) {
        let frame_opt = {
            let lock = self.dataset.frames.read().unwrap();
            if lock.is_empty() || self.current_frame_idx >= lock.len() {
                None
            } else {
                Some(lock[self.current_frame_idx].clone())
            }
        };

        let Some(frame) = frame_opt else {
            return;
        };

        if self.detector.geometry.height != frame.range_image.height
            || self.detector.geometry.width != frame.range_image.width
        {
            self.detector.geometry = LidarGeometry::new(
                frame.range_image.height,
                frame.range_image.width,
                15.0,
                -25.0,
                40.0,
            );
        }

        self.sync_detector_params();

        let t0 = Instant::now();
        self.last_res = self.detector.detect(&frame.range_image, frame.idx);
        self.last_calc_dur = t0.elapsed();

        // Отправка в Rerun (2 окна: 3D и 2D)
        if self.stream_to_rerun {
            if let Some(ref rec) = self.rec_stream {
                rec.set_time_sequence("frame", frame.idx as i64);

                let geo = &self.detector.geometry;
                let ri = &frame.range_image;
                let res = self.last_res.as_ref();

                // ─── ОКНО 1: 3D сцена ───
                // 3D Point cloud из RangeImage
                let total = geo.height * geo.width;
                let mut pts = Vec::with_capacity(total);
                let mut colors = Vec::with_capacity(total);
                for row in 0..geo.height {
                    let r_off = row * geo.width;
                    for col in 0..geo.width {
                        let r = ri.data[r_off + col];
                        if r > 0.5 && r < 200.0 {
                            let (x, y, z) = geo.row_col_range_to_xyz(row, col, r);
                            pts.push([x, y, z]);
                            let norm = (r / 200.0).clamp(0.0, 1.0);
                            let c = turbo_rgb(norm);
                            colors.push(Color::from_rgb(c[0], c[1], c[2]));
                        }
                    }
                }
                let _ = rec.log(
                    "lidar/point_cloud",
                    &Points3D::new(pts)
                        .with_colors(colors)
                        .with_radii([Radius::new_ui_points(1.2)]),
                );

                if let Some(r) = res {
                    let center_pts: Vec<[f32; 3]> = (0..r.x_curve.len())
                        .map(|i| [r.x_curve[i], r.y_center[i], r.z_center[i]])
                        .collect();
                    let left_pts: Vec<[f32; 3]> = (0..r.x_left.len())
                        .map(|i| [r.x_left[i], r.y_left[i], r.z_center[i]])
                        .collect();
                    let right_pts: Vec<[f32; 3]> = (0..r.x_right.len())
                        .map(|i| [r.x_right[i], r.y_right[i], r.z_center[i]])
                        .collect();

                    let _ = rec.log(
                        "tracks/3d/centerline",
                        &LineStrips3D::new([center_pts])
                            .with_colors([Color::from_rgb(0, 255, 60)])
                            .with_radii([Radius::new_ui_points(2.5)]),
                    );
                    let _ = rec.log(
                        "tracks/3d/left_rail",
                        &LineStrips3D::new([left_pts])
                            .with_colors([Color::from_rgb(30, 210, 255)])
                            .with_radii([Radius::new_ui_points(2.5)]),
                    );
                    let _ = rec.log(
                        "tracks/3d/right_rail",
                        &LineStrips3D::new([right_pts])
                            .with_colors([Color::from_rgb(255, 90, 30)])
                            .with_radii([Radius::new_ui_points(2.5)]),
                    );

                    let mut sleepers: Vec<Vec<[f32; 3]>> = Vec::new();
                    for i in (0..r.x_curve.len()).step_by(4) {
                        sleepers.push(vec![
                            [r.x_left[i], r.y_left[i], r.z_center[i]],
                            [r.x_right[i], r.y_right[i], r.z_center[i]],
                        ]);
                    }
                    let _ = rec.log(
                        "tracks/3d/sleepers",
                        &LineStrips3D::new(sleepers)
                            .with_colors([Color::from_rgb(180, 220, 180)])
                            .with_radii([Radius::new_ui_points(1.2)]),
                    );

                    // 3D Extrapolation (Magenta)
                    if !r.x_ext.is_empty() {
                        let ext_c: Vec<[f32; 3]> = (0..r.x_ext.len())
                            .map(|i| [r.x_ext[i], r.y_ext[i], r.z_ext[i]])
                            .collect();
                        let ext_l: Vec<[f32; 3]> = (0..r.x_ext_l.len())
                            .map(|i| [r.x_ext_l[i], r.y_ext_l[i], r.z_ext[i]])
                            .collect();
                        let ext_r: Vec<[f32; 3]> = (0..r.x_ext_r.len())
                            .map(|i| [r.x_ext_r[i], r.y_ext_r[i], r.z_ext[i]])
                            .collect();
                        let _ = rec.log(
                            "tracks/3d/extrapolation_center",
                            &LineStrips3D::new([ext_c])
                                .with_colors([Color::from_rgb(255, 0, 255)])
                                .with_radii([Radius::new_ui_points(2.0)]),
                        );
                        let _ = rec.log(
                            "tracks/3d/extrapolation_left",
                            &LineStrips3D::new([ext_l])
                                .with_colors([Color::from_rgb(200, 50, 200)])
                                .with_radii([Radius::new_ui_points(1.5)]),
                        );
                        let _ = rec.log(
                            "tracks/3d/extrapolation_right",
                            &LineStrips3D::new([ext_r])
                                .with_colors([Color::from_rgb(200, 50, 200)])
                                .with_radii([Radius::new_ui_points(1.5)]),
                        );
                    }

                    // 3D Obstacles
                    if !r.obstacles.is_empty() {
                        let centers: Vec<[f32; 3]> = r
                            .obstacles
                            .iter()
                            .map(|o| {
                                [
                                    (o.bbox_3d_min[0] + o.bbox_3d_max[0]) * 0.5,
                                    (o.bbox_3d_min[1] + o.bbox_3d_max[1]) * 0.5,
                                    (o.bbox_3d_min[2] + o.bbox_3d_max[2]) * 0.5,
                                ]
                            })
                            .collect();
                        let sizes: Vec<[f32; 3]> = r
                            .obstacles
                            .iter()
                            .map(|o| {
                                [
                                    (o.bbox_3d_max[0] - o.bbox_3d_min[0]).max(0.2),
                                    (o.bbox_3d_max[1] - o.bbox_3d_min[1]).max(0.2),
                                    (o.bbox_3d_max[2] - o.bbox_3d_min[2]).max(0.2),
                                ]
                            })
                            .collect();
                        let colors: Vec<Color> = r
                            .obstacles
                            .iter()
                            .map(|o| {
                                if o.is_critical {
                                    Color::from_rgb(255, 30, 30)
                                } else {
                                    Color::from_rgb(255, 170, 0)
                                }
                            })
                            .collect();
                        let labels: Vec<String> = r
                            .obstacles
                            .iter()
                            .map(|o| {
                                if o.is_critical {
                                    format!("CRITICAL {:.1}m", o.distance_along_track)
                                } else {
                                    format!("WARN {:.1}m", o.distance_along_track)
                                }
                            })
                            .collect();

                        let _ = rec.log(
                            "tracks/3d/obstacles",
                            &Boxes3D::from_centers_and_sizes(centers, sizes)
                                .with_colors(colors)
                                .with_labels(labels),
                        );
                    } else {
                        let _ = rec.log(
                            "tracks/3d/obstacles",
                            &Boxes3D::from_centers_and_sizes([] as [[f32; 3]; 0], [] as [[f32; 3]; 0]),
                        );
                    }
                } else {
                    let _ = rec.log(
                        "tracks/3d/centerline",
                        &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
                    );
                    let _ = rec.log(
                        "tracks/3d/left_rail",
                        &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
                    );
                    let _ = rec.log(
                        "tracks/3d/right_rail",
                        &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
                    );
                    let _ = rec.log(
                        "tracks/3d/sleepers",
                        &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
                    );
                    let _ = rec.log(
                        "tracks/3d/extrapolation_center",
                        &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
                    );
                    let _ = rec.log(
                        "tracks/3d/obstacles",
                        &Boxes3D::from_centers_and_sizes([] as [[f32; 3]; 0], [] as [[f32; 3]; 0]),
                    );
                }

                // ─── ОКНО 2: 2D Карта глубины ───
                if let Ok(depth_img) = ri.to_rerun() {
                    let _ = rec.log("depth_map/image", &depth_img);
                }

                if let Some(r) = res {
                    let h = ri.height;
                    let w = ri.width;
                    let to_img_pts = |xs: &[f32], ys: &[f32], zs: &[f32]| -> Vec<[f32; 2]> {
                        let mut out = Vec::new();
                        for i in 0..xs.len() {
                            let (row, col) = geo.xyz_to_row_col(xs[i], ys[i], zs[i]);
                            if row >= 0 && (row as usize) < h && col >= 0 && (col as usize) < w {
                                out.push([col as f32, row as f32]);
                            }
                        }
                        out
                    };

                    let pts_c = to_img_pts(&r.x_curve, &r.y_center, &r.z_center);
                    let pts_l = to_img_pts(&r.x_left, &r.y_left, &r.z_center);
                    let pts_r = to_img_pts(&r.x_right, &r.y_right, &r.z_center);

                    let _ = rec.log(
                        "depth_map/tracks/centerline",
                        &LineStrips2D::new([pts_c])
                            .with_colors([Color::from_rgb(0, 255, 60)])
                            .with_radii([Radius::new_ui_points(2.5)]),
                    );
                    let _ = rec.log(
                        "depth_map/tracks/left_rail",
                        &LineStrips2D::new([pts_l])
                            .with_colors([Color::from_rgb(30, 210, 255)])
                            .with_radii([Radius::new_ui_points(2.5)]),
                    );
                    let _ = rec.log(
                        "depth_map/tracks/right_rail",
                        &LineStrips2D::new([pts_r])
                            .with_colors([Color::from_rgb(255, 90, 30)])
                            .with_radii([Radius::new_ui_points(2.5)]),
                    );

                    // Sleepers 2D
                    let mut sleepers2d: Vec<Vec<[f32; 2]>> = Vec::new();
                    for i in (0..r.x_curve.len()).step_by(4) {
                        let (row_l, col_l) =
                            geo.xyz_to_row_col(r.x_left[i], r.y_left[i], r.z_center[i]);
                        let (row_r, col_r) =
                            geo.xyz_to_row_col(r.x_right[i], r.y_right[i], r.z_center[i]);
                        if row_l >= 0
                            && (row_l as usize) < h
                            && col_l >= 0
                            && (col_l as usize) < w
                            && row_r >= 0
                            && (row_r as usize) < h
                            && col_r >= 0
                            && (col_r as usize) < w
                        {
                            sleepers2d.push(vec![
                                [col_l as f32, row_l as f32],
                                [col_r as f32, row_r as f32],
                            ]);
                        }
                    }
                    let _ = rec.log(
                        "depth_map/tracks/sleepers",
                        &LineStrips2D::new(sleepers2d)
                            .with_colors([Color::from_rgb(180, 220, 180)])
                            .with_radii([Radius::new_ui_points(1.2)]),
                    );

                    // 2D Extrapolation (Magenta)
                    if !r.x_ext.is_empty() {
                        let ext_c = to_img_pts(&r.x_ext, &r.y_ext, &r.z_ext);
                        let ext_l = to_img_pts(&r.x_ext_l, &r.y_ext_l, &r.z_ext);
                        let ext_r = to_img_pts(&r.x_ext_r, &r.y_ext_r, &r.z_ext);
                        let _ = rec.log(
                            "depth_map/tracks/extrapolation_center",
                            &LineStrips2D::new([ext_c])
                                .with_colors([Color::from_rgb(255, 0, 255)])
                                .with_radii([Radius::new_ui_points(2.0)]),
                        );
                        let _ = rec.log(
                            "depth_map/tracks/extrapolation_left",
                            &LineStrips2D::new([ext_l])
                                .with_colors([Color::from_rgb(200, 50, 200)])
                                .with_radii([Radius::new_ui_points(1.5)]),
                        );
                        let _ = rec.log(
                            "depth_map/tracks/extrapolation_right",
                            &LineStrips2D::new([ext_r])
                                .with_colors([Color::from_rgb(200, 50, 200)])
                                .with_radii([Radius::new_ui_points(1.5)]),
                        );
                    }

                    // 2D discrete point markers
                    let mut pts_det_l = Vec::new();
                    let mut pts_det_r = Vec::new();
                    for p in &r.points {
                        if p.row < h {
                            if p.col_left < w {
                                pts_det_l.push([p.col_left as f32, p.row as f32]);
                            }
                            if p.col_right < w {
                                pts_det_r.push([p.col_right as f32, p.row as f32]);
                            }
                        }
                    }
                    let _ = rec.log(
                        "depth_map/tracks/points_left",
                        &Points2D::new(pts_det_l)
                            .with_colors([Color::from_rgb(0, 255, 255)])
                            .with_radii([Radius::new_ui_points(3.0)]),
                    );
                    let _ = rec.log(
                        "depth_map/tracks/points_right",
                        &Points2D::new(pts_det_r)
                            .with_colors([Color::from_rgb(255, 120, 0)])
                            .with_radii([Radius::new_ui_points(3.0)]),
                    );

                    // 2D Obstacles
                    if !r.obstacles.is_empty() {
                        let mins: Vec<[f32; 2]> = r
                            .obstacles
                            .iter()
                            .map(|o| [o.bbox_2d[0] as f32, o.bbox_2d[1] as f32])
                            .collect();
                        let sizes: Vec<[f32; 2]> = r
                            .obstacles
                            .iter()
                            .map(|o| {
                                [
                                    (o.bbox_2d[2].saturating_sub(o.bbox_2d[0]) + 1).max(2) as f32,
                                    (o.bbox_2d[3].saturating_sub(o.bbox_2d[1]) + 1).max(2) as f32,
                                ]
                            })
                            .collect();
                        let colors: Vec<Color> = r
                            .obstacles
                            .iter()
                            .map(|o| {
                                if o.is_critical {
                                    Color::from_rgb(255, 30, 30)
                                } else {
                                    Color::from_rgb(255, 170, 0)
                                }
                            })
                            .collect();
                        let labels: Vec<String> = r
                            .obstacles
                            .iter()
                            .map(|o| {
                                if o.is_critical {
                                    format!("CRITICAL {:.1}m", o.distance_along_track)
                                } else {
                                    format!("WARN {:.1}m", o.distance_along_track)
                                }
                            })
                            .collect();

                        let _ = rec.log(
                            "depth_map/tracks/obstacles",
                            &Boxes2D::from_mins_and_sizes(mins, sizes)
                                .with_colors(colors)
                                .with_labels(labels),
                        );
                    } else {
                        let _ = rec.log(
                            "depth_map/tracks/obstacles",
                            &Boxes2D::from_mins_and_sizes([] as [[f32; 2]; 0], [] as [[f32; 2]; 0]),
                        );
                    }
                } else {
                    let _ = rec.log(
                        "depth_map/tracks/obstacles",
                        &Boxes2D::from_mins_and_sizes([] as [[f32; 2]; 0], [] as [[f32; 2]; 0]),
                    );
                    let _ = rec.log(
                        "depth_map/tracks/centerline",
                        &LineStrips2D::new([] as [Vec<[f32; 2]>; 0]),
                    );
                    let _ = rec.log(
                        "depth_map/tracks/left_rail",
                        &LineStrips2D::new([] as [Vec<[f32; 2]>; 0]),
                    );
                    let _ = rec.log(
                        "depth_map/tracks/right_rail",
                        &LineStrips2D::new([] as [Vec<[f32; 2]>; 0]),
                    );
                    let _ = rec.log(
                        "depth_map/tracks/sleepers",
                        &LineStrips2D::new([] as [Vec<[f32; 2]>; 0]),
                    );
                    let _ = rec.log(
                        "depth_map/tracks/extrapolation_center",
                        &LineStrips2D::new([] as [Vec<[f32; 2]>; 0]),
                    );
                }
            }
        }
    }
}

impl eframe::App for RailTuner2DApp {
    fn ui(&mut self, ui: &mut egui::Ui, _frame: &mut eframe::Frame) {
        // Handle keyboard shortcuts
        let input = ui.input(|i| {
            (
                i.key_pressed(Key::Space),
                i.key_pressed(Key::ArrowLeft) || i.key_pressed(Key::A),
                i.key_pressed(Key::ArrowRight) || i.key_pressed(Key::D),
            )
        });

        if input.0 {
            self.is_playing = !self.is_playing;
        }
        if input.1 && self.current_frame_idx > 0 {
            self.current_frame_idx -= 1;
            self.detector.reset();
            self.process_current_frame();
        }
        let total_loaded = self.dataset.loaded_count.load(Ordering::Relaxed);
        if input.2 && self.current_frame_idx + 1 < total_loaded {
            self.current_frame_idx += 1;
            self.process_current_frame();
        }

        // Playback ticker
        if self.is_playing && total_loaded > 0 {
            let interval = Duration::from_secs_f32(1.0 / self.fps.max(1.0));
            if self.last_tick.elapsed() >= interval {
                self.last_tick = Instant::now();
                if self.current_frame_idx + 1 < total_loaded {
                    self.current_frame_idx += 1;
                } else {
                    self.current_frame_idx = 0;
                    self.detector.reset();
                }
                self.process_current_frame();
            }
            ui.ctx().request_repaint();
        }

        // Initial process
        if self.last_painted_frame != Some(self.current_frame_idx) && total_loaded > 0 {
            self.process_current_frame();
            self.last_painted_frame = Some(self.current_frame_idx);

            let lock = self.dataset.frames.read().unwrap();
            if self.current_frame_idx < lock.len() {
                let f = &lock[self.current_frame_idx];
                let color_img = self.painter.paint(
                    &f.range_image,
                    self.last_res.as_ref(),
                    &self.detector.geometry,
                    self.clearance_width,
                );
                self.texture = Some(ui.ctx().load_texture(
                    "range_view",
                    color_img,
                    TextureOptions::LINEAR,
                ));
            }
        }

        // Main 2-column layout: Controls on Left, 2D Range View on Right
        egui::ScrollArea::vertical().show(ui, |ui| {
            // Header Bar
            ui.horizontal(|ui| {
                ui.heading("🛤️ Rail Tuner 2D — Range Image Rail & Extrapolation Tuner");
                ui.separator();
                let is_loading = self.dataset.is_loading.load(Ordering::Relaxed);
                if is_loading {
                    ui.label(format!(
                        "⏳ Loading: {}/{} frames",
                        total_loaded, self.dataset.total_count
                    ));
                } else {
                    ui.label(format!("✅ Ready: {} frames", total_loaded));
                }

                ui.with_layout(egui::Layout::right_to_left(egui::Align::Center), |ui| {
                    if let Some(t) = self.copied_toast_time {
                        if t.elapsed() < Duration::from_secs(2) {
                            ui.colored_label(Color32::GREEN, "📋 Copied Rust Config!");
                        }
                    }
                    if ui.button("📋 Copy Rust Config").clicked() {
                        let cfg = format!(
                            "// Tuned RailTrackDetector Config\n\
                             let mut detector = RailTrackDetector::new(geo);\n\
                             detector.depth_step_thresh = {:.3};\n\
                             detector.max_depth_step_thresh = {:.3};\n\
                             detector.nominal_gauge = {:.3};\n\
                             detector.min_gauge = {:.3};\n\
                             detector.max_gauge = {:.3};\n\
                             detector.row_start_pct = {:.3};\n\
                             detector.row_end_pct = {:.3};\n\
                             detector.max_lateral_jump = {:.3};\n\
                             detector.max_lateral_rail_jump = {:.3};\n\
                             detector.extrapolate_m = {:.1};\n\
                             detector.smooth_n = {};\n\
                             detector.obstacle_config.enabled = {};\n\
                             detector.obstacle_config.mode = shared::rail_detection::ObstacleDetectionMode::{:?};\n\
                             detector.obstacle_config.clearance_width = {:.2};\n\
                             detector.obstacle_config.min_height_above_rail = {:.2};\n\
                             detector.obstacle_config.max_height_above_rail = {:.2};\n\
                             detector.obstacle_config.min_points = {};\n\
                             detector.obstacle_config.max_distance_m = {:.1};\n\
                             detector.obstacle_config.depth_diff_thresh = {:.2};",
                            self.depth_step_thresh,
                            self.max_depth_step_thresh,
                            self.nominal_gauge,
                            self.min_gauge,
                            self.max_gauge,
                            self.row_start_pct,
                            self.row_end_pct,
                            self.max_lateral_jump,
                            self.max_lateral_rail_jump,
                            self.extrapolate_m,
                            self.smooth_n,
                            self.obstacle_enabled,
                            self.obstacle_mode,
                            self.clearance_width,
                            self.min_height_above_rail,
                            self.max_height_above_rail,
                            self.min_points,
                            self.max_distance_m,
                            self.depth_diff_thresh,
                        );
                        ui.ctx().copy_text(cfg.clone());
                        println!("\n{}\n", cfg);
                        self.copied_toast_time = Some(Instant::now());
                    }

                    ui.checkbox(&mut self.stream_to_rerun, "📡 Stream to Rerun (2 Views)");
                });
            });

            ui.separator();

            ui.columns(2, |cols| {
                // ─── LEFT COLUMN: Parameters & Telemetry ───
                let left = &mut cols[0];

                left.group(|ui| {
                    ui.heading("⏯ Player Controls");
                    ui.horizontal(|ui| {
                        if ui
                            .button(if self.is_playing {
                                "⏸ Pause"
                            } else {
                                "▶ Play"
                            })
                            .clicked()
                        {
                            self.is_playing = !self.is_playing;
                        }
                        if ui.button("⏮ Prev").clicked() && self.current_frame_idx > 0 {
                            self.current_frame_idx -= 1;
                            self.detector.reset();
                            self.process_current_frame();
                        }
                        if ui.button("⏭ Next").clicked()
                            && self.current_frame_idx + 1 < total_loaded
                        {
                            self.current_frame_idx += 1;
                            self.process_current_frame();
                        }
                        ui.label(format!(
                            "Frame {} / {}",
                            self.current_frame_idx,
                            total_loaded.saturating_sub(1)
                        ));
                    });

                    ui.horizontal(|ui| {
                        ui.label("FPS:");
                        ui.add(egui::Slider::new(&mut self.fps, 1.0..=60.0).step_by(1.0));
                    });

                    if total_loaded > 1 {
                        let mut slider_idx = self.current_frame_idx;
                        if ui
                            .add(
                                egui::Slider::new(&mut slider_idx, 0..=total_loaded - 1)
                                    .text("Scrub"),
                            )
                            .changed()
                        {
                            self.current_frame_idx = slider_idx;
                            self.detector.reset();
                            self.process_current_frame();
                        }
                    }
                });

                left.add_space(4.0);

                let mut param_changed = false;
                left.group(|ui| {
                    ui.heading("🎛️ Rail Detection Parameters");

                    egui::CollapsingHeader::new("🔍 Discontinuity / Depth Step")
                        .default_open(true)
                        .show(ui, |ui| {
                            ui.label("Min depth step (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.depth_step_thresh, 0.02..=0.40)
                                        .step_by(0.005),
                                )
                                .changed();

                            ui.label("Max depth step (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.max_depth_step_thresh, 0.30..=2.00)
                                        .step_by(0.05),
                                )
                                .changed();
                        });

                    egui::CollapsingHeader::new("📏 Track Gauge (1520 mm)")
                        .default_open(true)
                        .show(ui, |ui| {
                            ui.label("Nominal Gauge (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.nominal_gauge, 1.40..=1.65)
                                        .step_by(0.005),
                                )
                                .changed();

                            ui.label("Min Allowed Gauge (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.min_gauge, 1.40..=1.55)
                                        .step_by(0.005),
                                )
                                .changed();

                            ui.label("Max Allowed Gauge (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.max_gauge, 1.50..=1.65)
                                        .step_by(0.005),
                                )
                                .changed();
                        });

                    egui::CollapsingHeader::new("📐 Scanline Search Window")
                        .default_open(true)
                        .show(ui, |ui| {
                            ui.label("Near Row Start % (bottom):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.row_start_pct, 0.60..=0.98)
                                        .step_by(0.01),
                                )
                                .changed();

                            ui.label("Far Row End % (top):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.row_end_pct, 0.20..=0.60)
                                        .step_by(0.01),
                                )
                                .changed();
                        });

                    egui::CollapsingHeader::new("📈 Continuity & Tracking")
                        .default_open(true)
                        .show(ui, |ui| {
                            ui.label("Max Lateral Center Jump (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.max_lateral_jump, 0.10..=0.80)
                                        .step_by(0.02),
                                )
                                .changed();

                            ui.label("Max Lateral Rail Jump (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.max_lateral_rail_jump, 0.02..=0.30)
                                        .step_by(0.01),
                                )
                                .changed();
                        });

                    egui::CollapsingHeader::new("🔮 Extrapolation & Smoothing")
                        .default_open(true)
                        .show(ui, |ui| {
                            ui.label("Extrapolation distance (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.extrapolate_m, 0.0..=50.0)
                                        .step_by(1.0),
                                )
                                .changed();

                            ui.label("Temporal Smoothing (N frames):");
                            param_changed |= ui
                                .add(egui::Slider::new(&mut self.smooth_n, 1..=15))
                                .changed();

                            if ui.button("🔄 Reset Temporal History").clicked() {
                                self.detector.reset();
                                param_changed = true;
                            }
                        });

                    egui::CollapsingHeader::new("🚨 Obstacle Detection & Clearance")
                        .default_open(true)
                        .show(ui, |ui| {
                            param_changed |= ui
                                .checkbox(&mut self.obstacle_enabled, "Enable Obstacle Detection")
                                .changed();

                            ui.label("Detection Algorithm:");
                            egui::ComboBox::from_id_salt("obs_mode")
                                .selected_text(match self.obstacle_mode {
                                    ObstacleDetectionMode::HybridGrid => "⚡ Hybrid 3D Clearance + 2D Cluster",
                                    ObstacleDetectionMode::Boxcast3D => "📦 3D Boxcast Envelope",
                                    ObstacleDetectionMode::DepthMatrix2D => "📊 2D Depth Matrix Analysis",
                                })
                                .show_ui(ui, |ui| {
                                    param_changed |= ui
                                        .selectable_value(
                                            &mut self.obstacle_mode,
                                            ObstacleDetectionMode::HybridGrid,
                                            "⚡ Hybrid 3D Clearance + 2D Cluster (Fast)",
                                        )
                                        .changed();
                                    param_changed |= ui
                                        .selectable_value(
                                            &mut self.obstacle_mode,
                                            ObstacleDetectionMode::Boxcast3D,
                                            "📦 3D Boxcast Envelope (Clearance Tunnel)",
                                        )
                                        .changed();
                                    param_changed |= ui
                                        .selectable_value(
                                            &mut self.obstacle_mode,
                                            ObstacleDetectionMode::DepthMatrix2D,
                                            "📊 2D Depth Matrix Analysis (Differential)",
                                        )
                                        .changed();
                                });

                            ui.label("Clearance Width (m):");
                            param_changed |= ui
                                .add(egui::Slider::new(&mut self.clearance_width, 1.6..=4.0).step_by(0.05))
                                .changed();

                            ui.label("Min Height Above Rail (m):");
                            param_changed |= ui
                                .add(egui::Slider::new(&mut self.min_height_above_rail, 0.05..=0.50).step_by(0.01))
                                .changed();

                            ui.label("Max Height Above Rail (m):");
                            param_changed |= ui
                                .add(egui::Slider::new(&mut self.max_height_above_rail, 1.5..=4.5).step_by(0.1))
                                .changed();

                            ui.label("Min Cluster Points:");
                            param_changed |= ui
                                .add(egui::Slider::new(&mut self.min_points, 2..=30))
                                .changed();

                            ui.label("Max Distance (m):");
                            param_changed |= ui
                                .add(egui::Slider::new(&mut self.max_distance_m, 10.0..=100.0).step_by(5.0))
                                .changed();

                            if self.obstacle_mode == ObstacleDetectionMode::DepthMatrix2D {
                                ui.label("Depth Matrix Diff Thresh (m):");
                                param_changed |= ui
                                    .add(egui::Slider::new(&mut self.depth_diff_thresh, 0.10..=1.00).step_by(0.05))
                                    .changed();
                            }
                        });
                });

                if param_changed {
                    self.process_current_frame();
                    let lock = self.dataset.frames.read().unwrap();
                    if self.current_frame_idx < lock.len() {
                        let f = &lock[self.current_frame_idx];
                        let color_img = self.painter.paint(
                            &f.range_image,
                            self.last_res.as_ref(),
                            &self.detector.geometry,
                            self.clearance_width,
                        );
                        self.texture = Some(left.ctx().load_texture(
                            "range_view",
                            color_img,
                            TextureOptions::LINEAR,
                        ));
                    }
                }

                left.add_space(4.0);

                left.group(|ui| {
                    ui.heading("📊 Telemetry HUD");
                    if let Some(ref r) = self.last_res {
                        ui.colored_label(
                            Color32::GREEN,
                            format!("Confidence: {:.1}%", r.confidence * 100.0),
                        );
                        ui.label(format!("Gauge: {:.3} m", r.gauge));
                        ui.label(format!("Direction: {}", r.turn_direction));
                        if r.turn_radius.is_infinite() || r.turn_radius > 9999.0 {
                            ui.label("Radius: ∞ (Straight)");
                        } else {
                            ui.label(format!("Radius: {:.1} m", r.turn_radius));
                        }
                        ui.label(format!("Points Detected: {}", r.points.len()));
                        ui.label(format!(
                            "Extrapolation: {:.1} m (N={})",
                            self.extrapolate_m, self.smooth_n
                        ));
                        if r.has_intensity {
                            ui.label(format!(
                                "Intensity L/R: {:.1} / {:.1}",
                                r.avg_intensity_left, r.avg_intensity_right
                            ));
                        }
                        ui.label(format!(
                            "Calc Latency: {:.2} ms",
                            self.last_calc_dur.as_secs_f64() * 1000.0
                        ));

                        ui.add_space(4.0);
                        ui.separator();
                        ui.heading("🚨 Obstacle Status");

                        let num_crit = r.obstacles.iter().filter(|o| o.is_critical).count();
                        let num_warn = r.obstacles.len() - num_crit;

                        if num_crit > 0 {
                            let closest = r
                                .obstacles
                                .iter()
                                .filter(|o| o.is_critical)
                                .map(|o| o.distance_along_track)
                                .fold(f32::INFINITY, f32::min);
                            ui.colored_label(
                                Color32::RED,
                                format!("🛑 CRITICAL: {} OBSTACLE(S) ON TRACK! (Closest: {:.1}m)", num_crit, closest),
                            );
                        } else if num_warn > 0 {
                            let closest = r
                                .obstacles
                                .iter()
                                .map(|o| o.distance_along_track)
                                .fold(f32::INFINITY, f32::min);
                            ui.colored_label(
                                Color32::from_rgb(255, 170, 0),
                                format!("⚠️ WARNING: {} IN CLEARANCE ZONE! (Closest: {:.1}m)", num_warn, closest),
                            );
                        } else {
                            ui.colored_label(
                                Color32::GREEN,
                                format!("🟢 CLEAR TRACK (No obstacles within {:.0}m)", self.max_distance_m),
                            );
                        }

                        if !r.obstacles.is_empty() {
                            egui::ScrollArea::vertical().max_height(120.0).show(ui, |ui| {
                                for o in &r.obstacles {
                                    let badge_color = if o.is_critical {
                                        Color32::RED
                                    } else {
                                        Color32::from_rgb(255, 170, 0)
                                    };
                                    let status_str = if o.is_critical { "CRITICAL" } else { "CLEARANCE" };
                                    ui.horizontal(|ui| {
                                        ui.colored_label(badge_color, format!("#{} [{}]", o.id, status_str));
                                        ui.label(format!(
                                            "Dist: {:.1}m | Lat: {:+.2}m | H: {:.2}m | Pts: {} | Dim: {:.1}x{:.1}x{:.1}m",
                                            o.distance_along_track,
                                            o.lateral_offset,
                                            o.height_above_rail,
                                            o.points_count,
                                            o.size_m[0],
                                            o.size_m[1],
                                            o.size_m[2],
                                        ));
                                    });
                                }
                            });
                        }
                    } else {
                        ui.colored_label(Color32::RED, "No Track Detected");
                    }
                });

                // ─── RIGHT COLUMN: 2D Range View Preview ───
                let right = &mut cols[1];
                right.group(|ui| {
                    ui.heading("📺 2D Range Image Preview");
                    if let Some(ref tex) = self.texture {
                        let img_size = tex.size_vec2();
                        let max_w = (ui.available_width() - 20.0).max(100.0);
                        let aspect = img_size.y / img_size.x.max(1.0);
                        let final_size = egui::vec2(max_w, max_w * aspect);

                        ui.vertical_centered(|ui| {
                            ui.image((tex.id(), final_size));
                            ui.add_space(4.0);
                            ui.horizontal_wrapped(|ui| {
                                ui.colored_label(Color32::from_rgb(30, 210, 255), "■ Left Rail");
                                ui.colored_label(Color32::from_rgb(255, 90, 30), "■ Right Rail");
                                ui.colored_label(Color32::from_rgb(0, 255, 60), "■ Centerline");
                                ui.colored_label(Color32::from_rgb(255, 0, 255), "■ Extrapolation");
                                ui.colored_label(Color32::from_rgb(180, 220, 180), "■ Sleepers");
                                ui.colored_label(Color32::from_rgb(240, 200, 50), "--- Clearance");
                                ui.colored_label(Color32::RED, "■ Critical Obstacle");
                                ui.colored_label(Color32::from_rgb(255, 170, 0), "■ Clearance Intrusion");
                            });
                        });
                    } else {
                        ui.label("Loading frame preview...");
                    }
                });
            });
        });
    }
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<String> = std::env::args().collect();
    let target = args.get(1).map(|s| s.as_str()).unwrap_or("frames");

    println!("============================================================");
    println!("🛤️  RAIL TUNER 2D — Starting Range Image Rail Detector GUI");
    println!("Target path: {}", target);
    println!("============================================================");

    let path = PathBuf::from(target);
    let npy_dir = if path.exists() && path.is_dir() {
        path
    } else if PathBuf::from("frames").exists() {
        PathBuf::from("frames")
    } else if PathBuf::from("../frames").exists() {
        PathBuf::from("../frames")
    } else {
        PathBuf::from("dev_pyrails/frames")
    };
    println!("Loading .npy frames from: {:?}", npy_dir);
    let npy_files = scan_npy_frames(&npy_dir);
    println!("Found {} frames", npy_files.len());
    let dataset = FrameDataset::from_npy_paths(npy_files);

    // Подключение к Rerun (или запуск viewer)
    println!("[*] Connecting / Spawning Rerun viewer...");
    let rec = RecordingStreamBuilder::new("rail_tuner_2d")
        .spawn()
        .or_else(|_| RecordingStreamBuilder::new("rail_tuner_2d").connect_grpc())
        .ok();

    let app = RailTuner2DApp::new(dataset, rec);
    let native_options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_inner_size([1200.0, 800.0])
            .with_min_inner_size([800.0, 600.0])
            .with_title("Rail Tuner 2D — LiDAR Track Extrapolation"),
        ..Default::default()
    };

    eframe::run_native(
        "Rail Tuner 2D",
        native_options,
        Box::new(|_cc| Ok(Box::new(app))),
    )?;

    Ok(())
}
