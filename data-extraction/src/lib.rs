use futures::StreamExt;

mod ros;
mod discovery;
mod point_cloud;

#[tokio::main]
async fn main() {
    let mut _ros = ros::Ros::new().expect("Failed to initialize ROS2");

    let receiver = _ros.node().status_receiver();

    while let Ok(event) = receiver.recv().await {
        if let ros2_client::NodeEvent::DDS(dss_event) = event {

            if let Some(topic) = discovery::find_pointcloud_topic(dss_event) {
                println!(
                    "Found PointCloud2 topic: {} -> {}",
                    topic.name, topic.msg_type.type_name()
                );
                let subscription = ros::node::subscribe(
                    _ros.mutable_node(),
                    topic,
                );

                if let Ok(subscription) = subscription {
                    let mut stream = Box::pin(subscription.async_stream());

                    while let Some(result) = stream.next().await {
                        match result {
                            Ok((msg, _info)) => {
                                match point_cloud::new(msg) {
                                    Ok(frame) => {
                                        println!("Found PointCloud frame");
                                        println!("{:#?}", frame);
                                    }
                                    Err(e) => {}
                                }
                            }

                            Err(error) => {
                                eprintln!("Failed to receive PointCloud2: {error:?}");
                            }
                        }
                    }
                }
            }
        }
    }
}
