//! main.rs — ROS2 PointCloud2 listener + Rerun debug viewer
//!
//! Запуск:
//!   source /opt/ros/humble/setup.bash
//!   cargo run --bin ros2_debug_viewer

use std::sync::{Arc, RwLock};

use rust_listener::debug::{self, rerun::init_rerun};
use rust_listener::engine::engine_entry::entry;
use rust_listener::engine::types::{pin_ptr, pin_u16_ptr};
use rust_listener::{ENV, Env};
use shared::error::{AppError, ErrCtx, ErrorType};
use shared::types::{AppPointCloud, SIZE};
use tracing::*;
use tracing_subscriber::EnvFilter;

// ─── Точка входа ──────────────────────────────────────────────────────────────

#[tokio::main]
async fn main() -> Result<(), AppError> {
    // Неблокирующая тварь
    let (non_blocking_writer, _guard) = tracing_appender::non_blocking(std::io::stdout());
    let filter = EnvFilter::try_from_default_env()
        //  формат: package=level "," - разделитель
        .unwrap_or_else(|_| {
            EnvFilter::new(
                "info,ros2_data_extraction=info,ros2_debug_viewer=info,shared=info,rustdds=off",
            )
        });

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
    let r_ptr = pin_u16_ptr(SIZE);

    let cloud = Arc::<RwLock<AppPointCloud>>::new(RwLock::new(AppPointCloud::new(
        x_ptr, y_ptr, z_ptr, i_ptr, r_ptr,
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

    let _ = entry(point_cloud_stream, rerun, Arc::clone(&cloud)).await?;

    info!("[POST] Поток сообщений завершён.");
    debug::std::print_banner();
    info!("[END] Завершение работы клиента");
    drop(_guard);
    Ok(())
}
