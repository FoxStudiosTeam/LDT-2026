use std::fmt;
use std::ops::{Deref, DerefMut, Index, IndexMut};

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

/// Проверка, является ли точка началом координат с запасом 5 мм (0.005 м)
#[inline(always)]
pub fn is_zero_point(x: f32, y: f32, z: f32) -> bool {
    x.abs() <= 0.005 && y.abs() <= 0.005 && z.abs() <= 0.005
}

#[repr(C)]
pub struct CudaU16Array<const SIZE: usize> {
    pub ptr: *mut u16,
    pub length: usize,
}

impl<const SIZE: usize> CudaU16Array<SIZE> {
    pub fn get(&self, index: usize) -> Option<u16> {
        if index >= self.length || self.ptr.is_null() {
            return None;
        }
        unsafe { Some(*self.ptr.add(index)) }
    }

    // Теперь берет истинный последний элемент, а не физический конец капы
    pub fn last(&self) -> Option<&u16> {
        if self.length == 0 || self.ptr.is_null() {
            return None;
        }

        unsafe {
            let last_ptr = self.ptr.add(self.length - 1);
            Some(&*last_ptr)
        }
    }

    pub fn push(&mut self, value: u16) {
        if self.length == SIZE {
            return;
        }
        unsafe {
            let write_ptr = self.ptr.add(self.length);
            *write_ptr = value;
        }
        self.length += 1;
    }

    // Сброс счетчика перед новым циклом записи из ROS2
    #[inline(always)]
    pub fn clear(&mut self) {
        self.length = 0;
    }

    #[inline(always)]
    pub fn cap(&self) -> usize {
        SIZE
    }
}

unsafe impl<const SIZE: usize> Send for CudaU16Array<SIZE> {}
unsafe impl<const SIZE: usize> Sync for CudaU16Array<SIZE> {}

impl<const SIZE: usize> Deref for CudaU16Array<SIZE> {
    type Target = [u16];

    fn deref(&self) -> &Self::Target {
        if self.ptr.is_null() {
            panic!("Попытка разыменовать пустой указатель")
        }
        // Создаем слайс только до РЕАЛЬНОЙ заполненной длины
        unsafe { std::slice::from_raw_parts(self.ptr, SIZE) }
    }
}

impl<const SIZE: usize> DerefMut for CudaU16Array<SIZE> {
    #[inline]
    fn deref_mut(&mut self) -> &mut Self::Target {
        if self.ptr.is_null() {
            panic!("Попытка разыменовать пустой указатель")
        }
        // Создаем слайс только до РЕАЛЬНОЙ заполненной длины
        unsafe { std::slice::from_raw_parts_mut(self.ptr, SIZE) }
    }
}

#[repr(C)]
pub struct CudaArray<const SIZE: usize> {
    pub ptr: *mut f32,
    pub length: usize,
}

impl<const SIZE: usize> CudaArray<SIZE> {
    pub fn get(&self, index: usize) -> Option<f32> {
        if index >= self.length || self.ptr.is_null() {
            return None;
        }
        unsafe { Some(*self.ptr.add(index)) }
    }

    // Теперь берет истинный последний элемент, а не физический конец капы
    pub fn last(&self) -> Option<&f32> {
        if self.length == 0 || self.ptr.is_null() {
            return None;
        }

        unsafe {
            let last_ptr = self.ptr.add(self.length - 1);
            Some(&*last_ptr)
        }
    }

    pub fn push(&mut self, value: f32) {
        if self.length == SIZE {
            return;
        }
        unsafe {
            let write_ptr = self.ptr.add(self.length);
            *write_ptr = value;
        }
        self.length += 1;
    }

    // Сброс счетчика перед новым циклом записи из ROS2
    #[inline(always)]
    pub fn clear(&mut self) {
        self.length = 0;
    }

    #[inline(always)]
    pub fn cap(&self) -> usize {
        SIZE
    }
}

unsafe impl<const SIZE: usize> Send for CudaArray<SIZE> {}
unsafe impl<const SIZE: usize> Sync for CudaArray<SIZE> {}

impl<const SIZE: usize> Deref for CudaArray<SIZE> {
    type Target = [f32];

    fn deref(&self) -> &Self::Target {
        if self.ptr.is_null() {
            panic!("Попытка разыменовать пустой указатель")
        }
        // Создаем слайс только до РЕАЛЬНОЙ заполненной длины
        unsafe { std::slice::from_raw_parts(self.ptr, SIZE) }
    }
}

impl<const SIZE: usize> DerefMut for CudaArray<SIZE> {
    #[inline]
    fn deref_mut(&mut self) -> &mut Self::Target {
        if self.ptr.is_null() {
            panic!("Попытка разыменовать пустой указатель")
        }
        // Создаем слайс только до РЕАЛЬНОЙ заполненной длины
        unsafe { std::slice::from_raw_parts_mut(self.ptr, SIZE) }
    }
}

pub struct TripleBuffer<T>(pub [T; 3]);

impl<T> Index<ProcessingQueue> for TripleBuffer<T> {
    type Output = T;

    #[inline(always)]
    fn index(&self, queue: ProcessingQueue) -> &Self::Output {
        &self.0[queue as usize]
    }
}

impl<T> IndexMut<ProcessingQueue> for TripleBuffer<T> {
    #[inline(always)]
    fn index_mut(&mut self, queue: ProcessingQueue) -> &mut Self::Output {
        &mut self.0[queue as usize]
    }
}

pub const SIZE: usize = 2_000_000;
pub type AppPointCloud = PointCloud<SIZE>;

pub struct PointCloud<const SIZE: usize> {
    pub x: TripleBuffer<CudaArray<SIZE>>,
    pub y: TripleBuffer<CudaArray<SIZE>>,
    pub z: TripleBuffer<CudaArray<SIZE>>,
    pub intensity: TripleBuffer<CudaArray<SIZE>>,

    pub can_write: bool,

    pub ring: TripleBuffer<CudaU16Array<SIZE>>,
    // Дублирующее поле "pub length: TripleBuffer<usize>" удалено, чтобы избежать рассинхронизации.
    pub height: TripleBuffer<u32>,
    pub width: TripleBuffer<u32>,
    pub is_dense: TripleBuffer<bool>,
    pub timestamp: TripleBuffer<i64>,
}

impl<const SIZE: usize> PointCloud<SIZE> {
    pub const CAP: usize = SIZE;

    pub fn clear(&mut self, queue: ProcessingQueue) {
        self.x[queue].clear();
        self.y[queue].clear();
        self.z[queue].clear();
        self.intensity[queue].clear();
        self.ring[queue].clear();
    }

    pub fn new(
        x_ptrs: [*mut f32; 3],
        y_ptrs: [*mut f32; 3],
        z_ptrs: [*mut f32; 3],
        i_ptrs: [*mut f32; 3],
        r_ptrs: [*mut u16; 3],
    ) -> Self {
        let make_fields = |ptrs: [*mut f32; 3]| {
            [
                CudaArray {
                    ptr: ptrs[0],
                    length: 0,
                },
                CudaArray {
                    ptr: ptrs[1],
                    length: 0,
                },
                CudaArray {
                    ptr: ptrs[2],
                    length: 0,
                },
            ]
        };

        let make_ring_fields = |ptrs: [*mut u16; 3]| {
            [
                CudaU16Array {
                    ptr: ptrs[0],
                    length: 0,
                },
                CudaU16Array {
                    ptr: ptrs[1],
                    length: 0,
                },
                CudaU16Array {
                    ptr: ptrs[2],
                    length: 0,
                },
            ]
        };

        Self {
            x: TripleBuffer(make_fields(x_ptrs)),
            y: TripleBuffer(make_fields(y_ptrs)),
            z: TripleBuffer(make_fields(z_ptrs)),
            intensity: TripleBuffer(make_fields(i_ptrs)),
            can_write: true,

            width: TripleBuffer([0; 3]),
            height: TripleBuffer([0; 3]),
            ring: TripleBuffer(make_ring_fields(r_ptrs)),
            timestamp: TripleBuffer([0; 3]),
            is_dense: TripleBuffer([false; 3]),
        }
    }

    #[inline(always)]
    pub fn is_empty(&self, queue: ProcessingQueue) -> bool {
        self.len(queue) == 0
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ProcessingQueue {
    WRITE = 0,
    NEXT = 1,
    READ = 2,
}

impl ProcessingQueue {
    #[inline(always)]
    pub fn next_step(&mut self) {
        *self = match *self {
            ProcessingQueue::WRITE => ProcessingQueue::NEXT,
            ProcessingQueue::NEXT => ProcessingQueue::READ,
            ProcessingQueue::READ => ProcessingQueue::WRITE,
        };
    }
}

impl fmt::Display for ProcessingQueue {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let numeric_value = *self as u8;
        write!(f, "Current state: {}", numeric_value)
    }
}

impl<const SIZE: usize> PointCloud<SIZE> {
    pub fn iter(&self, queue: ProcessingQueue) -> impl Iterator<Item = (&f32, &f32, &f32, &f32, &u16)> {
        let len = self.len(queue);
        let x_iter = self.x[queue][..len].iter();
        let y_iter = self.y[queue][..len].iter();
        let z_iter = self.z[queue][..len].iter();
        let int_iter = self.intensity[queue][..len].iter();
        let r_iter = self.ring[queue][..len].iter();

        x_iter
            .zip(y_iter)
            .zip(z_iter)
            .zip(int_iter)
            .zip(r_iter)
            .map(|((((x, y), z), intensity), ring)| (x, y, z, intensity, ring))
    }

    #[inline(always)]
    pub fn len(&self, queue: ProcessingQueue) -> usize {
        // Истинная длина теперь живет внутри CudaArray (x == y == z)
        self.x[queue].length
    }

    pub fn compute_stats(&self, queue: ProcessingQueue) -> CloudStats {
        let mut cloud_stats = CloudStats::new();
        let current_len = self.len(queue);

        tracing::debug!("Len: {}", current_len);

        if current_len == 0 {
            return cloud_stats;
        }

        let (mut sum_x, mut sum_y, mut sum_z) = (0.0f32, 0.0f32, 0.0f32);
        let mut valid_count = 0usize;

        for (&x, &y, &z, _, _) in self.iter(queue) {
            if is_zero_point(x, y, z) {
                continue;
            }
            valid_count += 1;
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

        cloud_stats.n_points = valid_count;
        if valid_count > 0 {
            let count = valid_count as f32;
            cloud_stats.centroid_x = sum_x / count;
            cloud_stats.centroid_y = sum_y / count;
            cloud_stats.centroid_z = sum_z / count;
        } else {
            cloud_stats.min_x = 0.0;
            cloud_stats.min_y = 0.0;
            cloud_stats.min_z = 0.0;
            cloud_stats.max_x = 0.0;
            cloud_stats.max_y = 0.0;
            cloud_stats.max_z = 0.0;
        }
        cloud_stats.width = self.width[queue];
        cloud_stats.height = self.height[queue];

        cloud_stats
    }

    pub fn change_state(&mut self, queue_old: ProcessingQueue, queue_new: ProcessingQueue) {
        let idx_old = queue_old as usize;
        let idx_new = queue_new as usize;

        if idx_old == idx_new {
            return;
        }

        self.x.0.swap(idx_old, idx_new);
        self.y.0.swap(idx_old, idx_new);
        self.z.0.swap(idx_old, idx_new);
        self.intensity.0.swap(idx_old, idx_new);

        self.width.0.swap(idx_old, idx_new);
        self.height.0.swap(idx_old, idx_new);
        self.timestamp.0.swap(idx_old, idx_new);
        self.ring.0.swap(idx_old, idx_new);
        self.is_dense.0.swap(idx_old, idx_new);
    }

    pub fn to_rerun(&self, queue: ProcessingQueue) -> impl Iterator<Item = [f32; 3]> + '_ {
        let len = self.len(queue);
        let xs = self.x[queue][..len].iter();
        let ys = self.y[queue][..len].iter();
        let zs = self.z[queue][..len].iter();

        xs.zip(ys)
            .zip(zs)
            .filter(|((x, y), z)| !is_zero_point(**x, **y, **z))
            .map(|((&x, &y), &z)| [x, y, z])
    }
}
