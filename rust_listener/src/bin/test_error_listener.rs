//! test_error_listener.rs — CLI утилита для тестирования и чтения топика /rail/error
//!
//! Запуск:
//!   cargo run --bin test_error_listener

use ros2_data_extraction::ros2_client::{
    Context, ContextOptions, MessageTypeName, Name, NodeName, NodeOptions,
};
use ros2_data_extraction::rustdds::{QosPolicyBuilder, qos::HasQoSPolicy};
use shared::transport::StringMsg;

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let domain_id: u16 = std::env::var("ROS_DOMAIN_ID")
        .ok()
        .and_then(|s| s.parse().ok())
        .unwrap_or(0);
    let topic_name = std::env::var("ROS_ERROR_TOPIC").unwrap_or_else(|_| "/rail/error".to_string());

    println!("==================================================");
    println!("🚂 ROS2 Error / Obstacle Listener (Rust Service)");
    println!("   ROS_DOMAIN_ID: {}", domain_id);
    println!("   Topic:         {}", topic_name);
    println!("==================================================");

    let opt = ContextOptions::new().domain_id(domain_id);
    let context = Context::with_options(opt)?;
    let node_name = NodeName::new("/", "test_error_listener")?;
    let mut node = context.new_node(node_name, NodeOptions::new())?;

    let spinner = node.spinner()?;
    tokio::spawn(async move {
        if let Err(e) = spinner.spin().await {
            eprintln!("Spinner error: {}", e);
        }
    });

    let topic = node.create_topic(
        &Name::parse(&topic_name)?,
        MessageTypeName::new("std_msgs", "String"),
        &QosPolicyBuilder::new().build(),
    )?;

    let subscription = node.create_subscription::<StringMsg>(&topic, Some(topic.qos()))?;
    println!(
        "⏳ Listening for messages on {} ... (Press Ctrl+C to stop)\n",
        topic_name
    );

    let mut count = 0;
    while let Ok((msg, _info)) = subscription.async_take().await {
        count += 1;
        println!("─── [MSG #{count}] ───");
        if let Ok(val) = serde_json::from_str::<serde_json::Value>(&msg.data) {
            println!("{}", serde_json::to_string_pretty(&val)?);
        } else {
            println!("{}", msg.data);
        }
        println!();
    }

    Ok(())
}
