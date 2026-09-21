use std::sync::{Arc, RwLock};

use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;
use shared::types::AppPointCloud;

use shared::error::{AppError, ErrCtx};
use std::time::{Duration, Instant};
use tracing::{info, warn};

use crate::parser::{extract_and_validate_layout, parse_coords};
mod discovery;
// pub mod error;
mod parser;
mod ros;

// lib.rs

pub struct PointCloudStream {
    ros2: ros::Ros,
    pub subscription: ros2_client::Subscription<PointCloud2>,
    cached_cloud: Arc<RwLock<AppPointCloud>>,
    frame_num: u64,
}

impl PointCloudStream {
    pub async fn next(&mut self) -> Result<Option<u64>, AppError> {
        self.frame_num += 1;
        let (point_cloud, _msg) = self.subscription.async_take().await.app_error()?;
        let layout = extract_and_validate_layout(&point_cloud)?;
        parse_coords(&point_cloud, Arc::clone(&self.cached_cloud), &layout)?;
        Ok(Some(self.frame_num))
    }
}

pub async fn init_sub(
    domain_id: u16,
    cloud: Arc<RwLock<AppPointCloud>>,
) -> Result<PointCloudStream, AppError> {
    let mut ros2 = ros::Ros::new(domain_id)?;
    let participant = ros2.domain_participant();

    info!("[ROS2] Поиск топика PointCloud2 в DDS сети...");

    // ВАЖНО: не ждём событие WriterDetected через `node.status_receiver()`.
    // Оно edge-triggered и теряется (иногда -> вечное зависание после
    // "Spinner initialized"), потому что:
    //   1. Spinner стартует в отдельной tokio-задаче и начинает раздавать
    //      события ДО того, как мы успеваем вызвать `status_receiver()`;
    //      события без подписчиков молча выбрасываются.
    //   2. Канал у подписчика `bounded(8)`, а `try_send` при переполнении
    //      тоже молча теряет событие (у бэга десятки топиков -> пачка событий).
    // Поэтому опрашиваем снимок discovery-базы: результат не зависит от
    // того, когда мы начали слушать. Аллокации только на этапе инициализации.
    const POLL_INTERVAL: Duration = Duration::from_millis(200);
    const REPORT_EVERY: Duration = Duration::from_secs(5);

    let started = Instant::now();
    let mut last_report = started;

    let topic = loop {
        if let Some(topic) = discovery::find_pointcloud_topic(&participant) {
            break topic;
        }

        if last_report.elapsed() >= REPORT_EVERY {
            last_report = Instant::now();
            warn!(
                "[DISCOVERY] PointCloud2 ещё не найден ({} с). Обнаружено writer'ов: {}",
                started.elapsed().as_secs(),
                participant.discovered_writers().len()
            );
        }

        tokio::time::sleep(POLL_INTERVAL).await;
    };

    info!(
        "[DISCOVERY] Обнаружен топик лидара: {} (за {:?})",
        topic.name,
        started.elapsed()
    );

    let subscription = ros::node::subscribe(ros2.mutable_node(), topic)?;

    info!("[SUBSCRIBE] Успешная подписка");

    Ok(PointCloudStream {
        ros2,
        subscription,
        cached_cloud: cloud,
        frame_num: 0,
    })
}
