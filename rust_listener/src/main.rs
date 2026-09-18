//! main.rs — ROS2 PointCloud2 listener + Rerun debug viewer
//!
//! Запуск:
//!   source /opt/ros/humble/setup.bash
//!   cargo run --bin ros2_debug_viewer

mod debug_viz;

use anyhow::Result;
use ddl::{AppPointCloud, CloudStats};
use futures::StreamExt;
use rerun::RecordingStreamBuilder;

// ─── Конфигурация ─────────────────────────────────────────────────────────────
const LIDAR_TOPIC: &str = "/sensing/lidar/hesai128/pointcloud";
const RERUN_ADDR: &str = "rerun+http://host.docker.internal:9876/proxy";
const CHANNEL_SIZE: usize = 2; // Двойная буферизация

// ─── Точка входа ──────────────────────────────────────────────────────────────

#[tokio::main]
async fn main() -> Result<()> {
    print_banner();

    // 1. Инициализируем Rerun
    let rec = init_rerun()?;

    // 2. Инициализируем RT-подписку (Discovery + выделение памяти под буферы происходят внутри)
    println!("[ROS2] Инициализация подписки и выделение RT-буферов...");
    let mut point_cloud_stream  = ros2_data_extraction::init_sub(CHANNEL_SIZE).await?;
    
    println!("[ROS2] Успешно подписались на топик: {LIDAR_TOPIC}");
    println!("[INFO] Ожидание сообщений...\n");

    let mut frame_id: u64 = 0;

    // 3. Главный Zero-Allocation RT цикл обработки
    // Нам больше не нужны r2r, Node, spin_once и сырые сообщения в main!
    while let Some(result) = point_cloud_stream.next().await {
        frame_id += 1;

        // Достаем готовое облако точек (если была ошибка в ROS2/парсинге, логируем её)
        let cloud : AppPointCloud = match result {
            Ok(c ) => c,
            Err(e) => {
                eprintln!("[FRAME {:4}] Ошибка стрима/парсинга: {e}", frame_id);
                continue;
            }
        };

        // Защита от пустых кадров лидара
        if cloud.length == 0 {
            eprintln!("[FRAME {:4}] Пустое облако точек, пропускаем.", frame_id);
            point_cloud_stream.reuse_buffer(cloud).await;
            continue;
        }

        let timestamp_ns = cloud.timestamp as i64;

        // Считаем статы по SoA массивам (отрабатывает моментально через SIMD)
        let stats = cloud.compute_stats();

        // Выводим информацию в консоль
        print_frame_info(frame_id, timestamp_ns, &stats);

        // Выставляем временны́е метки в Rerun таймлайны
        rec.set_time(
            "ros_time",
            rerun::TimeCell::from_duration_nanos(timestamp_ns),
        );
        rec.set_time_sequence("frame", frame_id as i64);

        // Логируем данные в Rerun Viewer
        debug_viz::log_raw_cloud(&rec, &cloud)?;
        debug_viz::log_debug_overlays(&rec, &cloud, &stats)?;

        // КРИТИЧЕСКИ ВАЖНО: Возвращаем буфер обратно в пул для следующего кадра!
        point_cloud_stream.reuse_buffer(cloud).await;
    }

    println!("[INFO] Поток сообщений завершён.");
    Ok(())
}

// ─── Инициализация Rerun ──────────────────────────────────────────────────────

fn init_rerun() -> Result<rerun::RecordingStream> {
    println!("[Rerun] Подключение к {RERUN_ADDR}...");

    let rec = RecordingStreamBuilder::new("ros2_lidar_viewer")
        .connect_grpc_opts(RERUN_ADDR)
        .unwrap();

    println!("[Rerun] Подключено!\n");
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
    println!("║       ROS2 → Rerun Debug Viewer  (Rust)         ║");
    println!("╠══════════════════════════════════════════════════╣");
    println!("║  Topic  : {LIDAR_TOPIC:<39}║");
    println!("║  Rerun  : {RERUN_ADDR:<39}║");
    println!("╚══════════════════════════════════════════════════╝");
    println!();
}
