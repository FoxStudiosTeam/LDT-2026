//! test_error_listener.rs — CLI утилита для тестирования и чтения топика /rail/error
//!
//! Запуск:
//!   cargo run -p test_error_listener
//!   cargo run -p test_error_listener -- --raw
//!   cargo run -p test_error_listener -- --topic /rail/error --domain 0

use std::env;
use std::sync::atomic::{AtomicUsize, Ordering};

use chrono::Local;
use ros2_data_extraction::ros2_client::{
    Context, ContextOptions, MessageTypeName, Name, NodeName, NodeOptions,
};
use ros2_data_extraction::rustdds::{Duration, QosPolicyBuilder, policy, qos::HasQoSPolicy};
use serde::Deserialize;
use shared::transport::StringMsg;

#[derive(Debug, Deserialize)]
pub struct ErrorPayload {
    pub status: String,
    pub frame_id: Option<u64>,
    pub timestamp_ns: Option<i64>,
    pub critical_count: Option<usize>,
    pub warning_count: Option<usize>,
    pub unlikely_count: Option<usize>,
    pub total_obstacles: Option<usize>,
    pub closest_distance_m: Option<f32>,
    pub gauge: Option<f32>,
    pub turn_radius: Option<f32>,
    pub turn_direction: Option<String>,
    pub message: Option<String>,
    #[serde(default)]
    pub obstacles: Vec<ObstaclePayload>,
}

#[derive(Debug, Deserialize)]
pub struct ObstaclePayload {
    pub id: Option<usize>,
    pub status: Option<String>,
    pub hits: Option<usize>,
    pub distance_along_track: Option<f32>,
    pub lateral_offset: Option<f32>,
    pub height_above_rail: Option<f32>,
    pub is_critical: Option<bool>,
    pub points_count: Option<usize>,
    pub bbox_2d: Option<[usize; 4]>,
    pub bbox_3d_min: Option<[f32; 3]>,
    pub bbox_3d_max: Option<[f32; 3]>,
    pub size_m: Option<[f32; 3]>,
}

struct Config {
    domain_id: u16,
    topic_name: String,
    raw_mode: bool,
}

fn parse_cli_args() -> Config {
    let args: Vec<String> = env::args().collect();

    if args.iter().any(|a| a == "--help" || a == "-h") {
        println!("🚂 ROS2 Error & Obstacle Listener (Rust Service)");
        println!("Использование:");
        println!("  cargo run -p test_error_listener [ОПЦИИ]\n");
        println!("Опции:");
        println!(
            "  --topic <ТОПИК>   Имя топика ROS2 (по умолч.: $ROS_ERROR_TOPIC или /rail/error)"
        );
        println!("  --domain <ID>     ROS Domain ID (по умолч.: $ROS_DOMAIN_ID или 0)");
        println!(
            "  --raw             Выводить сырой JSON вместо структурированного форматирования"
        );
        println!("  -h, --help        Показать эту справку");
        std::process::exit(0);
    }

    let mut topic_name = env::var("ROS_ERROR_TOPIC").unwrap_or_else(|_| "/rail/error".to_string());
    let mut domain_id: u16 = env::var("ROS_DOMAIN_ID")
        .ok()
        .and_then(|s| s.parse().ok())
        .unwrap_or(0);
    let mut raw_mode = false;

    let mut i = 1;
    while i < args.len() {
        match args[i].as_str() {
            "--raw" => {
                raw_mode = true;
            }
            "--topic" if i + 1 < args.len() => {
                topic_name = args[i + 1].clone();
                i += 1;
            }
            "--domain" | "-d" if i + 1 < args.len() => {
                if let Ok(d) = args[i + 1].parse() {
                    domain_id = d;
                }
                i += 1;
            }
            other if !other.starts_with("--") => {
                topic_name = other.to_string();
            }
            _ => {}
        }
        i += 1;
    }

    Config {
        domain_id,
        topic_name,
        raw_mode,
    }
}

static TOTAL_MSGS: AtomicUsize = AtomicUsize::new(0);
static CRITICAL_MSGS: AtomicUsize = AtomicUsize::new(0);
static WARNING_MSGS: AtomicUsize = AtomicUsize::new(0);
static TRACK_LOST_MSGS: AtomicUsize = AtomicUsize::new(0);

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let config = parse_cli_args();

    println!("╔════════════════════════════════════════════════════════════════╗");
    println!("║       🚂 ROS2 Rail Error & Obstacle Listener (Rust Service)     ║");
    println!("╠════════════════════════════════════════════════════════════════╣");
    println!("║  ROS_DOMAIN_ID: {:<47}║", config.domain_id);
    println!("║  Topic:         {:<47}║", config.topic_name);
    println!(
        "║  Mode:          {:<47}║",
        if config.raw_mode {
            "RAW JSON"
        } else {
            "DIAGNOSTIC TELEMETRY"
        }
    );
    println!("╚════════════════════════════════════════════════════════════════╝");

    let opt = ContextOptions::new().domain_id(config.domain_id);
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
        &Name::parse(&config.topic_name)?,
        MessageTypeName::new("std_msgs", "String"),
        &QosPolicyBuilder::new()
            .reliability(policy::Reliability::Reliable {
                max_blocking_time: Duration::from_millis(100),
            })
            .durability(policy::Durability::Volatile)
            .history(policy::History::KeepLast { depth: 10 })
            .build(),
    )?;

    let subscription = node.create_subscription::<StringMsg>(&topic, Some(topic.qos()))?;
    println!(
        "⏳ Listening for messages on {} ... (Press Ctrl+C to stop)\n",
        config.topic_name
    );

    loop {
        tokio::select! {
            result = subscription.async_take() => {
                match result {
                    Ok((msg, _info)) => {
                        let count = TOTAL_MSGS.fetch_add(1, Ordering::SeqCst) + 1;
                        let now = Local::now().format("%H:%M:%S%.3f");

                        if config.raw_mode {
                            println!("─── [MSG #{count} @ {now}] ───");
                            if let Ok(val) = serde_json::from_str::<serde_json::Value>(&msg.data) {
                                println!("{}", serde_json::to_string_pretty(&val)?);
                            } else {
                                println!("{}", msg.data);
                            }
                            println!();
                            continue;
                        }

                        match serde_json::from_str::<ErrorPayload>(&msg.data) {
                            Ok(payload) => {
                                let (badge, color_code) = match payload.status.as_str() {
                                    "CRITICAL_OBSTACLE" => {
                                        CRITICAL_MSGS.fetch_add(1, Ordering::SeqCst);
                                        ("🛑 [CRITICAL OBSTACLE]", "\x1b[1;91m")
                                    }
                                    "CLEARANCE_INTRUSION" => {
                                        WARNING_MSGS.fetch_add(1, Ordering::SeqCst);
                                        ("⚠️  [CLEARANCE INTRUSION]", "\x1b[1;93m")
                                    }
                                    "TRACK_LOST" => {
                                        TRACK_LOST_MSGS.fetch_add(1, Ordering::SeqCst);
                                        ("❌ [TRACK LOST]", "\x1b[1;95m")
                                    }
                                    _ => ("ℹ️  [INFO]", "\x1b[1;94m"),
                                };

                                let frame_str = payload
                                    .frame_id
                                    .map(|f| format!("#{f}"))
                                    .unwrap_or_else(|| "?".to_string());

                                println!("{color_code}{badge}\x1b[0m [{now}] Frame {frame_str} | Status: {}", payload.status);

                                if let Some(ref m) = payload.message {
                                    println!("   ► Message: {m}");
                                }

                                if let Some(dist) = payload.closest_distance_m {
                                    let crit = payload.critical_count.unwrap_or(0);
                                    let warn = payload.warning_count.unwrap_or(0);
                                    let unl = payload.unlikely_count.unwrap_or(0);
                                    println!(
                                        "   ► Closest: \x1b[1m{dist:.2}m\x1b[0m | Critical: \x1b[91m{crit}\x1b[0m | Clearance: \x1b[93m{warn}\x1b[0m | Unconfirmed: {unl}"
                                    );
                                }

                                if let (Some(gauge), Some(radius)) = (payload.gauge, payload.turn_radius) {
                                    let rad_str = if radius.is_infinite() || radius.abs() > 9999.0 {
                                        "∞ (прямая)".to_string()
                                    } else {
                                        let dir = payload.turn_direction.as_deref().unwrap_or("");
                                        format!("{radius:.1}m ({dir})")
                                    };
                                    println!("   ► Track Geometry: Gauge = {gauge:.3}m, Turn Radius = {rad_str}");
                                }

                                if !payload.obstacles.is_empty() {
                                    println!("   ► Detected Objects ({}/{}):", payload.obstacles.len(), payload.total_obstacles.unwrap_or(payload.obstacles.len()));
                                    for (i, obs) in payload.obstacles.iter().enumerate() {
                                        let is_crit = obs.is_critical.unwrap_or(false);
                                        let tag = if is_crit {
                                            "\x1b[91m🚨 IN GAUGE\x1b[0m"
                                        } else {
                                            "\x1b[93m⚠️  CLEARANCE\x1b[0m"
                                        };
                                        let dist = obs.distance_along_track.unwrap_or(0.0);
                                        let lat = obs.lateral_offset.unwrap_or(0.0);
                                        let h = obs.height_above_rail.unwrap_or(0.0);
                                        let pts = obs.points_count.unwrap_or(0);
                                        let hits = obs.hits.unwrap_or(1);
                                        let size_str = if let Some([sx, sy, sz]) = obs.size_m {
                                            format!(", size: {sx:.1}x{sy:.1}x{sz:.1}m")
                                        } else {
                                            String::new()
                                        };

                                        println!(
                                            "      [{}] {} @ \x1b[1m{dist:.2}m\x1b[0m (lat: {lat:+.2}m, h: {h:.2}m, pts: {pts}, hits: {hits}{size_str})",
                                            i + 1, tag
                                        );
                                    }
                                }
                                println!();
                            }
                            Err(_) => {
                                println!("\x1b[94m[MSG #{count} @ {now}]\x1b[0m {}", msg.data);
                            }
                        }
                    }
                    Err(e) => {
                        eprintln!("Subscription error: {:?}", e);
                        break;
                    }
                }
            }
            _ = tokio::signal::ctrl_c() => {
                println!("\n🛑 Interrupted by user (Ctrl+C).");
                break;
            }
        }
    }

    let total = TOTAL_MSGS.load(Ordering::SeqCst);
    let crit = CRITICAL_MSGS.load(Ordering::SeqCst);
    let warn = WARNING_MSGS.load(Ordering::SeqCst);
    let lost = TRACK_LOST_MSGS.load(Ordering::SeqCst);

    println!("╔════════════════════════════════════════════════════════════════╗");
    println!("║                    📊 Session Statistics                       ║");
    println!("╠════════════════════════════════════════════════════════════════╣");
    println!("║  Total Messages Received:   {:<35}║", total);
    println!("║  Critical Obstacles:        {:<35}║", crit);
    println!("║  Clearance Warnings:        {:<35}║", warn);
    println!("║  Track Lost Alerts:         {:<35}║", lost);
    println!("╚════════════════════════════════════════════════════════════════╝");

    Ok(())
}
