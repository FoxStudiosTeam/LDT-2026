use std::sync::{Arc, RwLock};

use rerun::Color;
use shared::{error::AppError, types::{AppPointCloud, CudaArray, SIZE}};

use crate::engine::types::Engine;

pub struct CPUEngine {
    point_cloud: Arc<RwLock<AppPointCloud>>,
}

impl CPUEngine {
    pub fn new(point_cloud: Arc<RwLock<AppPointCloud>>) -> Self {
        Self { point_cloud }
    }
}

impl Engine for CPUEngine{
    fn check(&self) -> Result<bool, AppError> {
        Ok(false)
    }
    
    fn check_tunnel(&self) -> Result<(), AppError> {
        let mut point_cloud_guard = self.point_cloud.write().unwrap();
        point_cloud_guard.can_write = false;

        // Работаем строго с буфером NEXT, куда только что прилетел свежий своп из WRITE
        let q = shared::types::ProcessingQueue::NEXT;
        
        // ВАЖНО: Убедись, что len() возвращает размер СВЕЖЕГО кадра (307200), 
        // а не максимальную емкость статического буфера (например, 2_000_000).
        let points_len = point_cloud_guard.y[q].length; 
        if points_len == 0 {
            point_cloud_guard.can_write = true;
            return Ok(());
        }

        let slice_step = 1.5; 
        let pc = &mut *point_cloud_guard; 

        // Локальный дебаг-счетчик, очищается строго в 0 на каждом кадре
        let mut debug_counts = [0usize; 10];

        // Бежим строго по points_len. 
        // Если points_len равен 307200, цикл выполнится РОВНО 307200 раз.
        for idx in 0..points_len {
            let y_val = pc.y[q][idx];
            let absolute_y = y_val.abs();
            
            let slice_num = (absolute_y / slice_step) as usize;
            
            if slice_num < 10 {
                debug_counts[slice_num] += 1;
            }
            
            // Пишем цвет строго для текущего индекса кадра
            pc.colors[q][idx] = gen_color(slice_num);
        }

        // Дебаг-вывод покажет, очистился ли овердрайв памяти
        let total_counted: usize = debug_counts.iter().sum();
        println!("КАДР ИЗ ТРОЙНОГО БУФЕРА: обработано точек всего {}, в первых 10 слайсах: {}", points_len, total_counted);

        // Ротируем буфер дальше: NEXT -> READ для Rerun вьювера
        pc.change_state(q, shared::types::ProcessingQueue::READ);
        
        point_cloud_guard.can_write = true;
        Ok(())
    }

}

fn gen_color(slice_idx: usize) -> Color {
    let mut hash: u64 = 0xcbf29ce484222325;
    for byte in slice_idx.to_le_bytes() {
        hash ^= byte as u64;
        hash = hash.wrapping_mul(0x100000001b3);
    }

    let r_raw = (hash & 0xFF) as u8;
    let g_raw = ((hash >> 8) & 0xFF) as u8;
    let b_raw = ((hash >> 16) & 0xFF) as u8;

    let r = (r_raw >> 1) + 130;
    let g = (g_raw >> 1) + 130;
    let b = (b_raw >> 1) + 130;

    Color::from_rgb(r, g, b)
}