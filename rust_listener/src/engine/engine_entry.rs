use std::sync::{Arc, RwLock};

use rerun::RecordingStream;
use ros2_data_extraction::PointCloudStream;
use shared::types::AppPointCloud;
use shared::{
    error::{AppError, ErrCtx},
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

    let mut processed_frames: u64 = 0;
    let mut begin_lock = ENV.BEGIN_TIMESTAMP > 0;

    while let Some(frame) = point_cloud_stream.next().await? {
        // info!("A");
        if begin_lock {
            // info!("B");
            let timestamp_ns = {
                // info!("C");
                let pc = point_cloud.read().expect("Mutex poisoned");
                pc.timestamp[ProcessingQueue::NEXT]
            };
            // info!("D");
            if timestamp_ns != ENV.BEGIN_TIMESTAMP {
                // info!("E");
                tracing::info!(
                    "[SKIP] Кадр {frame}: timestamp {timestamp_ns} < BEGIN_TIMESTAMP {} (осталось {} мс)",
                    ENV.BEGIN_TIMESTAMP,
                    (ENV.BEGIN_TIMESTAMP - timestamp_ns) / 1_000_000
                );
                continue;
            } else {
                begin_lock = false;
            }
        }

        processed_frames += 1;

        tracing::info!("Frame {processed_frames}");
        if processed_frames >= ENV.TOTAL_FRAMES {
            return Ok(());
        }

        let frame_id = processed_frames;

        let point_cloud_lock = point_cloud.clone();
        let recording_stream: Arc<RecordingStream> = recording_stream.clone();
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
            engine.check_tunnel().unwrap();

            // 2. Вычисляем статистику, строим RangeImage и извлекаем точки ПОД READ-ЛОКОМ,
            //    после чего НЕМЕДЛЕННО освобождаем лок, чтобы не задерживать ROS2 парсер.
            let compute_start = std::time::Instant::now();
            let (timestamp_ns, stats, rerun_points, rerun_intensities, rerun_colors, range_image) = {
                let point_cloud = point_cloud_lock.read().expect(&format!(
                    "⚠️ Мутекс отравился ☠️ {} {}",
                    file!(),
                    line!()
                ));

                let number = ProcessingQueue::READ;
                let timestamp_ns: i64 = point_cloud.timestamp[number];

                // rerun log text
                recording_stream.log("logs/text", &rerun::TextLog::new(format!("{timestamp_ns}"))).app_error().ok();

                let stats = point_cloud.compute_stats(number);
                let cap = point_cloud.len(number);
                let mut rerun_points: Vec<[f32; 3]> = Vec::with_capacity(cap);
                let mut rerun_intensities: Vec<f32> = Vec::with_capacity(cap);
                let mut rerun_colors: Vec<rerun::Color> = Vec::with_capacity(cap);

                for (&x, &y, &z, &intensity, _) in point_cloud.iter(number) {
                    if shared::types::is_zero_point(x, y, z) {
                        continue;
                    }
                    rerun_points.push([x, y, z]);
                    rerun_intensities.push(intensity);
                    rerun_colors.push(crate::engine::rail_curve::intensity_to_turbo_color(intensity));
                }

                let range_image = shared::range_image::RangeImage::from_pandar128_organized(
                    &point_cloud,
                    number,
                    1,
                );

                (timestamp_ns, stats, rerun_points, rerun_intensities, rerun_colors, range_image)
            }; // <--- read-lock освобожден!
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

            // 3. Отправка 3D облака (раскрашенного по intensity) и оверлеев в Rerun (БЕЗ удержания лока point_cloud!)
            let rerun_cloud_start = std::time::Instant::now();
            let point_cloud = point_cloud_lock.read().expect(&format!(
                "⚠️ Мутекс отравился ☠️ {} {}",
                file!(),
                line!()
            ));
            if let Err(e) = recording_stream.log_points_with_colors(&rerun_points, &rerun_colors) {
                error!("Ошибка логирования облака точек в rerun: {e:?}");
            }
            if let Err(e) = recording_stream.log_debug_centroid(&stats) {
                error!("Ошибка логирования оверлеев в rerun: {e:?}");
            }
            debug!(
                "[FRAME {frame_id}] Rerun 3D points & overlays send duration: {:?}",
                rerun_cloud_start.elapsed()
            );

            // 3.1. Расчет железнодорожной кривой (RANSAC + полиномы + прямизна) и логирование в Rerun
            let rail_fit_start = std::time::Instant::now();
            let rail_config = crate::engine::rail_curve::RailCurveConfig::default();
            let rail_estimator = crate::engine::rail_curve::RailCurveEstimator::new(rail_config);
            match rail_estimator.fit(&rerun_points, &rerun_intensities) {
                Some(rail_result) => {
                    let radius_str = rail_result
                        .curve_radius_m
                        .map(|r| format!("{r:.1}m"))
                        .unwrap_or_else(|| "∞ (прямая)".to_string());
                    info!(
                        "[FRAME {frame_id}] Rail curve detected in {:?}: straightness={:.3}, radius={}, inliers_left={}, inliers_right={}",
                        rail_fit_start.elapsed(),
                        rail_result.straightness,
                        radius_str,
                        rail_result.inliers_left.len(),
                        rail_result.inliers_right.len()
                    );
                    if let Err(e) = rail_result.log_to_rerun(&recording_stream) {
                        error!("Ошибка логирования кривой рельсов в rerun: {e:?}");
                    }
                }
                None => {
                    debug!(
                        "[FRAME {frame_id}] Rail curve not found ({:?})",
                        rail_fit_start.elapsed()
                    );
                }
            }

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
