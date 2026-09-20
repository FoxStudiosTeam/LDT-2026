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
        if writer.type_name.contains(POINTCLOUD2_TYPE) =>
            {
                let mut message_type = writer.type_name.split("::");

                let topic_name = writer.topic_name.strip_prefix("rt")?;
                Some(DiscoveredTopic {
                    name: topic_name.to_owned(),
                    msg_type: MessageTypeName::new(
                        message_type.next()?,
                        message_type.last()?.trim_end_matches("_"),
                    ),
                    qos: writer.qos,
                })
          }

        _ => None,
    }
}