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
    pub width: u32,
    pub height: u32,
}

impl CloudStats {
    pub fn new() -> Self {
        Self {
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
            width: 0,
            height: 0,
        }
    }
}

// 307_200
pub type AppPointCloud = PointCloud<2_000_000>;

pub struct PointCloud<const SIZE: usize> {
    pub x: Box<[f32; SIZE]>,
    pub y: Box<[f32; SIZE]>,
    pub z: Box<[f32; SIZE]>,
    pub intensity: Box<[f32; SIZE]>,
    pub ring: u16,
    pub length: usize,
    pub height: u32,
    pub width: u32,
    pub is_dense: bool,
    pub timestamp: i64,
}

impl<const SIZE: usize> PointCloud<SIZE> {
    pub const CAP: usize = SIZE;

    pub fn new() -> Self {
        Self {
            x: vec![0.0; SIZE].into_boxed_slice().try_into().unwrap(),
            y: vec![0.0; SIZE].into_boxed_slice().try_into().unwrap(),
            z: vec![0.0; SIZE].into_boxed_slice().try_into().unwrap(),
            intensity: vec![0.0; SIZE].into_boxed_slice().try_into().unwrap(),
            length: 0,
            width: 0,
            height: 0,
            ring: 0,
            timestamp: 0,
            is_dense: false,
        }
    }

    pub fn is_empty(&self) -> bool {
        return self.length == 0;
    }
}

impl<'a, const SIZE: usize> PointCloud<SIZE> {
    pub fn iter(&self) -> impl Iterator<Item = (&f32, &f32, &f32, &f32)> {
        let x_iter = self.x[..self.length].iter();
        let y_iter = self.y[..self.length].iter();
        let z_iter = self.z[..self.length].iter();
        let int_iter = self.intensity[..self.length].iter();

        x_iter
            .zip(y_iter)
            .zip(z_iter)
            .zip(int_iter)
            .map(|(((x, y), z), intensity)| (x, y, z, intensity))
    }

    pub fn len(&self) -> usize {
        self.length
    }

    pub fn compute_stats(&self) -> CloudStats {
        let mut cloud_stats = CloudStats::new();

        if self.length == 0 {
            return cloud_stats;
        }

        cloud_stats.n_points = self.length;

        let (mut sum_x, mut sum_y, mut sum_z) = (0.0f32, 0.0f32, 0.0f32);

        for (&x, &y, &z, _) in self.iter() {
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
        cloud_stats.width = self.width;
        cloud_stats.height = self.height;

        cloud_stats
    }

    pub fn to_rerun(&self) -> impl Iterator<Item = [f32; 3]> + '_ {
        let xs = self.x[..self.length].iter();
        let ys = self.y[..self.length].iter();
        let zs = self.z[..self.length].iter();

        xs.zip(ys).zip(zs).map(|((&x, &y), &z)| [x, y, z])
    }
}
