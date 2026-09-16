use std::error::Error;
use ros2_client::{Context, Name, Node, NodeName, NodeOptions, Subscription};
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;
use crate::discovery::DiscoveredTopic;

pub fn create_node(context: &Context) -> Result<Node, ros2_client::NodeCreateError> {
    let node_name = NodeName::new("/","data_extraction").expect("Invalid node name");
    context.new_node(node_name, NodeOptions::new())
}

pub fn start_spinner(node: &mut Node) {
    let spinner = node.spinner().expect("Failed to create spinner");

    tokio::spawn(async move {
        let _ = spinner.spin().await;
    });
}

pub fn subscribe(node: &mut Node, discovered_topic: DiscoveredTopic) -> Result<Subscription<PointCloud2>, Box<dyn Error>> {
    let topic = node.create_topic(
        &Name::parse(discovered_topic.name.as_str()).expect(""),
        discovered_topic.msg_type.clone(),
        &discovered_topic.qos
    ).expect("Failed to create topic");

    println!("Topic: {:?}", topic);

    let subscription = node.create_subscription::<PointCloud2>(&topic, None)
        .expect("Failed to create subscription");

    println!("Subscription created");

    Ok(subscription)
}