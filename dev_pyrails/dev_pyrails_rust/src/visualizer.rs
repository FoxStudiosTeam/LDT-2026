//! visualizer.rs — Multi-panel visualizer and composite image renderer
//!
//! Replicates Python `dev_pyrails/visualizer.py`:
//! 1. Perspective Range Image with Turbo colormap, driveable corridor, rails, and extrapolation.
//! 2. Top-down Bird's Eye View (BEV) with distance/lateral guidelines, vehicle icon, rails, corridor.
//! 3. Telemetry HUD card (Turn direction, radius, heading, gauge, offset, confidence, intensity).
//! 4. Horizontal composite layout [ Range View | BEV | HUD ] exportable as PNG.

use image::{Rgb, RgbImage};
use shared::rail_detection::{DetectionResult, LidarGeometry};
use shared::range_image::RangeImage;

/// Google Turbo Colormap polynomial approximation
#[inline(always)]
pub fn turbo_rgb(x: f32) -> [u8; 3] {
    let x = x.clamp(0.0, 1.0);
    let r = 0.13572138 + x * (4.61539260 + x * (-42.66032258 + x * (132.13108234 + x * (-152.94239396 + x * 59.28637943))));
    let g = 0.09140261 + x * (2.19418839 + x * (4.84296658 + x * (-14.18503333 + x * (4.27729857 + x * 2.82956604))));
    let b = 0.10667330 + x * (12.64194608 + x * (-60.58204836 + x * (110.36276771 + x * (-89.90310912 + x * 27.34824973))));
    [
        (r.clamp(0.0, 1.0) * 255.0).round() as u8,
        (g.clamp(0.0, 1.0) * 255.0).round() as u8,
        (b.clamp(0.0, 1.0) * 255.0).round() as u8,
    ]
}

// ---------------------------------------------------------------------------
// Basic Drawing Primitives on RgbImage
// ---------------------------------------------------------------------------

#[inline]
pub fn put_pixel_safe(img: &mut RgbImage, x: i32, y: i32, color: Rgb<u8>) {
    if x >= 0 && y >= 0 && (x as u32) < img.width() && (y as u32) < img.height() {
        img.put_pixel(x as u32, y as u32, color);
    }
}

pub fn draw_line(
    img: &mut RgbImage,
    mut x0: i32,
    mut y0: i32,
    x1: i32,
    y1: i32,
    color: Rgb<u8>,
    thickness: i32,
) {
    let dx = (x1 - x0).abs();
    let dy = (y1 - y0).abs();
    let sx = if x0 < x1 { 1 } else { -1 };
    let sy = if y0 < y1 { 1 } else { -1 };
    let mut err = dx - dy;

    let half = thickness / 2;

    loop {
        for tx in -half..=half {
            for ty in -half..=half {
                if tx * tx + ty * ty <= half * half + 1 {
                    put_pixel_safe(img, x0 + tx, y0 + ty, color);
                }
            }
        }

        if x0 == x1 && y0 == y1 {
            break;
        }
        let e2 = 2 * err;
        if e2 > -dy {
            err -= dy;
            x0 += sx;
        }
        if e2 < dx {
            err += dx;
            y0 += sy;
        }
    }
}

pub fn draw_polyline(
    img: &mut RgbImage,
    pts: &[[i32; 2]],
    color: Rgb<u8>,
    thickness: i32,
) {
    if pts.len() < 2 {
        return;
    }
    for i in 0..pts.len() - 1 {
        draw_line(img, pts[i][0], pts[i][1], pts[i + 1][0], pts[i + 1][1], color, thickness);
    }
}

pub fn draw_dashed_polyline(
    img: &mut RgbImage,
    pts: &[[i32; 2]],
    color: Rgb<u8>,
    thickness: i32,
    dash_step: usize,
) {
    if pts.len() < 2 {
        return;
    }
    let mut i = 0;
    while i < pts.len() - 1 {
        let i_end = (i + (dash_step / 2).max(1) + 1).min(pts.len());
        for j in i..i_end - 1 {
            draw_line(img, pts[j][0], pts[j][1], pts[j + 1][0], pts[j + 1][1], color, thickness);
        }
        i += dash_step.max(2);
    }
}

pub fn draw_filled_circle(img: &mut RgbImage, cx: i32, cy: i32, r: i32, color: Rgb<u8>) {
    for dy in -r..=r {
        for dx in -r..=r {
            if dx * dx + dy * dy <= r * r {
                put_pixel_safe(img, cx + dx, cy + dy, color);
            }
        }
    }
}

#[allow(dead_code)]
pub fn draw_rect(img: &mut RgbImage, x0: i32, y0: i32, x1: i32, y1: i32, color: Rgb<u8>) {
    for x in x0..=x1 {
        put_pixel_safe(img, x, y0, color);
        put_pixel_safe(img, x, y1, color);
    }
    for y in y0..=y1 {
        put_pixel_safe(img, x0, y, color);
        put_pixel_safe(img, x1, y, color);
    }
}

pub fn draw_filled_rect(img: &mut RgbImage, x0: i32, y0: i32, x1: i32, y1: i32, color: Rgb<u8>) {
    let min_x = x0.max(0);
    let max_x = x1.min(img.width() as i32 - 1);
    let min_y = y0.max(0);
    let max_y = y1.min(img.height() as i32 - 1);
    for y in min_y..=max_y {
        for x in min_x..=max_x {
            img.put_pixel(x as u32, y as u32, color);
        }
    }
}

/// Simple scanline polygon fill with alpha blending
pub fn draw_filled_polygon_alpha(
    img: &mut RgbImage,
    pts: &[[i32; 2]],
    color: Rgb<u8>,
    alpha: f32,
) {
    if pts.len() < 3 {
        return;
    }

    let min_y = pts.iter().map(|p| p[1]).min().unwrap().max(0);
    let max_y = pts.iter().map(|p| p[1]).max().unwrap().min(img.height() as i32 - 1);

    let inv_alpha = 1.0 - alpha;
    let cr = color[0] as f32 * alpha;
    let cg = color[1] as f32 * alpha;
    let cb = color[2] as f32 * alpha;

    for y in min_y..=max_y {
        let mut nodes = Vec::new();
        let mut j = pts.len() - 1;
        for i in 0..pts.len() {
            let (xi, yi) = (pts[i][0], pts[i][1]);
            let (xj, yj) = (pts[j][0], pts[j][1]);
            if (yi < y && yj >= y) || (yj < y && yi >= y) {
                let x = xi + ((y - yi) as f64 / (yj - yi) as f64 * (xj - xi) as f64).round() as i32;
                nodes.push(x);
            }
            j = i;
        }

        nodes.sort_unstable();

        let mut k = 0;
        while k + 1 < nodes.len() {
            let x_start = nodes[k].max(0);
            let x_end = nodes[k + 1].min(img.width() as i32 - 1);
            for x in x_start..=x_end {
                let p = img.get_pixel_mut(x as u32, y as u32);
                p[0] = (cr + p[0] as f32 * inv_alpha).min(255.0) as u8;
                p[1] = (cg + p[1] as f32 * inv_alpha).min(255.0) as u8;
                p[2] = (cb + p[2] as f32 * inv_alpha).min(255.0) as u8;
            }
            k += 2;
        }
    }
}

// ---------------------------------------------------------------------------
// 5x7 Minimal Builtin Bitmap Font
// ---------------------------------------------------------------------------

// 5 columns x 7 rows bitmask for characters
fn get_char_bitmap(c: char) -> [u8; 5] {
    match c {
        '0' => [0x3E, 0x51, 0x49, 0x45, 0x3E],
        '1' => [0x00, 0x42, 0x7F, 0x40, 0x00],
        '2' => [0x42, 0x61, 0x51, 0x49, 0x46],
        '3' => [0x21, 0x41, 0x45, 0x4B, 0x31],
        '4' => [0x18, 0x14, 0x12, 0x7F, 0x10],
        '5' => [0x27, 0x45, 0x45, 0x45, 0x39],
        '6' => [0x3C, 0x4A, 0x49, 0x49, 0x30],
        '7' => [0x01, 0x71, 0x09, 0x05, 0x03],
        '8' => [0x36, 0x49, 0x49, 0x49, 0x36],
        '9' => [0x06, 0x49, 0x49, 0x29, 0x1E],
        'A' | 'a' => [0x7E, 0x11, 0x11, 0x11, 0x7E],
        'B' | 'b' => [0x7F, 0x49, 0x49, 0x49, 0x36],
        'C' | 'c' => [0x3E, 0x41, 0x41, 0x41, 0x22],
        'D' | 'd' => [0x7F, 0x41, 0x41, 0x22, 0x1C],
        'E' | 'e' => [0x7F, 0x49, 0x49, 0x49, 0x41],
        'F' | 'f' => [0x7F, 0x09, 0x09, 0x09, 0x01],
        'G' | 'g' => [0x3E, 0x41, 0x49, 0x49, 0x7A],
        'H' | 'h' => [0x7F, 0x08, 0x08, 0x08, 0x7F],
        'I' | 'i' => [0x00, 0x41, 0x7F, 0x41, 0x00],
        'J' | 'j' => [0x20, 0x40, 0x41, 0x3F, 0x01],
        'K' | 'k' => [0x7F, 0x08, 0x14, 0x22, 0x41],
        'L' | 'l' => [0x7F, 0x40, 0x40, 0x40, 0x40],
        'M' | 'm' => [0x7F, 0x02, 0x0C, 0x02, 0x7F],
        'N' | 'n' => [0x7F, 0x04, 0x08, 0x10, 0x7F],
        'O' | 'o' => [0x3E, 0x41, 0x41, 0x41, 0x3E],
        'P' | 'p' => [0x7F, 0x09, 0x09, 0x09, 0x06],
        'Q' | 'q' => [0x3E, 0x41, 0x51, 0x21, 0x5E],
        'R' | 'r' => [0x7F, 0x09, 0x19, 0x29, 0x46],
        'S' | 's' => [0x46, 0x49, 0x49, 0x49, 0x31],
        'T' | 't' => [0x01, 0x01, 0x7F, 0x01, 0x01],
        'U' | 'u' => [0x3F, 0x40, 0x40, 0x40, 0x3F],
        'V' | 'v' => [0x1F, 0x20, 0x40, 0x20, 0x1F],
        'W' | 'w' => [0x7F, 0x20, 0x18, 0x20, 0x7F],
        'X' | 'x' => [0x63, 0x14, 0x08, 0x14, 0x63],
        'Y' | 'y' => [0x07, 0x08, 0x70, 0x08, 0x07],
        'Z' | 'z' => [0x61, 0x51, 0x49, 0x45, 0x43],
        ':' => [0x00, 0x36, 0x36, 0x00, 0x00],
        '.' => [0x00, 0x60, 0x60, 0x00, 0x00],
        ',' => [0x00, 0x80, 0x60, 0x00, 0x00],
        '+' => [0x08, 0x08, 0x3E, 0x08, 0x08],
        '-' => [0x08, 0x08, 0x08, 0x08, 0x08],
        '/' => [0x20, 0x10, 0x08, 0x04, 0x02],
        '%' => [0x23, 0x13, 0x08, 0x64, 0x62],
        '[' => [0x00, 0x7F, 0x41, 0x41, 0x00],
        ']' => [0x00, 0x41, 0x41, 0x7F, 0x00],
        '(' => [0x00, 0x1C, 0x22, 0x41, 0x00],
        ')' => [0x00, 0x41, 0x22, 0x1C, 0x00],
        '>' => [0x00, 0x41, 0x22, 0x14, 0x08],
        '<' => [0x08, 0x14, 0x22, 0x41, 0x00],
        '=' => [0x14, 0x14, 0x14, 0x14, 0x14],
        '!' => [0x00, 0x00, 0x5F, 0x00, 0x00],
        '?' => [0x02, 0x01, 0x51, 0x09, 0x06],
        '_' => [0x80, 0x80, 0x80, 0x80, 0x80],
        '|' => [0x00, 0x00, 0x7F, 0x00, 0x00],
        '\'' => [0x00, 0x07, 0x03, 0x00, 0x00],
        '@' => [0x3C, 0x42, 0x99, 0xA1, 0x5E],
        _ => [0x00, 0x00, 0x00, 0x00, 0x00], // space or unhandled
    }
}

pub fn draw_text(
    img: &mut RgbImage,
    start_x: i32,
    start_y: i32,
    text: &str,
    color: Rgb<u8>,
    scale: i32,
) {
    let mut cur_x = start_x;
    for ch in text.chars() {
        let bitmap = get_char_bitmap(ch);
        for col in 0..5 {
            let col_byte = bitmap[col];
            for row in 0..7 {
                if (col_byte & (1 << row)) != 0 {
                    let px = cur_x + (col as i32) * scale;
                    let py = start_y + (row as i32) * scale;
                    for sx in 0..scale {
                        for sy in 0..scale {
                            put_pixel_safe(img, px + sx, py + sy, color);
                        }
                    }
                }
            }
        }
        cur_x += (5 + 1) * scale;
    }
}

// ---------------------------------------------------------------------------
// Multi-Panel Renderers
// ---------------------------------------------------------------------------

pub struct RailVisualizer {
    pub scale: u32,
    pub max_dist_m: f32,
}

impl Default for RailVisualizer {
    fn default() -> Self {
        Self {
            scale: 2,
            max_dist_m: 200.0,
        }
    }
}

impl RailVisualizer {
    pub fn new(scale: u32, max_dist_m: f32) -> Self {
        Self { scale, max_dist_m }
    }

    /// Renders 2D Range Image view with Turbo colormap and 3D overlays
    pub fn render_range_view(
        &self,
        frame: &RangeImage,
        res: Option<&DetectionResult>,
        geo: &LidarGeometry,
    ) -> RgbImage {
        let w = frame.width as u32;
        let h = frame.height as u32;
        let out_w = w * self.scale;
        let out_h = h * self.scale;

        let mut img = RgbImage::new(out_w, out_h);

        // 1. Colorize with Turbo colormap
        for r in 0..h {
            for c in 0..w {
                let val = frame.data[(r * w + c) as usize];
                let color = if val <= 0.0 {
                    Rgb([0, 0, 0])
                } else {
                    let norm = (val / self.max_dist_m).clamp(0.0, 1.0);
                    Rgb(turbo_rgb(norm))
                };

                for sy in 0..self.scale {
                    for sx in 0..self.scale {
                        img.put_pixel(c * self.scale + sx, r * self.scale + sy, color);
                    }
                }
            }
        }

        let Some(r) = res else {
            draw_text(&mut img, 20, 20, "NO TRACK DETECTED", Rgb([255, 0, 0]), 2);
            return img;
        };

        let to_img_pts = |xs: &[f32], ys: &[f32], zs: &[f32]| -> Vec<[i32; 2]> {
            let mut out = Vec::new();
            for i in 0..xs.len() {
                let (row, col) = geo.xyz_to_row_col(xs[i], ys[i], zs[i]);
                if row >= 0 && (row as u32) < h && col >= 0 && (col as u32) < w {
                    out.push([(col as u32 * self.scale) as i32, (row as u32 * self.scale) as i32]);
                }
            }
            out
        };

        let pts_c = to_img_pts(&r.x_curve, &r.y_center, &r.z_center);
        let pts_l = to_img_pts(&r.x_left, &r.y_left, &r.z_center);
        let pts_r = to_img_pts(&r.x_right, &r.y_right, &r.z_center);

        // 1. Corridor polygon
        if pts_l.len() > 1 && pts_r.len() > 1 {
            let mut poly = pts_l.clone();
            let mut r_rev = pts_r.clone();
            r_rev.reverse();
            poly.extend(r_rev);
            draw_filled_polygon_alpha(&mut img, &poly, Rgb([0, 230, 110]), 0.35);
        }

        // 2. Left and Right rails
        draw_polyline(&mut img, &pts_l, Rgb([30, 210, 255]), 2); // Cyan
        draw_polyline(&mut img, &pts_r, Rgb([255, 90, 30]), 2);  // Orange

        // 3. Centerline
        draw_polyline(&mut img, &pts_c, Rgb([0, 255, 0]), 2);   // Bright Green

        // 4. Extrapolation (Magenta)
        if !r.x_ext.is_empty() {
            let pts_ext_c = to_img_pts(&r.x_ext, &r.y_ext, &r.z_ext);
            let pts_ext_l = to_img_pts(&r.x_ext_l, &r.y_ext_l, &r.z_ext);
            let pts_ext_r = to_img_pts(&r.x_ext_r, &r.y_ext_r, &r.z_ext);

            draw_dashed_polyline(&mut img, &pts_ext_c, Rgb([255, 0, 255]), 2, 4);
            draw_dashed_polyline(&mut img, &pts_ext_l, Rgb([220, 60, 220]), 1, 4);
            draw_dashed_polyline(&mut img, &pts_ext_r, Rgb([220, 60, 220]), 1, 4);
        }

        // 5. Raw point markers
        for pt in &r.points {
            draw_filled_circle(&mut img, (pt.col_left as u32 * self.scale) as i32, (pt.row as u32 * self.scale) as i32, 2, Rgb([255, 255, 0]));
            draw_filled_circle(&mut img, (pt.col_right as u32 * self.scale) as i32, (pt.row as u32 * self.scale) as i32, 2, Rgb([0, 0, 255]));
        }

        // 6. Distance tick markers
        for &dist in &[5.0, 10.0, 15.0, 20.0, 25.0, 30.0] {
            if let Some(idx) = r.x_curve.iter().position(|&x| (x - dist).abs() < 0.4) {
                let (row, col) = geo.xyz_to_row_col(r.x_curve[idx], r.y_center[idx], r.z_center[idx]);
                if row >= 0 && (row as u32) < h && col >= 0 && (col as u32) < w {
                    let px = (col as u32 * self.scale) as i32;
                    let py = (row as u32 * self.scale) as i32;
                    draw_filled_circle(&mut img, px, py, 3, Rgb([255, 255, 255]));
                    draw_text(&mut img, px + 6, py - 4, &format!("{:.0}m", dist), Rgb([255, 255, 255]), 1);
                }
            }
        }

        // Title
        draw_text(&mut img, 12, 12, "RANGE IMAGE (PERSPECTIVE)", Rgb([220, 220, 220]), 1);

        img
    }

    /// Renders Bird's Eye View (BEV) top-down panel
    pub fn render_bev_view(&self, res: Option<&DetectionResult>, width: u32, height: u32) -> RgbImage {
        let mut img = RgbImage::from_pixel(width, height, Rgb([12, 12, 12]));

        let cx = (width / 2) as i32;
        let cy = (height - 35) as i32;

        let max_x = 55.0_f32;
        let max_y = 3.0_f32;

        let to_bev = |x: f32, y: f32| -> [i32; 2] {
            let px = cx + (y / max_y * (cx as f32 - 15.0)).round() as i32;
            let py = cy - (x / max_x * (cy as f32 - 25.0)).round() as i32;
            [px, py]
        };

        // Grid lines (Distance 10m, 20m, 30m, 40m, 50m)
        for &dist in &[10.0, 20.0, 30.0, 40.0, 50.0] {
            let p = to_bev(dist, 0.0);
            draw_line(&mut img, 15, p[1], width as i32 - 15, p[1], Rgb([40, 40, 40]), 1);
            draw_text(&mut img, width as i32 - 42, p[1] - 8, &format!("{:.0}m", dist), Rgb([90, 90, 90]), 1);
        }

        // Lateral lines (-1.5, -0.75, 0, 0.75, 1.5)
        for &lat in &[-1.5, -0.75, 0.0, 0.75, 1.5] {
            let p = to_bev(0.0, lat);
            let col = if lat == 0.0 { Rgb([60, 60, 60]) } else { Rgb([35, 35, 35]) };
            draw_line(&mut img, p[0], 20, p[0], cy, col, 1);
        }

        // Vehicle icon at (0, 0)
        let v0 = to_bev(0.0, 0.0);
        let tri = [
            [v0[0], v0[1] - 12],
            [v0[0] - 6, v0[1] + 5],
            [v0[0] + 6, v0[1] + 5],
        ];
        draw_filled_polygon_alpha(&mut img, &tri, Rgb([0, 200, 255]), 1.0);

        if let Some(r) = res {
            let pts_l: Vec<[i32; 2]> = (0..r.x_left.len()).map(|i| to_bev(r.x_left[i], r.y_left[i])).collect();
            let pts_r: Vec<[i32; 2]> = (0..r.x_right.len()).map(|i| to_bev(r.x_right[i], r.y_right[i])).collect();
            let pts_c: Vec<[i32; 2]> = (0..r.x_curve.len()).map(|i| to_bev(r.x_curve[i], r.y_center[i])).collect();

            // Corridor
            if pts_l.len() > 1 && pts_r.len() > 1 {
                let mut poly = pts_l.clone();
                let mut r_rev = pts_r.clone();
                r_rev.reverse();
                poly.extend(r_rev);
                draw_filled_polygon_alpha(&mut img, &poly, Rgb([0, 180, 80]), 0.28);
            }

            // Rails
            draw_polyline(&mut img, &pts_l, Rgb([255, 210, 30]), 2);
            draw_polyline(&mut img, &pts_r, Rgb([30, 90, 255]), 2);
            draw_polyline(&mut img, &pts_c, Rgb([0, 255, 0]), 2);

            // Extrapolation (Magenta)
            if !r.x_ext.is_empty() {
                let pts_ext_c: Vec<[i32; 2]> = (0..r.x_ext.len()).map(|i| to_bev(r.x_ext[i], r.y_ext[i])).collect();
                let pts_ext_l: Vec<[i32; 2]> = (0..r.x_ext_l.len()).map(|i| to_bev(r.x_ext_l[i], r.y_ext_l[i])).collect();
                let pts_ext_r: Vec<[i32; 2]> = (0..r.x_ext_r.len()).map(|i| to_bev(r.x_ext_r[i], r.y_ext_r[i])).collect();

                draw_dashed_polyline(&mut img, &pts_ext_c, Rgb([255, 0, 255]), 2, 4);
                draw_dashed_polyline(&mut img, &pts_ext_l, Rgb([200, 50, 200]), 1, 4);
                draw_dashed_polyline(&mut img, &pts_ext_r, Rgb([200, 50, 200]), 1, 4);

                if let Some(tip) = pts_ext_c.last() {
                    draw_text(&mut img, tip[0] + 5, tip[1] - 4, &format!("Extrap +{:.0}m", r.extrapolate_m), Rgb([255, 120, 255]), 1);
                }
            }

            // Raw points
            for pt in &r.points {
                let pl = to_bev(pt.x_left, pt.y_left);
                let pr = to_bev(pt.x_right, pt.y_right);
                draw_filled_circle(&mut img, pl[0], pl[1], 2, Rgb([255, 255, 0]));
                draw_filled_circle(&mut img, pr[0], pr[1], 2, Rgb([0, 0, 255]));
            }
        }

        draw_text(&mut img, 12, 12, "BIRD'S EYE VIEW (BEV)", Rgb([220, 220, 220]), 1);
        img
    }

    /// Renders HUD telemetry dashboard card
    pub fn render_hud_view(&self, res: Option<&DetectionResult>, width: u32, height: u32) -> RgbImage {
        let mut img = RgbImage::from_pixel(width, height, Rgb([15, 15, 15]));

        // Header
        draw_text(&mut img, 15, 16, "RAIL TRACK TELEMETRY", Rgb([240, 240, 240]), 1);
        draw_line(&mut img, 15, 28, width as i32 - 15, 28, Rgb([50, 50, 50]), 1);

        let Some(r) = res else {
            draw_filled_rect(&mut img, 15, 40, width as i32 - 15, 75, Rgb([160, 20, 20]));
            draw_text(&mut img, 25, 52, "STATUS: TRACK LOST", Rgb([255, 255, 255]), 1);
            return img;
        };

        // Badge
        let (badge_col, badge_text) = if r.turn_direction == "STRAIGHT" {
            (Rgb([30, 160, 40]), "TRACK: STRAIGHT")
        } else if r.turn_direction.contains("LEFT") {
            (Rgb([200, 130, 20]), "TRACK: CURVE LEFT")
        } else {
            (Rgb([20, 120, 220]), "TRACK: CURVE RIGHT")
        };

        draw_filled_rect(&mut img, 15, 38, width as i32 - 15, 70, badge_col);
        draw_text(&mut img, 25, 49, badge_text, Rgb([255, 255, 255]), 1);

        // Metrics
        let heading_deg = r.heading_b.atan().to_degrees();
        let offset_cm = r.offset_c * 100.0;
        let gauge_cm = r.gauge * 100.0;
        let radius_str = if r.turn_radius < 5000.0 {
            format!("{:.0} m", r.turn_radius)
        } else {
            "> 5000 m".to_string()
        };

        let mut metrics = vec![
            ("Frame", format!("{:06}", r.frame_idx)),
            ("Turn Radius", radius_str),
            ("Heading Angle", format!("{:+5.1} deg", heading_deg)),
            ("Lateral Offset", format!("{:+5.1} cm", offset_cm)),
            ("Track Gauge", format!("{:.1} cm", gauge_cm)),
            ("Drift @ 15m", format!("{:+4.2} m", r.lateral_shift_15m)),
            ("Scanlines Found", format!("{} / 48", r.points.len())),
            ("Confidence", format!("{:.0} %", r.confidence * 100.0)),
        ];

        if r.has_intensity {
            metrics.push((
                "Intensity L/R",
                format!("{:.0} / {:.0}", r.avg_intensity_left, r.avg_intensity_right),
            ));
        }

        let mut y_off = 90;
        for (label, val) in metrics {
            draw_text(&mut img, 18, y_off, label, Rgb([160, 160, 160]), 1);
            draw_text(&mut img, width as i32 - 130, y_off, &val, Rgb([255, 255, 255]), 1);
            y_off += 24;
        }

        // Quality bar
        draw_text(&mut img, 18, y_off + 4, "TRACK QUALITY", Rgb([140, 140, 140]), 1);
        let bar_x = 18;
        let bar_y = y_off + 16;
        let bar_w = width as i32 - 36;
        let bar_h = 8;
        draw_filled_rect(&mut img, bar_x, bar_y, bar_x + bar_w, bar_y + bar_h, Rgb([40, 40, 40]));
        let fill_w = (bar_w as f32 * r.confidence) as i32;
        let fill_col = if r.confidence > 0.7 { Rgb([0, 220, 80]) } else { Rgb([0, 180, 240]) };
        draw_filled_rect(&mut img, bar_x, bar_y, bar_x + fill_w, bar_y + bar_h, fill_col);

        y_off = bar_y + bar_h + 16;

        // Extrapolation info
        if !r.x_ext.is_empty() {
            draw_line(&mut img, 15, y_off, width as i32 - 15, y_off, Rgb([50, 50, 50]), 1);
            draw_text(&mut img, 18, y_off + 8, &format!("EXTRAPOLATION (+{:.0}m)", r.extrapolate_m), Rgb([220, 220, 220]), 1);
            draw_text(&mut img, 18, y_off + 24, &format!("Smoothed N: {}", r.smooth_n), Rgb([170, 170, 170]), 1);
        }

        // Legend at bottom
        let leg_y = height as i32 - 45;
        draw_line(&mut img, 15, leg_y - 8, width as i32 - 15, leg_y - 8, Rgb([50, 50, 50]), 1);
        draw_text(&mut img, 18, leg_y, "Track: ", Rgb([140, 140, 140]), 1);
        draw_filled_circle(&mut img, 65, leg_y + 3, 3, Rgb([255, 210, 30]));
        draw_text(&mut img, 72, leg_y, "Left", Rgb([200, 200, 200]), 1);
        draw_filled_circle(&mut img, 110, leg_y + 3, 3, Rgb([30, 90, 255]));
        draw_text(&mut img, 117, leg_y, "Right", Rgb([200, 200, 200]), 1);
        draw_filled_circle(&mut img, 160, leg_y + 3, 3, Rgb([0, 255, 0]));
        draw_text(&mut img, 167, leg_y, "Center", Rgb([200, 200, 200]), 1);

        draw_text(&mut img, 18, leg_y + 18, "Extrap:", Rgb([140, 140, 140]), 1);
        draw_filled_circle(&mut img, 65, leg_y + 21, 3, Rgb([255, 0, 255]));
        draw_text(&mut img, 72, leg_y + 18, "Poly (Magenta)", Rgb([255, 120, 255]), 1);

        img
    }

    /// Renders full composite image [ Range View | BEV | HUD ]
    pub fn render_composite(
        &self,
        frame: &RangeImage,
        res: Option<&DetectionResult>,
        geo: &LidarGeometry,
    ) -> RgbImage {
        let range_img = self.render_range_view(frame, res, geo);
        let h = range_img.height();
        let bev_img = self.render_bev_view(res, 360, h);
        let hud_img = self.render_hud_view(res, 320, h);

        let total_w = range_img.width() + bev_img.width() + hud_img.width();
        let mut composite = RgbImage::new(total_w, h);

        // Blit range_img
        image::imageops::overlay(&mut composite, &range_img, 0, 0);
        // Blit bev_img
        image::imageops::overlay(&mut composite, &bev_img, range_img.width() as i64, 0);
        // Blit hud_img
        image::imageops::overlay(
            &mut composite,
            &hud_img,
            (range_img.width() + bev_img.width()) as i64,
            0,
        );

        composite
    }
}
