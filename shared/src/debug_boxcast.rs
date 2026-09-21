//! Визуализация boxcast в Rerun.
//!
//! Что рисуется (`lidar/debug/boxcast/*`):
//!  * `start`  — стартовый бокс (серый);
//!  * `sweep`  — прямоугольник движения, в котором ищутся точки (синий);
//!  * `end`    — бокс в позиции, до которой он доехал (зелёный — путь свободен,
//!               красный — столкновение), в подписи расстояние и счётчики;
//!  * `hit`    — точки столкновения (красные): `threshold` ближайших точек;
//!  * `noise`  — если точек в объёме меньше `threshold`: отсеянные точки (жёлтые);
//!  * `points_in_sweep` — временной ряд: сколько точек попало в объём движения.

use crate::{
    boxcast::{BoxCastQuery, BoxCastResult},
    error::{AppError, ErrCtx},
};
use rerun::{Boxes3D, Clear, Color, Points3D, Radius, RecordingStream, Scalars};

const START: &str = "lidar/debug/boxcast/start";
const SWEEP: &str = "lidar/debug/boxcast/sweep";
const END: &str = "lidar/debug/boxcast/end";
const HIT: &str = "lidar/debug/boxcast/hit";
const NOISE: &str = "lidar/debug/boxcast/noise";
const COUNT: &str = "lidar/debug/boxcast/points_in_sweep";

// todo: trait
pub fn log_boxcast(
    rec: &RecordingStream,
    q: &BoxCastQuery,
    r: &BoxCastResult,
) -> Result<(), AppError> {
    let line = Radius::new_ui_points(1.5);

    // Стартовый бокс
    rec.log(
        START,
        &Boxes3D::from_centers_and_half_sizes([q.center], [q.half_size])
            .with_colors([Color::from_rgb(150, 150, 150)])
            .with_radii([line]),
    )
    .app_error()?;

    // Прямоугольник движения
    let (sweep_center, sweep_half) = q.sweep_volume();
    rec.log(
        SWEEP,
        &Boxes3D::from_centers_and_half_sizes([sweep_center], [sweep_half])
            .with_colors([Color::from_rgb(80, 160, 255)])
            .with_radii([line]),
    )
    .app_error()?;

    // Бокс в конечной позиции
    let (color, label) = if r.hit {
        (
            Color::from_rgb(255, 60, 60),
            format!(
                "HIT d={:.2} m | {} pts (в объёме: {})",
                r.distance, r.nearest_len, r.points_in_sweep
            ),
        )
    } else {
        (
            Color::from_rgb(50, 255, 80),
            format!(
                "FREE d={:.2} m | в объёме: {} (< порога)",
                r.distance, r.points_in_sweep
            ),
        )
    };
    rec.log(
        END,
        &Boxes3D::from_centers_and_half_sizes([q.box_center_at(r.distance)], [q.half_size])
            .with_colors([color])
            .with_radii([line])
            .with_labels([label]),
    )
    .app_error()?;

    // Точки: подтверждённое столкновение или отсеянный шум
    let points = r.nearest_points();
    if r.hit {
        rec.log(
            HIT,
            &Points3D::new(points.iter().copied())
                .with_colors([Color::from_rgb(255, 40, 40)])
                .with_radii([Radius::new_scene_units(0.06)]),
        )
        .app_error()?;
        rec.log(NOISE, &Clear::flat()).app_error()?;
    } else if !points.is_empty() {
        rec.log(
            NOISE,
            &Points3D::new(points.iter().copied())
                .with_colors([Color::from_rgb(255, 210, 40)])
                .with_radii([Radius::new_scene_units(0.06)]),
        )
        .app_error()?;
        rec.log(HIT, &Clear::flat()).app_error()?;
    } else {
        rec.log(HIT, &Clear::flat()).app_error()?;
        rec.log(NOISE, &Clear::flat()).app_error()?;
    }

    rec.log(COUNT, &Scalars::single(r.points_in_sweep as f64))
        .app_error()?;

    Ok(())
}
