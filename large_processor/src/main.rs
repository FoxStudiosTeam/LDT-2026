use shared::error::{AppError, ErrCtx};
use tracing::*;
use tracing_subscriber::EnvFilter;

use crate::sandbox::rerun_enshured;

mod diag;
mod ros;
mod sandbox;
mod types;

shared::env_config! {
    "" => pub ENV = pub Env {
        rerun_url : String = "rerun+http://192.168.0.100:9876/proxy".to_string(),
        ROS_DOMAIN_ID : u16 = 0
    }
}

#[tokio::main]
async fn main() -> Result<(), AppError> {
    let filter =
        EnvFilter::try_from_default_env().unwrap_or_else(|_| EnvFilter::new("info,rustdds=error"));
    tracing_subscriber::fmt().with_env_filter(filter).init();

    info!("ROS_DOMAIN_ID = {}", ENV.ROS_DOMAIN_ID);
    info!("Rerun URL     = {}", ENV.rerun_url);

    // ── Диагностика (временно) ─────────────────────────────────────────────────
    // diag::run_diagnostic(ENV.ROS_DOMAIN_ID).await;
    // return Ok(());

    // ── ROS2: node → спиннер → discovery → subscribe ──────────────────────────
    // ВАЖНО: Rerun init намеренно стоит ПОСЛЕ — перед discovery не должно быть
    // никаких задержек, иначе bounded(8) канал статусов переполнится и
    // WriterDetected события будут потеряны.
    let mut ros = ros::Ros::new(ENV.ROS_DOMAIN_ID)?;

    let topic = ros::discover_pointcloud(&mut ros).await?;
    let subscription = ros::subscribe_empty(&mut ros.node, topic)?;

    // let subscription = ros::subscribe(&mut ros.node, topic)?;

    // ── Rerun (подключаемся уже после того как нашли топик) ───────────────────
    let rerun = rerun_enshured().await?;
    info!("[INIT] Подписка установлена, запуск основного цикла.");

    // ── Кэшированный layout (инициализируется из первого кадра) ──────────────
    let mut layout: Option<ros::PointLayout> = None;
    let mut frame_num: u64 = 0;

    // ── Основной цикл ──────────────────────────────────────────────────────────
    loop {
        // Блокируемся до следующего пакета
        info!("Uwuiting {frame_num}");
        let (cloud, meta) = subscription.async_take().await.app_error()?;
        // let (cloud, meta) = subscription.take().app_error()?;
        // let taken = subscription.take().app_error()?;

        info!("{frame_num}");

        // // Инициализируем layout один раз из первого кадра
        // let layout = match layout {
        //     Some(ref l) => l,
        //     None => {
        //         layout = Some(ros::PointLayout::from_cloud(&cloud)?);
        //         layout.as_ref().unwrap()
        //     }
        // };

        // let (pts, intensities) = ros::parse_cloud(&cloud, layout);

        // if pts.is_empty() {
        //     debug!("[frame {frame_num}] Пустой кадр, пропускаем.");
        //     frame_num += 1;
        //     continue;
        // }

        // // ── Timestamp из заголовка ROS2 или source_timestamp DDS ───────────────
        // let timestamp_ns: i64 = meta
        //     .source_timestamp()
        //     .map(|t| {
        //         use ros2_client::ros2::Timestamp;
        //         t.duration_since(Timestamp::ZERO).to_nanoseconds()
        //     })
        //     .unwrap_or_else(|| {
        //         cloud.header.stamp.sec as i64 * 1_000_000_000 + cloud.header.stamp.nanosec as i64
        //     });

        // // ── Нормализуем интенсивность → оттенки серого ─────────────────────────
        // let max_i = intensities
        //     .iter()
        //     .cloned()
        //     .fold(f32::NEG_INFINITY, f32::max)
        //     .max(1.0);

        // let colors: Vec<rerun::Color> = intensities
        //     .iter()
        //     .map(|&i| {
        //         let v = ((i / max_i) * 255.0) as u8;
        //         rerun::Color::from_rgb(v, v, v)
        //     })
        //     .collect();

        // // ── Временны́е метки на timeline-ах ───────────────────────────────────
        // rerun.set_time(
        //     "ros_time",
        //     rerun::TimeCell::from_timestamp_nanos_since_epoch(timestamp_ns),
        // );
        // rerun.set_time_sequence("frame", frame_num as i64);

        // // ── Логируем в Rerun ───────────────────────────────────────────────────
        // rerun
        //     .log(
        //         "lidar/points",
        //         &rerun::archetypes::Points3D::new(pts)
        //             .with_colors(colors)
        //             .with_radii([0.02]),
        //     )
        //     .app_error()?;

        // info!(
        //     "[frame {frame_num}] {} точек (ts={timestamp_ns} ns)",
        //     intensities.len()
        // );

        frame_num += 1;
    }
}
