//! main.rs — Rail Track Detection & Trajectory Prediction in Rust
//!
//! Rust port of Python `dev_pyrails/main.py`:
//!
//! Usage:
//!   cargo run -p dev_pyrails_rust -- --frame 100               # Process single frame & save composite PNG
//!   cargo run -p dev_pyrails_rust -- --range 50 150           # Process range of frames
//!   cargo run -p dev_pyrails_rust -- --all                    # Process all frames in frames/
//!   cargo run -p dev_pyrails_rust -- --interactive            # Interactive desktop GUI with slider & playback
//!   cargo run -p dev_pyrails_rust -- --all --rerun            # Process all frames and stream 3D to Rerun

mod gui;
mod visualizer;

use std::path::{Path, PathBuf};
use std::time::Instant;

use clap::Parser;
use rerun::{Color, LineStrips3D, Points3D, Radius, RecordingStreamBuilder};
use shared::rail_detection::{LidarGeometry, RailTrackDetector};
use shared::range_image::RangeImage;
use visualizer::RailVisualizer;

#[derive(Parser, Debug)]
#[command(author, version, about = "Rail Track Detection & Trajectory Prediction (Rust)", long_about = None)]
struct Cli {
    /// Path to folder containing frame_*.npy files
    #[arg(short = 'd', long, default_value = "frames")]
    frames_dir: String,

    /// Single frame number to process (e.g. --frame 100)
    #[arg(short = 'f', long)]
    frame: Option<usize>,

    /// Process frame range [START, END] (e.g. --range 50 150)
    #[arg(short = 'r', long, num_args = 2, value_names = ["START", "END"])]
    range: Option<Vec<usize>>,

    /// Process all frames in frames folder
    #[arg(short = 'a', long)]
    all: bool,

    /// Video playback / processing FPS (default: 12.0)
    #[arg(long, default_value_t = 12.0)]
    fps: f64,

    /// Extrapolation distance in meters beyond detected track
    #[arg(short = 'e', long, default_value_t = 15.0)]
    extrapolate_m: f32,

    /// Number of consecutive frames for temporal averaging
    #[arg(short = 's', long, default_value_t = 5)]
    smooth_n: usize,

    /// Output directory for composite images and screenshots
    #[arg(short = 'o', long, default_value = "output")]
    output_dir: String,

    /// Launch interactive desktop GUI with timeline slider & playback
    #[arg(short, long)]
    interactive: bool,

    /// Connect or spawn Rerun 3D viewer and stream results
    #[arg(long)]
    rerun: bool,

    /// Do not save composite PNG images to disk
    #[arg(long)]
    no_save: bool,
}

fn find_frames_dir(specified: &str) -> PathBuf {
    let cand = PathBuf::from(specified);
    if cand.exists() {
        return cand;
    }
    for alt in &[
        "../frames",
        "../../frames",
        "dev_pyrails/../frames",
        "frames",
    ] {
        let p = PathBuf::from(alt);
        if p.exists() {
            return p;
        }
    }
    cand
}

fn get_frame_paths(dir: &Path) -> Vec<(usize, PathBuf)> {
    let mut files = Vec::new();
    if let Ok(entries) = std::fs::read_dir(dir) {
        for entry in entries.flatten() {
            let path = entry.path();
            if path.extension().and_then(|s| s.to_str()) == Some("npy") {
                if let Some(file_name) = path.file_stem().and_then(|s| s.to_str()) {
                    if file_name.starts_with("frame_") {
                        if let Ok(idx) = file_name["frame_".len()..].parse::<usize>() {
                            files.push((idx, path));
                        }
                    }
                }
            }
        }
    }
    files.sort_by_key(|&(idx, _)| idx);
    files
}

fn log_to_rerun(
    rec: &rerun::RecordingStream,
    frame: &RangeImage,
    geo: &LidarGeometry,
    res: Option<&shared::rail_detection::DetectionResult>,
    frame_idx: usize,
) -> Result<(), Box<dyn std::error::Error>> {
    rec.set_time_sequence("frame", frame_idx as i64);

    // 1. Log 3D point cloud reconstructed from range image
    let total = geo.height * geo.width;
    let mut pts = Vec::with_capacity(total);
    let mut colors = Vec::with_capacity(total);
    for row in 0..geo.height {
        let r_off = row * geo.width;
        for col in 0..geo.width {
            let r = frame.data[r_off + col];
            if r > 0.0 && r < 200.0 {
                let (x, y, z) = geo.row_col_range_to_xyz(row, col, r);
                pts.push([x, y, z]);
                let norm = (r / 200.0).clamp(0.0, 1.0);
                let c = visualizer::turbo_rgb(norm);
                colors.push(Color::from_rgb(c[0], c[1], c[2]));
            }
        }
    }
    let _ = rec.log("lidar/point_cloud", &Points3D::new(pts).with_colors(colors).with_radii([Radius::new_ui_points(1.2)]));

    // 2. Log 2D depth image
    if let Ok(depth_img) = frame.to_rerun() {
        let _ = rec.log("lidar/depth_image", &depth_img);
    }

    // 3. Log 3D tracks and extrapolation
    if let Some(r) = res {
        let center_pts: Vec<[f32; 3]> = (0..r.x_curve.len()).map(|i| [r.x_curve[i], r.y_center[i], r.z_center[i]]).collect();
        let left_pts: Vec<[f32; 3]> = (0..r.x_left.len()).map(|i| [r.x_left[i], r.y_left[i], r.z_center[i]]).collect();
        let right_pts: Vec<[f32; 3]> = (0..r.x_right.len()).map(|i| [r.x_right[i], r.y_right[i], r.z_center[i]]).collect();

        let _ = rec.log("tracks/3d/centerline", &LineStrips3D::new([center_pts]).with_colors([Color::from_rgb(0, 255, 60)]).with_radii([Radius::new_ui_points(2.5)]));
        let _ = rec.log("tracks/3d/left_rail", &LineStrips3D::new([left_pts]).with_colors([Color::from_rgb(30, 210, 255)]).with_radii([Radius::new_ui_points(2.5)]));
        let _ = rec.log("tracks/3d/right_rail", &LineStrips3D::new([right_pts]).with_colors([Color::from_rgb(255, 90, 30)]).with_radii([Radius::new_ui_points(2.5)]));

        // Sleepers
        let mut sleepers: Vec<Vec<[f32; 3]>> = Vec::new();
        for i in (0..r.x_curve.len()).step_by(4) {
            sleepers.push(vec![
                [r.x_left[i], r.y_left[i], r.z_center[i]],
                [r.x_right[i], r.y_right[i], r.z_center[i]],
            ]);
        }
        let _ = rec.log("tracks/3d/sleepers", &LineStrips3D::new(sleepers).with_colors([Color::from_rgb(180, 220, 180)]).with_radii([Radius::new_ui_points(1.2)]));

        // Extrapolation
        if !r.x_ext.is_empty() {
            let ext_c: Vec<[f32; 3]> = (0..r.x_ext.len()).map(|i| [r.x_ext[i], r.y_ext[i], r.z_ext[i]]).collect();
            let ext_l: Vec<[f32; 3]> = (0..r.x_ext_l.len()).map(|i| [r.x_ext_l[i], r.y_ext_l[i], r.z_ext[i]]).collect();
            let ext_r: Vec<[f32; 3]> = (0..r.x_ext_r.len()).map(|i| [r.x_ext_r[i], r.y_ext_r[i], r.z_ext[i]]).collect();
            let _ = rec.log("tracks/3d/extrapolation_center", &LineStrips3D::new([ext_c]).with_colors([Color::from_rgb(255, 0, 255)]).with_radii([Radius::new_ui_points(2.0)]));
            let _ = rec.log("tracks/3d/extrapolation_left", &LineStrips3D::new([ext_l]).with_colors([Color::from_rgb(200, 50, 200)]).with_radii([Radius::new_ui_points(1.5)]));
            let _ = rec.log("tracks/3d/extrapolation_right", &LineStrips3D::new([ext_r]).with_colors([Color::from_rgb(200, 50, 200)]).with_radii([Radius::new_ui_points(1.5)]));
        }

        // Raw points
        let pts_l: Vec<[f32; 3]> = r.points.iter().map(|p| [p.x_left, p.y_left, p.z_left]).collect();
        let pts_r: Vec<[f32; 3]> = r.points.iter().map(|p| [p.x_right, p.y_right, p.z_right]).collect();
        let _ = rec.log("tracks/3d/points_left", &Points3D::new(pts_l).with_colors([Color::from_rgb(0, 255, 255)]).with_radii([Radius::new_ui_points(3.0)]));
        let _ = rec.log("tracks/3d/points_right", &Points3D::new(pts_r).with_colors([Color::from_rgb(255, 120, 0)]).with_radii([Radius::new_ui_points(3.0)]));
    } else {
        let _ = rec.log("tracks/3d/centerline", &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]));
        let _ = rec.log("tracks/3d/left_rail", &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]));
        let _ = rec.log("tracks/3d/right_rail", &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]));
        let _ = rec.log("tracks/3d/sleepers", &LineStrips3D::new([] as [Vec<[f32; 3]>; 0]));
    }

    Ok(())
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let cli = Cli::parse();

    let frames_dir = find_frames_dir(&cli.frames_dir);
    println!("Looking for frames in: {:?}", frames_dir);

    let all_paths = get_frame_paths(&frames_dir);
    if all_paths.is_empty() {
        eprintln!("Error: No frame_*.npy files found in {:?}", frames_dir);
        return Ok(());
    }

    // Determine initial sample frame for geometry
    let first_frame = RangeImage::load_npy(&all_paths[0].1)?;
    let channels_str = if !first_frame.intensity.is_empty() {
        ", channels=2 (range + intensity)"
    } else {
        " (range only)"
    };
    println!(
        "Loaded range image geometry: {}x{}{}",
        first_frame.height, first_frame.width, channels_str
    );

    let out_dir = PathBuf::from(&cli.output_dir);
    let _ = std::fs::create_dir_all(&out_dir);

    // Interactive GUI mode
    if cli.interactive {
        let initial_idx = if let Some(target) = cli.frame {
            all_paths.iter().position(|&(idx, _)| idx == target).unwrap_or(0)
        } else {
            0
        };

        let app = gui::RailViewerApp::new(
            all_paths,
            initial_idx,
            cli.extrapolate_m,
            cli.smooth_n,
            cli.fps as f32,
            out_dir,
        );

        let options = eframe::NativeOptions {
            viewport: egui::ViewportBuilder::default()
                .with_inner_size([1400.0, 780.0])
                .with_min_inner_size([900.0, 500.0])
                .with_title("Rail Track Detection & Trajectory (LDT-2026 Rust)"),
            ..Default::default()
        };

        return Ok(eframe::run_native(
            "dev_pyrails_rust",
            options,
            Box::new(|_cc| Ok(Box::new(app))),
        )?);
    }

    // Filter frames to process
    let selected_frames: Vec<_> = all_paths
        .into_iter()
        .filter(|&(idx, _)| {
            if let Some(target) = cli.frame {
                idx == target
            } else if let Some(ref r) = cli.range {
                idx >= r[0] && idx <= r[1]
            } else {
                true
            }
        })
        .collect();

    if selected_frames.is_empty() {
        eprintln!("No frames matched criteria");
        return Ok(());
    }

    println!(
        "Processing {} frames (Extrapolate: +{:.0}m, Smooth N: {})...",
        selected_frames.len(),
        cli.extrapolate_m,
        cli.smooth_n
    );

    let geo = LidarGeometry::new(first_frame.height, first_frame.width, 15.0, -25.0, 40.0);
    let mut detector = RailTrackDetector::new(geo.clone());
    detector.extrapolate_m = cli.extrapolate_m;
    detector.smooth_n = cli.smooth_n;

    let visualizer = RailVisualizer::new(2, 200.0);

    let rec = if cli.rerun {
        println!("Connecting / spawning Rerun viewer...");
        let stream = RecordingStreamBuilder::new("dev_pyrails_rust")
            .spawn()
            .expect("Failed to spawn Rerun viewer");
        Some(stream)
    } else {
        None
    };

    let t0 = Instant::now();
    let is_single = cli.frame.is_some() || selected_frames.len() == 1;

    for (i, &(f_idx, ref p)) in selected_frames.iter().enumerate() {
        let frame = RangeImage::load_npy(p)?;
        let t_det_start = Instant::now();
        let res = detector.detect(&frame, f_idx);
        let t_det = t_det_start.elapsed();

        if let Some(ref r_stream) = rec {
            let _ = log_to_rerun(r_stream, &frame, &geo, res.as_ref(), f_idx);
        }

        // Save sample keyframe images or single frame
        let should_save = !cli.no_save && (is_single || (i % 25 == 0) || (i == selected_frames.len() - 1));
        if should_save {
            let composite = visualizer.render_composite(&frame, res.as_ref(), &geo);
            let img_path = out_dir.join(format!("frame_{:06}_composite.png", f_idx));
            if let Err(e) = composite.save(&img_path) {
                eprintln!("Error saving image {}: {e}", img_path.display());
            } else {
                println!("Saved composite: {}", img_path.display());
            }
        }

        if let Some(ref r) = res {
            println!(
                "Frame {:06}: {:12} | R={:5.0}m | Gauge={:5.1}cm | Offset={:+5.1}cm | Drift@15m={:+4.2}m | {} pts | det: {:.2}ms",
                f_idx,
                r.turn_direction,
                r.turn_radius,
                r.gauge * 100.0,
                r.offset_c * 100.0,
                r.lateral_shift_15m,
                r.points.len(),
                t_det.as_secs_f64() * 1000.0,
            );
        } else {
            println!("Frame {:06}: NO TRACK DETECTED                           | det: {:.2}ms", f_idx, t_det.as_secs_f64() * 1000.0);
        }
    }

    let elapsed = t0.elapsed();
    let fps_proc = selected_frames.len() as f64 / elapsed.as_secs_f64().max(1e-3);
    println!(
        "\n[DONE] Processed {} frames in {:.2}s ({:.1} FPS).",
        selected_frames.len(),
        elapsed.as_secs_f64(),
        fps_proc
    );

    Ok(())
}
