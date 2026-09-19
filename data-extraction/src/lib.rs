use std::sync::{Arc, RwLock};

use ddl::AppPointCloud;
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;

use shared::error::{AppError, ErrCtx, ErrorType};
use tracing::info;

use crate::parser::{extract_and_validate_layout, parse_coords};
mod discovery;
// pub mod error;
mod parser;
mod ros;

// lib.rs

pub struct PointCloudStream {
    ros2: ros::Ros,
    subscription: ros2_client::Subscription<PointCloud2>,
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
    let receiver = ros2.node().status_receiver();

    info!("[ROS2] Поиск топика PointCloud2 в DDS сети...");
    let mut target_topic = None;

    while let Ok(msg) = receiver.recv().await {
        if let ros2_client::NodeEvent::DDS(dds_event) = msg {
            if let Some(topic) = discovery::find_pointcloud_topic(dds_event) {
                info!("[ROS2] Успешно обнаружен топик лидара: {}", topic.name);
                target_topic = Some(topic);
                break;
            }
        }
    }

    let topic = match target_topic {
        Some(t) => t,
        None => {
            return ErrorType::message("DDS receiver channel closed".to_string()).err();
        }
    };

    let subscription = ros::node::subscribe(ros2.mutable_node(), topic)?;

    Ok(PointCloudStream {
        ros2,
        subscription,
        cached_cloud: cloud,
        frame_num: 0,
    })
}
