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
        DomainParticipantStatusEvent::WriterDetected { writer }
        if writer.type_name.contains("PointCloud2") =>
            {
                let message_type: Vec<&str> = writer.type_name.split("::").collect();

                let topic_name = writer.topic_name.strip_prefix("rt").unwrap().into();

                println!("ROS name: {:}", topic_name);

                Some(DiscoveredTopic {
                    name: topic_name,
                    msg_type: MessageTypeName::new(
                        message_type.first().unwrap(),
                        message_type.last().unwrap().trim_end_matches("_"),
                    ),
                    qos: writer.qos,
                })
            }

        _ => None,
    }
}