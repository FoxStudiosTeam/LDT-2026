//! rail_curve.rs — 3D RANSAC Rail Track Detector & Curve Extrapolator
//!
//! Features:
//! 1. Specular reflection anchor seeds (`intensity == 0` for Y in near zone [-10.0, -1.8]m).
//! 2. Rigid dual-rail pre-pairing (gauge constraint 1.50..1.65m, equal height).
//! 3. Curvature-aware 3D RANSAC with zero inner-loop allocations and squared distances.
//! 4. Straightness metric (`straightness` in [0.0, 1.0]) that dampens curvature
//!    during extrapolation on straight tracks, preventing unnatural bending.
//! 5. Analytical C2-smooth extrapolation "по накатанной".
//! 6. Temporal smoothing: rolling window of last N fits with exponential decay weighting
//!    for butter-smooth track transitions across frames.
//! 7. Native Rerun 3D visualization: rails, centerline, sleepers, inliers, and telemetry.

use rerun::{Color, LineStrips3D, Points3D, Radius, RecordingStream};
use shared::error::{AppError, ErrCtx};
use std::collections::VecDeque;

/// Параметры конфигурации детектора кривых пути
#[derive(Clone, Debug)]
pub struct RailCurveConfig {
    /// Число итераций RANSAC (по умолчанию: 250)
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
    /// Число последних кадров/фитов для сглаживания (по умолчанию: 5, 1 = без сглаживания)
    pub history_size: usize,
    /// Фактор экспоненциального затухания для истории (по умолчанию: 0.70, 1.0 = равные веса)
    pub smoothing_decay: f32,
    /// Максимальное число кадров удержания кривой (coasting) при кратковременной потере детекции (по умолчанию: 2)
    pub max_coasting_frames: usize,
}

impl Default for RailCurveConfig {
    fn default() -> Self {
        Self {
            n_iters: 250,
            inlier_thresh: 0.085,
            gauge_nominal: 1.575,
            gauge_tol: 0.075,
            max_extrapolate_m: 25.0,
            near_y_min: -10.0,
            near_y_max: -1.8,
            max_y: -45.0,
            straightness_deflection_threshold_m: 0.35,
            sleeper_spacing_m: 0.6,
            history_size: 1,
            smoothing_decay: 0.70,
            max_coasting_frames: 2,
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
    /// Сколько последних фитов было смешано для сглаживания
    pub smoothed_frames_count: usize,
    /// Флаг удержания траектории при кратковременной потере (coasting)
    pub is_coasting: bool,

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
        let coasting_str = if self.is_coasting { " [COASTING]" } else { "" };
        let det_len = -self.y_range.0 - (-self.y_range.1);
        let info_text = format!(
            "Gauge: {:.3}m | Straightness: {:.1}% | Radius: {} | Smooth: {} frames{} | Deflection: {:.3}m\n\
             Detected range: {:.1}m..{:.1}m (len: {:.1}m) | Extrapolated: +{:.1}m (Total: {:.1}m)\n\
             Inliers: Left={}, Right={}",
            self.gauge,
            self.straightness * 100.0,
            radius_str,
            self.smoothed_frames_count,
            coasting_str,
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

/// Элемент истории для временного сглаживания
#[derive(Clone, Debug)]
struct RailFitHistoryItem {
    poly_x_deg3: [f32; 4],
    poly_z: [f32; 2],
    gauge: f32,
    straightness: f32,
    max_deflection: f32,
    y_min: f32,
    y_max: f32,
}

/// Сырой результат фита текущего кадра
struct RawFit {
    poly_x_deg3: [f32; 4],
    poly_z: [f32; 2],
    gauge: f32,
    straightness: f32,
    max_deflection: f32,
    y_min: f32,
    y_max: f32,
    inliers_left: Vec<[f32; 3]>,
    inliers_right: Vec<[f32; 3]>,
    seeds_near: Vec<[f32; 3]>,
}

/// Вычислитель кривых железнодорожных путей с поддержкой сглаживания по N кадрам
#[derive(Clone, Debug)]
pub struct RailCurveEstimator {
    pub config: RailCurveConfig,
    history: VecDeque<RailFitHistoryItem>,
    lost_frames: usize,
    last_inliers_l: Vec<[f32; 3]>,
    last_inliers_r: Vec<[f32; 3]>,
    last_seeds: Vec<[f32; 3]>,
}

#[derive(Clone, Copy)]
struct SeedPair {
    c: [f32; 3],
    gauge: f32,
    y: f32,
}

impl RailCurveEstimator {
    pub fn new(config: RailCurveConfig) -> Self {
        Self {
            config,
            history: VecDeque::new(),
            lost_frames: 0,
            last_inliers_l: Vec::new(),
            last_inliers_r: Vec::new(),
            last_seeds: Vec::new(),
        }
    }

    /// Сброс истории сглаживания (например, при смене сцены или длинном пропуске)
    pub fn reset(&mut self) {
        self.history.clear();
        self.lost_frames = 0;
        self.last_inliers_l.clear();
        self.last_inliers_r.clear();
        self.last_seeds.clear();
    }

    /// Рассчитывает 3D модель кривой пути по облаку точек и интенсивности
    /// со сглаживанием по последним N кадрам.
    pub fn fit(&mut self, points: &[[f32; 3]], intensities: &[f32]) -> Option<RailCurveResult> {
        let raw_opt = self.fit_raw(points, intensities);

        match raw_opt {
            Some(raw) => {
                self.lost_frames = 0;
                self.last_inliers_l = raw.inliers_left.clone();
                self.last_inliers_r = raw.inliers_right.clone();
                self.last_seeds = raw.seeds_near.clone();

                self.history.push_back(RailFitHistoryItem {
                    poly_x_deg3: raw.poly_x_deg3,
                    poly_z: raw.poly_z,
                    gauge: raw.gauge,
                    straightness: raw.straightness,
                    max_deflection: raw.max_deflection,
                    y_min: raw.y_min,
                    y_max: raw.y_max,
                });

                let max_h = self.config.history_size.max(1);
                while self.history.len() > max_h {
                    self.history.pop_front();
                }

                self.build_smoothed_result(
                    false,
                    raw.inliers_left,
                    raw.inliers_right,
                    raw.seeds_near,
                )
            }
            None => {
                self.lost_frames += 1;
                if self.lost_frames <= self.config.max_coasting_frames && !self.history.is_empty() {
                    // Coasting: используем последнее сглаженное состояние
                    self.build_smoothed_result(
                        true,
                        self.last_inliers_l.clone(),
                        self.last_inliers_r.clone(),
                        self.last_seeds.clone(),
                    )
                } else {
                    if self.lost_frames > self.config.max_coasting_frames {
                        self.history.clear();
                    }
                    None
                }
            }
        }
    }

    /// Смешивает историю последних N фитов и генерирует итоговую 3D геометрию
    fn build_smoothed_result(
        &self,
        is_coasting: bool,
        inliers_left: Vec<[f32; 3]>,
        inliers_right: Vec<[f32; 3]>,
        seeds_near: Vec<[f32; 3]>,
    ) -> Option<RailCurveResult> {
        let k = self.history.len();
        if k == 0 {
            return None;
        }

        let decay = self.config.smoothing_decay.clamp(0.05, 1.0);
        let mut total_w = 0.0f32;
        let mut weights = Vec::with_capacity(k);
        for i in 0..k {
            // i = k - 1 (текущий кадр): exponent = 0 -> weight = 1.0
            // i = 0 (самый старый): exponent = k - 1 -> weight = decay^(k-1)
            let w = decay.powi((k - 1 - i) as i32);
            weights.push(w);
            total_w += w;
        }

        let mut poly_x_deg3 = [0.0f32; 4];
        let mut poly_z = [0.0f32; 2];
        let mut gauge = 0.0f32;
        let mut straightness = 0.0f32;
        let mut y_min = 0.0f32;
        let mut y_max = 0.0f32;
        let mut max_deflection = 0.0f32;

        for (i, item) in self.history.iter().enumerate() {
            let nw = weights[i] / total_w;
            for c in 0..4 {
                poly_x_deg3[c] += item.poly_x_deg3[c] * nw;
            }
            for h in 0..2 {
                poly_z[h] += item.poly_z[h] * nw;
            }
            gauge += item.gauge * nw;
            straightness += item.straightness * nw;
            y_min += item.y_min * nw;
            y_max += item.y_max * nw;
            max_deflection += item.max_deflection * nw;
        }

        let poly_x = if poly_x_deg3[0].abs() < 1e-7 {
            vec![poly_x_deg3[1], poly_x_deg3[2], poly_x_deg3[3]]
        } else {
            vec![
                poly_x_deg3[0],
                poly_x_deg3[1],
                poly_x_deg3[2],
                poly_x_deg3[3],
            ]
        };

        Some(build_geometry_result(
            &self.config,
            poly_x,
            poly_z,
            gauge,
            straightness,
            max_deflection,
            y_min,
            y_max,
            k,
            is_coasting,
            inliers_left,
            inliers_right,
            seeds_near,
        ))
    }

    /// Быстрый RANSAC-расчет одного сырого кадра:
    /// - Zero allocations во внутреннем цикле скоринга
    /// - Предварительное спаривание сидов
    /// - Ранний отсев по Z и сравнение по квадрату расстояния (без sqrt)
    /// - Прореживание пула кандидатов до <= 2000 точек
    fn fit_raw(&self, points: &[[f32; 3]], intensities: &[f32]) -> Option<RawFit> {
        let n = points.len();
        if n < 50 || n != intensities.len() {
            return None;
        }

        let cfg = &self.config;

        // 1. Выделяем якоря в ближней зоне (intensity <= 0.5)
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

        if left_seeds.len() < 5 || right_seeds.len() < 5 {
            return None;
        }

        // 2. Предварительное спаривание сидов левого и правого рельса (O(N_L * N_R) < 2500)
        let mut seed_pairs = Vec::new();
        for pl in &left_seeds {
            for pr in &right_seeds {
                if (pr[1] - pl[1]).abs() < 0.8 {
                    let g = pr[0] - pl[0];
                    if (g - cfg.gauge_nominal).abs() <= cfg.gauge_tol
                        && (pr[2] - pl[2]).abs() <= 0.08
                    {
                        seed_pairs.push(SeedPair {
                            c: [
                                0.5 * (pl[0] + pr[0]),
                                0.5 * (pl[1] + pr[1]),
                                0.5 * (pl[2] + pr[2]),
                            ],
                            gauge: g,
                            y: 0.5 * (pl[1] + pr[1]),
                        });
                    }
                }
            }
        }

        if seed_pairs.len() < 2 {
            return None;
        }

        // 3. Пул кандидатов для коридора пути
        let mut pool_indices = Vec::with_capacity(n / 4);
        for i in 0..n {
            let p = points[i];
            if p[0].abs() < 3.5
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
                if p[0] < 0.0 && p[0] > -3.0 {
                    dist_left.push(p);
                } else if p[0] > 0.0 && p[0] < 3.0 {
                    dist_right.push(p);
                }
            }
        }

        // Прореживание пула для быстрого RANSAC-скоринга (макс 2000 точек)
        let step = if pool_indices.len() > 2000 {
            pool_indices.len() / 2000
        } else {
            1
        };
        let scoring_indices: Vec<usize> = pool_indices.iter().step_by(step).copied().collect();

        // 4. Оптимизированный RANSAC без аллокаций
        let mut rng_state: u32 = 42;
        let mut next_rand = || -> u32 {
            rng_state ^= rng_state << 13;
            rng_state ^= rng_state >> 17;
            rng_state ^= rng_state << 5;
            rng_state
        };

        let mut best_score = -1.0f32;
        let mut best_poly_c = [0.0f32; 3];
        let mut best_kz = 0.0f32;
        let mut best_bz = 0.0f32;
        let mut best_gauge = cfg.gauge_nominal;

        let inlier_thresh2 = cfg.inlier_thresh * cfg.inlier_thresh;

        for _ in 0..cfg.n_iters {
            let pair1 = seed_pairs[next_rand() as usize % seed_pairs.len()];

            // Выбираем вторую пару на расстоянии >= 1.2м
            let mut pair2_opt = None;
            for _ in 0..8 {
                let cand = seed_pairs[next_rand() as usize % seed_pairs.len()];
                if (cand.y - pair1.y).abs() > 1.2 {
                    pair2_opt = Some(cand);
                    break;
                }
            }
            let pair2 = match pair2_opt {
                Some(p) => p,
                None => continue,
            };

            let c1 = pair1.c;
            let c2 = pair2.c;
            let gauge = 0.5 * (pair1.gauge + pair2.gauge);
            let half_w = gauge * 0.5;

            // Гипотеза параболы
            let mut poly_c: Option<[f32; 3]> = None;
            if !dist_left.is_empty() && !dist_right.is_empty() && (next_rand() % 100 < 70) {
                let pl3 = dist_left[next_rand() as usize % dist_left.len()];
                let pr3_opt = dist_right.iter().find(|pr| {
                    (pr[1] - pl3[1]).abs() < 0.8
                        && ((pr[0] - pl3[0]) - cfg.gauge_nominal).abs() < (cfg.gauge_tol + 0.06)
                });
                if let Some(pr3) = pr3_opt {
                    let c3 = [
                        0.5 * (pl3[0] + pr3[0]),
                        0.5 * (pl3[1] + pr3[1]),
                        0.5 * (pl3[2] + pr3[2]),
                    ];
                    poly_c = fit_parabola_3pts(c1[1], c1[0], c2[1], c2[0], c3[1], c3[0]);
                }
            }

            if poly_c.is_none() {
                let dy = c2[1] - c1[1];
                if dy.abs() < 1.0 {
                    continue;
                }
                let k0 = (c2[0] - c1[0]) / dy;
                let rand_f = (next_rand() % 10000) as f32 / 10000.0;
                let a = (rand_f * 2.0 - 1.0) * 0.0030;
                let c2_coeff = a;
                let c1_coeff = k0 - 2.0 * a * c1[1];
                let c0_coeff = c1[0] - k0 * c1[1] + a * c1[1] * c1[1];
                poly_c = Some([c2_coeff, c1_coeff, c0_coeff]);
            }

            let poly_c = poly_c.unwrap();
            if poly_c[0].abs() > 0.0042 {
                continue;
            }

            let dy_z = c2[1] - c1[1];
            if dy_z.abs() < 0.1 {
                continue;
            }
            let kz = (c2[2] - c1[2]) / dy_z;
            let bz = c1[2] - kz * c1[1];

            let mut score = 0.0f32;
            let mut near_count_l = 0usize;
            let mut near_count_r = 0usize;

            // Внутренний цикл: нулевые аллокации, ранний отсев по Z и сравнение без корней
            for &idx in &scoring_indices {
                let p = points[idx];
                let zc = kz * p[1] + bz;
                let dz = p[2] - zc;
                if dz.abs() >= cfg.inlier_thresh {
                    continue;
                }
                let dz2 = dz * dz;
                let xc = poly_c[0] * p[1] * p[1] + poly_c[1] * p[1] + poly_c[2];

                let dxl = p[0] - (xc - half_w);
                if dxl.abs() < cfg.inlier_thresh && (dxl * dxl + dz2) < inlier_thresh2 {
                    let weight = if intensities[idx] <= 0.5 { 3.0 } else { 1.0 };
                    score += weight;
                    if p[1] > -10.0 {
                        near_count_l += 1;
                    }
                } else {
                    let dxr = p[0] - (xc + half_w);
                    if dxr.abs() < cfg.inlier_thresh && (dxr * dxr + dz2) < inlier_thresh2 {
                        let weight = if intensities[idx] <= 0.5 { 3.0 } else { 1.0 };
                        score += weight;
                        if p[1] > -10.0 {
                            near_count_r += 1;
                        }
                    }
                }
            }

            if near_count_l < 15 || near_count_r < 15 {
                continue;
            }

            if score > best_score {
                best_score = score;
                best_poly_c = poly_c;
                best_kz = kz;
                best_bz = bz;
                best_gauge = gauge;
            }
        }

        if best_score < 0.0 {
            return None;
        }

        // 5. Единоразовый сбор всех инлаеров для победившей гипотезы
        let half_w = best_gauge * 0.5;
        let mut best_inl_l = Vec::with_capacity(pool_indices.len() / 6);
        let mut best_inl_r = Vec::with_capacity(pool_indices.len() / 6);

        for &idx in &pool_indices {
            let p = points[idx];
            let zc = best_kz * p[1] + best_bz;
            let dz = p[2] - zc;
            if dz.abs() >= cfg.inlier_thresh {
                continue;
            }
            let dz2 = dz * dz;
            let xc = best_poly_c[0] * p[1] * p[1] + best_poly_c[1] * p[1] + best_poly_c[2];

            let dxl = p[0] - (xc - half_w);
            if dxl.abs() < cfg.inlier_thresh && (dxl * dxl + dz2) < inlier_thresh2 {
                best_inl_l.push(p);
            } else {
                let dxr = p[0] - (xc + half_w);
                if dxr.abs() < cfg.inlier_thresh && (dxr * dxr + dz2) < inlier_thresh2 {
                    best_inl_r.push(p);
                }
            }
        }

        if best_inl_l.len() < 20 || best_inl_r.len() < 20 {
            return None;
        }

        // 6. Аналитическое МНК-уточнение полинома
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

        let deg = if sample_y.len() > 200 && y_min < -18.0 {
            3
        } else {
            2
        };
        let poly_x = polyfit(&sample_y, &sample_x, deg)?;
        let poly_z_vec = polyfit(&sample_y, &sample_z, 1)?;
        let poly_z = [poly_z_vec[0], poly_z_vec[1]];

        let poly_x_deg3 = match poly_x.len() {
            4 => [poly_x[0], poly_x[1], poly_x[2], poly_x[3]],
            3 => [0.0, poly_x[0], poly_x[1], poly_x[2]],
            2 => [0.0, 0.0, poly_x[0], poly_x[1]],
            _ => [0.0, 0.0, 0.0, poly_x[0]],
        };

        // 7. Расчет прямизны и максимального отклонения от хорды
        let y_max = -2.0f32;
        let x_start = polyval(&poly_x, y_max);
        let x_end = polyval(&poly_x, y_min);

        let mut max_deflection = 0.0f32;
        let test_steps = 40;
        for i in 0..=test_steps {
            let y_t = y_max + (y_min - y_max) * (i as f32 / test_steps as f32);
            let x_curve = polyval(&poly_x, y_t);
            let chord_t = (y_t - y_max) / (y_min - y_max);
            let x_chord = x_start + (x_end - x_start) * chord_t;
            let defl = (x_curve - x_chord).abs();
            if defl > max_deflection {
                max_deflection = defl;
            }
        }

        let straightness =
            (1.0 - (max_deflection / cfg.straightness_deflection_threshold_m)).clamp(0.0, 1.0);

        Some(RawFit {
            poly_x_deg3,
            poly_z,
            gauge: actual_gauge,
            straightness,
            max_deflection,
            y_min,
            y_max,
            inliers_left: best_inl_l,
            inliers_right: best_inl_r,
            seeds_near: seeds_all,
        })
    }
}

/// Собирает полную 3D геометрию (рельсы, шпалы, экстраполяция) по заданным параметрам пути
fn build_geometry_result(
    cfg: &RailCurveConfig,
    poly_x: Vec<f32>,
    poly_z: [f32; 2],
    gauge: f32,
    straightness: f32,
    max_deflection: f32,
    y_min: f32,
    y_max: f32,
    smoothed_frames_count: usize,
    is_coasting: bool,
    inliers_left: Vec<[f32; 3]>,
    inliers_right: Vec<[f32; 3]>,
    seeds_near: Vec<[f32; 3]>,
) -> RailCurveResult {
    let half_w = gauge * 0.5;

    // Радиус кривизны
    let arc_len = (y_max - y_min).abs();
    let curve_radius_m = if max_deflection > 0.025 {
        Some((arc_len * arc_len) / (8.0 * max_deflection))
    } else {
        None
    };

    // Точки подтвержденного участка с шагом 0.25м
    let n_steps = ((y_max - y_min).abs() / 0.25).ceil() as usize;
    let mut pts_left = Vec::with_capacity(n_steps + 1);
    let mut pts_right = Vec::with_capacity(n_steps + 1);
    let mut pts_center = Vec::with_capacity(n_steps + 1);

    for i in 0..=n_steps {
        let y_t = y_max - (i as f32 * 0.25).min((y_max - y_min).abs());
        let xc = polyval(&poly_x, y_t);
        let zc = poly_z[0] * y_t + poly_z[1];
        pts_left.push([xc - half_w, y_t, zc]);
        pts_right.push([xc + half_w, y_t, zc]);
        pts_center.push([xc, y_t, zc]);
    }

    // Шпалы
    let mut sleepers = Vec::new();
    let mut sy = y_max;
    while sy >= y_min {
        let s_xc = polyval(&poly_x, sy);
        let s_zc = poly_z[0] * sy + poly_z[1];
        sleepers.push([
            [s_xc - half_w - 0.2, sy, s_zc],
            [s_xc + half_w + 0.2, sy, s_zc],
        ]);
        sy -= cfg.sleeper_spacing_m;
    }

    // Экстраполяция "по накатанной" с демпфированием кривизны по прямизне
    let mut ext_pts_left = None;
    let mut ext_pts_right = None;
    let mut ext_pts_center = None;
    let mut ext_sleepers = Vec::new();

    if cfg.max_extrapolate_m > 0.0 {
        let y0 = y_min;
        let x0 = polyval(&poly_x, y0);
        let z0 = poly_z[0] * y0 + poly_z[1];

        let k0 = poly_derivative1(&poly_x, y0);
        let raw_curv0 = poly_derivative2(&poly_x, y0).clamp(-0.0035, 0.0035);
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

            ext_l.push([x_ext - half_w, y_ext, z_ext]);
            ext_r.push([x_ext + half_w, y_ext, z_ext]);
            ext_c.push([x_ext, y_ext, z_ext]);
        }

        let mut es = cfg.sleeper_spacing_m;
        while es <= cfg.max_extrapolate_m {
            let ey = y0 - es;
            let ex = x0 - k0 * es + 0.5 * effective_curv * es * es;
            let ez = z0 - poly_z[0] * es;
            ext_sleepers.push([[ex - half_w - 0.2, ey, ez], [ex + half_w + 0.2, ey, ez]]);
            es += cfg.sleeper_spacing_m;
        }

        ext_pts_left = Some(ext_l);
        ext_pts_right = Some(ext_r);
        ext_pts_center = Some(ext_c);
    }

    RailCurveResult {
        poly_x,
        poly_z,
        gauge,
        straightness,
        curve_radius_m,
        lateral_deflection_m: max_deflection,
        y_range: (y_min, y_max),
        extrapolate_m: cfg.max_extrapolate_m,
        smoothed_frames_count,
        is_coasting,
        pts_left,
        pts_right,
        pts_center,
        sleepers,
        ext_pts_left,
        ext_pts_right,
        ext_pts_center,
        ext_sleepers,
        inliers_left,
        inliers_right,
        seeds_near,
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
    let c0 =
        (y2 * y3 * (y2 - y3) * x1 + y3 * y1 * (y3 - y1) * x2 + y1 * y2 * (y1 - y2) * x3) / denom;
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

    for (&yi, &xi) in y.iter().zip(x.iter()) {
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
            a_mat[j][j] = a_mat[j][j]; // dummy to keep structure readable
        }
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
    Color::from_rgb((r * 255.0) as u8, (g * 255.0) as u8, (b * 255.0) as u8)
}
