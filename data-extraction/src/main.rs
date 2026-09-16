use futures::StreamExt;

mod ros;
mod discovery;

#[tokio::main]
async fn main() {
    let mut _ros = ros::Ros::new().expect("Failed to initialize ROS2");

    let receiver = _ros.node().status_receiver();

    while let Ok(event) = receiver.recv().await {
        if let ros2_client::NodeEvent::DDS(dss_event) = event {
            // println!("[DDS EVENT] {:?}", dss_event);

            if let Some(topic) = discovery::find_pointcloud_topic(dss_event) {
                println!(
                    "[DISCOVERY] Found PointCloud2 topic: {} -> {}",
                    topic.name, topic.msg_type.type_name()
                );
                let subscription = ros::node::subscribe(
                    _ros.mutable_node(),
                    topic,
                );

                if let Ok(subscription) = subscription {
                    let mut stream = Box::pin(subscription.async_stream());

                    println!("[SUBSCRIBER] Starting message stream");

                    while let Some(result) = stream.next().await {
                        match result {
                            Ok((msg, _info)) => {
                                println!("Received PointCloud2!");
                                println!("  frame_id: {}", msg.header.frame_id);
                                println!("  width: {}", msg.width);
                                println!("  height: {}", msg.height);
                                println!("  fields: {:?}", msg.fields);
                                println!("  point_step: {}", msg.point_step);
                                println!("  row_step: {}", msg.row_step);
                                println!("  data_len: {}", msg.data.len());
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
