use ros2_client::MessageTypeName;
use ros2_client::rustdds::{DomainParticipantStatusEvent, QosPolicies};


const POINTCLOUD2_TYPE: &str =
    "PointCloud2";

#[derive(Debug, Clone)]
pub struct DiscoveredTopic {
    pub name: String,
    pub msg_type: MessageTypeName,
    pub qos: QosPolicies
}
pub fn find_pointcloud_topic(
    event: DomainParticipantStatusEvent,
) -> Option<DiscoveredTopic> {
    match event {
        DomainParticipantStatusEvent::WriterDetected { writer } => {
            // Чистый DDS тип: "sensor_msgs::msg::dds_::PointCloud2_"
            if !writer.type_name.contains(POINTCLOUD2_TYPE) {
                return None;
            }

            tracing::info!(
                topic = %writer.topic_name,
                type_name = %writer.type_name,
                "DDS WriterDetected matching PointCloud2"
            );

            // Безопасно убираем "rt/" префикс, учитывая слэш
            let topic_name = if writer.topic_name.starts_with("rt/") {
                &writer.topic_name[3..]
            } else if writer.topic_name.starts_with("rt") {
                &writer.topic_name[2..]
            } else {
                &writer.topic_name
            };

            // Разбиваем DDS тип по "::"
            let parts: Vec<&str> = writer.type_name.split("::").collect();
            if parts.len() < 2 {
                return None;
            }

            let package = parts[0]; // "sensor_msgs"
            
            // Забираем самый последний элемент и чистим его от хвостов ROS2 фреймворка
            let raw_type = parts.last()?;
            let type_name = raw_type
                .trim_end_matches('_')
                .trim_end_matches("Reply")
                .trim_end_matches("Request");

            tracing::info!(
                topic = %topic_name,
                package = %package,
                type_name = %type_name,
                "Found PointCloud2 writer successfully"
            );

            Some(DiscoveredTopic {
                name: topic_name.to_owned(),
                msg_type: MessageTypeName::new(package, type_name),
                qos: writer.qos,
            })
        }

        other => {
            tracing::debug!(
                event = ?other,
                "DDS status event"
            );
            None
        }
    }
}
