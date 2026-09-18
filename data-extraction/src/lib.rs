mod ros;
mod discovery;
mod parser;
mod error;

use ddl::AppPointCloud;
use futures::{Stream, StreamExt};
use std::{
    pin::Pin,
    task::{Context, Poll},
};
use tokio::sync::mpsc;

pub use error::Error;

use crate::parser::parse_pointcloud;

pub struct PointCloudStream {
    _ros: ros::Ros,
    receiver: mpsc::Receiver<Result<AppPointCloud, Error>>,
    buffer_sender: mpsc::Sender<AppPointCloud>,
}

impl PointCloudStream {
    pub async fn reuse_buffer(&self, cloud: AppPointCloud) {
        let _ = self.buffer_sender.send(cloud).await;
    }
}

impl Stream for PointCloudStream {
    type Item = Result<AppPointCloud, Error>;

    fn poll_next(
        mut self: Pin<&mut Self>,
        cx: &mut Context<'_>,
    ) -> Poll<Option<Self::Item>> {
        self.receiver.poll_recv(cx)
    }
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
                    mpsc::channel::<Result<AppPointCloud, Error>>(channel_size);

                let (buf_tx, mut buf_rx) = mpsc::channel::<AppPointCloud>(2);


                buf_tx.send(AppPointCloud::new()).await.unwrap();
                buf_tx.send(AppPointCloud::new()).await.unwrap();

                let buf_tx_clone = buf_tx.clone();

                tokio::spawn(async move {
                    let mut stream = Box::pin(subscription.async_stream());

                    while let Some(mut cloud) = buf_rx.recv().await {
                        
                        if let Some(result) = stream.next().await {
                            match result {
                                Ok((msg, _info)) => {
                                    // Передаем сообщение ПО ССЫЛКЕ и мутабельный буфер
                                    if let Err(error) = parse_pointcloud(&msg, &mut cloud) {
                                        if tx.send(Err(error)).await.is_err() { break; }
                                        // В случае ошибки парсинга возвращаем буфер назад в пул
                                        let _ = buf_tx_clone.send(cloud).await;
                                        continue;
                                    }
                                    
                                    if tx.send(Ok(cloud)).await.is_err() { break; }
                                }
                                Err(error) => {
                                    if tx.send(Err(Error::ParseFailed { err: error })).await.is_err() { 
                                        break; 
                                    }
                                    let _ = buf_tx_clone.send(cloud).await;
                                }
                            }
                        } else {
                            break;
                        }
                    }
                });

                // Возвращаем стрим (переиспользуем)
                return Ok(PointCloudStream {
                    _ros: ros,
                    receiver: rx,
                    buffer_sender: buf_tx, 
                });
            }
        }
    }
}
