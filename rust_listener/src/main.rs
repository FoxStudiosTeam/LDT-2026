//! main.rs — ROS2 PointCloud2 listener + Rerun debug viewer
//!
//! Запуск:
//!   source /opt/ros/humble/setup.bash
//!   cargo run --bin ros2_debug_viewer
//!
//! Требует работающего Rerun viewer на 192.168.0.100:9876 (Windows host).
//! Требует запущенного `ros2 bag play <path>` или реального ROS2 сенсора.

mod debug_viz;
mod pointcloud;

use anyhow::Result;
use futures::StreamExt;
use r2r::sensor_msgs::msg::PointCloud2;
use r2r::{Context, QosProfile};
use rerun::RecordingStreamBuilder;
use std::net::SocketAddrV4;
use std::time::Duration;
use tokio::task;

// ─── Конфигурация ─────────────────────────────────────────────────────────────

const LIDAR_TOPIC: &str = "/sensing/lidar/hesai128/pointcloud";
// Полный gRPC-URI viewer'а, как просит сам Rerun при старте
const RERUN_ADDR: &str = "rerun+http://192.168.0.100:9876/proxy";
const NODE_SPIN_INTERVAL_MS: u64 = 1;

// ─── Точка входа ──────────────────────────────────────────────────────────────

#[tokio::main]
async fn main() -> Result<()> {
    print_banner();

    // Инициализируем Rerun
    let rec = init_rerun()?;

    // Инициализируем ROS2 ноду
    let ctx = Context::create()?;
    let mut node = r2r::Node::create(ctx, "rust_listener", "")?;
    let mut sub = node.subscribe::<PointCloud2>(LIDAR_TOPIC, QosProfile::default())?;

    println!("[ROS2] Подписка на топик: {LIDAR_TOPIC}");
    println!("[INFO] Ожидание сообщений...\n");

    // r2r::Node реализует Send — можно перенести в отдельный поток
    let _spinner = task::spawn(async move {
        loop {
            node.spin_once(Duration::ZERO);
            tokio::time::sleep(Duration::from_millis(NODE_SPIN_INTERVAL_MS)).await;
        }
    });

    // Основной цикл обработки сообщений
    let mut frame_id: u64 = 0;

    while let Some(msg) = sub.next().await {
        frame_id += 1;

        let timestamp_ns: i64 =
            msg.header.stamp.sec as i64 * 1_000_000_000 + msg.header.stamp.nanosec as i64;

        match process_frame(&rec, &msg, frame_id, timestamp_ns) {
            Ok(()) => {}
            Err(e) => eprintln!("[FRAME {:4}] Ошибка обработки: {e}", frame_id),
        }
    }

    println!("[INFO] Поток сообщений завершён.");
    Ok(())
}

// ─── Инициализация Rerun ──────────────────────────────────────────────────────

fn init_rerun() -> Result<rerun::RecordingStream> {
    println!("[Rerun] Подключение к {RERUN_ADDR}...");

    let rec = RecordingStreamBuilder::new("rerun_example_grpc_drop_test")
        .connect_grpc_opts(RERUN_ADDR) // <-- один аргумент — строка-URL
        .unwrap();

    println!("[Rerun] Подключено!\n");
    Ok(rec)
}

// ─── Обработка одного фрейма ──────────────────────────────────────────────────

fn process_frame(
    rec: &rerun::RecordingStream,
    msg: &PointCloud2,
    frame_id: u64,
    timestamp_ns: i64,
) -> Result<()> {
    // Парсим облако точек
    let points = pointcloud::parse(msg)?;
    if points.is_empty() {
        eprintln!("[FRAME {:4}] Пустое облако точек, пропускаем.", frame_id);
        return Ok(());
    }

    // Вычисляем статистику
    let stats = pointcloud::compute_stats(&points);

    // Выводим в stdout
    print_frame_info(frame_id, timestamp_ns, &stats);

    // Выставляем временну́ю метку в Rerun (два таймлайна: ros_time и frame)
    rec.set_time(
        "ros_time",
        rerun::TimeCell::from_duration_nanos(timestamp_ns),
    );
    rec.set_time_sequence("frame", frame_id as i64);

    // Логируем исходное облако
    debug_viz::log_raw_cloud(rec, &points)?;

    // Логируем отладочные оверлеи
    debug_viz::log_debug_overlays(rec, &points, &stats)?;

    Ok(())
}

// ─── Вывод в stdout ───────────────────────────────────────────────────────────

fn print_frame_info(frame_id: u64, timestamp_ns: i64, stats: &pointcloud::CloudStats) {
    let [cx, cy, cz] = stats.centroid;
    let [xmin, ymin, zmin] = stats.min;
    let [xmax, ymax, zmax] = stats.max;

    println!(
        "[FRAME {:4}] pts={:6} | t={} ns | \
         bbox x=[{:6.1},{:6.1}] y=[{:6.1},{:6.1}] z=[{:5.1},{:5.1}] | \
         centroid=({:.2},{:.2},{:.2})",
        frame_id, stats.n_points, timestamp_ns, xmin, xmax, ymin, ymax, zmin, zmax, cx, cy, cz,
    );
}

// ─── Баннер ───────────────────────────────────────────────────────────────────

fn print_banner() {
    println!("╔══════════════════════════════════════════════════╗");
    println!("║       ROS2 → Rerun Debug Viewer  (Rust)         ║");
    println!("╠══════════════════════════════════════════════════╣");
    println!("║  Topic  : {LIDAR_TOPIC:<39}║");
    println!("║  Rerun  : {RERUN_ADDR:<39}║");
    println!("╚══════════════════════════════════════════════════╝");
    println!();
}
