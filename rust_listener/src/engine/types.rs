use std::alloc::{Layout, alloc};

use shared::error::AppError;

use crate::engine::cpu_engine::CPUEngine;

pub trait Engine {
    fn check(&self) -> Result<bool, AppError>;
    fn check_tunnel(&self) -> Result<(),AppError>;
}

pub type AppEngine = CPUEngine;

pub fn pin_ptr<T: Copy>(size : usize) -> [*mut T; 3] {
    unsafe {
        let layout = Layout::array::<T>(size).unwrap();
            
        let ptr1 = alloc(layout) as *mut T;
        let ptr2 = alloc(layout) as *mut T;
        let ptr3 = alloc(layout) as *mut T;
            
        if ptr1.is_null() || ptr2.is_null() || ptr3.is_null() {
            std::alloc::handle_alloc_error(layout);
        }

        [ptr1, ptr2, ptr3]
    }
}