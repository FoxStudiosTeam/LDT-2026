use std::sync::{
    Arc, RwLock,
    atomic::{AtomicUsize, Ordering},
};

use rerun::RecordingStream;
use ros2_data_extraction::PointCloudStream;
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;
use shared::error::{AppError, ErrCtx, ErrorType};
use shared::types::AppPointCloud;
use tokio::{sync::Semaphore, time};
use tracing::*;

use crate::debug;

struct TaskGuard {
    counter: Arc<AtomicUsize>,
}

impl Drop for TaskGuard {
    fn drop(&mut self) {
        // Гарантированный декремент при любом исходе (паника, ошибка, выход)
        self.counter.fetch_sub(1, Ordering::SeqCst);
    }
}

pub async fn entry(
    mut point_cloud_stream: PointCloudStream,
    recording_stream: RecordingStream,
    point_cloud: Arc<RwLock<AppPointCloud>>,
) -> Result<(), AppError> {
    let mut frame_id: u64 = 0;
    let recording_stream = Arc::new(recording_stream);
    let active_tasks = Arc::new(AtomicUsize::new(0));

    recording_stream
        .log("point", &rerun::Points3D::new([(0.0, 0.0, 0.0)]))
        .app_error()?;

    // while let Some(a) = point_cloud_stream.next().await? {
    while let Ok((pc, _msg)) = point_cloud_stream.subscription.async_take().await {
        // info!("[Frame {a}] frame took");
        info!("frame took");
        let re = recording_stream.clone();
        tokio::task::spawn_blocking(move || {
            let parsed = parse_coords(&pc).app_error().unwrap();
            re.log("points", &rerun::Points3D::new(&parsed))
                .app_error()
                .unwrap();
        });

        // frame_id = a;

        // // 2. Проверяем лимит без блокировок
        // if active_tasks.load(Ordering::Relaxed) >= 4 {
        //     info!("Скипаем кадр {}, так как обработка перегружена", frame_id);
        //     continue;
        // }

        // // 3. Инкрементируем счетчик перед спавном
        // active_tasks.fetch_add(1, Ordering::SeqCst);

        // let point_cloud = point_cloud.clone();
        // let recording_stream = recording_stream.clone();
        // let active_tasks_clone = active_tasks.clone();

        // tokio::spawn(async move {
        //     // 4. Активируем гвард. Как только таска завершится или упадет — счетчик уменьшится
        //     let _guard = TaskGuard {
        //         counter: active_tasks_clone,
        //     };
        //     let point_cloud_lock = point_cloud.clone();
        //     tokio::task::spawn_blocking(move || {
        //         {
        //             let mut point_cloud_write = point_cloud_lock.write().expect(&format!(
        //                 "⚠️ Мутекс отравился ☠️ {} {}",
        //                 file!(),
        //                 line!()
        //             ));
        //             point_cloud_write.can_write = false;
        //             point_cloud_write.change_state(
        //                 shared::types::ProcessingQueue::NEXT,
        //                 shared::types::ProcessingQueue::READ,
        //             );
        //             point_cloud_write.can_write = true;
        //         }

        //         let point_cloud = point_cloud_lock.read().expect(&format!(
        //             "⚠️ Мутекс отравился ☠️ {} {}",
        //             file!(),
        //             line!()
        //         ));

        //         let number = shared::types::ProcessingQueue::READ;

        //         let timestamp_ns = point_cloud.timestamp[number];
        //         let stats = point_cloud.compute_stats(number);

        //         debug::std::print_frame_info(frame_id, timestamp_ns, &stats);
        //         recording_stream.set_time(
        //             "ros_time",
        //             rerun::TimeCell::from_duration_nanos(timestamp_ns),
        //         );
        //         recording_stream.set_time_sequence("frame", frame_id as i64);

        //         // Пушим данные в сеть (Rerun визуализация)
        //         if let Err(e) = debug::helper::log_raw_cloud(&recording_stream, &point_cloud) {
        //             error!("Ошибка логирования облака точек в rerun: {e:?}");
        //         }
        //         if let Err(e) =
        //             debug::helper::log_debug_overlays(&recording_stream, &point_cloud, &stats)
        //         {
        //             error!("Ошибка логирования оверлеев в rerun: {e:?}");
        //         }
        //     })
        //     .await
        //     .unwrap();
        // });
    }

    Ok(())
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Point {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub intensity: f32,
}

impl From<&Point> for rerun::Position3D {
    #[inline]
    fn from(p: &Point) -> Self {
        rerun::Position3D::new(p.x, p.y, p.z)
    }
}

pub fn parse_coords(pc: &PointCloud2) -> Result<Vec<Point>, AppError> {
    let width = pc.width as usize;
    let height = pc.height as usize;
    let point_step = pc.point_step as usize;

    let total_points = width.checked_mul(height).ok_or_else(|| {
        ErrorType::message(format!(
            "Overflow calculating total points: {}x{}",
            width, height
        ))
    })?;

    // Поиск смещений полей
    let x_field = pc
        .fields
        .iter()
        .find(|f| f.name == "x")
        .ok_or(ErrorType::NoneError("field 'x' not found"))?;
    let y_field = pc
        .fields
        .iter()
        .find(|f| f.name == "y")
        .ok_or(ErrorType::NoneError("field 'y' not found"))?;
    let z_field = pc
        .fields
        .iter()
        .find(|f| f.name == "z")
        .ok_or(ErrorType::NoneError("field 'z' not found"))?;
    let i_field = pc
        .fields
        .iter()
        .find(|f| f.name == "intensity")
        .ok_or(ErrorType::NoneError("field 'intensity' not found"))?;

    let x_off = x_field.offset as usize;
    let y_off = y_field.offset as usize;
    let z_off = z_field.offset as usize;
    let i_off = i_field.offset as usize;

    // Валидация: смещения полей должны умещаться в размер одной точки (4 байта на f32)
    if x_off + 4 > point_step
        || y_off + 4 > point_step
        || z_off + 4 > point_step
        || i_off + 4 > point_step
    {
        return Err(
            ErrorType::message("Field offset is out of point_step bounds".to_string()).into(),
        );
    }

    let is_bigendian = pc.is_bigendian;
    let mut result = Vec::with_capacity(total_points);

    // Функция чтения f32 с учетом endianness и возможной невыровненности памяти
    #[inline(always)]
    unsafe fn read_f32_unaligned(ptr: *const u8, offset: usize, is_bigendian: bool) -> f32 {
        let raw_bytes = std::ptr::read_unaligned(ptr.add(offset) as *const u32);
        let bits = if is_bigendian {
            u32::from_be(raw_bytes)
        } else {
            u32::from_le(raw_bytes)
        };
        f32::from_bits(bits)
    }

    let point_chunks = pc.data.chunks_exact(point_step).take(total_points);

    for point_buf in point_chunks {
        let ptr = point_buf.as_ptr();

        let (x, y, z, intensity) = unsafe {
            (
                read_f32_unaligned(ptr, x_off, is_bigendian),
                read_f32_unaligned(ptr, y_off, is_bigendian),
                read_f32_unaligned(ptr, z_off, is_bigendian),
                read_f32_unaligned(ptr, i_off, is_bigendian),
            )
        };

        // Игнорируем точки с NaN (если точка «пустая»)
        if pc.is_dense || (!x.is_nan() && !y.is_nan() && !z.is_nan()) {
            result.push(Point { x, y, z, intensity });
        }
    }

    Ok(result)
}
