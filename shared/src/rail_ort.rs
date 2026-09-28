//! rail_ort.rs — Orthographic / Ring-based Railway Track Detection for 3D LiDAR
//!
//! Алгоритм детекции:
//! 1. На вход принимаются PointCloud и ProcessingQueue:
//!    - `crop_tunnel` производит пространственную обрезку тоннеля: Z in [z_min, z_max], X in [x_min, x_max].
//!    - Фильтрация коллизий: отсечение слишком близких точек на кольце (< min_point_distance).
//!    - Точки сохраняются в виде `RawFloorPoint` (хранит компактный индекс в PointCloud).
//! 2. По кольцам от `ring_start` к `ring_end` ищутся резкие скачки по отражающей способности (|Delta I| >= intensity_jump_threshold).
//! 3. Кандидаты отбираются по ширине колеи (nominal_gauge +- tolerance), высоте и непрерывности (lateral jump).
//! 4. Аппроксимация траектории полиномами (Y(X) парабола, Z(X) наклон), темпоральное сглаживание, экстраполяция и Boxcast габарита.

use std::collections::VecDeque;
use std::time::Instant;

use crate::rail_detection::{
    DetectionHistoryItem, LidarGeometry, ObstacleConfig, RailPoint,
    RailTrackDetector, TrackObstacle,
};
use crate::range_image::RangeImage;
use crate::types::{is_zero_point, AppPointCloud, ProcessingQueue};

/// Конфигурация ортографического детектора путей по кольцам (RailOrt)
#[derive(Clone, Debug)]
pub struct RailOrtConfig {
    /// Нижняя граница по высоте полотна (м), отсечение подпола/балласта
    pub z_min: f32,
    /// Верхняя граница по высоте полотна (м), отсечение потолка, подвеса и верхних стен
    pub z_max: f32,
    /// Минимальная дистанция вперед (м)
    pub y_min: f32,
    /// Максимальная дистанция вперед (м)
    pub y_max: f32,

    /// Стартовое (ближнее к поезду) кольцо лидара (номер ring/строки, например 127)
    pub ring_start: usize,
    /// Конечное (дальнее) кольцо лидара (номер ring/строки, например 15)
    pub ring_end: usize,

    /// Порог резкого скачка по отражающей способности (|Delta I|) для поиска кандидатов
    pub intensity_jump_threshold: f32,
    /// Максимальная интенсивность точки рельса (0 = не ограничивать)
    pub intensity_max: f32,

    /// Минимальное расстояние между точками на одном кольце для фильтрации коллизий/прореживания (м)
    /// Например 0.01 (1 см) или 0.05 (5 см). 0.0 = фильтрация отключена.
    pub min_point_distance: f32,

    /// Номинальная ширина колеи (м), стандарт 1.520 м (1520 мм)
    pub nominal_gauge: f32,
    /// Допуск ширины колеи (м), например 0.08 м (диапазон [nominal - tol .. nominal + tol])
    pub gauge_tolerance: f32,
    /// Максимальная разница по высоте между левым и правым рельсом (м)
    pub max_rail_height_diff: f32,

    /// Максимально допустимый скачок центра колеи между кольцами по Y (м)
    pub max_lateral_jump: f32,
    /// Максимально допустимый скачок отдельного рельса между кольцами по Y (м)
    pub max_lateral_rail_jump: f32,

    /// Дистанция экстраполяции пути вперед (м), например 25.0 м
    pub extrapolate_m: f32,
    /// Окно темпорального сглаживания полинома (кадров)
    pub smooth_n: usize,

    /// Включить проверку препятствий в кинематическом габарите (Boxcast)
    pub detect_obstacles: bool,
    /// Конфигурация поиска препятствий и габарита приближения (Boxcast)
    pub obstacle_config: ObstacleConfig,
}

impl Default for RailOrtConfig {
    fn default() -> Self {
        Self {
            z_min: -2.50,
            z_max: -1.00,
            y_min: 1.50,
            y_max: 200.0,
            ring_start: 127,
            ring_end: 40,
            intensity_jump_threshold: 8.0,
            intensity_max: 0.0,
            min_point_distance: 0.01,
            nominal_gauge: 1.520,
            gauge_tolerance: 0.08,
            max_rail_height_diff: 0.12,
            max_lateral_jump: 3.0,
            max_lateral_rail_jump: 0.15,
            extrapolate_m: 50.0,
            smooth_n: 2,
            detect_obstacles: true,
            obstacle_config: ObstacleConfig::default(),
        }
    }
}

/// Точка пола тоннеля — компактное представление через индекс исходной точки в `AppPointCloud`
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct RawFloorPoint {
    pub index: usize,
}

impl RawFloorPoint {
    #[inline(always)]
    pub fn new(index: usize) -> Self {
        Self { index }
    }

    #[inline(always)]
    pub fn get_xyz(&self, cloud: &AppPointCloud, queue: ProcessingQueue) -> [f32; 3] {
        [
            cloud.x[queue][self.index],
            cloud.y[queue][self.index],
            cloud.z[queue][self.index],
        ]
    }

    #[inline(always)]
    pub fn get_xyzi(&self, cloud: &AppPointCloud, queue: ProcessingQueue) -> (f32, f32, f32, f32) {
        (
            cloud.x[queue][self.index],
            cloud.y[queue][self.index],
            cloud.z[queue][self.index],
            cloud.intensity[queue][self.index],
        )
    }

    #[inline(always)]
    pub fn ring(&self, cloud: &AppPointCloud, queue: ProcessingQueue) -> usize {
        cloud.ring[queue][self.index] as usize
    }
}

/// Результат детекции рельсов ортографическим детектором RailOrt
#[derive(Clone, Debug)]
pub struct DetectionResultOrt {
    pub frame_idx: usize,
    pub points: Vec<RailPoint>,
    pub gauge: f32,
    pub curvature_a: f32,
    pub heading_b: f32,
    pub offset_c: f32,
    pub turn_radius: f32,
    pub turn_direction: String,
    pub lateral_shift_15m: f32,
    pub poly_y: [f32; 3],
    pub poly_z: [f32; 2],
    pub x_curve: Vec<f32>,
    pub y_center: Vec<f32>,
    pub z_center: Vec<f32>,
    pub x_left: Vec<f32>,
    pub y_left: Vec<f32>,
    pub x_right: Vec<f32>,
    pub y_right: Vec<f32>,
    pub confidence: f32,
    pub extrapolate_m: f32,
    pub smooth_n: usize,
    pub x_ext: Vec<f32>,
    pub y_ext: Vec<f32>,
    pub z_ext: Vec<f32>,
    pub x_ext_l: Vec<f32>,
    pub y_ext_l: Vec<f32>,
    pub x_ext_r: Vec<f32>,
    pub y_ext_r: Vec<f32>,
    pub avg_intensity_left: f32,
    pub avg_intensity_right: f32,
    pub obstacles: Vec<TrackObstacle>,
    pub timing_rail_ms: f32,
    pub timing_obstacles_ms: f32,
    pub timing_total_ms: f32,
}

impl DetectionResultOrt {
    /// Генерирует 3D полилинии (wireframe strips) для визуализации габарита приближения пути (Boxcast)
    pub fn shapecast_wireframe_3d(&self) -> Vec<Vec<[f32; 3]>> {
        let x_min = 2.0_f32;
        let x_max = self
            .x_ext
            .last()
            .copied()
            .or_else(|| self.x_curve.last().copied())
            .unwrap_or(40.0)
            .max(x_min + 2.0);

        let step_m = 0.5_f32;
        let num_steps = ((x_max - x_min) / step_m).round().max(10.0) as usize;

        let mut line_bl = Vec::with_capacity(num_steps + 1);
        let mut line_br = Vec::with_capacity(num_steps + 1);
        let mut line_tl = Vec::with_capacity(num_steps + 1);
        let mut line_tr = Vec::with_capacity(num_steps + 1);
        let mut frames = Vec::new();

        let hoop_dist_m = 4.0_f32;
        let hoop_step = ((hoop_dist_m / step_m).round().max(1.0)) as usize;

        let clearance_width = 3.20_f32;
        let min_height_above_rail = -0.10_f32;
        let max_height_above_rail = 2.40_f32;
        let half_w = clearance_width * 0.5;

        for i in 0..=num_steps {
            let t = (i as f32) / (num_steps as f32);
            let x = x_min + t * (x_max - x_min);

            let y_c = self.poly_y[0] * x * x + self.poly_y[1] * x + self.poly_y[2];
            let z_surf = self.poly_z[0] * x + self.poly_z[1];
            let dy_dx = 2.0 * self.poly_y[0] * x + self.poly_y[1];
            let theta = dy_dx.atan();
            let sin_t = theta.sin();
            let cos_t = theta.cos();

            let xl = x + half_w * sin_t;
            let yl = y_c - half_w * cos_t;
            let xr = x - half_w * sin_t;
            let yr = y_c + half_w * cos_t;

            let zb = z_surf + min_height_above_rail;
            let zt = z_surf + max_height_above_rail;

            let p_bl = [xl, yl, zb];
            let p_br = [xr, yr, zb];
            let p_tr = [xr, yr, zt];
            let p_tl = [xl, yl, zt];

            line_bl.push(p_bl);
            line_br.push(p_br);
            line_tr.push(p_tr);
            line_tl.push(p_tl);

            if i % hoop_step == 0 || i == num_steps {
                frames.push(vec![p_bl, p_br, p_tr, p_tl, p_bl]);
                if i == 0 || i == num_steps {
                    frames.push(vec![p_bl, p_tr]);
                    frames.push(vec![p_br, p_tl]);
                }
            }
        }

        let mut strips = Vec::with_capacity(4 + frames.len());
        strips.push(line_bl);
        strips.push(line_br);
        strips.push(line_tl);
        strips.push(line_tr);
        strips.extend(frames);
        strips
    }

    /// Возвращает цвет RGB для шейпкаста: Красный при критическом препятствии,
    /// Янтарный при препятствии в габарите, Бирюзовый при чистом пути.
    pub fn shapecast_color(&self) -> [u8; 3] {
        let num_crit = self.obstacles.iter().filter(|o| o.is_critical).count();
        let num_warn = self.obstacles.len() - num_crit;
        if num_crit > 0 {
            [255, 30, 30] // Alert Red
        } else if num_warn > 0 {
            [255, 170, 0] // Warning Amber
        } else {
            [0, 220, 220] // Calm Cyan / Clear
        }
    }
}

/// Ортографический детектор рельсов по кольцам лидара и отражающей способности
pub struct RailOrtDetector {
    pub config: RailOrtConfig,
    pub geometry: LidarGeometry,
    pub history: VecDeque<DetectionHistoryItem>,
    pub last_frame_idx: Option<usize>,
    internal_obstacle_detector: RailTrackDetector,
}

impl RailOrtDetector {
    pub fn new(geometry: LidarGeometry, config: RailOrtConfig) -> Self {
        let internal_obstacle_detector = RailTrackDetector::new(geometry.clone());
        Self {
            config,
            geometry,
            history: VecDeque::new(),
            last_frame_idx: None,
            internal_obstacle_detector,
        }
    }

    /// Сброс истории темпорального сглаживания
    pub fn reset(&mut self) {
        self.history.clear();
        self.last_frame_idx = None;
        self.internal_obstacle_detector.reset();
    }

    /// Обрезка тоннеля с группировкой по кольцам (128 колец) и фильтрацией коллизий
    pub fn crop_tunnel_rings(
        &self,
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
    ) -> Vec<Vec<RawFloorPoint>> {
        let total_pts = cloud.len(queue);
        if total_pts == 0 {
            return vec![Vec::new(); 128];
        }

        let mut rings: Vec<Vec<RawFloorPoint>> = vec![Vec::new(); 128];

        // Фильтрация коллизий: если min_point_distance > 0.0, отсекаем точки на одном кольце,
        // расстояние между которыми меньше заданного порога (например, 1 см или 5 см).
        let min_dist = self.config.min_point_distance;
        let min_dist_sq = min_dist * min_dist;

        let mut last_pos: Option<(f32, f32, f32)> = None;

        for (i, (&x, &y, &z, _, &ring_u16)) in cloud.iter(queue).enumerate() {
            if i >= total_pts {
                break;
            }
            if is_zero_point(x, y, z) {
                continue;
            }

            if z >= self.config.z_min
                && z <= self.config.z_max
                && y.abs() >= self.config.y_min
                && y.abs() <= self.config.y_max
            {
                if let Some((lx, ly, lz)) = last_pos {
                    let dx = x - lx;
                    let dy = y - ly;
                    let dz = z - lz;
                    if dx * dx + dy * dy + dz * dz < min_dist_sq {
                        // Коллизия точек — пропускаем дублирующуюся / слишком близкую точку
                        continue;
                    }
                }
                last_pos = Some((x, y, z));

                let r = (ring_u16 as usize).min(127);
                rings[r].push(RawFloorPoint { index: i });
            }
        }

        rings
    }

    /// Детекция рельсов по облаку точек AppPointCloud
    pub fn detect_rails(
        &mut self,
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
        frame_idx: usize,
    ) -> Option<DetectionResultOrt> {
        let mut rings = self.crop_tunnel_rings(cloud, queue);
        self.process_rings(&mut rings, cloud, queue, frame_idx, None)
    }

    /// Алиас детекции для обратной совместимости (вызывает `detect_rails`)
    #[inline(always)]
    pub fn detect_from_cloud(
        &mut self,
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
        frame_idx: usize,
    ) -> Option<DetectionResultOrt> {
        self.detect_rails(cloud, queue, frame_idx)
    }

    /// Основной алгоритм:
    /// 2. Идем от ring_start (ближнего к поезду) к ring_end, ищем резкие скачки отражающей способности
    /// 3. Отбираем кандидатов по паттерну: колея, одна высота, lateral jump — сохраняем в пулл лучших точек
    /// 4. Повторяем до ring_end
    /// 5. Строим прямые/полиномы и Boxcast габарита
    pub fn process_rings(
        &mut self,
        rings: &mut Vec<Vec<RawFloorPoint>>,
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
        frame_idx: usize,
        obs_frame: Option<&RangeImage>,
    ) -> Option<DetectionResultOrt> {
        let t_start_rail = Instant::now();

        // Проверка непрерывности истории
        if let Some(last_idx) = self.last_frame_idx {
            if frame_idx > last_idx + 4 {
                self.history.clear();
            }
        }
        self.last_frame_idx = Some(frame_idx);

        let max_ring_avail = rings.len().saturating_sub(1);
        let row_start = self.config.ring_start.min(max_ring_avail);
        let row_end = self.config.ring_end.min(row_start);

        let mut best_points_pool: Vec<RailPoint> = Vec::new();
        let mut prev_x_center: Option<f32> = None;
        let mut prev_x_left: Option<f32> = None;
        let mut prev_x_right: Option<f32> = None;
        let mut last_detected_ring: Option<usize> = None;

        let g_min = self.config.nominal_gauge - self.config.gauge_tolerance;
        let g_max = self.config.nominal_gauge + self.config.gauge_tolerance;
        let threshold = self.config.intensity_jump_threshold;
        let max_int = self.config.intensity_max;

        // Прямые ссылки на срезы SoA буферов лидара в регистрах CPU
        let xs = &cloud.x[queue];
        let ys = &cloud.y[queue];
        let zs = &cloud.z[queue];
        let ints = &cloud.intensity[queue];

        for (rev_offset, pts) in rings[row_end..=row_start].iter_mut().rev().enumerate() {
            let ring = row_start - rev_offset;
            let n = pts.len();
            if n < 2 {
                continue;
            }

            // Сортировка слева направо: X- (право) -> X+ (лево)
            pts.sort_unstable_by(|a, b|
                xs[a.index].total_cmp(&xs[b.index]));

            let ring_gap = if let Some(lr) = last_detected_ring {
                lr.abs_diff(ring) as f32
            } else {
                1.0
            };
            // На дальних кольцах шаг по расстоянию больше, расширяем коридор
            let gap_scale = 1.0 + 0.35 * (ring_gap - 1.0).max(0.0);
            let max_lat = (0.60 * gap_scale).min(1.80);
            let max_lat_rail = (0.50 * gap_scale).min(1.50);

            let mut best_pair: Option<RailPoint> = None;
            let mut best_score = f32::INFINITY;

            // 1. Первая точка pl — правый рельс (X < 0)
            for (i, pr) in pts.iter().enumerate() {
                let idx_r = pr.index;
                let xr = xs[idx_r];

                if let Some(pxl) = prev_x_right {
                    if (xr - pxl).abs() > max_lat_rail {
                        continue;
                    }
                } else if xr < -1.40 || xr > -0.15 {
                    // На первом кольце правый рельс в диапазоне [-1.40 .. -0.15]
                    continue;
                }

                let int_r = ints[idx_r];
                if max_int > 0.0 && int_r > max_int {
                    continue;
                }

                let yr = ys[idx_r];
                let zr = zs[idx_r];

                // 2. Вторая точка pr — левый рельс (X > 0, правее в отсортированном массиве)
                for (j_offset, pr) in pts[i + 1..].iter().enumerate() {
                    let j = i + 1 + j_offset;
                    let idx_l = pr.index;
                    let xl = xs[idx_l];
                    let dx = xl - xr; // xr > xl, строго положительная разность

                    if dx < g_min - 0.15 {
                        continue;
                    }
                    if dx > g_max + 0.15 {
                        break;
                    }

                    if let Some(pxl) = prev_x_left {
                        if (xl - pxl).abs() > max_lat_rail {
                            continue;
                        }
                    } else if xl < 0.15 || xl > 1.40 {
                        // На первом кольце левый рельс в диапазоне [0.15 .. 1.40]
                        continue;
                    }

                    let int_l = ints[idx_l];
                    if max_int > 0.0 && int_l > max_int {
                        continue;
                    }

                    let zl = zs[idx_l];
                    let dz = zl - zr;
                    if dz.abs() > self.config.max_rail_height_diff {
                        continue;
                    }

                    let yl = ys[idx_l];
                    let dy = yr - yl;
                    let gauge = (dx * dx + dy * dy).sqrt();
                    if gauge < g_min || gauge > g_max {
                        continue;
                    }

                    let xm = 0.5 * (xl + xr);
                    if let Some(prev_xm) = prev_x_center {
                        if (xm - prev_xm).abs() > max_lat {
                            continue;
                        }
                    }

                    let cur_xc = -0.5 * (yr + yl); // X вперед
                    let cur_yc = xm;               // Y вбок
                    let cur_zc = 0.5 * (zr + zl);  // Z вверх

                    if let Some(prev_pt) = best_points_pool.last() {
                        let dx3d = cur_xc - prev_pt.x_center;
                        let dy3d = cur_yc - prev_pt.y_center;
                        let dz3d = cur_zc - prev_pt.z_center;

                        let max_dist = self.config.max_lateral_jump * gap_scale;
                        if dx3d * dx3d + dy3d * dy3d + dz3d * dz3d > max_dist * max_dist {
                            continue; // Слишком резкий скачок — кандидат отбрасывается!
                        }
                    }

                    // Скоринг: точная геометрия колеи + непрерывность
                    let gauge_err = (gauge - self.config.nominal_gauge).abs();
                    let continuity_err = if let Some(prev_xm) = prev_x_center {
                        (xm - prev_xm).abs()
                    } else {
                        0.0
                    };

                    // Зеркальная головка рельса: чем ниже интенсивность, тем лучше
                    let intensity_score = (int_l + int_r) * 0.03;

                    // УБРАН штраф за xm.abs(), теперь поворот не штрафуется!
                    let score = gauge_err * 3.5
                        + continuity_err * 2.5
                        + dz.abs() * 1.5
                        + intensity_score;

                    if score < best_score {
                        best_score = score;

                        // Перевод в СК поезда/Rerun:
                        // X = вперед (-y), Y = вбок (+x), Z = высота (+z)
                        best_pair = Some(RailPoint {
                            row: ring,
                            col_left: 0,
                            col_right: 0,
                            x_left: -yl,
                            y_left: xl,
                            z_left: zl,
                            x_right: -yr,
                            y_right: xr,
                            z_right: zr,
                            x_center: -0.5 * (yl + yr),
                            y_center: xm,
                            z_center: 0.5 * (zl + zr),
                            gauge,
                            intensity_left: int_l,
                            intensity_right: int_r,
                        });
                    }
                }
            }

            if let Some(ref pair) = best_pair {
                // Запоминаем X сенсора (в pair.y_* записан X сенсора xl, xr, xm)
                prev_x_center = Some(pair.y_center);
                prev_x_left   = Some(pair.y_left);
                prev_x_right  = Some(pair.y_right);
                last_detected_ring = Some(ring);
                best_points_pool.push(pair.clone());
            }
        }

        if best_points_pool.len() < 4 {
            return None;
        }

        if best_points_pool.len() < 4 {
            return None;
        }

        // 5. Строим прямые/полиномы: Y(X) - боковое смещение от расстояния вперед, Z(X) - уклон от расстояния вперед
        let xm: Vec<f32> = best_points_pool.iter().map(|p| p.x_center).collect();
        let ym: Vec<f32> = best_points_pool.iter().map(|p| p.y_center).collect();
        let zm: Vec<f32> = best_points_pool.iter().map(|p| p.z_center).collect();

        // ПРАВИЛЬНО: аргумент X (дистанция вперед), целевая функция Y (смещение влево/вправо):
        let raw_poly_y = polyfit2(&xm, &ym).unwrap_or([0.0, 0.0, 0.0]);
        let raw_poly_z = polyfit1(&xm, &zm).unwrap_or([0.0, zm.first().copied().unwrap_or(0.0)]);

        let mut sorted_gauges: Vec<f32> = best_points_pool.iter().map(|p| p.gauge).collect();
        sorted_gauges.sort_by(|a, b| a.partial_cmp(b).unwrap());
        let median_gauge = sorted_gauges[sorted_gauges.len() / 2];
        let x_det_max = xm.iter().cloned().fold(f32::NEG_INFINITY, f32::max);

        // Темпоральное взвешенное сглаживание
        self.history.push_back(DetectionHistoryItem {
            poly_y: raw_poly_y,
            poly_z: raw_poly_z,
            gauge: median_gauge,
            x_det_max,
        });
        while self.history.len() > self.config.smooth_n.max(1) {
            self.history.pop_front();
        }

        let (poly_y, poly_z, median_gauge, smooth_det_max) = {
            let mut sum_y = [0.0f64; 3];
            let mut sum_z = [0.0f64; 2];
            let mut sum_gauge = 0.0f64;
            let mut sum_xmax = 0.0f64;
            let mut total_w = 0.0f64;

            for (i, item) in self.history.iter().enumerate() {
                let w = (i + 1) as f64;
                total_w += w;
                sum_y[0] += item.poly_y[0] as f64 * w;
                sum_y[1] += item.poly_y[1] as f64 * w;
                sum_y[2] += item.poly_y[2] as f64 * w;
                sum_z[0] += item.poly_z[0] as f64 * w;
                sum_z[1] += item.poly_z[1] as f64 * w;
                sum_gauge += item.gauge as f64 * w;
                sum_xmax += item.x_det_max as f64 * w;
            }

            let inv_w = 1.0 / total_w;
            (
                [
                    (sum_y[0] * inv_w) as f32,
                    (sum_y[1] * inv_w) as f32,
                    (sum_y[2] * inv_w) as f32,
                ],
                [(sum_z[0] * inv_w) as f32, (sum_z[1] * inv_w) as f32],
                (sum_gauge * inv_w) as f32,
                (sum_xmax * inv_w) as f32,
            )
        };

        let [a, b, c] = poly_y;
        let [d, e] = poly_z;

        let turn_radius = if a.abs() > 1e-6 {
            1.0 / (2.0 * a.abs())
        } else {
            99999.0
        };

        let lateral_shift_15m = a * (15.0 * 15.0) + b * 15.0;
        let turn_direction = if lateral_shift_15m.abs() < 0.20 && a.abs() < 0.0003 {
            "STRAIGHT".to_string()
        } else if lateral_shift_15m < 0.0 || a < 0.0 {
            "CURVE LEFT".to_string()
        } else {
            "CURVE RIGHT".to_string()
        };

        // Ресемплинг аналитических 3D линий путей
        let xm_min = xm.iter().cloned().fold(f32::INFINITY, f32::min);
        let x_min = 2.0_f32.max(xm_min);
        let x_max = smooth_det_max.max(x_min + 1.0);

        let n_resample = 100;
        let mut x_curve = Vec::with_capacity(n_resample);
        let mut y_center = Vec::with_capacity(n_resample);
        let mut z_center = Vec::with_capacity(n_resample);
        let mut x_left = Vec::with_capacity(n_resample);
        let mut y_left = Vec::with_capacity(n_resample);
        let mut x_right = Vec::with_capacity(n_resample);
        let mut y_right = Vec::with_capacity(n_resample);

        let half_w = 0.5 * median_gauge;

        for i in 0..n_resample {
            let t = i as f32 / (n_resample - 1) as f32;
            let xi = x_min + t * (x_max - x_min);
            let yi = a * xi * xi + b * xi + c;
            let zi = d * xi + e;

            let theta_poly = (2.0 * a * xi + b).atan();
            let sin_t = theta_poly.sin();
            let cos_t = theta_poly.cos();

            x_curve.push(xi);
            y_center.push(yi);
            z_center.push(zi);

            x_left.push(xi + half_w * sin_t);
            y_left.push(yi - half_w * cos_t);

            x_right.push(xi - half_w * sin_t);
            y_right.push(yi + half_w * cos_t);
        }

        // Экстраполяция полинома вперед на M метров
        let mut x_ext = Vec::new();
        let mut y_ext = Vec::new();
        let mut z_ext = Vec::new();
        let mut x_ext_l = Vec::new();
        let mut y_ext_l = Vec::new();
        let mut x_ext_r = Vec::new();
        let mut y_ext_r = Vec::new();

        if self.config.extrapolate_m > 0.0 {
            let n_ext = 50;
            let x_ext_end = x_max + self.config.extrapolate_m;
            for i in 0..n_ext {
                let t = i as f32 / (n_ext - 1) as f32;
                let xe = x_max + t * (x_ext_end - x_max);
                let ye = a * xe * xe + b * xe + c;
                let ze = d * xe + e;

                let theta_poly = (2.0 * a * xe + b).atan();
                let sin_t = theta_poly.sin();
                let cos_t = theta_poly.cos();

                x_ext.push(xe);
                y_ext.push(ye);
                z_ext.push(ze);

                x_ext_l.push(xe + half_w * sin_t);
                y_ext_l.push(ye - half_w * cos_t);

                x_ext_r.push(xe - half_w * sin_t);
                y_ext_r.push(ye + half_w * cos_t);
            }
        }

        let total_checked_rings = (row_start.abs_diff(row_end) + 1) as f32;
        let confidence = (best_points_pool.len() as f32 / total_checked_rings).min(1.0);

        let (avg_i_l, avg_i_r) = if !best_points_pool.is_empty() {
            let n = best_points_pool.len() as f32;
            (
                best_points_pool.iter().map(|p| p.intensity_left).sum::<f32>() / n,
                best_points_pool.iter().map(|p| p.intensity_right).sum::<f32>() / n,
            )
        } else {
            (0.0, 0.0)
        };

        let t_rail_dur = t_start_rail.elapsed();

        // Поиск препятствий и проверка кинематического габарита (Boxcast)
        let t_start_obs = Instant::now();
        let obstacles = if self.config.detect_obstacles && self.config.obstacle_config.enabled {
            if let Some(frame) = obs_frame {
                self.internal_obstacle_detector.detect_obstacles(
                    frame,
                    Some((cloud, queue)),
                    &poly_y,
                    &poly_z,
                    median_gauge,
                    &self.config.obstacle_config,
                    false,
                )
            } else {
                // Прямой Boxcast по точкам AppPointCloud
                detect_obstacles_direct(
                    cloud,
                    queue,
                    &poly_y,
                    &poly_z,
                    median_gauge,
                    &self.config.obstacle_config,
                )
            }
        } else {
            Vec::new()
        };
        let t_obs_dur = t_start_obs.elapsed();

        let timing_rail_ms = t_rail_dur.as_secs_f32() * 1000.0;
        let timing_obstacles_ms = t_obs_dur.as_secs_f32() * 1000.0;
        let timing_total_ms = timing_rail_ms + timing_obstacles_ms;

        Some(DetectionResultOrt {
            frame_idx,
            points: best_points_pool,
            gauge: median_gauge,
            curvature_a: a,
            heading_b: b,
            offset_c: c,
            turn_radius,
            turn_direction,
            lateral_shift_15m,
            poly_y,
            poly_z,
            x_curve,
            y_center,
            z_center,
            x_left,
            y_left,
            x_right,
            y_right,
            confidence,
            extrapolate_m: self.config.extrapolate_m,
            smooth_n: self.history.len(),
            x_ext,
            y_ext,
            z_ext,
            x_ext_l,
            y_ext_l,
            x_ext_r,
            y_ext_r,
            avg_intensity_left: avg_i_l,
            avg_intensity_right: avg_i_r,
            obstacles,
            timing_rail_ms,
            timing_obstacles_ms,
            timing_total_ms,
        })
    }
}

/// Прямой Boxcast габарита приближения по облаку точек AppPointCloud
fn detect_obstacles_direct(
    pc: &AppPointCloud,
    queue: ProcessingQueue,
    poly_y: &[f32; 3],
    poly_z: &[f32; 2],
    gauge: f32,
    cfg: &ObstacleConfig,
) -> Vec<TrackObstacle> {
    let [a, b, c] = *poly_y;
    let [d, e] = *poly_z;

    let half_gauge = gauge * 0.5;
    let danger_half_w = half_gauge + 0.15;
    let clearance_half_w = cfg.clearance_width * 0.5;

    let total = pc.len(queue);
    let mut count_crit = 0usize;
    let mut count_warn = 0usize;
    let mut min_dist = f32::INFINITY;

    for (i, (&x, &y, &z, _, _)) in pc.iter(queue).enumerate() {
        if i >= total {
            break;
        }
        if x < 2.0 || x > cfg.max_distance_m || is_zero_point(x, y, z) {
            continue;
        }

        let y_track = a * x * x + b * x + c;
        let z_track = d * x + e;

        let dy = (y - y_track).abs();
        let dz = z - z_track;

        if dz >= cfg.min_height_above_rail && dz <= cfg.max_height_above_rail {
            if dy <= clearance_half_w {
                let is_critical = dy <= danger_half_w;
                if is_critical {
                    count_crit += 1;
                } else {
                    count_warn += 1;
                }
                if x < min_dist {
                    min_dist = x;
                }
            }
        }
    }

    let mut obstacles = Vec::new();
    if count_crit > 0 || count_warn > 0 {
        let is_crit = count_crit > 0;
        let total_pts = count_crit + count_warn;
        let obs_h = cfg.max_height_above_rail - cfg.min_height_above_rail;
        obstacles.push(TrackObstacle {
            id: 1,
            distance_along_track: min_dist,
            lateral_offset: 0.0,
            height_above_rail: 0.5,
            bbox_3d_min: [min_dist, -clearance_half_w, 0.0],
            bbox_3d_max: [min_dist + 1.0, clearance_half_w, obs_h],
            bbox_2d: [0, 0, 10, 10],
            points_count: total_pts,
            is_critical: is_crit,
            size_m: [1.0, clearance_half_w * 2.0, obs_h],
        });
    }

    obstacles
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
