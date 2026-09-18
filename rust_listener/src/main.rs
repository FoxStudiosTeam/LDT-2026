//! main.rs — ROS2 PointCloud2 listener + Rerun debug viewer
//!
//! Запуск:
//!   source /opt/ros/humble/setup.bash
//!   cargo run --bin ros2_debug_viewer

mod debug_viz;

use std::{sync::{Arc}, time::Duration};

use anyhow::Result;
use ddl::{AppPointCloud, CloudStats};
use futures::StreamExt;
use rerun::{RecordingStreamBuilder, log::ChunkBatcherConfig};
use tokio::sync::RwLock;

// ─── Конфигурация ─────────────────────────────────────────────────────────────
const RERUN_ADDR: &str = "rerun+http://host.docker.internal:9876/proxy";
const CHANNEL_SIZE: usize = 8; // Количество буфферов

// ─── Точка входа ──────────────────────────────────────────────────────────────

#[tokio::main]
async fn main() -> Result<()> {
    print_banner();
    let rec = init_rerun()?;

    println!("[ROS2] Инициализация подписки...");
    let cloud = Arc::new(RwLock::new(AppPointCloud::new()));

    let mut point_cloud_stream = ros2_data_extraction::init_sub(CHANNEL_SIZE, cloud).await?;
    
    println!("[ROS2] Успешно подписались. Ожидание сообщений...\n");
    let mut frame_id: u64 = 0;

    // 🔄 ЕДИНСТВЕННЫЙ ГОРЯЧИЙ ЦИКЛ ОБРАБОТКИ (Остался родным и чистым!)
    while let Some(result) = point_cloud_stream.next().await {
        frame_id += 1;

        let cloud = match result {
            Ok(c) => c,
            Err(e) => {
                eprintln!("[FRAME {:4}] Ошибка парсинга: {e}", frame_id);
                continue;
            }
        };

        let timestamp_ns = cloud.timestamp as i64;
        let stats = cloud.compute_stats();
        print_frame_info(frame_id, timestamp_ns, &stats);

        rec.set_time("ros_time", rerun::TimeCell::from_duration_nanos(timestamp_ns));
        rec.set_time_sequence("frame", frame_id as i64);

        // Пушим данные в сеть (Rerun визуализация)
        debug_viz::log_raw_cloud(&rec, &cloud)?;
        debug_viz::log_debug_overlays(&rec, &cloud, &stats)?;

        // ВОЗВРАЩАЕМ БУФЕР В ПУЛ (Zero-Copy возвращается на место)
        point_cloud_stream.reuse_buffer(cloud).await;
    }

    println!("[INFO] Поток сообщений завершён.");
    Ok(())
}

// ─── Инициализация Rerun ──────────────────────────────────────────────────────

fn init_rerun() -> Result<rerun::RecordingStream> {
    println!("[Rerun] Настройка RT-конфигурации батчера...");

    // Создаем кастомный конфиг, расширяя лимиты в куче
    let mut batcher_config = rerun::log::ChunkBatcherConfig::from_env().unwrap_or_default();
    
    batcher_config.flush_tick = std::time::Duration::from_nanos(0);
    
    batcher_config.flush_num_bytes = 1;

    batcher_config.max_bytes_in_flight = 2 * 1024 * 1024 * 1024; 

    println!("[Rerun] Подключение к {RERUN_ADDR}...");

    let rec = rerun::RecordingStreamBuilder::new("ros2_lidar_viewer")
        .batcher_config(batcher_config) 
        .connect_grpc_opts(RERUN_ADDR)
        .unwrap();

    println!("[Rerun] Подключено в режиме максимальной пропускной способности!\n");
    Ok(rec)
}

// ─── Вывод в stdout ───────────────────────────────────────────────────────────

fn print_frame_info(frame_id: u64, timestamp_ns: i64, stats: &CloudStats) {
    println!(
        "[FRAME {:4}] pts={:6} | t={} ns | \
         bbox x=[{:6.1},{:6.1}] y=[{:6.1},{:6.1}] z=[{:5.1},{:5.1}] | \
         centroid=({:.2},{:.2},{:.2})",
        frame_id, stats.n_points, timestamp_ns, 
        stats.min_x, stats.max_x, stats.min_y, stats.max_y, stats.min_z, stats.max_z, 
        stats.centroid_x, stats.centroid_y, stats.centroid_z,
    );
}

// ─── Баннер ───────────────────────────────────────────────────────────────────

fn print_banner() {
    println!("╔══════════════════════════════════════════════════╗");
    println!("║       ROS2 → Rerun Debug Viewer  (Rust)          ║");
    println!("╠══════════════════════════════════════════════════╣");
    println!("║  Rerun  : {RERUN_ADDR:<39}║");
    println!("╚══════════════════════════════════════════════════╝");
    println!();
}
