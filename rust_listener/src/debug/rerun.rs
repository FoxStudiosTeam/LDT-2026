// ─── Инициализация Rerun ──────────────────────────────────────────────────────

// ─── Конфигурация ─────────────────────────────────────────────────────────────
const RERUN_ADDR: &str = "rerun+http://host.docker.internal:9876/proxy";

pub fn init_rerun() -> Result<rerun::RecordingStream, ()> {
    let rec = rerun::RecordingStreamBuilder::new("ros2_lidar_viewer")
        .connect_grpc_opts(RERUN_ADDR)
        .unwrap();
    Ok(rec)
}
