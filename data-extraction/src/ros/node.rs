use crate::error::Error;
use ros2_client::{Context, Name, Node, NodeName, NodeOptions, Subscription};
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;
use crate::discovery::DiscoveredTopic;

pub fn create_node(context: &Context) -> Result<Node, Error> {
    let node_name = NodeName::new("/","rust_listener")
        .map_err(|_| Error::InvalidName("Invalid node name"))?;
    context.new_node(node_name, NodeOptions::new())
        .map_err(|err| Error::NodeCreation(err))
}

pub fn start_spinner(node: &mut Node) -> Result<(), Error> {
    let spinner = node.spinner()
        .map_err(|err| Error::CreateError(err, "Failed to create spinner"))?;

    tokio::spawn(async move {
        if let Err(error) = spinner.spin().await{
            eprintln!("Spinner error: {}", error);
        };
    });

    Ok(())
}

pub fn subscribe(
    node: &mut Node,
    discovered_topic: DiscoveredTopic
) -> Result<Subscription<PointCloud2>, Error> {
    let topic = node.create_topic(
        &Name::parse(discovered_topic.name.as_str())
            .map_err(|_| Error::InvalidName("Invalid topic name"))?,
        discovered_topic.msg_type.clone(),
        &discovered_topic.qos
    ).map_err(|error| Error::CreateError(error, "Failed to create topic"))?;

    let subscription = node
        .create_subscription::<PointCloud2>(&topic, None)
        .map_err(|error| Error::CreateError(error, "Failed to create subscription"))?;

    Ok(subscription)
}