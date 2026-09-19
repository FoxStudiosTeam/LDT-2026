//! diag.rs — проверяем что async_take() вообще получает данные

use ros2_client::{
    Context, ContextOptions, MessageTypeName, Name, Node, NodeName, NodeOptions,
    rustdds::DomainParticipantStatusEvent,
};
use tracing::*;

pub async fn run_diagnostic(domain_id: u16) {
    let opt = ContextOptions::new().domain_id(domain_id);
    let context = Context::with_options(opt).expect("context");
    let node_name = NodeName::new("/", "large_processor_diag").expect("name");
    let mut node = context.new_node(node_name, NodeOptions::new()).expect("node");

    // Spinner ПЕРВЫМ
    let spinner = node.spinner().expect("spinner");
    tokio::spawn(async move {
        let _ = spinner.spin().await;
    });

    // Сразу receiver
    let receiver = node.status_receiver();
    info!("[DIAG] Ожидание PointCloud2...");

    let mut discovered = None;
    while let Ok(msg) = receiver.recv().await {
        if let ros2_client::NodeEvent::DDS(DomainParticipantStatusEvent::WriterDetected { writer }) = msg {
            if writer.type_name.contains("PointCloud2") {
                info!("[DIAG] Найден издатель: topic={} type={}", writer.topic_name, writer.type_name);
                discovered = Some((writer.topic_name.clone(), writer.type_name.clone(), writer.qos.clone()));
                break;
            }
        }
    }

    let (topic_name, type_name, qos) = discovered.expect("not found");
    let topic_name_clean = topic_name.strip_prefix("rt").unwrap_or(&topic_name);

    let mut parts = type_name.split("::");
    let pkg = parts.next().unwrap_or("sensor_msgs");
    let msg_type = parts.last().unwrap_or("PointCloud2").trim_end_matches('_');
    let msg_type_name = ros2_client::MessageTypeName::new(pkg, msg_type);

    let t = node.create_topic(
        &Name::parse(topic_name_clean).expect("topic name"),
        msg_type_name,
        &qos,
    ).expect("create topic");

    // Явный QoS для subscriber — best effort чтобы точно матчиться с publisher
    use ros2_client::rustdds::QosPolicyBuilder;
    let sub_qos = QosPolicyBuilder::new()
        .reliability(ros2_client::rustdds::policy::Reliability::BestEffort)
        .history(ros2_client::rustdds::policy::History::KeepLast { depth: 1 })
        .build();

    let sub = node.create_subscription::<()>(&t, Some(sub_qos)).expect("sub");
    info!("[DIAG] Подписались как () с BEST_EFFORT QoS, ждём пакеты...");

    let mut count = 0;
    loop {
        match sub.async_take().await {
            Ok((_, meta)) => {
                count += 1;
                info!("[DIAG] Пакет #{count} получен, source_ts={:?}", meta.source_timestamp());
                if count >= 5 { break; }
            }
            Err(e) => {
                error!("[DIAG] async_take ошибка: {e:?}");
                break;
            }
        }
    }
    info!("[DIAG] Итог: получено {count} пакетов");
}
