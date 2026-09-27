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
use rayon::prelude::*;
use rerun::{Color, Points3D, Radius, RecordingStream, RecordingStreamBuilder};
use rusqlite::{Connection, OpenFlags};
use rust_listener::debug::helper::DebugStream;
use shared::configs::DetectionPreset;
use shared::rail_detection::{
    DetectionResult, LidarGeometry, ObstacleDetectionMode, RailTrackDetector,
};
use shared::range_image::RangeImage;
use shared::transport::PointCloud2;

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

/// Источник трека данных (ROS2 .db3 или директория с .npy)
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum TrackSource {
    Db3(PathBuf),
    NpyDir(PathBuf),
}

impl TrackSource {
    pub fn label(&self) -> String {
        match self {
            TrackSource::Db3(p) => {
                let stem = p.file_stem().and_then(|s| s.to_str()).unwrap_or("db3");
                let parent = p
                    .parent()
                    .and_then(|pr| pr.file_name())
                    .and_then(|s| s.to_str())
                    .unwrap_or("");
                if parent.is_empty() || parent == "dataset" || parent == "." {
                    format!("📁 [DB3] {}", stem)
                } else if stem.starts_with(parent) {
                    format!("📁 [DB3] {}", stem)
                } else {
                    format!("📁 [DB3] {} ({})", parent, stem)
                }
            }
            TrackSource::NpyDir(p) => {
                let name = p.file_name().and_then(|s| s.to_str()).unwrap_or("npy");
                format!("📂 [NPY] {}", name)
            }
        }
    }
}

/// Рекурсивно находит файлы .db3 с размером > 1 МБ (исключая пустые заглушки)
fn scan_db3_in_dir(dir: &Path, out: &mut Vec<PathBuf>) {
    if let Ok(entries) = std::fs::read_dir(dir) {
        for entry in entries.flatten() {
            let p = entry.path();
            if p.is_dir() {
                scan_db3_in_dir(&p, out);
            } else if p.extension().and_then(|s| s.to_str()) == Some("db3") {
                if let Ok(meta) = std::fs::metadata(&p) {
                    if meta.len() > 1024 * 1024 {
                        out.push(p);
                    }
                }
            }
        }
    }
}

/// Находит доступные треки: .db3 датасеты и .npy директории
pub fn discover_available_tracks(cli_arg: Option<&str>) -> Vec<TrackSource> {
    let mut tracks = Vec::new();

    // 1. Приоритетный путь из аргументов командной строки
    if let Some(arg) = cli_arg {
        let p = PathBuf::from(arg);
        if p.is_file() && p.extension().and_then(|s| s.to_str()) == Some("db3") {
            tracks.push(TrackSource::Db3(p));
        } else if p.is_dir() {
            let npy = scan_npy_frames(&p);
            if !npy.is_empty() {
                tracks.push(TrackSource::NpyDir(p.clone()));
            }
            let mut db3s = Vec::new();
            scan_db3_in_dir(&p, &mut db3s);
            for d in db3s {
                tracks.push(TrackSource::Db3(d));
            }
        }
    }

    // 2. Сканирование папки dataset и текущей директории на наличие db3
    let search_roots = [
        PathBuf::from("dataset"),
        PathBuf::from("../dataset"),
        PathBuf::from("."),
    ];

    let mut db3_found = Vec::new();
    for root in &search_roots {
        if root.exists() && root.is_dir() {
            scan_db3_in_dir(root, &mut db3_found);
        }
    }
    db3_found.sort();
    db3_found.dedup();

    for d in db3_found {
        let ts = TrackSource::Db3(d);
        if !tracks.contains(&ts) {
            tracks.push(ts);
        }
    }

    // 3. Сканирование известных папок с .npy кадрами
    let npy_roots = [
        PathBuf::from("frames"),
        PathBuf::from("../frames"),
        PathBuf::from("dev_pyrails/frames"),
    ];
    for n in &npy_roots {
        if n.exists() && n.is_dir() {
            let npy = scan_npy_frames(n);
            if !npy.is_empty() {
                let ts = TrackSource::NpyDir(n.clone());
                if !tracks.contains(&ts) {
                    tracks.push(ts);
                }
            }
        }
    }

    tracks
}

/// Поиск ID топика PointCloud2 в SQLite базе rosbag2
fn find_pointcloud_topic_id(conn: &Connection) -> Option<i64> {
    if let Ok(mut stmt) =
        conn.prepare("SELECT id FROM topics WHERE type = 'sensor_msgs/msg/PointCloud2' LIMIT 1")
    {
        if let Ok(mut rows) = stmt.query([]) {
            if let Ok(Some(row)) = rows.next() {
                if let Ok(id) = row.get(0) {
                    return Some(id);
                }
            }
        }
    }
    if let Ok(mut stmt) = conn.prepare(
        "SELECT id FROM topics WHERE type LIKE '%PointCloud%' OR name LIKE '%point%' LIMIT 1",
    ) {
        if let Ok(mut rows) = stmt.query([]) {
            if let Ok(Some(row)) = rows.next() {
                if let Ok(id) = row.get(0) {
                    return Some(id);
                }
            }
        }
    }
    if let Ok(mut stmt) = conn.prepare("SELECT id FROM topics LIMIT 1") {
        if let Ok(mut rows) = stmt.query([]) {
            if let Ok(Some(row)) = rows.next() {
                if let Ok(id) = row.get(0) {
                    return Some(id);
                }
            }
        }
    }
    None
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

/// Хранилище загруженных кадров в оперативной памяти (RAM)
pub struct FrameDataset {
    pub source: TrackSource,
    pub frames: Arc<RwLock<Vec<TunerFrame>>>,
    pub is_loading: Arc<AtomicBool>,
    pub loaded_count: Arc<AtomicUsize>,
    pub total_count: Arc<AtomicUsize>,
    pub cancel_flag: Arc<AtomicBool>,
}

impl FrameDataset {
    /// Сигнализирует фоновому потоку остановить чтение кадров
    pub fn stop(&self) {
        self.cancel_flag.store(true, Ordering::SeqCst);
    }

    /// Загружает датасет из указанного источника (db3 или npy директория)
    pub fn from_source(source: TrackSource) -> Self {
        match source {
            TrackSource::Db3(ref p) => Self::from_db3(source.clone(), p),
            TrackSource::NpyDir(ref p) => Self::from_npy_dir(source.clone(), p),
        }
    }

    /// Потоковая фоновая загрузка .db3 файла в RAM с параллельной конвертацией в RangeImage
    pub fn from_db3(source: TrackSource, path: &Path) -> Self {
        let frames = Arc::new(RwLock::new(Vec::new()));
        let is_loading = Arc::new(AtomicBool::new(true));
        let loaded_count = Arc::new(AtomicUsize::new(0));
        let total_count = Arc::new(AtomicUsize::new(0));
        let cancel_flag = Arc::new(AtomicBool::new(false));

        let mut total_messages = 0usize;
        if let Ok(conn) = Connection::open_with_flags(path, OpenFlags::SQLITE_OPEN_READ_ONLY) {
            let topic_id = find_pointcloud_topic_id(&conn).unwrap_or(1);
            if let Ok(mut stmt) = conn.prepare("SELECT count(*) FROM messages WHERE topic_id = ?") {
                if let Ok(count) = stmt.query_row([topic_id], |row| row.get::<_, i64>(0)) {
                    total_messages = count as usize;
                }
            }
        }
        total_count.store(total_messages, Ordering::Relaxed);

        let bg_path = path.to_path_buf();
        let bg_frames = Arc::clone(&frames);
        let bg_is_loading = Arc::clone(&is_loading);
        let bg_loaded_count = Arc::clone(&loaded_count);
        let bg_cancel = Arc::clone(&cancel_flag);

        std::thread::spawn(move || {
            let conn = match Connection::open_with_flags(&bg_path, OpenFlags::SQLITE_OPEN_READ_ONLY)
            {
                Ok(c) => c,
                Err(e) => {
                    eprintln!(
                        "[-] Не удалось открыть SQLite {}: {:?}",
                        bg_path.display(),
                        e
                    );
                    bg_is_loading.store(false, Ordering::SeqCst);
                    return;
                }
            };

            let topic_id = find_pointcloud_topic_id(&conn).unwrap_or(1);
            let mut stmt =
                match conn.prepare("SELECT data FROM messages WHERE topic_id = ? ORDER BY id") {
                    Ok(s) => s,
                    Err(e) => {
                        eprintln!("[-] Ошибка подготовки запроса к messages: {:?}", e);
                        bg_is_loading.store(false, Ordering::SeqCst);
                        return;
                    }
                };

            let mut rows = match stmt.query([topic_id]) {
                Ok(r) => r,
                Err(e) => {
                    eprintln!("[-] Ошибка выполнения запроса к messages: {:?}", e);
                    bg_is_loading.store(false, Ordering::SeqCst);
                    return;
                }
            };

            println!("[FrameDataset] Загрузка .db3 в RAM: {}", bg_path.display());

            const BATCH_SIZE: usize = 16;
            let mut batch: Vec<(usize, Vec<u8>)> = Vec::with_capacity(BATCH_SIZE);
            let mut global_idx = 0usize;

            while let Ok(Some(row)) = rows.next() {
                if bg_cancel.load(Ordering::Relaxed) {
                    println!("[FrameDataset] Загрузка отменена: {}", bg_path.display());
                    return;
                }

                let raw_data: Vec<u8> = match row.get(0) {
                    Ok(v) => v,
                    Err(_) => continue,
                };
                batch.push((global_idx, raw_data));
                global_idx += 1;

                if batch.len() >= BATCH_SIZE {
                    let cancel = Arc::clone(&bg_cancel);
                    let parsed: Vec<TunerFrame> = batch
                        .into_par_iter()
                        .filter_map(|(idx, raw_bytes)| {
                            if cancel.load(Ordering::Relaxed) {
                                return None;
                            }
                            let cloud: PointCloud2 = match cdr::deserialize(&raw_bytes) {
                                Ok(c) => c,
                                Err(e) => {
                                    if idx < 3 {
                                        eprintln!(
                                            "[-] Frame {} CDR deserialize error: {:?}",
                                            idx, e
                                        );
                                    }
                                    return None;
                                }
                            };
                            let ri =
                                match RangeImage::from_pandar128_point_cloud2(&cloud, Some(40.0)) {
                                    Some(r) => r,
                                    None => {
                                        if idx < 3 {
                                            eprintln!(
                                                "[-] Frame {} RangeImage conversion returned None",
                                                idx
                                            );
                                        }
                                        return None;
                                    }
                                };
                            Some(TunerFrame {
                                idx,
                                range_image: ri,
                            })
                        })
                        .collect();

                    if bg_cancel.load(Ordering::Relaxed) {
                        return;
                    }

                    {
                        let mut w = bg_frames.write().unwrap();
                        w.extend(parsed);
                        bg_loaded_count.store(w.len(), Ordering::Relaxed);
                    }
                    batch = Vec::with_capacity(BATCH_SIZE);
                }
            }

            if !batch.is_empty() && !bg_cancel.load(Ordering::Relaxed) {
                let cancel = Arc::clone(&bg_cancel);
                let parsed: Vec<TunerFrame> = batch
                    .into_par_iter()
                    .filter_map(|(idx, raw_bytes)| {
                        if cancel.load(Ordering::Relaxed) {
                            return None;
                        }
                        let cloud: PointCloud2 = match cdr::deserialize(&raw_bytes) {
                            Ok(c) => c,
                            Err(e) => {
                                if idx < 3 {
                                    eprintln!("[-] Frame {} CDR deserialize error: {:?}", idx, e);
                                }
                                return None;
                            }
                        };
                        let ri = match RangeImage::from_pandar128_point_cloud2(&cloud, Some(40.0)) {
                            Some(r) => r,
                            None => {
                                if idx < 3 {
                                    eprintln!(
                                        "[-] Frame {} RangeImage conversion returned None",
                                        idx
                                    );
                                }
                                return None;
                            }
                        };
                        Some(TunerFrame {
                            idx,
                            range_image: ri,
                        })
                    })
                    .collect();

                if !bg_cancel.load(Ordering::Relaxed) {
                    let mut w = bg_frames.write().unwrap();
                    w.extend(parsed);
                    bg_loaded_count.store(w.len(), Ordering::Relaxed);
                }
            }

            bg_is_loading.store(false, Ordering::SeqCst);
            println!(
                "[FrameDataset] Загрузка завершена: {} кадров",
                bg_loaded_count.load(Ordering::Relaxed)
            );
        });

        Self {
            source,
            frames,
            is_loading,
            loaded_count,
            total_count,
            cancel_flag,
        }
    }

    /// Фоновая загрузка кадров из папки с .npy файлами
    pub fn from_npy_dir(source: TrackSource, dir: &Path) -> Self {
        let npy_files = scan_npy_frames(dir);
        let total = npy_files.len();
        let frames = Arc::new(RwLock::new(Vec::with_capacity(total)));
        let is_loading = Arc::new(AtomicBool::new(true));
        let loaded_count = Arc::new(AtomicUsize::new(0));
        let total_count = Arc::new(AtomicUsize::new(total));
        let cancel_flag = Arc::new(AtomicBool::new(false));

        let bg_frames = Arc::clone(&frames);
        let bg_is_loading = Arc::clone(&is_loading);
        let bg_loaded_count = Arc::clone(&loaded_count);
        let bg_cancel = Arc::clone(&cancel_flag);

        std::thread::spawn(move || {
            const BATCH_SIZE: usize = 16;
            for chunk in npy_files.chunks(BATCH_SIZE) {
                if bg_cancel.load(Ordering::Relaxed) {
                    return;
                }
                let cancel = Arc::clone(&bg_cancel);
                let parsed: Vec<TunerFrame> = chunk
                    .par_iter()
                    .filter_map(|(idx, path)| {
                        if cancel.load(Ordering::Relaxed) {
                            return None;
                        }
                        let ri = RangeImage::load_npy(path).ok()?;
                        Some(TunerFrame {
                            idx: *idx,
                            range_image: ri,
                        })
                    })
                    .collect();

                if bg_cancel.load(Ordering::Relaxed) {
                    return;
                }

                {
                    let mut w = bg_frames.write().unwrap();
                    w.extend(parsed);
                    bg_loaded_count.store(w.len(), Ordering::Relaxed);
                }
            }
            bg_is_loading.store(false, Ordering::SeqCst);
        });

        Self {
            source,
            frames,
            is_loading,
            loaded_count,
            total_count,
            cancel_flag,
        }
    }
}

/// Режим отображения слоёв в 2D вьювере
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ImageLayerMode {
    /// Карта дальности (глубина) с палитрой Turbo
    Depth,
    /// Карта интенсивности отражения (рефлективность)
    Intensity,
    /// Смешанный слой: глубина + интенсивность
    Blend,
}

/// Цветовая палитра слоя интенсивности
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum IntensityColormap {
    Grayscale,
    Turbo,
}

/// Конфигурация отображения слоёв
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

/// 2D визуализатор карты глубины и интенсивности для отображения текстуры в egui
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
        _clearance_width: f32,
        layer_cfg: &LayerViewConfig,
    ) -> ColorImage {
        let w = frame.width;
        let h = frame.height;
        let out_w = w * self.scale;
        let out_h = h * self.scale;

        let mut rgb = vec![0u8; out_w * out_h * 3];
        let has_intensity = !frame.intensity.is_empty();

        // 1. Colorize pixels based on selected layer mode (Depth, Intensity, or Blend)
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
                            [25, 25, 30] // Gray placeholder if no intensity data
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

            // Clearance corridor shapecast 2D wireframe
            let shapecast_2d = r.shapecast_wireframe_2d(geo);
            let shapecast_col = r.shapecast_color();
            for strip in &shapecast_2d {
                let px_strip: Vec<(i32, i32)> = strip
                    .iter()
                    .map(|p| {
                        (
                            (p[0] * self.scale as f32) as i32,
                            (p[1] * self.scale as f32) as i32,
                        )
                    })
                    .collect();
                draw_line_rgb(&mut rgb, out_w, out_h, &px_strip, shapecast_col, 1);
            }

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
                let c_len = (6 * self.scale as i32 / 3)
                    .max(4)
                    .min((x1 - x0).abs() / 2)
                    .min((y1 - y0).abs() / 2);
                if c_len > 1 {
                    // Top-left
                    draw_line_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        &[(x0, y0), (x0 + c_len, y0)],
                        [255, 255, 255],
                        2,
                    );
                    draw_line_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        &[(x0, y0), (x0, y0 + c_len)],
                        [255, 255, 255],
                        2,
                    );
                    // Top-right
                    draw_line_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        &[(x1, y0), (x1 - c_len, y0)],
                        [255, 255, 255],
                        2,
                    );
                    draw_line_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        &[(x1, y0), (x1, y0 + c_len)],
                        [255, 255, 255],
                        2,
                    );
                    // Bottom-left
                    draw_line_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        &[(x0, y1), (x0 + c_len, y1)],
                        [255, 255, 255],
                        2,
                    );
                    draw_line_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        &[(x0, y1), (x0, y1 - c_len)],
                        [255, 255, 255],
                        2,
                    );
                    // Bottom-right
                    draw_line_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        &[(x1, y1), (x1 - c_len, y1)],
                        [255, 255, 255],
                        2,
                    );
                    draw_line_rgb(
                        &mut rgb,
                        out_w,
                        out_h,
                        &[(x1, y1), (x1, y1 - c_len)],
                        [255, 255, 255],
                        2,
                    );
                }

                // If critical, fill top 3-pixel badge
                if o.is_critical {
                    for ty in y0..=(y0 + 3).min(y1) {
                        for tx in x0..=x1 {
                            if tx >= 0 && (tx as usize) < out_w && ty >= 0 && (ty as usize) < out_h
                            {
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

/// Замеры времени выполнения стадий конвейера обработки кадра
#[derive(Clone, Copy, Debug, Default)]
pub struct PipelineProfiling {
    /// 1. Искривление / компенсация кривизны тоннеля (warp_curvature)
    pub warp_ms: f32,
    /// 2. Детекция геометрии рельсов (поиск ступеней и аппроксимация полинома)
    pub rail_detect_ms: f32,
    /// 3. Проверка габарита приближения и кластеризация препятствий
    pub obstacle_detect_ms: f32,
    /// 4. Общее время работы детектора (detect_with_raw)
    pub detector_total_ms: f32,
    /// 5. Восстановление истинных 3D координат
    pub restore_coords_ms: f32,
    /// 6. Формирование и отправка сцен в Rerun (3D + 2D окна)
    pub rerun_stream_ms: f32,
    /// 7. 2D растеризация и оверлеи в Turbo палитре (painter.paint)
    pub egui_paint_ms: f32,
    /// 8. Загрузка текстуры на GPU (egui load_texture)
    pub texture_upload_ms: f32,
    /// Время основных вычислений до отрисовки интерфейса
    pub calc_pipeline_ms: f32,
    /// Полное сквозное время обработки и отображения одного кадра (end-to-end)
    pub total_pipeline_ms: f32,

    // Сглаженные средние значения (EMA, alpha = 0.15)
    pub ema_total_ms: f32,
    pub ema_detector_ms: f32,
    pub ema_rerun_ms: f32,
    pub ema_paint_ms: f32,
}

impl PipelineProfiling {
    pub fn update_ema(&mut self) {
        let alpha = 0.15;
        if self.ema_total_ms <= 0.0 {
            self.ema_total_ms = self.total_pipeline_ms;
            self.ema_detector_ms = self.detector_total_ms;
            self.ema_rerun_ms = self.rerun_stream_ms;
            self.ema_paint_ms = self.egui_paint_ms + self.texture_upload_ms;
        } else {
            self.ema_total_ms = self.ema_total_ms * (1.0 - alpha) + self.total_pipeline_ms * alpha;
            self.ema_detector_ms =
                self.ema_detector_ms * (1.0 - alpha) + self.detector_total_ms * alpha;
            self.ema_rerun_ms = self.ema_rerun_ms * (1.0 - alpha) + self.rerun_stream_ms * alpha;
            self.ema_paint_ms = self.ema_paint_ms * (1.0 - alpha)
                + (self.egui_paint_ms + self.texture_upload_ms) * alpha;
        }
    }
}

/// Интерактивное приложение RailTuner2D
pub struct RailTuner2DApp {
    available_tracks: Vec<TrackSource>,
    selected_track_idx: usize,
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

    // Параметры двух текстур и смешивания (синхронизированы с определителем и 2D вьювером)
    contrast_depth: f32,
    contrast_intensity: f32,
    blend: f32,

    // Параметры детектора препятствий
    obstacle_enabled: bool,
    obstacle_mode: ObstacleDetectionMode,
    clearance_width: f32,
    clearance_narrowing_width: f32,
    clearance_narrowing_height: f32,
    min_height_above_rail: f32,
    max_height_above_rail: f32,
    min_points: usize,
    cluster_depth_thresh: f32,
    max_distance_m: f32,
    depth_diff_thresh: f32,
    upward_curvature: f32,

    // Rerun
    rec_stream: Option<RecordingStream>,
    stream_to_rerun: bool,

    // UI state
    detector: RailTrackDetector,
    last_res: Option<DetectionResult>,
    last_bent_res: Option<DetectionResult>,
    active_range_image: Option<RangeImage>,
    last_calc_dur: Duration,
    painter: EguiRangePainter,
    layer_cfg: LayerViewConfig,
    texture: Option<TextureHandle>,
    last_painted_frame: Option<usize>,
    copied_toast_time: Option<Instant>,
    profiling: PipelineProfiling,
}

impl RailTuner2DApp {
    pub fn new(
        available_tracks: Vec<TrackSource>,
        selected_track_idx: usize,
        dataset: FrameDataset,
        rec_stream: Option<RecordingStream>,
    ) -> Self {
        let detector: RailTrackDetector = DetectionPreset::current().into();

        Self {
            available_tracks,
            selected_track_idx,
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
            contrast_depth: detector.contrast_depth,
            contrast_intensity: detector.contrast_intensity,
            blend: detector.blend,
            obstacle_enabled: detector.obstacle_config.enabled,
            obstacle_mode: detector.obstacle_config.mode,
            clearance_width: detector.obstacle_config.clearance_width,
            clearance_narrowing_width: detector.obstacle_config.clearance_narrowing_width,
            clearance_narrowing_height: detector.obstacle_config.clearance_narrowing_height,
            min_height_above_rail: detector.obstacle_config.min_height_above_rail,
            max_height_above_rail: detector.obstacle_config.max_height_above_rail,
            min_points: detector.obstacle_config.min_points,
            cluster_depth_thresh: detector.obstacle_config.cluster_depth_thresh,
            max_distance_m: detector.obstacle_config.max_distance_m,
            depth_diff_thresh: detector.obstacle_config.depth_diff_thresh,
            upward_curvature: detector.obstacle_config.upward_curvature,

            rec_stream,
            stream_to_rerun: true,

            detector: detector,
            last_res: None,
            last_bent_res: None,
            active_range_image: None,
            last_calc_dur: Duration::ZERO,
            painter: EguiRangePainter::new(3),
            layer_cfg: LayerViewConfig {
                mode: ImageLayerMode::Depth,
                intensity_colormap: IntensityColormap::Grayscale,
                contrast_depth: 200.0,
                contrast_intensity: 20.0,
                blend: 0.0,
            },
            texture: None,
            last_painted_frame: None,
            copied_toast_time: None,
            profiling: PipelineProfiling::default(),
        }
    }

    /// Переключение на другой трек: выгрузка предыдущего из RAM и потоковая загрузка нового
    pub fn open_track(&mut self, track_idx: usize) {
        if track_idx >= self.available_tracks.len() {
            return;
        }
        // 1. Прерываем предыдущую фоновую загрузку (если шла)
        self.dataset.stop();

        // 2. Освобождаем память предыдущего датасета и начинаем загрузку нового
        let source = self.available_tracks[track_idx].clone();
        println!("[RailTuner2D] Смена трека на: {}", source.label());
        self.dataset = FrameDataset::from_source(source);
        self.selected_track_idx = track_idx;

        // 3. Сбрасываем плеер, превью и детектор
        self.is_playing = false;
        self.current_frame_idx = 0;
        self.last_painted_frame = None;
        self.texture = None;
        self.active_range_image = None;
        self.last_res = None;
        self.last_bent_res = None;
        self.profiling = PipelineProfiling::default();
        self.detector.reset();
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

        self.detector.contrast_depth = self.contrast_depth;
        self.detector.contrast_intensity = self.contrast_intensity;
        self.detector.blend = self.blend;

        self.layer_cfg.contrast_depth = self.contrast_depth;
        self.layer_cfg.contrast_intensity = self.contrast_intensity;
        self.layer_cfg.blend = self.blend;

        self.detector.obstacle_config.enabled = self.obstacle_enabled;
        self.detector.obstacle_config.mode = self.obstacle_mode;
        self.detector.obstacle_config.clearance_width = self.clearance_width;
        self.detector.obstacle_config.min_height_above_rail = self.min_height_above_rail;
        self.detector.obstacle_config.max_height_above_rail = self.max_height_above_rail;
        self.detector.obstacle_config.min_points = self.min_points;
        self.detector.obstacle_config.max_distance_m = self.max_distance_m;
        self.detector.obstacle_config.depth_diff_thresh = self.depth_diff_thresh;
        self.detector.obstacle_config.upward_curvature = self.upward_curvature;
        self.detector.obstacle_config.clearance_narrowing_width = self.clearance_narrowing_width;
        self.detector.obstacle_config.clearance_narrowing_height = self.clearance_narrowing_height;
        self.detector.obstacle_config.cluster_depth_thresh = self.cluster_depth_thresh;
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

        let t_pipeline = Instant::now();

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

        let geo = &self.detector.geometry;
        let raw_ri = &frame.range_image;

        // 1. Искривление всех точек тоннеля и карты глубины/интенсивности:
        //    Z_bent = Z + c_z * X^2
        let t_warp = Instant::now();
        let active_ri = if self.upward_curvature.abs() > 1e-7 {
            raw_ri.warp_curvature(geo, self.upward_curvature)
        } else {
            raw_ri.clone()
        };
        self.profiling.warp_ms = t_warp.elapsed().as_secs_f32() * 1000.0;

        self.sync_detector_params();

        // 2. Детекция путей на искривленном (выпрямленном) представлении и габарита на истинных координатах
        let t_detect = Instant::now();
        let bent_res = self
            .detector
            .detect_with_raw(&active_ri, Some(raw_ri), frame.idx);
        let detect_dur = t_detect.elapsed();
        self.last_calc_dur = detect_dur;
        self.profiling.detector_total_ms = detect_dur.as_secs_f32() * 1000.0;

        if let Some(ref r) = bent_res {
            self.profiling.rail_detect_ms = r.timing_rail_ms;
            self.profiling.obstacle_detect_ms = r.timing_obstacles_ms;
        } else {
            self.profiling.rail_detect_ms = 0.0;
            self.profiling.obstacle_detect_ms = 0.0;
        }

        // 3. Восстановление истинных координат для Rerun и 3D мира:
        //    Z_real = Z_bent - upward_curvature * X^2
        let t_restore = Instant::now();
        let mut real_res = bent_res.clone();
        if let Some(ref mut r) = real_res {
            r.restore_real_coordinates();
        }
        self.profiling.restore_coords_ms = t_restore.elapsed().as_secs_f32() * 1000.0;

        self.last_bent_res = bent_res;
        self.last_res = real_res;
        self.active_range_image = Some(active_ri);

        // Отправка в Rerun (2 окна: 3D и 2D)
        let t_rerun = Instant::now();
        if self.stream_to_rerun {
            if let Some(ref rec) = self.rec_stream {
                rec.set_time_sequence("frame", frame.idx as i64);

                let geo = &self.detector.geometry;
                let raw_ri = &frame.range_image;
                let active_ri = self.active_range_image.as_ref().unwrap_or(raw_ri);

                // ─── ОКНО 1: 3D сцена ───
                // Точки реального облака и искривленного облака из RangeImage
                let total = geo.height * geo.width;
                let mut pts_real = Vec::with_capacity(total);
                let mut pts_bent = Vec::with_capacity(total);
                let mut colors = Vec::with_capacity(total);

                for row in 0..geo.height {
                    let r_off = row * geo.width;
                    for col in 0..geo.width {
                        let r = raw_ri.data[r_off + col];
                        if r > 0.5 && r < 200.0 {
                            let (x, y, z) = geo.row_col_range_to_xyz(row, col, r);
                            pts_real.push([x, y, z]);
                            let z_bent = z + self.upward_curvature * x * x;
                            pts_bent.push([x, y, z_bent]);

                            let norm = (r / 200.0).clamp(0.0, 1.0);
                            let c = turbo_rgb(norm);
                            colors.push(Color::from_rgb(c[0], c[1], c[2]));
                        }
                    }
                }

                // Истинные физические точки лидара в реальном мире:
                let _ = rec.log(
                    "lidar/point_cloud",
                    &Points3D::new(&pts_real)
                        .with_colors(colors.clone())
                        .with_radii([Radius::new_ui_points(1.2)]),
                );

                // Искривленные точки тоннеля:
                if self.upward_curvature.abs() > 1e-7 {
                    let _ = rec.log(
                        "lidar/point_cloud_bent",
                        &Points3D::new(&pts_bent)
                            .with_colors(colors)
                            .with_radii([Radius::new_ui_points(1.2)]),
                    );
                }

                // 3D рельсы с ВОССТАНОВЛЕННЫМ реальным положением (садятся строго на реальные рельсы):
                let _ = rec.log_rail_detection(self.last_res.as_ref());

                // ─── ОКНО 2: 2D Карта глубины, интенсивности, путей и Shapecast ───
                // Стримим искривленную карту глубины и интенсивности с соответствующими путями:
                let _ = rec.log_rail_detection_2d(active_ri, geo, self.last_bent_res.as_ref());
            }
            self.profiling.rerun_stream_ms = t_rerun.elapsed().as_secs_f32() * 1000.0;
        } else {
            self.profiling.rerun_stream_ms = 0.0;
        }

        self.profiling.calc_pipeline_ms = t_pipeline.elapsed().as_secs_f32() * 1000.0;
    }

    fn update_preview_texture(&mut self, ctx: &egui::Context) {
        let lock = self.dataset.frames.read().unwrap();
        if self.current_frame_idx < lock.len() {
            let f = &lock[self.current_frame_idx];
            let active_ri = self.active_range_image.as_ref().unwrap_or(&f.range_image);

            let t_paint = Instant::now();
            let color_img = self.painter.paint(
                active_ri,
                self.last_bent_res.as_ref(),
                &self.detector.geometry,
                self.clearance_width,
                &self.layer_cfg,
            );
            self.profiling.egui_paint_ms = t_paint.elapsed().as_secs_f32() * 1000.0;

            let t_upload = Instant::now();
            self.texture = Some(ctx.load_texture("range_view", color_img, TextureOptions::LINEAR));
            self.profiling.texture_upload_ms = t_upload.elapsed().as_secs_f32() * 1000.0;

            self.profiling.total_pipeline_ms = self.profiling.calc_pipeline_ms
                + self.profiling.egui_paint_ms
                + self.profiling.texture_upload_ms;
            self.profiling.update_ema();
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
        }
        let total_loaded = self.dataset.loaded_count.load(Ordering::Relaxed);
        if input.2 && self.current_frame_idx + 1 < total_loaded {
            self.current_frame_idx += 1;
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
            }
            ui.ctx().request_repaint();
        }

        // Process frame if frame changed or not painted yet
        if self.last_painted_frame != Some(self.current_frame_idx) && total_loaded > 0 {
            self.process_current_frame();
            self.last_painted_frame = Some(self.current_frame_idx);
            self.update_preview_texture(ui.ctx());
        }

        // Main 2-column layout: Controls on Left, 2D Range View on Right
        egui::ScrollArea::vertical().show(ui, |ui| {
            // Header Bar
            ui.horizontal(|ui| {
                ui.heading("🛤️ Rail Tuner 2D");
                ui.separator();

                if !self.available_tracks.is_empty() {
                    let cur_label = self
                        .available_tracks
                        .get(self.selected_track_idx)
                        .map(|t| t.label())
                        .unwrap_or_else(|| "Select track...".to_string());

                    let mut next_track_idx = self.selected_track_idx;
                    egui::ComboBox::from_id_salt("track_select")
                        .width(260.0)
                        .selected_text(cur_label)
                        .show_ui(ui, |ui| {
                            for (idx, track) in self.available_tracks.iter().enumerate() {
                                let label = track.label();
                                let is_selected = self.selected_track_idx == idx;
                                if ui.selectable_label(is_selected, label).clicked() {
                                    next_track_idx = idx;
                                }
                            }
                        });
                    if next_track_idx != self.selected_track_idx {
                        self.open_track(next_track_idx);
                    }
                }

                ui.separator();

                let is_loading = self.dataset.is_loading.load(Ordering::Relaxed);
                let loaded = self.dataset.loaded_count.load(Ordering::Relaxed);
                let total = self.dataset.total_count.load(Ordering::Relaxed);
                let approx_mb = (loaded * 400) / 1024;
                if is_loading {
                    let pct = if total > 0 { (loaded * 100) / total } else { 0 };
                    ui.colored_label(
                        Color32::from_rgb(255, 190, 50),
                        format!("⏳ RAM: {}/{} кадров ({}%)", loaded, total, pct),
                    );
                    ui.ctx().request_repaint_after(Duration::from_millis(50));
                } else {
                    ui.colored_label(
                        Color32::from_rgb(80, 220, 100),
                        format!("💾 RAM: {} кадров (~{} МБ)", loaded, approx_mb),
                    );
                }

                ui.separator();
                let tot_ema = self.profiling.ema_total_ms;
                let badge_color = if tot_ema <= 0.0 {
                    Color32::GRAY
                } else if tot_ema < 30.0 {
                    Color32::from_rgb(80, 220, 100)
                } else if tot_ema < 60.0 {
                    Color32::from_rgb(255, 190, 50)
                } else {
                    Color32::from_rgb(255, 90, 70)
                };
                let fps_val = if tot_ema > 0.0 { 1000.0 / tot_ema } else { 0.0 };
                ui.colored_label(
                    badge_color,
                    format!("⚡ {:.1} ms ({:.0} FPS)", tot_ema, fps_val),
                );

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
                             detector.contrast_depth = {:.1};\n\
                             detector.contrast_intensity = {:.1};\n\
                             detector.blend = {:.2};\n\
                             detector.obstacle_config.enabled = {};\n\
                             detector.obstacle_config.mode = shared::rail_detection::ObstacleDetectionMode::{:?};\n\
                             detector.obstacle_config.clearance_width = {:.2};\n\
                             detector.obstacle_config.min_height_above_rail = {:.2};\n\
                             detector.obstacle_config.max_height_above_rail = {:.2};\n\
                             detector.obstacle_config.min_points = {};\n\
                             detector.obstacle_config.max_distance_m = {:.1};\n\
                             detector.obstacle_config.depth_diff_thresh = {:.2};\n\
                             detector.obstacle_config.upward_curvature = {:.5};\n\
                             detector.obstacle_config.clearance_narrowing_width = {:.4};\n\
                             detector.obstacle_config.clearance_narrowing_height = {:.4};\n\
                             detector.obstacle_config.cluster_depth_thresh = {:.2};",
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
                            self.contrast_depth,
                            self.contrast_intensity,
                            self.blend,
                            self.obstacle_enabled,
                            self.obstacle_mode,
                            self.clearance_width,
                            self.min_height_above_rail,
                            self.max_height_above_rail,
                            self.min_points,
                            self.max_distance_m,
                            self.depth_diff_thresh,
                            self.upward_curvature,
                            self.clearance_narrowing_width,
                            self.clearance_narrowing_height,
                            self.cluster_depth_thresh,
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
                        }
                        if ui.button("⏭ Next").clicked()
                            && self.current_frame_idx + 1 < total_loaded
                        {
                            self.current_frame_idx += 1;
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

                    egui::CollapsingHeader::new("🖼️ Dual Texture & Blending (Depth + Intensity)")
                        .default_open(true)
                        .show(ui, |ui| {
                            ui.label("Contrast Depth (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.contrast_depth, 10.0..=300.0)
                                        .step_by(5.0),
                                )
                                .changed();

                            ui.label("Contrast Intensity:");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.contrast_intensity, 5.0..=255.0)
                                        .step_by(1.0),
                                )
                                .changed();

                            ui.label("Blend Ratio (Depth ↔ Intensity):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.blend, 0.0..=1.0)
                                        .step_by(0.01),
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
                                    egui::Slider::new(&mut self.row_end_pct, -0.1..=0.60)
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
                                    egui::Slider::new(&mut self.extrapolate_m, 0.0..=100.0)
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

                            ui.label("Narrowing Width (m/m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.clearance_narrowing_width, 0.0..=0.030)
                                        .step_by(0.001)
                                        .custom_formatter(|val, _| {
                                            let narr_50m = val * 50.0;
                                            format!("{:.3} (-{:.2}m @50m)", val, narr_50m)
                                        }),
                                )
                                .changed();

                            ui.label("Narrowing Height (m/m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.clearance_narrowing_height, 0.0..=0.030)
                                        .step_by(0.001)
                                        .custom_formatter(|val, _| {
                                            let narr_50m = val * 50.0;
                                            format!("{:.3} (-{:.2}m @50m)", val, narr_50m)
                                        }),
                                )
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

                            ui.label("Cluster Max Depth Gap (m):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.cluster_depth_thresh, 0.20..=5.00)
                                        .step_by(0.10)
                                        .custom_formatter(|val, _| {
                                            if val <= 0.0 {
                                                "Disabled (2D only)".to_string()
                                            } else {
                                                format!("{:.2} m", val)
                                            }
                                        }),
                                )
                                .changed();

                            ui.label("Max Distance (m):");
                            param_changed |= ui
                                .add(egui::Slider::new(&mut self.max_distance_m, 5.0..=120.0).step_by(1.0))
                                .changed();

                            ui.label("Tunnel Upward Curve (c_z):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.upward_curvature, 0.0..=0.0020)
                                        .step_by(0.00005)
                                        .custom_formatter(|val, _| {
                                            let lift = val * 2500.0;
                                            format!("{:.5} (+{:.1}m @50m)", val, lift)
                                        }),
                                )
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
                    self.update_preview_texture(left.ctx());
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
                            "Detection Latency: {:.2} ms",
                            self.profiling.detector_total_ms
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

                left.add_space(4.0);
                left.group(|ui| {
                    ui.horizontal(|ui| {
                        ui.heading("⏱️ Latency & Performance");
                        let tot_ema = self.profiling.ema_total_ms;
                        let fps_approx = if tot_ema > 0.0 { 1000.0 / tot_ema } else { 0.0 };
                        let badge_color = if tot_ema <= 0.0 {
                            Color32::GRAY
                        } else if tot_ema < 30.0 {
                            Color32::from_rgb(80, 220, 100)
                        } else if tot_ema < 60.0 {
                            Color32::from_rgb(255, 190, 50)
                        } else {
                            Color32::from_rgb(255, 90, 70)
                        };
                        ui.colored_label(badge_color, format!("~{:.0} FPS cap", fps_approx));
                    });

                    ui.horizontal(|ui| {
                        ui.label("Total End-to-End:");
                        ui.monospace(format!("{:.2} ms", self.profiling.total_pipeline_ms));
                        ui.colored_label(Color32::LIGHT_GRAY, format!("(avg: {:.2} ms)", self.profiling.ema_total_ms));
                    });

                    ui.separator();

                    // Stage breakdown grid
                    egui::Grid::new("perf_grid").num_columns(3).spacing([8.0, 3.0]).show(ui, |ui| {
                        let tot = self.profiling.total_pipeline_ms.max(0.001);

                        ui.colored_label(Color32::from_rgb(0, 215, 255), "🛤️ Rail Detection");
                        ui.monospace(format!("{:>5.2} ms", self.profiling.rail_detect_ms));
                        ui.label(format!("{:>3.0}%", (self.profiling.rail_detect_ms / tot * 100.0).clamp(0.0, 100.0)));
                        ui.end_row();

                        ui.colored_label(Color32::from_rgb(255, 170, 0), "🚨 Obstacles & Clearance");
                        ui.monospace(format!("{:>5.2} ms", self.profiling.obstacle_detect_ms));
                        ui.label(format!("{:>3.0}%", (self.profiling.obstacle_detect_ms / tot * 100.0).clamp(0.0, 100.0)));
                        ui.end_row();

                        ui.colored_label(Color32::from_rgb(180, 180, 255), "🌀 Curvature Warp");
                        ui.monospace(format!("{:>5.2} ms", self.profiling.warp_ms));
                        ui.label(format!("{:>3.0}%", (self.profiling.warp_ms / tot * 100.0).clamp(0.0, 100.0)));
                        ui.end_row();

                        ui.colored_label(Color32::from_rgb(160, 220, 160), "📐 3D Restore Coords");
                        ui.monospace(format!("{:>5.2} ms", self.profiling.restore_coords_ms));
                        ui.label(format!("{:>3.0}%", (self.profiling.restore_coords_ms / tot * 100.0).clamp(0.0, 100.0)));
                        ui.end_row();

                        if self.stream_to_rerun {
                            ui.colored_label(Color32::from_rgb(220, 140, 240), "📡 Rerun 3D/2D Stream");
                            ui.monospace(format!("{:>5.2} ms", self.profiling.rerun_stream_ms));
                            ui.label(format!("{:>3.0}%", (self.profiling.rerun_stream_ms / tot * 100.0).clamp(0.0, 100.0)));
                            ui.end_row();
                        }

                        ui.colored_label(Color32::from_rgb(255, 230, 120), "🎨 2D Egui Paint");
                        ui.monospace(format!("{:>5.2} ms", self.profiling.egui_paint_ms));
                        ui.label(format!("{:>3.0}%", (self.profiling.egui_paint_ms / tot * 100.0).clamp(0.0, 100.0)));
                        ui.end_row();

                        ui.colored_label(Color32::from_rgb(140, 200, 255), "🖼️ GPU Texture Upload");
                        ui.monospace(format!("{:>5.2} ms", self.profiling.texture_upload_ms));
                        ui.label(format!("{:>3.0}%", (self.profiling.texture_upload_ms / tot * 100.0).clamp(0.0, 100.0)));
                        ui.end_row();
                    });
                });

                // ─── RIGHT COLUMN: 2D Range View Preview ───
                let right = &mut cols[1];
                right.group(|ui| {
                    let mut layer_changed = false;
                    ui.horizontal(|ui| {
                        ui.heading("📺 2D View");
                        ui.separator();
                        ui.label("Layer:");
                        layer_changed |= ui.selectable_value(
                            &mut self.layer_cfg.mode,
                            ImageLayerMode::Depth,
                            "🗺️ Depth",
                        ).changed();
                        layer_changed |= ui.selectable_value(
                            &mut self.layer_cfg.mode,
                            ImageLayerMode::Intensity,
                            "💡 Intensity",
                        ).changed();
                        layer_changed |= ui.selectable_value(
                            &mut self.layer_cfg.mode,
                            ImageLayerMode::Blend,
                            "🔀 Blend",
                        ).changed();
                    });

                    // Layer configuration sub-bar with 3 sliders (contrast_depth, contrast_intensity, blend)
                    ui.horizontal_wrapped(|ui| {
                        if self.layer_cfg.mode != ImageLayerMode::Depth {
                            ui.label("Colormap:");
                            layer_changed |= ui.selectable_value(
                                &mut self.layer_cfg.intensity_colormap,
                                IntensityColormap::Grayscale,
                                "⚪ Gray",
                            ).changed();
                            layer_changed |= ui.selectable_value(
                                &mut self.layer_cfg.intensity_colormap,
                                IntensityColormap::Turbo,
                                "🌈 Turbo",
                            ).changed();
                            ui.separator();
                        }

                        ui.label("Contrast Depth:");
                        let d_changed = ui.add(
                            egui::Slider::new(&mut self.layer_cfg.contrast_depth, 10.0..=300.0)
                                .text("m")
                                .step_by(5.0),
                        ).changed();
                        if d_changed {
                            self.contrast_depth = self.layer_cfg.contrast_depth;
                            layer_changed = true;
                        }

                        ui.separator();
                        ui.label("Contrast Intensity:");
                        let i_changed = ui.add(
                            egui::Slider::new(&mut self.layer_cfg.contrast_intensity, 5.0..=255.0)
                                .step_by(1.0),
                        ).changed();
                        if i_changed {
                            self.contrast_intensity = self.layer_cfg.contrast_intensity;
                            layer_changed = true;
                        }

                        ui.separator();
                        ui.label("Blend:");
                        let b_changed = ui.add(
                            egui::Slider::new(&mut self.layer_cfg.blend, 0.0..=1.0)
                                .text("D ↔ I")
                                .step_by(0.01),
                        ).changed();
                        if b_changed {
                            self.blend = self.layer_cfg.blend;
                            layer_changed = true;
                        }
                    });

                    if layer_changed {
                        self.update_preview_texture(ui.ctx());
                    }

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
                                ui.colored_label(Color32::from_rgb(0, 220, 220), "⬚ Shapecast");
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
    let cli_arg = args.get(1).map(|s| s.as_str());

    println!("============================================================");
    println!("🛤️  RAIL TUNER 2D — Starting Range Image Rail Detector GUI");
    println!("============================================================");

    let mut available_tracks = discover_available_tracks(cli_arg);
    if available_tracks.is_empty() {
        println!("[!] No tracks found in standard paths, defaulting to 'frames'");
        available_tracks.push(TrackSource::NpyDir(PathBuf::from("frames")));
    }

    println!("Found {} available tracks:", available_tracks.len());
    for (i, t) in available_tracks.iter().enumerate() {
        println!("  [{}] {}", i, t.label());
    }

    let initial_track_idx = 0;
    println!(
        "Loading initial track: {}",
        available_tracks[initial_track_idx].label()
    );
    let dataset = FrameDataset::from_source(available_tracks[initial_track_idx].clone());

    // Подключение к Rerun (или запуск viewer)
    println!("[*] Connecting / Spawning Rerun viewer...");
    let rec = RecordingStreamBuilder::new("rail_tuner_2d")
        .spawn()
        .or_else(|_| RecordingStreamBuilder::new("rail_tuner_2d").connect_grpc())
        .ok();

    let app = RailTuner2DApp::new(available_tracks, initial_track_idx, dataset, rec);
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
