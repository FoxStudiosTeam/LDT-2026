use std::alloc::{Layout, alloc};

use shared::error::AppError;

use crate::engine::cpu_engine::CPUEngine;

pub trait Engine {
    fn check(&self) -> Result<bool, AppError>;
}

pub type AppEngine = CPUEngine;

pub fn pin_ptr(size : usize) -> [*mut f32; 3] {
    unsafe {
        let layout = Layout::array::<f32>(size).unwrap();
            
        let ptr1 = alloc(layout) as *mut f32;
        let ptr2 = alloc(layout) as *mut f32;
        let ptr3 = alloc(layout) as *mut f32;
            
        if ptr1.is_null() || ptr2.is_null() || ptr3.is_null() {
            std::alloc::handle_alloc_error(layout);
        }

        [ptr1, ptr2, ptr3]
    }
}