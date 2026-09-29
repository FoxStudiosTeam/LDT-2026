use std::sync::{Arc, RwLock};

use shared::transport::PointCloud2;
use shared::types::AppPointCloud;

use shared::error::{AppError, ErrCtx};
use std::time::{Duration, Instant};
use tracing::{info, warn};

use crate::parser::{PointLayout, extract_and_validate_layout, parse_coords};
mod discovery;
// pub mod error;
mod parser;
mod ros;

pub use ros2_client;
pub use rustdds;

pub struct PointCloudStream {
    ros2: ros::Ros,
    pub subscription: ros2_client::Subscription<PointCloud2>,
    cached_cloud: Arc<RwLock<AppPointCloud>>,
    frame_num: u64,
    layout: Option<PointLayout>,
    pub error_publisher: Arc<ros2_client::Publisher<shared::transport::StringMsg>>,
}

impl PointCloudStream {
    pub fn error_publisher(&self) -> Arc<ros2_client::Publisher<shared::transport::StringMsg>> {
        Arc::clone(&self.error_publisher)
    }

    pub fn publish_error(&self, message: impl Into<String>) {
        let pub_clone = Arc::clone(&self.error_publisher);
        let msg = shared::transport::StringMsg::new(message);
        tokio::spawn(async move {
            let _ = pub_clone.async_publish(msg).await;
        });
    }

    pub async fn next(&mut self) -> Result<Option<u64>, AppError> {
        self.frame_num += 1;

        tracing::info!("Waiting for PointCloud2...");

        let result = self.subscription.async_take().await;

        if let Err(ref e) = result {
            tracing::error!(
                error = ?e,
                "PointCloud2 deserialization failed"
            );
        }

        let (point_cloud, _msg) = result.app_error()?;

        let layout = 'a: {
            let Some(l) = self.layout else {
                let l = extract_and_validate_layout(&point_cloud)?;
                self.layout = Some(l);
                break 'a l;
            };
            l
        };

        parse_coords(&point_cloud, Arc::clone(&self.cached_cloud), &layout)?;

        Ok(Some(self.frame_num))
    }
}

pub async fn init_sub(
    domain_id: u16,
    cloud: Arc<RwLock<AppPointCloud>>,
) -> Result<PointCloudStream, AppError> {
    init_sub_with_error_topic(domain_id, cloud, "/rail/error").await
}

pub async fn init_sub_with_error_topic(
    domain_id: u16,
    cloud: Arc<RwLock<AppPointCloud>>,
    error_topic: &str,
) -> Result<PointCloudStream, AppError> {
    let mut ros2 = ros::Ros::new(domain_id)?;
    let participant = ros2.domain_participant();

    info!("[ROS2] Поиск топика PointCloud2 в DDS сети...");

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

    let error_publisher = Arc::new(ros::node::create_string_publisher(
        ros2.mutable_node(),
        error_topic,
    )?);
    info!(
        "[PUBLISHER] Топик ошибок/препятствий готов: {}",
        error_topic
    );

    Ok(PointCloudStream {
        ros2,
        subscription,
        cached_cloud: cloud,
        frame_num: 0,
        layout: None,
        error_publisher,
    })
}
