use crate::error::AppError;
use crate::types::{AppPointCloud, ProcessingQueue};
use rerun::DepthImage;
use tracing::info;

const PANDAR128_CHANNELS: usize = 128;

// Вертикальные интервалы между каналами.
const PANDAR128_VERTICAL_STEP_EDGE_DEG: f32 = 1.0;
const PANDAR128_VERTICAL_STEP_STANDARD_DEG: f32 = 0.5;
const PANDAR128_VERTICAL_STEP_HIGH_RES_DEG: f32 = 0.125;

// Границы high-resolution области.
const PANDAR128_HR_FIRST_CHANNEL: usize = 26;
const PANDAR128_HR_LAST_CHANNEL: usize = 89;

// Вертикальный FOV.
const PANDAR128_FOV_UP_DEG: f32 = 15.0;
const PANDAR128_FOV_DOWN_DEG: f32 = -25.0;
const VERTICAL_FOV_DEG: f32 = 40.0;

// Горизонтальное разрешение.
const PANDAR128_HORIZONTAL_RES_HR_DEG: f32 = 0.1;
const PANDAR128_HORIZONTAL_RES_STANDARD_DEG: f32 = 0.2;

const PANDAR128_RANGE_IMAGE_WIDTH: usize = 3600;

#[derive(Clone, Copy, Debug)]
pub struct RangeImageConfig {
    /// Число столбцов карты глубины (горизонтальное разрешение)
    pub width: usize,
    /// Число строк карты глубины (вертикальное разрешение, для Pandar128 обычно 128)
    pub height: usize,
    /// Верхний предел вертикального угла (в радианах), по умолчанию +15°
    pub fov_up_rad: f32,
    /// Нижний предел вертикального угла (в радианах), по умолчанию -25°
    pub fov_down_rad: f32,
    /// Минимальная дальность отсева сенсора (в метрах)
    pub min_range_m: f32,
    /// Максимальная дальность (в метрах)
    pub max_range_m: f32,
}

impl Default for RangeImageConfig {
    fn default() -> Self {
        Self {
            width: 3600,
            height: (VERTICAL_FOV_DEG / PANDAR128_VERTICAL_STEP_HIGH_RES_DEG) as usize + 1,
            fov_up_rad: 15.0_f32.to_radians(),
            fov_down_rad: -25.0_f32.to_radians(),
            min_range_m: 0.5,
            max_range_m: 250.0,
        }
    }
}

/// 2D Карта глубины (Range Image / Depth Map), сформированная из облака точек.
/// Координаты пикселя: (row: 0..height-1 сверху вниз, col: 0..width-1 слева направо).
#[derive(Clone, Debug)]
pub struct RangeImage {
    pub width: usize,
    pub height: usize,
    /// Прямой буфер глубин в метрах. Размер `width * height`.
    /// Непоражённые лучи / пропуски хранятся как `0.0`.
    pub data: Vec<f32>,
}

/// Расчётная вертикальная геометрия Pandar128E3X.
///
/// Каналы нумеруются сверху вниз: 1..128.
///
/// Из документации:
/// - Ch 1 -> Ch 2:       1.0°
/// - Ch 2 -> Ch 26:      0.5°
/// - Ch 26 -> Ch 90:     0.125°
/// - Ch 90 -> Ch 127:    0.5°
/// - Ch 127 -> Ch 128:   1.0°
pub struct Pandar128VerticalGeometry {
    pub pitch_rad: [f32; 128],
}

impl Pandar128VerticalGeometry {
    pub fn new() -> Self {
        let mut pitch_rad = [0.0f32; PANDAR128_CHANNELS];

        // Ch1 находится на верхней границе FOV.
        pitch_rad[0] = PANDAR128_FOV_UP_DEG.to_radians();

        for channel in 1..PANDAR128_CHANNELS {
            let step_deg: f32 = match channel {
                // Ch1 -> Ch2
                1 => 1.0,

                // Ch2 -> Ch26
                2..=25 => 0.5,

                // Ch26 -> Ch90
                26..=89 => 0.125,

                // Ch90 -> Ch127
                90..=126 => 0.5,

                // Ch127 -> Ch128
                127 => 1.0,

                _ => unreachable!(),
            };

            pitch_rad[channel] =
                pitch_rad[channel - 1] - step_deg.to_radians();
        }

        Self { pitch_rad }
    }

    #[inline(always)]
    pub fn pitch(&self, row: usize) -> f32 {
        self.pitch_rad[row]
    }

    #[inline(always)]
    pub fn nearest_channel(&self, pitch_rad: f32) -> usize {
        let mut best_channel = 0;
        let mut best_error = f32::MAX;

        for channel in 0..PANDAR128_CHANNELS {
            let error = (self.pitch_rad[channel] - pitch_rad).abs();

            if error < best_error {
                best_error = error;
                best_channel = channel;
            }
        }

        best_channel
    }
}

#[inline(always)]
fn horizontal_resolution_deg(channel: usize) -> f32 {
    match channel {
        // Ch 26..89 = 0.1°
        26..=89 => PANDAR128_HORIZONTAL_RES_HR_DEG,

        // Ch 1..25 и Ch 90..128 = 0.2°
        1..=25 | 90..=128 => PANDAR128_HORIZONTAL_RES_STANDARD_DEG,

        _ => unreachable!(),
    }
}

#[inline(always)]
fn vertical_resolution_deg(channel: usize) -> f32 {
    match channel {
        // Ch1 -> Ch2
        1 => 1.0,

        // Ch2 -> Ch26
        2..=25 => 0.5,

        // Ch26 -> Ch90
        26..=89 => 0.125,

        // Ch90 -> Ch127
        90..=126 => 0.5,

        // Ch127 -> Ch128
        127 => 1.0,

        _ => unreachable!(),
    }
}

/// Быстрое вычисление atan2(y, x) через полиномиальную аппроксимацию.
/// Максимальная абсолютная погрешность < 0.0008 радиана (~0.04°),
/// что существенно меньше шага азимута лидара (~0.2°).
/// Работает в 5-10 раз быстрее std::f32::atan2.
#[inline(always)]
pub fn fast_atan2(y: f32, x: f32) -> f32 {
    if x == 0.0 && y == 0.0 {
        return 0.0;
    }
    let ax = x.abs();
    let ay = y.abs();

    let (ratio, offset) = if ax >= ay {
        (ay / ax, 0.0)
    } else {
        (ax / ay, std::f32::consts::FRAC_PI_2)
    };

    let z2 = ratio * ratio;
    let mut angle = ratio * (0.995354 + z2 * (-0.288679 + 0.079331 * z2));

    if ax < ay {
        angle = offset - angle;
    }
    if x < 0.0 {
        angle = std::f32::consts::PI - angle;
    }
    if y < 0.0 {
        angle = -angle;
    }
    angle
}

impl RangeImage {
    pub fn new(width: usize, height: usize) -> Self {
        Self {
            width,
            height,
            data: vec![0.0; width * height],
        }
    }

    #[inline(always)]
    pub fn get(&self, row: usize, col: usize) -> f32 {
        self.data[row * self.width + col]
    }

    #[inline(always)]
    pub fn set(&mut self, row: usize, col: usize, val: f32) {
        self.data[row * self.width + col] = val;
    }

    /// Быстрое формирование Range Image из организованного облака Hesai Pandar128E3X.
    ///
    /// Особенности Pandar128:
    /// - 128 колец (строк), нумерация лучей в сообщении: `index % 128` = кольцо (ring).
    /// - Но каждый луч стреляет с небольшим индивидуальным азимутальным смещением (до 15.4°)!
    /// - Для устранения артефактов и "зебры" азимут вычисляется через `fast_atan2(y, x)`.
    /// - Курс поезда (+X, yaw = 0) проецируется строго по центру: col = width / 2.
    /// - `downsample_x`: прореживание по горизонтали (например, 4 -> 450x128).
    pub fn from_pandar128_organized(
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
        downsample_x: usize,
    ) -> Self {
        const CHANNELS: usize = 128;
        const BASE_WIDTH: usize = 3600; // +15° ... -25°

        let total_pts = cloud.len(queue);

        let ds = downsample_x.max(1);
        let width = BASE_WIDTH / ds;
        let height = (VERTICAL_FOV_DEG / PANDAR128_VERTICAL_STEP_HIGH_RES_DEG) as usize + 1;

        let mut image = Self::new(width, height);

        let geometry = Pandar128VerticalGeometry::new();

        let pi = std::f32::consts::PI;
        let inv_two_pi = 0.5 * std::f32::consts::FRAC_1_PI;
        let width_f = width as f32;

        for (i, (&x, &y, &z, _, &r)) in cloud.iter(queue).enumerate() {
            if i >= total_pts {
                break;
            }

            if (y.abs() < 1e-4 && z.abs() < 1e-4)
                || (x == 0.0 && y == 0.0 && z == 0.0)
            {
                continue;
            }

            let r2 = x * x + y * y + z * z;

            if r2 < 0.04 {
                continue;
            }

            let range = r2.sqrt();

            let yaw = fast_atan2(-x, -y);
            let norm = (-yaw + pi) * inv_two_pi;

            let col = ((norm * width_f) as usize)
                .min(width - 1);

            let ring = r as usize;

            if ring >= CHANNELS {
                continue;
            }

            let pitch_rad = geometry.pitch(ring);

            let row = (
                (PANDAR128_FOV_UP_DEG.to_radians() - pitch_rad)
                    / PANDAR128_VERTICAL_STEP_HIGH_RES_DEG.to_radians()
            )
                .round() as usize;

            if row >= height {
                continue;
            }

            let center_row = row as isize;
            let center_col = col as isize;

            // Сколько пикселей между соседними каналами по вертикали.
            let row_radius =
                (vertical_resolution_deg(ring+1) / PANDAR128_VERTICAL_STEP_HIGH_RES_DEG)
                    .round() as isize
                    - 1;

            // Сколько пикселей между соседними измерениями по горизонтали.
            //
            // При width = 3600:
            // 360° / 3600 = 0.1° на пиксель.
            let horizontal_step_deg = 360.0 / width as f32;

            let col_radius =
                (horizontal_resolution_deg(ring+1) / horizontal_step_deg)
                    .round() as isize
                    - 1;

            for dr in -row_radius..=row_radius {
                for dc in -col_radius..=col_radius {
                    // Реальный радиус — окружность, а не квадрат.
                    let distance2 = dr * dr + dc * dc;

                    if distance2 > row_radius * row_radius {
                        continue;
                    }

                    let target_row = center_row + dr;
                    let target_col = center_col + dc;

                    // Проверяем границы.
                    if target_row < 0
                        || target_row >= height as isize
                        || target_col < 0
                        || target_col >= width as isize
                    {
                        continue;
                    }

                    let target_row = target_row as usize;
                    let target_col = target_col as usize;

                    let idx = target_row * width + target_col;

                    // Оставляем ближайшую точку.
                    let current = image.data[idx];

                    if current == 0.0 || range < current {
                        image.data[idx] = range;
                    }
                }
            }
        }

            // let idx = row * width + col;
            //
            // let current = image.data[idx];
            //
            // if current == 0.0 || range < current {
            //     image.data[idx] = range;
            // }
        // }

        // image.fill_single_pixel_holes();
        //
        // image.fill_vertical_holes();

        image
    }

    pub fn fill_vertical_holes(&mut self) {
        let w = self.width;
        let h = self.height;

        for r in 1..h - 1 {
            let row_start = r * w;
            let row_end = row_start + w;

            // Реальная строка канала — ничего не делаем.
            if self.data[row_start..row_end]
                .iter()
                .any(|&v| v > 0.0)
            {
                continue;
            }

            // Ближайшая заполненная строка сверху.
            let mut top = r;
            while top > 0 {
                top -= 1;

                let start = top * w;
                let end = start + w;

                if self.data[start..end].iter().any(|&v| v > 0.0) {
                    break;
                }
            }

            // Ближайшая заполненная строка снизу.
            let mut bottom = r;
            while bottom + 1 < h {
                bottom += 1;

                let start = bottom * w;
                let end = start + w;

                if self.data[start..end].iter().any(|&v| v > 0.0) {
                    break;
                }
            }

            if top == r || bottom == r {
                continue;
            }

            let gap = (bottom - top) as f32;
            let t = (r - top) as f32 / gap;

            for c in 0..w {
                let top_value = self.data[top * w + c];
                let bottom_value = self.data[bottom * w + c];

                if top_value > 0.0
                    && bottom_value > 0.0
                    && (top_value - bottom_value).abs() < 2.0
                {
                    self.data[row_start + c] =
                        top_value * (1.0 - t) + bottom_value * t;
                }
            }
        }
    }

    /// Заполнение одиночных 1- и 2-пиксельных пропусков по горизонтали для устранения шума и артефактов
    pub fn fill_single_pixel_holes(&mut self) {
        let w = self.width;
        let h = self.height;
        for r in 0..h {
            let row_offset = r * w;
            for c in 1..w - 1 {
                let idx = row_offset + c;
                if self.data[idx] == 0.0 {
                    let left = self.data[idx - 1];
                    let right = self.data[idx + 1];
                    if left > 0.0 && right > 0.0 && (left - right).abs() < 2.0 {
                        self.data[idx] = (left + right) * 0.5;
                    } else if c + 2 < w
                        && left > 0.0
                        && self.data[idx + 2] > 0.0
                        && (left - self.data[idx + 2]).abs() < 2.0
                    {
                        let r2 = self.data[idx + 2];
                        self.data[idx] = left * 0.67 + r2 * 0.33;
                        self.data[idx + 1] = left * 0.33 + r2 * 0.67;
                    }
                }
            }
        }
    }

    /// Построение карты глубины через сферическую проекцию (для произвольных / неорганизованных облаков).
    /// Вычисляет сферическую проекцию на 2D сетку `[height, width]`.
    /// При конфликтах нескольких точек в одном пикселе сохраняется минимальная глубина (ближайшая поверхность).
    pub fn from_point_cloud(
        cloud: &AppPointCloud,
        queue: ProcessingQueue,
        config: &RangeImageConfig,
    ) -> Self {
        let width = config.width;
        let height = config.height;
        let mut image = Self::new(width, height);

        let total_fov_v = config.fov_up_rad - config.fov_down_rad;
        if total_fov_v <= 0.0 || width == 0 || height == 0 {
            return image;
        }

        let fov_v_inv = 1.0 / total_fov_v;
        let two_pi = 2.0 * std::f32::consts::PI;

        for (&x, &y, &z, _, &r) in cloud.iter(queue) {
            let r2 = x * x + y * y + z * z;
            if r2 < config.min_range_m * config.min_range_m
                || r2 > config.max_range_m * config.max_range_m
            {
                continue;
            }

            let range = r2.sqrt();
            let pitch = (z / range).clamp(-1.0, 1.0).asin();
            let yaw = fast_atan2(y, x); // [-PI, PI], 0 = вперед по оси X

            // Проекция по вертикали: pitch -> [0..height-1]
            // pitch = fov_up -> row 0 (верх), pitch = fov_down -> row height-1 (низ)
            let vertical_geometry = Pandar128VerticalGeometry::new();

            let row = r as usize;

            if row >= height {
                continue;
            }

            // Проекция по горизонтали: yaw -> [0..width-1]
            // yaw = 0 (вперед) -> центр изображения (width / 2)
            let h_norm = (yaw + std::f32::consts::PI) / two_pi;
            let col = ((h_norm * (width as f32)).floor() as usize).min(width - 1);

            let idx = row * width + col;
            let current = image.data[idx];
            if current == 0.0 || range < current {
                image.data[idx] = range;
            }
        }

        image
    }

    /// Число валидных (ненулевых) пикселей глубины
    pub fn valid_pixels_count(&self) -> usize {
        self.data.iter().filter(|&&v| v > 0.0).count()
    }

    /// Растягивание изображения по вертикали (дублирование строк) в `factor` раз.
    /// Позволяет сделать из узкой полоски 128px высокое, удобное для глаз изображение (например 128*4 = 512px).
    pub fn stretch_vertical(&self, factor: usize) -> Self {
        let factor = factor.max(1);
        let new_height = self.height * factor;
        let mut new_data = Vec::with_capacity(new_height * self.width);

        for row in 0..self.height {
            let row_slice = &self.data[row * self.width..(row + 1) * self.width];
            for _ in 0..factor {
                new_data.extend_from_slice(row_slice);
            }
        }

        Self {
            width: self.width,
            height: new_height,
            data: new_data,
        }
    }

    /// Извлечение переднего сектора по ходу поезда с заданным горизонтальным углом обзора `fov_x_deg`
    /// (центрировано строго вокруг курса поезда вперед) и плавной билинейной интерполяцией
    /// в целевое разрешение (например 800x600 в 4:3).
    ///
    /// - `fov_x_deg`: угол обзора по горизонтали в градусах (например, 20°..30° для плотного кадрирования
    ///   узкого тоннеля и путей без пустоты по краям, или 60°..90° для широкого обзора).
    pub fn front_view_preview_fov(&self, fov_x_deg: f32, target_w: usize, target_h: usize) -> Self {
        let fov_deg = if fov_x_deg <= 0.0 {
            25.0
        } else {
            fov_x_deg.clamp(1.0, 360.0)
        };
        let crop_w =
            (((fov_deg / 360.0) * self.width as f32).round() as usize).clamp(2, self.width);
        let center = self.width / 2;
        let half_w = crop_w / 2;
        let start_col = center.saturating_sub(half_w);

        let mut out = vec![0.0_f32; target_w * target_h];

        let sx = (crop_w - 1) as f32 / (target_w - 1).max(1) as f32;
        let sy = (self.height - 1) as f32 / (target_h - 1).max(1) as f32;

        for ty in 0..target_h {
            let fy = ty as f32 * sy;
            let y0 = fy as usize;
            let y1 = (y0 + 1).min(self.height - 1);
            let dy = fy - y0 as f32;
            let inv_dy = 1.0 - dy;

            let row0_off = y0 * self.width + start_col;
            let row1_off = y1 * self.width + start_col;
            let out_row_off = ty * target_w;

            for tx in 0..target_w {
                let fx = tx as f32 * sx;
                let x0 = fx as usize;
                let x1 = (x0 + 1).min(crop_w - 1);
                let dx = fx - x0 as f32;
                let inv_dx = 1.0 - dx;

                let c00 = self.data[row0_off + x0];
                let c10 = self.data[row0_off + x1];
                let c01 = self.data[row1_off + x0];
                let c11 = self.data[row1_off + x1];

                // Взвешенная интерполяция между валидными точками
                let w00 = if c00 > 0.0 { inv_dx * inv_dy } else { 0.0 };
                let w10 = if c10 > 0.0 { dx * inv_dy } else { 0.0 };
                let w01 = if c01 > 0.0 { inv_dx * dy } else { 0.0 };
                let w11 = if c11 > 0.0 { dx * dy } else { 0.0 };

                let w_sum = w00 + w10 + w01 + w11;
                if w_sum > 0.0 {
                    out[out_row_off + tx] = (c00 * w00 + c10 * w10 + c01 * w01 + c11 * w11) / w_sum;
                }
            }
        }

        Self {
            width: target_w,
            height: target_h,
            data: out,
        }
    }

    /// Превью переднего сектора поезда с фиксированным углом обзора 25° (800x600, 4:3).
    pub fn front_view_preview(&self) -> Self {
        self.front_view_preview_fov(25.0, 800, 600)
    }

    /// Извлечение сырого (БЕЗ интерполяции) переднего сектора по заданному горизонтальному углу обзора `fov_x_deg`.
    /// Кадрирование производится симметрично относительно центра курса (`width / 2`).
    /// Возвращает матрицу глубины размером `[height, crop_w]`, где каждый пиксель содержит истинную дальность (f32, метры).
    pub fn crop_fov(&self, fov_x_deg: f32) -> Self {
        let fov_deg = if fov_x_deg <= 0.0 {
            25.0
        } else {
            fov_x_deg.clamp(1.0, 360.0)
        };
        let crop_w =
            (((fov_deg / 360.0) * self.width as f32).round() as usize).clamp(2, self.width);
        let center = self.width / 2;
        let half_w = crop_w / 2;
        let start_col = center.saturating_sub(half_w);
        let end_col = (start_col + crop_w).min(self.width);
        let actual_w = end_col - start_col;

        let mut out = vec![0.0_f32; self.height * actual_w];
        for r in 0..self.height {
            let src_off = r * self.width + start_col;
            let dst_off = r * actual_w;
            out[dst_off..dst_off + actual_w]
                .copy_from_slice(&self.data[src_off..src_off + actual_w]);
        }

        Self {
            width: actual_w,
            height: self.height,
            data: out,
        }
    }

    /// Сохранение 2D матрицы дальности в стандартном формате NumPy `.npy` (v1.0, float32, C-order).
    /// В Python читается мгновенно:
    /// ```python
    /// import numpy as np
    /// depth = np.load("frame_000000.npy") # shape: (height, width), float32
    /// ```
    pub fn save_npy<P: AsRef<std::path::Path>>(&self, path: P) -> std::io::Result<()> {
        use std::io::Write;
        let mut file = std::fs::File::create(path)?;
        // Magic NPY v1.0
        file.write_all(b"\x93NUMPY\x01\x00")?;
        let dict = format!(
            "{{'descr': '<f4', 'fortran_order': False, 'shape': ({}, {})}}",
            self.height, self.width
        );
        let prefix_len = 10 + dict.len() + 1; // 10 bytes prefix + dict + '\n'
        let pad_len = ((prefix_len + 63) / 64) * 64 - prefix_len;
        let mut header = dict;
        for _ in 0..pad_len {
            header.push(' ');
        }
        header.push('\n');
        let total_header_len = header.len() as u16;
        file.write_all(&total_header_len.to_le_bytes())?;
        file.write_all(header.as_bytes())?;
        let raw_bytes: &[u8] = unsafe {
            std::slice::from_raw_parts(
                self.data.as_ptr() as *const u8,
                self.data.len() * std::mem::size_of::<f32>(),
            )
        };
        file.write_all(raw_bytes)?;
        Ok(())
    }

    /// Преобразование в Rerun `DepthImage`.
    pub fn to_rerun(&self) -> Result<DepthImage, AppError> {
        let bytes: &[u8] = unsafe {
            std::slice::from_raw_parts(
                self.data.as_ptr() as *const u8,
                self.data.len() * std::mem::size_of::<f32>(),
            )
        };
        let format = rerun::datatypes::ImageFormat::depth(
            [self.width as u32, self.height as u32],
            rerun::datatypes::ChannelDatatype::F32,
        );
        let depth_img = DepthImage::new(bytes, format).with_meter(1.0);
        Ok(depth_img)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_range_image_basic() {
        let mut img = RangeImage::new(10, 10);
        assert_eq!(img.get(0, 0), 0.0);
        img.set(2, 3, 15.5);
        assert_eq!(img.get(2, 3), 15.5);
    }

    #[test]
    fn test_fast_atan2_accuracy() {
        let mut max_err = 0.0_f32;
        for deg in -180..=180 {
            let rad = (deg as f32).to_radians();
            let x = rad.cos() * 10.0;
            let y = rad.sin() * 10.0;
            let expected = y.atan2(x);
            let actual = fast_atan2(y, x);
            let diff = (actual - expected).abs();
            if diff > max_err {
                max_err = diff;
            }
        }
        assert!(max_err < 0.001, "max error too high: {max_err}");
    }

    #[test]
    fn test_crop_fov_and_save_npy() {
        let mut img = RangeImage::new(360, 10);
        // Заполним центр (col = 180, row = 5) значением 12.5м
        img.set(5, 180, 12.5);

        // Обрезаем до FOV 36 градусов (1/10 окружности -> 36 колонок)
        let cropped = img.crop_fov(36.0);
        assert_eq!(cropped.height, 10);
        assert_eq!(cropped.width, 36);
        // Центр обрезанного изображения (col = 18) должен иметь 12.5м
        assert_eq!(cropped.get(5, 18), 12.5);

        // Тестируем запись в .npy во временный файл
        let tmp_path = std::env::temp_dir().join("test_frame.npy");
        cropped.save_npy(&tmp_path).expect("Failed to save npy");
        assert!(tmp_path.exists());

        // Проверяем заголовок файла
        let bytes = std::fs::read(&tmp_path).expect("Failed to read npy");
        assert_eq!(&bytes[..6], b"\x93NUMPY");
        let _ = std::fs::remove_file(&tmp_path);
    }

    #[test]
    fn test_is_zero_point() {
        use crate::types::is_zero_point;
        assert!(is_zero_point(0.0, 0.0, 0.0));
        assert!(is_zero_point(0.004, -0.003, 0.005));
        assert!(!is_zero_point(0.006, 0.0, 0.0));
        assert!(!is_zero_point(0.0, 10.0, 0.0));
    }

    #[test]
    fn test_pandar128_vertical_geometry() {
        let geometry = Pandar128VerticalGeometry::new();

        for channel in 0..128 {
            println!(
                "Ch {:3}: {:8.4}°",
                channel + 1,
                geometry.pitch_rad[channel].to_degrees(),
            );
        }

        let ch1 = geometry.pitch_rad[0].to_degrees();
        let ch2 = geometry.pitch_rad[1].to_degrees();
        let ch26 = geometry.pitch_rad[25].to_degrees();
        let ch27 = geometry.pitch_rad[26].to_degrees();
        let ch89 = geometry.pitch_rad[88].to_degrees();
        let ch90 = geometry.pitch_rad[89].to_degrees();
        let ch127 = geometry.pitch_rad[126].to_degrees();
        let ch128 = geometry.pitch_rad[127].to_degrees();

        assert!((ch1 - 15.0).abs() < 1e-5);
        assert!((ch2 - 14.0).abs() < 1e-5);

        assert!((ch27 - ch26 + 0.125).abs() < 1e-5);

        assert!((ch90 - ch89 + 0.125).abs() < 1e-5);

        assert!((ch128 + 25.0).abs() < 1e-5);
    }
}
