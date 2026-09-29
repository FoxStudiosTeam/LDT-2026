use std::sync::{Arc, Mutex, RwLock};
use std::time::Instant;

use rerun::{Color, Points3D, Radius, RecordingStream, TimeCell};
use ros2_data_extraction::PointCloudStream;
use shared::types::AppPointCloud;
use shared::{
    error::AppError,
    types::ProcessingQueue,
};
use tracing::*;

use crate::ENV;
use crate::debug::helper::DebugStream;

pub async fn entry(
    mut point_cloud_stream: PointCloudStream,
    recording_stream: RecordingStream,
    point_cloud: Arc<RwLock<AppPointCloud>>,
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
        if begin_lock {
            let timestamp_ns = {
                let pc = point_cloud.read().expect("Mutex poisoned");
                pc.timestamp[ProcessingQueue::NEXT]
            };
            if timestamp_ns != ENV.BEGIN_TIMESTAMP {
                info!(
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
        if ENV.TOTAL_FRAMES > 0 && processed_frames >= ENV.TOTAL_FRAMES {
            info!("[ENGINE] Достигнут лимит кадров ({})", ENV.TOTAL_FRAMES);
            return Ok(());
        }

        let frame_id = processed_frames;
        let point_cloud_lock = point_cloud.clone();
        let recording_stream = recording_stream.clone();
        let injector = injector.clone();

        let err_payload = tokio::task::spawn_blocking(move || -> Option<String> {
            let frame_start = Instant::now();

            // 1. TripleBuffer swap: переключение очередей NEXT -> READ
            let swap_start = Instant::now();
            {
                let mut point_cloud_write = point_cloud_lock.write().expect("Mutex poisoned");
                point_cloud_write.change_state(ProcessingQueue::NEXT, ProcessingQueue::READ);
            }
            let swap_dur = swap_start.elapsed();

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
                    inj_guard.inject(&mut point_cloud, number, timestamp_ns, frame_id)
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

            let geo = LidarGeometry::new(
                crop_raw.height,
                crop_raw.width,
                15.0,
                -25.0,
                ENV.PREVIEW_FOV_X_DEG,
            );

            // Искривление всех точек тоннеля и карты глубины: Z_bent = Z + c_z * X^2
            let c_z = {
                let detector = rail_detector_lock.lock().unwrap();
                detector.obstacle_config.upward_curvature
            };
            let t_warp = Instant::now();
            let active_ri = if c_z.abs() > 1e-7 {
                crop_raw.warp_curvature(&geo, c_z)
            } else {
                crop_raw.clone()
            };
            let warp_dur = t_warp.elapsed();

            // Детекция путей на искривленном представлении и препятствий (полный аналог rail_tuner_2d)
            let t_detect = Instant::now();
            let bent_result = {
                let mut detector = rail_detector_lock.lock().unwrap();
                if detector.geometry.height != geo.height
                    || detector.geometry.width != geo.width
                    || (detector.geometry.fov_h_rad - geo.fov_h_rad).abs() > 1e-4
                {
                    detector.geometry = geo.clone();
                }
                detector.detect_with_raw(
                    &active_ri,
                    Some(&crop_raw),
                    None,
                    frame_id as usize,
                )
            };
            let detect_dur = t_detect.elapsed();

            // 3. Восстановление истинных координат для Rerun и 3D сцены: Z_real = Z_bent - c_z * X^2
            let t_restore = Instant::now();
            let mut real_result = bent_result.clone();
            if let Some(ref mut r) = real_result {
                r.restore_real_coordinates();
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

            // 4. Отправка в Rerun
            let t_rerun = Instant::now();
            recording_stream.set_time("ros_time", TimeCell::from_duration_nanos(timestamp_ns));
            recording_stream.set_time_sequence("frame", frame_id as i64);

            // ─── ОКНО 1: 3D сцена ───
            let total = geo.height * geo.width;
            let mut pts_real = Vec::with_capacity(total);
            let mut colors = Vec::with_capacity(total);

            for row in 0..geo.height {
                let r_off = row * geo.width;
                for col in 0..geo.width {
                    let r = crop_raw.data[r_off + col];
                    if r > 0.5 && r < 200.0 {
                        let (x, y, z) = geo.row_col_range_to_xyz(row, col, r);
                        pts_real.push([x, y, z]);

                        let norm = (r / 200.0).clamp(0.0, 1.0);
                        let c = turbo_rgb(norm);
                        colors.push(Color::from_rgb(c[0], c[1], c[2]));
                    }
                }
            }

            // ─── ОКНО 1: Истинные физические точки лидара (3D неискривленное облако) ───
            let _ = recording_stream.log(
                "world/point_cloud",
                &Points3D::new(&pts_real)
                    .with_colors(colors)
                    .with_radii([Radius::new_ui_points(1.2)]),
            );

            // 3D рельсы, шпалы, экстраполяция, шейпкаст и препятствия с ВОССТАНОВЛЕННЫМ реальным положением:
            let _ = recording_stream.log_rail_detection(real_result.as_ref());

            // ─── ОКНО 2: 2D Карта глубины, путей, шейпкаста и препятствий ───
            let _ = recording_stream.log_rail_detection_2d(&active_ri, &geo, bent_result.as_ref());
            let rerun_dur = t_rerun.elapsed();

            // 5. Сохранение сырых кадров без интерполяции для прототипирования на Python
            if !ENV.RENDER_PATH.is_empty() {
                let _ = std::fs::create_dir_all(&ENV.RENDER_PATH);
                let file_path = format!("{}/frame_{frame_id:06}.npy", ENV.RENDER_PATH);
                let _ = crop_raw.save_npy(&file_path);
            }

            // 6. Формирование логов профилирования и статуса в консоль
            let rail_ms = real_result.as_ref().map(|r| r.timing_rail_ms).unwrap_or(0.0);
            let obs_ms = real_result.as_ref().map(|r| r.timing_obstacles_ms).unwrap_or(0.0);
            let total_dur = frame_start.elapsed();

            let (obs_str, error_msg_json) = match &real_result {
                Some(r) => {
                    let num_crit = r.obstacles.iter().filter(|o| o.status == shared::rail_detection::ObstacleStatus::Critical).count();
                    let num_warn = r.obstacles.iter().filter(|o| o.status == shared::rail_detection::ObstacleStatus::ClearanceWarning).count();
                    let num_unlikely = r.obstacles.iter().filter(|o| o.status == shared::rail_detection::ObstacleStatus::Unlikely).count();

                    let (desc, err_json) = if num_crit > 0 || num_warn > 0 {
                        let closest = r
                            .obstacles
                            .iter()
                            .filter(|o| o.status != shared::rail_detection::ObstacleStatus::Unlikely)
                            .map(|o| o.distance_along_track)
                            .fold(f32::INFINITY, f32::min);

                        let (status_str, log_prefix) = if num_crit > 0 {
                            (
                                "CRITICAL_OBSTACLE",
                                format!(
                                    " | 🛑 CRITICAL ON TRACK: {} obj (closest {:.1}m)!",
                                    num_crit, closest
                                ),
                            )
                        } else {
                            (
                                "CLEARANCE_INTRUSION",
                                format!(
                                    " | ⚠️ CLEARANCE INTRUSION: {} obj (closest {:.1}m)",
                                    num_warn, closest
                                ),
                            )
                        };

                        let payload = json!({
                            "status": status_str,
                            "frame_id": frame_id,
                            "timestamp_ns": timestamp_ns,
                            "critical_count": num_crit,
                            "warning_count": num_warn,
                            "unlikely_count": num_unlikely,
                            "total_obstacles": r.obstacles.len(),
                            "closest_distance_m": closest,
                            "gauge": r.gauge,
                            "turn_radius": r.turn_radius,
                            "turn_direction": r.turn_direction,
                            "message": if num_crit > 0 {
                                format!("CRITICAL: {} obstacle(s) detected directly in gauge! Closest at {:.2}m", num_crit, closest)
                            } else {
                                format!("WARNING: {} obstacle(s) inside clearance envelope! Closest at {:.2}m", num_warn, closest)
                            },
                            "obstacles": r.obstacles.iter().map(|o| json!({
                                "id": o.id,
                                "status": format!("{:?}", o.status),
                                "hits": o.hits,
                                "distance_along_track": o.distance_along_track,
                                "lateral_offset": o.lateral_offset,
                                "height_above_rail": o.height_above_rail,
                                "is_critical": o.is_critical,
                                "points_count": o.points_count,
                                "bbox_2d": o.bbox_2d,
                                "bbox_3d_min": o.bbox_3d_min,
                                "bbox_3d_max": o.bbox_3d_max,
                                "size_m": o.size_m,
                            })).collect::<Vec<_>>()
                        });

                        (log_prefix, Some(payload.to_string()))
                    } else if num_unlikely > 0 {
                        (
                            format!(" | ℹ️ {} unconfirmed single obstacle hit(s)", num_unlikely),
                            None,
                        )
                    } else {
                        (" | 🟢 CLEAR TRACK".to_string(), None)
                    };


                    (desc, err_json)
                }
                None => {
                    let payload = json!({
                        "status": "TRACK_LOST",
                        "frame_id": frame_id,
                        "timestamp_ns": timestamp_ns,
                        "message": format!("ERROR: Rail track not detected on frame {}", frame_id)
                    });
                    (" | ❌ TRACK NOT FOUND".to_string(), Some(payload.to_string()))
                }
            };

            let radius_str = match &real_result {
                Some(r) if r.turn_radius.is_infinite() || r.turn_radius > 9999.0 => {
                    "∞ (прямая)".to_string()
                }
                Some(r) => format!("{:.1}m ({})", r.turn_radius, r.turn_direction),
                None => "-".to_string(),
            };

            info!(
                "[FRAME {frame_id}] ⏱️ Pipeline: {:.2}ms (swap: {:.2}ms, warp: {:.2}ms, detect: {:.2}ms, rail: {:.2}ms, obs: {:.2}ms, restore: {:.2}ms, rerun: {:.2}ms) | gauge: {:.3}m, radius: {}, conf: {:.1}%{}",
                total_dur.as_secs_f64() * 1000.0,
                swap_dur.as_secs_f64() * 1000.0,
                warp_dur.as_secs_f64() * 1000.0,
                detect_dur.as_secs_f64() * 1000.0,
                rail_ms,
                obs_ms,
                restore_dur.as_secs_f64() * 1000.0,
                rerun_dur.as_secs_f64() * 1000.0,
                real_result.as_ref().map(|r| r.gauge).unwrap_or(0.0),
                radius_str,
                real_result.as_ref().map(|r| r.confidence * 100.0).unwrap_or(0.0),
                obs_str
            );

            error_msg_json
        })
        .await
        .unwrap();

        // 10. Асинхронная публикация в топик ROS2 об ошибках/препятствиях
        if let Some(payload_str) = err_payload {
            let msg = shared::transport::StringMsg::new(payload_str);
            if let Err(e) = error_publisher.async_publish(msg).await {
                error!(
                    "[ROS2] Ошибка публикации в топик {}: {:?}",
                    ENV.ROS_ERROR_TOPIC, e
                );
            } else {
                info!(
                    "📢 [ROS2 ALERT] Опубликовано в топик {} (кадр {})",
                    ENV.ROS_ERROR_TOPIC, frame_id
                );
            }
        }
    }
    Ok(())
}
