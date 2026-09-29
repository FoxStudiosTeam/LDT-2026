## !/usr/bin/env python3
import sys
print("Interpreter used by main.py:", sys.executable)

import argparse
import glob
import os
import sys
import time
import numpy as np
import rerun as rr

try:
    import matplotlib.pyplot as plt
    HAVE_MPL = True
except ImportError:
    HAVE_MPL = False


def intensity_to_rgb(intensity: np.ndarray, colormap: str = "turbo") -> np.ndarray:
    """
    Преобразует массив интенсивностей [0.0, 1.0] в массив RGB-цветов (uint8)
    с использованием непрерывной градиентной палитры Turbo.
    """
    intensity_clamped = np.clip(intensity / 255, 0.0, 1.0)
    
    cmap = plt.get_cmap('turbo')
    
    rgba_colors = cmap(intensity_clamped)
    
    rgb_colors = (rgba_colors[:, :3] * 255).astype(np.uint8)
    
    return rgb_colors


def compute_range_and_intensity_maps(
    xyz: np.ndarray,
    intensity: np.ndarray,
    height: int = 180,
    width: int = 500,
    fov_up_deg: float = 15.5,
    fov_down_deg: float = -25.5,
    fov_h_deg: float = 104.0,
    max_depth_m: float = 200.0,
    max_intensity: float = 80.0,
) -> tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    """
    Projects 3D LiDAR point cloud into 2D spherical depth and intensity maps.
    Sorts points by descending distance so closer points naturally occlude/overwrite
    farther points for both depth and intensity channels simultaneously.

    Returns:
      (depth_norm, raw_depth, intensity_norm, raw_intensity):
        - depth_norm: (H, W) float32 in [0.0, 1.0] (0m -> 0.0, 200m -> 1.0)
        - raw_depth: (H, W) float32 in meters (0.0 = no return)
        - intensity_norm: (H, W) float32 in [0.0, 1.0] (0..80 -> 0.0..1.0)
        - raw_intensity: (H, W) float32 raw reflection values
    """
    x = xyz[:, 0]
    y = xyz[:, 1]
    z = xyz[:, 2]

    fwd = -y
    dist = np.sqrt(x**2 + y**2 + z**2)

    valid = (fwd > 0.5) & (dist > 0.5)
    xv = x[valid]
    zv = z[valid]
    dv = dist[valid]
    fwd_v = fwd[valid]
    iv = intensity[valid]

    yaw = np.arctan2(xv, fwd_v)
    pitch = np.arcsin(np.clip(zv / dv, -1.0, 1.0))

    pitch_min, pitch_max = np.radians(fov_down_deg), np.radians(fov_up_deg)
    half_h = np.radians(fov_h_deg / 2.0)
    yaw_min, yaw_max = -half_h, half_h

    row = ((pitch_max - pitch) / (pitch_max - pitch_min) * height).astype(int)
    col = ((yaw - yaw_min) / (yaw_max - yaw_min) * width).astype(int)

    grid_mask = (row >= 0) & (row < height) & (col >= 0) & (col < width)
    r_val = row[grid_mask]
    c_val = col[grid_mask]
    d_val = dv[grid_mask]
    i_val = iv[grid_mask]

    # Сортировка по убыванию расстояния: более близкие точки записываются последними
    order = np.argsort(-d_val)

    raw_depth = np.zeros((height, width), dtype=np.float32)
    raw_intensity = np.zeros((height, width), dtype=np.float32)

    raw_depth[r_val[order], c_val[order]] = d_val[order]
    raw_intensity[r_val[order], c_val[order]] = i_val[order]

    depth_norm = np.clip(raw_depth / max_depth_m, 0.0, 1.0)
    intensity_norm = np.clip(raw_intensity / max_intensity, 0.0, 1.0)

    return depth_norm, raw_depth, intensity_norm, raw_intensity


# Backwards compatibility alias
compute_depth_map = compute_range_and_intensity_maps


def create_depth_intensity_composite(depth_norm: np.ndarray, intensity_norm: np.ndarray) -> np.ndarray:
    """
    Creates false-color 2-channel composite image:
      - Red channel: depth_norm (0m -> 0, 200m -> 255)
      - Green channel: 0
      - Blue channel: intensity_norm (0 -> 0, max_intensity -> 255)
    Empty pixels (no return) remain black [0, 0, 0].
    """
    h, w = depth_norm.shape
    composite = np.zeros((h, w, 3), dtype=np.uint8)
    composite[:, :, 0] = (depth_norm * 255.0).astype(np.uint8)       # Red: Depth
    composite[:, :, 1] = 0                                            # Green: 0
    composite[:, :, 2] = (intensity_norm * 255.0).astype(np.uint8)   # Blue: Intensity
    return composite


def depth_to_rgb(depth_norm: np.ndarray, colormap: str = "turbo") -> np.ndarray:
    """
    Maps normalized depth [0.0, 1.0] (0m..200m) to RGB image [0, 255] uint8.
    0.0 represents empty / no return and is mapped to black [0, 0, 0].
    """
    if HAVE_MPL:
        cmap = plt.get_cmap(colormap)
        rgba = cmap(depth_norm)
        rgb = (rgba[:, :, :3] * 255.0).astype(np.uint8)
    else:
        # Fallback Turbo-like colormap
        r = np.clip(1.5 - np.abs(depth_norm * 4.0 - 3.0), 0.0, 1.0)
        g = np.clip(1.5 - np.abs(depth_norm * 4.0 - 2.0), 0.0, 1.0)
        b = np.clip(1.5 - np.abs(depth_norm * 4.0 - 1.0), 0.0, 1.0)
        rgb = (np.stack([r, g, b], axis=-1) * 255.0).astype(np.uint8)

    # 0.0 = нет отражения (фон / пустота -> черный цвет)
    rgb[depth_norm <= 0.0] = 0
    return rgb


def ransac_3d_rails(
    xyz: np.ndarray,
    intensity: np.ndarray,
    n_iters: int = 400,
    inlier_thresh: float = 0.085,
    gauge_nominal: float = 1.575,
    gauge_tol: float = 0.075,
    extrapolate_m: float = 25.0,
) -> dict | None:
    """
    3D RANSAC for dual-rail track trajectory detection:
      - Uses dense near-zone seeds with intensity == 0 (specular reflection on rail head)
        for Y > -10.0m as high-confidence initial direction guides.
      - Enforces strict dual-rail pairing: left and right rails move strictly together
        with constant physical gauge (1.52..1.62m).
      - Scores inliers along the full corridor up to 45m ahead, giving higher weight
        to zero-intensity returns.
      - Refines 3D polynomial trajectory (cubic clothoid curve in X, elevation in Z).
      - Extrapolates curve forward 'по накатанной' (constant-curvature C2 continuation)
        by extrapolate_m meters beyond the last detected point.
    """
    # 1. Выделяем надежные якоря в ближней зоне (Y > -10м) с intensity == 0
    near_mask = (
        (intensity == 0)
        & (xyz[:, 1] > -10.0)
        & (xyz[:, 1] < -1.8)
        & (np.abs(xyz[:, 0]) < 2.5)
        & (xyz[:, 2] > -1.6)
        & (xyz[:, 2] < -0.6)
    )
    pts_seed = xyz[near_mask]
    if len(pts_seed) < 20:
        return None

    left_seeds = pts_seed[pts_seed[:, 0] < 0]
    right_seeds = pts_seed[pts_seed[:, 0] > 0]
    if len(left_seeds) < 10 or len(right_seeds) < 10:
        return None

    # Пул кандидатов для скоринга: коридор пути до 45м вперед
    pool_mask = (
        (np.abs(xyz[:, 0]) < 4.0)
        & (xyz[:, 1] < -1.8)
        & (xyz[:, 1] > -45.0)
        & (xyz[:, 2] > -1.7)
        & (xyz[:, 2] < -0.4)
    )
    pts_pool = xyz[pool_mask]
    int_pool = intensity[pool_mask]
    xp, yp, zp = pts_pool[:, 0], pts_pool[:, 1], pts_pool[:, 2]

    # Вес точек: зеркальные отражения рельсов (intensity == 0) весят в 3 раза больше
    weights = np.where(int_pool == 0, 3.0, 1.0)

    # Кандидаты в дальней зоне (y < -12м) для генерации криволинейных гипотез
    dist_mask = (yp < -12.0) & (yp > -35.0)
    pts_dist = pts_pool[dist_mask]
    int_dist = int_pool[dist_mask]
    dist_zero = pts_dist[int_dist == 0]
    dist_left = dist_zero[dist_zero[:, 0] < 0]
    dist_right = dist_zero[dist_zero[:, 0] > 0]

    rng = np.random.default_rng(42)
    best_score = -1.0
    best_inl = None
    best_gauge = gauge_nominal

    for _ in range(n_iters):
        # 1. Выбираем ближнюю пару рельс (Y > -10м)
        p_l1 = left_seeds[rng.integers(len(left_seeds))]
        cands_r1 = right_seeds[np.abs(right_seeds[:, 1] - p_l1[1]) < 0.8]
        if len(cands_r1) == 0:
            continue
        p_r1 = cands_r1[rng.integers(len(cands_r1))]
        g1 = p_r1[0] - p_l1[0]
        if abs(g1 - gauge_nominal) > gauge_tol or abs(p_r1[2] - p_l1[2]) > 0.08:
            continue

        # 2. Выбираем вторую пару рельс на расстоянии не менее 1.5м
        far_l = left_seeds[left_seeds[:, 1] < p_l1[1] - 1.5]
        if len(far_l) == 0:
            far_l = left_seeds[left_seeds[:, 1] > p_l1[1] + 1.5]
        if len(far_l) == 0:
            continue
        p_l2 = far_l[rng.integers(len(far_l))]

        cands_r2 = right_seeds[np.abs(right_seeds[:, 1] - p_l2[1]) < 0.8]
        if len(cands_r2) == 0:
            continue
        p_r2 = cands_r2[rng.integers(len(cands_r2))]
        g2 = p_r2[0] - p_l2[0]
        if abs(g2 - gauge_nominal) > gauge_tol or abs(p_r2[2] - p_l2[2]) > 0.08:
            continue

        c1 = 0.5 * (p_l1 + p_r1)
        c2 = 0.5 * (p_l2 + p_r2)
        gauge = 0.5 * (g1 + g2)

        # 3. Формируем гипотезу кривизны пути (парабола через 3 точки или сэмплирование кривизны)
        has_distant = len(dist_left) > 0 and len(dist_right) > 0 and (rng.random() < 0.75)
        if has_distant:
            p_l3 = dist_left[rng.integers(len(dist_left))]
            cands_r3 = dist_right[np.abs(dist_right[:, 1] - p_l3[1]) < 1.0]
            if len(cands_r3) > 0:
                p_r3 = cands_r3[rng.integers(len(cands_r3))]
                g3 = p_r3[0] - p_l3[0]
                if abs(g3 - gauge_nominal) < (gauge_tol + 0.05):
                    c3 = 0.5 * (p_l3 + p_r3)
                    ys_sample = np.array([c1[1], c2[1], c3[1]])
                    xs_sample = np.array([c1[0], c2[0], c3[0]])
                    poly_c = np.polyfit(ys_sample, xs_sample, deg=2)
                else:
                    has_distant = False
            else:
                has_distant = False

        if not has_distant:
            dy = c2[1] - c1[1]
            k0 = (c2[0] - c1[0]) / dy
            # Сэмплируем допустимую железнодорожную кривизну (|a| <= 0.003, R >= 160м)
            a = rng.uniform(-0.0030, 0.0030)
            c2_coeff = a
            c1_coeff = k0 - 2.0 * a * c1[1]
            c0_coeff = c1[0] - k0 * c1[1] + a * (c1[1] ** 2)
            poly_c = np.array([c2_coeff, c1_coeff, c0_coeff])

        # Ограничение физической кривизны ж/д путей (минимальный радиус R >= 120м -> |c2| <= 0.0042)
        if abs(poly_c[0]) > 0.0042:
            continue

        # Линия профиля высоты Z по точкам c1 и c2
        kz = (c2[2] - c1[2]) / (c2[1] - c1[1])
        bz = c1[2] - kz * c1[1]

        half_w = gauge / 2.0
        xc = np.polyval(poly_c, yp)
        zc = kz * yp + bz

        dist_l = np.sqrt((xp - (xc - half_w)) ** 2 + (zp - zc) ** 2)
        dist_r = np.sqrt((xp - (xc + half_w)) ** 2 + (zp - zc) ** 2)

        inl_l = dist_l < inlier_thresh
        inl_r = dist_r < inlier_thresh

        # Проверяем наличие поддержки в ближней зоне (якорь)
        nl_near = np.count_nonzero(inl_l & (yp > -10.0))
        nr_near = np.count_nonzero(inl_r & (yp > -10.0))
        if nl_near < 25 or nr_near < 25:
            continue

        score = float(np.sum(weights[inl_l]) + np.sum(weights[inl_r]))
        if score > best_score:
            best_score = score
            best_inl = (inl_l, inl_r)
            best_gauge = gauge

    if best_inl is None:
        return None

    inl_l, inl_r = best_inl
    half_w = best_gauge / 2.0

    # Аналитическое уточнение на ВСЕХ найденных инлаерах:
    # Кубический полином (deg=3) идеально соответствует переходной кривой (клотоиде) ж/д пути
    xc_samples = np.concatenate([xp[inl_l] + half_w, xp[inl_r] - half_w])
    yc_samples = np.concatenate([yp[inl_l], yp[inl_r]])
    zc_samples = np.concatenate([zp[inl_l], zp[inl_r]])

    y_min = max(float(min(yc_samples.min(), -16.0)), -45.0)
    deg = 3 if (len(yc_samples) > 200 and y_min < -18.0) else 2

    poly_x = np.polyfit(yc_samples, xc_samples, deg=deg)
    poly_z = np.polyfit(yc_samples, zc_samples, deg=1)

    actual_gauge = float(np.mean(xp[inl_r]) - np.mean(xp[inl_l]))
    refined_half_w = actual_gauge / 2.0

    # Формируем гладкие 3D траектории рельсов и осевой линии
    y_max = -2.0
    y_eval = np.linspace(y_max, y_min, int(np.ceil((y_max - y_min) / 0.25)))

    xc_eval = np.polyval(poly_x, y_eval)
    zc_eval = np.polyval(poly_z, y_eval)

    pts_left = np.column_stack([xc_eval - refined_half_w, y_eval, zc_eval])
    pts_right = np.column_stack([xc_eval + refined_half_w, y_eval, zc_eval])
    pts_center = np.column_stack([xc_eval, y_eval, zc_eval])

    # Генерация шпал (sleepers) с шагом 0.6м
    sleepers = []
    sleeper_ys = np.arange(y_max, y_min, -0.6)
    for sy in sleeper_ys:
        s_xc = float(np.polyval(poly_x, sy))
        s_zc = float(np.polyval(poly_z, sy))
        sleepers.append(
            np.array([
                [s_xc - refined_half_w - 0.2, sy, s_zc],
                [s_xc + refined_half_w + 0.2, sy, s_zc],
            ], dtype=np.float32)
        )

    # 4. Аналитическое продление "по накатанной" (C2-гладкое продолжение с установившейся кривизной)
    ext_pts_left = None
    ext_pts_right = None
    ext_pts_center = None
    ext_sleepers = []

    if extrapolate_m > 0.0:
        y0 = y_min
        x0 = float(np.polyval(poly_x, y0))
        z0 = float(np.polyval(poly_z, y0))

        # Первая производная (тангенс курса) и вторая производная (кривизна) в конечной точке детекции
        der1 = np.polyder(poly_x, 1)
        der2 = np.polyder(poly_x, 2)
        k0 = float(np.polyval(der1, y0))
        curv0 = float(np.polyval(der2, y0))
        # Ограничение физической кривизны ж/д пути (минимальный радиус круговой кривой R >= 140м)
        curv0 = float(np.clip(curv0, -0.0035, 0.0035))
        hz = float(poly_z[0]) if len(poly_z) > 1 else 0.0

        s_steps = int(np.ceil(extrapolate_m / 0.25))
        s_eval = np.linspace(0.25, extrapolate_m, s_steps)

        # Движение вперед по расстоянию s: y(s) = y0 - s
        # Поперечное смещение "по накатанной": x(s) = x0 - k0 * s + 0.5 * curv0 * s^2
        y_ext = y0 - s_eval
        x_ext = x0 - k0 * s_eval + 0.5 * curv0 * (s_eval ** 2)
        z_ext = z0 - hz * s_eval

        ext_pts_left = np.column_stack([x_ext - refined_half_w, y_ext, z_ext])
        ext_pts_right = np.column_stack([x_ext + refined_half_w, y_ext, z_ext])
        ext_pts_center = np.column_stack([x_ext, y_ext, z_ext])

        # Шпалы на продленном участке
        ext_sleeper_s = np.arange(0.6, extrapolate_m, 0.6)
        for es in ext_sleeper_s:
            e_y = y0 - es
            e_x = x0 - k0 * es + 0.5 * curv0 * (es ** 2)
            e_z = z0 - hz * es
            ext_sleepers.append(
                np.array([
                    [e_x - refined_half_w - 0.2, e_y, e_z],
                    [e_x + refined_half_w + 0.2, e_y, e_z],
                ], dtype=np.float32)
            )

    return {
        "poly_x": poly_x,
        "poly_z": poly_z,
        "gauge": actual_gauge,
        "inliers_left": pts_pool[inl_l],
        "inliers_right": pts_pool[inl_r],
        "seeds_near": pts_seed,
        "pts_left": pts_left,
        "pts_right": pts_right,
        "pts_center": pts_center,
        "sleepers": sleepers,
        "ext_pts_left": ext_pts_left,
        "ext_pts_right": ext_pts_right,
        "ext_pts_center": ext_pts_center,
        "ext_sleepers": ext_sleepers,
        "extrapolate_m": extrapolate_m,
        "y_range": (y_min, y_max),
    }


def load_snapshot(file_path: str):
    """
    Loads a point cloud snapshot from a .npz file.
    Returns (xyz, intensity, timestamp_ns, metadata_dict).
    """
    data = np.load(file_path)
    xyz = data["xyz"]
    intensity = data["intensity"]
    ts = int(data["timestamp_ns"]) if "timestamp_ns" in data else 0
    meta = {
        "file": os.path.basename(file_path),
        "total_raw_points": int(data["total_raw_points"]) if "total_raw_points" in data else len(xyz),
        "valid_points_count": int(data["valid_points_count"]) if "valid_points_count" in data else len(xyz),
    }
    return xyz, intensity, ts, meta


def log_frame(
    xyz: np.ndarray,
    intensity: np.ndarray,
    ts: int,
    meta: dict,
    frame_idx: int,
    extrapolate_m: float = 25.0,
):
    # 1. Timeline indexing
    if ts > 0:
        rr.set_time("ros_time", timestamp=np.datetime64(ts, "ns"))
    rr.set_time("frame", sequence=frame_idx)

    # 2. Colorize points by intensity
    colors = intensity_to_rgb(intensity, colormap="turbo")

    # 3. Log 3D point cloud
    rr.log(
        "lidar/points",
        rr.Points3D(
            positions=xyz,
            colors=colors,
            radii=0.03, # 3cm physical radius in 3D world
        )
    )

    # 4. Compute 2D spherical projections for depth & intensity
    depth_norm, raw_depth, intensity_norm, raw_intensity = compute_range_and_intensity_maps(
        xyz, intensity, max_depth_m=200.0, max_intensity=80.0
    )

    # Вьюпорт 1а: Карта глубины (числовой тензор [0.0, 1.0])
    # rr.log("lidar/depth_image", rr.DepthImage(depth_norm))

    # Вьюпорт 1б: Карта глубины (Turbo colormap, 0..200м)
    depth_colored = depth_to_rgb(depth_norm, colormap="turbo")
    rr.log("lidar/depth_colored", rr.Image(depth_colored))

    # Вьюпорт 2: Карта intensity (2D изображение интенсивности)
    # intensity_img = (intensity_norm * 255.0).astype(np.uint8)
    # rr.log("lidar/intensity_map", rr.Image(intensity_img))

    rr.log("lidar/intensity_raw", rr.Image((raw_intensity).astype(np.uint8)))
    # Вьюпорт 3: Скомбинированная intensity (синий канал) + depth (красный канал)
    # composite_img = create_depth_intensity_composite(depth_norm, intensity_norm)
    # rr.log("lidar/depth_intensity_composite", rr.Image(composite_img))

    # 5. 3D RANSAC определение пути железнодорожных путей
    rail_res = ransac_3d_rails(xyz, intensity, extrapolate_m=extrapolate_m)
    rail_telemetry = "Rails: Not detected"
    if rail_res is not None:
        # Непрерывные 3D линии рельсов и оси пути (подтвержденный точками участок)
        rr.log("rails/left_track", rr.LineStrips3D([rail_res["pts_left"]], colors=[0, 255, 100], radii=0.035))
        rr.log("rails/right_track", rr.LineStrips3D([rail_res["pts_right"]], colors=[0, 210, 255], radii=0.035))
        rr.log("rails/centerline", rr.LineStrips3D([rail_res["pts_center"]], colors=[255, 255, 255], radii=0.015))

        # Шпалы на подтвержденном участке
        if rail_res["sleepers"]:
            rr.log("rails/sleepers", rr.LineStrips3D(rail_res["sleepers"], colors=[190, 160, 110], radii=0.018))

        # Аналитически продленный участок "по накатанной"
        if rail_res["ext_pts_left"] is not None:
            rr.log("rails/extrapolated/left_track", rr.LineStrips3D([rail_res["ext_pts_left"]], colors=[255, 190, 40], radii=0.028))
            rr.log("rails/extrapolated/right_track", rr.LineStrips3D([rail_res["ext_pts_right"]], colors=[255, 190, 40], radii=0.028))
            rr.log("rails/extrapolated/centerline", rr.LineStrips3D([rail_res["ext_pts_center"]], colors=[255, 220, 120], radii=0.012))
            if rail_res["ext_sleepers"]:
                rr.log("rails/extrapolated/sleepers", rr.LineStrips3D(rail_res["ext_sleepers"], colors=[170, 140, 80], radii=0.015))

        # Найденные инлаеры рельсов и зерновые точки
        rr.log("rails/inliers_left", rr.Points3D(rail_res["inliers_left"], colors=[0, 255, 100], radii=0.03))
        rr.log("rails/inliers_right", rr.Points3D(rail_res["inliers_right"], colors=[0, 210, 255], radii=0.03))
        rr.log("rails/seeds_near_zero_intensity", rr.Points3D(rail_res["seeds_near"], colors=[255, 230, 0], radii=0.04))

        det_range = -rail_res["y_range"][0] - (-rail_res["y_range"][1])
        total_range = -rail_res["y_range"][0] + rail_res["extrapolate_m"]
        rail_telemetry = (
            f"Rails: Gauge={rail_res['gauge']:.3f}m | "
            f"Detected={-rail_res['y_range'][1]:.1f}m..{-rail_res['y_range'][0]:.1f}m ({det_range:.1f}m) | "
            f"Extrapolated=+{rail_res['extrapolate_m']:.1f}m (Total: {total_range:.1f}m) | "
            f"Inliers: L={len(rail_res['inliers_left'])}, R={len(rail_res['inliers_right'])}"
        )

    # 6. Log text telemetry
    valid_d = raw_depth[raw_depth > 0]
    depth_str = (
        f"Depth: min={valid_d.min():.1f}m, max={valid_d.max():.1f}m "
        f"(normalized 0..200m: min={valid_d.min()/200.0:.3f}, max={valid_d.max()/200.0:.3f})"
        if len(valid_d) > 0 else "Depth: N/A"
    )
    info_text = (
        f"File: {meta['file']} | Frame: {frame_idx}\n"
        f"Timestamp: {ts} ns\n"
        f"Points: {len(xyz):,} valid (raw: {meta['total_raw_points']:,})\n"
        f"Intensity: min={intensity.min():.1f}, max={intensity.max():.1f}, "
        f"mean={intensity.mean():.1f}, median={np.median(intensity):.1f}\n"
        f"{depth_str}\n"
        f"{rail_telemetry}"
    )
    rr.log("telemetry/summary", rr.TextLog(info_text))


def main():
    parser = argparse.ArgumentParser(description="Visualize nextgen pointcloud snapshots in Rerun")
    parser.add_argument("--dir", default=os.path.join(os.path.dirname(__file__), "frames"), help="Directory with .npz frames")
    parser.add_argument("--file", default=None, help="Path to a single .npz snapshot file")
    parser.add_argument("--connect", default=None, help="Rerun connect URL (e.g. rerun+http://127.0.0.1:9876/proxy)")
    parser.add_argument("--spawn", action="store_true", help="Spawn local Rerun viewer window")
    parser.add_argument("--fps", type=float, default=2.0, help="Playback FPS (default: 2.0)")
    parser.add_argument("--loop", action="store_true", help="Loop playback continuously")
    parser.add_argument(
        "--extrapolate",
        type=float,
        default=25.0,
        help="Analytical track extrapolation distance in meters 'по накатанной' (default: 25.0m, 0 to disable)",
    )
    args = parser.parse_args()

    # Determine files to visualize
    if args.file:
        if not os.path.exists(args.file):
            print(f"Error: File not found: {args.file}")
            sys.exit(1)
        files = [args.file]
    else:
        pattern = os.path.join(args.dir, "frame_*.npz")
        files = sorted(glob.glob(pattern))
        if not files:
            print(f"Error: No frame_*.npz files found in {args.dir}")
            sys.exit(1)

    print("============================================================")
    print("  NextGen Point Cloud & Intensity Rerun Viewer")
    print("============================================================")
    print(f"Found frames:    {len(files)}")
    print(f"Frames source:   {os.path.abspath(args.dir) if not args.file else args.file}")

    # Initialize Rerun Recording
    rr.init("nextgen_pointcloud_viewer", spawn=args.spawn)

    if not args.spawn:
        url = args.connect or os.environ.get("RERUN_URL", "rerun+http://127.0.0.1:9876/proxy")
        print(f"Connecting to Rerun at: {url} ...")
        try:
            rr.connect_grpc(url)
            print("Connected to Rerun server!")
        except Exception as e:
            print(f"Could not connect to {url}: {e}")
            print("Spawning local Rerun viewer instead...")
            rr.spawn()

    delay = 1.0 / max(args.fps, 0.1)

    try:
        while True:
            for idx, fpath in enumerate(files):
                xyz, intensity, ts, meta = load_snapshot(fpath)
                log_frame(xyz, intensity, ts, meta, idx, extrapolate_m=args.extrapolate)
                print(f"[{idx+1}/{len(files)}] Logged {meta['file']} ({len(xyz):,} pts, ts: {ts})")
                if len(files) > 1 and delay > 0:
                    time.sleep(delay)
            if not args.loop or len(files) <= 1:
                break
    except KeyboardInterrupt:
        print("\nViewer stopped by user.")

    print("------------------------------------------------------------")
    print("[DONE] Finished streaming snapshots to Rerun.")
    print("============================================================")


if __name__ == "__main__":
    main()
