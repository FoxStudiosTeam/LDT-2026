use std::{mem, ops::{Deref, DerefMut, Index, IndexMut}};

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
            width: 0,
            height: 0,
        }
    }
}


#[repr(C)]
pub struct CudaArray<const SIZE : usize> {
    pub ptr : *mut f32
}

unsafe impl<const SIZE: usize> Send for CudaArray<SIZE> {}
unsafe impl<const SIZE: usize> Sync for CudaArray<SIZE> {}

impl<const SIZE : usize> Deref for CudaArray<SIZE> {
     type Target = [f32];

    fn deref(&self) -> &Self::Target {
        if self.ptr.is_null() {
            panic!("Попытка разыменовать пустой указатель")
        }
        unsafe { std::slice::from_raw_parts(self.ptr, SIZE) }
    }
}

impl<const SIZE: usize> DerefMut for CudaArray<SIZE> {
    #[inline]
    fn deref_mut(&mut self) -> &mut Self::Target {
        if self.ptr.is_null() {
            panic!("Попытка разыменовать пустой указатель")
        }
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

pub const SIZE : usize = 2_000_000;

// 307_200
pub type AppPointCloud = PointCloud<SIZE>;

pub struct PointCloud<const SIZE: usize> {
    pub x: TripleBuffer<CudaArray<SIZE>>,
    pub y: TripleBuffer<CudaArray<SIZE>>,
    pub z: TripleBuffer<CudaArray<SIZE>>,
    pub intensity: TripleBuffer<CudaArray<SIZE>>,

    pub can_write : bool,

    pub ring : TripleBuffer<u16>,
    pub length: TripleBuffer<usize>,
    pub height : TripleBuffer<u32>,
    pub width : TripleBuffer<u32>,
    pub is_dense: TripleBuffer<bool>,
    pub timestamp: TripleBuffer<i64>,
}

impl<const SIZE : usize> PointCloud<SIZE> {
    pub const CAP : usize = SIZE;

    // Передавать нужно предварительно выделенные буфферы из графической памяти (DMA)
    pub fn new(
        x_ptrs: [*mut f32; 3],
        y_ptrs: [*mut f32; 3],
        z_ptrs: [*mut f32; 3],
        i_ptrs: [*mut f32; 3],
    ) -> Self {
        let make_fields = |ptrs: [*mut f32; 3]| [
            CudaArray { ptr: ptrs[0] },
            CudaArray { ptr: ptrs[1] },
            CudaArray { ptr: ptrs[2] }
        ];

        Self {
            x: TripleBuffer(make_fields(x_ptrs)),
            y: TripleBuffer(make_fields(y_ptrs)),
            z: TripleBuffer(make_fields(z_ptrs)),
            intensity: TripleBuffer(make_fields(i_ptrs)),
            can_write: true,

            length: TripleBuffer([0;3]),
            width: TripleBuffer([0;3]),
            height: TripleBuffer([0;3]),
            ring: TripleBuffer([0;3]),
            timestamp: TripleBuffer([0;3]),
            is_dense: TripleBuffer([false;3]),
        }
    }

    pub fn is_empty(&self, queue : ProcessingQueue) -> bool {
        return self.length[queue] == 0
    }
}

#[derive(Clone, Copy)]
pub enum ProcessingQueue {
    WRITE = 0,
    NEXT = 1,
    READ = 2,
}

impl ProcessingQueue {
    //  FSM состояний (Конечный автомат)
    #[inline(always)]
    pub fn next_step(&mut self){
        *self = match *self {
            ProcessingQueue::WRITE => ProcessingQueue::NEXT,
            ProcessingQueue::NEXT  => ProcessingQueue::READ,
            ProcessingQueue::READ  => ProcessingQueue::WRITE,
        };
    }
}

impl<'a, const SIZE : usize> PointCloud<SIZE> {
    pub fn iter(&self, queue: ProcessingQueue) -> impl Iterator<Item = (&f32, &f32, &f32, &f32)> {
        let x_iter = self.x[queue][..self.length[queue]].iter();
        let y_iter = self.y[queue][..self.length[queue]].iter();
        let z_iter = self.z[queue][..self.length[queue]].iter();
        let int_iter = self.intensity[queue][..self.length[queue]].iter();

        x_iter.zip(y_iter).zip(z_iter).zip(int_iter)
        .map(|(((x, y), z), intensity)| (x, y, z, intensity))
    }

    pub fn len(&self, queue: ProcessingQueue) -> usize {
        self.length[queue]
    }

    pub fn compute_stats(&self, queue: ProcessingQueue) -> CloudStats {
        let mut cloud_stats = CloudStats::new();
        
        if self.length[queue] == 0 {
            return cloud_stats
        }

        cloud_stats.n_points = self.length[queue];

        let (mut sum_x, mut sum_y, mut sum_z) = (0.0f32, 0.0f32, 0.0f32);

        for (&x,&y,&z,_) in self.iter(queue) {
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

        let count = self.length[queue] as f32;
        cloud_stats.centroid_x = sum_x / count;
        cloud_stats.centroid_y = sum_y / count;
        cloud_stats.centroid_z = sum_z / count;
        cloud_stats.width = self.width[queue];
        cloud_stats.height = self.height[queue];

        cloud_stats
    } 

    // Заменить на макросы но тогда копировать на стек self.$x и после этого уже без self
    pub fn change_state(&mut self, queue_old : ProcessingQueue, queue_new : ProcessingQueue) {
        if !self.can_write {
            return;
        }
        
        let mut ptr_old = self.x[queue_old].ptr;
        let mut ptr_new = self.x[queue_new].ptr;
        mem::swap(&mut ptr_old, &mut ptr_new);

        let mut ptr_old = self.y[queue_old].ptr;
        let mut ptr_new = self.y[queue_new].ptr;
        mem::swap(&mut ptr_old, &mut ptr_new);

        let mut ptr_old = self.z[queue_old].ptr;
        let mut ptr_new = self.z[queue_new].ptr;
        mem::swap(&mut ptr_old, &mut ptr_new);

        let mut ptr_old = self.intensity[queue_old].ptr;
        let mut ptr_new = self.intensity[queue_new].ptr;
        mem::swap(&mut ptr_old, &mut ptr_new);

        let mut ptr_old = self.length[queue_old];
        let mut ptr_new = self.length[queue_new];
        mem::swap(&mut ptr_old, &mut ptr_new);
    }

    pub fn to_rerun(&self, queue: ProcessingQueue) -> impl Iterator<Item = [f32; 3]> + '_ {
        let xs = self.x[queue][..self.length[queue]].iter();
        let ys = self.y[queue][..self.length[queue]].iter();
        let zs = self.z[queue][..self.length[queue]].iter();

        xs.zip(ys).zip(zs).map(|((&x, &y), &z)| [x, y, z])
    }

}

