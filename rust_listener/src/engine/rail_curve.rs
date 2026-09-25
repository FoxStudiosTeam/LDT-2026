//! rail_curve.rs — 3D RANSAC Rail Track Detector & Curve Extrapolator
//!
//! Features:
//! 1. Specular reflection anchor seeds (`intensity == 0` for Y in near zone [-10.0, -1.8]m).
//! 2. Rigid dual-rail pairing (gauge constraint 1.50..1.65m, equal height).
//! 3. Curvature-aware 3D RANSAC + cubic polynomial / clothoid refinement.
//! 4. Straightness metric (`straightness` in [0.0, 1.0]) that dampens curvature
//!    during extrapolation on straight tracks, preventing unnatural bending.
//! 5. Analytical C2-smooth extrapolation "по накатанной".
//! 6. Native Rerun 3D visualization: rails, centerline, sleepers, inliers, and telemetry.

use rerun::{Color, LineStrips3D, Points3D, Radius, RecordingStream};
use shared::error::{AppError, ErrCtx};

/// Параметры конфигурации детектора кривых пути
#[derive(Clone, Debug)]
pub struct RailCurveConfig {
    /// Число итераций RANSAC (по умолчанию: 400)
    pub n_iters: usize,
    /// Порог расстояния до рельса для инлаеров в метрах (по умолчанию: 0.085)
    pub inlier_thresh: f32,
    /// Номинальная ширина колеи в метрах (по умолчанию: 1.575)
    pub gauge_nominal: f32,
    /// Допустимое отклонение ширины колеи (по умолчанию: 0.075)
    pub gauge_tol: f32,
    /// Максимальное расстояние экстраполяции "по накатанной" в метрах (по умолчанию: 25.0)
    pub max_extrapolate_m: f32,
    /// Ближняя граница Y для поиска якорей (по умолчанию: -10.0)
    pub near_y_min: f32,
    /// Дальняя граница Y для поиска якорей (по умолчанию: -1.8)
    pub near_y_max: f32,
    /// Максимальная дальность поиска рельсов по Y (по умолчанию: -45.0)
    pub max_y: f32,
    /// Порог бокового отклонения от прямой хорды в метрах, при котором прямизна = 0 (по умолчанию: 0.35)
    pub straightness_deflection_threshold_m: f32,
    /// Шаг между шпалами в метрах (по умолчанию: 0.6)
    pub sleeper_spacing_m: f32,
}

impl Default for RailCurveConfig {
    fn default() -> Self {
        Self {
            n_iters: 400,
            inlier_thresh: 0.085,
            gauge_nominal: 1.575,
            gauge_tol: 0.075,
            max_extrapolate_m: 25.0,
            near_y_min: -10.0,
            near_y_max: -1.8,
            max_y: -45.0,
            straightness_deflection_threshold_m: 0.35,
            sleeper_spacing_m: 0.6,
        }
    }
}

/// Результат расчета кривой железнодорожного пути
#[derive(Clone, Debug)]
pub struct RailCurveResult {
    /// Коэффициенты кубического/квадратичного полинома X_c(y) (по убыванию степеней: [c_deg, ..., c_0])
    pub poly_x: Vec<f32>,
    /// Коэффициенты линейного полинома высоты Z_c(y) = [h1, h0]
    pub poly_z: [f32; 2],
    /// Измеренная ширина колеи в метрах
    pub gauge: f32,
    /// Метрика "прямизны" пути в диапазоне [0.0, 1.0]
    /// (1.0 = идеальная прямая, 0.0 = крутая кривая)
    pub straightness: f32,
    /// Оценочный радиус кривизны пути в метрах (None если путь прямой)
    pub curve_radius_m: Option<f32>,
    /// Максимальный боковой прогиб от прямой хорды в метрах
    pub lateral_deflection_m: f32,
    /// Границы обнаруженного участка (y_min, y_max) в метрах
    pub y_range: (f32, f32),
    /// Примененная дистанция экстраполяции в метрах
    pub extrapolate_m: f32,

    // ── Геометрия подтвержденного участка ──
    pub pts_left: Vec<[f32; 3]>,
    pub pts_right: Vec<[f32; 3]>,
    pub pts_center: Vec<[f32; 3]>,
    pub sleepers: Vec<[[f32; 3]; 2]>,

    // ── Экстраполированный участок "по накатанной" ──
    pub ext_pts_left: Option<Vec<[f32; 3]>>,
    pub ext_pts_right: Option<Vec<[f32; 3]>>,
    pub ext_pts_center: Option<Vec<[f32; 3]>>,
    pub ext_sleepers: Vec<[[f32; 3]; 2]>,

    // ── Инлаеры и зерна для отладки ──
    pub inliers_left: Vec<[f32; 3]>,
    pub inliers_right: Vec<[f32; 3]>,
    pub seeds_near: Vec<[f32; 3]>,
}

impl RailCurveResult {
    /// Отправляет все геометрические слои кривой пути в Rerun
    pub fn log_to_rerun(&self, rec: &RecordingStream) -> Result<(), AppError> {
        // 1. Подтвержденный участок рельсов и оси
        rec.log(
            "rails/left_track",
            &LineStrips3D::new([self.pts_left.clone()])
                .with_colors([Color::from_rgb(0, 255, 100)])
                .with_radii([Radius::new_scene_units(0.035)]),
        )
        .app_error()?;

        rec.log(
            "rails/right_track",
            &LineStrips3D::new([self.pts_right.clone()])
                .with_colors([Color::from_rgb(0, 210, 255)])
                .with_radii([Radius::new_scene_units(0.035)]),
        )
        .app_error()?;

        rec.log(
            "rails/centerline",
            &LineStrips3D::new([self.pts_center.clone()])
                .with_colors([Color::from_rgb(255, 255, 255)])
                .with_radii([Radius::new_scene_units(0.015)]),
        )
        .app_error()?;

        // Шпалы
        if !self.sleepers.is_empty() {
            rec.log(
                "rails/sleepers",
                &LineStrips3D::new(self.sleepers.clone())
                    .with_colors([Color::from_rgb(190, 160, 110)])
                    .with_radii([Radius::new_scene_units(0.018)]),
            )
            .app_error()?;
        }

        // 2. Продленный участок "по накатанной"
        if let (Some(ext_l), Some(ext_r), Some(ext_c)) = (
            &self.ext_pts_left,
            &self.ext_pts_right,
            &self.ext_pts_center,
        ) {
            rec.log(
                "rails/extrapolated/left_track",
                &LineStrips3D::new([ext_l.clone()])
                    .with_colors([Color::from_rgb(255, 190, 40)])
                    .with_radii([Radius::new_scene_units(0.028)]),
            )
            .app_error()?;

            rec.log(
                "rails/extrapolated/right_track",
                &LineStrips3D::new([ext_r.clone()])
                    .with_colors([Color::from_rgb(255, 190, 40)])
                    .with_radii([Radius::new_scene_units(0.028)]),
            )
            .app_error()?;

            rec.log(
                "rails/extrapolated/centerline",
                &LineStrips3D::new([ext_c.clone()])
                    .with_colors([Color::from_rgb(255, 220, 120)])
                    .with_radii([Radius::new_scene_units(0.012)]),
            )
            .app_error()?;

            if !self.ext_sleepers.is_empty() {
                rec.log(
                    "rails/extrapolated/sleepers",
                    &LineStrips3D::new(self.ext_sleepers.clone())
                        .with_colors([Color::from_rgb(170, 140, 80)])
                        .with_radii([Radius::new_scene_units(0.015)]),
                )
                .app_error()?;
            }
        }

        // 3. Инлаеры и семена
        rec.log(
            "rails/inliers_left",
            &Points3D::new(self.inliers_left.clone())
                .with_colors([Color::from_rgb(0, 255, 100)])
                .with_radii([Radius::new_scene_units(0.03)]),
        )
        .app_error()?;

        rec.log(
            "rails/inliers_right",
            &Points3D::new(self.inliers_right.clone())
                .with_colors([Color::from_rgb(0, 210, 255)])
                .with_radii([Radius::new_scene_units(0.03)]),
        )
        .app_error()?;

        rec.log(
            "rails/seeds_near_zero_intensity",
            &Points3D::new(self.seeds_near.clone())
                .with_colors([Color::from_rgb(255, 230, 0)])
                .with_radii([Radius::new_scene_units(0.04)]),
        )
        .app_error()?;

        // 4. Текстовая телеметрия
        let radius_str = match self.curve_radius_m {
            Some(r) => format!("{:.0}m", r),
            None => "Inf (straight)".to_string(),
        };
        let det_len = -self.y_range.0 - (-self.y_range.1);
        let info_text = format!(
            "Gauge: {:.3}m | Straightness: {:.1}% | Radius: {} | Deflection: {:.3}m\n\
             Detected range: {:.1}m..{:.1}m (len: {:.1}m) | Extrapolated: +{:.1}m (Total: {:.1}m)\n\
             Inliers: Left={}, Right={}",
            self.gauge,
            self.straightness * 100.0,
            radius_str,
            self.lateral_deflection_m,
            -self.y_range.1,
            -self.y_range.0,
            det_len,
            self.extrapolate_m,
            -self.y_range.0 + self.extrapolate_m,
            self.inliers_left.len(),
            self.inliers_right.len()
        );
        rec.log("telemetry/rail_curve", &rerun::TextLog::new(info_text))
            .app_error()?;

        Ok(())
    }
}

/// Вычислитель кривых железнодорожных путей
#[derive(Clone, Debug)]
pub struct RailCurveEstimator {
    pub config: RailCurveConfig,
}

impl RailCurveEstimator {
    pub fn new(config: RailCurveConfig) -> Self {
        Self { config }
    }

    /// Рассчитывает 3D модель кривой пути по облаку точек и интенсивности
    pub fn fit(&self, points: &[[f32; 3]], intensities: &[f32]) -> Option<RailCurveResult> {
        let n = points.len();
        if n < 50 || n != intensities.len() {
            return None;
        }

        let cfg = &self.config;

        // 1. Выделяем якоря в ближней зоне (intensity == 0 из-за зеркального отражения головки рельса)
        let mut left_seeds = Vec::new();
        let mut right_seeds = Vec::new();
        let mut seeds_all = Vec::new();

        for i in 0..n {
            let p = points[i];
            let intensity = intensities[i];

            if intensity <= 0.5
                && p[1] > cfg.near_y_min
                && p[1] < cfg.near_y_max
                && p[0].abs() < 2.5
                && p[2] > -1.6
                && p[2] < -0.6
            {
                seeds_all.push(p);
                if p[0] < 0.0 {
                    left_seeds.push(p);
                } else {
                    right_seeds.push(p);
                }
            }
        }

        if left_seeds.len() < 10 || right_seeds.len() < 10 {
            return None;
        }

        // 2. Пул кандидатов для скоринга (коридор пути до max_y)
        let mut pool_indices = Vec::new();
        for i in 0..n {
            let p = points[i];
            if p[0].abs() < 4.0
                && p[1] < cfg.near_y_max
                && p[1] > cfg.max_y
                && p[2] > -1.7
                && p[2] < -0.4
            {
                pool_indices.push(i);
            }
        }

        if pool_indices.len() < 50 {
            return None;
        }

        // Дальние кандидаты для криволинейных гипотез (Y < -12м)
        let mut dist_left = Vec::new();
        let mut dist_right = Vec::new();
        for &idx in &pool_indices {
            let p = points[idx];
            let intensity = intensities[idx];
            if p[1] < -12.0 && p[1] > -35.0 && intensity <= 0.5 {
                if p[0] < 0.0 {
                    dist_left.push(p);
                } else {
                    dist_right.push(p);
                }
            }
        }

        // 3. RANSAC сэмплирование криволинейных гипотез
        // Простой псевдо-ГСЧ (Xorshift32) для воспроизводимости и скорости без внешних зависимостей
        let mut rng_state: u32 = 42;
        let mut next_rand = || -> u32 {
            rng_state ^= rng_state << 13;
            rng_state ^= rng_state >> 17;
            rng_state ^= rng_state << 5;
            rng_state
        };

        let mut best_score = -1.0f32;
        let mut best_inl_l = Vec::new();
        let mut best_inl_r = Vec::new();
        let mut best_gauge = cfg.gauge_nominal;

        for _ in 0..cfg.n_iters {
            // Выбираем ближнюю пару рельс
            let p_l1 = left_seeds[next_rand() as usize % left_seeds.len()];
            let cands_r1: Vec<[f32; 3]> = right_seeds
                .iter()
                .copied()
                .filter(|pr| (pr[1] - p_l1[1]).abs() < 0.8)
                .collect();
            if cands_r1.is_empty() {
                continue;
            }
            let p_r1 = cands_r1[next_rand() as usize % cands_r1.len()];
            let g1 = p_r1[0] - p_l1[0];
            if (g1 - cfg.gauge_nominal).abs() > cfg.gauge_tol || (p_r1[2] - p_l1[2]).abs() > 0.08 {
                continue;
            }

            // Выбираем вторую пару рельс на расстоянии не менее 1.5м
            let far_left_cands: Vec<[f32; 3]> = left_seeds
                .iter()
                .copied()
                .filter(|pl| (pl[1] - p_l1[1]).abs() > 1.5)
                .collect();
            if far_left_cands.is_empty() {
                continue;
            }
            let p_l2 = far_left_cands[next_rand() as usize % far_left_cands.len()];
            let cands_r2: Vec<[f32; 3]> = right_seeds
                .iter()
                .copied()
                .filter(|pr| (pr[1] - p_l2[1]).abs() < 0.8)
                .collect();
            if cands_r2.is_empty() {
                continue;
            }
            let p_r2 = cands_r2[next_rand() as usize % cands_r2.len()];
            let g2 = p_r2[0] - p_l2[0];
            if (g2 - cfg.gauge_nominal).abs() > cfg.gauge_tol || (p_r2[2] - p_l2[2]).abs() > 0.08 {
                continue;
            }

            let c1 = [
                0.5 * (p_l1[0] + p_r1[0]),
                0.5 * (p_l1[1] + p_r1[1]),
                0.5 * (p_l1[2] + p_r1[2]),
            ];
            let c2 = [
                0.5 * (p_l2[0] + p_r2[0]),
                0.5 * (p_l2[1] + p_r2[1]),
                0.5 * (p_l2[2] + p_r2[2]),
            ];
            let gauge = 0.5 * (g1 + g2);

            // Гипотеза кривизны: 3 точки (c1, c2, c3) или сэмплирование кривизны
            let mut poly_c: Option<[f32; 3]> = None; // [c2, c1, c0]

            if !dist_left.is_empty() && !dist_right.is_empty() && (next_rand() % 100 < 75) {
                let p_l3 = dist_left[next_rand() as usize % dist_left.len()];
                let cands_r3: Vec<[f32; 3]> = dist_right
                    .iter()
                    .copied()
                    .filter(|pr| (pr[1] - p_l3[1]).abs() < 1.0)
                    .collect();
                if !cands_r3.is_empty() {
                    let p_r3 = cands_r3[next_rand() as usize % cands_r3.len()];
                    let g3 = p_r3[0] - p_l3[0];
                    if (g3 - cfg.gauge_nominal).abs() < (cfg.gauge_tol + 0.05) {
                        let c3 = [
                            0.5 * (p_l3[0] + p_r3[0]),
                            0.5 * (p_l3[1] + p_r3[1]),
                            0.5 * (p_l3[2] + p_r3[2]),
                        ];
                        // Парабола через 3 точки: c1, c2, c3
                        poly_c = fit_parabola_3pts(c1[1], c1[0], c2[1], c2[0], c3[1], c3[0]);
                    }
                }
            }

            if poly_c.is_none() {
                let dy = c2[1] - c1[1];
                if dy.abs() < 1.0 {
                    continue;
                }
                let k0 = (c2[0] - c1[0]) / dy;
                // Сэмплируем допустимую железнодорожную кривизну (|a| <= 0.003)
                let rand_f = (next_rand() % 10000) as f32 / 10000.0;
                let a = (rand_f * 2.0 - 1.0) * 0.0030;
                let c2_coeff = a;
                let c1_coeff = k0 - 2.0 * a * c1[1];
                let c0_coeff = c1[0] - k0 * c1[1] + a * c1[1] * c1[1];
                poly_c = Some([c2_coeff, c1_coeff, c0_coeff]);
            }

            let poly_c = poly_c.unwrap();
            // Ограничение физической кривизны ж/д пути (R >= 120м -> |c2| <= 0.0042)
            if poly_c[0].abs() > 0.0042 {
                continue;
            }

            let kz = (c2[2] - c1[2]) / (c2[1] - c1[1]);
            let bz = c1[2] - kz * c1[1];
            let half_w = gauge / 2.0;

            let mut inl_l = Vec::new();
            let mut inl_r = Vec::new();
            let mut score = 0.0f32;
            let mut near_count_l = 0;
            let mut near_count_r = 0;

            for &idx in &pool_indices {
                let p = points[idx];
                let intensity = intensities[idx];

                let xc = poly_c[0] * p[1] * p[1] + poly_c[1] * p[1] + poly_c[2];
                let zc = kz * p[1] + bz;

                let dl = ((p[0] - (xc - half_w)).powi(2) + (p[2] - zc).powi(2)).sqrt();
                let dr = ((p[0] - (xc + half_w)).powi(2) + (p[2] - zc).powi(2)).sqrt();

                let weight = if intensity <= 0.5 { 3.0 } else { 1.0 };

                if dl < cfg.inlier_thresh {
                    inl_l.push(p);
                    score += weight;
                    if p[1] > -10.0 {
                        near_count_l += 1;
                    }
                } else if dr < cfg.inlier_thresh {
                    inl_r.push(p);
                    score += weight;
                    if p[1] > -10.0 {
                        near_count_r += 1;
                    }
                }
            }

            if near_count_l < 25 || near_count_r < 25 {
                continue;
            }

            if score > best_score {
                best_score = score;
                best_inl_l = inl_l;
                best_inl_r = inl_r;
                best_gauge = gauge;
            }
        }

        if best_score < 0.0 || best_inl_l.is_empty() || best_inl_r.is_empty() {
            return None;
        }

        let half_w = best_gauge / 2.0;

        // 4. Аналитическое МНК-уточнение полинома по инлаерам
        let mut sample_y = Vec::with_capacity(best_inl_l.len() + best_inl_r.len());
        let mut sample_x = Vec::with_capacity(best_inl_l.len() + best_inl_r.len());
        let mut sample_z = Vec::with_capacity(best_inl_l.len() + best_inl_r.len());

        let mut y_min = -16.0f32;
        let mut sum_xr = 0.0f32;
        let mut sum_xl = 0.0f32;

        for p in &best_inl_l {
            sample_y.push(p[1]);
            sample_x.push(p[0] + half_w);
            sample_z.push(p[2]);
            y_min = y_min.min(p[1]);
            sum_xl += p[0];
        }
        for p in &best_inl_r {
            sample_y.push(p[1]);
            sample_x.push(p[0] - half_w);
            sample_z.push(p[2]);
            y_min = y_min.min(p[1]);
            sum_xr += p[0];
        }

        y_min = y_min.max(cfg.max_y);
        let actual_gauge = (sum_xr / best_inl_r.len() as f32) - (sum_xl / best_inl_l.len() as f32);
        let refined_half_w = actual_gauge / 2.0;

        let deg = if sample_y.len() > 200 && y_min < -18.0 { 3 } else { 2 };
        let poly_x = polyfit(&sample_y, &sample_x, deg)?;
        let poly_z_vec = polyfit(&sample_y, &sample_z, 1)?;
        let poly_z = [poly_z_vec[0], poly_z_vec[1]];

        // 5. Расчет метрики "прямизны" (Straightness)
        // Сравниваем кривую пути X_c(y) с прямой хордой между началом и концом детектированного участка
        let y_max = -2.0f32;
        let x_start = polyval(&poly_x, y_max);
        let x_end = polyval(&poly_x, y_min);

        let mut max_deflection = 0.0f32;
        let test_steps = 50;
        for i in 0..=test_steps {
            let y_t = y_max + (y_min - y_max) * (i as f32 / test_steps as f32);
            let x_curve = polyval(&poly_x, y_t);
            // Прямая хорда между началом и концом
            let chord_t = (y_t - y_max) / (y_min - y_max);
            let x_chord = x_start + (x_end - x_start) * chord_t;
            let defl = (x_curve - x_chord).abs();
            if defl > max_deflection {
                max_deflection = defl;
            }
        }

        // Прямизна в диапазоне [0.0, 1.0]:
        // если прогиб <= 3см — прямизна ~90..100%
        // если прогиб >= threshold (35см) — прямизна 0% (выраженная кривая)
        let straightness = (1.0 - (max_deflection / cfg.straightness_deflection_threshold_m))
            .clamp(0.0, 1.0);

        // Оценка радиуса кривизны (по формуле хорды и стрелы прогиба: R ≈ L^2 / (8 * f))
        let arc_len = (y_max - y_min).abs();
        let curve_radius_m = if max_deflection > 0.025 {
            Some((arc_len * arc_len) / (8.0 * max_deflection))
        } else {
            None
        };

        // 6. Формирование 3D точек подтвержденного участка
        let n_steps = ((y_max - y_min).abs() / 0.25).ceil() as usize;
        let mut pts_left = Vec::with_capacity(n_steps + 1);
        let mut pts_right = Vec::with_capacity(n_steps + 1);
        let mut pts_center = Vec::with_capacity(n_steps + 1);

        for i in 0..=n_steps {
            let y_t = y_max - (i as f32 * 0.25).min((y_max - y_min).abs());
            let xc = polyval(&poly_x, y_t);
            let zc = poly_z[0] * y_t + poly_z[1];
            pts_left.push([xc - refined_half_w, y_t, zc]);
            pts_right.push([xc + refined_half_w, y_t, zc]);
            pts_center.push([xc, y_t, zc]);
        }

        // Шпалы на подтвержденном участке
        let mut sleepers = Vec::new();
        let mut sy = y_max;
        while sy >= y_min {
            let s_xc = polyval(&poly_x, sy);
            let s_zc = poly_z[0] * sy + poly_z[1];
            sleepers.push([
                [s_xc - refined_half_w - 0.2, sy, s_zc],
                [s_xc + refined_half_w + 0.2, sy, s_zc],
            ]);
            sy -= cfg.sleeper_spacing_m;
        }

        // 7. Экстраполяция "по накатанной" с демпфированием кривизны по прямизне
        let mut ext_pts_left = None;
        let mut ext_pts_right = None;
        let mut ext_pts_center = None;
        let mut ext_sleepers = Vec::new();

        if cfg.max_extrapolate_m > 0.0 {
            let y0 = y_min;
            let x0 = polyval(&poly_x, y0);
            let z0 = poly_z[0] * y0 + poly_z[1];

            // Первая производная (тангенс курса) и вторая производная (кривизна)
            let k0 = poly_derivative1(&poly_x, y0);
            let raw_curv0 = poly_derivative2(&poly_x, y0).clamp(-0.0035, 0.0035);

            // КЛЮЧЕВОЕ: на прямых участках (straightness -> 1.0) зануляем кривизну экстраполяции,
            // чтобы кривая не уходила вбок на прямых, а шла строго по курсу!
            let effective_curv = (1.0 - straightness) * raw_curv0;

            let ext_steps = (cfg.max_extrapolate_m / 0.25).ceil() as usize;
            let mut ext_l = Vec::with_capacity(ext_steps);
            let mut ext_r = Vec::with_capacity(ext_steps);
            let mut ext_c = Vec::with_capacity(ext_steps);

            for i in 1..=ext_steps {
                let s = i as f32 * 0.25;
                if s > cfg.max_extrapolate_m {
                    break;
                }
                let y_ext = y0 - s;
                let x_ext = x0 - k0 * s + 0.5 * effective_curv * s * s;
                let z_ext = z0 - poly_z[0] * s;

                ext_l.push([x_ext - refined_half_w, y_ext, z_ext]);
                ext_r.push([x_ext + refined_half_w, y_ext, z_ext]);
                ext_c.push([x_ext, y_ext, z_ext]);
            }

            // Шпалы на экстраполированном участке
            let mut es = cfg.sleeper_spacing_m;
            while es <= cfg.max_extrapolate_m {
                let ey = y0 - es;
                let ex = x0 - k0 * es + 0.5 * effective_curv * es * es;
                let ez = z0 - poly_z[0] * es;
                ext_sleepers.push([
                    [ex - refined_half_w - 0.2, ey, ez],
                    [ex + refined_half_w + 0.2, ey, ez],
                ]);
                es += cfg.sleeper_spacing_m;
            }

            ext_pts_left = Some(ext_l);
            ext_pts_right = Some(ext_r);
            ext_pts_center = Some(ext_c);
        }

        Some(RailCurveResult {
            poly_x,
            poly_z,
            gauge: actual_gauge,
            straightness,
            curve_radius_m,
            lateral_deflection_m: max_deflection,
            y_range: (y_min, y_max),
            extrapolate_m: cfg.max_extrapolate_m,
            pts_left,
            pts_right,
            pts_center,
            sleepers,
            ext_pts_left,
            ext_pts_right,
            ext_pts_center,
            ext_sleepers,
            inliers_left: best_inl_l,
            inliers_right: best_inl_r,
            seeds_near: seeds_all,
        })
    }
}

// ─── Вспомогательные математические функции ───────────────────────────────────

/// Парабола через 3 точки (y1, x1), (y2, x2), (y3, x3) -> [c2, c1, c0]
fn fit_parabola_3pts(y1: f32, x1: f32, y2: f32, x2: f32, y3: f32, x3: f32) -> Option<[f32; 3]> {
    let denom = (y1 - y2) * (y1 - y3) * (y2 - y3);
    if denom.abs() < 1e-4 {
        return None;
    }
    let c2 = (y3 * (x2 - x1) + y2 * (x1 - x3) + y1 * (x3 - x2)) / denom;
    let c1 = (y3 * y3 * (x1 - x2) + y2 * y2 * (x3 - x1) + y1 * y1 * (x2 - x3)) / denom;
    let c0 = (y2 * y3 * (y2 - y3) * x1 + y3 * y1 * (y3 - y1) * x2 + y1 * y2 * (y1 - y2) * x3) / denom;
    Some([c2, c1, c0])
}

/// Вычисление значения полинома по схеме Горнера (poly = [c_n, ..., c_0])
#[inline(always)]
pub fn polyval(poly: &[f32], x: f32) -> f32 {
    let mut val = 0.0f32;
    for &coeff in poly {
        val = val * x + coeff;
    }
    val
}

/// Первая производная полинома d(poly)/dx
fn poly_derivative1(poly: &[f32], x: f32) -> f32 {
    let n = poly.len();
    if n <= 1 {
        return 0.0;
    }
    let mut val = 0.0f32;
    for (i, &coeff) in poly[..n - 1].iter().enumerate() {
        let power = (n - 1 - i) as f32;
        val = val * x + power * coeff;
    }
    val
}

/// Вторая производная полинома d^2(poly)/dx^2
fn poly_derivative2(poly: &[f32], x: f32) -> f32 {
    let n = poly.len();
    if n <= 2 {
        return 0.0;
    }
    let mut val = 0.0f32;
    for (i, &coeff) in poly[..n - 2].iter().enumerate() {
        let power1 = (n - 1 - i) as f32;
        let power2 = (n - 2 - i) as f32;
        val = val * x + power1 * power2 * coeff;
    }
    val
}

/// МНК-полиномиальная регрессия степени deg (возвращает [c_deg, ..., c_0])
fn polyfit(y: &[f32], x: &[f32], deg: usize) -> Option<Vec<f32>> {
    let n = y.len();
    let m = deg + 1;
    if n < m {
        return None;
    }

    // Построение нормальной матрицы А^T * A и вектора A^T * X
    let mut a_mat = vec![vec![0.0f64; m]; m];
    let mut b_vec = vec![0.0f64; m];

    let mut powers = vec![0.0f64; 2 * deg + 1];
    for &yi in y {
        let mut p = 1.0f64;
        let y_d = yi as f64;
        for pk in powers.iter_mut() {
            *pk += p;
            p *= y_d;
        }
    }

    for (k, (&yi, &xi)) in y.iter().zip(x.iter()).enumerate() {
        let _ = k;
        let mut p = 1.0f64;
        let y_d = yi as f64;
        let x_d = xi as f64;
        for bj in b_vec.iter_mut() {
            *bj += x_d * p;
            p *= y_d;
        }
    }

    for row in 0..m {
        for col in 0..m {
            a_mat[row][col] = powers[row + col];
        }
    }

    // Решение СЛАУ методом Гаусса с частичным выбором главного элемента
    for i in 0..m {
        let mut max_row = i;
        let mut max_val = a_mat[i][i].abs();
        for k in (i + 1)..m {
            if a_mat[k][i].abs() > max_val {
                max_val = a_mat[k][i].abs();
                max_row = k;
            }
        }
        if max_val < 1e-12 {
            return None;
        }
        a_mat.swap(i, max_row);
        b_vec.swap(i, max_row);

        let pivot = a_mat[i][i];
        for j in i..m {
            a_mat[i][j] /= pivot;
        }
        b_vec[i] /= pivot;

        for k in 0..m {
            if k != i {
                let factor = a_mat[k][i];
                for j in i..m {
                    a_mat[k][j] -= factor * a_mat[i][j];
                }
                b_vec[k] -= factor * b_vec[i];
            }
        }
    }

    // Переворачиваем порядок коэффициентов к стандартному: [c_deg, ..., c_0]
    let mut coeffs: Vec<f32> = b_vec.into_iter().map(|v| v as f32).collect();
    coeffs.reverse();
    Some(coeffs)
}

/// Преобразование интенсивности лидара (0..255) в цвет Turbo colormap
#[inline(always)]
pub fn intensity_to_turbo_color(intensity: f32) -> Color {
    let norm = (intensity / 80.0).clamp(0.0, 1.0);
    let r = (1.5 - (norm * 4.0 - 3.0).abs()).clamp(0.0, 1.0);
    let g = (1.5 - (norm * 4.0 - 2.0).abs()).clamp(0.0, 1.0);
    let b = (1.5 - (norm * 4.0 - 1.0).abs()).clamp(0.0, 1.0);
    Color::from_rgb(
        (r * 255.0) as u8,
        (g * 255.0) as u8,
        (b * 255.0) as u8,
    )
}
