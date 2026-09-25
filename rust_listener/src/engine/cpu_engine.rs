use std::sync::{Arc, RwLock};

use rerun::Color;
<<<<<<< HEAD
use shared::{
    error::AppError,
    types::{AppPointCloud, CudaArray, SIZE},
};
=======
use tracing::info;
use shared::{error::AppError, types::{AppPointCloud, CudaArray, SIZE}};
>>>>>>> c6b1007537a06ae0674b046bbf98dec400e707f3

use crate::engine::types::Engine;

pub struct CPUEngine {
    point_cloud: Arc<RwLock<AppPointCloud>>,
}

impl CPUEngine {
    pub fn new(point_cloud: Arc<RwLock<AppPointCloud>>) -> Self {
        Self { point_cloud }
    }
}

impl Engine for CPUEngine {
    fn check(&self) -> Result<bool, AppError> {
        Ok(false)
    }

    fn check_tunnel(&self) -> Result<(), AppError> {
        let mut point_cloud_guard = self.point_cloud.write().unwrap();
        point_cloud_guard.can_write = false;

        let q = shared::types::ProcessingQueue::NEXT;
        let points_len = point_cloud_guard.y[q].length; 
        if points_len == 0 {
            point_cloud_guard.can_write = true;
            return Ok(());
        }

        let slice_step = 1.5; 
        let pc = &mut *point_cloud_guard; 

        // Массивы для аналитики оси (если они используются где-то еще в кодовой базе)
        let mut slice_centers_x = vec![0.0f32; 1000];
        let mut slice_centers_z = vec![0.0f32; 1000];
        let mut slice_point_counts = vec![0usize; 1000];

        // --- ШАГ 1: Сбор точек для аналитики оси ---
        for idx in 0..points_len {
            let x_val = pc.x[q][idx];
            let z_val = pc.z[q][idx];
            let y_val = pc.y[q][idx];
            
            if z_val > 0.5 && (x_val.abs() > 1.4 && x_val.abs() < 3.0) {
                let slice_num = (y_val.abs() / slice_step) as usize;
                if slice_num < 1000 {
                    slice_centers_x[slice_num] += x_val;
                    slice_centers_z[slice_num] += z_val;
                    slice_point_counts[slice_num] += 1;
                }
            }
        }

        // --- ШАГ 2: Базовый расчет центров ---
        for i in 0..1000 {
            if slice_point_counts[i] > 10 {
                slice_centers_x[i] /= slice_point_counts[i] as f32;
                slice_centers_z[i] = (slice_centers_z[i] / slice_point_counts[i] as f32) - 1.2;
            }
        }

        // --- ШАГ 3: Проверка жесткого габарита ПТЭ от (0,0,0) лидара ---
        for idx in 0..points_len {
            let y_val = pc.y[q][idx];
            let slice_num = (y_val.abs() / slice_step) as usize;
            
            // ВАЖНО: Мы берем исходные x и z напрямую из облака точек, 
            // БЕЗ вычитания smooth_centers, так как габарит ПТЭ привязан к поезду/лидару!
            let raw_x = pc.x[q][idx];
            let raw_z = pc.z[q][idx];
            
            let in_pt_clearance = (raw_x >= -1.55 && raw_x <= 1.55) && (raw_z >= -1.7 && raw_z <= 2.4);

            if in_pt_clearance {
                // Любая точка, нарушившая габарит относительно лидара — КРАСНАЯ
                pc.colors[q][idx] = Color::from_rgb(255, 0, 0); 
            } else {
                // Все, что вне габарита (стены тоннеля) — красится в цвет слайса
                pc.colors[q][idx] = gen_color(slice_num);
            }
        }

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
