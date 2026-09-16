use ros2_client::{Context, Node, NodeName, NodeOptions};

pub fn create_node(context: &Context) -> Result<Node, ros2_client::NodeCreateError> {
    let node_name = NodeName::new("/","fs").expect("Invalid node name");
    context.new_node(node_name, NodeOptions::new())
}

pub fn start_spinner(node: &mut Node) {
    let spinner = node.spinner().expect("Failed to create spinner");

    tokio::spawn(async move {
        let _ = spinner.spin().await;
    });
}