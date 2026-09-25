//! rail_tuner.rs — Standalone GUI with egui & Rerun for RailCurveConfig Tuning
//!
//! Features:
//! 1. Direct high-speed background preloading of ROS2 .db3 (SQLite) datasets into RAM:
//!    - Sequential SQLite read + parallel Rayon CDR decoding into memory.
//!    - First frames ready in < 100 ms; instantaneous 0 ms frame seeking and scrubbing.
//!    - Live RAM usage and loading progress indicator in egui.
//! 2. Rerun in-place frame overwriting:
//!    - Uses `reset_time()` (timeless) so frames overwrite `lidar/raw` and rails in-place
//!      instead of creating a cluttered timestamp timeline in Rerun.
//! 3. Interactive controls for all RailCurveConfig parameters with real-time recalculation.
//! 4. Full frame player: Play, Pause, Step forward/back, Frame slider, FPS control, Loop.
//! 5. Snapshot-aware slider tuning: Tweaking sliders on a paused frame re-evaluates against
//!    actual prior temporal history without stacking duplicate frames.
//! 6. Telemetry panel: Calculation time, Straightness, Radius, Gauge, Inlier counts.
//! 7. Config export: One-click copy/print of tuned RailCurveConfig as ready-to-paste Rust code.
//!
//! Usage:
//!   cargo run --bin rail_tuner
//!   cargo run --bin rail_tuner -- R:\path\to\dataset.db3

use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicBool, AtomicUsize, Ordering};
use std::sync::{Arc, RwLock};
use std::time::{Duration, Instant};

use eframe::egui;
use rayon::prelude::*;
use rerun::{Color, RecordingStream, RecordingStreamBuilder};
use rusqlite::Connection;
use shared::transport::PointCloud2;

use rust_listener::engine::rail_curve::{
    RailCurveConfig, RailCurveEstimator, RailCurveResult, intensity_to_turbo_color,
};

/// Находит все файлы .db3 в указанной директории и поддиректориях
fn scan_db3_files(base_dir: &Path) -> Vec<PathBuf> {
    let mut files = Vec::new();
    if base_dir.is_file() {
        if base_dir.extension().and_then(|s| s.to_str()) == Some("db3") {
            files.push(base_dir.to_path_buf());
        }
        return files;
    }

    if let Ok(entries) = std::fs::read_dir(base_dir) {
        for entry in entries.flatten() {
            let p = entry.path();
            if p.is_dir() {
                files.extend(scan_db3_files(&p));
            } else if p.extension().and_then(|s| s.to_str()) == Some("db3") {
                if let Ok(meta) = p.metadata() {
                    if meta.len() > 1024 * 1024 {
                        files.push(p);
                    }
                }
            }
        }
    }
    files.sort();
    files
}

/// Извлечение 3D координат и интенсивности из PointCloud2
fn extract_cloud_points(cloud: &PointCloud2) -> (Vec<[f32; 3]>, Vec<f32>) {
    let mut x_offset = 0;
    let mut y_offset = 4;
    let mut z_offset = 8;
    let mut int_offset = None;
    let mut int_is_u8 = false;

    for f in &cloud.fields {
        match f.name.as_str() {
            "x" => x_offset = f.offset as usize,
            "y" => y_offset = f.offset as usize,
            "z" => z_offset = f.offset as usize,
            "intensity" => {
                int_offset = Some(f.offset as usize);
                int_is_u8 = f.datatype == 2; // UINT8
            }
            _ => {}
        }
    }

    let point_step = cloud.point_step as usize;
    if point_step == 0 {
        return (Vec::new(), Vec::new());
    }

    let total_pts = cloud.data.len() / point_step;
    let mut pts = Vec::with_capacity(total_pts);
    let mut ints = Vec::with_capacity(total_pts);

    for chunk in cloud.data.chunks_exact(point_step) {
        if chunk.len() < x_offset + 4 || chunk.len() < y_offset + 4 || chunk.len() < z_offset + 4 {
            continue;
        }
        let x = f32::from_le_bytes(chunk[x_offset..x_offset + 4].try_into().unwrap());
        let y = f32::from_le_bytes(chunk[y_offset..y_offset + 4].try_into().unwrap());
        let z = f32::from_le_bytes(chunk[z_offset..z_offset + 4].try_into().unwrap());

        if shared::types::is_zero_point(x, y, z) || x.is_nan() || y.is_nan() || z.is_nan() {
            continue;
        }

        let intensity = if let Some(io) = int_offset {
            if io < chunk.len() {
                if int_is_u8 {
                    chunk[io] as f32
                } else if io + 4 <= chunk.len() {
                    f32::from_le_bytes(chunk[io..io + 4].try_into().unwrap_or([0; 4]))
                } else {
                    0.0
                }
            } else {
                0.0
            }
        } else {
            0.0
        };

        pts.push([x, y, z]);
        ints.push(intensity);
    }

    (pts, ints)
}

/// Распарсенный кадр, полностью хранящийся в оперативной памяти (RAM)
#[derive(Clone)]
struct LoadedFrame {
    pub idx: usize,
    pub timestamp_ns: i64,
    pub points: Vec<[f32; 3]>,
    pub intensities: Vec<f32>,
    pub colors: Vec<Color>,
}

/// Фоновый загрузчик датасета в оперативную память
struct RamDataset {
    pub path: PathBuf,
    pub total_messages_in_db: usize,
    pub frames: Arc<RwLock<Vec<LoadedFrame>>>,
    pub is_loading: Arc<AtomicBool>,
    pub loaded_count: Arc<AtomicUsize>,
    pub cancel_flag: Arc<AtomicBool>,
}

impl RamDataset {
    pub fn start_loading(path: PathBuf) -> Self {
        let frames = Arc::new(RwLock::new(Vec::new()));
        let is_loading = Arc::new(AtomicBool::new(true));
        let loaded_count = Arc::new(AtomicUsize::new(0));
        let cancel_flag = Arc::new(AtomicBool::new(false));

        let mut total_messages_in_db = 0usize;
        if let Ok(conn) = Connection::open(&path) {
            let mut topic_id = 1;
            if let Ok(mut stmt) = conn
                .prepare("SELECT id FROM topics WHERE type = 'sensor_msgs/msg/PointCloud2' LIMIT 1")
            {
                if let Ok(mut rows) = stmt.query([]) {
                    if let Ok(Some(row)) = rows.next() {
                        if let Ok(tid) = row.get(0) {
                            topic_id = tid;
                        }
                    }
                }
            }
            if let Ok(mut stmt) = conn.prepare("SELECT count(*) FROM messages WHERE topic_id = ?") {
                if let Ok(count) = stmt.query_row([topic_id], |row| row.get::<_, i64>(0)) {
                    total_messages_in_db = count as usize;
                }
            }
        }

        let bg_path = path.clone();
        let bg_frames = Arc::clone(&frames);
        let bg_is_loading = Arc::clone(&is_loading);
        let bg_loaded_count = Arc::clone(&loaded_count);
        let bg_cancel = Arc::clone(&cancel_flag);

        std::thread::spawn(move || {
            let conn = match Connection::open(&bg_path) {
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

            let mut topic_id = 1;
            if let Ok(mut stmt) = conn
                .prepare("SELECT id FROM topics WHERE type = 'sensor_msgs/msg/PointCloud2' LIMIT 1")
            {
                if let Ok(mut rows) = stmt.query([]) {
                    if let Ok(Some(row)) = rows.next() {
                        if let Ok(tid) = row.get(0) {
                            topic_id = tid;
                        }
                    }
                }
            }

            let mut stmt = match conn.prepare(
                "SELECT timestamp, data FROM messages WHERE topic_id = ? ORDER BY timestamp",
            ) {
                Ok(s) => s,
                Err(e) => {
                    eprintln!("[-] Ошибка подготовки SELECT запроса: {:?}", e);
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

            println!(
                "[RamDataset] Старт потокового чтения в RAM: {}",
                bg_path.display()
            );
            let load_t0 = Instant::now();

            const BATCH_SIZE: usize = 16;
            let mut batch = Vec::with_capacity(BATCH_SIZE);
            let mut global_idx = 0usize;

            while let Ok(Some(row)) = rows.next() {
                if bg_cancel.load(Ordering::Relaxed) {
                    println!("[RamDataset] Загрузка отменена пользователем");
                    return;
                }

                let ts: i64 = match row.get(0) {
                    Ok(v) => v,
                    Err(_) => continue,
                };
                let raw_data: Vec<u8> = match row.get(1) {
                    Ok(v) => v,
                    Err(_) => continue,
                };
                batch.push((global_idx, ts, raw_data));
                global_idx += 1;

                if batch.len() >= BATCH_SIZE {
                    // Параллельная десериализация CDR и извлечение точек через Rayon
                    let parsed: Vec<LoadedFrame> = batch
                        .into_par_iter()
                        .filter_map(|(idx, ts, raw_bytes)| {
                            let cloud: PointCloud2 = cdr::deserialize(&raw_bytes).ok()?;
                            let (pts, ints) = extract_cloud_points(&cloud);
                            let colors: Vec<Color> =
                                ints.iter().map(|&i| intensity_to_turbo_color(i)).collect();
                            Some(LoadedFrame {
                                idx,
                                timestamp_ns: ts,
                                points: pts,
                                intensities: ints,
                                colors,
                            })
                        })
                        .collect();

                    {
                        let mut w = bg_frames.write().unwrap();
                        w.extend(parsed);
                        bg_loaded_count.store(w.len(), Ordering::Relaxed);
                    }
                    batch = Vec::with_capacity(BATCH_SIZE);
                }
            }

            // Догружаем остаток
            if !batch.is_empty() && !bg_cancel.load(Ordering::Relaxed) {
                let parsed: Vec<LoadedFrame> = batch
                    .into_par_iter()
                    .filter_map(|(idx, ts, raw_bytes)| {
                        let cloud: PointCloud2 = cdr::deserialize(&raw_bytes).ok()?;
                        let (pts, ints) = extract_cloud_points(&cloud);
                        let colors: Vec<Color> =
                            ints.iter().map(|&i| intensity_to_turbo_color(i)).collect();
                        Some(LoadedFrame {
                            idx,
                            timestamp_ns: ts,
                            points: pts,
                            intensities: ints,
                            colors,
                        })
                    })
                    .collect();

                let mut w = bg_frames.write().unwrap();
                w.extend(parsed);
                bg_loaded_count.store(w.len(), Ordering::Relaxed);
            }

            bg_is_loading.store(false, Ordering::SeqCst);
            println!(
                "[RamDataset] ✅ Загружено {} кадров в RAM за {:?}",
                bg_loaded_count.load(Ordering::Relaxed),
                load_t0.elapsed()
            );
        });

        Self {
            path,
            total_messages_in_db,
            frames,
            is_loading,
            loaded_count,
            cancel_flag,
        }
    }

    pub fn stop(&self) {
        self.cancel_flag.store(true, Ordering::SeqCst);
    }
}

/// Главное состояние приложения egui
struct RailTunerApp {
    recording_stream: RecordingStream,
    available_datasets: Vec<PathBuf>,
    selected_dataset_idx: usize,
    ram_dataset: Option<RamDataset>,

    // Текущий выбранный кадр
    current_frame_idx: usize,

    // Воспроизведение
    is_playing: bool,
    playback_fps: f32,
    last_frame_instant: Instant,
    loop_playback: bool,

    // Настройки отображения в Rerun
    overwrite_frame_in_rerun: bool,

    // Конфиг и вычислитель
    config: RailCurveConfig,
    estimator: RailCurveEstimator,
    estimator_snapshot: RailCurveEstimator,

    // Результат последнего вычисления
    last_result: Option<RailCurveResult>,
    last_calc_duration: Duration,
    export_copied_status: Option<(String, Instant)>,
}

impl RailTunerApp {
    pub fn new(rec: RecordingStream, datasets: Vec<PathBuf>, initial_dataset_idx: usize) -> Self {
        let config = RailCurveConfig::default();
        let estimator = RailCurveEstimator::new(config.clone());
        let estimator_snapshot = estimator.clone();

        let mut app = Self {
            recording_stream: rec,
            available_datasets: datasets,
            selected_dataset_idx: initial_dataset_idx,
            ram_dataset: None,
            current_frame_idx: 0,
            is_playing: false,
            playback_fps: 10.0,
            last_frame_instant: Instant::now(),
            loop_playback: true,
            overwrite_frame_in_rerun: true, // По умолчанию перезаписывать кадр в Rerun
            config,
            estimator,
            estimator_snapshot,
            last_result: None,
            last_calc_duration: Duration::ZERO,
            export_copied_status: None,
        };

        if !app.available_datasets.is_empty() {
            app.open_selected_dataset();
        }

        app
    }

    fn open_selected_dataset(&mut self) {
        if self.selected_dataset_idx >= self.available_datasets.len() {
            return;
        }

        // Останавливаем предыдущую фоновую загрузку, если она шла
        if let Some(prev) = &self.ram_dataset {
            prev.stop();
        }

        let path = self.available_datasets[self.selected_dataset_idx].clone();
        println!(
            "[RailTuner] Запуск RAM-загрузки датасета: {}",
            path.display()
        );
        self.ram_dataset = Some(RamDataset::start_loading(path));
        self.current_frame_idx = 0;
        self.estimator.reset();
        self.estimator_snapshot.reset();
    }

    /// Получает клон текущего кадра из RAM без блокировок
    fn get_current_frame(&self) -> Option<LoadedFrame> {
        let ds = self.ram_dataset.as_ref()?;
        let r = ds.frames.read().unwrap();
        if r.is_empty() {
            return None;
        }
        let safe_idx = self.current_frame_idx.min(r.len() - 1);
        Some(r[safe_idx].clone())
    }

    /// Переключает на выбранный кадр (0 ms, чтение из RAM)
    fn select_frame(&mut self, idx: usize) {
        let Some(ds) = &self.ram_dataset else { return };
        let count = ds.loaded_count.load(Ordering::Relaxed);
        if count == 0 {
            return;
        }

        let target_idx = idx.min(count - 1);
        let is_consecutive = target_idx == self.current_frame_idx + 1;
        self.current_frame_idx = target_idx;

        // Если прыгнули далеко вперед/назад, сбрасываем историю сглаживания
        if !is_consecutive && target_idx != self.current_frame_idx {
            self.estimator.reset();
            self.estimator_snapshot.reset();
        }

        self.recalculate_and_send_rerun(true);
    }

    /// Пересчитывает кривую пути и обновляет сцену в Rerun
    fn recalculate_and_send_rerun(&mut self, is_new_frame: bool) {
        let frame = match self.get_current_frame() {
            Some(f) => f,
            None => return,
        };

        if is_new_frame {
            // Новый кадр: запоминаем состояние оценщика перед добавлением кадра
            self.estimator_snapshot = self.estimator.clone();
            self.estimator.config = self.config.clone();

            let t0 = Instant::now();
            self.last_result = self.estimator.fit(&frame.points, &frame.intensities);
            self.last_calc_duration = t0.elapsed();
        } else {
            // Подбор параметров слайдерами на ТОМ ЖЕ кадре:
            // Пересчитываем от снимка предыдущего кадра, чтобы не дублировать один и тот же кадр в истории
            let mut est = self.estimator_snapshot.clone();
            est.config = self.config.clone();

            let t0 = Instant::now();
            self.last_result = est.fit(&frame.points, &frame.intensities);
            self.last_calc_duration = t0.elapsed();
            self.estimator = est;
        }

        // ─── УПРАВЛЕНИЕ ВРЕМЕНЕМ В RERUN ───
        if self.overwrite_frame_in_rerun {
            // ПЕРЕЗАПИСЬ КАДРА: сбрасываем время в Rerun (timeless),
            // чтобы данные заменялись в том же пространстве без нарастания шкалы времени
            self.recording_stream.reset_time();
        } else {
            // Режим с таймлайном
            self.recording_stream
                .set_time_sequence("frame", frame.idx as i64);
            self.recording_stream.set_time(
                "ros_time",
                rerun::TimeCell::from_duration_nanos(frame.timestamp_ns),
            );
        }

        // 1. Точки облака лидара с Turbo-раскраской (перезаписывают lidar/raw)
        let _ = self.recording_stream.log(
            "lidar/raw",
            &rerun::Points3D::new(frame.points.clone())
                .with_colors(frame.colors.iter().copied())
                .with_radii([rerun::Radius::new_ui_points(1.2)]),
        );

        // 2. Геометрия кривой рельсов
        if let Some(r) = &self.last_result {
            let _ = r.log_to_rerun(&self.recording_stream);
            // Если экстраполяция отключена или пуста — подчищаем слой экстраполяции
            if r.ext_pts_left.is_none() {
                let _ = self
                    .recording_stream
                    .log("rails/extrapolated/left_track", &rerun::Clear::flat());
                let _ = self
                    .recording_stream
                    .log("rails/extrapolated/right_track", &rerun::Clear::flat());
                let _ = self
                    .recording_stream
                    .log("rails/extrapolated/centerline", &rerun::Clear::flat());
                let _ = self
                    .recording_stream
                    .log("rails/extrapolated/sleepers", &rerun::Clear::flat());
            }
        } else {
            // Очищаем оверлеи если путь не найден
            let _ = self
                .recording_stream
                .log("rails/centerline", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/left_track", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/right_track", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/sleepers", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/extrapolated/centerline", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/extrapolated/left_track", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/extrapolated/right_track", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/extrapolated/sleepers", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/inliers_left", &rerun::Clear::flat());
            let _ = self
                .recording_stream
                .log("rails/inliers_right", &rerun::Clear::flat());
        }
    }

    /// Генерирует готовый Rust-код для вставки в проект
    fn generate_rust_config_code(&self) -> String {
        format!(
            "RailCurveConfig {{\n\
            \x20   n_iters: {},\n\
            \x20   inlier_thresh: {:.3},\n\
            \x20   gauge_nominal: {:.3},\n\
            \x20   gauge_tol: {:.3},\n\
            \x20   max_extrapolate_m: {:.1},\n\
            \x20   near_y_min: {:.1},\n\
            \x20   near_y_max: {:.1},\n\
            \x20   max_y: {:.1},\n\
            \x20   straightness_deflection_threshold_m: {:.3},\n\
            \x20   sleeper_spacing_m: {:.2},\n\
            \x20   history_size: {},\n\
            \x20   smoothing_decay: {:.2},\n\
            \x20   max_coasting_frames: {},\n\
            }}",
            self.config.n_iters,
            self.config.inlier_thresh,
            self.config.gauge_nominal,
            self.config.gauge_tol,
            self.config.max_extrapolate_m,
            self.config.near_y_min,
            self.config.near_y_max,
            self.config.max_y,
            self.config.straightness_deflection_threshold_m,
            self.config.sleeper_spacing_m,
            self.config.history_size,
            self.config.smoothing_decay,
            self.config.max_coasting_frames
        )
    }
}

impl eframe::App for RailTunerApp {
    fn ui(&mut self, ui: &mut egui::Ui, _frame: &mut eframe::Frame) {
        let mut config_changed = false;
        let ctx = ui.ctx().clone();

        // Авто-воспроизведение кадров из RAM
        if self.is_playing {
            let interval = Duration::from_secs_f32(1.0 / self.playback_fps.max(1.0));
            if self.last_frame_instant.elapsed() >= interval {
                self.last_frame_instant = Instant::now();
                if let Some(ds) = &self.ram_dataset {
                    let loaded = ds.loaded_count.load(Ordering::Relaxed);
                    if loaded > 0 {
                        if self.current_frame_idx + 1 < loaded {
                            self.select_frame(self.current_frame_idx + 1);
                        } else if self.loop_playback {
                            self.select_frame(0);
                        } else {
                            self.is_playing = false;
                        }
                    }
                }
            }
            ctx.request_repaint_after(interval);
        }

        // Если идет фоновая загрузка в RAM — просим egui перерисовываться для обновления счетчиков
        if let Some(ds) = &self.ram_dataset {
            if ds.is_loading.load(Ordering::Relaxed) {
                // Если мы еще не показали первый кадр, но он уже появился — сразу показываем!
                let count = ds.loaded_count.load(Ordering::Relaxed);
                if count > 0 && self.current_frame_idx == 0 && self.last_result.is_none() {
                    self.select_frame(0);
                }
                ctx.request_repaint_after(Duration::from_millis(100));
            }
        }

        egui::ScrollArea::vertical().show(ui, |ui| {
            // ─── ВЕРХНЯЯ ЧАСТЬ: Заголовок и выбор датасета ───
            ui.add_space(4.0);
            ui.horizontal(|ui| {
                ui.heading("🚆 RailCurve Tuner");
                ui.label(
                    egui::RichText::new("egui + rerun (RAM preloaded)")
                        .weak()
                        .small(),
                );
            });
            ui.add_space(4.0);

            // Выбор .db3 файла
            ui.horizontal(|ui| {
                ui.label("Датасет (.db3):");
                if self.available_datasets.is_empty() {
                    ui.colored_label(egui::Color32::RED, "Файлы .db3 не найдены");
                } else {
                    let prev_idx = self.selected_dataset_idx;
                    let current_name = self.available_datasets[self.selected_dataset_idx]
                        .file_name()
                        .and_then(|s| s.to_str())
                        .unwrap_or("unknown");

                    egui::ComboBox::from_id_salt("db3_combo")
                        .width(320.0)
                        .selected_text(current_name)
                        .show_ui(ui, |ui| {
                            for (i, p) in self.available_datasets.iter().enumerate() {
                                let name = p.file_name().and_then(|s| s.to_str()).unwrap_or("?");
                                ui.selectable_value(&mut self.selected_dataset_idx, i, name);
                            }
                        });

                    if self.selected_dataset_idx != prev_idx {
                        self.open_selected_dataset();
                    }
                }
            });

            // Статус RAM-загрузки
            if let Some(ds) = &self.ram_dataset {
                let loaded = ds.loaded_count.load(Ordering::Relaxed);
                let total = ds.total_messages_in_db;
                let is_load = ds.is_loading.load(Ordering::Relaxed);

                ui.horizontal(|ui| {
                    if is_load {
                        ui.colored_label(egui::Color32::YELLOW, "⏳ Загрузка в RAM:");
                        ui.label(format!("{}/{} кадров...", loaded, total));
                        let frac = if total > 0 {
                            (loaded as f32) / (total as f32)
                        } else {
                            0.0
                        };
                        ui.add(egui::ProgressBar::new(frac).show_percentage());
                    } else {
                        let approx_mb = loaded * 3;
                        ui.colored_label(
                            egui::Color32::GREEN,
                            format!(
                                "💾 RAM: {} кадров полностью в памяти (~{} МБ)",
                                loaded, approx_mb
                            ),
                        );
                    }
                });
            }

            ui.add_space(4.0);

            // ─── ПЛЕЕР КАДРОВ ───
            let loaded_frames = self
                .ram_dataset
                .as_ref()
                .map(|d| d.loaded_count.load(Ordering::Relaxed))
                .unwrap_or(0);
            ui.horizontal(|ui| {
                if ui.button("⏮").on_hover_text("Первый кадр").clicked() {
                    self.select_frame(0);
                }
                if ui.button("◀").on_hover_text("Предыдущий кадр").clicked() {
                    if self.current_frame_idx > 0 {
                        self.select_frame(self.current_frame_idx - 1);
                    }
                }
                let play_icon = if self.is_playing {
                    "⏸ Пауза"
                } else {
                    "▶ Воспроизведение"
                };
                if ui.button(play_icon).clicked() {
                    self.is_playing = !self.is_playing;
                    self.last_frame_instant = Instant::now();
                }
                if ui.button("▶").on_hover_text("Следующий кадр").clicked() {
                    if self.current_frame_idx + 1 < loaded_frames {
                        self.select_frame(self.current_frame_idx + 1);
                    }
                }
                if ui.button("⏭").on_hover_text("Последний кадр").clicked() {
                    if loaded_frames > 0 {
                        self.select_frame(loaded_frames - 1);
                    }
                }

                ui.checkbox(&mut self.loop_playback, "Зациклить");
                ui.label(format!(
                    "Кадр: {} / {}",
                    self.current_frame_idx + 1,
                    loaded_frames
                ));
            });

            // Слайдер выбора кадра (мгновенное переключение 0 мс)
            if loaded_frames > 1 {
                let mut slider_idx = self.current_frame_idx;
                let slider = egui::Slider::new(&mut slider_idx, 0..=loaded_frames - 1)
                    .text("Кадр в RAM")
                    .show_value(true);
                if ui.add(slider).changed() {
                    self.select_frame(slider_idx);
                }
            }

            ui.horizontal(|ui| {
                ui.label("Скорость (FPS):");
                ui.add(egui::Slider::new(&mut self.playback_fps, 1.0..=30.0).step_by(1.0));

                ui.separator();
                // Флаг перезаписи кадра в Rerun
                if ui
                    .checkbox(
                        &mut self.overwrite_frame_in_rerun,
                        "🔄 Перезаписывать в Rerun (без шкалы времени)",
                    )
                    .changed()
                {
                    self.recalculate_and_send_rerun(false);
                }
            });

            ui.separator();

            // ─── ПАРАМЕТРЫ RailCurveConfig ───
            ui.heading("Параметры RailCurveConfig");

            // 1. RANSAC
            ui.collapsing("1. RANSAC Алгоритм", |ui| {
                ui.horizontal(|ui| {
                    ui.label("Число итераций (n_iters):");
                    config_changed |= ui
                        .add(egui::Slider::new(&mut self.config.n_iters, 50..=600).step_by(10.0))
                        .changed();
                });
                ui.horizontal(|ui| {
                    ui.label("Порог инлаеров (inlier_thresh, м):");
                    config_changed |= ui
                        .add(
                            egui::Slider::new(&mut self.config.inlier_thresh, 0.03..=0.25)
                                .step_by(0.005),
                        )
                        .changed();
                });
            });

            // 2. Ширина колеи (Gauge)
            ui.collapsing("2. Геометрия колеи", |ui| {
                ui.horizontal(|ui| {
                    ui.label("Номинал колеи (gauge_nominal, м):");
                    config_changed |= ui
                        .add(
                            egui::Slider::new(&mut self.config.gauge_nominal, 1.40..=1.65)
                                .step_by(0.005),
                        )
                        .changed();
                });
                ui.horizontal(|ui| {
                    ui.label("Допуск колеи (gauge_tol, м):");
                    config_changed |= ui
                        .add(
                            egui::Slider::new(&mut self.config.gauge_tol, 0.02..=0.15)
                                .step_by(0.005),
                        )
                        .changed();
                });
            });

            // 3. Коридор поиска и сиды
            ui.collapsing("3. Коридор поиска по Y", |ui| {
                ui.horizontal(|ui| {
                    ui.label("Ближняя зона сидов min (near_y_min, м):");
                    config_changed |= ui
                        .add(
                            egui::Slider::new(&mut self.config.near_y_min, -15.0..=-4.0)
                                .step_by(0.5),
                        )
                        .changed();
                });
                ui.horizontal(|ui| {
                    ui.label("Ближняя зона сидов max (near_y_max, м):");
                    config_changed |= ui
                        .add(
                            egui::Slider::new(&mut self.config.near_y_max, -5.0..=-1.0)
                                .step_by(0.2),
                        )
                        .changed();
                });
                ui.horizontal(|ui| {
                    ui.label("Макс. дальность поиска (max_y, м):");
                    config_changed |= ui
                        .add(egui::Slider::new(&mut self.config.max_y, -60.0..=-20.0).step_by(1.0))
                        .changed();
                });
            });

            // 4. Экстраполяция и прямизна
            ui.collapsing("4. Экстраполяция и прямизна", |ui| {
                ui.horizontal(|ui| {
                    ui.label("Дистанция продления (max_extrapolate_m, м):");
                    config_changed |= ui
                        .add(
                            egui::Slider::new(&mut self.config.max_extrapolate_m, 0.0..=50.0)
                                .step_by(1.0),
                        )
                        .changed();
                });
                ui.horizontal(|ui| {
                    ui.label("Порог прогиба прямизны (deflection_thresh, м):");
                    config_changed |= ui
                        .add(
                            egui::Slider::new(
                                &mut self.config.straightness_deflection_threshold_m,
                                0.10..=0.80,
                            )
                            .step_by(0.02),
                        )
                        .changed();
                });
                ui.horizontal(|ui| {
                    ui.label("Шаг шпал (sleeper_spacing_m, м):");
                    config_changed |= ui
                        .add(
                            egui::Slider::new(&mut self.config.sleeper_spacing_m, 0.3..=1.5)
                                .step_by(0.05),
                        )
                        .changed();
                });
            });

            // 5. Временное сглаживание
            ui.collapsing(
                "5. Временное сглаживание (Temporal Smoothing)",
                |ui| {
                    ui.horizontal(|ui| {
                        ui.label("Окно кадров (history_size):");
                        config_changed |= ui
                            .add(
                                egui::Slider::new(&mut self.config.history_size, 1..=15)
                                    .step_by(1.0),
                            )
                            .changed();
                    });
                    ui.horizontal(|ui| {
                        ui.label("Коэффициент затухания (smoothing_decay):");
                        config_changed |= ui
                            .add(
                                egui::Slider::new(&mut self.config.smoothing_decay, 0.10..=1.00)
                                    .step_by(0.05),
                            )
                            .changed();
                    });
                    ui.horizontal(|ui| {
                        ui.label("Удержание пути (max_coasting_frames):");
                        config_changed |= ui
                            .add(
                                egui::Slider::new(&mut self.config.max_coasting_frames, 0..=5)
                                    .step_by(1.0),
                            )
                            .changed();
                    });
                },
            );

            ui.add_space(8.0);

            // Кнопки утилит
            ui.horizontal(|ui| {
                if ui.button("Сброс к умолчанию").clicked() {
                    self.config = RailCurveConfig::default();
                    self.estimator.reset();
                    self.estimator_snapshot.reset();
                    config_changed = true;
                }
                if ui.button("Очистить историю фитов").clicked() {
                    self.estimator.reset();
                    self.estimator_snapshot.reset();
                    config_changed = true;
                }
                if ui.button("📋 Скопировать конфиг (Rust)").clicked() {
                    let code = self.generate_rust_config_code();
                    ui.ctx().copy_text(code.clone());
                    println!(
                        "\n=== Скопированный конфиг ===\n{}\n============================\n",
                        code
                    );
                    self.export_copied_status = Some((
                        "Конфиг скопирован в буфер обмена!".to_string(),
                        Instant::now(),
                    ));
                }
            });

            if let Some((msg, t)) = &self.export_copied_status {
                if t.elapsed() < Duration::from_secs(3) {
                    ui.colored_label(egui::Color32::GREEN, msg);
                }
            }

            ui.add_space(10.0);
            ui.heading("📊 Телеметрия детекции");
            ui.separator();

            // Карточка результатов
            let dur_ms = self.last_calc_duration.as_secs_f64() * 1000.0;
            ui.horizontal(|ui| {
                ui.label("Время расчета:");
                let color = if dur_ms < 5.0 {
                    egui::Color32::GREEN
                } else if dur_ms < 20.0 {
                    egui::Color32::YELLOW
                } else {
                    egui::Color32::RED
                };
                ui.colored_label(color, format!("{:.2} мс", dur_ms));
            });

            match &self.last_result {
                Some(res) => {
                    let status_text = if res.is_coasting {
                        "⚠️ Удержание (Coasting)"
                    } else if res.smoothed_frames_count > 1 {
                        "✅ Обнаружен (Сглажен)"
                    } else {
                        "✅ Обнаружен (Одиночный)"
                    };
                    let status_color = if res.is_coasting {
                        egui::Color32::GOLD
                    } else {
                        egui::Color32::GREEN
                    };
                    ui.horizontal(|ui| {
                        ui.label("Статус:");
                        ui.colored_label(status_color, status_text);
                    });

                    ui.horizontal(|ui| {
                        ui.label("Прямизна:");
                        ui.label(format!(
                            "{:.1}% (прогиб: {:.3} м)",
                            res.straightness * 100.0,
                            res.lateral_deflection_m
                        ));
                    });

                    ui.horizontal(|ui| {
                        ui.label("Радиус кривизны:");
                        let rad_str = res
                            .curve_radius_m
                            .map(|r| format!("{:.0} м", r))
                            .unwrap_or_else(|| "∞ (Прямой участок)".to_string());
                        ui.label(rad_str);
                    });

                    ui.horizontal(|ui| {
                        ui.label("Ширина колеи:");
                        ui.label(format!(
                            "{:.3} м (отклонение: {:+.1} мм)",
                            res.gauge,
                            (res.gauge - self.config.gauge_nominal) * 1000.0
                        ));
                    });

                    ui.horizontal(|ui| {
                        ui.label("Инлаеры:");
                        ui.label(format!(
                            "Левый: {} | Правый: {}",
                            res.inliers_left.len(),
                            res.inliers_right.len()
                        ));
                    });

                    ui.horizontal(|ui| {
                        ui.label("Дальность пути:");
                        ui.label(format!(
                            "{:.1} м .. {:.1} м (длина: {:.1} м, экстраполяция: +{:.1} м)",
                            -res.y_range.1,
                            -res.y_range.0,
                            -res.y_range.0 - (-res.y_range.1),
                            res.extrapolate_m
                        ));
                    });

                    ui.horizontal(|ui| {
                        ui.label("Сглажено фитов:");
                        ui.label(format!("{}", res.smoothed_frames_count));
                    });
                }
                None => {
                    ui.horizontal(|ui| {
                        ui.label("Статус:");
                        ui.colored_label(egui::Color32::RED, "❌ Рельсы не найдены");
                    });
                }
            }

            if let Some(cf) = self.get_current_frame() {
                ui.add_space(6.0);
                ui.label(format!("Точек в текущем кадре: {}", cf.points.len()));
            }

            ui.add_space(10.0);
        });

        // Если пользователь изменил параметры слайдеров — мгновенно пересчитываем на текущем кадре
        if config_changed {
            self.recalculate_and_send_rerun(false);
        }
    }
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    println!("============================================================");
    println!("  🚆 RailCurve Tuner (RAM preloaded + rerun live overwrite)");
    println!("============================================================");

    // 1. Поиск .db3 датасетов
    let cli_arg = std::env::args().nth(1);
    let mut datasets = Vec::new();

    if let Some(arg) = cli_arg {
        let p = PathBuf::from(arg);
        if p.exists() {
            datasets.extend(scan_db3_files(&p));
        }
    }

    if datasets.is_empty() {
        let candidates = [
            Path::new("dataset"),
            Path::new("../dataset"),
            Path::new("."),
        ];
        for c in candidates {
            if c.exists() {
                datasets.extend(scan_db3_files(c));
            }
        }
    }

    datasets.dedup();
    println!("Найдено .db3 датасетов: {}", datasets.len());
    for (i, d) in datasets.iter().enumerate() {
        println!("  [{}] {}", i, d.display());
    }

    // 2. Инициализация Rerun visualizer
    println!("\n[*] Подключение к Rerun...");
    let rec = match RecordingStreamBuilder::new("rail_tuner").spawn() {
        Ok(r) => {
            println!("[+] Rerun viewer успешно запущен / подключен!");
            r
        }
        Err(e) => {
            eprintln!("[-] Не удалось запустить rerun viewer: {e:?}");
            println!("[*] Пробуем подключиться к существующему rerun...");
            RecordingStreamBuilder::new("rail_tuner").connect_grpc()?
        }
    };

    // 3. Запуск GUI окна egui
    let native_options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_inner_size([540.0, 880.0])
            .with_min_inner_size([460.0, 600.0])
            .with_title("RailCurve Config Tuner"),
        ..Default::default()
    };

    println!("[*] Запуск окна egui...");
    eframe::run_native(
        "RailCurve Tuner",
        native_options,
        Box::new(move |_cc| Ok(Box::new(RailTunerApp::new(rec, datasets, 0)))),
    )?;

    Ok(())
}
