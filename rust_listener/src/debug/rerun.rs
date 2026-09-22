// ─── Инициализация Rerun ──────────────────────────────────────────────────────

use rerun::{RecordingStream, RecordingStreamBuilder};
use shared::error::{AppError, ErrCtx};

use crate::ENV;

pub async fn init_rerun() -> Result<RecordingStream, AppError> {
    RecordingStreamBuilder::new("point_cloud")
        .connect_grpc_opts(ENV.RERUN_URL.clone())
        .app_error()
}

pub fn test_rerun(rerun: &RecordingStream) {
    let points = vec![
        [0.0, 0.0, 0.0],
        [1.0, 0.0, 0.0],
        [0.0, 1.0, 0.0],
        [0.0, 0.0, 1.0],
        [1.0, 1.0, 1.0],
    ];

    rerun
        .log(
            "point_cloud",
            &rerun::archetypes::Points3D::new(points).with_radii([0.05; 5]),
        )
        .unwrap();

    tracing::info!("Point cloud sent to Rerun");
}
