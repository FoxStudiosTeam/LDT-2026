//! rail_ort.rs — Orthographic / Slice-based Railway Track Detection for 3D LiDAR
//!
//! Физическая модель железнодорожного пути:
//! 1. Рельсовое полотно — это жесткая параллельная конструкция с фиксированной колеей 1520 мм (номинал 1.520 м).
//! 2. Левый и правый рельсы жестко связаны с осью пути:
//!    X_left(y)  = X_center(y) + half_gauge
//!    X_right(y) = X_center(y) - half_gauge
//!    Оба рельса поворачивают синхронно с единым наклоном оси пути: dX/dY = slope_c.
//! 3. На первом срезе под кабиной поезд физически стоит на путях:
//!    X_center находится в узком коридоре пола [-0.60 .. +0.60] м.
//! 4. От первого среза алгоритм шагает вперед по срезам:
//!    - Предикшн положения: X_pred = X_prev + slope_c * dY
//!    - Жесткий коридор отклонения рельсов (max_lateral_rail_jump) вокруг предсказанной траектории.
//!    - Приоритет минимальной интенсивности (головка рельса зеркалит луч, I ~ 0).
//!    - Фильтр минимального шага min_longitudinal_jump исключает дубликаты.
//!    - Плавный уклон по высоте Z.

use std::collections::VecDeque;
use std::time::Instant;

use crate::rail_detection::{
    DetectionHistoryItem, DetectionResult, LidarGeometry, ObstacleConfig, ObstacleDetectionMode,
    RailPoint, RailTrackDetector, TrackObstacle,
};
use crate::range_image::RangeImage;
use crate::types::{AppPointCloud, ProcessingQueue, is_zero_point};

/// Конфигурация ортографического детектора путей (RailOrt)
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

    /// Стартовое кольцо лидара (для совместимости)
    pub ring_start: usize,
    /// Конечное кольцо лидара (для совместимости)
    pub ring_end: usize,

    /// Порог резкого скачка по отражающей способности (|Delta I|) для поиска кандидатов
    pub intensity_jump_threshold: f32,
    /// Максимальная интенсивность точки рельса (0 = не ограничивать)
    pub intensity_max: f32,

    /// Номинальный скачёк по высоте для рельс
    pub nominal_height_jump: f32,
    /// Допуск высоты рельс
    pub height_jump_tolerance: f32,

    /// Минимальное расстояние между точками на одном кольце/срезе для фильтрации коллизий (м)
    pub min_point_distance: f32,

    /// Номинальная ширина колеи (м), стандарт 1.520 м (1520 мм)
    pub nominal_gauge: f32,
    /// Допуск ширины колеи (м), например 0.10 м
    pub gauge_tolerance: f32,
    /// Максимальная разница по высоте между левым и правым рельсом в одном срезе (м)
    pub max_rail_height_diff: f32,

    /// Максимально допустимый скачок центра колеи между срезами по Y (м)
    pub max_lateral_jump: f32,
    /// Максимально допустимый скачок отдельного рельса относительно предсказанной линии (м)
    pub max_lateral_rail_jump: f32,
    /// Максимальный допустимый шаг между последовательными парами по Y (м)
    pub max_longitudinal_jump: f32,
    /// Минимальный допустимый шаг между парами по Y (м) для исключения скучивания точек
    pub min_longitudinal_jump: f32,

    /// Минимальная продольная протяженность найденного пути (м) для отсечения шума (0 = выключено)
    pub min_track_length_m: f32,

    /// Дистанция экстраполяции пути вперед (м), например 30.0 м
    pub extrapolate_m: f32,
    /// Окно темпорального сглаживания полинома (кадров)
    pub smooth_n: usize,

    /// Включить проверку препятствий в кинематическом габарите (Boxcast)
    pub detect_obstacles: bool,
    /// Конфигурация поиска препятствий и габарита приближения (Boxcast)
    pub obstacle_config: ObstacleConfig,

    pub intensity_score: f32,
    pub gauge_err_score: f32,
    pub delta_z_score: f32,
    pub continuity_score: f32,
}

impl Default for RailOrtConfig {
    fn default() -> Self {
        Self {
            z_min: -12.00,
            z_max: -1.00,
            y_min: 2.00,
            y_max: 50.0,
            ring_start: 127,
            ring_end: 40,
            intensity_jump_threshold: 1.00,
            intensity_max: 2.5,
            nominal_height_jump: 0.44,
            height_jump_tolerance: 0.46,
            min_point_distance: 0.030,
            min_track_length_m: 0.000,
            nominal_gauge: 1.520,
            gauge_tolerance: 0.100,
            max_rail_height_diff: 0.100,
            max_lateral_jump: 1.00,
            max_lateral_rail_jump: 0.050,
            max_longitudinal_jump: 4.50,
            min_longitudinal_jump: 0.000,
            extrapolate_m: 40.0,
            smooth_n: 6,
            detect_obstacles: true,
            intensity_score: 1.20,
            gauge_err_score: 3.30,
            delta_z_score: 4.00,
            continuity_score: 2.40,
            obstacle_config: ObstacleConfig {
                enabled: true,
                mode: ObstacleDetectionMode::Boxcast3D,
                clearance_width: 2.20,
                clearance_narrowing_width: 0.6000,
                clearance_narrowing_height: 0.3000,
                min_height_above_rail: 0.20,
                max_height_above_rail: 3.10,
                min_points: 6,
                max_distance_m: 60.0,
                depth_diff_thresh: 0.25,
                upward_curvature: 0.00040,
                cluster_depth_thresh: 0.80,
                ..ObstacleConfig::default()
            },
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
    pub poly_y: [f32; 3], // Полином бокового смещения X(Y) = a*Y^2 + b*Y + c
    pub poly_z: [f32; 2], // Полином высоты Z(Y) = d*Y + e
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
    pub clearance_width: f32,
    pub min_height_above_rail: f32,
    pub max_height_above_rail: f32,
    pub timing_rail_ms: f32,
    pub timing_obstacles_ms: f32,
    pub timing_total_ms: f32,
}

impl DetectionResultOrt {
    /// Генерирует 3D полилинии (wireframe strips) для визуализации габарита приближения пути (Boxcast)
    pub fn shapecast_wireframe_3d(&self) -> Vec<Vec<[f32; 3]>> {
        let y_start = self.y_center.first().copied().unwrap_or(-2.0);
        let y_end = self
            .y_ext
            .last()
            .copied()
            .or_else(|| self.y_center.last().copied())
            .unwrap_or(-40.0);

        let step_m = 0.5_f32;
        let total_dist = (y_end - y_start).abs();
        let num_steps = ((total_dist / step_m).round().max(10.0)) as usize;

        let mut line_bl = Vec::with_capacity(num_steps + 1);
        let mut line_br = Vec::with_capacity(num_steps + 1);
        let mut line_tl = Vec::with_capacity(num_steps + 1);
        let mut line_tr = Vec::with_capacity(num_steps + 1);
        let mut frames = Vec::new();

        let hoop_dist_m = 4.0_f32;
        let hoop_step = ((hoop_dist_m / step_m).round().max(1.0)) as usize;

        let clearance_width = if self.clearance_width > 0.0 {
            self.clearance_width
        } else {
            2.10
        };
        let min_height_above_rail = self.min_height_above_rail;
        let max_height_above_rail = if self.max_height_above_rail > self.min_height_above_rail {
            self.max_height_above_rail
        } else {
            3.00
        };
        let half_w = clearance_width * 0.5;

        for i in 0..=num_steps {
            let t = (i as f32) / (num_steps as f32);
            let y = y_start + t * (y_end - y_start);

            let x_c = self.poly_y[0] * y * y + self.poly_y[1] * y + self.poly_y[2];
            let z_surf = self.poly_z[0] * y + self.poly_z[1];
            let dx_dy = 2.0 * self.poly_y[0] * y + self.poly_y[1];
            let theta = dx_dy.atan();
            let cos_t = theta.cos();
            let sin_t = theta.sin();

            let xl = x_c + half_w * cos_t;
            let yl = y - half_w * sin_t;
            let xr = x_c - half_w * cos_t;
            let yr = y + half_w * sin_t;

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

    /// Преобразует результат ортографического детектора в канонический DetectionResult
    /// для сквозной совместимости с 2D рендерером, Rerun стримингом и системой двойного шейпкаста.
    pub fn to_detection_result(&self, obs_cfg: &ObstacleConfig) -> DetectionResult {
        let x_curve: Vec<f32> = self.y_center.iter().map(|&y| -y).collect();
        let y_center = self.x_curve.clone();
        let z_center = self.z_center.clone();

        let x_left: Vec<f32> = self.y_left.iter().map(|&y| -y).collect();
        let y_left = self.x_left.clone();

        let x_right: Vec<f32> = self.y_right.iter().map(|&y| -y).collect();
        let y_right = self.x_right.clone();

        let x_ext: Vec<f32> = self.y_ext.iter().map(|&y| -y).collect();
        let y_ext = self.x_ext.clone();
        let z_ext = self.z_ext.clone();

        let x_ext_l: Vec<f32> = self.y_ext_l.iter().map(|&y| -y).collect();
        let y_ext_l = self.x_ext_l.clone();

        let x_ext_r: Vec<f32> = self.y_ext_r.iter().map(|&y| -y).collect();
        let y_ext_r = self.x_ext_r.clone();

        let points = self
            .points
            .iter()
            .map(|p| {
                let mut pt = p.clone();
                pt.x_left = -p.y_left;
                pt.y_left = p.x_left;
                pt.x_right = -p.y_right;
                pt.y_right = p.x_right;
                pt.x_center = -p.y_center;
                pt.y_center = p.x_center;
                pt
            })
            .collect();

        DetectionResult {
            frame_idx: self.frame_idx,
            points,
            gauge: self.gauge,
            curvature_a: self.curvature_a,
            heading_b: -self.heading_b,
            offset_c: self.offset_c,
            turn_radius: self.turn_radius,
            turn_direction: self.turn_direction.clone(),
            lateral_shift_15m: self.lateral_shift_15m,
            poly_y: [self.poly_y[0], -self.poly_y[1], self.poly_y[2]],
            poly_z: [-self.poly_z[0], self.poly_z[1]],
            x_curve,
            y_center,
            z_center,
            x_left,
            y_left,
            x_right,
            y_right,
            confidence: self.confidence,
            extrapolate_m: self.extrapolate_m,
            smooth_n: self.smooth_n,
            x_ext,
            y_ext,
            z_ext,
            x_ext_l,
            y_ext_l,
            x_ext_r,
            y_ext_r,
            has_intensity: self.avg_intensity_left > 0.0 || self.avg_intensity_right > 0.0,
            avg_intensity_left: self.avg_intensity_left,
            avg_intensity_right: self.avg_intensity_right,
            obstacles: self.obstacles.clone(),
            clearance_width: obs_cfg.clearance_width,
            min_height_above_rail: obs_cfg.min_height_above_rail,
            max_height_above_rail: obs_cfg.max_height_above_rail,
            max_distance_m: obs_cfg.max_distance_m,
            upward_curvature: obs_cfg.upward_curvature,
            clearance_narrowing_width: obs_cfg.clearance_narrowing_width,
            clearance_narrowing_height: obs_cfg.clearance_narrowing_height,
            clearance_height_end_shift: obs_cfg.clearance_height_end_shift,
            clearance_start_offset: obs_cfg.clearance_start_offset,
            obstacle_enabled: obs_cfg.enabled,
            shapecast2_enabled: obs_cfg.shapecast2_enabled,
            clearance_width_2: obs_cfg.clearance_width_2,
            min_height_above_rail_2: obs_cfg.min_height_above_rail_2,
            max_height_above_rail_2: obs_cfg.max_height_above_rail_2,
            max_distance_m_2: obs_cfg.max_distance_m_2,
            upward_curvature_2: obs_cfg.upward_curvature_2,
            clearance_narrowing_width_2: obs_cfg.clearance_narrowing_width_2,
            clearance_narrowing_height_2: obs_cfg.clearance_narrowing_height_2,
            clearance_height_end_shift_2: obs_cfg.clearance_height_end_shift_2,
            clearance_start_offset_2: obs_cfg.clearance_start_offset_2,
            is_real_coordinates: true,
            is_coasting: false,
            outlier_streak: 0,
            far_anchor_active: false,
            timing_rail_ms: self.timing_rail_ms,
            timing_obstacles_ms: self.timing_obstacles_ms,
            timing_total_ms: self.timing_total_ms,
        }
    }
}

/// Ортографический детектор путей по продольным 10-см срезам (slices)
pub struct RailOrtDetector {
    pub config: RailOrtConfig,
    pub geometry: LidarGeometry,
    pub history: VecDeque<DetectionHistoryItem>,
    pub internal_obstacle_detector: RailTrackDetector,
}

impl RailOrtDetector {
    pub fn new(geometry: LidarGeometry, config: RailOrtConfig) -> Self {
        let mut internal_obstacle_detector = RailTrackDetector::new(geometry.clone());
        internal_obstacle_detector.obstacle_config = config.obstacle_config.clone();
        Self {
            config,
            geometry,
            history: VecDeque::new(),
            internal_obstacle_detector,
        }
    }

    pub fn reset(&mut self) {
        self.history.clear();
    }

    /// 1. Пространственная нарезка облака лидара на 10-см срезы по координате Y (дистанция вперед)
    /// Формула индекса: slice_idx = (-y * 10.0).round()
    pub fn crop_tunnel_slices(
        &self,
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
    ) -> Vec<Vec<RawFloorPoint>> {
        let num_slices = ((self.config.y_max * 10.0).ceil() as usize).max(100) + 1;
        let mut slices: Vec<Vec<RawFloorPoint>> = vec![Vec::new(); num_slices];
        let total_pts = cloud.len(queue);

        for (i, (&_x, &y, &z, &int, _)) in cloud.iter(queue).enumerate() {
            if i >= total_pts {
                break;
            }

            let dist_fwd = -y;
            if dist_fwd < self.config.y_min || dist_fwd > self.config.y_max {
                continue;
            }

            if z < self.config.z_min || z > self.config.z_max {
                continue;
            }

            if self.config.intensity_max > 0.0 && int.abs() > self.config.intensity_max {
                continue;
            }

            let slice_idx = (dist_fwd * 10.0).round() as usize;
            if slice_idx < num_slices {
                slices[slice_idx].push(RawFloorPoint::new(i));
            }
        }

        slices
    }

    /// Алиас для обратной совместимости вызовов
    #[inline(always)]
    pub fn crop_tunnel_rings(
        &self,
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
    ) -> Vec<Vec<RawFloorPoint>> {
        self.crop_tunnel_slices(cloud, queue)
    }

    /// Основной алгоритм детекции рельсов:
    /// Идем от ближних к дальним 10-см срезам (от поезда вглубь тоннеля)
    pub fn process_slices(
        &mut self,
        slices: &mut [Vec<RawFloorPoint>],
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
        frame_idx: usize,
        _obs_frame: Option<&RangeImage>,
    ) -> Option<DetectionResultOrt> {
        let t_start_rail = Instant::now();

        if slices.is_empty() {
            return None;
        }

        let max_slice_avail = slices.len().saturating_sub(1);
        let start_slice = ((self.config.y_min * 10.0).round() as usize).min(max_slice_avail);
        let end_slice = ((self.config.y_max * 10.0).round() as usize).min(max_slice_avail);

        let mut best_points_pool: Vec<RailPoint> = Vec::new();

        let g_nom = self.config.nominal_gauge;
        let g_tol = self.config.gauge_tolerance;
        let half_g = g_nom * 0.5;
        let max_lat_rail = self.config.max_lateral_rail_jump;
        let max_lon_jump = self.config.max_longitudinal_jump;
        let min_lon_jump = self.config.min_longitudinal_jump;
        let max_rail_height_diff = self.config.max_rail_height_diff;

        let xs = &cloud.x[queue];
        let ys = &cloud.y[queue];
        let zs = &cloud.z[queue];
        let ints = &cloud.intensity[queue];

        let slice_iter = start_slice..=end_slice;

        // Единый устойчивый наклон траектории пути: dX/dY и dZ/dY
        let mut track_slope_c = 0.0_f32;
        let mut track_slope_z = 0.0_f32;

        for slice_idx in slice_iter {
            let pts = &mut slices[slice_idx];
            if pts.len() < 2 {
                continue;
            }

            // 1. Сортируем точки среза строго по X слева направо (от X- справа к X+ слева)
            pts.sort_unstable_by(|a, b| xs[a.index].total_cmp(&xs[b.index]));

            let last_pt = best_points_pool.last().cloned();

            let mut best_pair: Option<RailPoint> = None;
            let mut best_score = f32::INFINITY;

            // 2. Внешний цикл: ищем правый рельс pr (X- = справа)
            for (i, pr) in pts.iter().enumerate() {
                let idx_r = pr.index;
                let xr = xs[idx_r];
                let yr = ys[idx_r];
                let zr = zs[idx_r];
                let int_r = ints[idx_r];

                let dy = if let Some(ref lp) = last_pt {
                    yr - lp.y_center
                } else {
                    0.0
                };
                let abs_dy = dy.abs();

                // Проверка продольного шага:
                if let Some(ref _lp) = last_pt {
                    if min_lon_jump > 0.0 && abs_dy < min_lon_jump {
                        continue;
                    }
                    if max_lon_jump > 0.0 && abs_dy > max_lon_jump {
                        continue;
                    }
                }

                // Предикшн положения рельсов от центра пути:
                // X_c(y) = lp.x_center + slope * dy
                // X_right = X_c - half_gauge, X_left = X_c + half_gauge
                let (pred_xr, pred_xl, pred_xc, pred_zc, allowed_lat) =
                    if let Some(ref lp) = last_pt {
                        let xc = lp.x_center + track_slope_c * dy;
                        let zc = lp.z_center + track_slope_z * dy;
                        let allowed = max_lat_rail + 0.08 * abs_dy;
                        (xc - half_g, xc + half_g, xc, zc, allowed)
                    } else {
                        // Под кабиной ось поезда в коридоре [-0.60 .. +0.60] м
                        (0.0 - half_g, 0.0 + half_g, 0.0, zr, 0.50)
                    };

                // Отклонение правого рельса от предсказанной линии
                if (xr - pred_xr).abs() > allowed_lat {
                    continue;
                }

                // Внутренний диапазон по X для левого рельса:
                // Он обязан находиться на расстоянии nominal_gauge +- tolerance от xr!
                let target_min_xl = xr + (g_nom - g_tol);
                let target_max_xl = xr + (g_nom + g_tol);

                // 3. Внутренний цикл: ищем левый рельс pl
                for pl in &pts[i + 1..] {
                    let idx_l = pl.index;
                    let xl = xs[idx_l];

                    if xl < target_min_xl {
                        continue;
                    }
                    if xl > target_max_xl {
                        // Точки отсортированы по X — дальше искать бессмысленно!
                        break;
                    }

                    // Отклонение левого рельса от предсказанной линии полотна
                    if (xl - pred_xl).abs() > allowed_lat {
                        continue;
                    }

                    let yl = ys[idx_l];
                    let zl = zs[idx_l];
                    let int_l = ints[idx_l];

                    // Перепад высот между рельсами в одном срезе
                    let dz = zl - zr;
                    if dz.abs() > max_rail_height_diff {
                        continue;
                    }

                    let xm = 0.5 * (xl + xr);
                    let ym = 0.5 * (yl + yr);
                    let zm = 0.5 * (zl + zr);

                    // Проверка центра пути под кабиной на первом шаге
                    if last_pt.is_none() && (xm < -0.60 || xm > 0.60) {
                        continue;
                    }

                    // Ограничение изменения центра пути и уклона Z
                    if last_pt.is_some() {
                        if (xm - pred_xc).abs() > (self.config.max_lateral_jump + 0.08 * abs_dy) {
                            continue;
                        }
                        let max_allowed_dz = 0.08 + (track_slope_z * dy).abs() + 0.05 * abs_dy;
                        if (zm - pred_zc).abs() > max_allowed_dz {
                            continue;
                        }
                    }

                    let current_gauge = xl - xr;
                    let gauge_err = (current_gauge - g_nom).abs();
                    if gauge_err > g_tol {
                        continue;
                    }

                    // Скоринг пары:
                    // 1. Интенсивность около 0 (рельсы минимально диффузят)
                    let intensity_cost = (int_l.abs() + int_r.abs()) * self.config.intensity_score;

                    // 2. Отклонение ширины колеи от 1.520 м
                    let gauge_cost = gauge_err * self.config.gauge_err_score;

                    // 3. Непрерывность смещения центров и рельсов
                    let continuity_cost =
                        ((xm - pred_xc).abs() + (xr - pred_xr).abs() + (xl - pred_xl).abs())
                            * self.config.continuity_score;

                    // 4. Перепад по высоте
                    let dz_cost = dz.abs() * self.config.delta_z_score;

                    let jump_pen = (xm - pred_xc).abs() * self.config.continuity_score * 0.4
                        + (zm - pred_zc).abs() * self.config.continuity_score * 0.4;

                    let score = intensity_cost + gauge_cost + continuity_cost + dz_cost - jump_pen;

                    if score < best_score {
                        best_score = score;
                        best_pair = Some(RailPoint {
                            row: slice_idx,
                            col_left: 0,
                            col_right: 0,
                            x_left: xl,
                            y_left: yl,
                            z_left: zl,
                            x_right: xr,
                            y_right: yr,
                            z_right: zr,
                            x_center: xm,
                            y_center: ym,
                            z_center: zm,
                            gauge: current_gauge,
                            intensity_left: int_l,
                            intensity_right: int_r,
                        });
                    }
                }
            }

            // Если на данном срезе найдена пара рельсов
            if let Some(pair) = best_pair {
                // Обновляем единый наклон оси пути dX/dY и dZ/dY
                if let Some(ref lp) = last_pt {
                    let dy = pair.y_center - lp.y_center;
                    if dy.abs() > 0.15 {
                        // Оцениваем мгновенный наклон и ограничиваем физическим максимумом кривых метро
                        let raw_slope_c = ((pair.x_center - lp.x_center) / dy).clamp(-0.25, 0.25);
                        let raw_slope_z = ((pair.z_center - lp.z_center) / dy).clamp(-0.15, 0.15);

                        // Мягкое экспоненциальное сглаживание (EMA) для подавления численного шума
                        track_slope_c = 0.80 * track_slope_c + 0.20 * raw_slope_c;
                        track_slope_z = 0.80 * track_slope_z + 0.20 * raw_slope_z;
                    }
                }

                best_points_pool.push(pair);
            }
        }

        if best_points_pool.len() < 4 {
            return None;
        }

        // 4. Строим полиномы: X(Y) - боковое смещение, Z(Y) - уклон
        let xm: Vec<f32> = best_points_pool.iter().map(|p| p.x_center).collect();
        let ym: Vec<f32> = best_points_pool.iter().map(|p| p.y_center).collect();
        let zm: Vec<f32> = best_points_pool.iter().map(|p| p.z_center).collect();

        // Проверка минимальной протяженности пути
        let ym_max = ym.iter().cloned().fold(f32::NEG_INFINITY, f32::max);
        let ym_min = ym.iter().cloned().fold(f32::INFINITY, f32::min);
        let track_length = (ym_max - ym_min).abs();

        if self.config.min_track_length_m > 0.0 && track_length < self.config.min_track_length_m {
            return None;
        }

        let raw_poly_y = polyfit2(&ym, &xm).unwrap_or([0.0, 0.0, 0.0]); // X(Y)
        let raw_poly_z = polyfit1(&ym, &zm).unwrap_or([0.0, zm.first().copied().unwrap_or(0.0)]); // Z(Y)

        let mut sorted_gauges: Vec<f32> = best_points_pool.iter().map(|p| p.gauge).collect();
        sorted_gauges.sort_by(|a, b| a.partial_cmp(b).unwrap());
        let median_gauge = sorted_gauges[sorted_gauges.len() / 2];
        let x_det_max = ym.iter().map(|y| y.abs()).fold(f32::NEG_INFINITY, f32::max);

        // Темпоральное взвешенное сглаживание полинома
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

            let n = self.history.len();
            for (idx, item) in self.history.iter().enumerate() {
                let w = (idx + 1) as f64 / n as f64;
                sum_y[0] += item.poly_y[0] as f64 * w;
                sum_y[1] += item.poly_y[1] as f64 * w;
                sum_y[2] += item.poly_y[2] as f64 * w;
                sum_z[0] += item.poly_z[0] as f64 * w;
                sum_z[1] += item.poly_z[1] as f64 * w;
                sum_gauge += item.gauge as f64 * w;
                sum_xmax += item.x_det_max as f64 * w;
                total_w += w;
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

        // В СК лидара: Y- вперед, X+ влево, X- вправо
        let lateral_shift_15m = a * (15.0 * 15.0) - b * 15.0;
        let turn_direction = if lateral_shift_15m.abs() < 0.20 && a.abs() < 0.0003 {
            "STRAIGHT".to_string()
        } else if lateral_shift_15m > 0.0 {
            "CURVE LEFT".to_string()
        } else {
            "CURVE RIGHT".to_string()
        };

        // Ресемплинг аналитических 3D линий путей
        let y_start = ym_max.min(-1.5);
        let y_end = ym_min.min(-smooth_det_max).min(y_start - 1.0);

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
            let yi = y_start + t * (y_end - y_start);
            let xi = a * yi * yi + b * yi + c;
            let zi = d * yi + e;

            let theta_poly = (2.0 * a * yi + b).atan();
            let cos_t = theta_poly.cos();
            let sin_t = theta_poly.sin();

            x_curve.push(xi);
            y_center.push(yi);
            z_center.push(zi);

            x_left.push(xi + half_w * cos_t);
            y_left.push(yi - half_w * sin_t);

            x_right.push(xi - half_w * cos_t);
            y_right.push(yi + half_w * sin_t);
        }

        // Экстраполяция полинома вперед (в сторону еще более отрицательного Y)
        let mut x_ext = Vec::new();
        let mut y_ext = Vec::new();
        let mut z_ext = Vec::new();
        let mut x_ext_l = Vec::new();
        let mut y_ext_l = Vec::new();
        let mut x_ext_r = Vec::new();
        let mut y_ext_r = Vec::new();

        if self.config.extrapolate_m > 0.0 {
            let n_ext = 50;
            let y_ext_start = y_end;
            let y_ext_end = y_end - self.config.extrapolate_m;
            for i in 0..n_ext {
                let t = i as f32 / (n_ext - 1) as f32;
                let ye = y_ext_start + t * (y_ext_end - y_ext_start);
                let xe = a * ye * ye + b * ye + c;
                let ze = d * ye + e;

                let theta_poly = (2.0 * a * ye + b).atan();
                let cos_t = theta_poly.cos();
                let sin_t = theta_poly.sin();

                x_ext.push(xe);
                y_ext.push(ye);
                z_ext.push(ze);

                x_ext_l.push(xe + half_w * cos_t);
                y_ext_l.push(ye - half_w * sin_t);

                x_ext_r.push(xe - half_w * cos_t);
                y_ext_r.push(ye + half_w * sin_t);
            }
        }

        let total_checked_slices = (start_slice.abs_diff(end_slice) + 1) as f32;
        let confidence = (best_points_pool.len() as f32 / total_checked_slices.max(1.0)).min(1.0);

        let (avg_i_l, avg_i_r) = if !best_points_pool.is_empty() {
            let n = best_points_pool.len() as f32;
            (
                best_points_pool
                    .iter()
                    .map(|p| p.intensity_left)
                    .sum::<f32>()
                    / n,
                best_points_pool
                    .iter()
                    .map(|p| p.intensity_right)
                    .sum::<f32>()
                    / n,
            )
        } else {
            (0.0, 0.0)
        };

        let t_rail_dur = t_start_rail.elapsed();

        // Прямой 3D Boxcast без искажения тоннеля (warp)
        let t_start_obs = Instant::now();
        let obstacles = if self.config.detect_obstacles && self.config.obstacle_config.enabled {
            detect_obstacles_direct(
                cloud,
                queue,
                &poly_y,
                &poly_z,
                median_gauge,
                &self.config.obstacle_config,
            )
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
            clearance_width: self.config.obstacle_config.clearance_width,
            min_height_above_rail: self.config.obstacle_config.min_height_above_rail,
            max_height_above_rail: self.config.obstacle_config.max_height_above_rail,
            timing_rail_ms,
            timing_obstacles_ms,
            timing_total_ms,
        })
    }

    /// Алиас для обратной совместимости вызовов
    #[inline(always)]
    pub fn process_rings(
        &mut self,
        slices: &mut [Vec<RawFloorPoint>],
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
        frame_idx: usize,
        obs_frame: Option<&RangeImage>,
    ) -> Option<DetectionResultOrt> {
        self.process_slices(slices, cloud, queue, frame_idx, obs_frame)
    }
}

/// Прямой 3D Boxcast габарита приближения по облаку точек AppPointCloud
/// без искусственного искажения тоннеля (warp)
pub fn detect_obstacles_direct(
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
    let clearance_width = cfg.clearance_width;
    let min_w = gauge.max(1.0).min(clearance_width);
    let nom_h = (cfg.max_height_above_rail - cfg.min_height_above_rail).max(0.1);
    let center_h = (cfg.min_height_above_rail + cfg.max_height_above_rail) * 0.5;
    let min_h_thickness = 0.30_f32.min(nom_h);

    let total = pc.len(queue);

    // Точки-вторжения: (x, y, z, dist_fwd, d_lat, dz, is_critical)
    let mut intrusions: Vec<([f32; 3], f32, f32, f32, bool)> = Vec::new();

    for (i, (&x, &y, &z, _, _)) in pc.iter(queue).enumerate() {
        if i >= total {
            break;
        }
        let dist_fwd = -y;
        if dist_fwd < 2.0 || dist_fwd > cfg.max_distance_m || is_zero_point(x, y, z) {
            continue;
        }

        // Положение оси пути в точке y: X_track(y) и Z_track(y)
        let x_track = a * y * y + b * y + c;
        let z_track = d * y + e;

        // Касательный угол пути в этой точке
        let k = 2.0 * a * y + b;
        let cos_theta = 1.0 / (1.0 + k * k).sqrt();

        // Боковое расстояние по нормали к оси пути
        let d_lat = (x - x_track) * cos_theta;
        let dz = z - z_track;

        // Сужение/расширение габарита по дальности
        let dx_fwd = (dist_fwd - 2.0).max(0.0);
        let cur_half_w =
            (clearance_width - cfg.clearance_narrowing_width * dx_fwd).max(min_w) * 0.5;
        let cur_h = (nom_h - cfg.clearance_narrowing_height * dx_fwd).max(min_h_thickness);
        let cur_min_h = center_h - cur_h * 0.5;
        let cur_max_h = center_h + cur_h * 0.5;

        if d_lat.abs() <= cur_half_w && dz >= cur_min_h && dz <= cur_max_h {
            let is_critical = d_lat.abs() <= danger_half_w;
            intrusions.push(([x, y, z], dist_fwd, d_lat, dz, is_critical));
        }
    }

    if intrusions.is_empty() {
        return Vec::new();
    }

    // Сортировка по продольной дистанции вперед
    intrusions.sort_unstable_by(|a, b| a.1.total_cmp(&b.1));

    // Кластеризация по продольному расстоянию вдоль пути
    let cluster_depth = cfg.cluster_depth_thresh.max(0.60);
    let mut clusters: Vec<Vec<([f32; 3], f32, f32, f32, bool)>> = Vec::new();
    let mut cur_cluster: Vec<([f32; 3], f32, f32, f32, bool)> = Vec::new();

    for pt in intrusions {
        if let Some(last_in_cluster) = cur_cluster.last() {
            if (pt.1 - last_in_cluster.1).abs() > cluster_depth {
                if !cur_cluster.is_empty() {
                    clusters.push(std::mem::take(&mut cur_cluster));
                }
            }
        }
        cur_cluster.push(pt);
    }
    if !cur_cluster.is_empty() {
        clusters.push(cur_cluster);
    }

    let mut obstacles = Vec::new();
    let mut obs_id = 1usize;

    for cl in clusters {
        if cl.len() < cfg.min_points {
            continue;
        }

        let n = cl.len() as f32;
        let mut min_x = f32::INFINITY;
        let mut max_x = f32::NEG_INFINITY;
        let mut min_y = f32::INFINITY;
        let mut max_y = f32::NEG_INFINITY;
        let mut min_z = f32::INFINITY;
        let mut max_z = f32::NEG_INFINITY;

        let mut sum_dist = 0.0f32;
        let mut sum_lat = 0.0f32;
        let mut sum_dz = 0.0f32;
        let mut crit_count = 0usize;

        for &(p, dist_fwd, d_lat, dz, is_crit) in &cl {
            min_x = min_x.min(p[0]);
            max_x = max_x.max(p[0]);
            min_y = min_y.min(p[1]);
            max_y = max_y.max(p[1]);
            min_z = min_z.min(p[2]);
            max_z = max_z.max(p[2]);

            sum_dist += dist_fwd;
            sum_lat += d_lat;
            sum_dz += dz;
            if is_crit {
                crit_count += 1;
            }
        }

        let avg_dist = sum_dist / n;
        let avg_lat = sum_lat / n;
        let avg_dz = sum_dz / n;
        let is_critical = crit_count >= 2;

        let size_x = (max_x - min_x).max(0.15);
        let size_y = (max_y - min_y).max(0.15);
        let size_z = (max_z - min_z).max(0.15);

        let status = if is_critical {
            crate::rail_detection::ObstacleStatus::Critical
        } else {
            crate::rail_detection::ObstacleStatus::ClearanceWarning
        };

        obstacles.push(TrackObstacle {
            id: obs_id,
            distance_along_track: avg_dist,
            lateral_offset: avg_lat,
            height_above_rail: avg_dz,
            bbox_3d_min: [min_x, min_y, min_z],
            bbox_3d_max: [max_x, max_y, max_z],
            bbox_2d: [0, 0, 10, 10],
            points_count: cl.len(),
            is_critical,
            size_m: [size_x, size_y, size_z],
            status,
            hits: 1,
            in_gauge: is_critical,
        });

        obs_id += 1;
    }

    obstacles
}

/// Линейная регрессия Z(Y) = d*Y + e
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

/// Квадратичная регрессия X(Y) = a*Y^2 + b*Y + c методом наименьших квадратов
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_polyfit1_linear() {
        let ys = vec![-10.0, -20.0, -30.0, -40.0];
        let zs = vec![-1.0, -1.2, -1.4, -1.6]; // Z = 0.02 * Y - 0.8
        let res = polyfit1(&ys, &zs).expect("fit failed");
        assert!((res[0] - 0.02).abs() < 1e-4);
        assert!((res[1] - (-0.8)).abs() < 1e-4);
    }

    #[test]
    fn test_polyfit2_parabola() {
        let ys = vec![-5.0, -10.0, -15.0, -20.0, -25.0];
        let xs: Vec<f32> = ys.iter().map(|&y| 0.001 * y * y - 0.02 * y + 0.1).collect();
        let res = polyfit2(&ys, &xs).expect("fit failed");
        assert!((res[0] - 0.001).abs() < 1e-4);
        assert!((res[1] - (-0.02)).abs() < 1e-4);
        assert!((res[2] - 0.1).abs() < 1e-4);
    }

    #[test]
    fn test_shapecast_wireframe_3d_coordinates() {
        let res = DetectionResultOrt {
            frame_idx: 1,
            points: Vec::new(),
            gauge: 1.52,
            curvature_a: 0.0,
            heading_b: 0.0,
            offset_c: 0.0,
            turn_radius: 99999.0,
            turn_direction: "STRAIGHT".to_string(),
            lateral_shift_15m: 0.0,
            poly_y: [0.0, 0.0, 0.0],
            poly_z: [0.0, -1.5],
            x_curve: Vec::new(),
            y_center: vec![-2.0, -10.0, -20.0],
            z_center: vec![-1.5, -1.5, -1.5],
            x_left: Vec::new(),
            y_left: Vec::new(),
            x_right: Vec::new(),
            y_right: Vec::new(),
            confidence: 1.0,
            extrapolate_m: 10.0,
            smooth_n: 1,
            x_ext: Vec::new(),
            y_ext: vec![-20.0, -30.0],
            z_ext: Vec::new(),
            x_ext_l: Vec::new(),
            y_ext_l: Vec::new(),
            x_ext_r: Vec::new(),
            y_ext_r: Vec::new(),
            avg_intensity_left: 10.0,
            avg_intensity_right: 10.0,
            obstacles: Vec::new(),
            clearance_width: 2.10,
            min_height_above_rail: 0.00,
            max_height_above_rail: 3.00,
            timing_rail_ms: 1.0,
            timing_obstacles_ms: 0.5,
            timing_total_ms: 1.5,
        };

        let strips = res.shapecast_wireframe_3d();
        assert!(!strips.is_empty());
        let p0 = strips[0][0];
        // X+ = left, Y- = forward, Z- = down
        assert!(p0[1] <= -1.5, "Y should be negative forward distance");
        assert!(
            p0[0] > 0.0,
            "Left boundary X should be positive (X+ is left)"
        );
    }
}
