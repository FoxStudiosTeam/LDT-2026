//! debug_viz.rs — генерация отладочных примитивов для Rerun

use rerun::{
    Boxes2D, Boxes3D, Color, LineStrips2D, LineStrips3D, Points2D, Points3D, Radius,
    RecordingStream,
};
use shared::error::{AppError, ErrCtx};
use shared::types::{AppPointCloud, CloudStats, ProcessingQueue, is_zero_point};

// ─── Пороги ───────────────────────────────────────────────────────────────────
const NEAR_RANGE_M: f32 = 1.0; // точки ближе этого — "опасные"
const HIGH_Z_M: f32 = 2.0; // точки выше этого — "верхний слой"

/// 2D прямоугольник (bounding box) для отладки поверх кадров глубины
#[derive(Clone, Debug)]
pub struct DebugBox2D {
    pub min_x: f32,
    pub min_y: f32,
    pub width: f32,
    pub height: f32,
    pub label: Option<String>,
    pub color: [u8; 3],
    pub stroke_width: f32,
}

impl DebugBox2D {
    pub fn new(min_x: f32, min_y: f32, width: f32, height: f32) -> Self {
        Self {
            min_x,
            min_y,
            width,
            height,
            label: None,
            color: [255, 60, 60],
            stroke_width: 1.5,
        }
    }

    pub fn with_label(mut self, label: impl Into<String>) -> Self {
        self.label = Some(label.into());
        self
    }

    pub fn with_color(mut self, color: [u8; 3]) -> Self {
        self.color = color;
        self
    }

    pub fn with_stroke_width(mut self, width: f32) -> Self {
        self.stroke_width = width;
        self
    }
}

/// 2D ломаная линия / отрезок для отладки поверх кадров глубины
#[derive(Clone, Debug)]
pub struct DebugLine2D {
    pub points: Vec<[f32; 2]>,
    pub label: Option<String>,
    pub color: [u8; 3],
    pub stroke_width: f32,
}

impl DebugLine2D {
    pub fn new(points: Vec<[f32; 2]>) -> Self {
        Self {
            points,
            label: None,
            color: [0, 230, 180],
            stroke_width: 1.5,
        }
    }

    pub fn segment(p1: [f32; 2], p2: [f32; 2]) -> Self {
        Self::new(vec![p1, p2])
    }

    pub fn with_label(mut self, label: impl Into<String>) -> Self {
        self.label = Some(label.into());
        self
    }

    pub fn with_color(mut self, color: [u8; 3]) -> Self {
        self.color = color;
        self
    }

    pub fn with_stroke_width(mut self, width: f32) -> Self {
        self.stroke_width = width;
        self
    }
}

/// 3D бокс для отладки в 3D пространстве лидара
#[derive(Clone, Debug)]
pub struct DebugBox3D {
    pub center: [f32; 3],
    pub size: [f32; 3],
    pub label: Option<String>,
    pub color: [u8; 3],
}

impl DebugBox3D {
    pub fn new(center: [f32; 3], size: [f32; 3]) -> Self {
        Self {
            center,
            size,
            label: None,
            color: [255, 60, 60],
        }
    }

    pub fn with_label(mut self, label: impl Into<String>) -> Self {
        self.label = Some(label.into());
        self
    }

    pub fn with_color(mut self, color: [u8; 3]) -> Self {
        self.color = color;
        self
    }
}

pub trait DebugStream {
    fn log_raw_cloud(&self, point_cloud: &AppPointCloud) -> Result<(), AppError>;
    fn log_raw_points(&self, point_cloud: &AppPointCloud) -> Result<(), AppError>;
    fn log_points_with_colors(&self, points: &[[f32; 3]], colors: &[Color])
    -> Result<(), AppError>;
    fn log_debug_overlays(
        &self,
        point_cloud: &AppPointCloud,
        stats: &CloudStats,
    ) -> Result<(), AppError>;
    fn log_debug_centroid(&self, stats: &CloudStats) -> Result<(), AppError>;
    fn log_debug_bbox(&self, stats: &CloudStats) -> Result<(), AppError>;
    fn log_debug_near_points(&self, point_cloud: &AppPointCloud) -> Result<(), AppError>;
    fn log_debug_high_points(&self, point_cloud: &AppPointCloud) -> Result<(), AppError>;
    fn log_depth_image(
        &self,
        range_image: &shared::range_image::RangeImage,
        fov_x_deg: f32,
    ) -> Result<(), AppError>;

    // ─── API отладки поверх 2D кадров и в 3D ───
    fn log_boxes_2d(&self, entity_path: &str, boxes: &[DebugBox2D]) -> Result<(), AppError>;
    fn log_lines_2d(&self, entity_path: &str, lines: &[DebugLine2D]) -> Result<(), AppError>;
    fn log_points_2d(
        &self,
        entity_path: &str,
        points: &[[f32; 2]],
        color: [u8; 3],
        radius_ui: f32,
    ) -> Result<(), AppError>;
    fn log_boxes_3d(&self, entity_path: &str, boxes: &[DebugBox3D]) -> Result<(), AppError>;
    fn log_demo_overlay_on_frame(&self, fov_w: usize, fov_h: usize) -> Result<(), AppError>;

    // ─── Визуализация детектора рельсов в 3D и телеметрии ───
    fn log_rail_detection(
        &self,
        res: Option<&shared::rail_detection::DetectionResult>,
    ) -> Result<(), AppError>;

    fn log_range_image_3d(
        &self,
        frame: &shared::range_image::RangeImage,
        geo: &shared::rail_detection::LidarGeometry,
    ) -> Result<(), AppError>;

    fn log_range_image_3d_dist(
        &self,
        frame: &shared::range_image::RangeImage,
        geo: &shared::rail_detection::LidarGeometry,
        max_dist_m: f32,
    ) -> Result<(), AppError>;
}

impl DebugStream for RecordingStream {
    /// Логируем всё облако точек в rerun
    fn log_raw_cloud(&self, point_cloud: &AppPointCloud) -> Result<(), AppError> {
        if point_cloud.is_empty(ProcessingQueue::READ) {
            tracing::info!("PointCloud is empty");
            return Ok(());
        }

        let q = ProcessingQueue::READ;

        let points = point_cloud.to_rerun(q);
        let colors = point_cloud.to_rerun_colors(q);

        self.log(
            "lidar/raw",
            &Points3D::new(points)
                .with_colors(colors)
                .with_radii([Radius::new_ui_points(1.2)]),
        )
        .app_error()?;

        Ok(())
    }

    /// Логируем готовый срез точек без удержания лочки AppPointCloud
    fn log_raw_points(&self, point_cloud: &AppPointCloud) -> Result<(), AppError> {
        let q = ProcessingQueue::READ;

        if point_cloud.is_empty(q) {
            return Ok(());
        }

        let colors = point_cloud.to_rerun_colors(q);

        self.log(
            "lidar/raw",
            &Points3D::new(point_cloud.to_rerun(q))
                .with_colors(colors)
                .with_radii([Radius::new_ui_points(1.2)]),
        )
        .app_error()?;

        Ok(())
    }

    /// Логируем срез точек с индивидуальными цветами (например, intensity colormap)
    fn log_points_with_colors(
        &self,
        points: &[[f32; 3]],
        colors: &[Color],
    ) -> Result<(), AppError> {
        if points.is_empty() {
            return Ok(());
        }

        self.log(
            "lidar/raw",
            &Points3D::new(points)
                .with_colors(colors.iter().copied())
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
                if is_zero_point(x, y, z) {
                    return None;
                }
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
                if is_zero_point(x, y, z) {
                    return None;
                }
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

    /// 2D Карта глубины (Range Image)
    fn log_depth_image(
        &self,
        range_image: &shared::range_image::RangeImage,
        fov_x_deg: f32,
    ) -> Result<(), AppError> {
        let depth_img = range_image.to_rerun()?;
        // Логируем в отдельный корень "depth_image/...", чтобы Rerun не требовал Pinhole для 3D
        self.log("depth_image/raw", &depth_img).app_error()?;

        // Сырой (без интерполяции) урезанный кадр
        let cropped = range_image.crop_fov(fov_x_deg);
        let crop_img = cropped.to_rerun()?;
        self.log("depth_image/crop", &crop_img).app_error()?;

        // Логируем сглаженный фронтальный превью высокого разрешения (800x600, 4:3) с настраиваемым углом обзора
        let preview = range_image.front_view_preview_fov(fov_x_deg, 800, 600); // 800x600 с билинейной интерполяцией
        let preview_img = preview.to_rerun()?;
        self.log("depth_image/front_preview", &preview_img)
            .app_error()?;

        // Демонстрационный оверлей линий и боксов поверх превью
        self.log_demo_overlay_on_frame(preview.width, preview.height)?;

        Ok(())
    }

    /// Логирование 2D боксов (прямоугольников) поверх указанной 2D сущности (например "depth_image/front_preview/boxes")
    fn log_boxes_2d(&self, entity_path: &str, boxes: &[DebugBox2D]) -> Result<(), AppError> {
        if boxes.is_empty() {
            self.log(
                entity_path,
                &Boxes2D::from_mins_and_sizes([] as [[f32; 2]; 0], [] as [[f32; 2]; 0]),
            )
            .app_error()?;
            return Ok(());
        }

        let mins: Vec<[f32; 2]> = boxes.iter().map(|b| [b.min_x, b.min_y]).collect();
        let sizes: Vec<[f32; 2]> = boxes.iter().map(|b| [b.width, b.height]).collect();
        let colors: Vec<Color> = boxes
            .iter()
            .map(|b| Color::from_rgb(b.color[0], b.color[1], b.color[2]))
            .collect();
        let radii: Vec<Radius> = boxes
            .iter()
            .map(|b| Radius::new_ui_points(b.stroke_width))
            .collect();
        let labels: Vec<String> = boxes
            .iter()
            .map(|b| b.label.clone().unwrap_or_default())
            .collect();

        self.log(
            entity_path,
            &Boxes2D::from_mins_and_sizes(mins, sizes)
                .with_colors(colors)
                .with_radii(radii)
                .with_labels(labels),
        )
        .app_error()?;

        Ok(())
    }

    /// Логирование 2D линий поверх указанной 2D сущности (например "depth_image/front_preview/lines")
    fn log_lines_2d(&self, entity_path: &str, lines: &[DebugLine2D]) -> Result<(), AppError> {
        if lines.is_empty() {
            self.log(entity_path, &LineStrips2D::new([] as [Vec<[f32; 2]>; 0]))
                .app_error()?;
            return Ok(());
        }

        let strips: Vec<Vec<[f32; 2]>> = lines.iter().map(|l| l.points.clone()).collect();
        let colors: Vec<Color> = lines
            .iter()
            .map(|l| Color::from_rgb(l.color[0], l.color[1], l.color[2]))
            .collect();
        let radii: Vec<Radius> = lines
            .iter()
            .map(|l| Radius::new_ui_points(l.stroke_width))
            .collect();
        let labels: Vec<String> = lines
            .iter()
            .map(|l| l.label.clone().unwrap_or_default())
            .collect();

        self.log(
            entity_path,
            &LineStrips2D::new(strips)
                .with_colors(colors)
                .with_radii(radii)
                .with_labels(labels),
        )
        .app_error()?;

        Ok(())
    }

    /// Логирование 2D точек поверх указанной 2D сущности
    fn log_points_2d(
        &self,
        entity_path: &str,
        points: &[[f32; 2]],
        color: [u8; 3],
        radius_ui: f32,
    ) -> Result<(), AppError> {
        if points.is_empty() {
            self.log(entity_path, &Points2D::new([] as [[f32; 2]; 0]))
                .app_error()?;
            return Ok(());
        }

        self.log(
            entity_path,
            &Points2D::new(points)
                .with_colors([Color::from_rgb(color[0], color[1], color[2])])
                .with_radii([Radius::new_ui_points(radius_ui)]),
        )
        .app_error()?;

        Ok(())
    }

    /// Логирование 3D боксов
    fn log_boxes_3d(&self, entity_path: &str, boxes: &[DebugBox3D]) -> Result<(), AppError> {
        if boxes.is_empty() {
            self.log(
                entity_path,
                &Boxes3D::from_centers_and_sizes([] as [[f32; 3]; 0], [] as [[f32; 3]; 0]),
            )
            .app_error()?;
            return Ok(());
        }

        let centers: Vec<[f32; 3]> = boxes.iter().map(|b| b.center).collect();
        let sizes: Vec<[f32; 3]> = boxes.iter().map(|b| b.size).collect();
        let colors: Vec<Color> = boxes
            .iter()
            .map(|b| Color::from_rgb(b.color[0], b.color[1], b.color[2]))
            .collect();
        let labels: Vec<String> = boxes
            .iter()
            .map(|b| b.label.clone().unwrap_or_default())
            .collect();

        self.log(
            entity_path,
            &Boxes3D::from_centers_and_sizes(centers, sizes)
                .with_colors(colors)
                .with_labels(labels),
        )
        .app_error()?;

        Ok(())
    }

    /// Демонстрационный оверлей: направляющие рельсов и зона препятствия прямо поверх кадра
    fn log_demo_overlay_on_frame(&self, fov_w: usize, fov_h: usize) -> Result<(), AppError> {
        let w = fov_w as f32;
        let h = fov_h as f32;

        // 1. Направляющие линии колеи (рельсы)
        let left_rail = DebugLine2D::segment([w * 0.38, h * 0.98], [w * 0.46, h * 0.48])
            .with_label("left_rail")
            .with_color([255, 215, 0]) // золотисто-желтый
            .with_stroke_width(2.0);

        let right_rail = DebugLine2D::segment([w * 0.62, h * 0.98], [w * 0.54, h * 0.48])
            .with_label("right_rail")
            .with_color([255, 215, 0])
            .with_stroke_width(2.0);

        self.log_lines_2d("depth_image/front_preview/rails", &[left_rail, right_rail])?;

        // 2. Детектированная зона / габарит препятствия
        let obstacle_box = DebugBox2D::new(w * 0.44, h * 0.42, w * 0.12, h * 0.18)
            .with_label("Track Clearance ROI")
            .with_color([0, 255, 128]) // зеленый контур
            .with_stroke_width(2.0);

        self.log_boxes_2d("depth_image/front_preview/clearance_box", &[obstacle_box])?;

        Ok(())
    }

    fn log_rail_detection(
        &self,
        res: Option<&shared::rail_detection::DetectionResult>,
    ) -> Result<(), AppError> {
        if let Some(r) = res {
            // 1. Centerline 3D curve (Bright Green)
            let center_pts: Vec<[f32; 3]> = (0..r.x_curve.len())
                .map(|i| [r.x_curve[i], r.y_center[i], r.z_center[i]])
                .collect();
            self.log(
                "tracks/3d/centerline",
                &LineStrips3D::new([center_pts])
                    .with_colors([Color::from_rgb(0, 255, 60)])
                    .with_radii([Radius::new_ui_points(2.5)]),
            )
            .app_error()?;

            // 2. Left rail 3D curve (Cyan)
            let left_pts: Vec<[f32; 3]> = (0..r.x_left.len())
                .map(|i| [r.x_left[i], r.y_left[i], r.z_center[i]])
                .collect();
            self.log(
                "tracks/3d/left_rail",
                &LineStrips3D::new([left_pts])
                    .with_colors([Color::from_rgb(30, 210, 255)])
                    .with_radii([Radius::new_ui_points(2.5)]),
            )
            .app_error()?;

            // 3. Right rail 3D curve (Orange-Red)
            let right_pts: Vec<[f32; 3]> = (0..r.x_right.len())
                .map(|i| [r.x_right[i], r.y_right[i], r.z_center[i]])
                .collect();
            self.log(
                "tracks/3d/right_rail",
                &LineStrips3D::new([right_pts])
                    .with_colors([Color::from_rgb(255, 90, 30)])
                    .with_radii([Radius::new_ui_points(2.5)]),
            )
            .app_error()?;

            // 4. Sleepers / Ties (Cross ties every 4 points)
            let mut sleepers: Vec<Vec<[f32; 3]>> = Vec::new();
            for i in (0..r.x_curve.len()).step_by(4) {
                sleepers.push(vec![
                    [r.x_left[i], r.y_left[i], r.z_center[i]],
                    [r.x_right[i], r.y_right[i], r.z_center[i]],
                ]);
            }
            self.log(
                "tracks/3d/sleepers",
                &LineStrips3D::new(sleepers)
                    .with_colors([Color::from_rgb(180, 220, 180)])
                    .with_radii([Radius::new_ui_points(1.2)]),
            )
            .app_error()?;

            // 5. Detected raw rail points markers
            let pts_l: Vec<[f32; 3]> = r
                .points
                .iter()
                .map(|p| [p.x_left, p.y_left, p.z_left])
                .collect();
            let pts_r: Vec<[f32; 3]> = r
                .points
                .iter()
                .map(|p| [p.x_right, p.y_right, p.z_right])
                .collect();
            let pts_c: Vec<[f32; 3]> = r
                .points
                .iter()
                .map(|p| [p.x_center, p.y_center, p.z_center])
                .collect();

            self.log(
                "tracks/3d/points_left",
                &Points3D::new(pts_l)
                    .with_colors([Color::from_rgb(0, 255, 255)])
                    .with_radii([Radius::new_ui_points(3.0)]),
            )
            .app_error()?;

            self.log(
                "tracks/3d/points_right",
                &Points3D::new(pts_r)
                    .with_colors([Color::from_rgb(255, 120, 0)])
                    .with_radii([Radius::new_ui_points(3.0)]),
            )
            .app_error()?;

            self.log(
                "tracks/3d/points_center",
                &Points3D::new(pts_c)
                    .with_colors([Color::from_rgb(255, 255, 0)])
                    .with_radii([Radius::new_ui_points(2.0)]),
            )
            .app_error()?;
        } else {
            // Clear visualization on frames where no track detected
            let _ = self.log(
                "tracks/3d/centerline",
                &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
            );
            let _ = self.log(
                "tracks/3d/left_rail",
                &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
            );
            let _ = self.log(
                "tracks/3d/right_rail",
                &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
            );
            let _ = self.log(
                "tracks/3d/sleepers",
                &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]),
            );
            let _ = self.log("tracks/3d/points_left", &Points3D::new([] as [[f32; 3]; 0]));
            let _ = self.log(
                "tracks/3d/points_right",
                &Points3D::new([] as [[f32; 3]; 0]),
            );
            let _ = self.log(
                "tracks/3d/points_center",
                &Points3D::new([] as [[f32; 3]; 0]),
            );
        }

        Ok(())
    }

    fn log_range_image_3d(
        &self,
        frame: &shared::range_image::RangeImage,
        geo: &shared::rail_detection::LidarGeometry,
    ) -> Result<(), AppError> {
        self.log_range_image_3d_dist(frame, geo, 250.0)
    }

    fn log_range_image_3d_dist(
        &self,
        frame: &shared::range_image::RangeImage,
        geo: &shared::rail_detection::LidarGeometry,
        max_dist_m: f32,
    ) -> Result<(), AppError> {
        let mut pts = Vec::with_capacity(frame.width * frame.height / 2);
        let mut colors = Vec::with_capacity(frame.width * frame.height / 2);

        for row in 0..frame.height {
            for col in 0..frame.width {
                let r = frame.get(row, col);
                if r > 0.5 && r < max_dist_m {
                    let (x, y, z) = geo.row_col_range_to_xyz(row, col, r);
                    pts.push([x, y, z]);
                    // Плавный цветовой градиент на всю глубину обзора (ближние - сине-зеленые, дальние - теплые)
                    let norm = (r / (max_dist_m * 0.4).max(40.0)).clamp(0.0, 1.0);
                    let color = Color::from_rgb(
                        (norm * 200.0) as u8,
                        (120.0 + (1.0 - norm) * 135.0) as u8,
                        ((1.0 - norm) * 255.0) as u8,
                    );
                    colors.push(color);
                }
            }
        }

        self.log(
            "lidar/points",
            &Points3D::new(pts)
                .with_colors(colors)
                .with_radii([Radius::new_ui_points(1.2)]),
        )
        .app_error()?;

        Ok(())
    }
}
