use std::sync::{Arc};

use ddl::AppPointCloud;
use ros2_client::Subscription;
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;
use tokio::sync::RwLock;

use crate::{error::Error, parser::{extract_and_validate_layout, parse_coords}};
mod parser;
mod error;
mod discovery;
mod ros;

// lib.rs

pub struct PointCloudStream {
    ros2: ros::Ros,                        
    subscription: ros2_client::Subscription<PointCloud2>, 
    // 🔥 Храним атомарную ссылку на одно-единственное тяжелое облако
    cached_cloud: Arc<RwLock<AppPointCloud>>,           
}

impl PointCloudStream {
    pub async fn next(&mut self) -> Option<Result<AppPointCloud, Error>> {
        let mut raw_data = None;
        
        // 1. Ждем пакет от лидара
        loop {
            match self.subscription.take() {
                Ok(Some(data)) => {
                    raw_data = Some(data);
                    break; 
                }
                Ok(None) => {
                    tokio::time::sleep(tokio::time::Duration::from_millis(1)).await;
                }
                Err(e) => {
                    println!("[ROS2] Ошибка получения пакета: {e}");
                    return Some(Err(Error::ParseFailed { err: e }));
                }
            }
        }

        let (cloud_raw, _msg) = raw_data?;

        // 2. Разбираем разметку
        let layout = match extract_and_validate_layout(&cloud_raw) {
            Ok(l) => l,
            Err(e) => return Some(Err(e)),
        };

        // 3. Блокируем облако на запись и парсим прямо туда (Zero-Copy)
        {
            // Если у тебя синхронный lock(), пиши: .lock().unwrap()
            // Если асинхронный RwLock от tokio, пиши: .write().await
            let mut cloud_lock = self.cached_cloud.write().await; 
            
            if let Err(e) = parse_coords(&cloud_raw, &mut *cloud_lock, &layout) {
                return Some(Err(e));
            }
        } // Лок мгновенно освобождается здесь!

        // 4. Возвращаем main.rs копию самого облака из под лока.
        // Так как main.rs в старом коде ожидает чистый `AppPointCloud` по значению,
        // нам нужно забрать данные. Чтобы не делать глубокое копирование (clone массивов),
        // мы можем использовать std::mem::take, если AppPointCloud реализует Default,
        // либо возвращать разыменованное значение, если мы управляем пулом.
        // Но если main.rs забирает владение, в reuse_buffer он вернет его обратно!
        let mut cloud_lock = self.cached_cloud.write().await;

        let ready_cloud = std::mem::replace(&mut *cloud_lock, AppPointCloud::new()); 

        Some(Ok(ready_cloud))
    }

    // Сюда main.rs возвращает отработанный буфер в конце своего цикла
    pub async fn reuse_buffer(&mut self, returned_cloud: AppPointCloud) {
        // Возвращаем тяжелую структуру обратно под защиту RwLock без аллокаций
        let mut cloud_lock = self.cached_cloud.write().await;
        *cloud_lock = returned_cloud;
    }
}

pub async fn init_sub(channel_size: usize, cloud: Arc<RwLock<AppPointCloud>>) -> Result<PointCloudStream, Error> {
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

    // Передаем Arc внутрь стрима
    Ok(PointCloudStream {
        ros2, 
        subscription,
        cached_cloud: cloud,
    })
}
