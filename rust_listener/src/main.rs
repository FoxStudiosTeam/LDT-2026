//! main.rs — ROS2 PointCloud2 listener + Rerun debug viewer
//!
//! Запуск:
//!   source /opt/ros/humble/setup.bash
//!   cargo run --bin ros2_debug_viewer

mod debug;
mod engine;


use std::sync::{Arc, RwLock};

use anyhow::Result;
use ddl::AppPointCloud;


use crate::{debug::rerun::init_rerun, engine::engine_entry::entry};
use ros2_data_extraction::error::Error;

const CHANNEL_SIZE: usize = 8;

// ─── Точка входа ──────────────────────────────────────────────────────────────

// Error надо отрефакторить чтобы у нас была одна общая ошибка, в рамках этой ветки не делаю потому что важнее сделать data-pipe чтобы корректно было, а не пакеты.
#[tokio::main]
async fn main() -> Result<(), Error> {
    let cloud = Arc::<RwLock<AppPointCloud>>::new(RwLock::new(AppPointCloud::new()));

    debug::std::print_banner();
    println!("[PRE INIT] подготовка стримов");
    let rec = init_rerun().map_err(|_| Error::AbstractError { msg: "Rerun Init отпал".to_string() })?;

    let point_cloud_stream = ros2_data_extraction::init_sub(CHANNEL_SIZE,Arc::clone(&cloud)).await?;
    println!("[INIT] Успешно подписались.");

    let _ = entry(point_cloud_stream,rec, Arc::clone(&cloud)).await?;

    println!("[POST] Поток сообщений завершён.");
    debug::std::print_banner();
    println!("[END] Завершение работы клиента");
    Ok(())
}
