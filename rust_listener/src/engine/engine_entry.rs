use std::{
    sync::{
        Arc, RwLock,
        atomic::{AtomicUsize, Ordering},
    },
    time::Duration,
};

use rerun::RecordingStream;
use ros2_data_extraction::PointCloudStream;
use shared::error::AppError;
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

    while let Some(a) = point_cloud_stream.next().await? {
        frame_id = a;

        info!("[Frame {a}] frame took");

        info!("[Frame {a}]");

        // 2. Проверяем лимит без блокировок
        if active_tasks.load(Ordering::Relaxed) >= 4 {
            info!("Скипаем кадр {}, так как обработка перегружена", frame_id);
            continue;
        }

        // 3. Инкрементируем счетчик перед спавном
        active_tasks.fetch_add(1, Ordering::SeqCst);

        let point_cloud = point_cloud.clone();
        let recording_stream = recording_stream.clone();
        let active_tasks_clone = active_tasks.clone();

        tokio::spawn(async move {
            // 4. Активируем гвард. Как только таска завершится или упадет — счетчик уменьшится
            let _guard = TaskGuard {
                counter: active_tasks_clone,
            };
            let point_cloud_lock = point_cloud.clone();

            //deadlock😎

            // tokio::task::spawn_blocking(move || {
            //
            //     let mut point_cloud_write = point_cloud_lock.write().expect(&format!("⚠️ Мутекс отравился ☠️ {} {}", file!(), line!()));
            //     {
            //         point_cloud_write.can_write = false;
            //         point_cloud_write.change_state(shared::types::ProcessingQueue::NEXT, shared::types::ProcessingQueue::READ);
            //         point_cloud_write.can_write = true;
            //     }
            //
                let point_cloud = point_cloud_lock
                    .read()
                    // отъебнет так, что в логах не покажется
                    // .map_err(|e| Error::AbstractError { msg: e.to_string() }).unwrap()
                    .expect(&format!("⚠️ Мутекс отравился ☠️ {} {}", file!(), line!()));
                let number = shared::types::ProcessingQueue::READ;

                let timestamp_ns = point_cloud.timestamp[number];
                let stats = point_cloud.compute_stats(number);

                debug::std::print_frame_info(frame_id, timestamp_ns, &stats);
                recording_stream.set_time(
                    "ros_time",
                    rerun::TimeCell::from_duration_nanos(timestamp_ns),
                );
                recording_stream.set_time_sequence("frame", frame_id as i64);

                // Пушим данные в сеть (Rerun визуализация)
                debug::helper::log_raw_cloud(&recording_stream, &point_cloud).unwrap();
                debug::helper::log_debug_overlays(&recording_stream, &point_cloud, &stats)
                    // .map_err(|e| Error::AbstractError { msg: e.to_string() })
                    .expect(&format!("⚠️ Мутекс отравился ☠️ {} {}", file!(), line!()));
            // })
            // .await
            // .unwrap();
        });
    }

    Ok(())
}
