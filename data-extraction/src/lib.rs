use std::sync::{Arc, RwLock};

use shared::transport::PointCloud2;
use shared::types::AppPointCloud;

use shared::error::{AppError, ErrCtx, ErrorType};
use tracing::{error, info};

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
    frame_num: u64
}

impl PointCloudStream {
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

        tracing::info!(
            width = point_cloud.width,
            height = point_cloud.height,
            fields = point_cloud.fields.len(),
            point_step = point_cloud.point_step,
            row_step = point_cloud.row_step,
            data_len = point_cloud.data.len(),
            "Received PointCloud2"
        );

        for field in &point_cloud.fields {
            tracing::info!(
                name = %field.name,
                offset = field.offset,
                datatype = field.datatype,
                count = field.count,
                "PointCloud2 field"
            );
        }

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

    info!("[ROS2] Ожидание топика PointCloud2 в DDS сети...");

    let mut subscribed = std::collections::HashSet::<String>::new();

    let topic = loop {
        let msg = match receiver.recv().await {
            Ok(msg) => msg,
            Err(err) => {
                return ErrorType::message(format!(
                    "DDS receiver channel closed: {err}"
                ))
                .err();
            }
        };

        let ros2_client::NodeEvent::DDS(dds_event) = msg else {
            continue;
        };

        if let Some(topic) = discovery::find_pointcloud_topic(dds_event) {
            if !subscribed.insert(topic.name.clone()) {
                info!(
                    "[DISCOVERY] Дубликат обнаружения топика {}, пропускаю",
                    topic.name
                );
                continue;
            }

            info!(
                "[DISCOVERY] Обнаружен PointCloud2: {}",
                topic.name
            );

            break topic;
        }
    };

    info!(
        "[SUBSCRIBE] Подписка на PointCloud2: {}",
        topic.name
    );

    let subscription = ros::node::subscribe(
        ros2.mutable_node(),
        topic,
    )?;

    info!("[SUBSCRIBE] Успешная подписка");

    Ok(PointCloudStream {
        ros2,
        subscription,
        cached_cloud: cloud,
        frame_num: 0,
    })
}
