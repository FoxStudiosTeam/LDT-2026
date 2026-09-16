//! debug_viz.rs — генерация отладочных примитивов для Rerun

use anyhow::Result;
use rerun::{Color, LineStrips3D, Points3D, Radius, RecordingStream};

use crate::pointcloud::CloudStats;

// ─── Пороги ───────────────────────────────────────────────────────────────────
const NEAR_RANGE_M: f32 = 1.0; // точки ближе этого — "опасные"
const HIGH_Z_M: f32 = 2.0; // точки выше этого — "верхний слой"

/// Логируем всё облако точек в rerun
pub fn log_raw_cloud(rec: &RecordingStream, points: &[[f32; 3]]) -> Result<()> {
    if points.is_empty() {
        return Ok(());
    }

    rec.log(
        "lidar/raw",
        &Points3D::new(points)
            .with_colors(vec![Color::from_rgb(160, 185, 220); points.len()])
            .with_radii(vec![Radius::new_ui_points(1.2); points.len()]),
    )?;

    Ok(())
}

/// Логируем отладочные оверлеи
pub fn log_debug_overlays(
    rec: &RecordingStream,
    points: &[[f32; 3]],
    stats: &CloudStats,
) -> Result<()> {
    // 1. Центр масс
    log_centroid(rec, stats)?;

    // 2. Bounding box
    log_bbox(rec, stats)?;

    // 3. Близкие точки (< NEAR_RANGE_M)
    log_near_points(rec, points)?;

    // 4. Высокие точки (Z > HIGH_Z_M)
    log_high_points(rec, points)?;

    Ok(())
}

/// Центр масс — одна большая зелёная точка
fn log_centroid(rec: &RecordingStream, stats: &CloudStats) -> Result<()> {
    let c = stats.centroid;
    rec.log(
        "lidar/debug/centroid",
        &Points3D::new([c])
            .with_colors([Color::from_rgb(50, 255, 80)])
            .with_radii([Radius::new_scene_units(0.25)])
            .with_labels(["centroid"]),
    )?;
    Ok(())
}

/// Wireframe bounding box — 12 рёбер жёлтым
fn log_bbox(rec: &RecordingStream, stats: &CloudStats) -> Result<()> {
    let [x0, y0, z0] = stats.min;
    let [x1, y1, z1] = stats.max;

    // 12 рёбер куба (каждое ребро — отдельная полилиния из 2 точек)
    let edges: Vec<Vec<[f32; 3]>> = vec![
        // нижняя грань
        vec![[x0, y0, z0], [x1, y0, z0]],
        vec![[x1, y0, z0], [x1, y1, z0]],
        vec![[x1, y1, z0], [x0, y1, z0]],
        vec![[x0, y1, z0], [x0, y0, z0]],
        // верхняя грань
        vec![[x0, y0, z1], [x1, y0, z1]],
        vec![[x1, y0, z1], [x1, y1, z1]],
        vec![[x1, y1, z1], [x0, y1, z1]],
        vec![[x0, y1, z1], [x0, y0, z1]],
        // вертикальные рёбра
        vec![[x0, y0, z0], [x0, y0, z1]],
        vec![[x1, y0, z0], [x1, y0, z1]],
        vec![[x1, y1, z0], [x1, y1, z1]],
        vec![[x0, y1, z0], [x0, y1, z1]],
    ];

    let n_edges = edges.len();
    rec.log(
        "lidar/debug/bbox",
        &LineStrips3D::new(edges)
            .with_colors(vec![Color::from_rgb(255, 210, 0); n_edges])
            .with_radii(vec![Radius::new_ui_points(1.5); n_edges]),
    )?;
    Ok(())
}

/// Точки ближе NEAR_RANGE_M к началу координат — красным
fn log_near_points(rec: &RecordingStream, points: &[[f32; 3]]) -> Result<()> {
    let near: Vec<[f32; 3]> = points
        .iter()
        .filter(|p| {
            let dist2 = p[0] * p[0] + p[1] * p[1] + p[2] * p[2];
            dist2 < NEAR_RANGE_M * NEAR_RANGE_M
        })
        .copied()
        .collect();

    if near.is_empty() {
        // Логируем пустое облако чтобы убрать старые точки
        rec.log(
            "lidar/debug/near_range",
            &Points3D::new([] as [[f32; 3]; 0]),
        )?;
        return Ok(());
    }

    rec.log(
        "lidar/debug/near_range",
        &Points3D::new(&near)
            .with_colors(vec![Color::from_rgb(255, 60, 60); near.len()])
            .with_radii(vec![Radius::new_ui_points(2.5); near.len()])
            .with_labels(vec!["near"; near.len()]),
    )?;
    Ok(())
}

/// Точки выше HIGH_Z_M — бирюзовым
fn log_high_points(rec: &RecordingStream, points: &[[f32; 3]]) -> Result<()> {
    let high: Vec<[f32; 3]> = points.iter().filter(|p| p[2] > HIGH_Z_M).copied().collect();

    if high.is_empty() {
        rec.log("lidar/debug/high_z", &Points3D::new([] as [[f32; 3]; 0]))?;
        return Ok(());
    }

    rec.log(
        "lidar/debug/high_z",
        &Points3D::new(&high)
            .with_colors(vec![Color::from_rgb(0, 230, 180); high.len()])
            .with_radii(vec![Radius::new_ui_points(2.0); high.len()])
            .with_labels(vec!["high_z"; high.len()]),
    )?;
    Ok(())
}
