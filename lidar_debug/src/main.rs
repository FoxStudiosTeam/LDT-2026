mod cdr;
mod utils;

use std::path::Path;

use anyhow::Result;
use nalgebra::Vector3;
use rand::Rng;

use utils::{cache_entire_bag, perform_boxcast, perform_boxcast_fast, timed, CachedReplay, Timer};

const DB3_PATH: &str = "dataset/roundT_doubleT/roundT_doubleT_0.db3";
const LIDAR_TOPIC: &str = "/lidar_points";
const CACHE_DIR: &str = ".cache";
const FRAME_INDEX: i64 = 90;

fn train_size() -> Vector3<f32> {
    Vector3::new(2.1, 2.0, 3.0) * 0.5
}

fn bottom_hit_offset() -> Vector3<f32> {
    Vector3::new(0.0, 0.0, 0.1)
}

fn r() -> f32 {
    rand::thread_rng().gen_range(0.0..1.0).into()
}

/// Прямой порт `train_shapecast` (наивный boxcast).
fn train_shapecast(rec: &rerun::RecordingStream, points: &[[f32; 3]]) {
    timed("train_shapecast", || {
        let col_first = [255u8, 230, 230];
        let step = 5.0f32;

        let _t = Timer::new("Train Shapecast");

        let mut origin = Vector3::new(-0.9f32, -5.0, 1.0);
        let mut direction = Vector3::new(0.0f32, 0.0, -1.0);
        let y_box_size = Vector3::new(0.3f32, 5.0, 0.2);
        let x_box_size = Vector3::new(0.2f32, 5.0, 0.3);

        for _ in 0..30 {
            origin += Vector3::new(0.0, -step, 0.0);

            let hit = match perform_boxcast(points, origin, direction, y_box_size, 5.0, 0.05) {
                Some(h) => h,
                None => return,
            };

            log_box(rec, &hit.center, &y_box_size, col_first);
            log_points(rec, &hit.points, col_first);

            let top_pos = origin + direction * hit.dist + bottom_hit_offset();
            let mut left_pos = top_pos - Vector3::new(-0.25, 0.0, 0.12);

            direction = Vector3::new(-1.0, 0.0, 0.0);
            let hit2 = match perform_boxcast(points, left_pos, direction, y_box_size, 15.0, 0.05) {
                Some(h) => h,
                None => continue,
            };

            log_box(rec, &hit2.center, &x_box_size, col_first);
            log_points(rec, &hit2.points, col_first);

            left_pos = left_pos + direction * hit2.dist + bottom_hit_offset();
            left_pos += Vector3::new(0.0, -step, 0.0);
            let _ = left_pos; // используется только для повторения структуры python-версии
        }
    });
}

/// Прямой порт `train_shapecast_fast` (векторизованный boxcast).
fn train_shapecast_fast(rec: &rerun::RecordingStream, points: &[[f32; 3]]) {
    timed("train_shapecast_fast", || {
        let col_first = [255u8, 230, 230];
        let step = 5.0f32;

        let _t = Timer::new("Train Shapecast");

        let mut origin = Vector3::new(-0.9f32, -5.0, 1.0);
        let mut direction = Vector3::new(0.0f32, 0.0, -1.0);
        let y_box_size = Vector3::new(0.3f32, 5.0, 0.2);
        let x_box_size = Vector3::new(0.2f32, 5.0, 0.3);

        for _ in 0..30 {
            origin += Vector3::new(0.0, -step, 0.0);

            let hit = match perform_boxcast_fast(points, origin, direction, y_box_size, 5.0, 0.05) {
                Some(h) => h,
                None => return,
            };

            log_box(rec, &hit.center, &y_box_size, col_first);
            log_points(rec, &hit.points, col_first);

            let top_pos = origin + direction * hit.dist + bottom_hit_offset();
            let mut left_pos = top_pos - Vector3::new(-0.25, 0.0, 0.12);

            direction = Vector3::new(-1.0, 0.0, 0.0);
            let hit2 =
                match perform_boxcast_fast(points, left_pos, direction, y_box_size, 15.0, 0.05) {
                    Some(h) => h,
                    None => continue,
                };

            log_box(rec, &hit2.center, &x_box_size, col_first);
            log_points(rec, &hit2.points, col_first);

            left_pos = left_pos + direction * hit2.dist + bottom_hit_offset();
            left_pos += Vector3::new(0.0, -step, 0.0);
            let _ = left_pos;
        }
    });
}

fn log_box(
    rec: &rerun::RecordingStream,
    center: &Vector3<f32>,
    size: &Vector3<f32>,
    color: [u8; 3],
) {
    let path = format!("world/start{}", r());
    let half = *size * 0.5;
    let _ = rec.log(
        path,
        &rerun::Boxes3D::from_centers_and_half_sizes(
            [(center.x, center.y, center.z)],
            [(half.x, half.y, half.z)],
        )
        .with_colors([rerun::Color::from_rgb(color[0], color[1], color[2])]),
    );
}

fn log_points(rec: &rerun::RecordingStream, points: &[[f32; 3]], color: [u8; 3]) {
    if points.is_empty() {
        return;
    }
    let path = format!("world/start{}", r());
    let pts: Vec<(f32, f32, f32)> = points.iter().map(|p| (p[0], p[1], p[2])).collect();
    let _ = rec.log(
        path,
        &rerun::Points3D::new(pts)
            .with_radii([0.05])
            .with_colors([rerun::Color::from_rgb(color[0], color[1], color[2])]),
    );
}

fn main() -> Result<()> {
    let rec = {
        let _t = Timer::new("Rerun Init");
        let rec = rerun::RecordingStreamBuilder::new("lidar_single_frame_debug").spawn()?;
        rec.log("world", &rerun::Clear::recursive())?;
        rec
    };

    let db_path = Path::new(DB3_PATH);
    let cache_dir = Path::new(CACHE_DIR);
    let full_cache_path = cache_entire_bag(db_path, cache_dir, LIDAR_TOPIC)?;

    let (points, _timestamp) = {
        let _t = Timer::new("Cached Replay");
        let replay = CachedReplay::load(&full_cache_path)?;
        let _t2 = Timer::new("Get frame");
        let (pts, ts) = replay.get_frame(1)?;
        (pts.to_vec(), ts)
    };

    {
        let _t = Timer::new("Rerun Setup Logs");
        rec.set_time_sequence("bag_time", FRAME_INDEX);

        let train_half = train_size();
        rec.log(
            "world/train",
            &rerun::Boxes3D::from_centers_and_half_sizes(
                [(0.0, -4.0, 0.0)],
                [(train_half.x, train_half.y, train_half.z)],
            )
            .with_colors([rerun::Color::from_rgb(20, 255, 20)]),
        )?;

        let pts: Vec<(f32, f32, f32)> = points.iter().map(|p| (p[0], p[1], p[2])).collect();
        rec.log(
            "world/points",
            &rerun::Points3D::new(pts)
                .with_radii([0.02])
                .with_colors([rerun::Color::from_rgb(200, 200, 200)]),
        )?;
    }

    train_shapecast(&rec, &points);
    train_shapecast_fast(&rec, &points);

    Ok(())
}
