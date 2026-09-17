use futures::StreamExt;
use std::time::Instant;

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

                    let mut frame_count = 0;
                    let mut last_report = Instant::now();

                    while let Some(result) = stream.next().await {
                        match result {
                            Ok((msg, _info)) => {
                                match point_cloud::new(msg) {
                                    Ok(frame) => {
                                        frame_count += 1;

                                        if last_report.elapsed().as_secs_f64() >= 1.0 {
                                            println!(
                                                "Received {} frames/sec, {} points/frame",
                                                frame_count,
                                                frame.points.len()
                                            );

                                            frame_count = 0;
                                            last_report = Instant::now();
                                        }
                                    }

                                    Err(e) => {
                                        eprintln!("Failed to parse PointCloud2: {e:?}");
                                    }
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
