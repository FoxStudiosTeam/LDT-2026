use crate::ENV;
use rerun::{RecordingStream, RecordingStreamBuilder};
use shared::error::{AppError, ErrCtx, ErrorType};
use std::time::Duration;
use tokio::time::sleep;
use tracing::*;

pub async fn rerun_enshured() -> Result<RecordingStream, AppError> {
    let rerun_conn = RecordingStreamBuilder::new("point_cloud")
        .connect_grpc_opts(ENV.rerun_url.clone())
        .app_error()?;

    let timeout = Duration::from_secs(5);
    let start = std::time::Instant::now();

    while !rerun_conn.is_enabled() {
        if start.elapsed() > timeout {
            error!(
                "Не удалось подключиться к Rerun Viewer по адресу {}",
                ENV.rerun_url
            );
            return ErrorType::RerunConnectionTimeout.err();
        }
        sleep(Duration::from_millis(50)).await;
    }

    Ok(rerun_conn)
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

    info!("Point cloud sent to Rerun");
}
