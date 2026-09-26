//! rail_detection.rs — Railway track detection for 3D LiDAR Range Images
//!
//! Port of Python implementation (`dev_pyrails/detector.py` and `dev_pyrails/geometry.py`).
//! Detects left/right rails from range discontinuities, verifies gauge and height consistency,
//! tracks scanline continuity, and fits 3D trajectory curves.

use crate::range_image::RangeImage;

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

    /// Converts (row, col, range) to (X, Y, Z) in meters.
    #[inline(always)]
    pub fn row_col_range_to_xyz(&self, row: usize, col: usize, r: f32) -> (f32, f32, f32) {
        let idx = row * self.width + col;
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
    pub obstacle_enabled: bool,
    /// Флаг истинных (восстановленных) координат в реальном физическом пространстве
    pub is_real_coordinates: bool,
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
        for o in &mut self.obstacles {
            let x = 0.5 * (o.bbox_3d_min[0] + o.bbox_3d_max[0]);
            let dz = cz * x * x;
            o.bbox_3d_min[2] -= dz;
            o.bbox_3d_max[2] -= dz;
        }
        self.is_real_coordinates = true;
    }

    /// Возвращает цвет RGB для шейпкаста: Красный при критическом препятствии на колее,
    /// Янтарный при препятствии в габарите, Бирюзовый/Циан при свободном пути.
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

    /// Генерирует 3D полилинии (wireframe strips) для визуализации шейпкаста габарита приближения:
    /// Коридор шейпкаста строится непосредственно вдоль аналитической кривой пути
    /// от x_min (2.0 м перед лидаром) до x_max = max_distance_m с квадратичным подъемом вверх по глубине:
    /// - 4 продольные грани туннеля (нижняя левая/правая, верхняя левая/правая)
    /// - Поперечные прямоугольные рамки (шпангоуты) с шагом ~4 м вдоль кривой
    /// - Торцевые диагональные крестовины (порталы входа и выхода)
    pub fn shapecast_wireframe_3d(&self) -> Vec<Vec<[f32; 3]>> {
        if !self.obstacle_enabled || self.max_distance_m <= 2.0 || self.clearance_width <= 0.0 {
            return Vec::new();
        }

        let x_min = 2.0_f32;
        let x_max = self.max_distance_m;
        if x_max <= x_min {
            return Vec::new();
        }

        // Дискретизация вдоль аналитической траектории пути с шагом 0.5 м
        let step_m = 0.5_f32;
        let num_steps = ((x_max - x_min) / step_m).round().max(10.0) as usize;

        let half_w = self.clearance_width * 0.5;
        let mut line_bl = Vec::with_capacity(num_steps + 1);
        let mut line_br = Vec::with_capacity(num_steps + 1);
        let mut line_tl = Vec::with_capacity(num_steps + 1);
        let mut line_tr = Vec::with_capacity(num_steps + 1);
        let mut frames = Vec::new();

        // Поперечные рамки-шпангоуты примерно каждые 4 метра
        let hoop_dist_m = 4.0_f32;
        let hoop_step = ((hoop_dist_m / step_m).round().max(1.0)) as usize;

        for i in 0..=num_steps {
            let t = (i as f32) / (num_steps as f32);
            let x = x_min + t * (x_max - x_min);

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

            let zb = z_surf + self.min_height_above_rail;
            let zt = z_surf + self.max_height_above_rail;

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
        }
    }
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
    /// Препятствие находится непосредственно в колее (угроза схода / удара)
    pub is_critical: bool,
    /// Приблизительные размеры объекта [длина, ширина, высота] в метрах
    pub size_m: [f32; 3],
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
}

impl RailTrackDetector {
    pub fn new(geometry: LidarGeometry) -> Self {
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
        }
    }

    /// Clears temporal smoothing history to eliminate lag on frame jumps.
    pub fn reset(&mut self) {
        self.history.clear();
        self.last_frame_idx = None;
    }

    /// Analyzes a single range frame and returns DetectionResult or None if no track is found.
    pub fn detect(&mut self, frame: &RangeImage, frame_idx: usize) -> Option<DetectionResult> {
        let h = frame.height;
        let w = frame.width;
        let (x_arr, y_arr, z_arr) = self.geometry.range_image_to_xyz(frame);

        let mut candidates: Vec<RailPoint> = Vec::new();
        let mut prev_y_center: Option<f32> = None;
        let mut prev_y_right: Option<f32> = None;
        let mut prev_y_left: Option<f32> = None;
        let mut prev_x_center: Option<f32> = None;

        let row_start = (h as f32 * self.row_start_pct) as usize;
        let row_end = (h as f32 * self.row_end_pct) as usize;

        let has_intensity = !frame.intensity.is_empty();
        let b = if has_intensity {
            self.blend.clamp(0.0, 1.0)
        } else {
            0.0
        };
        let inv_b = 1.0 - b;

        // Scan rows from near (row_start) to far (row_end) with step -2
        let mut row = row_start;
        while row > row_end {
            let row_offset = row * w;
            let r_row = &frame.data[row_offset..row_offset + w];

            let mut pos_steps = Vec::new();
            let mut neg_steps = Vec::new();

            if b <= 0.0 {
                // Pure depth step detection (exact match to baseline)
                for c in 0..w - 1 {
                    let diff_r = r_row[c + 1] - r_row[c];
                    if diff_r > self.depth_step_thresh && diff_r <= self.max_depth_step_thresh {
                        pos_steps.push(c);
                    }
                    if diff_r < -self.depth_step_thresh && diff_r >= -self.max_depth_step_thresh {
                        neg_steps.push(c);
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
                    if d0 <= 0.1 || d1 <= 0.1 {
                        continue;
                    }

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

            let mut pairs = Vec::new();
            for &p in &pos_steps {
                for &n in &neg_steps {
                    if n > p {
                        let col_l = p;
                        let col_r = (n + 1).min(w - 1);

                        let idx_l = row_offset + col_l;
                        let idx_r = row_offset + col_r;

                        let xl = x_arr[idx_l];
                        let yl = y_arr[idx_l];
                        let zl = z_arr[idx_l];

                        let xr = x_arr[idx_r];
                        let yr = y_arr[idx_r];
                        let zr = z_arr[idx_r];

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

                        // Исключаем точки выше уровня земли (провода контактной сети и т.п.)
                        // Проверяем в реальных физических координатах (zm_real), чтобы upward_curvature не отсекала точки на глубине!
                        if zm_real > -0.3 {
                            continue;
                        }

                        // Адаптивные к дальности допуски: с ростом глубины (xm > 15m) шаг лучей лидара
                        // в метрах увеличивается, а кривизна пути создает естественный сдвиг по X между рельсами.
                        let tol_gauge =
                            (0.04 + 0.0018 * xm.min(15.0) + 0.003 * (xm - 15.0).max(0.0)).min(0.18);
                        let min_g =
                            (self.min_gauge - tol_gauge).min(self.nominal_gauge - tol_gauge);
                        let max_g =
                            (self.max_gauge + tol_gauge).max(self.nominal_gauge + tol_gauge);
                        let h_tol =
                            (0.05 + 0.0025 * xm.min(15.0) + 0.004 * (xm - 15.0).max(0.0)).min(0.30);
                        let x_tol =
                            (0.35 + 0.035 * xm.min(15.0) + 0.04 * (xm - 15.0).max(0.0)).min(3.0);

                        if gauge >= min_g && gauge <= max_g && h_diff < h_tol && x_diff < x_tol {
                            if let Some(pxc) = prev_x_center {
                                if xm < pxc - 0.5 {
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
                if row < 2 {
                    break;
                }
                row -= 2;
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

            let lateral_jump = if let Some(pyc) = prev_y_center {
                (best.y_center - pyc).abs()
            } else {
                best.y_center.abs()
            };

            let max_lat = (self.max_lateral_jump + 0.008 * best.x_center).min(0.80);
            let max_lat_rail = (self.max_lateral_rail_jump + 0.006 * best.x_center).min(0.50);

            // Reject sudden lateral discontinuity of center
            if prev_y_center.is_some() && lateral_jump > max_lat {
                if row < 2 {
                    break;
                }
                row -= 2;
                continue;
            }

            // Reject sudden lateral discontinuity of left rail
            if let Some(pyl) = prev_y_left {
                let left_lateral_jump = (best.y_left - pyl).abs();
                if left_lateral_jump > max_lat_rail {
                    if row < 2 {
                        break;
                    }
                    row -= 2;
                    continue;
                }
            }

            // Reject sudden lateral discontinuity of right rail
            if let Some(pyr) = prev_y_right {
                let right_lateral_jump = (best.y_right - pyr).abs();
                if right_lateral_jump > max_lat_rail {
                    if row < 2 {
                        break;
                    }
                    row -= 2;
                    continue;
                }
            }

            prev_x_center = Some(best.x_center);
            prev_y_center = Some(best.y_center);
            prev_y_left = Some(best.y_left);
            prev_y_right = Some(best.y_right);

            candidates.push(best.clone());

            if row < 2 {
                break;
            }
            row -= 2;
        }

        // Require a minimum number of valid scanlines
        if candidates.len() < 6 {
            return None;
        }

        // Extract coordinate arrays
        let cz = self.obstacle_config.upward_curvature;
        let xm: Vec<f32> = candidates.iter().map(|pt| pt.x_center).collect();
        let ym: Vec<f32> = candidates.iter().map(|pt| pt.y_center).collect();
        let zm_real: Vec<f32> = candidates
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

        // Fit quadratic curve for centerline: Y(X) = a*X^2 + b*X + c
        let raw_poly_y = polyfit2(&xm, &ym)?;
        // Fit elevation profile in REAL coordinates (linear slope): Z_real(X) = d*X + e
        let raw_poly_z = polyfit1(&xm, &zm_real)?;
        let raw_gauge = median_gauge;
        let raw_x_det_max = xm.iter().cloned().fold(f32::NEG_INFINITY, f32::max);

        // Reset history on non-consecutive jumps (gap > 2)
        if let Some(last_idx) = self.last_frame_idx {
            if last_idx.abs_diff(frame_idx) > 2 {
                self.history.clear();
            }
        }
        self.last_frame_idx = Some(frame_idx);

        if self.history.len() >= self.smooth_n.max(1) {
            self.history.pop_front();
        }
        self.history.push_back(DetectionHistoryItem {
            poly_y: raw_poly_y,
            poly_z: raw_poly_z,
            gauge: raw_gauge,
            x_det_max: raw_x_det_max,
        });

        // Weighted moving average
        let (poly_y, poly_z, median_gauge, smooth_det_max) = if self.history.len() == 1 {
            (raw_poly_y, raw_poly_z, raw_gauge, raw_x_det_max)
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

        let obstacles = if self.obstacle_config.enabled {
            self.detect_obstacles(frame, &poly_y, &poly_z, median_gauge, &self.obstacle_config)
        } else {
            Vec::new()
        };

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
            min_height_above_rail: self.obstacle_config.min_height_above_rail,
            max_height_above_rail: self.obstacle_config.max_height_above_rail,
            max_distance_m: self.obstacle_config.max_distance_m,
            upward_curvature: self.obstacle_config.upward_curvature,
            obstacle_enabled: self.obstacle_config.enabled,
            is_real_coordinates: false,
        })
    }

    /// Обнаруживает препятствия на путях и в зоне габарита приближения строений
    pub fn detect_obstacles(
        &self,
        frame: &RangeImage,
        poly_y: &[f32; 3],
        poly_z: &[f32; 2],
        gauge: f32,
        config: &ObstacleConfig,
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

        let (poly_a, poly_b, poly_c) = (poly_y[0], poly_y[1], poly_y[2]);
        let (poly_d, poly_e) = (poly_z[0], poly_z[1]);

        let half_w = config.clearance_width * 0.5;
        let half_g = gauge * 0.5;
        let x_min = 2.0_f32;
        let x_max = config.max_distance_m;

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
                        let (x, y, z) = self.geometry.row_col_range_to_xyz(row, col, r);
                        if x < x_min || x > x_max {
                            continue;
                        }
                        let y_c = poly_a * x * x + poly_b * x + poly_c;
                        let k = 2.0 * poly_a * x + poly_b;
                        let cos_th = 1.0 / (1.0 + k * k).sqrt();
                        let d_lat = (y - y_c) * cos_th;

                        let z_surf = poly_d * x + poly_e + config.upward_curvature * x * x;
                        let dz = z - z_surf;

                        if d_lat.abs() <= half_w
                            && dz >= config.min_height_above_rail
                            && dz <= config.max_height_above_rail
                        {
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
                        let (x, y, z) = self.geometry.row_col_range_to_xyz(row, col, r);
                        if x < x_min || x > x_max {
                            continue;
                        }
                        let y_c = poly_a * x * x + poly_b * x + poly_c;
                        let d_lat = (y - y_c).abs();
                        if d_lat > half_w {
                            continue;
                        }

                        let z_surf = poly_d * x + poly_e + config.upward_curvature * x * x;
                        let dz = z - z_surf;

                        let idx = r_off + col;
                        let dir_z = self.geometry.dir_z[idx];
                        let r_ground = if dir_z < -0.01 {
                            z_surf / dir_z
                        } else {
                            (x * x + y * y + z_surf * z_surf).sqrt()
                        };
                        let depth_diff = r_ground - r;

                        if depth_diff >= config.depth_diff_thresh
                            && dz >= config.min_height_above_rail
                            && dz <= config.max_height_above_rail
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
                        let (x, y, z) = self.geometry.row_col_range_to_xyz(row, col, r);
                        if x < x_min || x > x_max {
                            continue;
                        }
                        let y_c = poly_a * x * x + poly_b * x + poly_c;
                        let k = 2.0 * poly_a * x + poly_b;
                        let cos_th = 1.0 / (1.0 + k * k).sqrt();
                        let d_lat = (y - y_c) * cos_th;

                        let z_surf = poly_d * x + poly_e + config.upward_curvature * x * x;
                        let dz = z - z_surf;

                        if d_lat.abs() <= half_w
                            && dz >= config.min_height_above_rail
                            && dz <= config.max_height_above_rail
                        {
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
                                    visited[n_idx] = true;
                                    queue.push_back((nr as usize, nc as usize));
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

                let mut sum_x = 0.0;
                let mut sum_y_off = 0.0;
                let mut max_dz = 0.0f32;

                for &(r, c) in &cluster_cells {
                    col_min = col_min.min(c);
                    col_max = col_max.max(c);
                    row_min = row_min.min(r);
                    row_max = row_max.max(r);

                    let rng = frame.data[r * w + c];
                    let (x, y, z) = self.geometry.row_col_range_to_xyz(r, c, rng);

                    min_x = min_x.min(x);
                    max_x = max_x.max(x);
                    min_y = min_y.min(y);
                    max_y = max_y.max(y);
                    min_z = min_z.min(z);
                    max_z = max_z.max(z);

                    sum_x += x;

                    let y_c = poly_a * x * x + poly_b * x + poly_c;
                    sum_y_off += y - y_c;

                    let z_surf = poly_d * x + poly_e + config.upward_curvature * x * x;
                    max_dz = max_dz.max(z - z_surf);
                }

                let n_pts = cluster_cells.len() as f32;
                let _mean_x = sum_x / n_pts;
                let mean_y_off = sum_y_off / n_pts;

                // Препятствие критично, если проекция внутри колеи (половина колеи + 0.15м буфер)
                let is_critical = mean_y_off.abs() <= (half_g + 0.15);

                let size_m = [
                    (max_x - min_x).max(0.1),
                    (max_y - min_y).max(0.1),
                    (max_z - min_z).max(0.1),
                ];

                obstacles.push(TrackObstacle {
                    id: obstacle_id,
                    distance_along_track: min_x,
                    lateral_offset: mean_y_off,
                    height_above_rail: max_dz,
                    bbox_3d_min: [min_x, min_y, min_z],
                    bbox_3d_max: [max_x, max_y, max_z],
                    bbox_2d: [col_min, row_min, col_max, row_max],
                    points_count: cluster_cells.len(),
                    is_critical,
                    size_m,
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
    fn test_polyfit2_exact() {
        // y = 2*x^2 - 3*x + 5
        let x = vec![1.0, 2.0, 3.0, 4.0, 5.0];
        let y: Vec<f32> = x.iter().map(|&xi| 2.0 * xi * xi - 3.0 * xi + 5.0).collect();
        let res = polyfit2(&x, &y).expect("fit failed");
        assert!((res[0] - 2.0).abs() < 1e-4);
        assert!((res[1] - (-3.0)).abs() < 1e-4);
        assert!((res[2] - 5.0).abs() < 1e-4);
    }

    #[test]
    fn test_frame_000001_detection() {
        let candidates = [
            "frames/frame_000001.npy",
            "../frames/frame_000001.npy",
            "../../frames/frame_000001.npy",
        ];
        let frame_path = candidates.iter().find(|p| std::path::Path::new(p).exists());
        if let Some(&path) = frame_path {
            let frame = RangeImage::load_npy(path).expect("Failed to load frame");
            assert_eq!(frame.height, 321);
            assert_eq!(frame.width, 400);

            let geo = LidarGeometry::new(frame.height, frame.width, 15.0, -25.0, 40.0);
            let mut detector = RailTrackDetector::new(geo);
            let res = detector.detect(&frame, 1).expect("Detection failed");

            assert_eq!(res.points.len(), 58, "Points count mismatch");
            assert!(
                (res.gauge - 1.51).abs() < 0.03,
                "Gauge mismatch: {}",
                res.gauge
            );
            assert_eq!(res.turn_direction, "CURVE LEFT");
            println!(
                "Rust Detector: Gauge={:.4}, Radius={:.1}, Points={}, Dir={}",
                res.gauge,
                res.turn_radius,
                res.points.len(),
                res.turn_direction
            );
        }
    }

    #[test]
    fn test_frame_000001_dual_texture_detection() {
        let candidates = [
            "frames/frame_000001.npy",
            "../frames/frame_000001.npy",
            "../../frames/frame_000001.npy",
        ];
        let frame_path = candidates.iter().find(|p| std::path::Path::new(p).exists());
        if let Some(&path) = frame_path {
            let frame = RangeImage::load_npy(path).expect("Failed to load frame");
            let geo = LidarGeometry::new(frame.height, frame.width, 15.0, -25.0, 40.0);
            let mut detector = RailTrackDetector::new(geo);
            detector.contrast_depth = 200.0;
            detector.contrast_intensity = 20.0;
            detector.blend = 0.5;
            let res = detector
                .detect(&frame, 1)
                .expect("Dual texture detection failed");

            assert!(
                !res.points.is_empty(),
                "Should detect rail points with dual texture blend"
            );
            assert!(
                (res.gauge - 1.51).abs() < 0.05,
                "Gauge mismatch with blend: {}",
                res.gauge
            );
            println!(
                "Dual Texture Detector: Gauge={:.4}, Radius={:.1}, Points={}, Dir={}",
                res.gauge,
                res.turn_radius,
                res.points.len(),
                res.turn_direction
            );
        }
    }

    #[test]
    fn test_detect_obstacles_synthetic() {
        let geo = LidarGeometry::new(100, 100, 15.0, -25.0, 40.0);
        let detector = RailTrackDetector::new(geo.clone());

        // Create a flat range image where points correspond to ground
        let mut frame = RangeImage::new(100, 100);
        for row in 0..100 {
            for col in 0..100 {
                frame.set(row, col, 20.0);
            }
        }

        // Inject an obstacle at distance ~15m on the track center
        // Center col is 50, row ~60
        for r in 45..=52 {
            for c in 48..=52 {
                frame.set(r, c, 12.0); // 12m instead of 20m -> positive intrusion
            }
        }

        let poly_y = [0.0, 0.0, 0.0]; // Straight track centered at Y=0
        let poly_z = [0.0, -1.5]; // Track bed at Z = -1.5m

        let mut cfg = ObstacleConfig::default();
        cfg.min_points = 5;

        // Test HybridGrid
        cfg.mode = ObstacleDetectionMode::HybridGrid;
        let obs = detector.detect_obstacles(&frame, &poly_y, &poly_z, 1.52, &cfg);
        assert!(!obs.is_empty(), "HybridGrid should detect obstacle");
        assert!(obs[0].is_critical, "Obstacle is right on track centerline");

        // Test Boxcast3D
        cfg.mode = ObstacleDetectionMode::Boxcast3D;
        let obs_box = detector.detect_obstacles(&frame, &poly_y, &poly_z, 1.52, &cfg);
        assert!(!obs_box.is_empty(), "Boxcast3D should detect obstacle");

        // Test DepthMatrix2D
        cfg.mode = ObstacleDetectionMode::DepthMatrix2D;
        let obs_mat = detector.detect_obstacles(&frame, &poly_y, &poly_z, 1.52, &cfg);
        assert!(!obs_mat.is_empty(), "DepthMatrix2D should detect obstacle");
    }
}
