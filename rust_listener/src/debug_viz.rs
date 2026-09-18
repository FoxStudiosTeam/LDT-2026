//! debug_viz.rs — генерация отладочных примитивов для Rerun

use anyhow::Result;
use ddl::{AppPointCloud, CloudStats};
use rerun::{Color, LineStrips3D, Points3D, Radius, RecordingStream};



// ─── Пороги ───────────────────────────────────────────────────────────────────
const NEAR_RANGE_M: f32 = 1.0; // точки ближе этого — "опасные"
const HIGH_Z_M: f32 = 2.0; // точки выше этого — "верхний слой"

/// Логируем всё облако точек в rerun
pub fn log_raw_cloud(rec: &RecordingStream, point_cloud : &AppPointCloud) -> Result<()> {
    if point_cloud.is_empty() {
        return Ok(());
    }

    rec.log(
        "lidar/raw",
        &Points3D::new(point_cloud.to_rerun())
            .with_colors([Color::from_rgb(160, 185, 220)])
            .with_radii([Radius::new_ui_points(1.2)]),
    )?;

    Ok(())
}

/// Логируем отладочные оверлеи
pub fn log_debug_overlays(
    rec: &RecordingStream,
    point_cloud: &AppPointCloud,
    stats: &CloudStats,
) -> Result<()> {
    // 1. Центр масс
    log_centroid(rec, stats)?;

    // 2. Bounding box
    log_bbox(rec, stats)?;

    // 3. Близкие точки (< NEAR_RANGE_M)
    log_near_points(rec, point_cloud)?;

    // 4. Высокие точки (Z > HIGH_Z_M)
    log_high_points(rec, point_cloud)?;

    Ok(())
}

/// Центр масс — одна большая зелёная точка
fn log_centroid(rec: &RecordingStream, stats: &CloudStats) -> Result<()> {
    rec.log(
        "lidar/debug/centroid",
        &Points3D::new(&[[stats.centroid_x,stats.centroid_y, stats.centroid_z]])
            .with_colors([Color::from_rgb(50, 255, 80)])
            .with_radii([Radius::new_scene_units(0.25)])
            .with_labels(["centroid"]),
    )?;
    Ok(())
}

/// Wireframe bounding box — 12 рёбер жёлтым
fn log_bbox(rec: &RecordingStream, stats: &CloudStats) -> Result<()> {
    let x0 = stats.min_x;
    let y0 = stats.min_y;
    let z0 = stats.min_z;

    let x1 = stats.max_x;
    let y1 = stats.max_y;
    let z1 = stats.max_z;

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
fn log_near_points(rec: &RecordingStream, point_cloud: &AppPointCloud) -> Result<()> {
   let near: Vec<[f32; 3]> = point_cloud
        .iter()
        // Принимаем p (это ссылка на твой кортеж)
        .filter(|p| {
            // Достаем ссылки &f32 через точку и разыменовываем их звездочкой
            let x = *p.0;
            let y = *p.1;
            let z = *p.2;
            let dist2 = x * x + y * y + z * z;
            dist2 < NEAR_RANGE_M * NEAR_RANGE_M
        })
        // В map приходит сам кортеж по значению, достаем элементы так же
        .map(|p| [*p.0, *p.1, *p.2])
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
fn log_high_points(rec: &RecordingStream, point_cloud: &AppPointCloud) -> Result<()> {
    let high: Vec<[f32; 3]> = point_cloud
    .iter()
    .filter(|&(_, _, &z, _)| z > HIGH_Z_M) 
    .map(|(&x, &y, &z, _)| [x, y, z])
    .collect();


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
