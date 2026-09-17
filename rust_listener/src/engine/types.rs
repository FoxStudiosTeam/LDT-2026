use crate::engine::cpu_engine::CPUEngine;

/// Статистика по облаку точек
pub struct CloudStats {
    pub n_points: usize,
    pub centroid_x: f32,
    pub centroid_y: f32,
    pub centroid_z: f32,
    pub min_x: f32,
    pub min_y: f32,
    pub min_z: f32,
    pub max_x: f32,
    pub max_y: f32,
    pub max_z: f32,
}

impl CloudStats {
    pub fn new() -> Self {
        Self{ 
            centroid_x: 0.0,
            centroid_y: 0.0,
            centroid_z: 0.0,
            min_x: f32::INFINITY,
            min_y: f32::INFINITY,
            min_z: f32::INFINITY,
            max_x: f32::NEG_INFINITY,
            max_y: f32::NEG_INFINITY,
            max_z: f32::NEG_INFINITY,
            n_points: 0,
        }
    }
}

pub type AppPointCloud = PointCloud<1024>;

pub struct PointCloud<const SIZE: usize> {
    pub x: [f32; SIZE],
    pub y: [f32; SIZE],
    pub z: [f32; SIZE],
    pub intensity: [f32; SIZE],
    pub length: usize,
}

impl<const SIZE : usize> PointCloud<SIZE> {
    pub fn new() -> Self {
        Self { 
            x: [0.0;SIZE], 
            y: [0.0;SIZE],
            z: [0.0;SIZE],
            intensity: [0.0;SIZE],
            length: 0 
        }
    }

    pub fn is_empty(&self) -> bool {
        return self.length == 0
    }
}


impl<'a, const SIZE : usize> PointCloud<SIZE> {
    pub fn iter(&self) -> impl Iterator<Item = (&f32, &f32, &f32, &f32)> {
        let x_iter = self.x[..self.length].iter();
        let y_iter = self.y[..self.length].iter();
        let z_iter = self.z[..self.length].iter();
        let int_iter = self.intensity[..self.length].iter();

        x_iter.zip(y_iter).zip(z_iter).zip(int_iter)
        .map(|(((x, y), z), intensity)| (x, y, z, intensity))
    }

    pub fn len(&self) -> usize {
        self.length
    }

    pub fn compute_stats(&self) -> CloudStats {
        let mut cloud_stats = CloudStats::new();
        
        if self.length == 0 {
            return cloud_stats
        }

        cloud_stats.n_points = self.length;

        let (mut sum_x, mut sum_y, mut sum_z) = (0.0f32, 0.0f32, 0.0f32);

        for (&x,&y,&z,_) in self.iter() {
            sum_x += x;
            sum_y += y;
            sum_z += z;

            cloud_stats.min_x = cloud_stats.min_x.min(x);
            cloud_stats.min_y = cloud_stats.min_y.min(y);
            cloud_stats.min_z = cloud_stats.min_z.min(z);

            cloud_stats.max_x = cloud_stats.max_x.max(x);
            cloud_stats.max_y = cloud_stats.max_y.max(y);
            cloud_stats.max_z = cloud_stats.max_z.max(z);
        }

        let count = self.length as f32;
        cloud_stats.centroid_x = sum_x / count;
        cloud_stats.centroid_y = sum_y / count;
        cloud_stats.centroid_z = sum_z / count;

        cloud_stats
    }

    pub fn parse_ros2_msg(&mut self, ros2_msg: &r2r::sensor_msgs::msg::PointCloud2) {
        // 1. Сбрасываем длину
        self.length = 0;

        if ros2_msg.data.is_empty() || ros2_msg.point_step == 0 {
            return;
        }

        // 2. Вытаскиваем смещения полей (делаем безопасно, без HashMap, чтобы не аллоцировать в куче!)
        let mut x_off = None;
        let mut y_off = None;
        let mut z_off = None;
        let mut int_off = None;

        for f in &ros2_msg.fields {
            match f.name.as_str() {
                "x" => x_off = Some(f.offset as usize),
                "y" => y_off = Some(f.offset as usize),
                "z" => z_off = Some(f.offset as usize),
                "intensity" => int_off = Some(f.offset as usize),
                _ => {}
            }
        }

        // Если базовых координат нет — выходим, ловить нечего
        let (x_off, y_off, z_off) = match (x_off, y_off, z_off) {
            (Some(x), Some(y), Some(z)) => (x, y, z),
            _ => return,
        };
        
        // Интенсивность опциональна: если её нет, смещение будет 0
        let int_off = int_off.unwrap_or(0);

        let step = ros2_msg.point_step as usize;
        let n_points = ros2_msg.data.len() / step;
        let data = &ros2_msg.data;

        // 3. Твой идеальный плоский цикл без лесенок (Guard Clause)
        for i in 0..n_points {
            // Проверка на жесткий лимит статического буфера
            if self.length >= SIZE {
                break;
            }

            let base = i * step;

            // Безопасность границ бинарного массива (как в старом коде)
            if base + z_off + 4 > data.len() || base + int_off + 4 > data.len() {
                break;
            }

            // Парсим строго в Little Endian через копирование среза байт (ноль unsafe!)
            let x = f32::from_le_bytes(data[base + x_off..base + x_off + 4].try_into().unwrap_or([0; 4]));
            let y = f32::from_le_bytes(data[base + y_off..base + y_off + 4].try_into().unwrap_or([0; 4]));
            let z = f32::from_le_bytes(data[base + z_off..base + z_off + 4].try_into().unwrap_or([0; 4]));
            let intensity = f32::from_le_bytes(data[base + int_off..base + int_off + 4].try_into().unwrap_or([0; 4]));

            // Сохраняем спасительную проверку на валидность чисел (NaN / Inf)
            if x.is_finite() && y.is_finite() && z.is_finite() {
                let idx = self.length;
                self.x[idx] = x;
                self.y[idx] = y;
                self.z[idx] = z;
                self.intensity[idx] = intensity;
                self.length += 1;
            }
        }
    }

    pub fn to_rerun(&self) -> impl Iterator<Item = [f32; 3]> + '_ {
        // Просто перебираем индексы от 0 до length
        (0..self.length).map(move |i| {
            // Возвращаем массив f32. Компилятор сам сделает из него Position3D
            [self.x[i], self.y[i], self.z[i]]
        })
    }
}



pub trait Engine<const SIZE : usize> {
    fn check(&self) -> Result<bool, anyhow::Error>;
}

pub type AppEngine<'a, const SIZE : usize> = CPUEngine<'a,SIZE>;