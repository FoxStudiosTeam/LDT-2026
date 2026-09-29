//! rail_detection.rs — Railway track detection for 3D LiDAR Range Images
//!
//! Port of Python implementation (`dev_pyrails/detector.py` and `dev_pyrails/geometry.py`).
//! Detects left/right rails from range discontinuities, verifies gauge and height consistency,
//! tracks scanline continuity, and fits 3D trajectory curves.

use crate::range_image::RangeImage;
use crate::types::{AppPointCloud, ProcessingQueue};

/// 3D Geometry and Spherical Projection for Hesai Pandar128 LiDAR range images
#[derive(Clone, Debug)]
pub struct LidarGeometry {
    pub height: usize,
    pub width: usize,
    pub fov_up_rad: f32,
    pub fov_down_rad: f32,
    pub total_fov_v: f32,
    pub fov_h_rad: f32,
    pub step_v_rad: f32,
    pub dir_x: Vec<f32>,
    pub dir_y: Vec<f32>,
    pub dir_z: Vec<f32>,
}

impl Default for LidarGeometry {
    fn default() -> Self {
        Self::new(128, 140, 15.0, -25.0, 40.0)
    }
}

impl LidarGeometry {
    pub fn new(
        height: usize,
        width: usize,
        fov_up_deg: f32,
        fov_down_deg: f32,
        fov_h_deg: f32,
    ) -> Self {
        let fov_up_rad = fov_up_deg.to_radians();
        let fov_down_rad = fov_down_deg.to_radians();
        let total_fov_v = fov_up_rad - fov_down_rad;
        let fov_h_rad = fov_h_deg.to_radians();

        // Precompute pitch for each row [0..height-1] (row 0 is up, row H-1 is down)
        let step_v_rad = if height > 1 {
            total_fov_v / (height - 1) as f32
        } else {
            0.125_f32.to_radians()
        };
        let mut cos_pitch = Vec::with_capacity(height);
        let mut sin_pitch = Vec::with_capacity(height);
        for row in 0..height {
            let pitch = fov_up_rad - (row as f32) * step_v_rad;
            cos_pitch.push(pitch.cos());
            sin_pitch.push(pitch.sin());
        }

        // Precompute yaw for each col [0..width-1] (col W/2 is 0 rad / straight forward)
        let width_f = width as f32;
        let mut cos_yaw = Vec::with_capacity(width);
        let mut sin_yaw = Vec::with_capacity(width);
        for col in 0..width {
            let yaw = ((col as f32) + 0.5 - width_f / 2.0) / width_f * fov_h_rad;
            cos_yaw.push(yaw.cos());
            sin_yaw.push(yaw.sin());
        }

        let total_cells = height * width;
        let mut dir_x = Vec::with_capacity(total_cells);
        let mut dir_y = Vec::with_capacity(total_cells);
        let mut dir_z = Vec::with_capacity(total_cells);

        for row in 0..height {
            let cp = cos_pitch[row];
            let sp = sin_pitch[row];
            for col in 0..width {
                dir_x.push(cp * cos_yaw[col]);
                dir_y.push(cp * sin_yaw[col]);
                dir_z.push(sp);
            }
        }

        Self {
            height,
            width,
            fov_up_rad,
            fov_down_rad,
            total_fov_v,
            fov_h_rad,
            step_v_rad,
            dir_x,
            dir_y,
            dir_z,
        }
    }

    /// Converts (row, col, range) to (X, Y, Z) in meters using trigonometry.
    #[inline(always)]
    pub fn row_col_range_to_xyz(&self, row: usize, col: usize, r: f32) -> (f32, f32, f32) {
        let idx = row * self.width + col;
        (
            r * self.dir_x[idx],
            r * self.dir_y[idx],
            r * self.dir_z[idx],
        )
    }

    /// Получает 3D координаты (X, Y, Z) точки по координатам (row, col) на 2D плоскости Range Image.
    /// Если передано облако точек `cloud: Some((point_cloud, queue))` и в кадре сохранен валидный индекс точки,
    /// координаты берутся НАПРЯМУЮ из облака точек (zero-copy, без промежуточных массивов).
    /// Иначе вычисляются через тригонометрию по дальности `frame.data[idx]` и направляющим косинусам.
    /// Если `upward_curvature != 0.0`, к координате Z добавляется квадратичный прогиб `upward_curvature * X^2`
    /// для согласованности с warped RangeImage.
    #[inline(always)]
    pub fn get_point_xyz(
        &self,
        frame: &RangeImage,
        cloud: Option<(&AppPointCloud, ProcessingQueue)>,
        row: usize,
        col: usize,
        upward_curvature: f32,
    ) -> (f32, f32, f32) {
        let idx = row * self.width + col;
        if let Some((pc, queue)) = cloud {
            if let Some(&pt_idx) = frame.point_indices.get(idx) {
                if pt_idx != crate::range_image::NO_POINT_INDEX && (pt_idx as usize) < pc.len(queue)
                {
                    let p_i = pt_idx as usize;
                    let px = -pc.y[queue][p_i];
                    let py = pc.x[queue][p_i];
                    let pz = pc.z[queue][p_i];
                    if !crate::types::is_zero_point(px, py, pz) {
                        let z_bent = if upward_curvature.abs() > 1e-7 {
                            pz + upward_curvature * px * px
                        } else {
                            pz
                        };
                        return (px, py, z_bent);
                    }
                }
            }
        }
        let r = frame.data[idx];
        (
            r * self.dir_x[idx],
            r * self.dir_y[idx],
            r * self.dir_z[idx],
        )
    }

    /// Converts entire range image to X, Y, Z arrays (each of length width * height).
    pub fn range_image_to_xyz(&self, frame: &RangeImage) -> (Vec<f32>, Vec<f32>, Vec<f32>) {
        let total = self.height * self.width;
        let mut x = Vec::with_capacity(total);
        let mut y = Vec::with_capacity(total);
        let mut z = Vec::with_capacity(total);

        for (i, &r) in frame.data.iter().enumerate().take(total) {
            x.push(r * self.dir_x[i]);
            y.push(r * self.dir_y[i]);
            z.push(r * self.dir_z[i]);
        }

        (x, y, z)
    }

    /// Projects 3D points (x, y, z) back onto range image (row, col).
    pub fn xyz_to_row_col(&self, x: f32, y: f32, z: f32) -> (isize, isize) {
        let r = (x * x + y * y + z * z).sqrt();
        if r < 1e-6 {
            return (-1, -1);
        }
        let pitch = (z / r).clamp(-1.0, 1.0).asin();
        let yaw = y.atan2(x);

        let row = ((self.fov_up_rad - pitch) / self.step_v_rad).round() as isize;
        let col = ((yaw / self.fov_h_rad * (self.width as f32)) + (self.width as f32) / 2.0 - 0.5)
            .round() as isize;

        (row, col)
    }
}

/// Detected rail point pair on a single scanline
#[derive(Clone, Debug)]
pub struct RailPoint {
    pub row: usize,
    pub col_left: usize,
    pub col_right: usize,
    pub x_left: f32,
    pub y_left: f32,
    pub z_left: f32,
    pub x_right: f32,
    pub y_right: f32,
    pub z_right: f32,
    pub x_center: f32,
    pub y_center: f32,
    pub z_center: f32,
    pub gauge: f32,
    pub intensity_left: f32,
    pub intensity_right: f32,
}

/// Item stored in temporal history for smoothing across consecutive frames
#[derive(Clone, Debug)]
pub struct DetectionHistoryItem {
    pub poly_y: [f32; 3],
    pub poly_z: [f32; 2],
    pub gauge: f32,
    pub x_det_max: f32,
}

/// Complete track detection & 3D trajectory result
#[derive(Clone, Debug)]
pub struct DetectionResult {
    pub frame_idx: usize,
    pub points: Vec<RailPoint>,
    pub gauge: f32,
    pub curvature_a: f32,
    pub heading_b: f32,
    pub offset_c: f32,
    pub turn_radius: f32,
    pub turn_direction: String, // "STRAIGHT", "CURVE LEFT", "CURVE RIGHT"
    pub lateral_shift_15m: f32,
    pub poly_y: [f32; 3], // [a, b, c] for Y(X) = a*X^2 + b*X + c
    pub poly_z: [f32; 2], // [d, e] for Z(X) = d*X + e
    // Resampled 3D curves (120 points)
    pub x_curve: Vec<f32>,
    pub y_center: Vec<f32>,
    pub z_center: Vec<f32>,
    pub x_left: Vec<f32>,
    pub y_left: Vec<f32>,
    pub x_right: Vec<f32>,
    pub y_right: Vec<f32>,
    pub confidence: f32,
    // Extrapolation fields (Magenta Polynomial, N-frame smoothed)
    pub extrapolate_m: f32,
    pub smooth_n: usize,
    pub x_ext: Vec<f32>,
    pub y_ext: Vec<f32>,
    pub z_ext: Vec<f32>,
    pub x_ext_l: Vec<f32>,
    pub y_ext_l: Vec<f32>,
    pub x_ext_r: Vec<f32>,
    pub y_ext_r: Vec<f32>,
    pub has_intensity: bool,
    pub avg_intensity_left: f32,
    pub avg_intensity_right: f32,
    // Препятствия на пути и в габарите
    pub obstacles: Vec<TrackObstacle>,
    // Параметры габарита приближения (шейпкаст / бокскаст)
    pub clearance_width: f32,
    pub min_height_above_rail: f32,
    pub max_height_above_rail: f32,
    pub max_distance_m: f32,
    pub upward_curvature: f32,
    /// Коэффициент сужения ширины габарита с расстоянием (м/м)
    pub clearance_narrowing_width: f32,
    /// Коэффициент снижения высотного габарита с расстоянием (м/м)
    pub clearance_narrowing_height: f32,
    /// Вертикальный сдвиг конечной точки искривления габарита по высоте на дальней дистанции (м)
    pub clearance_height_end_shift: f32,
    /// Оффсет начала шейпкаста по глубине относительно начальной плоскости (м)
    pub clearance_start_offset: f32,
    pub obstacle_enabled: bool,
    /// Флаг истинных (восстановленных) координат в реальном физическом пространстве
    pub is_real_coordinates: bool,
    /// Режим удержания траектории (coasting) при отбрасывании скачка
    pub is_coasting: bool,
    /// Длина серии отброшенных выбросов подряд
    pub outlier_streak: usize,
    /// Использована ли дальняя опорная точка из предыдущего кадра
    pub far_anchor_active: bool,
    /// Время детекции рельсов (мс)
    pub timing_rail_ms: f32,
    /// Время проверки и кластеризации препятствий (мс)
    pub timing_obstacles_ms: f32,
    /// Общее время работы алгоритма детекции (мс)
    pub timing_total_ms: f32,
}

impl DetectionResult {
    /// Восстанавливает истинные 3D координаты в реальном физическом пространстве:
    /// Z_real = Z_bent - upward_curvature * X^2
    pub fn restore_real_coordinates(&mut self) {
        if self.is_real_coordinates || self.upward_curvature.abs() < 1e-7 {
            self.is_real_coordinates = true;
            return;
        }
        let cz = self.upward_curvature;
        for i in 0..self.x_curve.len() {
            let x = self.x_curve[i];
            self.z_center[i] -= cz * x * x;
        }
        for i in 0..self.x_ext.len() {
            let x = self.x_ext[i];
            self.z_ext[i] -= cz * x * x;
        }
        for p in &mut self.points {
            p.z_left -= cz * p.x_left * p.x_left;
            p.z_right -= cz * p.x_right * p.x_right;
            p.z_center -= cz * p.x_center * p.x_center;
        }
        self.is_real_coordinates = true;
    }

    /// Возвращает цвет RGB для шейпкаста: Красный при критическом препятствии на колее,
    /// Янтарный при препятствии в габарите, Бирюзовый/Циан при свободном пути.
    pub fn shapecast_color(&self) -> [u8; 3] {
        let num_crit = self.obstacles.iter().filter(|o| o.is_critical).count();
        let num_warn = self
            .obstacles
            .iter()
            .filter(|o| o.status == ObstacleStatus::ClearanceWarning)
            .count();
        if num_crit > 0 {
            [255, 30, 30] // Alert Red
        } else if num_warn > 0 {
            [255, 170, 0] // Warning Amber
        } else {
            [0, 220, 220] // Calm Cyan / Clear
        }
    }

    /// Генерирует 3D полилинии (wireframe strips) для визуализации шейпкаста габарита приближения:
    /// Коридор шейпкаста строится непосредственно вдоль аналитической кривой пути
    /// от x_min (2.0 м перед лидаром) до x_max = max_distance_m:
    /// - В реальных координатах (is_real_coordinates = true) строго следует профилю полотна poly_z[0]*X + poly_z[1]
    /// - В искривленных координатах (is_real_coordinates = false) добавляет upward_curvature * X^2 для точной проекции в warped RangeImage
    /// - 4 продольные грани туннеля (нижняя левая/правая, верхняя левая/правая)
    /// - Поперечные прямоугольные рамки (шпангоуты) с шагом ~4 м вдоль кривой
    /// - Торцевые диагональные крестовины (порталы входа и выхода)
    pub fn shapecast_wireframe_3d(&self) -> Vec<Vec<[f32; 3]>> {
        let x_min = (2.0 + self.clearance_start_offset).max(0.1);
        let x_max = self.max_distance_m;
        if !self.obstacle_enabled || x_max <= x_min || self.clearance_width <= 0.0 {
            return Vec::new();
        }

        // Дискретизация вдоль аналитической траектории пути с шагом 0.5 м
        let step_m = 0.5_f32;
        let num_steps = ((x_max - x_min) / step_m).round().max(10.0) as usize;

        let mut line_bl = Vec::with_capacity(num_steps + 1);
        let mut line_br = Vec::with_capacity(num_steps + 1);
        let mut line_tl = Vec::with_capacity(num_steps + 1);
        let mut line_tr = Vec::with_capacity(num_steps + 1);
        let mut frames = Vec::new();

        // Поперечные рамки-шпангоуты примерно каждые 4 метра
        let hoop_dist_m = 4.0_f32;
        let hoop_step = ((hoop_dist_m / step_m).round().max(1.0)) as usize;

        let min_w = self.gauge.max(1.0).min(self.clearance_width);
        let nom_h = (self.max_height_above_rail - self.min_height_above_rail).max(0.1);
        let center_h = (self.min_height_above_rail + self.max_height_above_rail) * 0.5;
        let min_h_thickness = 0.30_f32.min(nom_h);

        for i in 0..=num_steps {
            let t = (i as f32) / (num_steps as f32);
            let x = x_min + t * (x_max - x_min);

            // Сужение габарита по мере удаления (центрированно по ширине и высоте):
            let dx = (x - x_min).max(0.0);
            let cur_w = (self.clearance_width - self.clearance_narrowing_width * dx).max(min_w);
            let cur_h = (nom_h - self.clearance_narrowing_height * dx).max(min_h_thickness);
            let range_x = (x_max - x_min).max(1.0);
            let t_norm = (dx / range_x).min(2.0);
            let h_shift = self.clearance_height_end_shift * t_norm * t_norm;
            let half_w = cur_w * 0.5;
            let half_h = cur_h * 0.5;
            let cur_min_h = center_h + h_shift - half_h;
            let cur_max_h = center_h + h_shift + half_h;

            let y_c = self.poly_y[0] * x * x + self.poly_y[1] * x + self.poly_y[2];
            let z_surf = if self.is_real_coordinates {
                self.poly_z[0] * x + self.poly_z[1]
            } else {
                self.poly_z[0] * x + self.poly_z[1] + self.upward_curvature * x * x
            };
            let dy_dx = 2.0 * self.poly_y[0] * x + self.poly_y[1];
            let theta = dy_dx.atan();
            let sin_t = theta.sin();
            let cos_t = theta.cos();

            let xl = x + half_w * sin_t;
            let yl = y_c - half_w * cos_t;
            let xr = x - half_w * sin_t;
            let yr = y_c + half_w * cos_t;

            let zb = z_surf + cur_min_h;
            let zt = z_surf + cur_max_h;

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

    /// Проецирует 3D полилинии шейпкаста габарита на 2D Range Image в пиксели [col, row].
    pub fn shapecast_wireframe_2d(&self, geo: &LidarGeometry) -> Vec<Vec<[f32; 2]>> {
        let strips_3d = self.shapecast_wireframe_3d();
        let h = geo.height;
        let w = geo.width;
        let mut strips_2d = Vec::new();

        for strip in strips_3d {
            let mut cur_sub_strip = Vec::new();
            for p in strip {
                let (row, col) = geo.xyz_to_row_col(p[0], p[1], p[2]);
                if row >= 0 && (row as usize) < h && col >= 0 && (col as usize) < w {
                    cur_sub_strip.push([col as f32, row as f32]);
                } else {
                    if cur_sub_strip.len() >= 2 {
                        strips_2d.push(std::mem::take(&mut cur_sub_strip));
                    } else {
                        cur_sub_strip.clear();
                    }
                }
            }
            if cur_sub_strip.len() >= 2 {
                strips_2d.push(cur_sub_strip);
            }
        }

        strips_2d
    }
}

/// Алгоритм детекции препятствий на путях
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ObstacleDetectionMode {
    /// 3D бокскаст кинематического габарита вдоль кривой пути Y(X), Z(X)
    Boxcast3D,
    /// 2D матричный анализ перепадов дальности над полотном в коридоре путей
    DepthMatrix2D,
    /// Гибридный метод: 3D аналитический фильтр габарита + 2D связные компоненты O(N)
    HybridGrid,
}

/// Статус классификации препятствия системой временной фильтрации
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum ObstacleStatus {
    /// Одиночная детекция (маловероятное / tentative, серая обводка)
    Unlikely,
    /// Подтвержденное препятствие в габарите приближения вне колеи (предупреждение, янтарная обводка)
    ClearanceWarning,
    /// Подтвержденное критическое препятствие непосредственно в колее (красная обводка)
    Critical,
}

/// Конфигурация детекции препятствий на железнодорожном полотне
#[derive(Clone, Debug)]
pub struct ObstacleConfig {
    pub enabled: bool,
    pub mode: ObstacleDetectionMode,
    /// Ширина габарита приближения строений/подвижного состава (м), default: 2.40 м (±1.2 м от оси)
    pub clearance_width: f32,
    /// Минимальная высота над головкой рельса для отсечения шпал/балласта (м), default: 0.15 м
    pub min_height_above_rail: f32,
    /// Максимальная высота габарита приближения (м), default: 3.20 м
    pub max_height_above_rail: f32,
    /// Минимальное количество точек лидара в кластере, default: 6
    pub min_points: usize,
    /// Максимальная дальность поиска препятствий (м), default: 50.0 м
    pub max_distance_m: f32,
    /// Порог перепада глубины для матричного 2D метода (м), default: 0.25 м
    pub depth_diff_thresh: f32,
    /// Коэффициент квадратичного искривления тоннеля габарита вверх по глубине (1/м), Z_surf(X) += upward_curvature * X^2
    /// Позволяет компенсировать линейный наклон вниз и удерживать габарит на полотне на дальних расстояниях
    pub upward_curvature: f32,
    /// Коэффициент линейного сужения ширины габарита приближения с расстоянием (м/м)
    /// Например 0.010 означает сужение ширины коридора на 1.0м каждые 100м дистанции (-0.5м на 50м)
    pub clearance_narrowing_width: f32,
    /// Коэффициент линейного снижения высотного габарита приближения с расстоянием (м/м)
    /// Например 0.010 означает снижение потолка коридора на 1.0м каждые 100м дистанции (-0.5м на 50м)
    pub clearance_narrowing_height: f32,
    /// Вертикальный сдвиг конечной точки искривления габарита по высоте на дальней дистанции (м)
    /// Смещает центр габарита по высоте на дистанции max_distance_m (+ вверх, - вниз)
    pub clearance_height_end_shift: f32,
    /// Оффсет начала шейпкаста / габарита приближения (м) — игнорирование точек ближе чем этот сдвиг относительно начальной плоскости, default: 0.0 м
    pub clearance_start_offset: f32,
    /// Максимальный разрыв по дальности (м) между соседними точками для объединения в один кластер, default: 1.20 м
    /// Предотвращает склейку разноудаленных объектов на одной линии визирования
    pub cluster_depth_thresh: f32,
    /// Включение временного трекинга препятствий для фильтрации ложных одиночных срабатываний
    pub temporal_tracking_enabled: bool,
    /// Минимальное количество повторений (детекций) для подтверждения critical, default: 2
    pub min_hits_for_critical: usize,
    /// Допустимый пропуск кадров между повторениями (default: 1, что соответствует "через одно")
    pub max_missed_frames: usize,
    /// Допустимое смещение вдоль пути между соседними кадрами для одного объекта (м), default: 2.50 м
    pub track_match_dist_m: f32,
    /// Допустимое латеральное смещение между кадрами для одного объекта (м), default: 0.80 м
    pub track_match_lateral_m: f32,
    /// Включение динамического сжатия длины габарита (шейпкаста / дальности детекции) в поворотах в зависимости от радиуса кривизны
    pub turn_compression_enabled: bool,
    /// Минимальный радиус поворота (м), при котором достигается максимальное сжатие длины габарита (min_scale), default: 200.0 м
    pub turn_radius_min: f32,
    /// Максимальный радиус поворота (м), выше которого сжатие длины не применяется (scale = max_scale = 1.0), default: 1000.0 м
    pub turn_radius_max: f32,
    /// Минимальный масштаб длины габарита при крутом повороте (R <= turn_radius_min), default: 0.70 (70% от max_distance_m)
    pub turn_compression_min_scale: f32,
    /// Максимальный масштаб длины габарита на прямом участке (R >= turn_radius_max), default: 1.00 (100% от max_distance_m)
    pub turn_compression_max_scale: f32,
}

impl ObstacleConfig {
    /// Вычисляет коэффициент масштабирования длины (дальности) габарита (шейпкаста) в зависимости от радиуса поворота
    pub fn compute_turn_compression_scale(&self, turn_radius: f32) -> f32 {
        if !self.turn_compression_enabled
            || (self.turn_radius_max - self.turn_radius_min).abs() < 1e-4
        {
            return 1.0;
        }
        crate::utils::remap_clamped(
            turn_radius,
            self.turn_radius_min,
            self.turn_radius_max,
            self.turn_compression_min_scale,
            self.turn_compression_max_scale,
        )
    }

    /// Вычисляет эффективную максимальную дальность (длину) габарита с учетом сжатия в повороте
    pub fn effective_max_distance(&self, turn_radius: f32) -> f32 {
        let scale = self.compute_turn_compression_scale(turn_radius);
        let min_dist = (2.0 + self.clearance_start_offset).max(5.0);
        (self.max_distance_m * scale).max(min_dist)
    }
}

impl Default for ObstacleConfig {
    fn default() -> Self {
        Self {
            enabled: true,
            mode: ObstacleDetectionMode::HybridGrid,
            clearance_width: 2.40,
            min_height_above_rail: 0.15,
            max_height_above_rail: 3.20,
            min_points: 6,
            max_distance_m: 50.0,
            depth_diff_thresh: 0.25,
            upward_curvature: 0.0004,
            clearance_narrowing_width: 0.0,
            clearance_narrowing_height: 0.0,
            clearance_height_end_shift: 0.0,
            clearance_start_offset: 0.0,
            cluster_depth_thresh: 1.20,
            temporal_tracking_enabled: true,
            min_hits_for_critical: 2,
            max_missed_frames: 1,
            track_match_dist_m: 2.50,
            track_match_lateral_m: 0.80,
            turn_compression_enabled: false,
            turn_radius_min: 200.0,
            turn_radius_max: 1000.0,
            turn_compression_min_scale: 0.70,
            turn_compression_max_scale: 1.00,
        }
    }
}

/// Проецирует точку (x, y) ортогонально на кривую пути Y(X) = a*X^2 + b*X + c.
/// Возвращает станцию пути xc вдоль оси X, где нормаль к кривой проходит через (x, y),
/// угол касательной theta, знаковое латеральное смещение d_lat и высоту профиля z_surf_real.
#[inline(always)]
pub fn project_point_to_track(
    x: f32,
    y: f32,
    poly_y: &[f32; 3],
    poly_z: &[f32; 2],
) -> (f32, f32, f32, f32) {
    let poly_a = poly_y[0];
    let poly_b = poly_y[1];
    let poly_c = poly_y[2];

    // Ищем xc: g(xc) = (x - xc) + (y - yc) * Y'_c(xc) = 0
    let mut xc = x;
    for _ in 0..2 {
        let yc = poly_a * xc * xc + poly_b * xc + poly_c;
        let k = 2.0 * poly_a * xc + poly_b;
        let g = (x - xc) + (y - yc) * k;
        let g_prime = -1.0 + (y - yc) * (2.0 * poly_a) - k * k;
        xc -= g / g_prime;
    }

    let yc = poly_a * xc * xc + poly_b * xc + poly_c;
    let k = 2.0 * poly_a * xc + poly_b;
    let theta = k.atan();
    let sin_t = theta.sin();
    let cos_t = theta.cos();

    // Знаковое расстояние от осевой линии вдоль нормали к кривой:
    // Положительное — вправо (y > yc при theta=0), отрицательное — влево.
    let d_lat = (y - yc) * cos_t - (x - xc) * sin_t;
    let z_surf_real = poly_z[0] * xc + poly_z[1];

    (xc, theta, d_lat, z_surf_real)
}

/// Обнаруженное препятствие на пути или в габарите приближения
#[derive(Clone, Debug)]
pub struct TrackObstacle {
    pub id: usize,
    /// Дистанция вдоль пути от лидара до ближайшей точки препятствия (м)
    pub distance_along_track: f32,
    /// Поперечное смещение от центральной оси пути (м, отрицательное - влево, положительное - вправо)
    pub lateral_offset: f32,
    /// Максимальная высота точки объекта над поверхностью рельса (м)
    pub height_above_rail: f32,
    /// 3D Bounding Box: [min_x, min_y, min_z]
    pub bbox_3d_min: [f32; 3],
    /// 3D Bounding Box: [max_x, max_y, max_z]
    pub bbox_3d_max: [f32; 3],
    /// 2D Bounding Box на Range Image: [min_col, min_row, max_col, max_row]
    pub bbox_2d: [usize; 4],
    /// Количество точек лидара в препятствии
    pub points_count: usize,
    /// Препятствие находится непосредственно в колее и подтверждено трекером как угроза
    pub is_critical: bool,
    /// Приблизительные размеры объекта [длина, ширина, высота] в метрах
    pub size_m: [f32; 3],
    /// Статус классификации трекером: Unlikely (одиночное), ClearanceWarning или Critical
    pub status: ObstacleStatus,
    /// Количество подтверждающих детекций препятствия в трекере
    pub hits: usize,
    /// Находится ли физически в пределах рельсовой колеи
    pub in_gauge: bool,
}

/// Состояние трека препятствия во времени для межсерийного трекинга
#[derive(Clone, Debug)]
pub struct TrackedObstacleState {
    pub id: usize,
    pub distance_along_track: f32,
    pub lateral_offset: f32,
    pub height_above_rail: f32,
    pub center_3d: [f32; 3],
    pub size_m: [f32; 3],
    pub in_gauge: bool,
    pub last_seen_frame: usize,
    pub missed_frames: usize,
    pub hits: usize,
}

/// Rail Track Detector for LiDAR Range Images
pub struct RailTrackDetector {
    pub geometry: LidarGeometry,
    pub nominal_gauge: f32,
    pub min_gauge: f32,
    pub max_gauge: f32,
    pub depth_step_thresh: f32,
    pub max_depth_step_thresh: f32,
    pub row_start_pct: f32,
    pub row_end_pct: f32,
    pub max_lateral_jump: f32,
    pub max_lateral_rail_jump: f32,
    pub extrapolate_m: f32,
    pub smooth_n: usize,
    pub obstacle_config: ObstacleConfig,
    /// Dual texture & blending parameters
    pub contrast_depth: f32,
    pub contrast_intensity: f32,
    pub blend: f32,
    pub history: std::collections::VecDeque<DetectionHistoryItem>,
    pub last_frame_idx: Option<usize>,
    /// Отбрасывание резких боковых скачков траектории между кадрами (gating)
    pub temporal_jump_reject_enabled: bool,
    /// Максимальный допустимый боковой скачок траектории между кадрами (м)
    pub max_interframe_jump_m: f32,
    /// Максимальное число кадров подряд для удержания траектории при срыве (coasting)
    pub max_outlier_frames: usize,
    /// Включение функционала дальней опорной точки из предыдущего кадра
    pub far_anchor_enabled: bool,
    /// Счётчик последовательных отброшенных кадров-выбросов
    pub outlier_streak: usize,
    /// Последняя валидированная полиномиальная траектория Y(X) = a*X^2 + b*X + c
    pub last_valid_poly_y: Option<[f32; 3]>,
    /// Последний валидированный высотный профиль Z(X) = d*X + e
    pub last_valid_poly_z: Option<[f32; 2]>,
    /// Последняя валидированная ширина колеи
    pub last_valid_gauge: Option<f32>,
    /// Последняя максимальная дистанция подтвержденных точек
    pub last_valid_x_max: Option<f32>,
    /// Опорная дальняя точка [x, y, z] из предыдущего подтверждённого кадра
    pub last_far_anchor: Option<[f32; 3]>,
    /// Активные треки препятствий из предыдущих кадров для временной верификации
    pub tracked_obstacles: Vec<TrackedObstacleState>,
    /// Счётчик уникальных ID препятствий
    pub next_obstacle_id: usize,
}

impl RailTrackDetector {
    pub fn new(geometry: LidarGeometry) -> Self {
        // Tuned RailTrackDetector Config
        Self {
            geometry,
            nominal_gauge: 1.520,
            min_gauge: 1.515,
            max_gauge: 1.550,
            depth_step_thresh: 0.10,
            max_depth_step_thresh: 0.90,
            row_start_pct: 0.85,
            row_end_pct: 0.45,
            max_lateral_jump: 0.30,
            max_lateral_rail_jump: 0.10,
            extrapolate_m: 15.0,
            smooth_n: 5,
            obstacle_config: ObstacleConfig::default(),
            contrast_depth: 200.0,
            contrast_intensity: 20.0,
            blend: 0.0,
            history: std::collections::VecDeque::new(),
            last_frame_idx: None,
            temporal_jump_reject_enabled: true,
            max_interframe_jump_m: 0.25,
            max_outlier_frames: 4,
            far_anchor_enabled: true,
            outlier_streak: 0,
            last_valid_poly_y: None,
            last_valid_poly_z: None,
            last_valid_gauge: None,
            last_valid_x_max: None,
            last_far_anchor: None,
            tracked_obstacles: Vec::new(),
            next_obstacle_id: 1,
        }
    }

    /// Clears temporal smoothing history to eliminate lag on frame jumps.
    pub fn reset(&mut self) {
        self.history.clear();
        self.last_frame_idx = None;
        self.outlier_streak = 0;
        self.last_valid_poly_y = None;
        self.last_valid_poly_z = None;
        self.last_valid_gauge = None;
        self.last_valid_x_max = None;
        self.last_far_anchor = None;
        self.tracked_obstacles.clear();
        self.next_obstacle_id = 1;
    }

    /// Получает 3D координаты (X, Y, Z) точки по координатам (row, col) на 2D плоскости Range Image.
    /// Напрямую обращается к данным облака точек (zero-copy), либо вычисляет через тригонометрию.
    #[inline(always)]
    pub fn get_point_xyz(
        &self,
        frame: &RangeImage,
        cloud: Option<(&AppPointCloud, ProcessingQueue)>,
        row: usize,
        col: usize,
    ) -> (f32, f32, f32) {
        self.geometry.get_point_xyz(
            frame,
            cloud,
            row,
            col,
            self.obstacle_config.upward_curvature,
        )
    }

    /// Analyzes range image for track detection (using active_frame, which may be curvature-warped)
    /// and performs obstacle detection (preferring raw_frame with true physical coordinates if provided).
    pub fn detect_with_raw(
        &mut self,
        active_frame: &RangeImage,
        raw_frame: Option<&RangeImage>,
        cloud: Option<(&AppPointCloud, ProcessingQueue)>,
        frame_idx: usize,
    ) -> Option<DetectionResult> {
        let t_start_rail = std::time::Instant::now();
        let frame = active_frame;
        let h = frame.height;
        let w = frame.width;
        if self.geometry.height != h || self.geometry.width != w {
            self.geometry = LidarGeometry::new(
                h,
                w,
                self.geometry.fov_up_rad.to_degrees(),
                self.geometry.fov_down_rad.to_degrees(),
                self.geometry.fov_h_rad.to_degrees(),
            );
        }
        let mut candidates: Vec<RailPoint> = Vec::new();
        let mut prev_y_center: Option<f32> = None;
        let mut prev_y_right: Option<f32> = None;
        let mut prev_y_left: Option<f32> = None;
        let mut prev_x_center: Option<f32> = None;
        let mut last_detected_row: Option<usize> = None;

        let row_start = (h as f32 * self.row_start_pct) as usize;
        let row_end = (h as f32 * self.row_end_pct.max(0.0)) as usize;

        let has_intensity = !frame.intensity.is_empty();
        let b = if has_intensity {
            self.blend.clamp(0.0, 1.0)
        } else {
            0.0
        };
        let inv_b = 1.0 - b;

        // Scan rows from near (row_start) to far (row_end) with step 1
        let mut row = row_start;
        while row > row_end {
            let row_offset = row * w;
            let r_row = &frame.data[row_offset..row_offset + w];

            let mut pos_steps = Vec::new();
            let mut neg_steps = Vec::new();

            if b <= 0.0 {
                // Pure depth step detection (void-aware)
                for c in 0..w - 1 {
                    let d0 = r_row[c];
                    let d1 = r_row[c + 1];
                    if d0 <= 0.1 && d1 <= 0.1 {
                        continue;
                    }
                    if d0 <= 0.1 && d1 > 0.1 {
                        if d1 > self.depth_step_thresh {
                            pos_steps.push(c + 1);
                        }
                    } else if d0 > 0.1 && d1 <= 0.1 {
                        if d0 > self.depth_step_thresh {
                            neg_steps.push(c);
                        }
                    } else {
                        let diff_r = d1 - d0;
                        if diff_r > self.depth_step_thresh && diff_r <= self.max_depth_step_thresh {
                            pos_steps.push(c);
                        }
                        if diff_r < -self.depth_step_thresh && diff_r >= -self.max_depth_step_thresh
                        {
                            neg_steps.push(c);
                        }
                    }
                }
            } else {
                // Dual-texture blended edge detection:
                // Evaluates step on blended texture T_blend = (1 - b)*T_depth + b*T_intensity
                let cd = self.contrast_depth.max(1.0);
                let ci = self.contrast_intensity.max(0.1);

                let min_step_d = self.depth_step_thresh / cd;
                let max_step_d = self.max_depth_step_thresh / cd;
                let min_step_i = (self.depth_step_thresh * 2.0).clamp(0.05, 0.40);
                let max_step_i = 1.50;

                let min_thresh = inv_b * min_step_d + b * min_step_i;
                let max_thresh = inv_b * max_step_d + b * max_step_i;

                for c in 0..w - 1 {
                    let d0 = r_row[c];
                    let d1 = r_row[c + 1];
                    if d0 <= 0.1 && d1 <= 0.1 {
                        continue;
                    }

                    // Void-aware edge detection (handles far-field ground dropouts where reflective rails are flanked by void)
                    if d0 <= 0.1 && d1 > 0.1 {
                        let td1 = (d1 / cd).clamp(0.0, 1.0);
                        let ti1 = (frame.intensity[row_offset + c + 1] / ci).clamp(0.0, 1.0);
                        let step_mag = inv_b * td1 + b * ti1;
                        if step_mag >= min_thresh.min(0.06) {
                            pos_steps.push(c + 1);
                        }
                    } else if d0 > 0.1 && d1 <= 0.1 {
                        let td0 = (d0 / cd).clamp(0.0, 1.0);
                        let ti0 = (frame.intensity[row_offset + c] / ci).clamp(0.0, 1.0);
                        let step_mag = inv_b * td0 + b * ti0;
                        if step_mag >= min_thresh.min(0.06) {
                            neg_steps.push(c);
                        }
                    } else {
                        let td0 = (d0 / cd).clamp(0.0, 1.0);
                        let td1 = (d1 / cd).clamp(0.0, 1.0);

                        let i0 = frame.intensity[row_offset + c];
                        let i1 = frame.intensity[row_offset + c + 1];
                        let ti0 = (i0 / ci).clamp(0.0, 1.0);
                        let ti1 = (i1 / ci).clamp(0.0, 1.0);

                        let t0 = inv_b * td0 + b * ti0;
                        let t1 = inv_b * td1 + b * ti1;
                        let diff_t = t1 - t0;

                        if diff_t > min_thresh && diff_t <= max_thresh {
                            pos_steps.push(c);
                        }
                        if diff_t < -min_thresh && diff_t >= -max_thresh {
                            neg_steps.push(c);
                        }
                    }
                }
            }

            let mut pairs = Vec::new();
            for &p in &pos_steps {
                for &n in &neg_steps {
                    if n > p {
                        let col_l = p;
                        let col_r = (n + 1).min(w - 1);

                        let idx_l = row_offset + col_l;
                        let idx_r = row_offset + col_r;

                        // Прямой запрос точек по их координатам на 2D плоскости (row, col)
                        let (xl, yl, zl) = self.get_point_xyz(frame, cloud, row, col_l);
                        let (xr, yr, zr) = self.get_point_xyz(frame, cloud, row, col_r);

                        let dx = xr - xl;
                        let dy = yr - yl;
                        let cz = self.obstacle_config.upward_curvature;
                        let zl_real = zl - cz * xl * xl;
                        let zr_real = zr - cz * xr * xr;
                        let dz = zr_real - zl_real;
                        let gauge = (dx * dx + dy * dy + dz * dz).sqrt();
                        let h_diff = dz.abs();
                        let x_diff = dx.abs();

                        let xm = 0.5 * (xl + xr);
                        let ym = 0.5 * (yl + yr);
                        let zm = 0.5 * (zl + zr);
                        let zm_real = zm - cz * xm * xm;

                        // Исключаем точки выше уровня рельсов (провода контактной сети и т.п.)
                        // При подъеме пути в гору или тоннель zm_real поднимается, поэтому допускаем реальную высоту рельсов до +2.5 м
                        if zm_real > 2.5 {
                            continue;
                        }

                        // Адаптивные к дальности допуски: с ростом глубины (xm > 15m) шаг лучей лидара
                        // в метрах увеличивается, а кривизна пути создает естественный сдвиг по X между рельсами.
                        let tol_gauge =
                            (0.04 + 0.0018 * xm.min(15.0) + 0.0035 * (xm - 15.0).max(0.0))
                                .min(0.28);
                        let min_g =
                            (self.min_gauge - tol_gauge).min(self.nominal_gauge - tol_gauge);
                        let max_g =
                            (self.max_gauge + tol_gauge).max(self.nominal_gauge + tol_gauge);
                        let h_tol =
                            (0.05 + 0.0025 * xm.min(15.0) + 0.005 * (xm - 15.0).max(0.0)).min(0.45);
                        let x_tol =
                            (0.35 + 0.035 * xm.min(15.0) + 0.05 * (xm - 15.0).max(0.0)).min(4.5);

                        if gauge >= min_g && gauge <= max_g && h_diff < h_tol && x_diff < x_tol {
                            if let Some(pxc) = prev_x_center {
                                if xm < pxc - 2.5 {
                                    continue;
                                }
                            }

                            let (il, ir) = if !frame.intensity.is_empty() {
                                (frame.intensity[idx_l], frame.intensity[idx_r])
                            } else {
                                (0.0, 0.0)
                            };

                            pairs.push(RailPoint {
                                row,
                                col_left: col_l,
                                col_right: col_r,
                                x_left: xl,
                                y_left: yl,
                                z_left: zl,
                                x_right: xr,
                                y_right: yr,
                                z_right: zr,
                                x_center: xm,
                                y_center: ym,
                                z_center: zm,
                                gauge,
                                intensity_left: il,
                                intensity_right: ir,
                            });
                        }
                    }
                }
            }

            if pairs.is_empty() {
                if row == 0 {
                    break;
                }
                row -= 1;
                continue;
            }

            // Prioritize continuity from previous scanline
            if let (Some(pyc), Some(pyl), Some(pyr)) = (prev_y_center, prev_y_left, prev_y_right) {
                pairs.sort_by(|a, b_pair| {
                    let mut cost_a = (
                        (a.y_center - pyc).abs(),
                        (a.y_right - pyr).abs(),
                        (a.y_left - pyl).abs(),
                    );
                    let mut cost_b = (
                        (b_pair.y_center - pyc).abs(),
                        (b_pair.y_right - pyr).abs(),
                        (b_pair.y_left - pyl).abs(),
                    );
                    if b > 0.0 && has_intensity {
                        let ci = self.contrast_intensity.max(0.1);
                        let pen_a = 0.5 * (a.intensity_left + a.intensity_right) / ci * 0.1 * b;
                        let pen_b =
                            0.5 * (b_pair.intensity_left + b_pair.intensity_right) / ci * 0.1 * b;
                        cost_a.0 += pen_a;
                        cost_b.0 += pen_b;
                    }
                    cost_a
                        .0
                        .partial_cmp(&cost_b.0)
                        .unwrap_or(std::cmp::Ordering::Equal)
                        .then_with(|| {
                            cost_a
                                .1
                                .partial_cmp(&cost_b.1)
                                .unwrap_or(std::cmp::Ordering::Equal)
                        })
                        .then_with(|| {
                            cost_a
                                .2
                                .partial_cmp(&cost_b.2)
                                .unwrap_or(std::cmp::Ordering::Equal)
                        })
                });
            } else {
                pairs.sort_by(|a, b_pair| {
                    let mut cost_a = (
                        (a.gauge - self.nominal_gauge).abs(),
                        (a.x_right - a.x_left).abs(),
                        (a.z_left - a.z_right).abs(),
                    );
                    let mut cost_b = (
                        (b_pair.gauge - self.nominal_gauge).abs(),
                        (b_pair.x_right - b_pair.x_left).abs(),
                        (b_pair.z_left - b_pair.z_right).abs(),
                    );
                    if b > 0.0 && has_intensity {
                        let ci = self.contrast_intensity.max(0.1);
                        let pen_a = 0.5 * (a.intensity_left + a.intensity_right) / ci * 0.05 * b;
                        let pen_b =
                            0.5 * (b_pair.intensity_left + b_pair.intensity_right) / ci * 0.05 * b;
                        cost_a.0 += pen_a;
                        cost_b.0 += pen_b;
                    }
                    cost_a
                        .0
                        .partial_cmp(&cost_b.0)
                        .unwrap_or(std::cmp::Ordering::Equal)
                        .then_with(|| {
                            cost_a
                                .1
                                .partial_cmp(&cost_b.1)
                                .unwrap_or(std::cmp::Ordering::Equal)
                        })
                        .then_with(|| {
                            cost_a
                                .2
                                .partial_cmp(&cost_b.2)
                                .unwrap_or(std::cmp::Ordering::Equal)
                        })
                });
            }

            let best = &pairs[0];

            let row_gap = if let Some(lr) = last_detected_row {
                (lr - row) as f32
            } else {
                1.0
            };
            let gap_scale = 1.0 + 0.15 * (row_gap - 1.0);
            let max_lat = ((self.max_lateral_jump + 0.012 * best.x_center) * gap_scale).min(1.20);
            let max_lat_rail =
                ((self.max_lateral_rail_jump + 0.008 * best.x_center) * gap_scale).min(0.80);

            let lateral_jump = if let Some(pyc) = prev_y_center {
                (best.y_center - pyc).abs()
            } else {
                best.y_center.abs()
            };

            // Reject sudden lateral discontinuity of center
            if prev_y_center.is_some() && lateral_jump > max_lat {
                if row == 0 {
                    break;
                }
                row -= 1;
                continue;
            }

            // Reject sudden lateral discontinuity of left rail
            if let Some(pyl) = prev_y_left {
                let left_lateral_jump = (best.y_left - pyl).abs();
                if left_lateral_jump > max_lat_rail {
                    if row == 0 {
                        break;
                    }
                    row -= 1;
                    continue;
                }
            }

            // Reject sudden lateral discontinuity of right rail
            if let Some(pyr) = prev_y_right {
                let right_lateral_jump = (best.y_right - pyr).abs();
                if right_lateral_jump > max_lat_rail {
                    if row == 0 {
                        break;
                    }
                    row -= 1;
                    continue;
                }
            }

            prev_x_center = Some(best.x_center);
            prev_y_center = Some(best.y_center);
            prev_y_left = Some(best.y_left);
            prev_y_right = Some(best.y_right);
            last_detected_row = Some(row);

            candidates.push(best.clone());

            if row == 0 {
                break;
            }
            row -= 1;
        }

        // Require a minimum number of valid scanlines
        if candidates.len() < 6 {
            return None;
        }

        // Extract coordinate arrays
        let cz = self.obstacle_config.upward_curvature;
        let mut xm: Vec<f32> = candidates.iter().map(|pt| pt.x_center).collect();
        let mut ym: Vec<f32> = candidates.iter().map(|pt| pt.y_center).collect();
        let mut zm_real: Vec<f32> = candidates
            .iter()
            .map(|pt| pt.z_center - cz * pt.x_center * pt.x_center)
            .collect();
        let mut gauges: Vec<f32> = candidates.iter().map(|pt| pt.gauge).collect();
        gauges.sort_by(|a, b| a.partial_cmp(b).unwrap_or(std::cmp::Ordering::Equal));
        let median_gauge = if gauges.len() % 2 == 1 {
            gauges[gauges.len() / 2]
        } else {
            0.5 * (gauges[gauges.len() / 2 - 1] + gauges[gauges.len() / 2])
        };

        // If far anchor point feature is enabled, anchor the far horizon with previous frame's furthest verified point
        let mut far_anchor_active = false;
        if self.far_anchor_enabled {
            if let Some(anchor) = self.last_far_anchor {
                if anchor[0] > 15.0 {
                    // Inject anchor point with moderate weight (3 sample points) into least-squares fit
                    let z_lin = anchor[2] - cz * anchor[0] * anchor[0];
                    for _ in 0..3 {
                        xm.push(anchor[0]);
                        ym.push(anchor[1]);
                        zm_real.push(z_lin);
                    }
                    far_anchor_active = true;
                }
            }
        }

        // Fit quadratic curve for centerline: Y(X) = a*X^2 + b*X + c
        let raw_poly_y = polyfit2(&xm, &ym)?;
        // Fit elevation profile in REAL coordinates (linear slope): Z_real(X) = d*X + e
        let raw_poly_z = polyfit1(&xm, &zm_real)?;
        let raw_gauge = median_gauge;
        let raw_x_det_max = candidates
            .iter()
            .map(|pt| pt.x_center)
            .fold(f32::NEG_INFINITY, f32::max);

        // Reset history on non-consecutive jumps (gap > 2)
        if let Some(last_idx) = self.last_frame_idx {
            if last_idx.abs_diff(frame_idx) > 2 {
                self.history.clear();
                self.outlier_streak = 0;
                self.last_valid_poly_y = None;
                self.last_valid_poly_z = None;
                self.last_valid_gauge = None;
                self.last_valid_x_max = None;
                self.last_far_anchor = None;
                self.tracked_obstacles.clear();
            }
        }
        self.last_frame_idx = Some(frame_idx);

        let mut is_coasting = false;
        let mut accepted_poly_y = raw_poly_y;
        let mut accepted_poly_z = raw_poly_z;
        let mut accepted_gauge = raw_gauge;
        let mut accepted_x_max = raw_x_det_max;

        if self.temporal_jump_reject_enabled {
            if let Some(prev_poly_y) = self.last_valid_poly_y {
                // Check lateral deviation at multiple distances along track, extending up to the extrapolated tip
                let x_ext_end = (raw_x_det_max + self.extrapolate_m).max(raw_x_det_max);
                let test_xs = [5.0_f32, 15.0_f32, 30.0_f32, raw_x_det_max, x_ext_end];
                let mut max_dev = 0.0_f32;
                for &tx in &test_xs {
                    let y_raw = raw_poly_y[0] * tx * tx + raw_poly_y[1] * tx + raw_poly_y[2];
                    let y_prev = prev_poly_y[0] * tx * tx + prev_poly_y[1] * tx + prev_poly_y[2];
                    let dist_scale = 1.0 + 0.015 * (tx - 10.0).max(0.0);
                    let normalized_dev = (y_raw - y_prev).abs() / dist_scale;
                    max_dev = max_dev.max(normalized_dev);
                }

                if max_dev > self.max_interframe_jump_m {
                    self.outlier_streak += 1;
                    if self.outlier_streak <= self.max_outlier_frames {
                        // Reject outlier jump! Coast using previous valid trajectory
                        is_coasting = true;
                        accepted_poly_y = prev_poly_y;
                        if let Some(pz) = self.last_valid_poly_z {
                            accepted_poly_z = pz;
                        }
                        if let Some(g) = self.last_valid_gauge {
                            accepted_gauge = g;
                        }
                        if let Some(xm_max) = self.last_valid_x_max {
                            accepted_x_max = xm_max;
                        }
                    } else {
                        // Outlier streak exceeded threshold (e.g. genuine turn / switch): accept new trajectory
                        self.outlier_streak = 0;
                        self.last_valid_poly_y = Some(raw_poly_y);
                        self.last_valid_poly_z = Some(raw_poly_z);
                        self.last_valid_gauge = Some(raw_gauge);
                        self.last_valid_x_max = Some(raw_x_det_max);
                        self.last_far_anchor = None;
                    }
                } else {
                    // Valid continuous trajectory
                    self.outlier_streak = 0;
                    self.last_valid_poly_y = Some(raw_poly_y);
                    self.last_valid_poly_z = Some(raw_poly_z);
                    self.last_valid_gauge = Some(raw_gauge);
                    self.last_valid_x_max = Some(raw_x_det_max);
                }
            } else {
                // Initial frame
                self.outlier_streak = 0;
                self.last_valid_poly_y = Some(raw_poly_y);
                self.last_valid_poly_z = Some(raw_poly_z);
                self.last_valid_gauge = Some(raw_gauge);
                self.last_valid_x_max = Some(raw_x_det_max);
            }
        } else {
            self.outlier_streak = 0;
            self.last_valid_poly_y = Some(raw_poly_y);
            self.last_valid_poly_z = Some(raw_poly_z);
            self.last_valid_gauge = Some(raw_gauge);
            self.last_valid_x_max = Some(raw_x_det_max);
        }

        if !is_coasting {
            if self.history.len() >= self.smooth_n.max(1) {
                self.history.pop_front();
            }
            self.history.push_back(DetectionHistoryItem {
                poly_y: accepted_poly_y,
                poly_z: accepted_poly_z,
                gauge: accepted_gauge,
                x_det_max: accepted_x_max,
            });

            // Update far anchor at the tip of the extrapolated corridor on valid frame
            if self.far_anchor_enabled {
                let x_anchor = (accepted_x_max + self.extrapolate_m).max(accepted_x_max);
                if x_anchor > 10.0 {
                    let y_anchor = accepted_poly_y[0] * x_anchor * x_anchor
                        + accepted_poly_y[1] * x_anchor
                        + accepted_poly_y[2];
                    let z_anchor = accepted_poly_z[0] * x_anchor
                        + accepted_poly_z[1]
                        + cz * x_anchor * x_anchor;
                    self.last_far_anchor = Some([x_anchor, y_anchor, z_anchor]);
                }
            }
        }

        // Weighted moving average (when coasting, directly use accepted model)
        let (poly_y, poly_z, median_gauge, smooth_det_max) =
            if self.history.len() == 1 || is_coasting {
                (
                    accepted_poly_y,
                    accepted_poly_z,
                    accepted_gauge,
                    accepted_x_max,
                )
            } else {
                let mut total_w = 0.0_f64;
                let mut sum_y = [0.0_f64; 3];
                let mut sum_z = [0.0_f64; 2];
                let mut sum_gauge = 0.0_f64;
                let mut sum_xmax = 0.0_f64;

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

        // Radius of curvature: R = 1 / (2 * |a|)
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

        // Resample fine curve points in 3D (100 points across detected depth)
        let xm_min = xm.iter().cloned().fold(f32::INFINITY, f32::min);
        let x_min = 3.5_f32.max(xm_min);
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
            let t = (i as f32) / ((n_resample - 1) as f32);
            let xc = x_min + t * (x_max - x_min);
            let yc = a * xc * xc + b * xc + c;
            let zc = d * xc + e + cz * xc * xc;

            let dy_dx = 2.0 * a * xc + b;
            let theta = dy_dx.atan();

            let sin_t = theta.sin();
            let cos_t = theta.cos();

            x_curve.push(xc);
            y_center.push(yc);
            z_center.push(zc);

            x_left.push(xc + half_w * sin_t);
            y_left.push(yc - half_w * cos_t);

            x_right.push(xc - half_w * sin_t);
            y_right.push(yc + half_w * cos_t);
        }

        // Extrapolation curves (Purple/Magenta Polynomial, smoothed over last N frames)
        let mut x_ext = Vec::new();
        let mut y_ext = Vec::new();
        let mut z_ext = Vec::new();
        let mut x_ext_l = Vec::new();
        let mut y_ext_l = Vec::new();
        let mut x_ext_r = Vec::new();
        let mut y_ext_r = Vec::new();

        if self.extrapolate_m > 0.0 {
            let n_ext = 60;
            let x_start = smooth_det_max;
            let x_end = smooth_det_max + self.extrapolate_m;
            for i in 0..n_ext {
                let t = (i as f32) / ((n_ext - 1) as f32);
                let xe = x_start + t * (x_end - x_start);
                let ye = a * xe * xe + b * xe + c;
                let ze = d * xe + e + cz * xe * xe;

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

        let total_checked_rows = (row_start.abs_diff(row_end) + 1) as f32;
        let confidence = (candidates.len() as f32 / total_checked_rows).min(1.0);

        let has_intensity = !frame.intensity.is_empty();
        let (avg_i_l, avg_i_r) = if has_intensity && !candidates.is_empty() {
            let n = candidates.len() as f32;
            (
                candidates.iter().map(|p| p.intensity_left).sum::<f32>() / n,
                candidates.iter().map(|p| p.intensity_right).sum::<f32>() / n,
            )
        } else {
            (0.0, 0.0)
        };

        let t_rail_dur = t_start_rail.elapsed();

        let eff_max_distance = if self.obstacle_config.enabled {
            self.obstacle_config.effective_max_distance(turn_radius)
        } else {
            self.obstacle_config.max_distance_m
        };

        let t_start_obs = std::time::Instant::now();
        let mut obstacles = if self.obstacle_config.enabled {
            let mut obs_cfg = self.obstacle_config.clone();
            obs_cfg.max_distance_m = eff_max_distance;

            let (obs_frame, is_warped) = if let Some(raw) = raw_frame {
                (raw, false)
            } else {
                (frame, obs_cfg.upward_curvature.abs() > 1e-7)
            };
            self.detect_obstacles(
                obs_frame,
                cloud,
                &poly_y,
                &poly_z,
                median_gauge,
                &obs_cfg,
                is_warped,
            )
        } else {
            Vec::new()
        };

        if self.obstacle_config.enabled {
            self.track_and_classify_obstacles(&mut obstacles, frame_idx);
        }
        let t_obs_dur = t_start_obs.elapsed();

        let timing_rail_ms = t_rail_dur.as_secs_f32() * 1000.0;
        let timing_obstacles_ms = t_obs_dur.as_secs_f32() * 1000.0;
        let timing_total_ms = timing_rail_ms + timing_obstacles_ms;

        Some(DetectionResult {
            frame_idx,
            points: candidates,
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
            extrapolate_m: self.extrapolate_m,
            smooth_n: self.history.len(),
            x_ext,
            y_ext,
            z_ext,
            x_ext_l,
            y_ext_l,
            x_ext_r,
            y_ext_r,
            has_intensity,
            avg_intensity_left: avg_i_l,
            avg_intensity_right: avg_i_r,
            obstacles,
            clearance_width: self.obstacle_config.clearance_width,
            clearance_narrowing_width: self.obstacle_config.clearance_narrowing_width,
            clearance_narrowing_height: self.obstacle_config.clearance_narrowing_height,
            clearance_height_end_shift: self.obstacle_config.clearance_height_end_shift,
            clearance_start_offset: self.obstacle_config.clearance_start_offset,
            min_height_above_rail: self.obstacle_config.min_height_above_rail,
            max_height_above_rail: self.obstacle_config.max_height_above_rail,
            max_distance_m: eff_max_distance,
            upward_curvature: self.obstacle_config.upward_curvature,
            obstacle_enabled: self.obstacle_config.enabled,
            is_real_coordinates: false,
            is_coasting,
            outlier_streak: self.outlier_streak,
            far_anchor_active,
            timing_rail_ms,
            timing_obstacles_ms,
            timing_total_ms,
        })
    }

    /// Обнаруживает препятствия на путях и в зоне габарита приближения строений
    pub fn detect_obstacles(
        &self,
        frame: &RangeImage,
        cloud: Option<(&AppPointCloud, ProcessingQueue)>,
        poly_y: &[f32; 3],
        poly_z: &[f32; 2],
        gauge: f32,
        config: &ObstacleConfig,
        is_warped: bool,
    ) -> Vec<TrackObstacle> {
        if !config.enabled {
            return Vec::new();
        }

        let h = frame.height;
        let w = frame.width;
        let total = h * w;
        if total == 0 {
            return Vec::new();
        }

        let min_w = gauge.max(1.0).min(config.clearance_width);
        let nom_h = (config.max_height_above_rail - config.min_height_above_rail).max(0.1);
        let center_h = (config.min_height_above_rail + config.max_height_above_rail) * 0.5;
        let min_h_thickness = 0.30_f32.min(nom_h);
        let half_g = gauge * 0.5;
        let x_min = (2.0 + config.clearance_start_offset).max(0.1);
        let x_max = config.max_distance_m;

        let get_xyz_real = |row: usize, col: usize, r: f32| -> (f32, f32, f32) {
            let idx = row * w + col;
            if let Some((pc, queue)) = cloud {
                if let Some(&pt_idx) = frame.point_indices.get(idx) {
                    if pt_idx != crate::range_image::NO_POINT_INDEX
                        && (pt_idx as usize) < pc.len(queue)
                    {
                        let p_i = pt_idx as usize;
                        let px = pc.x[queue][p_i];
                        let py = pc.y[queue][p_i];
                        let pz = pc.z[queue][p_i];
                        if !crate::types::is_zero_point(px, py, pz) {
                            return (px, py, pz);
                        }
                    }
                }
            }
            let (x, y, z_frame) = self.geometry.row_col_range_to_xyz(row, col, r);
            let z_real = if is_warped {
                z_frame - config.upward_curvature * x * x
            } else {
                z_frame
            };
            (x, y, z_real)
        };

        let mut is_intrusion = vec![false; total];

        match config.mode {
            ObstacleDetectionMode::Boxcast3D => {
                // Способ 1: Прямой 3D бокскаст кинематического габарита вдоль аналитической кривой
                for row in 0..h {
                    let r_off = row * w;
                    for col in 0..w {
                        let r = frame.data[r_off + col];
                        if r < 0.5 || r > x_max * 1.5 {
                            continue;
                        }
                        let (x, y, z_real) = get_xyz_real(row, col, r);

                        let (xc, _theta, d_lat, z_surf_real) =
                            project_point_to_track(x, y, poly_y, poly_z);
                        if xc < x_min || xc > x_max {
                            continue;
                        }

                        let dx = (xc - x_min).max(0.0);
                        let cur_half_w = (config.clearance_width
                            - config.clearance_narrowing_width * dx)
                            .max(min_w)
                            * 0.5;
                        let cur_h =
                            (nom_h - config.clearance_narrowing_height * dx).max(min_h_thickness);
                        let range_x = (x_max - x_min).max(1.0);
                        let t_norm = (dx / range_x).min(2.0);
                        let h_shift = config.clearance_height_end_shift * t_norm * t_norm;
                        let cur_half_h = cur_h * 0.5;
                        let cur_min_h = center_h + h_shift - cur_half_h;
                        let cur_max_h = center_h + h_shift + cur_half_h;
                        let dz = z_real - z_surf_real;

                        if d_lat.abs() <= cur_half_w && dz >= cur_min_h && dz <= cur_max_h {
                            is_intrusion[r_off + col] = true;
                        }
                    }
                }
            }
            ObstacleDetectionMode::DepthMatrix2D => {
                // Способ 2: Матричный анализ перепадов дальности над полотном в 2D коридоре путей
                for row in 0..h {
                    let r_off = row * w;
                    for col in 0..w {
                        let r = frame.data[r_off + col];
                        if r < 0.5 || r > x_max * 1.5 {
                            continue;
                        }
                        let (x, y, z_real) = get_xyz_real(row, col, r);

                        let (xc, _theta, d_lat, z_surf_real) =
                            project_point_to_track(x, y, poly_y, poly_z);
                        if xc < x_min || xc > x_max {
                            continue;
                        }

                        let dx = (xc - x_min).max(0.0);
                        let cur_half_w = (config.clearance_width
                            - config.clearance_narrowing_width * dx)
                            .max(min_w)
                            * 0.5;
                        let cur_h =
                            (nom_h - config.clearance_narrowing_height * dx).max(min_h_thickness);
                        let range_x = (x_max - x_min).max(1.0);
                        let t_norm = (dx / range_x).min(2.0);
                        let h_shift = config.clearance_height_end_shift * t_norm * t_norm;
                        let cur_half_h = cur_h * 0.5;
                        let cur_min_h = center_h + h_shift - cur_half_h;
                        let cur_max_h = center_h + h_shift + cur_half_h;
                        if d_lat.abs() > cur_half_w {
                            continue;
                        }

                        let dz = z_real - z_surf_real;

                        let idx = r_off + col;
                        let dir_z = self.geometry.dir_z[idx];
                        let z_surf_ref = if is_warped {
                            z_surf_real + config.upward_curvature * xc * xc
                        } else {
                            z_surf_real
                        };
                        let r_ground = if dir_z < -0.01 {
                            z_surf_ref / dir_z
                        } else {
                            (x * x + y * y + z_surf_ref * z_surf_ref).sqrt()
                        };
                        let depth_diff = r_ground - r;

                        if depth_diff >= config.depth_diff_thresh
                            && dz >= cur_min_h
                            && dz <= cur_max_h
                        {
                            is_intrusion[r_off + col] = true;
                        }
                    }
                }
            }
            ObstacleDetectionMode::HybridGrid => {
                // Способ 3 (Гибридный, наиболее эффективный):
                // Точная 3D фильтрация по нормали к траектории пути с верификацией высотного габарита
                for row in 0..h {
                    let r_off = row * w;
                    for col in 0..w {
                        let r = frame.data[r_off + col];
                        if r < 0.5 || r > x_max * 1.5 {
                            continue;
                        }
                        let (x, y, z_real) = get_xyz_real(row, col, r);

                        let (xc, _theta, d_lat, z_surf_real) =
                            project_point_to_track(x, y, poly_y, poly_z);
                        if xc < x_min || xc > x_max {
                            continue;
                        }

                        let dx = (xc - x_min).max(0.0);
                        let cur_half_w = (config.clearance_width
                            - config.clearance_narrowing_width * dx)
                            .max(min_w)
                            * 0.5;
                        let cur_h =
                            (nom_h - config.clearance_narrowing_height * dx).max(min_h_thickness);
                        let range_x = (x_max - x_min).max(1.0);
                        let t_norm = (dx / range_x).min(2.0);
                        let h_shift = config.clearance_height_end_shift * t_norm * t_norm;
                        let cur_half_h = cur_h * 0.5;
                        let cur_min_h = center_h + h_shift - cur_half_h;
                        let cur_max_h = center_h + h_shift + cur_half_h;
                        let dz = z_real - z_surf_real;

                        if d_lat.abs() <= cur_half_w && dz >= cur_min_h && dz <= cur_max_h {
                            is_intrusion[r_off + col] = true;
                        }
                    }
                }
            }
        }

        // Кластеризация компонент связности (8-связный поиск с допуском разрывов до 1 строки и 2 колонок)
        let mut visited = vec![false; total];
        let mut obstacles = Vec::new();
        let mut obstacle_id = 1;

        for r_start in 0..h {
            for c_start in 0..w {
                let start_idx = r_start * w + c_start;
                if !is_intrusion[start_idx] || visited[start_idx] {
                    continue;
                }

                let mut cluster_cells = Vec::new();
                let mut queue = std::collections::VecDeque::new();
                queue.push_back((r_start, c_start));
                visited[start_idx] = true;

                while let Some((cr, cc)) = queue.pop_front() {
                    cluster_cells.push((cr, cc));
                    let r_curr = frame.data[cr * w + cc];

                    for dr in -1..=1 {
                        for dc in -2..=2 {
                            if dr == 0 && dc == 0 {
                                continue;
                            }
                            let nr = cr as isize + dr;
                            let nc = cc as isize + dc;
                            if nr >= 0 && (nr as usize) < h && nc >= 0 && (nc as usize) < w {
                                let n_idx = (nr as usize) * w + (nc as usize);
                                if is_intrusion[n_idx] && !visited[n_idx] {
                                    let r_next = frame.data[n_idx];
                                    let depth_ok = if config.cluster_depth_thresh > 0.0 {
                                        (r_next - r_curr).abs() <= config.cluster_depth_thresh
                                    } else {
                                        true
                                    };
                                    if depth_ok {
                                        visited[n_idx] = true;
                                        queue.push_back((nr as usize, nc as usize));
                                    }
                                }
                            }
                        }
                    }
                }

                if cluster_cells.len() < config.min_points {
                    continue;
                }

                // Вычисление 2D и 3D Bounding Box для сформированного кластера
                let mut col_min = usize::MAX;
                let mut col_max = 0;
                let mut row_min = usize::MAX;
                let mut row_max = 0;

                let mut min_x = f32::MAX;
                let mut max_x = f32::MIN;
                let mut min_y = f32::MAX;
                let mut max_y = f32::MIN;
                let mut min_z = f32::MAX;
                let mut max_z = f32::MIN;

                let mut min_track_dist = f32::MAX;
                let mut sum_lat_off = 0.0f32;
                let mut max_dz = 0.0f32;

                for &(r, c) in &cluster_cells {
                    col_min = col_min.min(c);
                    col_max = col_max.max(c);
                    row_min = row_min.min(r);
                    row_max = row_max.max(r);

                    let rng = frame.data[r * w + c];
                    let (x, y, z_real) = get_xyz_real(r, c, rng);

                    min_x = min_x.min(x);
                    max_x = max_x.max(x);
                    min_y = min_y.min(y);
                    max_y = max_y.max(y);
                    min_z = min_z.min(z_real);
                    max_z = max_z.max(z_real);

                    let (xc, _theta, d_lat, z_surf_real) =
                        project_point_to_track(x, y, poly_y, poly_z);

                    min_track_dist = min_track_dist.min(xc);
                    sum_lat_off += d_lat;
                    max_dz = max_dz.max(z_real - z_surf_real);
                }

                let n_pts = cluster_cells.len() as f32;
                let mean_lat_off = sum_lat_off / n_pts;

                // Препятствие в колее, если проекция внутри колеи (половина колеи + 0.10м буфер)
                let in_gauge = mean_lat_off.abs() <= (half_g + 0.10);
                let is_critical = in_gauge;
                let status = if in_gauge {
                    ObstacleStatus::Critical
                } else {
                    ObstacleStatus::ClearanceWarning
                };

                let size_m = [
                    (max_x - min_x).max(0.1),
                    (max_y - min_y).max(0.1),
                    (max_z - min_z).max(0.1),
                ];

                let bbox_2d = if !is_warped && config.upward_curvature.abs() > 1e-7 {
                    // Проецируем 3D габарит кластера в искривленную систему координат для отображения в warped RangeImage
                    let mut c_min = isize::MAX;
                    let mut c_max = isize::MIN;
                    let mut r_min = isize::MAX;
                    let mut r_max = isize::MIN;
                    for &px in &[min_x, max_x] {
                        for &py in &[min_y, max_y] {
                            for &pz in &[min_z, max_z] {
                                let pz_bent = pz + config.upward_curvature * px * px;
                                let (pr, pc) = self.geometry.xyz_to_row_col(px, py, pz_bent);
                                if pr >= 0 && pc >= 0 {
                                    r_min = r_min.min(pr);
                                    r_max = r_max.max(pr);
                                    c_min = c_min.min(pc);
                                    c_max = c_max.max(pc);
                                }
                            }
                        }
                    }
                    if c_min <= c_max && r_min <= r_max {
                        [
                            (c_min as usize).min(w - 1),
                            (r_min as usize).min(h - 1),
                            (c_max as usize).min(w - 1),
                            (r_max as usize).min(h - 1),
                        ]
                    } else {
                        [col_min, row_min, col_max, row_max]
                    }
                } else {
                    [col_min, row_min, col_max, row_max]
                };

                obstacles.push(TrackObstacle {
                    id: obstacle_id,
                    distance_along_track: min_track_dist,
                    lateral_offset: mean_lat_off,
                    height_above_rail: max_dz,
                    bbox_3d_min: [min_x, min_y, min_z],
                    bbox_3d_max: [max_x, max_y, max_z],
                    bbox_2d,
                    points_count: cluster_cells.len(),
                    is_critical,
                    size_m,
                    status,
                    hits: 1,
                    in_gauge,
                });

                obstacle_id += 1;
            }
        }

        obstacles.sort_by(|o1, o2| {
            o1.distance_along_track
                .partial_cmp(&o2.distance_along_track)
                .unwrap_or(std::cmp::Ordering::Equal)
        });
        obstacles
    }

    /// Применяет временной трекинг препятствий:
    /// Сопоставляет детекции текущего кадра с активными треками предыдущих кадров.
    /// Требует повторений (подряд или через одно) для подтверждения `Critical`,
    /// а одиночные детекции классифицирует как `Unlikely` (серая обводка).
    pub fn track_and_classify_obstacles(
        &mut self,
        obstacles: &mut [TrackObstacle],
        frame_idx: usize,
    ) {
        if !self.obstacle_config.temporal_tracking_enabled {
            // Если временной трекинг выключен, классифицируем напрямую по нахождению в колее
            for o in obstacles.iter_mut() {
                o.hits = 1;
                if o.in_gauge {
                    o.is_critical = true;
                    o.status = ObstacleStatus::Critical;
                } else {
                    o.is_critical = false;
                    o.status = ObstacleStatus::ClearanceWarning;
                }
            }
            return;
        }

        // Проверяем скачок кадров (например, перемотка или пауза)
        if let Some(last_idx) = self.last_frame_idx {
            if last_idx.abs_diff(frame_idx) > (self.obstacle_config.max_missed_frames + 2) {
                self.tracked_obstacles.clear();
            }
        }

        let mut matched_track_indices = vec![false; self.tracked_obstacles.len()];
        let mut new_tracks = Vec::new();

        for o in obstacles.iter_mut() {
            let o_center = [
                0.5 * (o.bbox_3d_min[0] + o.bbox_3d_max[0]),
                0.5 * (o.bbox_3d_min[1] + o.bbox_3d_max[1]),
                0.5 * (o.bbox_3d_min[2] + o.bbox_3d_max[2]),
            ];

            let mut best_match: Option<(usize, f32)> = None;

            for (t_idx, tracked) in self.tracked_obstacles.iter().enumerate() {
                if matched_track_indices[t_idx] {
                    continue;
                }

                let frame_gap = frame_idx.saturating_sub(tracked.last_seen_frame).max(1);
                if frame_gap > self.obstacle_config.max_missed_frames + 1 {
                    continue;
                }

                // Допустимый сдвиг по дистанции масштабируется разрывом кадров (при "через одно")
                let max_d = self.obstacle_config.track_match_dist_m * (frame_gap as f32);
                let dist_diff = (o.distance_along_track - tracked.distance_along_track).abs();
                let lat_diff = (o.lateral_offset - tracked.lateral_offset).abs();

                if dist_diff <= max_d && lat_diff <= self.obstacle_config.track_match_lateral_m {
                    let cost = dist_diff + lat_diff * 2.0;
                    if let Some((_, best_cost)) = best_match {
                        if cost < best_cost {
                            best_match = Some((t_idx, cost));
                        }
                    } else {
                        best_match = Some((t_idx, cost));
                    }
                }
            }

            if let Some((t_idx, _)) = best_match {
                matched_track_indices[t_idx] = true;
                let tracked = &mut self.tracked_obstacles[t_idx];
                tracked.missed_frames = 0;
                tracked.hits = (tracked.hits + 1).min(100);
                tracked.distance_along_track = o.distance_along_track;
                tracked.lateral_offset = o.lateral_offset;
                tracked.height_above_rail = o.height_above_rail;
                tracked.center_3d = o_center;
                tracked.size_m = o.size_m;
                tracked.last_seen_frame = frame_idx;
                tracked.in_gauge = o.in_gauge;

                o.id = tracked.id;
                o.hits = tracked.hits;

                if tracked.hits >= self.obstacle_config.min_hits_for_critical {
                    if o.in_gauge {
                        o.is_critical = true;
                        o.status = ObstacleStatus::Critical;
                    } else {
                        o.is_critical = false;
                        o.status = ObstacleStatus::ClearanceWarning;
                    }
                } else {
                    o.is_critical = false;
                    o.status = ObstacleStatus::Unlikely;
                }
            } else {
                // Новое препятствие (1-я детекция)
                let new_id = self.next_obstacle_id;
                self.next_obstacle_id += 1;

                new_tracks.push(TrackedObstacleState {
                    id: new_id,
                    distance_along_track: o.distance_along_track,
                    lateral_offset: o.lateral_offset,
                    height_above_rail: o.height_above_rail,
                    center_3d: o_center,
                    size_m: o.size_m,
                    in_gauge: o.in_gauge,
                    last_seen_frame: frame_idx,
                    missed_frames: 0,
                    hits: 1,
                });

                o.id = new_id;
                o.hits = 1;

                if 1 >= self.obstacle_config.min_hits_for_critical {
                    if o.in_gauge {
                        o.is_critical = true;
                        o.status = ObstacleStatus::Critical;
                    } else {
                        o.is_critical = false;
                        o.status = ObstacleStatus::ClearanceWarning;
                    }
                } else {
                    o.is_critical = false;
                    o.status = ObstacleStatus::Unlikely;
                }
            }
        }

        // Обновляем пропущенные треки и удаляем устаревшие
        for (t_idx, matched) in matched_track_indices.iter().enumerate() {
            if !matched {
                self.tracked_obstacles[t_idx].missed_frames += 1;
            }
        }
        self.tracked_obstacles
            .retain(|t| t.missed_frames <= self.obstacle_config.max_missed_frames);

        // Добавляем новые треки, обнаруженные в этом кадре
        self.tracked_obstacles.extend(new_tracks);
    }
}

/// Least-squares quadratic polynomial fitting: Y(X) = a*X^2 + b*X + c
/// Solves normal equations (A^T A) * beta = A^T Y via Cramer's rule.
pub fn polyfit2(x: &[f32], y: &[f32]) -> Option<[f32; 3]> {
    let n = x.len();
    if n < 3 || n != y.len() {
        return None;
    }

    let n_f = n as f64;
    let mut s1 = 0.0_f64;
    let mut s2 = 0.0_f64;
    let mut s3 = 0.0_f64;
    let mut s4 = 0.0_f64;

    let mut r0 = 0.0_f64;
    let mut r1 = 0.0_f64;
    let mut r2 = 0.0_f64;

    for i in 0..n {
        let xi = x[i] as f64;
        let yi = y[i] as f64;
        let xi2 = xi * xi;
        let xi3 = xi2 * xi;
        let xi4 = xi2 * xi2;

        s1 += xi;
        s2 += xi2;
        s3 += xi3;
        s4 += xi4;

        r0 += yi;
        r1 += xi * yi;
        r2 += xi2 * yi;
    }

    // Matrix:
    // [s4, s3, s2] [a]   [r2]
    // [s3, s2, s1] [b] = [r1]
    // [s2, s1, n ] [c]   [r0]
    let det = s4 * (s2 * n_f - s1 * s1) - s3 * (s3 * n_f - s1 * s2) + s2 * (s3 * s1 - s2 * s2);

    if det.abs() < 1e-12 {
        return None;
    }

    let det_a = r2 * (s2 * n_f - s1 * s1) - s3 * (r1 * n_f - s1 * r0) + s2 * (r1 * s1 - s2 * r0);
    let det_b = s4 * (r1 * n_f - s1 * r0) - r2 * (s3 * n_f - s1 * s2) + s2 * (s3 * r0 - r1 * s2);
    let det_c = s4 * (s2 * r0 - r1 * s1) - s3 * (s3 * r0 - r1 * s2) + r2 * (s3 * s1 - s2 * s2);

    Some([
        (det_a / det) as f32,
        (det_b / det) as f32,
        (det_c / det) as f32,
    ])
}

/// Least-squares linear polynomial fitting: Z(X) = d*X + e
/// Solves normal equations for degree 1.
pub fn polyfit1(x: &[f32], z: &[f32]) -> Option<[f32; 2]> {
    let n = x.len();
    if n < 2 || n != z.len() {
        return None;
    }

    let n_f = n as f64;
    let mut sum_x = 0.0_f64;
    let mut sum_x2 = 0.0_f64;
    let mut sum_z = 0.0_f64;
    let mut sum_xz = 0.0_f64;

    for i in 0..n {
        let xi = x[i] as f64;
        let zi = z[i] as f64;
        sum_x += xi;
        sum_x2 += xi * xi;
        sum_z += zi;
        sum_xz += xi * zi;
    }

    let det = n_f * sum_x2 - sum_x * sum_x;
    if det.abs() < 1e-12 {
        return None;
    }

    let d = (n_f * sum_xz - sum_x * sum_z) / det;
    let e = (sum_x2 * sum_z - sum_x * sum_xz) / det;

    Some([d as f32, e as f32])
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_clearance_height_end_shift() {
        let poly_y = [0.0_f32, 0.0_f32, 0.0_f32];
        let poly_z = [0.0_f32, -1.0_f32]; // Flat track at z = -1.0

        let res = DetectionResult {
            frame_idx: 0,
            points: Vec::new(),
            gauge: 1.52,
            curvature_a: 0.0,
            heading_b: 0.0,
            offset_c: 0.0,
            turn_radius: 99999.0,
            turn_direction: "STRAIGHT".to_string(),
            lateral_shift_15m: 0.0,
            poly_y,
            poly_z,
            x_curve: Vec::new(),
            y_center: Vec::new(),
            z_center: Vec::new(),
            x_left: Vec::new(),
            y_left: Vec::new(),
            x_right: Vec::new(),
            y_right: Vec::new(),
            confidence: 1.0,
            extrapolate_m: 0.0,
            smooth_n: 1,
            x_ext: Vec::new(),
            y_ext: Vec::new(),
            z_ext: Vec::new(),
            x_ext_l: Vec::new(),
            y_ext_l: Vec::new(),
            x_ext_r: Vec::new(),
            y_ext_r: Vec::new(),
            has_intensity: false,
            avg_intensity_left: 0.0,
            avg_intensity_right: 0.0,
            obstacles: Vec::new(),
            clearance_width: 2.50,
            clearance_narrowing_width: 0.0,
            clearance_narrowing_height: 0.0,
            clearance_height_end_shift: 0.50, // +0.50m shift at far station
            clearance_start_offset: 0.0,
            min_height_above_rail: 0.15,
            max_height_above_rail: 3.05,
            max_distance_m: 52.0,
            upward_curvature: 0.0,
            obstacle_enabled: true,
            is_real_coordinates: true,
            is_coasting: false,
            outlier_streak: 0,
            far_anchor_active: false,
            timing_rail_ms: 0.0,
            timing_obstacles_ms: 0.0,
            timing_total_ms: 0.0,
        };

        let strips = res.shapecast_wireframe_3d();
        assert!(!strips.is_empty());

        let line_bl = &strips[0];
        let line_tl = &strips[2];

        // Near station (x = 2.0m, t = 0.0)
        let pt_near_bl = line_bl.first().unwrap();
        let pt_near_tl = line_tl.first().unwrap();
        // Near bottom: z_surf (-1.0) + min_h (0.15) = -0.85
        assert!(
            (pt_near_bl[2] - (-0.85)).abs() < 1e-3,
            "Near bottom should be -0.85, got {}",
            pt_near_bl[2]
        );
        // Near top: z_surf (-1.0) + max_h (3.05) = +2.05
        assert!(
            (pt_near_tl[2] - 2.05).abs() < 1e-3,
            "Near top should be 2.05, got {}",
            pt_near_tl[2]
        );

        // Far station (x = 52.0m, t = 1.0)
        let pt_far_bl = line_bl.last().unwrap();
        let pt_far_tl = line_tl.last().unwrap();
        // Far bottom: -0.85 + 0.50 = -0.35
        assert!(
            (pt_far_bl[2] - (-0.35)).abs() < 1e-3,
            "Far bottom should be lifted by 0.50m to -0.35, got {}",
            pt_far_bl[2]
        );
        // Far top: 2.05 + 0.50 = 2.55
        assert!(
            (pt_far_tl[2] - 2.55).abs() < 1e-3,
            "Far top should be lifted by 0.50m to 2.55, got {}",
            pt_far_tl[2]
        );
    }

    #[test]
    fn test_clearance_start_offset() {
        let poly_y = [0.0_f32, 0.0_f32, 0.0_f32];
        let poly_z = [0.0_f32, 0.0_f32];

        let res = DetectionResult {
            frame_idx: 0,
            points: Vec::new(),
            gauge: 1.52,
            curvature_a: 0.0,
            heading_b: 0.0,
            offset_c: 0.0,
            turn_radius: 99999.0,
            turn_direction: "STRAIGHT".to_string(),
            lateral_shift_15m: 0.0,
            poly_y,
            poly_z,
            x_curve: Vec::new(),
            y_center: Vec::new(),
            z_center: Vec::new(),
            x_left: Vec::new(),
            y_left: Vec::new(),
            x_right: Vec::new(),
            y_right: Vec::new(),
            confidence: 1.0,
            extrapolate_m: 0.0,
            smooth_n: 1,
            x_ext: Vec::new(),
            y_ext: Vec::new(),
            z_ext: Vec::new(),
            x_ext_l: Vec::new(),
            y_ext_l: Vec::new(),
            x_ext_r: Vec::new(),
            y_ext_r: Vec::new(),
            has_intensity: false,
            avg_intensity_left: 0.0,
            avg_intensity_right: 0.0,
            obstacles: Vec::new(),
            clearance_width: 2.40,
            clearance_narrowing_width: 0.0,
            clearance_narrowing_height: 0.0,
            clearance_height_end_shift: 0.0,
            clearance_start_offset: 3.5, // Сдвиг начала на 3.5м вперед (2.0 + 3.5 = 5.5м)
            min_height_above_rail: 0.15,
            max_height_above_rail: 3.0,
            max_distance_m: 50.0,
            upward_curvature: 0.0,
            obstacle_enabled: true,
            is_real_coordinates: true,
            is_coasting: false,
            outlier_streak: 0,
            far_anchor_active: false,
            timing_rail_ms: 0.0,
            timing_obstacles_ms: 0.0,
            timing_total_ms: 0.0,
        };

        let strips = res.shapecast_wireframe_3d();
        assert!(!strips.is_empty());
        let line_bl = &strips[0];
        let pt_near = line_bl.first().unwrap();
        // Начальная плоскость шейпкаста должна начинаться точно с x = 2.0 + 3.5 = 5.5м
        assert!(
            (pt_near[0] - 5.5).abs() < 1e-2,
            "Shapecast wireframe should start at x=5.5m with offset=3.5m, got {}",
            pt_near[0]
        );
    }

    #[test]
    fn test_turn_compression() {
        let mut cfg = ObstacleConfig::default();
        cfg.max_distance_m = 60.0;
        cfg.turn_compression_enabled = true;
        cfg.turn_radius_min = 200.0;
        cfg.turn_radius_max = 1000.0;
        cfg.turn_compression_min_scale = 0.70;
        cfg.turn_compression_max_scale = 1.00;

        // Straight track (large radius): scale should be 1.0, distance 60.0m
        let scale_straight = cfg.compute_turn_compression_scale(99999.0);
        assert!((scale_straight - 1.0).abs() < 1e-4);
        let eff_dist_straight = cfg.effective_max_distance(99999.0);
        assert!((eff_dist_straight - 60.0).abs() < 1e-4);

        // Max compression at sharp turn (radius <= 200.0): scale should be 0.7, distance 42.0m
        let scale_sharp = cfg.compute_turn_compression_scale(200.0);
        assert!((scale_sharp - 0.70).abs() < 1e-4);
        let eff_dist_sharp = cfg.effective_max_distance(200.0);
        assert!((eff_dist_sharp - 42.0).abs() < 1e-4);

        // Even sharper (radius = 100.0): clamped to 0.70
        let scale_very_sharp = cfg.compute_turn_compression_scale(100.0);
        assert!((scale_very_sharp - 0.70).abs() < 1e-4);
        let eff_dist_very_sharp = cfg.effective_max_distance(100.0);
        assert!((eff_dist_very_sharp - 42.0).abs() < 1e-4);

        // Mid turn (radius = 600.0): scale 0.85, distance 51.0m
        let scale_mid = cfg.compute_turn_compression_scale(600.0);
        assert!((scale_mid - 0.85).abs() < 1e-4);
        let eff_dist_mid = cfg.effective_max_distance(600.0);
        assert!((eff_dist_mid - 51.0).abs() < 1e-4);

        // Disabled turn compression: always 1.0 and 60.0m
        cfg.turn_compression_enabled = false;
        let scale_disabled = cfg.compute_turn_compression_scale(200.0);
        assert!((scale_disabled - 1.0).abs() < 1e-4);
        let eff_dist_disabled = cfg.effective_max_distance(200.0);
        assert!((eff_dist_disabled - 60.0).abs() < 1e-4);
    }
}
