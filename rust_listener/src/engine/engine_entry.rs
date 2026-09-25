use std::sync::{Arc, RwLock};

use rerun::RecordingStream;
use ros2_data_extraction::PointCloudStream;
use shared::types::AppPointCloud;
use shared::{
    error::{AppError, ErrCtx},
    types::ProcessingQueue,
};
use tracing::*;

use crate::{
    ENV,
    debug::{self, helper::DebugStream},
};

pub async fn entry(
    mut point_cloud_stream: PointCloudStream,
    recording_stream: RecordingStream,
    point_cloud: Arc<RwLock<AppPointCloud>>,
) -> Result<(), AppError> {
    let recording_stream = Arc::new(recording_stream);

    let rail_detector = Arc::new(std::sync::Mutex::new(
        shared::rail_detection::RailTrackDetector::new(shared::rail_detection::LidarGeometry::new(
            128,
            140,
            15.0,
            -25.0,
            ENV.PREVIEW_FOV_X_DEG,
        )),
    ));

    let mut processed_frames: u64 = 0;
    let mut begin_lock = ENV.BEGIN_TIMESTAMP > 0;

    while let Some(frame) = point_cloud_stream.next().await? {
        if begin_lock {
            let timestamp_ns = {
                let pc = point_cloud.read().expect("Mutex poisoned");
                pc.timestamp[ProcessingQueue::NEXT]
            };
            if timestamp_ns != ENV.BEGIN_TIMESTAMP {
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
        let rail_detector_lock = rail_detector.clone();

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

            // 2. Вычисляем статистику, строим RangeImage и извлекаем точки ПОД READ-ЛОКОМ,
            //    после чего НЕМЕДЛЕННО освобождаем лок, чтобы не задерживать ROS2 парсер.
            let compute_start = std::time::Instant::now();
            let (timestamp_ns, stats, rerun_points, _rerun_intensities, rerun_colors, range_image) = {
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

            // 3.1. Подготовка 2D карты глубины (Range Image) и геометрии лидара
            let crop_raw = range_image.crop_fov(ENV.PREVIEW_FOV_X_DEG);
            let geo = shared::rail_detection::LidarGeometry::new(
                crop_raw.height,
                crop_raw.width,
                15.0,
                -25.0,
                ENV.PREVIEW_FOV_X_DEG,
            );

            // 3.2. Поиск рельсов по перепадам дальности, валидация колеи и полиномиальная экстраполяция (dev_pyrails_rust)
            let rail_fit_start = std::time::Instant::now();
            let rail_result = {
                let mut detector = rail_detector_lock.lock().unwrap();
                if detector.geometry.height != crop_raw.height || detector.geometry.width != crop_raw.width {
                    detector.geometry = geo.clone();
                }
                detector.detect(&crop_raw, frame_id as usize)
            };
            let rail_calc_dur = rail_fit_start.elapsed();

            info!(
                "[FRAME {frame_id}] ⏱️ Расчет кривой рельсов (2D Range Image) занял: {:.2} мс ({:?})",
                rail_calc_dur.as_secs_f64() * 1000.0,
                rail_calc_dur
            );

            match &rail_result {
                Some(r) => {
                    let radius_str = if r.turn_radius.is_infinite() || r.turn_radius > 9999.0 {
                        "∞ (прямая)".to_string()
                    } else {
                        format!("{:.1}m ({})", r.turn_radius, r.turn_direction)
                    };
                    let intensity_str = if r.has_intensity {
                        format!(
                            ", intensity_L={:.1}, intensity_R={:.1}",
                            r.avg_intensity_left, r.avg_intensity_right
                        )
                    } else {
                        String::new()
                    };
                    info!(
                        "[FRAME {frame_id}] 🛤️ Rail track detected: gauge={:.3}m, radius={}, conf={:.1}%, points={}{}",
                        r.gauge,
                        radius_str,
                        r.confidence * 100.0,
                        r.points.len(),
                        intensity_str
                    );
                }
                None => {
                    info!("[FRAME {frame_id}] Rail track not found");
                }
            }

            // 4. Отправка результатов детекции в Rerun:
            //    Окно 1: 3D сцена с облаком точек, 3D кривыми путей и 3D экстраполяцией
            if let Err(e) = recording_stream.log_rail_detection(rail_result.as_ref()) {
                error!("Ошибка логирования 3D кривой рельсов в rerun: {e:?}");
            }

            //    Окно 2: 2D карта глубины с наложенными 2D путями и экстраполяцией (как в dev_pyrails_rust)
            let rerun_depth_start = std::time::Instant::now();
            if let Err(e) = recording_stream.log_rail_detection_2d(&crop_raw, &geo, rail_result.as_ref()) {
                error!("Ошибка логирования 2D карты глубины в rerun: {e:?}");
            }
            debug!(
                "[FRAME {frame_id}] Rerun 2D depth map send duration: {:?}",
                rerun_depth_start.elapsed()
            );

            // 5. Сохранение сырых кадров без интерполяции для прототипирования на Python
            if !ENV.RENDER_PATH.is_empty() {
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
