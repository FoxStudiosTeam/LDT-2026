//! rail_detector.rs — Rust Railway Track Detector & Rerun Viewer
//!
//! Processes range image frames (e.g. `frames/frame_*.npy`) using Rust RailTrackDetector,
//! achieves identical behavior to Python `dev_pyrails`, and logs 3D rails, corridor,
//! points, and telemetry to Rerun.
//!
//! Usage:
//!   cargo run --bin rail_detector -- --frame 1
//!   cargo run --bin rail_detector -- --range 1 50
//!   cargo run --bin rail_detector

use std::path::{Path, PathBuf};
use std::time::{Duration, Instant};

use rerun::RecordingStreamBuilder;
use rust_listener::debug::helper::DebugStream;
use shared::rail_detection::{LidarGeometry, RailTrackDetector};
use shared::range_image::RangeImage;

fn get_frame_paths(frames_dir: &Path) -> Vec<(usize, PathBuf)> {
    let mut files = Vec::new();
    if let Ok(entries) = std::fs::read_dir(frames_dir) {
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

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<String> = std::env::args().collect();

    let mut frames_dir = PathBuf::from("frames");
    if !frames_dir.exists() && Path::new("../frames").exists() {
        frames_dir = PathBuf::from("../frames");
    }

    let mut target_frame: Option<usize> = None;
    let mut range_start: Option<usize> = None;
    let mut range_end: Option<usize> = None;
    let mut fps: f64 = 30.0;
    let mut no_sleep = false;
    let mut max_dist_m: f32 = 250.0;
    let mut row_end_pct: f32 = 0.38;

    let mut i = 1;
    while i < args.len() {
        match args[i].as_str() {
            "--frames-dir" if i + 1 < args.len() => {
                frames_dir = PathBuf::from(&args[i + 1]);
                i += 2;
            }
            "--frame" if i + 1 < args.len() => {
                target_frame = args[i + 1].parse().ok();
                i += 2;
            }
            "--range" if i + 2 < args.len() => {
                range_start = args[i + 1].parse().ok();
                range_end = args[i + 2].parse().ok();
                i += 3;
            }
            "--fps" if i + 1 < args.len() => {
                fps = args[i + 1].parse().unwrap_or(30.0);
                i += 2;
            }
            "--max-dist" if i + 1 < args.len() => {
                max_dist_m = args[i + 1].parse().unwrap_or(250.0);
                i += 2;
            }
            "--row-end-pct" if i + 1 < args.len() => {
                row_end_pct = args[i + 1].parse().unwrap_or(0.38);
                i += 2;
            }
            "--no-sleep" => {
                no_sleep = true;
                i += 1;
            }
            _ => {
                i += 1;
            }
        }
    }

    let all_frames = get_frame_paths(&frames_dir);
    if all_frames.is_empty() {
        eprintln!("Error: No frame_*.npy files found in {:?}", frames_dir);
        return Ok(());
    }

    let selected_frames: Vec<_> = all_frames
        .into_iter()
        .filter(|&(idx, _)| {
            if let Some(single) = target_frame {
                idx == single
            } else if let (Some(s), Some(e)) = (range_start, range_end) {
                idx >= s && idx <= e
            } else {
                true
            }
        })
        .collect();

    if selected_frames.is_empty() {
        eprintln!("No frames matched criteria");
        return Ok(());
    }

    println!("============================================================");
    println!("  Rust Rail Track Detector & Rerun Streamer");
    println!("============================================================");
    println!("Frames found:   {}", selected_frames.len());
    println!("Frames source:  {:?}", frames_dir);

    // Initialize Rerun stream
    let rerun_url =
        std::env::var("RERUN_URL").unwrap_or_else(|_| rust_listener::ENV.RERUN_URL.clone());
    println!("Connecting to Rerun at: {}", rerun_url);
    let rec = RecordingStreamBuilder::new("rail_detector")
        .connect_grpc_opts(rerun_url)
        .unwrap_or_else(|e| {
            println!(
                "Could not connect to remote Rerun ({}), spawning local viewer...",
                e
            );
            RecordingStreamBuilder::new("rail_detector")
                .spawn()
                .expect("Failed to spawn Rerun viewer")
        });

    println!("Streaming detection results to Rerun...");
    println!("------------------------------------------------------------");

    // Load first frame to setup geometry
    let first_frame = RangeImage::load_npy(&selected_frames[0].1)?;
    let geo = LidarGeometry::new(first_frame.height, first_frame.width, 15.0, -25.0, 40.0);
    let mut detector = RailTrackDetector::new(geo.clone());
    detector.row_end_pct = row_end_pct;

    println!("Max preview depth: {:.1} m (full depth enabled)", max_dist_m);
    println!("Detector end row:  {:.1}% (extended depth scanning)", detector.row_end_pct * 100.0);

    let delay_per_frame = if no_sleep || fps <= 0.0 {
        Duration::ZERO
    } else {
        Duration::from_secs_f64(1.0 / fps)
    };

    let start_all = Instant::now();
    let mut detected_count = 0;

    for &(idx, ref path) in &selected_frames {
        let t0 = Instant::now();
        let frame = RangeImage::load_npy(path)?;
        let t_load = t0.elapsed();

        let t_det_start = Instant::now();
        let res = detector.detect(&frame, idx);
        let t_det = t_det_start.elapsed();

        // 1. Time indexing in Rerun
        rec.set_time_sequence("frame", idx as i64);

        // 2. Log 3D point cloud reconstructed from range image with full depth
        rec.log_range_image_3d_dist(&frame, &geo, max_dist_m)?;

        // 3. Log 2D depth image
        if let Ok(depth_img) = frame.to_rerun() {
            let _ = rec.log("depth_image", &depth_img);
        }

        // 4. Log 3D tracks (centerline, left/right rails, sleepers, points)
        rec.log_rail_detection(res.as_ref())?;

        // 5. Console telemetry
        if let Some(ref r) = res {
            detected_count += 1;
            println!(
                "Frame {:06}: {:12} | R={:5.0}m | Gauge={:5.1}cm | Offset={:+5.1}cm | {} pts | det: {:?} (load: {:?})",
                idx,
                r.turn_direction,
                r.turn_radius,
                r.gauge * 100.0,
                r.offset_c * 100.0,
                r.points.len(),
                t_det,
                t_load,
            );
        } else {
            println!(
                "Frame {:06}: NO TRACK DETECTED                           | det: {:?}",
                idx, t_det
            );
        }

        if !delay_per_frame.is_zero() {
            let elapsed_frame = t0.elapsed();
            if elapsed_frame < delay_per_frame {
                tokio::time::sleep(delay_per_frame - elapsed_frame).await;
            }
        }
    }

    let total_time = start_all.elapsed();
    let proc_fps = selected_frames.len() as f64 / total_time.as_secs_f64().max(1e-3);

    println!("------------------------------------------------------------");
    println!(
        "[DONE] Processed {} frames in {:.2}s ({:.1} FPS). Detected tracks: {}/{}",
        selected_frames.len(),
        total_time.as_secs_f64(),
        proc_fps,
        detected_count,
        selected_frames.len()
    );
    println!("============================================================");

    Ok(())
}
