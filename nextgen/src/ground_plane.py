#!/usr/bin/env python3
"""
nextgen/src/ground_plane.py — RANSAC Ground & Track Plane Estimation

Estimates the track/ground plane from LiDAR xyz point clouds using RANSAC.
Computes:
1. Ground plane normal vector (normalized, oriented upwards).
2. LiDAR sensor height above the plane (ballast plane and rail head plane vs nominal 1075 mm).
3. Lateral offset of the LiDAR from the track center.

Usage:
    python nextgen/src/ground_plane.py --all
    python nextgen/src/ground_plane.py --frame 0
    python nextgen/src/ground_plane.py --file nextgen/frames/frame_946685811033314943.npz --visualize
"""

import argparse
import glob
import os
import sys
from dataclasses import dataclass
from typing import Dict, List, Optional, Tuple

import numpy as np

try:
    import rerun as rr
    HAVE_RERUN = True
except ImportError:
    HAVE_RERUN = False


@dataclass
class GroundPlaneResult:
    frame_name: str
    normal: np.ndarray             # (3,) unit normal (nx, ny, nz), nz > 0
    d: float                       # Plane equation: normal . p + d = 0
    height_ballast_m: float        # Distance from origin (LiDAR) to ballast plane
    rail_elevation_m: float        # Detected rail elevation above ballast plane
    height_rail_head_m: float      # Distance from LiDAR to rail head plane
    height_diff_mm: float          # Difference from nominal 1075 mm (height_rail_head_m * 1000 - 1075)
    track_center_offset_m: float   # Lateral offset of track center relative to LiDAR X=0
    gauge_m: float                 # Estimated distance between rails in near zone
    inliers_count: int             # Number of ground inliers
    total_candidates: int          # Candidate points tested
    pitch_deg: float               # Plane pitch angle (rotation around X)
    roll_deg: float                # Plane roll angle (rotation around Y)


def estimate_ground_plane(
    xyz: np.ndarray,
    frame_name: str = "frame",
    max_iter: int = 400,
    dist_thresh: float = 0.04,
    nominal_height_mm: float = 1075.0,
    random_seed: int = 42,
) -> GroundPlaneResult:
    """
    Estimates track ground plane using RANSAC.
    
    LiDAR frame convention:
      X: lateral (positive right, negative left)
      Y: longitudinal (negative forward along path: Y in [-150, -2] m)
      Z: vertical (positive up, ground at negative Z)
    """
    # 1. ROI for ground candidates: near zone forward corridor
    # Y in [-30, -3] m, |X| <= 2.5 m, Z in [-2.2, -0.4] m
    roi_mask = (
        (xyz[:, 1] >= -30.0)
        & (xyz[:, 1] <= -3.0)
        & (np.abs(xyz[:, 0]) <= 2.5)
        & (xyz[:, 2] >= -2.2)
        & (xyz[:, 2] <= -0.4)
    )
    cand_pts = xyz[roi_mask]
    if len(cand_pts) < 100:
        raise ValueError(f"Insufficient ground candidate points: {len(cand_pts)}")

    # Downsample candidate points for fast RANSAC convergence
    if len(cand_pts) > 2000:
        step = len(cand_pts) // 1500
        sample_pts = cand_pts[::step]
    else:
        sample_pts = cand_pts

    n = len(sample_pts)
    best_inliers_count = 0
    best_plane = None

    rng = np.random.default_rng(random_seed)
    triplets = rng.integers(0, n, size=(min(max_iter, 200), 3))

    for idxs in triplets:
        p1, p2, p3 = sample_pts[idxs]
        v1 = p2 - p1
        v2 = p3 - p1
        normal = np.cross(v1, v2)
        norm = np.linalg.norm(normal)
        if norm < 1e-5:
            continue
        normal = normal / norm
        if normal[2] < 0:
            normal = -normal

        # Ground normal must be dominantly vertical (nz > 0.90, pitch/roll < 25 deg)
        if normal[2] < 0.90:
            continue

        d = -float(np.dot(normal, p1))
        dists = np.abs(np.dot(sample_pts, normal) + d)
        inliers_cnt = int(np.count_nonzero(dists < dist_thresh))

        if inliers_cnt > best_inliers_count:
            best_inliers_count = inliers_cnt
            best_plane = (normal, d)

    if best_plane is None:
        raise RuntimeError("RANSAC failed to find a valid ground plane")

    normal, d = best_plane

    # Refine plane via SVD on all inliers from cand_pts
    all_dists = np.abs(np.dot(cand_pts, normal) + d)
    inlier_mask = all_dists < dist_thresh
    inlier_pts = cand_pts[inlier_mask]

    if len(inlier_pts) > 10:
        centroid = np.mean(inlier_pts, axis=0)
        _, _, vh = np.linalg.svd(inlier_pts - centroid)
        refined_normal = vh[2]
        if refined_normal[2] < 0:
            refined_normal = -refined_normal
        if refined_normal[2] >= 0.90:
            normal = refined_normal
            d = -float(np.dot(normal, centroid))

    # Height of origin (LiDAR center) above the fitted plane
    # With normal * p + d = 0 and p=(0,0,0), distance = d / ||normal|| = d
    height_ballast = float(d)

    # Calculate pitch and roll angles of the track plane
    # normal = (nx, ny, nz)
    pitch_deg = float(np.degrees(np.arctan2(-normal[1], normal[2])))
    roll_deg = float(np.degrees(np.arctan2(normal[0], normal[2])))

    # 2. Rail Head Detection & Height above plane
    # Near zone: Y in [-18, -4] m, |X| <= 2.2 m
    near_mask = (
        (xyz[:, 1] >= -18.0)
        & (xyz[:, 1] <= -4.0)
        & (np.abs(xyz[:, 0]) <= 2.2)
    )
    near_pts = xyz[near_mask]

    # Signed distance of each point above the ballast plane:
    # h_above_plane = normal . p + d  (positive means above plane)
    h_above = np.dot(near_pts, normal) + d

    # Rail heads are elevated above ballast by ~0.15m to 0.35m
    rail_band_mask = (h_above >= 0.16) & (h_above <= 0.34)
    rail_candidate_pts = near_pts[rail_band_mask]

    # Estimate rail elevation above ballast
    if len(rail_candidate_pts) >= 40:
        # 90th percentile of rail band gives the top rail head running surface
        rail_elevation = float(np.percentile(h_above[rail_band_mask], 85))
    else:
        rail_elevation = 0.25  # nominal R65 rail + tie plate height

    # Lidar height over the rail head:
    height_rail_head = height_ballast - rail_elevation
    height_diff_mm = (height_rail_head * 1000.0) - nominal_height_mm

    # 3. Track Center Offset & Gauge Estimation
    # Focus on candidate rail points within |X| <= 1.8 m (ego track)
    track_center_offset = 0.0
    gauge = 1.520

    if len(rail_candidate_pts) >= 40:
        # Separate rails: left (negative X) and right (positive X)
        # Using spatial distribution
        x_vals = rail_candidate_pts[:, 0]
        # Cluster into left rail and right rail based on sign or density
        left_pts = x_vals[x_vals < 0.0]
        right_pts = x_vals[x_vals > 0.0]

        if len(left_pts) >= 15 and len(right_pts) >= 15:
            # Rail head peaks (modes/medians)
            left_rail_x = float(np.median(left_pts[left_pts >= -1.4]))
            right_rail_x = float(np.median(right_pts[right_pts <= 1.4]))
            track_center_offset = float((left_rail_x + right_rail_x) / 2.0)
            gauge = float(right_rail_x - left_rail_x)
        else:
            # Multi-track or curve: use 25% and 75% quantiles if within ~1.5m
            p25, p75 = np.percentile(x_vals, [25, 75])
            if 1.2 <= (p75 - p25) <= 1.8:
                track_center_offset = float((p25 + p75) / 2.0)
                gauge = float(p75 - p25)
            else:
                track_center_offset = float(np.median(x_vals))

    return GroundPlaneResult(
        frame_name=frame_name,
        normal=normal,
        d=d,
        height_ballast_m=height_ballast,
        rail_elevation_m=rail_elevation,
        height_rail_head_m=height_rail_head,
        height_diff_mm=height_diff_mm,
        track_center_offset_m=track_center_offset,
        gauge_m=gauge,
        inliers_count=int(np.sum(inlier_mask)),
        total_candidates=len(cand_pts),
        pitch_deg=pitch_deg,
        roll_deg=roll_deg,
    )


def log_ground_plane_to_rerun(xyz: np.ndarray, res: GroundPlaneResult):
    """Visualizes the ground plane and coordinate axes in Rerun."""
    if not HAVE_RERUN:
        return

    # Create plane grid for visualization in ROI
    grid_y = np.linspace(-35.0, -2.0, 30)
    grid_x = np.linspace(-3.0, 3.0, 20)
    gy, gx = np.meshgrid(grid_y, grid_x)
    # n[0]*x + n[1]*y + n[2]*z + d = 0  => z = (-d - n[0]*x - n[1]*y) / n[2]
    gz = (-res.d - res.normal[0] * gx - res.normal[1] * gy) / res.normal[2]

    plane_points = np.column_stack([gx.ravel(), gy.ravel(), gz.ravel()])
    plane_colors = np.full((len(plane_points), 3), [40, 160, 220], dtype=np.uint8)

    # Rail head plane
    gz_rail = gz + res.rail_elevation_m
    rail_plane_points = np.column_stack([gx.ravel(), gy.ravel(), gz_rail.ravel()])
    rail_colors = np.full((len(rail_plane_points), 3), [220, 180, 40], dtype=np.uint8)

    rr.log(
        "ground/ballast_plane_grid",
        rr.Points3D(positions=plane_points, colors=plane_colors, radii=0.04),
    )
    rr.log(
        "ground/rail_head_plane_grid",
        rr.Points3D(positions=rail_plane_points, colors=rail_colors, radii=0.04),
    )

    info_str = (
        f"Ground Plane Estimation:\n"
        f"Normal: [{res.normal[0]:.4f}, {res.normal[1]:.4f}, {res.normal[2]:.4f}]\n"
        f"Pitch: {res.pitch_deg:+.2f}° | Roll: {res.roll_deg:+.2f}°\n"
        f"Height over Ballast: {res.height_ballast_m:.3f} m\n"
        f"Rail Elevation: {res.rail_elevation_m:.3f} m\n"
        f"Height over Rail Head: {res.height_rail_head_m:.3f} m (nominal: 1.075 m, diff: {res.height_diff_mm:+.1f} mm)\n"
        f"Track Center Offset: {res.track_center_offset_m:+.3f} m | Gauge: {res.gauge_m:.3f} m\n"
        f"Inliers: {res.inliers_count}/{res.total_candidates}"
    )
    rr.log("telemetry/ground_plane", rr.TextLog(info_str))


def print_summary_table(results: List[GroundPlaneResult]):
    """Prints a structured ASCII table comparing all evaluated frames."""
    print("\n" + "=" * 105)
    print("                      GROUND & TRACK PLANE ESTIMATION RESULTS (RANSAC)")
    print("=" * 105)
    print(
        f"{'Frame File':<36} | {'Normal (nx, ny, nz)':<22} | {'H_ballast':<9} | {'H_rail':<8} | {'Diff(1075)':<10} | {'Offset':<8} | {'Gauge':<7}"
    )
    print("-" * 105)
    for r in results:
        norm_str = f"[{r.normal[0]:+.3f}, {r.normal[1]:+.3f}, {r.normal[2]:.3f}]"
        print(
            f"{r.frame_name:<36} | {norm_str:<22} | {r.height_ballast_m:6.3f} m  | {r.height_rail_head_m:6.3f} m | {r.height_diff_mm:+7.1f} mm | {r.track_center_offset_m:+6.3f} m | {r.gauge_m:5.3f} m"
        )
    print("=" * 105 + "\n")


def main():
    parser = argparse.ArgumentParser(description="Track ground plane estimation using RANSAC")
    parser.add_argument(
        "--dir",
        default=os.path.join(os.path.dirname(__file__), "..", "frames"),
        help="Path to directory containing .npz frames",
    )
    parser.add_argument("--frame", type=int, default=None, help="Frame index (0..4)")
    parser.add_argument("--file", type=str, default=None, help="Path to single .npz file")
    parser.add_argument("--all", action="store_true", help="Process all frames in directory")
    parser.add_argument("--visualize", action="store_true", help="Stream plane to Rerun viewer")
    parser.add_argument(
        "--connect",
        type=str,
        default="rerun+http://127.0.0.1:9876/proxy",
        help="Rerun connect URL",
    )
    args = parser.parse_args()

    # Determine files to process
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
        rr.init("nextgen_ground_plane", spawn=False)
        try:
            rr.connect_grpc(args.connect)
            print(f"Connected to Rerun server at {args.connect}")
        except Exception as e:
            print(f"Could not connect to {args.connect}: {e}. Spawning viewer...")
            rr.spawn()

    results: List[GroundPlaneResult] = []
    for fpath in files:
        fname = os.path.basename(fpath)
        data = np.load(fpath)
        xyz = data["xyz"]

        res = estimate_ground_plane(xyz, frame_name=fname)
        results.append(res)

        if args.visualize and HAVE_RERUN:
            log_ground_plane_to_rerun(xyz, res)

    print_summary_table(results)


if __name__ == "__main__":
    main()
