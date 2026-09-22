use std::sync::{Arc, RwLock};

use shared::{error::{AppError, ErrorType}, types::{AppPointCloud, ProcessingQueue}};

use crate::engine::types::Engine;

pub struct GPUEngine {
    point_cloud: Arc<RwLock<AppPointCloud>>,
}

impl GPUEngine {
    pub fn new(point_cloud : Arc<RwLock<AppPointCloud>>) -> Self {
        Self { point_cloud }
    }
}

impl Engine for GPUEngine {
    fn check(&self) -> Result<(), AppError> {
        Ok(())
    }
    fn transform_tunnel(&self) -> Result<(), AppError> {
        let queue = ProcessingQueue::READ;

        let cloud = self.point_cloud.write().expect(&format!(
            "⚠️ Мутекс отравился ☠️ {} {}",
            file!(),
            line!()
        ));

        let code = cuda_pipeline::normalize_tunnel_wrapped(cloud.x[queue].ptr, cloud.y[queue].ptr, cloud.z[queue].ptr);
        if code != 0 {
            return ErrorType::CudaError(code).err()
        }
        Ok(())
    }
}

pub fn pin_ptr(size : usize) ->  [*mut f32; 3] {
    cuda_pipeline::pin_gpu(size)
}