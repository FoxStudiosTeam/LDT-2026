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

        // 1. Фиксируем начальную точку A
        let a_point = (cloud.x[q][0], cloud.y[q][0], cloud.z[q][0]);

        // Находим точку B, которая физически дальше всего удалена от точки A в пространстве фрейма.
        // Это гарантирует, что вектор AB пройдет через ВСЮ длину тоннеля, а не схлопнется из-за шума.
        let mut max_dist_sq = 0.0;
        let mut b_point = a_point;

        for id in 1..count {
            let px = cloud.x[q][id];
            let py = cloud.y[q][id];
            let pz = cloud.z[q][id];
            
            let dx = px - a_point.0;
            let dy = py - a_point.1;
            let dz = pz - a_point.2;
            let dist_sq = dx * dx + dy * dy + dz * dz;
            
            if dist_sq > max_dist_sq {
                max_dist_sq = dist_sq;
                b_point = (px, py, pz);
            }
        }

        // 2. Считаем вектор идеальной оси AB
        let ab_x = b_point.0 - a_point.0;
        let ab_y = b_point.1 - a_point.1;
        let ab_z = b_point.2 - a_point.2;
        
        let len_sq = max_dist_sq; // Квадрат длины тоннеля равен максимальному расстоянию
        let len = len_sq.sqrt();
        
        // Порог безопасности увеличен до 1 см (0.0001 м²). 
        // Если фрейм короче 10 см, выпрямлять в нём нечего.
        if len_sq < 0.0001 {
            return Ok(()); 
        }
        
        // 3. Выпрямляем каждую точку тоннеля, сохраняя геометрию трубы
        for id in 0..count {
            // Читаем текущие кривые координаты
            let px = cloud.x[q][id];
            let py = cloud.y[q][id];
            let pz = cloud.z[q][id];

            // Вектор от начала тоннеля (A) до текущей точки
            let ap_x = px - a_point.0;
            let ap_y = py - a_point.1;
            let ap_z = pz - a_point.2;

            // Скалярное произведение и коэффициент проекции `t`
            let t = (ap_x * ab_x + ap_y * ab_y + ap_z * ab_z) / len_sq;

            // Идеологически правильная точка на центральной оси
            let a_ideal_x = a_point.0 + t * ab_x;
            let a_ideal_y = a_point.1 + t * ab_y;

            // Вектор отклонения стенки тоннеля от центральной оси (сечение трубы)
            let ox = px - a_ideal_x;
            let oy = py - a_ideal_y;

            // 4. Перезаписываем выпрямленные координаты на месте
            // ox и oy — сохраняют радиус и форму тоннеля вокруг оси
            cloud.x[q][id] = ox;
            cloud.y[q][id] = oy;
            // Координата Z превращается в идеальный продольный километраж (от 0.0 до len)
            cloud.z[q][id] = t * len;
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