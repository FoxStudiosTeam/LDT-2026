use std::sync::{Arc, Mutex, RwLock};
use std::time::Instant;

use rerun::{Color, Points3D, Radius, RecordingStream, TimeCell};
use ros2_data_extraction::PointCloudStream;
use serde_json::json;
use shared::configs::DetectionPreset;
use shared::error::AppError;
use shared::rail_detection::{LidarGeometry, RailTrackDetector};
use shared::range_image::{RangeImage, turbo_rgb};
use shared::types::{AppPointCloud, ProcessingQueue};
use tracing::*;

use crate::ENV;
use crate::debug::helper::DebugStream;

pub async fn entry(
    mut point_cloud_stream: PointCloudStream,
    recording_stream: RecordingStream,
    point_cloud: Arc<RwLock<AppPointCloud>>,
) -> Result<(), AppError> {
    let recording_stream = Arc::new(recording_stream);
    let error_publisher = point_cloud_stream.error_publisher();

    let initial_detector: RailTrackDetector = DetectionPreset::current().into();
    let rail_detector = Arc::new(Mutex::new(initial_detector));

    let mut processed_frames: u64 = 0;
    let mut begin_lock = ENV.BEGIN_TIMESTAMP > 0;

    info!(
        "[ENGINE] Инициализация пайплайна (аналог rail_tuner_2d): FOV={}°, Rerun=ON, ErrorTopic={}",
        ENV.PREVIEW_FOV_X_DEG, ENV.ROS_ERROR_TOPIC
    );

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
        if processed_frames >= ENV.TOTAL_FRAMES {
            info!("[ENGINE] Достигнут лимит кадров ({})", ENV.TOTAL_FRAMES);
            return Ok(());
        }

        let frame_id = processed_frames;
        let point_cloud_lock = point_cloud.clone();
        let recording_stream = recording_stream.clone();
        let rail_detector_lock = rail_detector.clone();

        let err_payload = tokio::task::spawn_blocking(move || -> Option<String> {
            let frame_start = Instant::now();

            // 1. TripleBuffer swap: переключение очередей NEXT -> READ
            let swap_start = Instant::now();
            {
                let mut point_cloud_write = point_cloud_lock.write().expect("Mutex poisoned");
                point_cloud_write.change_state(ProcessingQueue::NEXT, ProcessingQueue::READ);
            }
            let swap_dur = swap_start.elapsed();

            // 2. Извлечение RangeImage под READ-локом с немедленным освобождением
            let (timestamp_ns, range_image) = {
                let pc = point_cloud_lock.read().expect("Mutex poisoned");
                let queue = ProcessingQueue::READ;
                let ts = pc.timestamp[queue];
                let ri = RangeImage::from_pandar128_organized(&pc, queue, 1);
                (ts, ri)
            };

            // 3. Подготовка 2D карты глубины (Range Image) и геометрии лидара
            let crop_raw = range_image.crop_fov(ENV.PREVIEW_FOV_X_DEG);
            let geo = LidarGeometry::new(
                crop_raw.height,
                crop_raw.width,
                15.0,
                -25.0,
                ENV.PREVIEW_FOV_X_DEG,
            );

            // 4. Искривление всех точек тоннеля и карты глубины: Z_bent = Z + c_z * X^2
            let c_z = {
                let det = rail_detector_lock.lock().unwrap();
                det.obstacle_config.upward_curvature
            };
            let t_warp = Instant::now();
            let active_ri = if c_z.abs() > 1e-7 {
                crop_raw.warp_curvature(&geo, c_z)
            } else {
                crop_raw.clone()
            };
            let warp_dur = t_warp.elapsed();

            // 5. Детекция путей на искривленном представлении и препятствий
            let t_detect = Instant::now();
            let bent_result = {
                let mut det = rail_detector_lock.lock().unwrap();
                if det.geometry.height != active_ri.height || det.geometry.width != active_ri.width {
                    det.geometry = geo.clone();
                }
                det.detect_with_raw(&active_ri, Some(&crop_raw), frame_id as usize)
            };
            let _detect_dur = t_detect.elapsed();

            // 6. Восстановление истинных координат для Rerun и 3D сцены: Z_real = Z_bent - c_z * X^2
            let t_restore = Instant::now();
            let mut real_result = bent_result.clone();
            if let Some(ref mut r) = real_result {
                r.restore_real_coordinates();
            }
            let restore_dur = t_restore.elapsed();

            // 7. Отправка в Rerun (точно так же, как в rail_tuner_2d)
            let t_rerun = Instant::now();
            recording_stream.set_time("ros_time", TimeCell::from_duration_nanos(timestamp_ns));
            recording_stream.set_time_sequence("frame", frame_id as i64);

            // ─── ОКНО 1: 3D сцена ───
            let total = geo.height * geo.width;
            let mut pts_real = Vec::with_capacity(total);
            let mut pts_bent = Vec::with_capacity(total);
            let mut colors = Vec::with_capacity(total);

            for row in 0..geo.height {
                let r_off = row * geo.width;
                for col in 0..geo.width {
                    let r = crop_raw.data[r_off + col];
                    if r > 0.5 && r < 200.0 {
                        let (x, y, z) = geo.row_col_range_to_xyz(row, col, r);
                        pts_real.push([x, y, z]);
                        let z_bent = z + c_z * x * x;
                        pts_bent.push([x, y, z_bent]);

                        let norm = (r / 200.0).clamp(0.0, 1.0);
                        let c = turbo_rgb(norm);
                        colors.push(Color::from_rgb(c[0], c[1], c[2]));
                    }
                }
            }

            // Истинные физические точки лидара в реальном мире:
            let _ = recording_stream.log(
                "lidar/point_cloud",
                &Points3D::new(&pts_real)
                    .with_colors(colors.clone())
                    .with_radii([Radius::new_ui_points(1.2)]),
            );

            // Искривленные точки тоннеля:
            if c_z.abs() > 1e-7 {
                let _ = recording_stream.log(
                    "lidar/point_cloud_bent",
                    &Points3D::new(&pts_bent)
                        .with_colors(colors)
                        .with_radii([Radius::new_ui_points(1.2)]),
                );
            }

            // 3D рельсы с ВОССТАНОВЛЕННЫМ реальным положением:
            let _ = recording_stream.log_rail_detection(real_result.as_ref());

            // ─── ОКНО 2: 2D Карта глубины, интенсивности, путей и Shapecast ───
            let _ = recording_stream.log_rail_detection_2d(&active_ri, &geo, bent_result.as_ref());
            let rerun_dur = t_rerun.elapsed();

            // 8. Сохранение сырых кадров без интерполяции для прототипирования на Python
            if !ENV.RENDER_PATH.is_empty() {
                let _ = std::fs::create_dir_all(&ENV.RENDER_PATH);
                let file_path = format!("{}/frame_{frame_id:06}.npy", ENV.RENDER_PATH);
                let _ = crop_raw.save_npy(&file_path);
            }

            // 9. Формирование логов профилирования и статуса в консоль
            let rail_ms = real_result.as_ref().map(|r| r.timing_rail_ms).unwrap_or(0.0);
            let obs_ms = real_result.as_ref().map(|r| r.timing_obstacles_ms).unwrap_or(0.0);
            let total_dur = frame_start.elapsed();

            let (obs_str, error_msg_json) = match &real_result {
                Some(r) => {
                    let num_crit = r.obstacles.iter().filter(|o| o.is_critical).count();
                    let num_warn = r.obstacles.len() - num_crit;

                    let (desc, err_json) = if num_crit > 0 || num_warn > 0 {
                        let closest = r
                            .obstacles
                            .iter()
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
                "[FRAME {frame_id}] ⏱️ Pipeline: {:.2}ms (swap: {:.2}ms, warp: {:.2}ms, rail: {:.2}ms, obs: {:.2}ms, restore: {:.2}ms, rerun: {:.2}ms) | gauge: {:.3}m, radius: {}, conf: {:.1}%{}",
                total_dur.as_secs_f64() * 1000.0,
                swap_dur.as_secs_f64() * 1000.0,
                warp_dur.as_secs_f64() * 1000.0,
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
            }
        }
    }

    Ok(())
}
