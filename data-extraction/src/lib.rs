use std::sync::{Arc, RwLock};

use ddl::AppPointCloud;
use ros2_client::Subscription;
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;

use crate::{error::Error, parser::{extract_and_validate_layout, parse_coords}};
mod parser;
pub mod error;
mod discovery;
mod ros;

// lib.rs

pub struct PointCloudStream {
    ros2: ros::Ros,                        
    subscription: ros2_client::Subscription<PointCloud2>, 
    cached_cloud: Arc<RwLock<AppPointCloud>>,  
    frame_num : u64     
}

impl PointCloudStream {
    pub async fn next(&mut self) -> Result<Option<u64>, Error> {
        self.frame_num += 1;
        let (point_cloud, msg) = self.subscription.async_take().await.map_err(|e| Error::AbstractError { msg: e.to_string() })?;
        let layout = extract_and_validate_layout(&point_cloud)?;
        parse_coords(&point_cloud, Arc::clone(&self.cached_cloud), &layout)?;
        Ok(Some(self.frame_num))
    }
}

pub async fn init_sub(channel_size: usize, cloud : Arc<RwLock<AppPointCloud>>) -> Result<PointCloudStream, Error> {
    if channel_size == 0 {
        return Err(Error::InvalidChannelSize);
    }

    let mut ros2 = ros::Ros::new().map_err(|e| Error::AbstractError { msg: e.to_string() })?;
    let receiver = ros2.node().status_receiver();

    println!("[ROS2] Поиск топика PointCloud2 в DDS сети...");
    let mut target_topic = None;

    while let Ok(msg) = receiver.recv().await {
        if let ros2_client::NodeEvent::DDS(dds_event) = msg {
            if let Some(topic) = discovery::find_pointcloud_topic(dds_event) {
                println!("[ROS2] Успешно обнаружен топик лидара: {}", topic.name);
                target_topic = Some(topic);
                break;
            }
        }
    }

    let topic = match target_topic {
        Some(t) => t,
        None => return Err(Error::AbstractError { msg: "DDS receiver channel closed".to_string() }),
    };

    let subscription = ros::node::subscribe(ros2.mutable_node(), topic)
        .map_err(|e| Error::AbstractError { msg: "SubscriptionFailed".to_string() })?;

    Ok(PointCloudStream{
        ros2,
        subscription,
        cached_cloud: cloud,
        frame_num: 0,
    })
}
