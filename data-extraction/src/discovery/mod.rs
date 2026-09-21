use ros2_client::MessageTypeName;
use ros2_client::rustdds::QosPolicies;
use ros2_client::rustdds::dds::DomainParticipant;

const POINTCLOUD2_TYPE: &str = "PointCloud2";

#[derive(Debug, Clone)]
pub struct DiscoveredTopic {
    pub name: String,
    pub msg_type: MessageTypeName,
    pub qos: QosPolicies,
}

/// Ищет PointCloud2-топик в **снимке** discovery-базы участника (level-triggered).
///
/// Раньше топик ловился по событию `WriterDetected` из `Node::status_receiver()`.
/// Это edge-triggered: событие приходит один раз, и если его никто не успел
/// принять — топик "потерян" навсегда (см. комментарий в `init_sub`).
/// Снимок `discovered_writers()` не зависит от того, когда мы начали слушать.
///
/// Если найдено несколько PointCloud2-топиков, берётся первый по имени,
/// чтобы выбор не зависел от порядка обхода внутренней базы.
pub fn find_pointcloud_topic(dp: &DomainParticipant) -> Option<DiscoveredTopic> {
    dp.discovered_writers()
        .into_iter()
        .filter_map(|writer| {
            let data = writer.publication_topic_data;
            if !data.type_name.contains(POINTCLOUD2_TYPE) {
                return None;
            }

            // "rt/lidar/points" -> "/lidar/points"
            let name = data.topic_name.strip_prefix("rt")?.to_owned();

            // "sensor_msgs::msg::dds_::PointCloud2_" -> ("sensor_msgs", "PointCloud2")
            let mut parts = data.type_name.split("::");
            let package = parts.next()?;
            let type_name = parts.last()?.trim_end_matches('_');

            Some(DiscoveredTopic {
                name,
                msg_type: MessageTypeName::new(package, type_name),
                qos: data.qos(),
            })
        })
        .min_by(|a, b| a.name.cmp(&b.name))
}
