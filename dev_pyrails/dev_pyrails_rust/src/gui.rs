//! gui.rs — Interactive egui / eframe GUI for Rail Track Detection
//!
//! Replicates Python OpenCV interactive GUI:
//! - Frame slider / scrubber with playback (Play / Pause, Space)
//! - Next / Prev frame stepping (D / A, Right / Left)
//! - Save Screenshot (S key)
//! - Real-time tunable parameters (FPS, extrapolation distance, smoothing N)
//! - Interactive viewport showing composite [ Range View | BEV | HUD ]

use std::path::PathBuf;
use std::time::{Duration, Instant};

use eframe::egui::{self, ColorImage, Key, TextureHandle, TextureOptions};
use shared::rail_detection::{LidarGeometry, RailTrackDetector};
use shared::range_image::RangeImage;

use crate::visualizer::RailVisualizer;

pub struct RailViewerApp {
    frame_paths: Vec<(usize, PathBuf)>,
    current_idx: usize,
    is_playing: bool,
    fps: f32,
    extrapolate_m: f32,
    smooth_n: usize,
    last_frame_time: Instant,
    output_dir: PathBuf,
    status_msg: String,
    status_time: Instant,

    detector: RailTrackDetector,
    visualizer: RailVisualizer,
    texture: Option<TextureHandle>,
    last_rendered_idx: Option<usize>,
    last_rendered_params: (f32, usize),
}

impl RailViewerApp {
    pub fn new(
        frame_paths: Vec<(usize, PathBuf)>,
        initial_frame_idx: usize,
        extrapolate_m: f32,
        smooth_n: usize,
        fps: f32,
        output_dir: PathBuf,
    ) -> Self {
        let first_path = &frame_paths[0].1;
        let sample = RangeImage::load_npy(first_path).expect("Failed to load sample frame");
        let geo = LidarGeometry::new(sample.height, sample.width, 15.0, -25.0, 40.0);
        let mut detector = RailTrackDetector::new(geo);
        detector.extrapolate_m = extrapolate_m;
        detector.smooth_n = smooth_n;

        let visualizer = RailVisualizer::new(2, 200.0);

        let current_idx = initial_frame_idx.min(frame_paths.len().saturating_sub(1));

        Self {
            frame_paths,
            current_idx,
            is_playing: false,
            fps,
            extrapolate_m,
            smooth_n,
            last_frame_time: Instant::now(),
            output_dir,
            status_msg: "Ready. Press Space to Play, S to Save screenshot.".to_string(),
            status_time: Instant::now(),
            detector,
            visualizer,
            texture: None,
            last_rendered_idx: None,
            last_rendered_params: (extrapolate_m, smooth_n),
        }
    }

    fn update_texture(&mut self, ctx: &egui::Context) {
        let (f_idx, ref path) = self.frame_paths[self.current_idx];
        let Ok(frame) = RangeImage::load_npy(path) else {
            return;
        };

        self.detector.extrapolate_m = self.extrapolate_m;
        self.detector.smooth_n = self.smooth_n;

        let res = self.detector.detect(&frame, f_idx);
        let composite = self.visualizer.render_composite(&frame, res.as_ref(), &self.detector.geometry);

        let w = composite.width() as usize;
        let h = composite.height() as usize;
        let color_img = ColorImage::from_rgb([w, h], composite.as_raw());

        self.texture = Some(ctx.load_texture("composite_view", color_img, TextureOptions::LINEAR));
        self.last_rendered_idx = Some(self.current_idx);
        self.last_rendered_params = (self.extrapolate_m, self.smooth_n);
    }

    fn save_current_screenshot(&mut self) {
        let (f_idx, ref path) = self.frame_paths[self.current_idx];
        if let Ok(frame) = RangeImage::load_npy(path) {
            let res = self.detector.detect(&frame, f_idx);
            let composite = self.visualizer.render_composite(&frame, res.as_ref(), &self.detector.geometry);
            let _ = std::fs::create_dir_all(&self.output_dir);
            let out_path = self.output_dir.join(format!("screenshot_{:06}.png", f_idx));
            if let Err(e) = composite.save(&out_path) {
                self.status_msg = format!("Error saving screenshot: {e}");
            } else {
                self.status_msg = format!("Saved screenshot: {}", out_path.display());
            }
            self.status_time = Instant::now();
        }
    }
}

impl eframe::App for RailViewerApp {
    fn ui(&mut self, ui: &mut egui::Ui, _frame: &mut eframe::Frame) {
        let ctx = ui.ctx().clone();

        // Handle keyboard shortcuts
        ctx.input(|i| {
            if i.key_pressed(Key::Space) {
                self.is_playing = !self.is_playing;
            }
            if i.key_pressed(Key::D) || i.key_pressed(Key::ArrowRight) {
                if !self.frame_paths.is_empty() {
                    self.current_idx = (self.current_idx + 1) % self.frame_paths.len();
                    self.detector.reset();
                }
            }
            if i.key_pressed(Key::A) || i.key_pressed(Key::ArrowLeft) {
                if !self.frame_paths.is_empty() {
                    self.current_idx = (self.current_idx + self.frame_paths.len() - 1) % self.frame_paths.len();
                    self.detector.reset();
                }
            }
            if i.key_pressed(Key::S) {
                self.save_current_screenshot();
            }
        });

        // Handle playback timer
        if self.is_playing {
            let frame_dur = Duration::from_secs_f32(1.0 / self.fps.max(1.0));
            if self.last_frame_time.elapsed() >= frame_dur {
                self.current_idx = (self.current_idx + 1) % self.frame_paths.len();
                self.last_frame_time = Instant::now();
            }
            ctx.request_repaint();
        }

        // Check if texture needs refresh
        let params_changed = self.last_rendered_params != (self.extrapolate_m, self.smooth_n);
        if self.last_rendered_idx != Some(self.current_idx) || params_changed {
            self.update_texture(&ctx);
        }

        // 1. Controls Top Area
        ui.add_space(4.0);
        ui.horizontal(|ui| {
            let play_btn_text = if self.is_playing { "⏸ Pause" } else { "▶ Play" };
            if ui.button(play_btn_text).clicked() {
                self.is_playing = !self.is_playing;
            }

            if ui.button("⏮ Prev").clicked() {
                if !self.frame_paths.is_empty() {
                    self.current_idx = (self.current_idx + self.frame_paths.len() - 1) % self.frame_paths.len();
                    self.detector.reset();
                }
            }

            if ui.button("Next ⏭").clicked() {
                if !self.frame_paths.is_empty() {
                    self.current_idx = (self.current_idx + 1) % self.frame_paths.len();
                    self.detector.reset();
                }
            }

            ui.separator();

            let cur_frame_num = self.frame_paths.get(self.current_idx).map(|p| p.0).unwrap_or(0);
            ui.label(format!("Frame {:06} ({}/{})", cur_frame_num, self.current_idx + 1, self.frame_paths.len()));

            let max_frames = self.frame_paths.len().saturating_sub(1);
            let mut slider_val = self.current_idx;
            if ui.add(egui::Slider::new(&mut slider_val, 0..=max_frames).show_value(false)).changed() {
                self.current_idx = slider_val;
                self.detector.reset();
            }

            ui.separator();

            ui.add(egui::Slider::new(&mut self.fps, 1.0..=60.0).text("FPS"));
            ui.add(egui::Slider::new(&mut self.extrapolate_m, 0.0..=50.0).text("Extrap (m)"));
            ui.add(egui::Slider::new(&mut self.smooth_n, 1..=15).text("Smooth N"));

            ui.separator();

            if ui.button("📷 Save Screenshot [S]").clicked() {
                self.save_current_screenshot();
            }
        });

        ui.add_space(2.0);
        ui.horizontal(|ui| {
            ui.label("Shortcuts: [Space] Play/Pause | [D/->] Next | [A/<-] Prev | [S] Screenshot");
            ui.with_layout(egui::Layout::right_to_left(egui::Align::Center), |ui| {
                if self.status_time.elapsed() < Duration::from_secs(4) {
                    ui.colored_label(egui::Color32::from_rgb(0, 220, 100), &self.status_msg);
                }
            });
        });
        ui.separator();

        // 2. Viewport Area
        if let Some(ref tex) = self.texture {
            let avail_size = ui.available_size();
            let aspect = tex.size()[0] as f32 / tex.size()[1] as f32;
            let mut fit_w = avail_size.x;
            let mut fit_h = fit_w / aspect;

            if fit_h > avail_size.y {
                fit_h = avail_size.y;
                fit_w = fit_h * aspect;
            }

            ui.centered_and_justified(|ui| {
                ui.image(egui::load::SizedTexture::new(tex.id(), egui::vec2(fit_w, fit_h)));
            });
        } else {
            ui.centered_and_justified(|ui| {
                ui.label("Loading frame...");
            });
        }
    }
}
