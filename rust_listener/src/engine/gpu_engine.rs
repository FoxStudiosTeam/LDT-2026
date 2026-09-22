use std::sync::{Arc, RwLock};

use shared::{error::AppError, types::AppPointCloud};

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
    fn check(&self) -> Result<bool, AppError> {
        Ok(false)
    }
}