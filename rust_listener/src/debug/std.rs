// ─── Вывод в stdout ───────────────────────────────────────────────────────────

use shared::types::CloudStats;
use tracing::*;

pub fn print_frame_info(frame_id: u64, timestamp_ns: i64, stats: &CloudStats) {
    tracing::info!(
        "[FRAME {:4}] pts={:6} | t={} ns | \
        bbox x=[{:6.1},{:6.1}] y=[{:6.1},{:6.1}] z=[{:5.1},{:5.1}] | \
        centroid=({:.2},{:.2},{:.2}) | \
        width=({}), height=({})]",
        frame_id,
        stats.n_points,
        timestamp_ns,
        stats.min_x,
        stats.max_x,
        stats.min_y,
        stats.max_y,
        stats.min_z,
        stats.max_z,
        stats.centroid_x,
        stats.centroid_y,
        stats.centroid_z,
        stats.width,
        stats.height
    );
}
 
// ─── Баннер ───────────────────────────────────────────────────────────────────

pub fn print_banner() {
    info!("╔══════════════════════════════════════════════════╗");
    info!("║       ROS2 → Rerun Debug Viewer  (Rust)          ║");
    info!("╚══════════════════════════════════════════════════╝");
    info!("");
}
