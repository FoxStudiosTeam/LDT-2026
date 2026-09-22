use std::sync::{Arc, RwLock};

use rerun::RecordingStream;
use ros2_data_extraction::PointCloudStream;
use shared::error::ErrCtx;
use shared::types::AppPointCloud;
use shared::{
    error::AppError,
    types::ProcessingQueue,
};
use tracing::*;

use crate::engine::types::{AppEngine, Engine};
use crate::{
    ENV,
    debug::{self, helper::DebugStream},
};

pub async fn entry(
    mut point_cloud_stream: PointCloudStream,
    recording_stream: RecordingStream,
    point_cloud: Arc<RwLock<AppPointCloud>>,
    engine: Arc<AppEngine>,
) -> Result<(), AppError> {
    let recording_stream = Arc::new(recording_stream);
    let mut initial_injector = crate::debug::injector::setup_obstacles();
    if !ENV.OBSTACLES_CONFIG.is_empty() {
        if let Some(loaded) = crate::debug::injector::ObstacleInjector::load_from_path(&ENV.OBSTACLES_CONFIG) {
            initial_injector = loaded;
        }
    }
    let injector = Arc::new(std::sync::Mutex::new(initial_injector));

    while let Some(frame) = point_cloud_stream.next().await? {
        tracing::info!("Frame {frame}");
        if frame >= ENV.TOTAL_FRAMES {
            return Ok(());
        }
        let frame_id = frame;

        let point_cloud_lock = point_cloud.clone();
        let recording_stream = recording_stream.clone();
        let injector = injector.clone();
        let engine = engine.clone();

        tokio::task::spawn_blocking(move || {
            let frame_start = std::time::Instant::now();
            
            // 1. Ожидание лочки и переключение очередей (TripleBuffer swap)
            let swap_start = std::time::Instant::now();
            {
                let mut point_cloud_write = point_cloud_lock.write().expect(&format!(
                    "⚠️ Мутекс отравился ☠️ {} {}",
                    file!(),
                    line!()
                ));
                let next_pts = point_cloud_write.len(ProcessingQueue::NEXT);
                let read_pts_old = point_cloud_write.len(ProcessingQueue::READ);
                point_cloud_write.change_state(ProcessingQueue::NEXT, ProcessingQueue::READ);
                let read_pts_new = point_cloud_write.len(ProcessingQueue::READ);

                debug!(
                    "[FRAME {frame_id}] Swapped queues in {:?}: NEXT had {next_pts} pts -> READ now has {read_pts_new} pts (was {read_pts_old})",
                    swap_start.elapsed()
                );
            }

            engine.transform_tunnel().app_error().unwrap();

            // 2. Инъекция препятствий, статистика, RangeImage под WRITE-локом буфера READ
            let compute_start = std::time::Instant::now();
            let (timestamp_ns, stats, rerun_points, range_image, gt_boxes) = {
                let mut point_cloud = point_cloud_lock.write().expect(&format!(
                    "⚠️ Мутекс отравился ☠️ {} {}",
                    file!(),
                    line!()
                ));

                let number = ProcessingQueue::READ;
                let timestamp_ns = point_cloud.timestamp[number];

                // Инъекция виртуальных препятствий
                let gt_boxes = if let Ok(mut inj_guard) = injector.lock() {
                    //inj_guard.inject(&mut point_cloud, number, timestamp_ns, frame_id)
                    Vec::new()
                } else {
                    Vec::new()
                };

                let stats = point_cloud.compute_stats(number);
                let rerun_points: Vec<[f32; 3]> = point_cloud.to_rerun(number).collect();
                let range_image = shared::range_image::RangeImage::from_pandar128_organized(
                    &point_cloud,
                    number,
                    1,
                );

                (timestamp_ns, stats, rerun_points, range_image, gt_boxes)
            }; // <--- write-lock освобожден!
            let compute_dur = compute_start.elapsed();
            debug!(
                "[FRAME {frame_id}] Data extracted & stats & RangeImage computed in {:?}: n_points={}, centroid=({:.2}, {:.2}, {:.2})",
                compute_dur,
                stats.n_points,
                stats.centroid_x, stats.centroid_y, stats.centroid_z
            );

            debug::std::print_frame_info(frame_id, timestamp_ns, &stats);
            recording_stream.set_time(
                "ros_time",
                rerun::TimeCell::from_duration_nanos(timestamp_ns),
            );
            recording_stream.set_time_sequence("frame", frame_id as i64);

            // 3. Отправка 3D облака и оверлеев в Rerun (БЕЗ удержания лока point_cloud!)
            let rerun_cloud_start = std::time::Instant::now();
            if let Err(e) = recording_stream.log_raw_points(&rerun_points) {
                error!("Ошибка логирования облака точек в rerun: {e:?}");
            }
            if let Err(e) = recording_stream.log_debug_centroid(&stats) {
                error!("Ошибка логирования оверлеев в rerun: {e:?}");
            }
            if !gt_boxes.is_empty() {
                if let Err(e) = recording_stream.log_boxes_3d("ground_truth/obstacle_boxes", &gt_boxes) {
                    error!("Ошибка логирования GT боксов препятствий в rerun: {e:?}");
                }
            }
            debug!(
                "[FRAME {frame_id}] Rerun 3D points & overlays send duration: {:?}",
                rerun_cloud_start.elapsed()
            );

            // 4. Отправка 2D карты глубины и 4:3 превью в Rerun (БЕЗ удержания лока point_cloud!)
            let rerun_depth_start = std::time::Instant::now();
            if let Err(e) = recording_stream.log_depth_image(&range_image, ENV.PREVIEW_FOV_X_DEG) {
                error!("Ошибка логирования карты глубины в rerun: {e:?}");
            }
            debug!(
                "[FRAME {frame_id}] Rerun depth image send duration: {:?}",
                rerun_depth_start.elapsed()
            );

            // 5. Сохранение сырых кадров без интерполяции для прототипирования на Python
            if !ENV.RENDER_PATH.is_empty() {
                let crop_raw = range_image.crop_fov(ENV.PREVIEW_FOV_X_DEG);
                let _ = std::fs::create_dir_all(&ENV.RENDER_PATH);
                let file_path = format!("{}/frame_{frame_id:06}.npy", ENV.RENDER_PATH);
                if let Err(e) = crop_raw.save_npy(&file_path) {
                    error!("Ошибка сохранения кадра {file_path}: {e}");
                } else {
                    debug!("[FRAME {frame_id}] Saved raw frame to {file_path}");
                }
            }

            debug!(
                "[FRAME {frame_id}] >>> TOTAL frame processing latency: {:?}",
                frame_start.elapsed()
            );
        })
        .await
        .unwrap();
    }
    Ok(())
}
