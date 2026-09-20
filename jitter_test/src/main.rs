use std::{env, time::Instant};

use anyhow::{Error, Result};
use futures::StreamExt;
use ros2_client::{
    Context, MessageTypeName, NodeName, NodeOptions,
    rustdds::{DomainParticipantStatusEvent, QosPolicies},
};
use rustdds::{
    DomainParticipant, RepresentationIdentifier, TopicKind,
    dds::adapters::no_key::{Decode, DefaultDecoder, DeserializerAdapter},
    policy,
};
use tracing::*;
use tracing_subscriber::EnvFilter;

#[derive(Debug, Clone)]
pub struct DiscoveredTopic {
    pub name: String,
    pub raw_type_name: String,
    pub msg_type: MessageTypeName,
    pub qos: QosPolicies,
}

pub fn find_pointcloud_topic(event: DomainParticipantStatusEvent) -> Option<DiscoveredTopic> {
    match event {
        DomainParticipantStatusEvent::WriterDetected { writer }
            if writer.type_name.contains("PointCloud2") =>
        {
            let mut message_type = writer.type_name.split("::");
            let topic_name = writer.topic_name.strip_prefix("rt")?;
            Some(DiscoveredTopic {
                name: topic_name.to_owned(),
                raw_type_name: writer.type_name.clone(),
                msg_type: MessageTypeName::new(
                    message_type.next()?,
                    message_type.last()?.trim_end_matches('_'),
                ),
                qos: writer.qos,
            })
        }
        _ => None,
    }
}

#[derive(Clone, Copy)]
pub struct RawDecoder;

impl<'de> Decode<'de, Vec<u8>> for RawDecoder {
    type Error = std::convert::Infallible;
    fn decode_bytes(
        self,
        input_bytes: &[u8],
        _encoding: RepresentationIdentifier,
    ) -> Result<Vec<u8>, Self::Error> {
        Ok(input_bytes.to_vec())
    }
}

pub struct RawBytesAdapter;

impl DeserializerAdapter<Vec<u8>> for RawBytesAdapter {
    type Error = std::convert::Infallible;
    type Decoded = Vec<u8>;

    fn supported_encodings() -> &'static [RepresentationIdentifier] {
        &[
            RepresentationIdentifier::CDR_LE,
            RepresentationIdentifier::CDR_BE,
            RepresentationIdentifier::PL_CDR_LE,
        ]
    }

    fn transform_decoded(decoded: Self::Decoded) -> Vec<u8> {
        decoded
    }
}

impl DefaultDecoder<Vec<u8>> for RawBytesAdapter {
    type Decoder = RawDecoder;
    const DECODER: Self::Decoder = RawDecoder;
}

#[tokio::main(flavor = "multi_thread", worker_threads = 4)]
async fn main() -> Result<(), Error> {
    let filter = EnvFilter::try_from_default_env()
        .unwrap_or_else(|_| EnvFilter::new("info,rustdds=error,rust_listener=info"));
    tracing_subscriber::fmt().with_env_filter(filter).init();

    let domain_id: u16 = env::var("ROS_DOMAIN_ID")
        .ok()
        .and_then(|v| v.parse().ok())
        .unwrap_or(0);

    let participant = DomainParticipant::new(domain_id).expect("participant");
    let context =
        Context::from_domain_participant(participant.clone()).expect("context from participant");

    let node_name = NodeName::new("/", "jitter_bench").expect("Invalid node name");
    let mut node = context
        .new_node(node_name, NodeOptions::new())
        .expect("NodeCreation");

    let spinner = node.spinner().expect("CreateError");
    // Keep the JoinHandle so we can abort the spinner after discovery
    let spinner_handle = tokio::spawn(async move {
        let _ = spinner.spin().await;
    });

    let receiver = node.status_receiver();
    info!("[jitter_bench] Looking for PointCloud2 topic...");
    let mut target_topic = None;
    while let Ok(msg) = receiver.recv().await {
        if let ros2_client::NodeEvent::DDS(dds_event) = msg {
            if let Some(topic) = find_pointcloud_topic(dds_event) {
                error!("[jitter_bench] Found topic: {}", topic.name);
                target_topic = Some(topic);
                break;
            }
        }
    }
    let discovered = target_topic.expect("topic not found");

    // Discovery done - abort spinner and drop node/context to free tokio workers.
    // The raw DDS reader operates directly on the participant, independent of
    // the ros2 node layer.
    spinner_handle.abort();
    drop(node);
    drop(context);

    // BestEffort + KeepLast(1): no retransmissions, no backlog.
    // A RELIABLE publisher is compatible with a BestEffort subscriber.
    let be_qos = rustdds::QosPolicies::builder()
        .best_effort()
        .history(policy::History::KeepLast { depth: 1 })
        .build();

    let subscriber = participant
        .create_subscriber(&be_qos)
        .expect("subscriber");

    let raw_topic = participant
        .create_topic(
            format!("rt{}", discovered.name),
            discovered.raw_type_name.clone(),
            &discovered.qos,
            TopicKind::NoKey,
        )
        .expect("raw topic");

    let raw_reader: rustdds::no_key::DataReader<Vec<u8>, RawBytesAdapter> = subscriber
        .create_datareader_no_key::<Vec<u8>, RawBytesAdapter>(&raw_topic, None)
        .expect("raw datareader");

    // CDR decode in a dedicated blocking thread
    let (tx, mut rx) = tokio::sync::mpsc::channel::<Vec<u8>>(2);
    tokio::task::spawn_blocking(move || {
        while let Some(raw) = rx.blocking_recv() {
            let mut buf = Vec::with_capacity(4 + raw.len());
            buf.extend_from_slice(&[0x00, 0x01, 0x00, 0x00]);
            buf.extend_from_slice(&raw);
            match cdr::deserialize::<ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2>(
                &buf,
            ) {
                Ok(pc) => {
                    tracing::debug!(
                        "PointCloud2 ok: {} points, frame={}",
                        pc.width * pc.height,
                        pc.header.frame_id
                    );
                }
                Err(e) => error!("CDR decode failed: {e}"),
            }
        }
    });

    let stream = raw_reader.async_sample_stream();
    futures::pin_mut!(stream);

    let mut last = Instant::now();
    while let Some(result) = stream.next().await {
        let now = Instant::now();
        info!("{}ms", now.duration_since(last).as_millis());
        last = now;
        if let Ok(sample) = result {
            let _ = tx.try_send(sample.into_value());
        }
    }

    Ok(())
}
