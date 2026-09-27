use shared::configs::DetectionPreset;
use shared::rail_detection::{LidarGeometry, RailTrackDetector};
use shared::range_image::RangeImage;
use std::path::Path;

fn main() {
    let frame_path = Path::new("frames/frame_000000.npy");
    if !frame_path.exists() {
        println!("Path frames/frame_000000.npy does not exist");
        return;
    }

    let raw_ri = RangeImage::load_npy(frame_path).expect("Failed to load npy");
    println!("Loaded RangeImage: {}x{}", raw_ri.width, raw_ri.height);

    let mut detector: RailTrackDetector = DetectionPreset::current().into();
    detector.geometry = LidarGeometry::new(raw_ri.height, raw_ri.width, 15.0, -25.0, 40.0);
    detector.row_end_pct = -0.50; // allow scanning all the way to row 0!

    let active_ri = if detector.obstacle_config.upward_curvature.abs() > 1e-7 {
        raw_ri.warp_curvature(
            &detector.geometry,
            detector.obstacle_config.upward_curvature,
        )
    } else {
        raw_ri.clone()
    };

    println!(
        "Starting detect_with_raw with row_end_pct = {}",
        detector.row_end_pct
    );
    let res = detector.detect_with_raw(&active_ri, Some(&raw_ri), 0);
    match res {
        Some(r) => {
            println!(
                "SUCCESS! Detected {} points, gauge={:.3}, radius={:.1}",
                r.points.len(),
                r.gauge,
                r.turn_radius
            );
            let min_row = r.points.iter().map(|p| p.row).min().unwrap_or(0);
            let max_row = r.points.iter().map(|p| p.row).max().unwrap_or(0);
            let min_x = r
                .points
                .iter()
                .map(|p| p.x_center)
                .fold(f32::INFINITY, f32::min);
            let max_x = r
                .points
                .iter()
                .map(|p| p.x_center)
                .fold(f32::NEG_INFINITY, f32::max);
            println!(
                "Row range in result: {} .. {} (min row pct = {:.2}%)",
                min_row,
                max_row,
                (min_row as f32 / raw_ri.height as f32) * 100.0
            );
            println!("Distance X range: {:.2}m .. {:.2}m", min_x, max_x);
        }
        None => {
            println!("Detection returned None!");
        }
    }
}
