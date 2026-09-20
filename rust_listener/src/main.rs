//! main.rs — ROS2 PointCloud2 listener + Rerun debug viewer
//!
//! Запуск:
//!   source /opt/ros/humble/setup.bash
//!   cargo run --bin ros2_debug_viewer

mod debug;
mod engine;

use std::sync::{Arc, RwLock};

use anyhow::Result;
use cuda_pipeline::pin_gpu;
use shared::error::{AppError, ErrorType};
use shared::types::{AppPointCloud, SIZE};
use tracing::*;
use tracing_subscriber::EnvFilter;

use crate::debug::rerun::init_rerun;
use crate::engine::engine_entry::entry;

kaiv_utils::env_config! {
    ".env" => pub (crate) ENV = pub (crate) Env {
        RERUN_URL : String = "rerun+http://host.docker.internal:9876/proxy".to_string(),
        ROS_DOMAIN_ID : u16 = 0
    }
}

// ─── Точка входа ──────────────────────────────────────────────────────────────

// Error надо отрефакторить чтобы у нас была одна общая ошибка, в рамках этой ветки не делаю потому что важнее сделать data-pipe чтобы корректно было, а не пакеты.
#[tokio::main]
async fn main() -> Result<(), AppError> {
    let filter = EnvFilter::try_from_default_env()
        //  формат: package=level "," - разделитель
        .unwrap_or_else(|_| EnvFilter::new("info,rustdds=off"));
    tracing_subscriber::fmt().with_env_filter(filter).init();

    Env::fetch();

    let x_ptr = pin_gpu(SIZE);
    let y_ptr = pin_gpu(SIZE);
    let z_ptr = pin_gpu(SIZE);
    let i_ptr = pin_gpu(SIZE);

    let cloud = Arc::<RwLock<AppPointCloud>>::new(RwLock::new(AppPointCloud::new(x_ptr, y_ptr, z_ptr, i_ptr)));

    debug::std::print_banner();
    info!("[PRE INIT] подготовка стримов");

    let rerun = init_rerun().await?;

    let point_cloud_stream =
        ros2_data_extraction::init_sub(ENV.ROS_DOMAIN_ID, Arc::clone(&cloud)).await?;

    let _ = entry(point_cloud_stream, rerun, Arc::clone(&cloud)).await?;

    info!("[POST] Поток сообщений завершён.");
    debug::std::print_banner();
    info!("[END] Завершение работы клиента");
    Ok(())
}
