// ─── Инициализация Rerun ──────────────────────────────────────────────────────

use crate::ENV;
use rerun::{RecordingStream, RecordingStreamBuilder};
use shared::error::{AppError, ErrCtx};
use tracing::*;

pub async fn init_rerun() -> Result<RecordingStream, AppError> {
    RecordingStreamBuilder::new("point_cloud")
        .connect_grpc_opts(ENV.RERUN_URL.clone())
        .app_error()
}
