//! main.rs — ROS2 PointCloud2 listener + Rerun debug viewer
//!
//! Запуск:
//!   source /opt/ros/humble/setup.bash
//!   cargo run --bin ros2_debug_viewer

mod debug;
mod engine;

use std::sync::{Arc, RwLock};

use shared::error::AppError;

use shared::types::{AppPointCloud, SIZE};
use tracing::*;
use tracing_subscriber::EnvFilter;

use crate::debug::rerun::init_rerun;
use crate::engine::engine_entry::entry;
use crate::engine::types::{AppEngine, pin_ptr};

kaiv_utils::env_config! {
    ".env" => pub (crate) ENV = pub (crate) Env {
        RERUN_URL : String = "rerun+http://host.docker.internal:9876/proxy".to_string(),
        ROS_DOMAIN_ID : u16 = 42,
        TOTAL_FRAMES : u64 = u64::MAX,
        TEST_RERUN : bool = false,
        PREVIEW_FOV_X_DEG : f32 = 25.0,
        RENDER_PATH : String = "".to_string(),
        OBSTACLES_CONFIG : String = "".to_string()
    }
}

// ─── Точка входа ──────────────────────────────────────────────────────────────

#[tokio::main]
async fn main() -> Result<(), AppError> {
    // Неблокирующая тварь
    let (non_blocking_writer, _guard) = tracing_appender::non_blocking(std::io::stdout());
    let filter = EnvFilter::try_from_default_env()
        //  формат: package=level "," - разделитель
        .unwrap_or_else(|_| EnvFilter::new("debug,rustdds=off,h2=off"));

    tracing_subscriber::fmt()
        .with_writer(non_blocking_writer)
        .with_env_filter(filter)
        .init();

    Env::fetch();

    info!("[START] Запуск клиента");

    let x_ptr = pin_ptr(SIZE);
    let y_ptr = pin_ptr(SIZE);
    let z_ptr = pin_ptr(SIZE);
    let i_ptr = pin_ptr(SIZE);

    let cloud = Arc::<RwLock<AppPointCloud>>::new(RwLock::new(AppPointCloud::new(
        x_ptr, y_ptr, z_ptr, i_ptr,
    )));

    debug::std::print_banner();
    info!("[PRE INIT] подготовка стримов");

    let rerun = init_rerun().await?;

    if ENV.TEST_RERUN {
        info!("TEST RERUN");
        debug::rerun::test_rerun(&rerun);
        return Ok(());
    }

    let point_cloud_stream =
        ros2_data_extraction::init_sub(ENV.ROS_DOMAIN_ID, Arc::clone(&cloud)).await?;

    let engine = AppEngine::new(cloud.clone());

    let _ = entry(point_cloud_stream, rerun, Arc::clone(&cloud), Arc::new(engine)).await?;

    info!("[POST] Поток сообщений завершён.");
    debug::std::print_banner();
    info!("[END] Завершение работы клиента");
    drop(_guard);
    Ok(())
}
