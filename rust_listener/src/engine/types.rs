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

pub type AppPointCloud = PointCloud<2_000_000>;

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
        let step = ros2_msg.point_step as usize;
        if step != 0 {
            // Считаем, сколько РЕАЛЬНО точек прислал ROS2 в этом кадре
            let real_points_count = ros2_msg.data.len() / step;
            println!("🔥 ROS2 MSG ACTUAL POINTS: {}", real_points_count);
        }
        
        self.length = 0;

        if ros2_msg.data.is_empty() || ros2_msg.point_step == 0 {
            return;
        }

        // Будем искать не только offset, но и datatype для каждой координаты
        let mut x_info = None;
        let mut y_info = None;
        let mut z_info = None;

        for f in &ros2_msg.fields {
            let info = (f.offset as usize, f.datatype as u8);
            match f.name.as_str() {
                "x" => x_info = Some(info),
                "y" => y_info = Some(info),
                "z" => z_info = Some(info),
                _ => {}
            }
        }

        let (x_info, y_info, z_info) = match (x_info, y_info, z_info) {
            (Some(x), Some(y), Some(z)) => (x, y, z),
            _ => return, // Нет базовых полей — выходим
        };

        let step = ros2_msg.point_step as usize;
        let n_points = ros2_msg.data.len() / step;
        let data = &ros2_msg.data;

        // Вспомогательная функция, которая умеет безопасно читать и f32 (тип 7), и f64 (тип 8)
        let read_cast_f32 = |base_offset: usize, info: (usize, u8), buffer: &[u8]| -> Option<f32> {
            let (offset, datatype) = info;
            let start = base_offset + offset;

            match datatype {
                8 => { // FLOAT64 (double) — занимает 8 байт
                    let bytes: [u8; 8] = buffer.get(start..start + 8)?.try_into().ok()?;
                    Some(f64::from_le_bytes(bytes) as f32) // кастуем double в f32
                }
                7 | _ => { // FLOAT32 (стандартный float) — занимает 4 байта
                    let bytes: [u8; 4] = buffer.get(start..start + 4)?.try_into().ok()?;
                    Some(f32::from_le_bytes(bytes))
                }
            }
        };

        for i in 0..n_points {
            if self.length >= SIZE {
                break;
            }

            let base = i * step;

            // Читаем координаты с авто-приведением типов. Если буфер кадра обрезался — выходим (как старый `?`)
            let x = match read_cast_f32(base, x_info, data) { Some(v) => v, None => return };
            let y = match read_cast_f32(base, y_info, data) { Some(v) => v, None => return };
            let z = match read_cast_f32(base, z_info, data) { Some(v) => v, None => return };

            if x.is_finite() && y.is_finite() && z.is_finite() {
                let idx = self.length;
                self.x[idx] = x;
                self.y[idx] = y;
                self.z[idx] = z;
                self.length += 1;
            }
        }
    }

    pub fn to_rerun(&self) -> impl Iterator<Item = [f32; 3]> + '_ {
        (0..self.length).map(move |i| {
            [self.x[i], self.y[i], self.z[i]]
        })
    }
}



pub trait Engine<const SIZE : usize> {
    fn check(&self) -> Result<bool, anyhow::Error>;
}

pub type AppEngine<'a, const SIZE : usize> = CPUEngine<'a,SIZE>;