//! top_rail_tuner_2d.rs — Orthographic Top-Down (BEV) LiDAR Rail Inspection & Tuner
//!
//! Features:
//! 1. Slices LiDAR tunnel corridor by Z <= N (default N = 0.0m).
//! 2. Renders orthographic Top-Down (Bird's Eye View) canvas at arbitrary user-configured resolution.
//! 3. Pure white canvas by default (`RGB = 255, 255, 255`).
//! 4. Points with intensity <= E (default E = 0.0) rendered with relative gradient (e.g. E=1 -> 0.5 & 1.0 colors).
//! 5. Top-down railway track detector: detects parallel rail tracks with nominal gauge (1.524m), fits 2nd order polynomial.
//! 6. Dual-stream to Rerun:
//!    - 3D view: Point cloud, cut plane Z = N, 3D track curves.
//!    - 2D view: High-resolution Top-Down orthographic canvas and 2D track overlays.
//! 7. Interactive egui GUI with real-time sliders, presets (E=0, E=1), frame player scrubber, and "Copy Rust Config".

use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicBool, AtomicUsize, Ordering};
use std::sync::{Arc, RwLock};
use std::time::{Duration, Instant};

use eframe::egui::{self, Color32, ColorImage, Key, TextureHandle, TextureOptions};
use rerun::{Color, LineStrips3D, Points3D, Radius, RecordingStream, RecordingStreamBuilder};
use shared::rail_detection::LidarGeometry;
use shared::range_image::RangeImage;

/// Turbo Colormap polynomial approximation for optional 3D point cloud coloring
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

// ─────────────────────────────────────────────────────────────────────────────
// Конфигурация и структуры ортогонального Top-Down инспектора
// ─────────────────────────────────────────────────────────────────────────────

/// Конфигурация среза тоннеля и ортогонального рендера
#[derive(Clone, Debug)]
pub struct TopRailConfig {
    /// Порог среза тоннеля по Z (Z <= z_cut). По умолчанию N = 0.0м.
    pub z_cut: f32,
    /// Нижняя граница тоннеля по Z (отсечение шума под землей)
    pub z_min: f32,
    /// Начальная дистанция вперед (м)
    pub x_min: f32,
    /// Максимальная дистанция вперед (м)
    pub x_max: f32,
    /// Полуширина тоннеля (м), Y в диапазоне [-y_max, +y_max]
    pub y_max: f32,

    /// Произвольное разрешение холста: ширина (пиксели, ось Y)
    pub canvas_width: usize,
    /// Произвольное разрешение холста: высота (пиксели, ось X)
    pub canvas_height: usize,
    /// Радиус отображения точки на холсте (1..5 пикселей)
    pub point_radius: i32,

    /// Порог интенсивности E: отображаются точки с intensity <= E. По умолчанию E = 0.0.
    pub intensity_e: f32,
    /// Минимальное значение серого в градиенте (для intensity = 0). По умолчанию 0.0 (черный).
    /// При пресете E=1: 0.5 (полутень).
    pub gradient_min: f32,
    /// Максимальное значение серого в градиенте (для intensity = E). По умолчанию 1.0 (белый/светло-серый).
    pub gradient_max: f32,

    // Параметры детекции путей на ортогональном виде
    pub detect_rails: bool,
    pub nominal_gauge: f32,
    pub gauge_tolerance: f32,
    pub extrapolate_m: f32,

    // Опции наложения на 2D холст
    pub show_grid: bool,
    pub show_rails: bool,
    pub show_raw_points: bool,
    pub show_sleepers: bool,
}

impl Default for TopRailConfig {
    fn default() -> Self {
        Self {
            z_cut: 0.0,
            z_min: -3.5,
            x_min: 1.0,
            x_max: 60.0,
            y_max: 3.5,
            canvas_width: 800,
            canvas_height: 1200,
            point_radius: 2,
            intensity_e: 0.0,
            gradient_min: 0.0,
            gradient_max: 1.0,
            detect_rails: true,
            nominal_gauge: 1.524,
            gauge_tolerance: 0.08,
            extrapolate_m: 25.0,
            show_grid: true,
            show_rails: true,
            show_raw_points: true,
            show_sleepers: true,
        }
    }
}

/// Точка, попавшая в срез тоннеля
#[derive(Clone, Copy, Debug)]
pub struct SlicedPoint {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub intensity: f32,
    pub px: i32,
    pub py: i32,
}

/// Результат детекции рельсов в ортогональной плоскости
#[derive(Clone, Debug, Default)]
pub struct TopDetectionResult {
    pub points_in_tunnel: usize,
    pub points_matching_e: usize,
    pub measured_gauge: f32,
    pub turn_radius: f32,
    pub turn_direction: String,
    pub poly_y: [f32; 3], // Y(X) = a*X^2 + b*X + c
    pub poly_z: [f32; 2], // Z(X) = d*X + e
    pub left_rail_pts: Vec<[f32; 3]>,
    pub right_rail_pts: Vec<[f32; 3]>,
    pub center_pts: Vec<[f32; 3]>,
    pub ext_center_pts: Vec<[f32; 3]>,
    pub ext_left_pts: Vec<[f32; 3]>,
    pub ext_right_pts: Vec<[f32; 3]>,
}

/// Структура детектора и рендера Top-Down вида
pub struct TopDownRailDetector {
    pub config: TopRailConfig,
}

impl TopDownRailDetector {
    pub fn new(config: TopRailConfig) -> Self {
        Self { config }
    }

    /// Преобразование координаты (X, Y) в пиксели холста (px, py).
    /// X идет снизу вверх (X_min внизу холста py = H-1, X_max вверху py = 0).
    /// Y идет слева направо (-Y_max слева px = 0, +Y_max справа px = W-1).
    #[inline(always)]
    pub fn xy_to_px(&self, x: f32, y: f32) -> (i32, i32) {
        let w = self.config.canvas_width as f32;
        let h = self.config.canvas_height as f32;
        let u = ((y + self.config.y_max) / (2.0 * self.config.y_max)).clamp(0.0, 1.0);
        let v = ((x - self.config.x_min) / (self.config.x_max - self.config.x_min)).clamp(0.0, 1.0);

        let px = (u * (w - 1.0)).round() as i32;
        let py = ((1.0 - v) * (h - 1.0)).round() as i32;
        (px, py)
    }

    /// Обратное преобразование пикселей (px, py) в метры (X, Y)
    #[inline(always)]
    pub fn px_to_xy(&self, px: i32, py: i32) -> (f32, f32) {
        let w = self.config.canvas_width as f32;
        let h = self.config.canvas_height as f32;
        let u = (px as f32 / (w - 1.0).max(1.0)).clamp(0.0, 1.0);
        let v = 1.0 - (py as f32 / (h - 1.0).max(1.0)).clamp(0.0, 1.0);

        let y = -self.config.y_max + u * (2.0 * self.config.y_max);
        let x = self.config.x_min + v * (self.config.x_max - self.config.x_min);
        (x, y)
    }

    /// Извлечение точек среза тоннеля по Z <= N из RangeImage
    pub fn extract_sliced_points(
        &self,
        frame: &RangeImage,
        geo: &LidarGeometry,
    ) -> (Vec<SlicedPoint>, Vec<SlicedPoint>) {
        let mut all_tunnel_pts = Vec::new();
        let mut matching_e_pts = Vec::new();

        let w = frame.width;
        let h = frame.height;
        let has_intensity = !frame.intensity.is_empty();

        for row in 0..h {
            let row_off = row * w;
            for col in 0..w {
                let range = frame.data[row_off + col];
                if range < 0.5 || range > 150.0 {
                    continue;
                }

                let (x, y, z) = geo.row_col_range_to_xyz(row, col, range);

                // Срез тоннеля: Z <= z_cut (где z_cut = N, по умолчанию N=0.0)
                // и границы рабочей области [x_min..x_max], [-y_max..y_max], [z_min..z_cut]
                if x >= self.config.x_min
                    && x <= self.config.x_max
                    && y >= -self.config.y_max
                    && y <= self.config.y_max
                    && z <= self.config.z_cut
                    && z >= self.config.z_min
                {
                    let intensity = if has_intensity {
                        frame.intensity[row_off + col]
                    } else {
                        0.0
                    };

                    let (px, py) = self.xy_to_px(x, y);
                    let pt = SlicedPoint {
                        x,
                        y,
                        z,
                        intensity,
                        px,
                        py,
                    };
                    all_tunnel_pts.push(pt);

                    // Фильтр по интенсивности: intensity <= E
                    if intensity <= self.config.intensity_e + 1e-4 {
                        matching_e_pts.push(pt);
                    }
                }
            }
        }

        (all_tunnel_pts, matching_e_pts)
    }

    /// Рендеринг ортогонального Top-Down изображения.
    /// Изначально холст БЕЛЫЙ. Точки intensity <= E отрисовываются с относительным градиентом.
    pub fn render_top_down(
        &self,
        matching_pts: &[SlicedPoint],
        res: Option<&TopDetectionResult>,
    ) -> ColorImage {
        let w = self.config.canvas_width;
        let h = self.config.canvas_height;

        // 1. Изначально холст БЕЛЫЙ: RGB = (255, 255, 255)
        let mut rgb = vec![255u8; w * h * 3];

        // 2. Отрисовка координатной сетки (тонкие серые линии и отметки дистанции)
        if self.config.show_grid {
            self.draw_grid(&mut rgb, w, h);
        }

        // 3. Отрисовка точек с intensity <= E относительным градиентом
        let e = self.config.intensity_e;
        let g_min = self.config.gradient_min.clamp(0.0, 1.0);
        let g_max = self.config.gradient_max.clamp(0.0, 1.0);
        let rad = self.config.point_radius.max(1);

        for pt in matching_pts {
            let gray_val = if e <= 0.0 {
                // Если E = 0: чистый черный цвет (0, 0, 0)
                (g_min * 255.0).round() as u8
            } else {
                // Относительный градиент от g_min до g_max
                let t = (pt.intensity / e).clamp(0.0, 1.0);
                let shade = g_min + t * (g_max - g_min);
                (shade * 255.0).round() as u8
            };

            draw_dot_min_rgb(&mut rgb, w, h, pt.px, pt.py, rad, gray_val);
        }

        // 4. Оверлей найденных рельсов и путевой траектории
        if self.config.show_rails {
            if let Some(r) = res {
                self.draw_rail_overlays(&mut rgb, w, h, r);
            }
        }

        ColorImage::from_rgb([w, h], &rgb)
    }

    /// Сетка разметки в метрах
    fn draw_grid(&self, rgb: &mut [u8], w: usize, h: usize) {
        let grid_col = [230, 235, 240];
        let center_col = [200, 210, 220];

        // Осевая линия Y = 0 (по курсу поезда)
        let (cx, _) = self.xy_to_px(self.config.x_min, 0.0);
        if cx >= 0 && (cx as usize) < w {
            for y in 0..h {
                let idx = (y * w + cx as usize) * 3;
                rgb[idx] = center_col[0];
                rgb[idx + 1] = center_col[1];
                rgb[idx + 2] = center_col[2];
            }
        }

        // Габаритные линии +/- 0.762м (номинальное положение рельсов)
        for &gy in &[
            -self.config.nominal_gauge * 0.5,
            self.config.nominal_gauge * 0.5,
        ] {
            let (gx, _) = self.xy_to_px(self.config.x_min, gy);
            if gx >= 0 && (gx as usize) < w {
                for y in (0..h).step_by(4) {
                    let idx = (y * w + gx as usize) * 3;
                    rgb[idx] = 215;
                    rgb[idx + 1] = 225;
                    rgb[idx + 2] = 235;
                }
            }
        }

        // Горизонтальные линии дальности каждые 10 метров
        let mut x_mark = (self.config.x_min / 10.0).ceil() * 10.0;
        while x_mark <= self.config.x_max {
            let (_, py) = self.xy_to_px(x_mark, 0.0);
            if py >= 0 && (py as usize) < h {
                for x in 0..w {
                    let idx = (py as usize * w + x) * 3;
                    rgb[idx] = grid_col[0];
                    rgb[idx + 1] = grid_col[1];
                    rgb[idx + 2] = grid_col[2];
                }
            }
            x_mark += 10.0;
        }
    }

    /// Отрисовка траектории путей
    fn draw_rail_overlays(&self, rgb: &mut [u8], w: usize, h: usize, r: &TopDetectionResult) {
        let to_px_strip = |pts: &[[f32; 3]]| -> Vec<(i32, i32)> {
            pts.iter().map(|p| self.xy_to_px(p[0], p[1])).collect()
        };

        // Sleepers (Шпалы поперек пути каждые 4 точки)
        if self.config.show_sleepers && !r.left_rail_pts.is_empty() && !r.right_rail_pts.is_empty()
        {
            let n = r.left_rail_pts.len().min(r.right_rail_pts.len());
            for i in (0..n).step_by(3) {
                let p1 = self.xy_to_px(r.left_rail_pts[i][0], r.left_rail_pts[i][1]);
                let p2 = self.xy_to_px(r.right_rail_pts[i][0], r.right_rail_pts[i][1]);
                draw_line_rgb(rgb, w, h, &[p1, p2], [140, 180, 140], 1);
            }
        }

        // 1. Левый рельс (Cyan)
        let left_strip = to_px_strip(&r.left_rail_pts);
        draw_line_rgb(rgb, w, h, &left_strip, [0, 180, 240], 2);

        // 2. Правый рельс (Orange)
        let right_strip = to_px_strip(&r.right_rail_pts);
        draw_line_rgb(rgb, w, h, &right_strip, [240, 100, 20], 2);

        // 3. Центральная линия (Bright Green)
        let center_strip = to_px_strip(&r.center_pts);
        draw_line_rgb(rgb, w, h, &center_strip, [0, 220, 50], 2);

        // 4. Экстраполяция пути (Magenta)
        if !r.ext_center_pts.is_empty() {
            let ext_c = to_px_strip(&r.ext_center_pts);
            let ext_l = to_px_strip(&r.ext_left_pts);
            let ext_r = to_px_strip(&r.ext_right_pts);

            draw_line_rgb(rgb, w, h, &ext_c, [230, 0, 230], 2);
            draw_line_rgb(rgb, w, h, &ext_l, [180, 50, 180], 1);
            draw_line_rgb(rgb, w, h, &ext_r, [180, 50, 180], 1);
        }
    }

    /// Детекция рельсов по срезанным точкам с низкой интенсивностью (черным линиям)
    pub fn detect_tracks(
        &self,
        all_pts: &[SlicedPoint],
        matching_pts: &[SlicedPoint],
    ) -> TopDetectionResult {
        let mut res = TopDetectionResult {
            points_in_tunnel: all_pts.len(),
            points_matching_e: matching_pts.len(),
            measured_gauge: self.config.nominal_gauge,
            turn_radius: 99999.0,
            turn_direction: "STRAIGHT".to_string(),
            ..Default::default()
        };

        if !self.config.detect_rails || matching_pts.len() < 10 {
            return res;
        }

        // Группируем точки с intensity <= E по продольным бинам дальности X (шаг 0.5м)
        let bin_step = 0.5_f32;
        let num_bins = ((self.config.x_max - self.config.x_min) / bin_step).ceil() as usize;
        let mut bins: Vec<Vec<&SlicedPoint>> = vec![Vec::new(); num_bins];

        for pt in matching_pts {
            let bin_idx = ((pt.x - self.config.x_min) / bin_step) as usize;
            if bin_idx < num_bins {
                bins[bin_idx].push(pt);
            }
        }

        let mut center_xs = Vec::new();
        let mut center_ys = Vec::new();
        let mut center_zs = Vec::new();
        let mut gauges = Vec::new();

        let half_g = self.config.nominal_gauge * 0.5;
        let g_min = self.config.nominal_gauge - self.config.gauge_tolerance;
        let g_max = self.config.nominal_gauge + self.config.gauge_tolerance;

        for bin in bins {
            if bin.len() < 2 {
                continue;
            }

            // Ищем кандидатов слева (Y < 0) и справа (Y > 0)
            let mut left_cands: Vec<&SlicedPoint> = bin
                .iter()
                .filter(|p| p.y < -0.2 && p.y > -half_g - 0.6)
                .cloned()
                .collect();
            let mut right_cands: Vec<&SlicedPoint> = bin
                .iter()
                .filter(|p| p.y > 0.2 && p.y < half_g + 0.6)
                .cloned()
                .collect();

            if left_cands.is_empty() || right_cands.is_empty() {
                continue;
            }

            // Выбираем пары с минимальной интенсивностью (самые темные точки)
            left_cands.sort_by(|a, b| a.intensity.partial_cmp(&b.intensity).unwrap());
            right_cands.sort_by(|a, b| a.intensity.partial_cmp(&b.intensity).unwrap());

            let mut best_pair = None;
            let mut best_score = f32::INFINITY;

            for lp in left_cands.iter().take(5) {
                for rp in right_cands.iter().take(5) {
                    let d = (rp.y - lp.y).abs();
                    if d >= g_min && d <= g_max {
                        let score = (d - self.config.nominal_gauge).abs()
                            + 0.1 * (lp.intensity + rp.intensity);
                        if score < best_score {
                            best_score = score;
                            best_pair = Some((*lp, *rp, d));
                        }
                    }
                }
            }

            if let Some((lp, rp, gauge)) = best_pair {
                let xm = 0.5 * (lp.x + rp.x);
                let ym = 0.5 * (lp.y + rp.y);
                let zm = 0.5 * (lp.z + rp.z);

                center_xs.push(xm);
                center_ys.push(ym);
                center_zs.push(zm);
                gauges.push(gauge);
            }
        }

        if center_xs.len() < 4 {
            return res;
        }

        // Средняя замеренная колея
        let mean_gauge = gauges.iter().sum::<f32>() / gauges.len() as f32;
        res.measured_gauge = mean_gauge;

        // Аппроксимация центральной кривой полиномом 2-й степени Y(X) = a*X^2 + b*X + c
        if let Some(poly_y) = polyfit2(&center_xs, &center_ys) {
            res.poly_y = poly_y;
            let [a, b, c] = poly_y;

            // Радиус кривизны: R = 1 / (2 * |a|)
            res.turn_radius = if a.abs() > 1e-6 {
                1.0 / (2.0 * a.abs())
            } else {
                99999.0
            };

            let lateral_shift_15m = a * (15.0 * 15.0) + b * 15.0;
            res.turn_direction = if lateral_shift_15m.abs() < 0.20 && a.abs() < 0.0003 {
                "STRAIGHT".to_string()
            } else if lateral_shift_15m < 0.0 || a < 0.0 {
                "CURVE LEFT".to_string()
            } else {
                "CURVE RIGHT".to_string()
            };

            // Линейная аппроксимация высоты Z(X) = d*X + e
            let poly_z = polyfit1(&center_xs, &center_zs).unwrap_or([0.0, -1.8]);
            res.poly_z = poly_z;
            let [d, e] = poly_z;

            // Дискретизация кривой рельсов на 80 точек
            let x_start = center_xs.first().cloned().unwrap_or(self.config.x_min);
            let x_end = center_xs.last().cloned().unwrap_or(self.config.x_max);
            let n_pts = 80;

            for i in 0..n_pts {
                let t = i as f32 / (n_pts - 1) as f32;
                let xc = x_start + t * (x_end - x_start);
                let yc = a * xc * xc + b * xc + c;
                let zc = d * xc + e;

                let theta = (2.0 * a * xc + b).atan();
                let sin_t = theta.sin();
                let cos_t = theta.cos();
                let half_w = 0.5 * mean_gauge;

                res.center_pts.push([xc, yc, zc]);
                res.left_rail_pts
                    .push([xc + half_w * sin_t, yc - half_w * cos_t, zc]);
                res.right_rail_pts
                    .push([xc - half_w * sin_t, yc + half_w * cos_t, zc]);
            }

            // Экстраполяция вперед
            if self.config.extrapolate_m > 0.0 {
                let n_ext = 50;
                let x_ext_end = x_end + self.config.extrapolate_m;
                for i in 0..n_ext {
                    let t = i as f32 / (n_ext - 1) as f32;
                    let xe = x_end + t * (x_ext_end - x_end);
                    let ye = a * xe * xe + b * xe + c;
                    let ze = d * xe + e;

                    let theta = (2.0 * a * xe + b).atan();
                    let sin_t = theta.sin();
                    let cos_t = theta.cos();
                    let half_w = 0.5 * mean_gauge;

                    res.ext_center_pts.push([xe, ye, ze]);
                    res.ext_left_pts
                        .push([xe + half_w * sin_t, ye - half_w * cos_t, ze]);
                    res.ext_right_pts
                        .push([xe - half_w * sin_t, ye + half_w * cos_t, ze]);
                }
            }
        }

        res
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// Вспомогательные функции рендера и математики
// ─────────────────────────────────────────────────────────────────────────────

/// Отрисовка круглой точки с сохранением минимального значения серого (темный цвет доминирует)
fn draw_dot_min_rgb(rgb: &mut [u8], w: usize, h: usize, cx: i32, cy: i32, rad: i32, gray_val: u8) {
    for dy in -rad..=rad {
        for dx in -rad..=rad {
            if dx * dx + dy * dy <= rad * rad {
                let x = cx + dx;
                let y = cy + dy;
                if x >= 0 && (x as usize) < w && y >= 0 && (y as usize) < h {
                    let idx = (y as usize * w + x as usize) * 3;
                    if gray_val < rgb[idx] {
                        rgb[idx] = gray_val;
                        rgb[idx + 1] = gray_val;
                        rgb[idx + 2] = gray_val;
                    }
                }
            }
        }
    }
}

/// Отрисовка отрезков линий методом Брезенхема
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

/// Линейная регрессия Z(X) = d*X + e
fn polyfit1(xs: &[f32], ys: &[f32]) -> Option<[f32; 2]> {
    let n = xs.len() as f32;
    if n < 2.0 {
        return None;
    }
    let sum_x: f32 = xs.iter().sum();
    let sum_y: f32 = ys.iter().sum();
    let sum_xx: f32 = xs.iter().map(|&x| x * x).sum();
    let sum_xy: f32 = xs.iter().zip(ys.iter()).map(|(&x, &y)| x * y).sum();

    let denom = n * sum_xx - sum_x * sum_x;
    if denom.abs() < 1e-7 {
        return None;
    }

    let slope = (n * sum_xy - sum_x * sum_y) / denom;
    let intercept = (sum_y - slope * sum_x) / n;
    Some([slope, intercept])
}

/// Квадратичная регрессия Y(X) = a*X^2 + b*X + c методом наименьших квадратов
fn polyfit2(xs: &[f32], ys: &[f32]) -> Option<[f32; 3]> {
    let n = xs.len() as f64;
    if n < 3.0 {
        return None;
    }

    let mut sx = 0.0;
    let mut sx2 = 0.0;
    let mut sx3 = 0.0;
    let mut sx4 = 0.0;
    let mut sy = 0.0;
    let mut sxy = 0.0;
    let mut sx2y = 0.0;

    for (&x_f, &y_f) in xs.iter().zip(ys.iter()) {
        let x = x_f as f64;
        let y = y_f as f64;
        let x2 = x * x;
        sx += x;
        sx2 += x2;
        sx3 += x2 * x;
        sx4 += x2 * x2;
        sy += y;
        sxy += x * y;
        sx2y += x2 * y;
    }

    let m = [[sx4, sx3, sx2, sx2y], [sx3, sx2, sx, sxy], [sx2, sx, n, sy]];

    let det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
        - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
        + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

    if det.abs() < 1e-12 {
        return None;
    }

    let det_a = m[0][3] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
        - m[0][1] * (m[1][3] * m[2][2] - m[1][2] * m[2][3])
        + m[0][2] * (m[1][3] * m[2][1] - m[1][1] * m[2][3]);

    let det_b = m[0][0] * (m[1][3] * m[2][2] - m[1][2] * m[2][3])
        - m[0][3] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
        + m[0][2] * (m[1][0] * m[2][3] - m[1][3] * m[2][0]);

    let det_c = m[0][0] * (m[1][1] * m[2][3] - m[1][3] * m[2][1])
        - m[0][1] * (m[1][0] * m[2][3] - m[1][3] * m[2][0])
        + m[0][3] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

    Some([
        (det_a / det) as f32,
        (det_b / det) as f32,
        (det_c / det) as f32,
    ])
}

// ─────────────────────────────────────────────────────────────────────────────
// GUI Приложение TopRailTunerApp
// ─────────────────────────────────────────────────────────────────────────────

pub struct TopRailTunerApp {
    dataset: FrameDataset,
    current_frame_idx: usize,
    is_playing: bool,
    fps: f32,
    last_tick: Instant,

    detector: TopDownRailDetector,
    geometry: LidarGeometry,

    last_res: Option<TopDetectionResult>,
    last_calc_dur: Duration,
    texture: Option<TextureHandle>,
    last_painted_frame: Option<usize>,
    copied_toast_time: Option<Instant>,

    // Rerun
    rec_stream: Option<RecordingStream>,
    stream_to_rerun: bool,
}

impl TopRailTunerApp {
    pub fn new(dataset: FrameDataset, rec_stream: Option<RecordingStream>) -> Self {
        let config = TopRailConfig::default();
        let geometry = LidarGeometry::new(128, 140, 15.0, -25.0, 40.0);
        let detector = TopDownRailDetector::new(config);

        Self {
            dataset,
            current_frame_idx: 0,
            is_playing: false,
            fps: 10.0,
            last_tick: Instant::now(),
            detector,
            geometry,
            last_res: None,
            last_calc_dur: Duration::ZERO,
            texture: None,
            last_painted_frame: None,
            copied_toast_time: None,
            rec_stream,
            stream_to_rerun: true,
        }
    }

    pub fn process_current_frame(&mut self) {
        let lock = self.dataset.frames.read().unwrap();
        if lock.is_empty() || self.current_frame_idx >= lock.len() {
            return;
        }

        let frame = &lock[self.current_frame_idx];

        if self.geometry.height != frame.range_image.height
            || self.geometry.width != frame.range_image.width
        {
            self.geometry = LidarGeometry::new(
                frame.range_image.height,
                frame.range_image.width,
                15.0,
                -25.0,
                40.0,
            );
        }

        let t0 = Instant::now();
        let (all_pts, matching_pts) = self
            .detector
            .extract_sliced_points(&frame.range_image, &self.geometry);
        let res = self.detector.detect_tracks(&all_pts, &matching_pts);
        self.last_calc_dur = t0.elapsed();
        self.last_res = Some(res);

        // Отправка в Rerun
        if self.stream_to_rerun {
            if let Some(ref rec) = self.rec_stream {
                rec.set_time_sequence("frame", frame.idx as i64);

                // ─── ОКНО 1: 3D сцена с секущей плоскостью Z = N ───
                let ri = &frame.range_image;
                let total = self.geometry.height * self.geometry.width;
                let mut pts_3d = Vec::with_capacity(total);
                let mut cols_3d = Vec::with_capacity(total);

                for r in 0..self.geometry.height {
                    let r_off = r * self.geometry.width;
                    for c in 0..self.geometry.width {
                        let range = ri.data[r_off + c];
                        if range > 0.5 && range < 150.0 {
                            let (x, y, z) = self.geometry.row_col_range_to_xyz(r, c, range);
                            pts_3d.push([x, y, z]);

                            if z <= self.detector.config.z_cut {
                                // Точки ниже секущей плоскости — подсветка Turbo
                                let norm = (range / 80.0).clamp(0.0, 1.0);
                                let rgb = turbo_rgb(norm);
                                cols_3d.push(Color::from_rgb(rgb[0], rgb[1], rgb[2]));
                            } else {
                                // Точки выше Z=N — полупрозрачные серые
                                cols_3d.push(Color::from_rgb(70, 75, 80));
                            }
                        }
                    }
                }

                let _ = rec.log(
                    "lidar/3d_points",
                    &Points3D::new(pts_3d)
                        .with_colors(cols_3d)
                        .with_radii([Radius::new_ui_points(1.2)]),
                );

                // Линии путей в 3D
                if let Some(ref r) = self.last_res {
                    if !r.center_pts.is_empty() {
                        let _ = rec.log(
                            "lidar/3d_tracks/centerline",
                            &LineStrips3D::new([r.center_pts.clone()])
                                .with_colors([Color::from_rgb(0, 255, 60)])
                                .with_radii([Radius::new_ui_points(2.5)]),
                        );
                    }
                    if !r.left_rail_pts.is_empty() {
                        let _ = rec.log(
                            "lidar/3d_tracks/left_rail",
                            &LineStrips3D::new([r.left_rail_pts.clone()])
                                .with_colors([Color::from_rgb(0, 200, 255)])
                                .with_radii([Radius::new_ui_points(2.0)]),
                        );
                    }
                    if !r.right_rail_pts.is_empty() {
                        let _ = rec.log(
                            "lidar/3d_tracks/right_rail",
                            &LineStrips3D::new([r.right_rail_pts.clone()])
                                .with_colors([Color::from_rgb(255, 120, 20)])
                                .with_radii([Radius::new_ui_points(2.0)]),
                        );
                    }
                    if !r.ext_center_pts.is_empty() {
                        let _ = rec.log(
                            "lidar/3d_tracks/extrapolation",
                            &LineStrips3D::new([r.ext_center_pts.clone()])
                                .with_colors([Color::from_rgb(255, 0, 255)])
                                .with_radii([Radius::new_ui_points(2.2)]),
                        );
                    }
                }

                // ─── ОКНО 2: 2D Ортогональный вид (Top-Down BEV Canvas) ───
                let color_img = self
                    .detector
                    .render_top_down(&matching_pts, self.last_res.as_ref());
                let rerun_img = rerun::Image::from_rgb24(
                    color_img.as_raw(),
                    [color_img.width() as u32, color_img.height() as u32],
                );
                let _ = rec.log("top_down/bev_canvas", &rerun_img);
            }
        }
    }
}

impl eframe::App for TopRailTunerApp {
    fn ui(&mut self, ui: &mut egui::Ui, _frame: &mut eframe::Frame) {
        // Клавиатурные шорткаты
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
            self.process_current_frame();
        }
        let total_loaded = self.dataset.loaded_count.load(Ordering::Relaxed);
        if input.2 && self.current_frame_idx + 1 < total_loaded {
            self.current_frame_idx += 1;
            self.process_current_frame();
        }

        // Тикер воспроизведения
        if self.is_playing && total_loaded > 0 {
            let interval = Duration::from_secs_f32(1.0 / self.fps.max(1.0));
            if self.last_tick.elapsed() >= interval {
                self.last_tick = Instant::now();
                if self.current_frame_idx + 1 < total_loaded {
                    self.current_frame_idx += 1;
                } else {
                    self.current_frame_idx = 0; // Loop
                }
                self.process_current_frame();
            }
            ui.ctx().request_repaint();
        }

        // Основная область: Заголовок и 2 колонки
        egui::ScrollArea::vertical().show(ui, |ui| {
            // Верхняя панель статуса
            ui.horizontal(|ui| {
                ui.heading("🛰️ Top Rail Tuner 2D");
                ui.separator();
                ui.label("Orthographic BEV Tunnel Inspection | Z <= N Slicing");

                ui.separator();
                let is_loading = self.dataset.is_loading.load(Ordering::Relaxed);
                if is_loading {
                    ui.spinner();
                    ui.label(format!(
                        "Loading: {} / {}",
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
                            "// TopRailConfig (Orthographic Top-Down Tuner)\n\
                             let mut top_cfg = TopRailConfig::default();\n\
                             top_cfg.z_cut = {:.3};\n\
                             top_cfg.z_min = {:.3};\n\
                             top_cfg.x_min = {:.2};\n\
                             top_cfg.x_max = {:.2};\n\
                             top_cfg.y_max = {:.2};\n\
                             top_cfg.canvas_width = {};\n\
                             top_cfg.canvas_height = {};\n\
                             top_cfg.point_radius = {};\n\
                             top_cfg.intensity_e = {:.2};\n\
                             top_cfg.gradient_min = {:.2};\n\
                             top_cfg.gradient_max = {:.2};\n\
                             top_cfg.detect_rails = {};\n\
                             top_cfg.nominal_gauge = {:.3};\n\
                             top_cfg.gauge_tolerance = {:.3};\n\
                             top_cfg.extrapolate_m = {:.1};",
                            self.detector.config.z_cut,
                            self.detector.config.z_min,
                            self.detector.config.x_min,
                            self.detector.config.x_max,
                            self.detector.config.y_max,
                            self.detector.config.canvas_width,
                            self.detector.config.canvas_height,
                            self.detector.config.point_radius,
                            self.detector.config.intensity_e,
                            self.detector.config.gradient_min,
                            self.detector.config.gradient_max,
                            self.detector.config.detect_rails,
                            self.detector.config.nominal_gauge,
                            self.detector.config.gauge_tolerance,
                            self.detector.config.extrapolate_m,
                        );
                        ui.ctx().copy_text(cfg.clone());
                        println!("\n{}\n", cfg);
                        self.copied_toast_time = Some(Instant::now());
                    }

                    ui.checkbox(
                        &mut self.stream_to_rerun,
                        "📡 Stream to Rerun (3D + 2D BEV)",
                    );
                });
            });

            ui.separator();

            // Центральная область: Левая колонка — параметры, Правая колонка — ортогональный Top-Down холст
            ui.columns(2, |cols| {
                // ─── ЛЕВАЯ КОЛОНКА: Настройки и Управление ───
                let left = &mut cols[0];

                egui::ScrollArea::vertical()
                    .id_salt("params_scroll")
                    .show(left, |ui| {
                        ui.group(|ui| {
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
                                    self.process_current_frame();
                                }
                            }
                        });

                        ui.add_space(4.0);
                        let mut param_changed = false;

                        ui.group(|ui| {
                            ui.heading("✂️ Tunnel Z-Slicing (срез тоннеля по Z=N)");
                            ui.label("Порог среза по высоте Z <= N (м):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.detector.config.z_cut, -3.0..=5.0)
                                        .step_by(0.1),
                                )
                                .changed();

                            ui.label("Нижняя граница тоннеля Z_min (м):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.detector.config.z_min, -6.0..=0.0)
                                        .step_by(0.1),
                                )
                                .changed();

                            ui.label("Полуширина тоннеля Y_max (м):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(&mut self.detector.config.y_max, 1.5..=10.0)
                                        .step_by(0.25),
                                )
                                .changed();

                            ui.horizontal(|ui| {
                                ui.label("Дистанция X_min:");
                                param_changed |= ui
                                    .add(
                                        egui::Slider::new(
                                            &mut self.detector.config.x_min,
                                            0.5..=10.0,
                                        )
                                        .step_by(0.5),
                                    )
                                    .changed();
                            });
                            ui.horizontal(|ui| {
                                ui.label("Дистанция X_max:");
                                param_changed |= ui
                                    .add(
                                        egui::Slider::new(
                                            &mut self.detector.config.x_max,
                                            15.0..=120.0,
                                        )
                                        .step_by(5.0),
                                    )
                                    .changed();
                            });
                        });

                        ui.add_space(4.0);

                        ui.group(|ui| {
                            ui.heading("💡 Intensity Threshold & Relative Gradient");
                            ui.label("Порог интенсивности E (точки intensity <= E):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(
                                        &mut self.detector.config.intensity_e,
                                        0.0..=50.0,
                                    )
                                    .step_by(0.5),
                                )
                                .changed();

                            ui.horizontal_wrapped(|ui| {
                                ui.label("Быстрые пресеты:");
                                if ui.button("E=0 (Черный)").clicked() {
                                    self.detector.config.intensity_e = 0.0;
                                    self.detector.config.gradient_min = 0.0;
                                    self.detector.config.gradient_max = 1.0;
                                    param_changed = true;
                                }
                                if ui.button("E=1 (0.5 и 1 цвета)").clicked() {
                                    self.detector.config.intensity_e = 1.0;
                                    self.detector.config.gradient_min = 0.5;
                                    self.detector.config.gradient_max = 1.0;
                                    param_changed = true;
                                }
                                if ui.button("Full Dynamic (0..1)").clicked() {
                                    self.detector.config.gradient_min = 0.0;
                                    self.detector.config.gradient_max = 1.0;
                                    param_changed = true;
                                }
                            });

                            ui.label("Gradient Min (для I=0):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(
                                        &mut self.detector.config.gradient_min,
                                        0.0..=1.0,
                                    )
                                    .step_by(0.05),
                                )
                                .changed();

                            ui.label("Gradient Max (для I=E):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(
                                        &mut self.detector.config.gradient_max,
                                        0.0..=1.0,
                                    )
                                    .step_by(0.05),
                                )
                                .changed();

                            ui.label("Радиус точки (Point Splat Radius):");
                            param_changed |= ui
                                .add(egui::Slider::new(
                                    &mut self.detector.config.point_radius,
                                    1..=5,
                                ))
                                .changed();
                        });

                        ui.add_space(4.0);

                        ui.group(|ui| {
                            ui.heading("🖼️ Canvas Resolution (произвольное разрешение)");
                            ui.horizontal(|ui| {
                                ui.label("Ширина (px):");
                                param_changed |= ui
                                    .add(
                                        egui::Slider::new(
                                            &mut self.detector.config.canvas_width,
                                            400..=1600,
                                        )
                                        .step_by(50.0),
                                    )
                                    .changed();
                            });
                            ui.horizontal(|ui| {
                                ui.label("Высота (px):");
                                param_changed |= ui
                                    .add(
                                        egui::Slider::new(
                                            &mut self.detector.config.canvas_height,
                                            600..=2400,
                                        )
                                        .step_by(50.0),
                                    )
                                    .changed();
                            });

                            ui.horizontal(|ui| {
                                ui.label("Пресеты разрешения:");
                                if ui.button("600x1000").clicked() {
                                    self.detector.config.canvas_width = 600;
                                    self.detector.config.canvas_height = 1000;
                                    param_changed = true;
                                }
                                if ui.button("800x1200").clicked() {
                                    self.detector.config.canvas_width = 800;
                                    self.detector.config.canvas_height = 1200;
                                    param_changed = true;
                                }
                                if ui.button("1024x1600").clicked() {
                                    self.detector.config.canvas_width = 1024;
                                    self.detector.config.canvas_height = 1600;
                                    param_changed = true;
                                }
                            });
                        });

                        ui.add_space(4.0);

                        ui.group(|ui| {
                            ui.heading("🛤️ Track Detection & Extrapolation");
                            param_changed |= ui
                                .checkbox(
                                    &mut self.detector.config.detect_rails,
                                    "Включить поиск рельсов",
                                )
                                .changed();

                            ui.label("Номинальная колея (м):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(
                                        &mut self.detector.config.nominal_gauge,
                                        1.45..=1.65,
                                    )
                                    .step_by(0.005),
                                )
                                .changed();

                            ui.label("Допуск колеи (м):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(
                                        &mut self.detector.config.gauge_tolerance,
                                        0.02..=0.20,
                                    )
                                    .step_by(0.01),
                                )
                                .changed();

                            ui.label("Дистанция экстраполяции (м):");
                            param_changed |= ui
                                .add(
                                    egui::Slider::new(
                                        &mut self.detector.config.extrapolate_m,
                                        0.0..=60.0,
                                    )
                                    .step_by(5.0),
                                )
                                .changed();

                            ui.horizontal(|ui| {
                                param_changed |= ui
                                    .checkbox(&mut self.detector.config.show_grid, "Сетка разметки")
                                    .changed();
                                param_changed |= ui
                                    .checkbox(&mut self.detector.config.show_rails, "Линии путей")
                                    .changed();
                                param_changed |= ui
                                    .checkbox(&mut self.detector.config.show_sleepers, "Шпалы")
                                    .changed();
                            });
                        });

                        ui.add_space(4.0);

                        ui.group(|ui| {
                            ui.heading("📊 Telemetry HUD");
                            if let Some(ref r) = self.last_res {
                                ui.horizontal(|ui| {
                                    ui.colored_label(
                                        Color32::from_rgb(0, 200, 255),
                                        format!("Gauge: {:.3}m", r.measured_gauge),
                                    );
                                    ui.label(format!("Radius: {:.0}m", r.turn_radius));
                                    ui.colored_label(
                                        Color32::YELLOW,
                                        format!("Dir: {}", r.turn_direction),
                                    );
                                });
                                ui.label(format!(
                                    "Points in Z-Cut Tunnel: {} | With Intensity <= E: {}",
                                    r.points_in_tunnel, r.points_matching_e
                                ));
                                ui.label(format!(
                                    "Frame Processing Latency: {:.1} ms",
                                    self.last_calc_dur.as_secs_f32() * 1000.0
                                ));
                            } else {
                                ui.colored_label(Color32::GRAY, "Processing frame...");
                            }
                        });

                        if param_changed {
                            self.process_current_frame();
                            self.texture = None; // Сброс текстуры для немедленной перерисовки
                        }
                    });

                // ─── ПРАВАЯ КОЛОНКА: Top-Down Ортогональный холст ───
                let right = &mut cols[1];
                right.group(|ui| {
                    ui.horizontal(|ui| {
                        ui.heading("📺 Orthographic Top-Down View");
                        ui.separator();
                        ui.label(format!(
                            "Canvas: {}x{} | Z <= {:.1}m | I <= {:.1}",
                            self.detector.config.canvas_width,
                            self.detector.config.canvas_height,
                            self.detector.config.z_cut,
                            self.detector.config.intensity_e
                        ));
                    });

                    // Рендерим текстуру для отображения в egui
                    let lock = self.dataset.frames.read().unwrap();
                    if self.current_frame_idx < lock.len() {
                        let f = &lock[self.current_frame_idx];
                        if self.texture.is_none()
                            || self.last_painted_frame != Some(self.current_frame_idx)
                        {
                            let (_, matching_pts) = self
                                .detector
                                .extract_sliced_points(&f.range_image, &self.geometry);
                            let color_img = self
                                .detector
                                .render_top_down(&matching_pts, self.last_res.as_ref());
                            self.texture = Some(ui.ctx().load_texture(
                                "top_down_view",
                                color_img,
                                TextureOptions::LINEAR,
                            ));
                            self.last_painted_frame = Some(self.current_frame_idx);
                        }
                    }

                    if let Some(ref tex) = self.texture {
                        let img_size = tex.size_vec2();
                        let max_h = (ui.available_height() - 40.0).max(200.0);
                        let aspect = img_size.x / img_size.y.max(1.0);
                        let final_size = egui::vec2(max_h * aspect, max_h);

                        ui.vertical_centered(|ui| {
                            ui.image((tex.id(), final_size));
                            ui.add_space(4.0);
                            ui.horizontal_wrapped(|ui| {
                                ui.colored_label(Color32::from_rgb(0, 180, 240), "■ Left Rail");
                                ui.colored_label(Color32::from_rgb(240, 100, 20), "■ Right Rail");
                                ui.colored_label(Color32::from_rgb(0, 220, 50), "■ Centerline");
                                ui.colored_label(Color32::from_rgb(230, 0, 230), "■ Extrapolation");
                                ui.colored_label(Color32::from_rgb(140, 180, 140), "■ Sleepers");
                                ui.colored_label(Color32::BLACK, "■ Points (I <= E)");
                            });
                        });
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
    println!("🛰️  TOP RAIL TUNER 2D — Orthographic Top-Down LiDAR Rail Tuner");
    println!("Target path: {}", target);
    println!("Approach: Z <= N Slicing + Orthographic BEV + Relative Intensity Gradient");
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
    let rec = RecordingStreamBuilder::new("top_rail_tuner_2d")
        .spawn()
        .or_else(|_| RecordingStreamBuilder::new("top_rail_tuner_2d").connect_grpc())
        .ok();

    let mut app = TopRailTunerApp::new(dataset, rec);
    app.process_current_frame();

    let native_options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_inner_size([1280.0, 850.0])
            .with_min_inner_size([800.0, 600.0])
            .with_title("Top Rail Tuner 2D — Orthographic BEV Rail Inspection"),
        ..Default::default()
    };

    eframe::run_native(
        "Top Rail Tuner 2D",
        native_options,
        Box::new(|_cc| Ok(Box::new(app))),
    )?;

    Ok(())
}
