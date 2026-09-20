//! jitter_bench.rs — минимальный high-perf профилировщик джиттера PointCloud2
//!
//! Запуск:
//!   source /opt/ros/humble/setup.bash
//!   ROS_DOMAIN_ID=42 cargo run --release --bin jitter_bench -- /lidar_points 300

use std::{
    env,
    fs::File,
    io::Write,
    time::{Instant, SystemTime, UNIX_EPOCH},
};

use anyhow::{Error, Result};
use ros2_client::{
    Context, ContextOptions, MessageTypeName, Name, Node, NodeName, NodeOptions, Subscription,
    ros2::Timestamp,
    rustdds::{DomainParticipantStatusEvent, QosPolicies},
};

use tracing::*;
use tracing_subscriber::EnvFilter;

#[derive(Debug, Clone)]
pub struct DiscoveredTopic {
    pub name: String,
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

pub fn subscribe(
    node: &mut Node,
    discovered_topic: DiscoveredTopic,
) -> Result<Subscription<()>, Error> {
    let topic = node
        .create_topic(
            &Name::parse(discovered_topic.name.as_str()).expect("Invalid topic name"),
            discovered_topic.msg_type.clone(),
            &discovered_topic.qos,
        )
        .expect("Failed to create topic");

    let subscription = node
        .create_subscription::<()>(&topic, None)
        .expect("Failed to create subscription");

    Ok(subscription)
}

// (recv_monotonic_ns, source_timestamp_ns)
type Record = (u128, i64);

fn summarize(name: &str, xs: &[f64]) {
    if xs.is_empty() {
        info!("{name}: no data");
        return;
    }
    let mut sorted = xs.to_vec();
    sorted.sort_by(|a, b| a.partial_cmp(b).unwrap());
    let n = sorted.len();
    let p50 = sorted[n / 2];
    let p95 = sorted[((n as f64) * 0.95) as usize];
    let mean = xs.iter().sum::<f64>() / n as f64;
    let min = sorted[0];
    let max = sorted[n - 1];
    info!(
        "{name}: n={n} min={min:.2}ms max={max:.2}ms mean={mean:.2}ms p50={p50:.2}ms p95={p95:.2}ms"
    );
}

#[tokio::main(flavor = "multi_thread", worker_threads = 4)]
async fn main() -> Result<(), Error> {
    let filter = EnvFilter::try_from_default_env()
        //  формат: package=level "," - разделитель
        .unwrap_or_else(|_| EnvFilter::new("info,rustdds=off"));
    tracing_subscriber::fmt().with_env_filter(filter).init();
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        error!("Usage: jitter_bench <topic-substring-optional-unused> [num_samples]");
        error!("(topic is auto-discovered like in ros2_debug_viewer, arg kept for CLI parity)");
    }
    let num_samples: usize = args.get(2).and_then(|s| s.parse().ok()).unwrap_or(250);

    let id = env::var("ROS_DOMAIN_ID").ok().and_then(|v| v.parse::<u16>().ok()).unwrap_or(42);

    info!("D id: {id}");

    let opt = ContextOptions::new().domain_id(
        env::var("ROS_DOMAIN_ID")
            .ok()
            .and_then(|v| v.parse::<u16>().ok())
            .unwrap_or(42),
    );
    let context = Context::with_options(opt).expect("context");
    let node_name = NodeName::new("/", "jitter_bench").expect("Invalid node name");
    let mut node = context
        .new_node(node_name, NodeOptions::new())
        .expect("NodeCreation");

    let spinner = node.spinner().expect("CreateError");
    tokio::spawn(async move {
        let _ = spinner.spin().await;
    });

    let receiver = node.status_receiver();
    error!("[jitter_bench] Поиск топика PointCloud2 в DDS сети...");
    let mut target_topic = None;
    while let Ok(msg) = receiver.recv().await {
        if let ros2_client::NodeEvent::DDS(dds_event) = msg {
            if let Some(topic) = find_pointcloud_topic(dds_event) {
                error!("[jitter_bench] Найден топик: {}", topic.name);
                target_topic = Some(topic);
                break;
            }
        }
    }
    let topic = target_topic.expect("топик не найден");
    let subscription = subscribe(&mut node, topic).expect("SubscriptionFailed");

    const SKIP_SAMPLES: usize = 30;
    error!("[jitter_bench] Пропускаю первые {SKIP_SAMPLES} фреймов (прогрев)...");

    let mut skipped = 0;
    while skipped < SKIP_SAMPLES {
        if let Ok(_) = subscription.async_take().await {
            skipped += 1;
        }
    }

    error!("[jitter_bench] Собираю {num_samples} сэмплов без логирования...");

    let mut records: Vec<Record> = Vec::with_capacity(num_samples);
    let epoch = SystemTime::now();
    let epoch_ns = epoch.duration_since(UNIX_EPOCH).unwrap().as_nanos();
    let start = Instant::now();

    while records.len() < num_samples {
        if let Ok((_pc, msg)) = subscription.async_take().await {
            let recv_ns = epoch_ns + start.elapsed().as_nanos();
            let src_ts = msg
                .source_timestamp()
                .map(|t| t.duration_since(Timestamp::ZERO).to_nanoseconds())
                .unwrap_or(0);
            records.push((recv_ns, src_ts));
            info!("🦀");
        }
    }

    // Пишем сырые данные
    let mut f = File::create("jitter_samples_rust.csv")?;
    writeln!(f, "recv_ns,source_timestamp_ns")?;
    info!("jitter_samples_rust.csv");
    for (recv, src) in &records {
        writeln!(f, "{recv},{src}")?;
        info!("{recv},{src}");
    }

    // recv-side inter-arrival
    let deltas_ms: Vec<f64> = records
        .windows(2)
        .map(|w| (w[1].0 as f64 - w[0].0 as f64) / 1e6)
        .collect();

    // publisher-side (source_timestamp) inter-arrival, только валидные (>0)
    let header_deltas_ms: Vec<f64> = records
        .windows(2)
        .filter(|w| w[0].1 > 0 && w[1].1 > 0)
        .map(|w| (w[1].1 as f64 - w[0].1 as f64) / 1e6)
        .collect();

    info!("\n=== Jitter summary (Rust) ===");
    summarize("Receive-side inter-arrival (recv_monotonic)", &deltas_ms);
    summarize(
        "Publisher-side inter-arrival (source_timestamp)",
        &header_deltas_ms,
    );
    info!(
        "\nRaw samples written to jitter_samples_rust.csv ({} rows)",
        records.len()
    );

    Ok(())
}
