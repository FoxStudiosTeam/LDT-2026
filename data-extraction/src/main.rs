mod ros;
mod discovery;

#[tokio::main]
async fn main() {
    let _ros = ros::Ros::new().expect("Failed to initialize ROS2");

    let topics = discovery::discover_topics(_ros.context()).expect("Failed to discover topics");

    for topic in topics {
        println!("{}\t -> \t{}", topic.name, topic.msg_type)
    }
}
