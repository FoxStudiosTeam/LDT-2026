use std::alloc::{Layout, alloc};

use shared::error::AppError;

use crate::engine::cpu_engine::{self, CPUEngine};
#[cfg(feature = "gpu")]
use crate::engine::gpu_engine::{self, GPUEngine};

pub trait Engine {
    fn check(&self) -> Result<(), AppError>;
    fn transform_tunnel(&self) -> Result<(), AppError>;
}

#[cfg(feature = "cpu")]
pub type AppEngine = CPUEngine;

#[cfg(feature = "gpu")]
pub type AppEngine = GPUEngine;

#[cfg(feature = "cpu")]
use cpu_engine as active_engine;

#[cfg(feature = "gpu")]
use gpu_engine as active_engine;

pub fn pin_ptr(size: usize) -> [*mut f32; 3] {
    active_engine::pin_ptr(size)
}