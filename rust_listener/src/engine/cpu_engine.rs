use std::{alloc::{Layout, alloc}, sync::{Arc, RwLock}};

use shared::{error::AppError, types::AppPointCloud};
use tracing::debug;

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
    fn check(&self) -> Result<(), AppError> {
        Ok(())
    }
    
    fn transform_tunnel(&self) -> Result<(), AppError> {
        let mut cloud = self.point_cloud.write().unwrap();
        let q = shared::types::ProcessingQueue::READ;
        
        let count = cloud.len(q);
        if count < 2 {
            return Ok(());
        }

        debug!("[TRANSFORM TUNNEL] entry");

        // 1. Находим базовую ось тоннеля
        let a_point = (cloud.x[q], cloud.y[q], cloud.z[q]);
        let mut max_dist_sq = 0.0;
        let mut b_point = a_point;

        for id in 1..count {
            let px = cloud.x[q][id];
            let py = cloud.y[q][id];
            let pz = cloud.z[q][id];
            
            let dx = px - a_point.0[id];
            let dy = py - a_point.1[id];
            let dz = pz - a_point.2[id];
            let dist_sq = dx * dx + dy * dy + dz * dz;
            
            if dist_sq > max_dist_sq {
                max_dist_sq = dist_sq;
                b_point = (px, py, pz);
            }
        }

        // Вектор направления тоннеля (AB)
        let mut ab_x = b_point.0 - a_point.0;
        let mut ab_y = b_point.1 - a_point.1;
        let mut ab_z = b_point.2 - a_point.2;
        
        let len_sq = max_dist_sq;
        let len = len_sq.sqrt();
        
        if len_sq < 0.0001 {
            return Ok(()); 
        }

        // Нормализуем вектор оси (делаем его длину равной 1.0)
        let dir_x = ab_x / len;
        let dir_y = ab_y / len;
        let dir_z = ab_z / len;

        // 2. СТРОИМ ЛОКАЛЬНЫЙ БАЗИС ДЛЯ ТРУБЫ (чтобы избежать сплющивания)
        // Нам нужны два вектора (Up и Right), которые строго перпендикулярны оси тоннеля
        let mut up_x = 0.0;
        let mut up_y = 1.0;
        let mut up_z = 0.0;

        // Если тоннель идет вертикально вверх, меняем опорный вектор, чтобы не было деления на ноль
        if dir_y.abs() > 0.9 {
            up_x = 1.0;
            up_y = 0.0;
        }

        // Вектор Right (вбок от оси тоннеля) через векторное произведение
        let r_x = dir_y * up_z - dir_z * up_y;
        let r_y = dir_z * up_x - dir_x * up_z;
        let r_z = dir_x * up_y - dir_y * up_x;
        let r_len = (r_x * r_x + r_y * r_y + r_z * r_z).sqrt();
        let r_x = r_x / r_len;
        let r_y = r_y / r_len;
        let r_z = r_z / r_len;

        // Вектор Up (вверх от оси тоннеля) под честным углом 90 градусов
        let u_x = r_y * dir_z - r_z * dir_y;
        let u_y = r_z * dir_x - r_x * dir_z;
        let u_z = r_x * dir_y - r_y * dir_x;

        // 3. ТРАНСФОРМАЦИЯ
        for id in 0..count {
            let px = cloud.x[q][id];
            let py = cloud.y[q][id];
            let pz = cloud.z[q][id];

            let ap_x = px - a_point.0;
            let ap_y = py - a_point.1;
            let ap_z = pz - a_point.2;

            // Координата `t_dist` — это честное расстояние в метрах вдоль тоннеля
            let t_dist = ap_x * dir_x + ap_y * dir_y + ap_z * dir_z;

            // Проецируем точку на наши новые перпендикулярные оси, чтобы узнать 
            // её реальный сдвиг ВБОК (lateral) и ВВЕРХ (vertical) относительно трубы
            let lateral = ap_x * r_x + ap_y * r_y + ap_z * r_z;
            let vertical = ap_x * u_x + ap_y * u_y + ap_z * u_z;

            // Записываем выпрямленные координаты:
            // Теперь труба гарантированно круглая, не плоская и идет ровно по оси Z
            cloud.x[q][id] = lateral;
            cloud.y[q][id] = vertical;
            cloud.z[q][id] = t_dist;
        }

        debug!("[TRANSFORM TUNNEL] end");
        Ok(())
    }
}

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