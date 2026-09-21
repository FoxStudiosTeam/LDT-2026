//! debug_viz.rs — генерация отладочных примитивов для Rerun

use rerun::{Boxes3D, Color, LineStrips3D, Points3D, Radius, RecordingStream};
use shared::error::{AppError, ErrCtx};
use shared::types::{AppPointCloud, CloudStats, ProcessingQueue};

// ─── Пороги ───────────────────────────────────────────────────────────────────
const NEAR_RANGE_M: f32 = 1.0; // точки ближе этого — "опасные"
const HIGH_Z_M: f32 = 2.0; // точки выше этого — "верхний слой"

pub trait DebugStream {
    fn log_raw_cloud(&self, point_cloud: &AppPointCloud) -> Result<(), AppError>;
    fn log_debug_overlays(
        &self,
        point_cloud: &AppPointCloud,
        stats: &CloudStats,
    ) -> Result<(), AppError>;
    fn log_debug_centroid(&self, stats: &CloudStats) -> Result<(), AppError>;
    fn log_debug_bbox(&self, stats: &CloudStats) -> Result<(), AppError>;
    fn log_debug_near_points(&self, point_cloud: &AppPointCloud) -> Result<(), AppError>;
    fn log_debug_high_points(&self, point_cloud: &AppPointCloud) -> Result<(), AppError>;
}

impl DebugStream for RecordingStream {
    /// Логируем всё облако точек в rerun
    fn log_raw_cloud(&self, point_cloud: &AppPointCloud) -> Result<(), AppError> {
        if point_cloud.is_empty(ProcessingQueue::READ) {
            tracing::info!("PointCloud is empty");
            return Ok(());
        }

        let points = point_cloud.to_rerun(ProcessingQueue::READ);
        self.log(
            "lidar/raw",
            &Points3D::new(points)
                .with_colors([Color::from_rgb(160, 185, 220)])
                .with_radii([Radius::new_ui_points(1.2)]),
        )
        .app_error()?;

        Ok(())
    }

    /// Логируем отладочные оверлеи
    fn log_debug_overlays(
        &self,
        point_cloud: &AppPointCloud,
        stats: &CloudStats,
    ) -> Result<(), AppError> {
        self.log_debug_centroid(stats)?;
        // self.log_debug_bbox(stats)?;
        // self.log_debug_near_points(point_cloud)?;
        // self.log_debug_high_points(point_cloud)?;

        Ok(())
    }

    /// Центр масс — одна большая зелёная точка
    fn log_debug_centroid(&self, stats: &CloudStats) -> Result<(), AppError> {
        self.log(
            "lidar/debug/centroid",
            &Points3D::new(&[[stats.centroid_x, stats.centroid_y, stats.centroid_z]])
                .with_colors([Color::from_rgb(50, 255, 80)])
                .with_radii([Radius::new_scene_units(0.25)])
                .with_labels(["centroid"]),
        )
        .app_error()?;

        Ok(())
    }

    /// Wireframe bounding box из 12 рёбер
    fn log_debug_bbox(&self, stats: &CloudStats) -> Result<(), AppError> {
        let x0 = stats.min_x;
        let y0 = stats.min_y;
        let z0 = stats.min_z;

        let x1 = stats.max_x;
        let y1 = stats.max_y;
        let z1 = stats.max_z;

        let edges = [
            // нижняя грань
            [[x0, y0, z0], [x1, y0, z0]],
            [[x1, y0, z0], [x1, y1, z0]],
            [[x1, y1, z0], [x0, y1, z0]],
            [[x0, y1, z0], [x0, y0, z0]],
            // верхняя грань
            [[x0, y0, z1], [x1, y0, z1]],
            [[x1, y0, z1], [x1, y1, z1]],
            [[x1, y1, z1], [x0, y1, z1]],
            [[x0, y1, z1], [x0, y0, z1]],
            // вертикальные рёбра
            [[x0, y0, z0], [x0, y0, z1]],
            [[x1, y0, z0], [x1, y0, z1]],
            [[x1, y1, z0], [x1, y1, z1]],
            [[x0, y1, z0], [x0, y1, z1]],
        ];

        self.log(
            "lidar/debug/bbox",
            &LineStrips3D::new(edges)
                .with_colors([Color::from_rgb(255, 210, 0)])
                .with_radii([Radius::new_ui_points(1.5)]),
        )
        .app_error()?;

        Ok(())
    }

    /// Точки ближе NEAR_RANGE_M к началу координат — красным
    fn log_debug_near_points(&self, point_cloud: &AppPointCloud) -> Result<(), AppError> {
        let near_sq = NEAR_RANGE_M * NEAR_RANGE_M;
        let near: Vec<[f32; 3]> = point_cloud
            .iter(ProcessingQueue::READ)
            .filter_map(|p| {
                let (x, y, z) = (*p.0, *p.1, *p.2);
                if x * x + y * y + z * z < near_sq {
                    Some([x, y, z])
                } else {
                    None
                }
            })
            .collect();

        if near.is_empty() {
            self.log(
                "lidar/debug/near_range",
                &Points3D::new([] as [[f32; 3]; 0]),
            )
            .app_error()?;
            return Ok(());
        }

        self.log(
            "lidar/debug/near_range",
            &Points3D::new(&near)
                .with_colors([Color::from_rgb(255, 60, 60)])
                .with_radii([Radius::new_ui_points(2.5)]),
        )
        .app_error()?;

        Ok(())
    }

    /// Точки выше HIGH_Z_M — бирюзовым
    fn log_debug_high_points(&self, point_cloud: &AppPointCloud) -> Result<(), AppError> {
        let high: Vec<[f32; 3]> = point_cloud
            .iter(ProcessingQueue::READ)
            .filter_map(|p| {
                let (x, y, z) = (*p.0, *p.1, *p.2);
                if z > HIGH_Z_M { Some([x, y, z]) } else { None }
            })
            .collect();

        if high.is_empty() {
            self.log("lidar/debug/high_z", &Points3D::new([] as [[f32; 3]; 0]))
                .app_error()?;
            return Ok(());
        }

        self.log(
            "lidar/debug/high_z",
            &Points3D::new(&high)
                .with_colors([Color::from_rgb(0, 230, 180)])
                .with_radii([Radius::new_ui_points(2.0)]),
        )
        .app_error()?;

        Ok(())
    }
}
