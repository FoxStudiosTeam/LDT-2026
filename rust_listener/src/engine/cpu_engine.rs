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
    
    // fn check_tunnel(&self) -> Result<(), AppError> {
    //     let mut point_cloud_guard = self.point_cloud.write().unwrap();
    //     point_cloud_guard.can_write = false;

    //     let q = shared::types::ProcessingQueue::NEXT;
    //     let points_len = point_cloud_guard.y[q].length; 
    //     if points_len == 0 {
    //         point_cloud_guard.can_write = true;
    //         return Ok(());
    //     }

    //     let slice_step = 1.5; 
    //     let pc = &mut *point_cloud_guard; 

    //     // --- ШАГ 1: Находим центр масс (средний X и Z) для каждого слайса ---
    //     // Допустим, у нас максимум 1000 слайсов в кадре (настрой под свой массив)
    //     let mut slice_centers_x = vec![0.0f32; 1000];
    //     let mut slice_centers_z = vec![0.0f32; 1000];
    //     let mut slice_point_counts = vec![0usize; 1000];

    //     for idx in 0..points_len {
    //         let y_val = pc.y[q][idx];
    //         let slice_num = (y_val.abs() / slice_step) as usize;
            
    //         if slice_num < 1000 {
    //             slice_centers_x[slice_num] += pc.x[q][idx];
    //             slice_centers_z[slice_num] += pc.z[q][idx];
    //             slice_point_counts[slice_num] += 1;
    //         }
    //     }

    //     // Вычисляем среднее арифметическое (координату центра оси) для каждого слайса
    //     for i in 0..1000 {
    //         if slice_point_counts[i] > 0 {
    //             slice_centers_x[i] /= slice_point_counts[i] as f32;
    //             slice_centers_z[i] /= slice_point_counts[i] as f32;
    //         }
    //     }

    //     // --- ШАГ 2: Смещаем точки к нулевой оси координат ---
    //     let mut debug_counts = [0usize; 10];

    //     for idx in 0..points_len {
    //         let y_val = pc.y[q][idx];
    //         let slice_num = (y_val.abs() / slice_step) as usize;
            
    //         if slice_num < 1000 {
    //             // Вычитаем координату центра этого слайса.
    //             // Вся форма туннеля (круглая, квадратная) и её объём сохраняются,
    //             // но сам слайс центрируется ровно по оси Y (0, 0).
    //             pc.x[q][idx] -= slice_centers_x[slice_num];
    //             pc.z[q][idx] -= slice_centers_z[slice_num];
    //         }

    //         if slice_num < 10 {
    //             debug_counts[slice_num] += 1;
    //         }
            
    //         pc.colors[q][idx] = gen_color(slice_num);
    //     }

    //     let total_counted: usize = debug_counts.iter().sum();
    //     println!("ВЫПРЯМЛЕННЫЙ КАДР: обработано точек {}, в первых 10 слайсах: {}", points_len, total_counted);

    //     pc.change_state(q, shared::types::ProcessingQueue::READ);
    //     point_cloud_guard.can_write = true;
    //     Ok(())
    // }

    fn check_tunnel(&self) -> Result<(), AppError> {
        let mut point_cloud_guard = self.point_cloud.write().unwrap();
        point_cloud_guard.can_write = false;

        let q = shared::types::ProcessingQueue::NEXT;
        let points_len = point_cloud_guard.y[q].length;

        if points_len == 0 {
            point_cloud_guard.can_write = true;
            return Ok(());
        }

        let pc = &mut *point_cloud_guard;

        // ============================================================
        // НАСТРОЙКИ
        // ============================================================

        let slice_step = 1.5f32;
        let max_slices = 1000usize;

        // Сильное сглаживание центральной линии.
        //
        // Чем больше window, тем сильнее убираются волны.
        //
        // 16-24  -> нормальное сглаживание
        // 24-35  -> очень сильное
        // 40+    -> может начать съедать реальный изгиб
        //
        let window = 24usize;

        let smoothing_passes = 2usize;

        // ============================================================
        // ШАГ 1.
        //
        // Находим центры сечений.
        //
        // ВАЖНО:
        // центры считаются только для построения ОСИ.
        // Мы НЕ будем просто переносить каждый чанк в (0,0).
        // ============================================================

        let mut slice_centers_x =
            vec![0.0f32; max_slices];

        let mut slice_centers_z =
            vec![0.0f32; max_slices];

        let mut slice_point_counts =
            vec![0usize; max_slices];

        let mut point_slices =
            vec![0usize; points_len];

        for idx in 0..points_len {
            let y = pc.y[q][idx];

            let mut slice_num =
                (y.abs() / slice_step) as usize;

            if slice_num >= max_slices {
                slice_num = max_slices - 1;
            }

            point_slices[idx] = slice_num;

            slice_centers_x[slice_num] +=
                pc.x[q][idx];

            slice_centers_z[slice_num] +=
                pc.z[q][idx];

            slice_point_counts[slice_num] += 1;
        }

        // ============================================================
        // ШАГ 2.
        //
        // Средние центры сечений.
        // ============================================================

        for i in 0..max_slices {
            if slice_point_counts[i] == 0 {
                continue;
            }

            let count =
                slice_point_counts[i] as f32;

            slice_centers_x[i] /= count;
            slice_centers_z[i] /= count;
        }

        // ============================================================
        // ШАГ 3.
        //
        // Сглаживаем центральную линию.
        //
        // Именно этот механизм у тебя давал наиболее стабильную
        // прямую в исходном варианте.
        // ============================================================

        let mut smoothed_x =
            slice_centers_x.clone();

        let mut smoothed_z =
            slice_centers_z.clone();

        for _ in 0..smoothing_passes {
            let current_x =
                smoothed_x.clone();

            let current_z =
                smoothed_z.clone();

            for i in 0..max_slices {
                if slice_point_counts[i] == 0 {
                    continue;
                }

                let start =
                    if i >= window {
                        i - window
                    } else {
                        0
                    };

                let end =
                    std::cmp::min(
                        max_slices,
                        i + window + 1,
                    );

                let mut sum_x = 0.0f32;
                let mut sum_z = 0.0f32;
                let mut count = 0usize;

                for j in start..end {
                    if slice_point_counts[j] == 0 {
                        continue;
                    }

                    sum_x += current_x[j];
                    sum_z += current_z[j];

                    count += 1;
                }

                if count > 0 {
                    smoothed_x[i] =
                        sum_x / count as f32;

                    smoothed_z[i] =
                        sum_z / count as f32;
                }
            }
        }

        // ============================================================
        // ШАГ 4.
        //
        // Ищем первый валидный slice.
        // ============================================================

        let first_slice =
            match slice_point_counts
                .iter()
                .position(|&count| count > 0)
            {
                Some(v) => v,

                None => {
                    point_cloud_guard.can_write = true;
                    return Ok(());
                }
            };

        // ============================================================
        // ШАГ 5.
        //
        // Фиксируем начальную точку оси.
        //
        // Весь туннель будет перенесён относительно неё.
        // ============================================================

        let origin_x =
            smoothed_x[first_slice];

        let origin_z =
            smoothed_z[first_slice];

        println!(
            "TUNNEL ORIGIN: slice={}, X={}, Z={}",
            first_slice,
            origin_x,
            origin_z
        );

        // ============================================================
        // ШАГ 6.
        //
        // СТРОИМ ПРЯМОЙ ТУННЕЛЬ.
        //
        // Важнейшая часть.
        //
        // Мы берём:
        //
        //     точка - сглаженная ось
        //
        // То есть сохраняем расстояние точки от оси.
        //
        // Но саму ось ставим в:
        //
        //     X = 0
        //     Z = 0
        //
        // В отличие от предыдущего варианта мы НЕ делаем
        // дополнительное масштабирование радиуса.
        // ============================================================

        let mut debug_counts =
            [0usize; 10];

        for idx in 0..points_len {
            let slice_num =
                point_slices[idx];

            if slice_point_counts[slice_num] == 0 {
                continue;
            }

            // --------------------------------------------------------
            // Исходная точка.
            // --------------------------------------------------------

            let old_x =
                pc.x[q][idx];

            let old_y =
                pc.y[q][idx];

            let old_z =
                pc.z[q][idx];

            // --------------------------------------------------------
            // Положение точки относительно СГЛАЖЕННОЙ оси.
            //
            // Вот это принципиально.
            //
            // НЕ:
            //
            //     old_x - raw_center_x
            //
            // а:
            //
            //     old_x - smoothed_axis_x
            //
            // Поэтому сохраняется внутренняя структура относительно
            // плавной оси, а мелкие движения самого центра убираются.
            // --------------------------------------------------------

            let local_x =
                old_x - smoothed_x[slice_num];

            let local_z =
                old_z - smoothed_z[slice_num];

            // --------------------------------------------------------
            // Ставим ось в X/Z = 0.
            // --------------------------------------------------------

            pc.x[q][idx] =
                local_x;

            pc.z[q][idx] =
                local_z;

            // --------------------------------------------------------
            // Y делаем строго линейным.
            //
            // Это та часть, которая давала прямой результат
            // в твоём первоначальном варианте.
            // --------------------------------------------------------

            let direction_sign =
                if old_y >= 0.0 {
                    1.0
                } else {
                    -1.0
                };

            let linear_y =
                (slice_num as f32
                    - first_slice as f32)
                    * slice_step;

            pc.y[q][idx] =
                direction_sign * linear_y;

            // --------------------------------------------------------
            // Цвет.
            // --------------------------------------------------------

            if slice_num < 10 {
                debug_counts[slice_num] += 1;
            }

            pc.colors[q][idx] =
                gen_color(slice_num);
        }

        // ============================================================
        // ШАГ 7.
        //
        // Статистика.
        // ============================================================

        let total_counted: usize =
            debug_counts.iter().sum();

        println!(
            "ВЫПРЯМЛЕННЫЙ ТУННЕЛЬ: \
            обработано точек={}, \
            первые 10 чанков={}",
            points_len,
            total_counted
        );

        println!(
            "SMOOTHING: window={}, passes={}",
            window,
            smoothing_passes
        );

        // ============================================================
        // Готово.
        // ============================================================

        pc.change_state(
            q,
            shared::types::ProcessingQueue::READ,
        );

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