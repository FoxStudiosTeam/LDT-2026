#!/usr/bin/env python3
"""
nextgen/src/rail_segment.py — Geometric Rail Ridge Segmentation & Ego-Track Extraction

Extracts the ego-track rail pair from BEV max-height profiles:
1. In each longitudinal X-slice (along direction of travel), identifies local height peaks in the lateral Y-profile
   within the physical rail head elevation range: Δz ≈ 0.17 .. 0.33 m.
2. Anchors ego-track in the near zone (X ≈ 3.5 .. 12.0 m) using:
   - Gauge constraint: gauge ≈ 1.520 m (tolerance ± 0.07 m)
   - Vehicle centering: track center near LiDAR center from ground_plane.py
3. Tracks ego-track smoothly forward along X:
   - Matches candidate pairs that maintain nominal 1.52m gauge and continue previous trajectory.
   - Robust to single-beam dropouts via rigid gauge constraint inference.
4. Distinguishes and separates "other tracks" (parallel tracks / turnouts on multi-track frames 4 & 5).
5. Visualizes in Rerun:
   - All candidate ridges (gray/red)
   - Left ego rail (bright green) and Right ego rail (bright cyan)
   - Rejected / other tracks (bright orange/yellow)

Usage:
    python nextgen/src/rail_segment.py --all
    python nextgen/src/rail_segment.py --frame 0 --visualize
    python nextgen/src/rail_segment.py --file nextgen/frames/frame_946685873633425951.npz --visualize
"""

import argparse
import glob
import os
import sys
from dataclasses import dataclass
from typing import Dict, List, Optional, Tuple

import numpy as np

# Add src folder to path
sys.path.insert(0, os.path.dirname(__file__))
from ground_plane import GroundPlaneResult, estimate_ground_plane
from bev_project import BEVFrame, BEVGrid, bev_to_raw_xyz, create_bev_transform, project_to_bev_grid

try:
    import rerun as rr
    HAVE_RERUN = True
except ImportError:
    HAVE_RERUN = False


@dataclass
class TrackedRailSlice:
    x_bev: float
    y_left_bev: float
    y_right_bev: float
    z_left_bev: float
    z_right_bev: float
    gauge_m: float
    center_y_bev: float
    is_inferred: bool   # True if one rail was reconstructed via gauge constraint
    raw_pt_left: np.ndarray   # (3,) raw LiDAR coordinates
    raw_pt_right: np.ndarray  # (3,) raw LiDAR coordinates


@dataclass
class RailSegmentationResult:
    frame_name: str
    tracked_slices: List[TrackedRailSlice]
    max_continuous_range_m: float  # Range reached without any dropout gap (> 1.2m)
    max_tracked_range_m: float     # Total longitudinal range tracked
    slices_count: int
    both_rails_detected_count: int
    single_rail_inferred_count: int
    mean_gauge_m: float
    std_gauge_m: float
    min_gauge_m: float
    max_gauge_m: float
    other_track_peaks_count: int   # Peaks classified as adjacent/foreign tracks
    rejected_noise_count: int      # Other rejected candidates
    all_candidate_ridges: List[Tuple[float, float, float]]  # (x, y, z) in BEV
    other_track_points: List[Tuple[float, float, float]]    # (x, y, z) in BEV
    grid: BEVGrid


def extract_candidate_ridges(
    grid: BEVGrid,
    z_min: float = 0.16,
    z_max: float = 0.34,
) -> List[List[Tuple[float, float]]]:
    """
    Extracts lateral height peaks in each X-slice with sub-bin centroid refinement.
    Returns: slice_peaks[ix] = [(y_refined, peak_height), ...]
    """
    slice_peaks = []
    for ix in range(grid.nx):
        h = grid.max_height_grid[ix]
        c = grid.count_grid[ix]
        peaks = []

        for iy in range(1, grid.ny - 1):
            if c[iy] >= 1 and z_min <= h[iy] <= z_max:
                # Check for local peak
                if h[iy] >= h[iy - 1] and h[iy] >= h[iy + 1]:
                    # Sub-bin centroid refinement using 3-bin neighborhood
                    weights = np.maximum(0.0, h[iy - 1 : iy + 2] - (z_min - 0.02))
                    w_sum = np.sum(weights)
                    if w_sum > 1e-4:
                        y_sub = float(np.sum(grid.y_centers[iy - 1 : iy + 2] * weights) / w_sum)
                    else:
                        y_sub = float(grid.y_centers[iy])
                    peaks.append((y_sub, float(h[iy])))

        slice_peaks.append(peaks)
    return slice_peaks


def segment_rails(
    xyz: np.ndarray,
    frame_name: str = "frame",
    intensity: Optional[np.ndarray] = None,
    ground_res: Optional[GroundPlaneResult] = None,
    nominal_gauge_m: float = 1.520,
    gauge_tol_m: float = 0.08,
    grid_dx: float = 0.40,
    grid_dy: float = 0.05,
    max_gap_m: float = 3.2,
) -> RailSegmentationResult:
    """
    Performs full geometric rail segmentation:
    1. Transforms to leveled BEV grid.
    2. Extracts candidate height ridges in [0.16, 0.34]m.
    3. Anchors ego track in near zone.
    4. Smoothly tracks ego-track along X and isolates other tracks.
    """
    if ground_res is None:
        ground_res = estimate_ground_plane(xyz, frame_name=frame_name)

    bev_frame = create_bev_transform(xyz, ground_res=ground_res, intensity=intensity)
    grid = project_to_bev_grid(
        bev_frame,
        frame_name=frame_name,
        dx=grid_dx,
        dy=grid_dy,
        x_min=2.0,
        x_max=60.0,
        y_min=-4.0,
        y_max=4.0,
    )

    slice_peaks = extract_candidate_ridges(grid)

    # 1. Anchor ego-track in near zone (X in [3.0, 11.0] m)
    anchor_pairs = []
    i_start = int(max(0, (3.0 - grid.x_min) / grid.dx))
    i_end = int(min(grid.nx, (11.0 - grid.x_min) / grid.dx))

    for ix in range(i_start, i_end):
        p = slice_peaks[ix]
        for j1 in range(len(p)):
            for j2 in range(j1 + 1, len(p)):
                y1, h1 = p[j1]
                y2, h2 = p[j2]
                g = y2 - y1
                if abs(g - nominal_gauge_m) <= gauge_tol_m:
                    mid = (y1 + y2) / 2.0
                    # Check distance to estimated track center
                    if abs(mid - ground_res.track_center_offset_m) < 0.35:
                        anchor_pairs.append((grid.x_centers[ix], y1, y2, g, mid))

    if not anchor_pairs:
        # Fallback to nearest detected pair
        for ix in range(grid.nx):
            p = slice_peaks[ix]
            for j1 in range(len(p)):
                for j2 in range(j1 + 1, len(p)):
                    y1, _ = p[j1]
                    y2, _ = p[j2]
                    g = y2 - y1
                    if abs(g - nominal_gauge_m) <= gauge_tol_m:
                        anchor_pairs.append((grid.x_centers[ix], y1, y2, g, (y1 + y2) / 2.0))
            if anchor_pairs:
                break

    if anchor_pairs:
        init_c = float(np.median([a[4] for a in anchor_pairs]))
        init_g = float(np.median([a[3] for a in anchor_pairs]))
    else:
        init_c = float(ground_res.track_center_offset_m)
        init_g = nominal_gauge_m

    cur_yl = init_c - init_g / 2.0
    cur_yr = init_c + init_g / 2.0
    cur_c = init_c
    slope_c = 0.0

    tracked_slices: List[TrackedRailSlice] = []
    other_track_peaks: List[Tuple[float, float, float]] = []
    all_candidate_ridges: List[Tuple[float, float, float]] = []
    rejected_noise_count = 0

    last_detected_x = 0.0
    continuous_break_x = None

    # Track longitudinally forward
    for ix in range(grid.nx):
        x = float(grid.x_centers[ix])
        if x < 2.5 or x > 45.0:
            continue

        p = slice_peaks[ix]
        # Collect for visualization
        for y_pk, h_pk in p:
            all_candidate_ridges.append((x, y_pk, h_pk))

        # Time/distance since last detection
        if last_detected_x > 0:
            dt_x = x - last_detected_x
        else:
            dt_x = grid.dx

        # Predicted positions using measured curvature
        pred_c = cur_c + slope_c * dt_x
        pred_yl = pred_c - nominal_gauge_m / 2.0
        pred_yr = pred_c + nominal_gauge_m / 2.0

        best_pair = None
        best_cost = 1e9

        for j1 in range(len(p)):
            for j2 in range(j1 + 1, len(p)):
                y1, h1 = p[j1]
                y2, h2 = p[j2]
                g = y2 - y1
                if abs(g - nominal_gauge_m) <= (gauge_tol_m + 0.04):
                    mid = (y1 + y2) / 2.0
                    cost = abs(mid - pred_c) + 0.5 * abs(g - nominal_gauge_m)
                    if cost < 0.38 and cost < best_cost:
                        best_cost = cost
                        best_pair = (y1, y2, h1, h2, g, mid)

        matched = False
        is_inferred = False

        if best_pair is not None:
            yl, yr, hl, hr, g, mid = best_pair
            matched = True
            is_inferred = False
        else:
            # Check single rail match
            match_l = [(y, h) for y, h in p if abs(y - pred_yl) < 0.18]
            match_r = [(y, h) for y, h in p if abs(y - pred_yr) < 0.18]

            if match_l and not match_r:
                yl, hl = match_l[0]
                yr = yl + nominal_gauge_m
                hr = hl
                g = nominal_gauge_m
                mid = yl + nominal_gauge_m / 2.0
                matched = True
                is_inferred = True
            elif match_r and not match_l:
                yr, hr = match_r[0]
                yl = yr - nominal_gauge_m
                hl = hr
                g = nominal_gauge_m
                mid = yr - nominal_gauge_m / 2.0
                matched = True
                is_inferred = True

        if matched:
            # Transform to raw 3D LiDAR coordinates for 3D viewer
            raw_pt_l = bev_to_raw_xyz(np.array([x]), np.array([yl]), np.array([hl]), bev_frame)[0]
            raw_pt_r = bev_to_raw_xyz(np.array([x]), np.array([yr]), np.array([hr]), bev_frame)[0]

            slice_res = TrackedRailSlice(
                x_bev=x,
                y_left_bev=yl,
                y_right_bev=yr,
                z_left_bev=hl,
                z_right_bev=hr,
                gauge_m=g,
                center_y_bev=mid,
                is_inferred=is_inferred,
                raw_pt_left=raw_pt_l,
                raw_pt_right=raw_pt_r,
            )
            tracked_slices.append(slice_res)

            # Smooth curvature / slope update only when both rails detected
            if not is_inferred:
                measured_slope = (mid - cur_c) / max(dt_x, 1e-3)
                slope_c = 0.8 * slope_c + 0.2 * np.clip(measured_slope, -0.08, 0.08)
            cur_yl, cur_yr, cur_c = yl, yr, mid

            # Check continuous tracking gap (no gap > 1.25m allowed)
            if last_detected_x > 0 and (x - last_detected_x) > 1.25 and continuous_break_x is None:
                continuous_break_x = last_detected_x

            last_detected_x = x

            # Classify all other peaks in this slice
            for y_cand, h_cand in p:
                if abs(y_cand - yl) > 0.15 and abs(y_cand - yr) > 0.15:
                    if abs(y_cand - mid) > 1.05:
                        other_track_peaks.append((x, y_cand, h_cand))
                    else:
                        rejected_noise_count += 1
        else:
            for y_cand, h_cand in p:
                if abs(y_cand - pred_c) > 1.05:
                    other_track_peaks.append((x, y_cand, h_cand))
                else:
                    rejected_noise_count += 1

            if last_detected_x > 0 and (x - last_detected_x) > max_gap_m:
                # Still classify remaining peaks up to 35m as other tracks or noise
                for rem_ix in range(ix + 1, min(grid.nx, int(35.0 / grid.dx))):
                    rem_x = float(grid.x_centers[rem_ix])
                    for y_rem, h_rem in slice_peaks[rem_ix]:
                        all_candidate_ridges.append((rem_x, y_rem, h_rem))
                        if abs(y_rem - pred_c) > 1.05:
                            other_track_peaks.append((rem_x, y_rem, h_rem))
                        else:
                            rejected_noise_count += 1
                break

    if continuous_break_x is None:
        continuous_break_x = last_detected_x

    # Gauge statistics on slices where both rails were directly detected
    both_detected_gauges = [s.gauge_m for s in tracked_slices if not s.is_inferred]
    if both_detected_gauges:
        mean_g = float(np.mean(both_detected_gauges))
        std_g = float(np.std(both_detected_gauges))
        min_g = float(np.min(both_detected_gauges))
        max_g = float(np.max(both_detected_gauges))
    else:
        mean_g, std_g, min_g, max_g = nominal_gauge_m, 0.0, nominal_gauge_m, nominal_gauge_m

    both_cnt = len(both_detected_gauges)
    inferred_cnt = len(tracked_slices) - both_cnt

    return RailSegmentationResult(
        frame_name=frame_name,
        tracked_slices=tracked_slices,
        max_continuous_range_m=float(continuous_break_x),
        max_tracked_range_m=float(last_detected_x),
        slices_count=len(tracked_slices),
        both_rails_detected_count=both_cnt,
        single_rail_inferred_count=inferred_cnt,
        mean_gauge_m=mean_g,
        std_gauge_m=std_g,
        min_gauge_m=min_g,
        max_gauge_m=max_g,
        other_track_peaks_count=len(other_track_peaks),
        rejected_noise_count=rejected_noise_count,
        all_candidate_ridges=all_candidate_ridges,
        other_track_points=other_track_peaks,
        grid=grid,
    )


def log_rail_segment_to_rerun(res: RailSegmentationResult, frame_idx: int = 0):
    """Visualizes segmented rails, candidate ridges, and rejected tracks in Rerun."""
    if not HAVE_RERUN:
        return

    rr.set_time("frame", sequence=frame_idx)

    bev = res.grid.bev_frame

    # 1. Base point cloud (dimmed background)
    m_near = (bev.x_bev >= res.grid.x_min) & (bev.x_bev <= 45.0) & (np.abs(bev.y_bev) <= 4.0)
    pts_bg = np.column_stack([bev.x_bev[m_near], bev.y_bev[m_near], bev.z_bev[m_near]])
    colors_bg = np.full((len(pts_bg), 3), [70, 70, 80], dtype=np.uint8)
    rr.log(
        "rail_segment/pointcloud_context",
        rr.Points3D(positions=pts_bg, colors=colors_bg, radii=0.02),
    )

    # 2. All candidate height ridges (red / salmon)
    if res.all_candidate_ridges:
        cand_arr = np.array(res.all_candidate_ridges)
        cand_colors = np.full((len(cand_arr), 3), [220, 80, 80], dtype=np.uint8)
        rr.log(
            "rail_segment/all_candidate_ridges",
            rr.Points3D(positions=cand_arr, colors=cand_colors, radii=0.04),
        )

    # 3. Rejected / Other tracks (bright yellow/orange) — confirming multi-track rejection on frames 4 & 5
    if res.other_track_points:
        other_arr = np.array(res.other_track_points)
        other_colors = np.full((len(other_arr), 3), [255, 190, 20], dtype=np.uint8)
        rr.log(
            "rail_segment/other_tracks_rejected",
            rr.Points3D(positions=other_arr, colors=other_colors, radii=0.07),
        )

    # 4. Final ego-track rails (Left: bright green, Right: bright cyan)
    if res.tracked_slices:
        pts_left = np.array([[s.x_bev, s.y_left_bev, s.z_left_bev] for s in res.tracked_slices])
        pts_right = np.array([[s.x_bev, s.y_right_bev, s.z_right_bev] for s in res.tracked_slices])

        colors_left = np.full((len(pts_left), 3), [50, 255, 100], dtype=np.uint8)
        colors_right = np.full((len(pts_right), 3), [0, 230, 255], dtype=np.uint8)

        rr.log(
            "rail_segment/ego_track_left",
            rr.Points3D(positions=pts_left, colors=colors_left, radii=0.08),
        )
        rr.log(
            "rail_segment/ego_track_right",
            rr.Points3D(positions=pts_right, colors=colors_right, radii=0.08),
        )

        # Track centerline
        pts_center = np.array([[s.x_bev, s.center_y_bev, 0.5 * (s.z_left_bev + s.z_right_bev)] for s in res.tracked_slices])
        colors_center = np.full((len(pts_center), 3), [255, 255, 255], dtype=np.uint8)
        rr.log(
            "rail_segment/ego_track_centerline",
            rr.Points3D(positions=pts_center, colors=colors_center, radii=0.05),
        )

    # Telemetry
    info = (
        f"Rail Segmentation: {res.frame_name}\n"
        f"Max Continuous Range (no gaps): {res.max_continuous_range_m:.1f} m\n"
        f"Max Tracked Range: {res.max_tracked_range_m:.1f} m ({res.slices_count} slices)\n"
        f"Detections: Both rails={res.both_rails_detected_count}, Single inferred={res.single_rail_inferred_count}\n"
        f"Measured Gauge: mean={res.mean_gauge_m:.3f} m (std={res.std_gauge_m*1000:.1f} mm, range: [{res.min_gauge_m:.3f} .. {res.max_gauge_m:.3f}] m)\n"
        f"Other Track Peaks Rejected: {res.other_track_peaks_count} (Noise: {res.rejected_noise_count})"
    )
    rr.log("telemetry/rail_segmentation", rr.TextLog(info))


def print_segmentation_summary(results: List[RailSegmentationResult]):
    """Prints structured summary table comparing rail segmentation across all 5 frames."""
    print("\n" + "=" * 115)
    print("                    GEOMETRIC RAIL SEGMENTATION & TRACKING SUMMARY (5 FRAMES)")
    print("=" * 115)
    print(
        f"{'Frame File':<34} | {'Cont. X':<8} | {'Max X':<7} | {'Slices':<8} | {'Both/Inf':<9} | {'Gauge Mean±Std':<17} | {'Gauge Min..Max':<14} | {'Other Tracks':<12}"
    )
    print("-" * 115)
    for r in results:
        gauge_str = f"{r.mean_gauge_m:.3f} ± {r.std_gauge_m*1000:4.1f}mm"
        min_max_str = f"{r.min_gauge_m:.3f} .. {r.max_gauge_m:.3f}"
        both_inf_str = f"{r.both_rails_detected_count:2d} / {r.single_rail_inferred_count:2d}"
        print(
            f"{r.frame_name:<34} | {r.max_continuous_range_m:5.1f} m | {r.max_tracked_range_m:5.1f}m | {r.slices_count:3d} pts  | {both_inf_str:<9} | {gauge_str:<17} | {min_max_str:<14} | {r.other_track_peaks_count:3d} peaks"
        )
    print("=" * 115 + "\n")


def main():
    parser = argparse.ArgumentParser(description="LiDAR Geometric Rail Segmentation & Tracking")
    parser.add_argument(
        "--dir",
        default=os.path.join(os.path.dirname(__file__), "..", "frames"),
        help="Path to directory containing .npz frames",
    )
    parser.add_argument("--frame", type=int, default=None, help="Frame index (0..4)")
    parser.add_argument("--file", type=str, default=None, help="Path to single .npz file")
    parser.add_argument("--all", action="store_true", help="Process all frames in directory")
    parser.add_argument("--visualize", action="store_true", help="Stream to Rerun viewer")
    parser.add_argument(
        "--connect",
        type=str,
        default="rerun+http://127.0.0.1:9876/proxy",
        help="Rerun connect URL",
    )
    args = parser.parse_args()

    if args.file:
        files = [args.file]
    else:
        pattern = os.path.join(args.dir, "*.npz")
        all_files = sorted(glob.glob(pattern))
        if not all_files:
            print(f"Error: No .npz files found in {args.dir}")
            sys.exit(1)
        if args.frame is not None:
            if args.frame < 0 or args.frame >= len(all_files):
                print(f"Error: frame index {args.frame} out of range [0, {len(all_files)-1}]")
                sys.exit(1)
            files = [all_files[args.frame]]
        else:
            files = all_files

    if args.visualize and HAVE_RERUN:
        rr.init("nextgen_rail_segmentation", spawn=False)
        try:
            rr.connect_grpc(args.connect)
            print(f"Connected to Rerun server at {args.connect}")
        except Exception as e:
            print(f"Could not connect to {args.connect}: {e}. Spawning local viewer...")
            rr.spawn()

    results: List[RailSegmentationResult] = []
    for idx, fpath in enumerate(files):
        fname = os.path.basename(fpath)
        data = np.load(fpath)
        xyz = data["xyz"]
        intensity = data["intensity"]

        res = segment_rails(xyz, frame_name=fname, intensity=intensity)
        results.append(res)

        if args.visualize and HAVE_RERUN:
            log_rail_segment_to_rerun(res, frame_idx=idx)

    print_segmentation_summary(results)


if __name__ == "__main__":
    main()
