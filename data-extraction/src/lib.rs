mod ros;
mod discovery;
mod point_cloud;
mod error;

use futures::{Stream, StreamExt};
use std::{
    pin::Pin,
    task::{Context, Poll},
};
use tokio::sync::mpsc;

pub use error::Error;
pub use point_cloud::PointCloud;

pub struct PointCloudStream {
    _ros: ros::Ros,
    receiver: mpsc::Receiver<Result<PointCloud, Error>>,
}
pub async fn init_sub(channel_size: usize) -> Result<PointCloudStream, Error> {
    if channel_size == 0 {
        return Err(Error::InvalidChannelSize);
    }

    let mut ros = ros::Ros::new()?;
    let receiver = ros.node().status_receiver();

    loop {
        let event = receiver
            .recv()
            .await
            .map_err(|_| Error::DiscoveryChannelClosed)?;

        if let ros2_client::NodeEvent::DDS(dds_event) = event {
            if let Some(topic) = discovery::find_pointcloud_topic(dds_event) {
                let subscription = ros::node::subscribe(
                    ros.mutable_node(),
                    topic,
                )?;

                let (tx, rx) =
                    mpsc::channel::<Result<PointCloud, Error>>(channel_size);

                tokio::spawn(async move {
                    let mut stream = Box::pin(subscription.async_stream());

                    while let Some(result) = stream.next().await {
                        let point_cloud = match result {
                            Ok((msg, _info)) => {
                                point_cloud::new(msg)
                            }

                            Err(error) => {
                                Err(Error::ParseFailed {err: error})
                            }
                        };

                        if tx.send(point_cloud).await.is_err() {
                            break;
                        }
                    }
                });

                return Ok(PointCloudStream {
                    _ros: ros,
                    receiver: rx,
                });
            }
        }
    }
}

impl Stream for PointCloudStream {
    type Item = Result<PointCloud, Error>;

    fn poll_next(
        mut self: Pin<&mut Self>,
        cx: &mut Context<'_>,
    ) -> Poll<Option<Self::Item>> {
        self.receiver.poll_recv(cx)
    }
}