//! rail_detection.rs — Railway track detection for 3D LiDAR Range Images
//!
//! Port of Python implementation (`dev_pyrails/detector.py` and `dev_pyrails/geometry.py`).
//! Detects left/right rails from range discontinuities, verifies gauge and height consistency,
//! tracks scanline continuity, and fits 3D trajectory curves.

use crate::range_image::RangeImage;

/// 3D Geometry and Spherical Projection for Hesai Pandar128 LiDAR range images
#[derive(Clone, Debug)]
pub struct LidarGeometry {
    pub height: usize,
    pub width: usize,
    pub fov_up_rad: f32,
    pub fov_down_rad: f32,
    pub total_fov_v: f32,
    pub fov_h_rad: f32,
    pub dir_x: Vec<f32>,
    pub dir_y: Vec<f32>,
    pub dir_z: Vec<f32>,
}

impl LidarGeometry {
    pub fn new(
        height: usize,
        width: usize,
        fov_up_deg: f32,
        fov_down_deg: f32,
        fov_h_deg: f32,
    ) -> Self {
        let fov_up_rad = fov_up_deg.to_radians();
        let fov_down_rad = fov_down_deg.to_radians();
        let total_fov_v = fov_up_rad - fov_down_rad;
        let fov_h_rad = fov_h_deg.to_radians();

        // Precompute pitch for each row [0..height-1] (row 0 is up, row H-1 is down)
        let step_v_rad = 0.125_f32.to_radians();
        let mut cos_pitch = Vec::with_capacity(height);
        let mut sin_pitch = Vec::with_capacity(height);
        for row in 0..height {
            let pitch = fov_up_rad - (row as f32) * step_v_rad;
            cos_pitch.push(pitch.cos());
            sin_pitch.push(pitch.sin());
        }

        // Precompute yaw for each col [0..width-1] (col W/2 is 0 rad / straight forward)
        let width_f = width as f32;
        let mut cos_yaw = Vec::with_capacity(width);
        let mut sin_yaw = Vec::with_capacity(width);
        for col in 0..width {
            let yaw = ((col as f32) + 0.5 - width_f / 2.0) / width_f * fov_h_rad;
            cos_yaw.push(yaw.cos());
            sin_yaw.push(yaw.sin());
        }

        let total_cells = height * width;
        let mut dir_x = Vec::with_capacity(total_cells);
        let mut dir_y = Vec::with_capacity(total_cells);
        let mut dir_z = Vec::with_capacity(total_cells);

        for row in 0..height {
            let cp = cos_pitch[row];
            let sp = sin_pitch[row];
            for col in 0..width {
                dir_x.push(cp * cos_yaw[col]);
                dir_y.push(cp * sin_yaw[col]);
                dir_z.push(sp);
            }
        }

        Self {
            height,
            width,
            fov_up_rad,
            fov_down_rad,
            total_fov_v,
            fov_h_rad,
            dir_x,
            dir_y,
            dir_z,
        }
    }

    /// Converts (row, col, range) to (X, Y, Z) in meters.
    #[inline(always)]
    pub fn row_col_range_to_xyz(&self, row: usize, col: usize, r: f32) -> (f32, f32, f32) {
        let idx = row * self.width + col;
        (
            r * self.dir_x[idx],
            r * self.dir_y[idx],
            r * self.dir_z[idx],
        )
    }

    /// Converts entire range image to X, Y, Z arrays (each of length width * height).
    pub fn range_image_to_xyz(&self, frame: &RangeImage) -> (Vec<f32>, Vec<f32>, Vec<f32>) {
        let total = self.height * self.width;
        let mut x = Vec::with_capacity(total);
        let mut y = Vec::with_capacity(total);
        let mut z = Vec::with_capacity(total);

        for (i, &r) in frame.data.iter().enumerate().take(total) {
            x.push(r * self.dir_x[i]);
            y.push(r * self.dir_y[i]);
            z.push(r * self.dir_z[i]);
        }

        (x, y, z)
    }

    /// Projects 3D points (x, y, z) back onto range image (row, col).
    pub fn xyz_to_row_col(&self, x: f32, y: f32, z: f32) -> (isize, isize) {
        let r = (x * x + y * y + z * z).sqrt();
        if r < 1e-6 {
            return (-1, -1);
        }
        let pitch = (z / r).clamp(-1.0, 1.0).asin();
        let yaw = y.atan2(x);

        let row = ((self.fov_up_rad - pitch) / 0.125_f32.to_radians()).round() as isize;
        let col = ((yaw / self.fov_h_rad * (self.width as f32)) + (self.width as f32) / 2.0 - 0.5)
            .round() as isize;

        (row, col)
    }
}

/// Detected rail point pair on a single scanline
#[derive(Clone, Debug)]
pub struct RailPoint {
    pub row: usize,
    pub col_left: usize,
    pub col_right: usize,
    pub x_left: f32,
    pub y_left: f32,
    pub z_left: f32,
    pub x_right: f32,
    pub y_right: f32,
    pub z_right: f32,
    pub x_center: f32,
    pub y_center: f32,
    pub z_center: f32,
    pub gauge: f32,
}

/// Complete track detection & 3D trajectory result
#[derive(Clone, Debug)]
pub struct DetectionResult {
    pub frame_idx: usize,
    pub points: Vec<RailPoint>,
    pub gauge: f32,
    pub curvature_a: f32,
    pub heading_b: f32,
    pub offset_c: f32,
    pub turn_radius: f32,
    pub turn_direction: String, // "STRAIGHT", "CURVE LEFT", "CURVE RIGHT"
    pub lateral_shift_15m: f32,
    pub poly_y: [f32; 3], // [a, b, c] for Y(X) = a*X^2 + b*X + c
    pub poly_z: [f32; 2], // [d, e] for Z(X) = d*X + e
    // Resampled 3D curves (120 points)
    pub x_curve: Vec<f32>,
    pub y_center: Vec<f32>,
    pub z_center: Vec<f32>,
    pub x_left: Vec<f32>,
    pub y_left: Vec<f32>,
    pub x_right: Vec<f32>,
    pub y_right: Vec<f32>,
    pub confidence: f32,
}

/// Rail Track Detector for LiDAR Range Images
pub struct RailTrackDetector {
    pub geometry: LidarGeometry,
    pub nominal_gauge: f32,
    pub min_gauge: f32,
    pub max_gauge: f32,
    pub depth_step_thresh: f32,
    pub max_depth_step_thresh: f32,
    pub row_start_pct: f32,
    pub row_end_pct: f32,
    pub max_lateral_jump: f32,
    pub max_lateral_rail_jump: f32,
}

impl RailTrackDetector {
    pub fn new(geometry: LidarGeometry) -> Self {
        Self {
            geometry,
            nominal_gauge: 1.520,
            min_gauge: 1.515,
            max_gauge: 1.550,
            depth_step_thresh: 0.10,
            max_depth_step_thresh: 0.90,
            row_start_pct: 0.85,
            row_end_pct: 0.38,
            max_lateral_jump: 0.30,
            max_lateral_rail_jump: 0.10,
        }
    }

    /// Analyzes a single range frame and returns DetectionResult or None if no track is found.
    pub fn detect(&self, frame: &RangeImage, frame_idx: usize) -> Option<DetectionResult> {
        let h = frame.height;
        let w = frame.width;
        let (x_arr, y_arr, z_arr) = self.geometry.range_image_to_xyz(frame);

        let mut candidates: Vec<RailPoint> = Vec::new();
        let mut prev_y_center: Option<f32> = None;
        let mut prev_y_right: Option<f32> = None;
        let mut prev_y_left: Option<f32> = None;
        let mut prev_x_center: Option<f32> = None;

        let row_start = (h as f32 * self.row_start_pct) as usize;
        let row_end = (h as f32 * self.row_end_pct) as usize;

        // Scan rows from near (row_start) to far (row_end) with step -2
        let mut row = row_start;
        while row > row_end {
            let row_offset = row * w;
            let r_row = &frame.data[row_offset..row_offset + w];

            let mut pos_steps = Vec::new();
            let mut neg_steps = Vec::new();

            for c in 0..w - 1 {
                let diff_r = r_row[c + 1] - r_row[c];
                if diff_r > self.depth_step_thresh && diff_r <= self.max_depth_step_thresh {
                    pos_steps.push(c);
                }
                if diff_r < -self.depth_step_thresh && diff_r >= -self.max_depth_step_thresh {
                    neg_steps.push(c);
                }
            }

            let mut pairs = Vec::new();
            for &p in &pos_steps {
                for &n in &neg_steps {
                    if n > p {
                        let col_l = p;
                        let col_r = (n + 1).min(w - 1);

                        let idx_l = row_offset + col_l;
                        let idx_r = row_offset + col_r;

                        let xl = x_arr[idx_l];
                        let yl = y_arr[idx_l];
                        let zl = z_arr[idx_l];

                        let xr = x_arr[idx_r];
                        let yr = y_arr[idx_r];
                        let zr = z_arr[idx_r];

                        let dx = xr - xl;
                        let dy = yr - yl;
                        let dz = zr - zl;
                        let gauge = (dx * dx + dy * dy + dz * dz).sqrt();
                        let h_diff = dz.abs();
                        let x_diff = dx.abs();

                        let xm = 0.5 * (xl + xr);
                        let ym = 0.5 * (yl + yr);
                        let zm = 0.5 * (zl + zr);

                        // Исключаем точки выше уровня земли (провода контактной сети и т.п.)
                        if zm > -0.5 {
                            continue;
                        }

                        // Адаптивные к дальности допуски: с ростом глубины (xm) шаг лучей лидара
                        // в метрах увеличивается, а кривизна пути создает естественный сдвиг по X между рельсами.
                        let tol_gauge = (0.04 + 0.0018 * xm).min(0.08);
                        let h_tol = (0.05 + 0.0025 * xm).min(0.18);
                        let x_tol = (0.35 + 0.035 * xm).min(2.0);

                        if gauge >= self.nominal_gauge - tol_gauge
                            && gauge <= self.nominal_gauge + tol_gauge
                            && h_diff < h_tol
                            && x_diff < x_tol
                        {
                            if let Some(pxc) = prev_x_center {
                                if xm < pxc - 0.5 {
                                    continue;
                                }
                            }

                            pairs.push(RailPoint {
                                row,
                                col_left: col_l,
                                col_right: col_r,
                                x_left: xl,
                                y_left: yl,
                                z_left: zl,
                                x_right: xr,
                                y_right: yr,
                                z_right: zr,
                                x_center: xm,
                                y_center: ym,
                                z_center: zm,
                                gauge,
                            });
                        }
                    }
                }
            }

            if pairs.is_empty() {
                if row < 2 {
                    break;
                }
                row -= 2;
                continue;
            }

            // Prioritize continuity from previous scanline
            if let (Some(pyc), Some(pyl), Some(pyr)) = (prev_y_center, prev_y_left, prev_y_right) {
                pairs.sort_by(|a, b| {
                    let cost_a = (
                        (a.y_center - pyc).abs(),
                        (a.y_right - pyr).abs(),
                        (a.y_left - pyl).abs(),
                    );
                    let cost_b = (
                        (b.y_center - pyc).abs(),
                        (b.y_right - pyr).abs(),
                        (b.y_left - pyl).abs(),
                    );
                    cost_a
                        .0
                        .partial_cmp(&cost_b.0)
                        .unwrap_or(std::cmp::Ordering::Equal)
                        .then_with(|| {
                            cost_a
                                .1
                                .partial_cmp(&cost_b.1)
                                .unwrap_or(std::cmp::Ordering::Equal)
                        })
                        .then_with(|| {
                            cost_a
                                .2
                                .partial_cmp(&cost_b.2)
                                .unwrap_or(std::cmp::Ordering::Equal)
                        })
                });
            } else {
                pairs.sort_by(|a, b| {
                    let cost_a = (
                        (a.gauge - self.nominal_gauge).abs(),
                        (a.x_right - a.x_left).abs(),
                        (a.z_left - a.z_right).abs(),
                    );
                    let cost_b = (
                        (b.gauge - self.nominal_gauge).abs(),
                        (b.x_right - b.x_left).abs(),
                        (b.z_left - b.z_right).abs(),
                    );
                    cost_a
                        .0
                        .partial_cmp(&cost_b.0)
                        .unwrap_or(std::cmp::Ordering::Equal)
                        .then_with(|| {
                            cost_a
                                .1
                                .partial_cmp(&cost_b.1)
                                .unwrap_or(std::cmp::Ordering::Equal)
                        })
                        .then_with(|| {
                            cost_a
                                .2
                                .partial_cmp(&cost_b.2)
                                .unwrap_or(std::cmp::Ordering::Equal)
                        })
                });
            }

            let best = &pairs[0];

            let lateral_jump = if let Some(pyc) = prev_y_center {
                (best.y_center - pyc).abs()
            } else {
                best.y_center.abs()
            };

            let max_lat = (self.max_lateral_jump + 0.005 * best.x_center).min(0.55);
            let max_lat_rail = (self.max_lateral_rail_jump + 0.004 * best.x_center).min(0.35);

            // Reject sudden lateral discontinuity of center
            if prev_y_center.is_some() && lateral_jump > max_lat {
                if row < 2 {
                    break;
                }
                row -= 2;
                continue;
            }

            // Reject sudden lateral discontinuity of left rail
            if let Some(pyl) = prev_y_left {
                let left_lateral_jump = (best.y_left - pyl).abs();
                if left_lateral_jump > max_lat_rail {
                    if row < 2 {
                        break;
                    }
                    row -= 2;
                    continue;
                }
            }

            // Reject sudden lateral discontinuity of right rail
            if let Some(pyr) = prev_y_right {
                let right_lateral_jump = (best.y_right - pyr).abs();
                if right_lateral_jump > max_lat_rail {
                    if row < 2 {
                        break;
                    }
                    row -= 2;
                    continue;
                }
            }

            prev_x_center = Some(best.x_center);
            prev_y_center = Some(best.y_center);
            prev_y_left = Some(best.y_left);
            prev_y_right = Some(best.y_right);

            candidates.push(best.clone());

            if row < 2 {
                break;
            }
            row -= 2;
        }

        // Require a minimum number of valid scanlines
        if candidates.len() < 6 {
            return None;
        }

        // Extract coordinate arrays
        let xm: Vec<f32> = candidates.iter().map(|pt| pt.x_center).collect();
        let ym: Vec<f32> = candidates.iter().map(|pt| pt.y_center).collect();
        let zm: Vec<f32> = candidates.iter().map(|pt| pt.z_center).collect();
        let mut gauges: Vec<f32> = candidates.iter().map(|pt| pt.gauge).collect();
        gauges.sort_by(|a, b| a.partial_cmp(b).unwrap_or(std::cmp::Ordering::Equal));
        let median_gauge = if gauges.len() % 2 == 1 {
            gauges[gauges.len() / 2]
        } else {
            0.5 * (gauges[gauges.len() / 2 - 1] + gauges[gauges.len() / 2])
        };

        // Fit quadratic curve for centerline: Y(X) = a*X^2 + b*X + c
        let poly_y = polyfit2(&xm, &ym)?;
        // Fit elevation profile: Z(X) = d*X + e
        let poly_z = polyfit1(&xm, &zm)?;

        let [a, b, c] = poly_y;
        let [d, e] = poly_z;

        // Radius of curvature: R = 1 / (2 * |a|)
        let turn_radius = if a.abs() > 1e-6 {
            1.0 / (2.0 * a.abs())
        } else {
            99999.0
        };
        let lateral_shift_15m = a * (15.0 * 15.0) + b * 15.0;

        let turn_direction = if lateral_shift_15m.abs() < 0.20 && a.abs() < 0.0003 {
            "STRAIGHT".to_string()
        } else if lateral_shift_15m < 0.0 || a < 0.0 {
            "CURVE LEFT".to_string()
        } else {
            "CURVE RIGHT".to_string()
        };

        // Resample fine curve points in 3D (150 points across full detected depth)
        let xm_min = xm.iter().cloned().fold(f32::INFINITY, f32::min);
        let xm_max = xm.iter().cloned().fold(f32::NEG_INFINITY, f32::max);
        let x_min = 3.5_f32.max(xm_min);
        let x_max = (xm_max + 2.0).max(35.0);

        let n_resample = 150;
        let mut x_curve = Vec::with_capacity(n_resample);
        let mut y_center = Vec::with_capacity(n_resample);
        let mut z_center = Vec::with_capacity(n_resample);
        let mut x_left = Vec::with_capacity(n_resample);
        let mut y_left = Vec::with_capacity(n_resample);
        let mut x_right = Vec::with_capacity(n_resample);
        let mut y_right = Vec::with_capacity(n_resample);

        let half_w = 0.5 * median_gauge;

        for i in 0..n_resample {
            let t = (i as f32) / ((n_resample - 1) as f32);
            let xc = x_min + t * (x_max - x_min);
            let yc = a * xc * xc + b * xc + c;
            let zc = d * xc + e;

            let dy_dx = 2.0 * a * xc + b;
            let theta = dy_dx.atan();

            let sin_t = theta.sin();
            let cos_t = theta.cos();

            x_curve.push(xc);
            y_center.push(yc);
            z_center.push(zc);

            x_left.push(xc + half_w * sin_t);
            y_left.push(yc - half_w * cos_t);

            x_right.push(xc - half_w * sin_t);
            y_right.push(yc + half_w * cos_t);
        }

        let total_checked_rows = (row_start.abs_diff(row_end) + 1) as f32;
        let confidence = (candidates.len() as f32 / total_checked_rows).min(1.0);

        Some(DetectionResult {
            frame_idx,
            points: candidates,
            gauge: median_gauge,
            curvature_a: a,
            heading_b: b,
            offset_c: c,
            turn_radius,
            turn_direction,
            lateral_shift_15m,
            poly_y,
            poly_z,
            x_curve,
            y_center,
            z_center,
            x_left,
            y_left,
            x_right,
            y_right,
            confidence,
        })
    }
}

/// Least-squares quadratic polynomial fitting: Y(X) = a*X^2 + b*X + c
/// Solves normal equations (A^T A) * beta = A^T Y via Cramer's rule.
pub fn polyfit2(x: &[f32], y: &[f32]) -> Option<[f32; 3]> {
    let n = x.len();
    if n < 3 || n != y.len() {
        return None;
    }

    let n_f = n as f64;
    let mut s1 = 0.0_f64;
    let mut s2 = 0.0_f64;
    let mut s3 = 0.0_f64;
    let mut s4 = 0.0_f64;

    let mut r0 = 0.0_f64;
    let mut r1 = 0.0_f64;
    let mut r2 = 0.0_f64;

    for i in 0..n {
        let xi = x[i] as f64;
        let yi = y[i] as f64;
        let xi2 = xi * xi;
        let xi3 = xi2 * xi;
        let xi4 = xi2 * xi2;

        s1 += xi;
        s2 += xi2;
        s3 += xi3;
        s4 += xi4;

        r0 += yi;
        r1 += xi * yi;
        r2 += xi2 * yi;
    }

    // Matrix:
    // [s4, s3, s2] [a]   [r2]
    // [s3, s2, s1] [b] = [r1]
    // [s2, s1, n ] [c]   [r0]
    let det = s4 * (s2 * n_f - s1 * s1) - s3 * (s3 * n_f - s1 * s2) + s2 * (s3 * s1 - s2 * s2);

    if det.abs() < 1e-12 {
        return None;
    }

    let det_a = r2 * (s2 * n_f - s1 * s1) - s3 * (r1 * n_f - s1 * r0) + s2 * (r1 * s1 - s2 * r0);
    let det_b = s4 * (r1 * n_f - s1 * r0) - r2 * (s3 * n_f - s1 * s2) + s2 * (s3 * r0 - r1 * s2);
    let det_c = s4 * (s2 * r0 - r1 * s1) - s3 * (s3 * r0 - r1 * s2) + r2 * (s3 * s1 - s2 * s2);

    Some([
        (det_a / det) as f32,
        (det_b / det) as f32,
        (det_c / det) as f32,
    ])
}

/// Least-squares linear polynomial fitting: Z(X) = d*X + e
/// Solves normal equations for degree 1.
pub fn polyfit1(x: &[f32], z: &[f32]) -> Option<[f32; 2]> {
    let n = x.len();
    if n < 2 || n != z.len() {
        return None;
    }

    let n_f = n as f64;
    let mut sum_x = 0.0_f64;
    let mut sum_x2 = 0.0_f64;
    let mut sum_z = 0.0_f64;
    let mut sum_xz = 0.0_f64;

    for i in 0..n {
        let xi = x[i] as f64;
        let zi = z[i] as f64;
        sum_x += xi;
        sum_x2 += xi * xi;
        sum_z += zi;
        sum_xz += xi * zi;
    }

    let det = n_f * sum_x2 - sum_x * sum_x;
    if det.abs() < 1e-12 {
        return None;
    }

    let d = (n_f * sum_xz - sum_x * sum_z) / det;
    let e = (sum_x2 * sum_z - sum_x * sum_xz) / det;

    Some([d as f32, e as f32])
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_polyfit2_exact() {
        // y = 2*x^2 - 3*x + 5
        let x = vec![1.0, 2.0, 3.0, 4.0, 5.0];
        let y: Vec<f32> = x.iter().map(|&xi| 2.0 * xi * xi - 3.0 * xi + 5.0).collect();
        let res = polyfit2(&x, &y).expect("fit failed");
        assert!((res[0] - 2.0).abs() < 1e-4);
        assert!((res[1] - (-3.0)).abs() < 1e-4);
        assert!((res[2] - 5.0).abs() < 1e-4);
    }

    #[test]
    fn test_frame_000001_detection() {
        let candidates = [
            "frames/frame_000001.npy",
            "../frames/frame_000001.npy",
            "../../frames/frame_000001.npy",
        ];
        let frame_path = candidates.iter().find(|p| std::path::Path::new(p).exists());
        if let Some(&path) = frame_path {
            let frame = RangeImage::load_npy(path).expect("Failed to load frame");
            assert_eq!(frame.height, 321);
            assert_eq!(frame.width, 400);

            let geo = LidarGeometry::new(frame.height, frame.width, 15.0, -25.0, 40.0);
            let detector = RailTrackDetector::new(geo);
            let res = detector.detect(&frame, 1).expect("Detection failed");

            assert_eq!(res.points.len(), 31, "Points count mismatch");
            assert!(
                (res.gauge - 1.5278).abs() < 0.005,
                "Gauge mismatch: {}",
                res.gauge
            );
            assert_eq!(res.turn_direction, "STRAIGHT");
            println!(
                "Rust Detector: Gauge={:.4}, Radius={:.1}, Points={}, Dir={}",
                res.gauge,
                res.turn_radius,
                res.points.len(),
                res.turn_direction
            );
        }
    }
}
