// ─── Инициализация Rerun ──────────────────────────────────────────────────────

use std::time::Duration;

use rerun::{RecordingStream, RecordingStreamBuilder};
use shared::error::{AppError, ErrCtx, ErrorType};
use tokio::time::sleep;
use tracing::*;

use crate::ENV;

pub async fn init_rerun() -> Result<RecordingStream, AppError> {
    RecordingStreamBuilder::new("point_cloud")
        .connect_grpc_opts(ENV.RERUN_URL.clone())
        .app_error()
}

pub async fn check_rerun_connection(rerun: &RecordingStream) -> Result<(), AppError> {
    let timeout = Duration::from_secs(5);
    let start = std::time::Instant::now();

    while !rerun.is_enabled() {
        if start.elapsed() > timeout {
            warn!(
                "[PRE INIT] Не удалось подключиться к Rerun Viewer по адресу {}",
                ENV.RERUN_URL
            );
            return ErrorType::RerunConnectionTimeout.err();
        }
        sleep(Duration::from_millis(50)).await;
    }
    info!("[PRE INIT] Успешно подключились к Rerun Viewer");
    Ok(())
}
