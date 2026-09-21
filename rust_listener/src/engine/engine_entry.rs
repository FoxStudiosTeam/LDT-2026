use std::sync::{
    Arc, RwLock,
    atomic::{AtomicUsize, Ordering},
};

use rerun::RecordingStream;
use ros2_data_extraction::PointCloudStream;
use shared::{
    boxcast::{BoxCastAxis, BoxCastQuery},
    types::AppPointCloud,
};
use shared::{
    error::{AppError, ErrCtx},
    types::ProcessingQueue,
};
use tracing::*;

use crate::debug::{self, helper::DebugStream};

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

    while let Some(a) = point_cloud_stream.next().await? {
        info!("[Frame {a}] frame took");
        frame_id = a;

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
            tokio::task::spawn_blocking(move || {
                {
                    let mut point_cloud_write = point_cloud_lock.write().expect(&format!(
                        "⚠️ Мутекс отравился ☠️ {} {}",
                        file!(),
                        line!()
                    ));
                    point_cloud_write.can_write = false;
                    point_cloud_write.change_state(
                        ProcessingQueue::NEXT,
                        ProcessingQueue::READ,
                    );
                    point_cloud_write.can_write = true;
                }

                let point_cloud = point_cloud_lock.read().expect(&format!(
                    "⚠️ Мутекс отравился ☠️ {} {}",
                    file!(),
                    line!()
                ));

                let number = ProcessingQueue::READ;

                let timestamp_ns = point_cloud.timestamp[number];
                let stats = point_cloud.compute_stats(number);

                debug::std::print_frame_info(frame_id, timestamp_ns, &stats);
                recording_stream.set_time(
                    "ros_time",
                    rerun::TimeCell::from_duration_nanos(timestamp_ns),
                );
                recording_stream.set_time_sequence("frame", frame_id as i64);

                // Пушим данные в сеть (Rerun визуализация)
                if let Err(e) = recording_stream.log_raw_cloud(&point_cloud) {
                    error!("Ошибка логирования облака точек в rerun: {e:?}");
                }
                if let Err(e) = recording_stream.log_debug_overlays(&point_cloud, &stats) {
                    error!("Ошибка логирования оверлеев в rerun: {e:?}");
                }

                // let q = BoxCastQuery {
                //     center: [0.0, 0.0, 0.5],
                //     half_size: [0.4, 0.3, 0.5],
                //     distance: 5.0,
                //     axis: BoxCastAxis::Forward,
                //     threshold: 3,
                // };
                // let res = point_cloud.box_cast(ProcessingQueue::READ, &q);
                // shared::debug_boxcast::log_boxcast(&recording_stream, &q, &res)
                //     .app_error()
                //     .ok();
            })
            .await
            .unwrap();
        });
    }

    Ok(())
}
