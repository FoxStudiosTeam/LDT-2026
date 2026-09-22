use crate::discovery::DiscoveredTopic;
use ros2_client::{Context, Name, Node, NodeName, NodeOptions, Subscription};
use rustdds::qos::HasQoSPolicy;
use shared::{error::{AppError, ErrCtx, ErrorType}, transport::PointCloud2};
use tracing::*;

pub fn create_node(context: &Context) -> Result<Node, AppError> {
    let node_name = NodeName::new("/", "rust_listener")
        .map_err(|_| ErrorType::InvalidName("Invalid node name"))?;
    context.new_node(node_name, NodeOptions::new()).app_error()
}

pub fn start_spinner(node: &mut Node) -> Result<(), AppError> {
    let spinner = node.spinner().app_error()?;

    tokio::spawn(async move {
        if let Err(error) = spinner.spin().await {
            error!("Spinner error: {}", error);
        };
    });

    Ok(())
}

pub fn subscribe(
    node: &mut Node,
    discovered_topic: DiscoveredTopic,
) -> Result<Subscription<PointCloud2>, AppError> {
    let topic = node
        .create_topic(
            &Name::parse(discovered_topic.name.as_str())
                .map_err(|_| ErrorType::InvalidName("Invalid topic name"))?,
            discovered_topic.msg_type.clone(),
            &discovered_topic.qos,
        )
        .app_error()?;

    let subscription = node
        .create_subscription::<PointCloud2>(&topic, Some(topic.qos()))
        .app_error()?;

    Ok(subscription)
}
