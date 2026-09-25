#!/usr/bin/env python3
"""
nextgen/src/bev_project.py — Bird's Eye View (BEV) Projection and Top-Down Grid

Projects 3D LiDAR point clouds into a leveled, track-aligned Bird's Eye View (BEV) frame:
- Axis X: Forward distance along the track travel direction (meters).
- Axis Y: Lateral distance across the track (meters, positive right, negative left).
- Axis Z: Height above the estimated track/ballast plane (meters, z=0 is ballast, z≈0.25m is rail head).

Computes a high-resolution 2D BEV grid:
- Cell resolution: ΔY ≈ 0.05 m (5 cm lateral), ΔX ≈ 0.25 m (25 cm longitudinal).
- Stored channels per cell:
  1. point_count: Density of LiDAR returns in cell.
  2. max_height: Maximum elevation above track plane in [0.0, 0.6] m (rail ridge signal).
  3. mean_intensity: Average reflection intensity in cell.

Usage:
    python nextgen/src/bev_project.py --all
    python nextgen/src/bev_project.py --frame 0 --visualize
    python nextgen/src/bev_project.py --file nextgen/frames/frame_946685811033314943.npz --visualize
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

try:
    import rerun as rr
    HAVE_RERUN = True
except ImportError:
    HAVE_RERUN = False

try:
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    HAVE_MPL = True
except ImportError:
    HAVE_MPL = False


@dataclass
class BEVFrame:
    """Holds 3D points transformed into leveled BEV coordinate frame."""
    x_bev: np.ndarray       # Forward distance (m)
    y_bev: np.ndarray       # Lateral distance (m)
    z_bev: np.ndarray       # Height above ballast plane (m)
    intensity: np.ndarray   # LiDAR intensity
    ex: np.ndarray          # Forward unit vector in raw LiDAR coords (3,)
    ey: np.ndarray          # Lateral unit vector in raw LiDAR coords (3,)
    ez: np.ndarray          # Plane normal unit vector in raw LiDAR coords (3,)
    plane_d: float          # Plane distance parameter
    ground_res: GroundPlaneResult


@dataclass
class BEVGrid:
    """2D rasterized BEV grid for rail ridge detection and corridor mapping."""
    frame_name: str
    x_min: float
    x_max: float
    dx: float
    y_min: float
    y_max: float
    dy: float
    nx: int
    ny: int
    x_edges: np.ndarray
    y_edges: np.ndarray
    x_centers: np.ndarray
    y_centers: np.ndarray
    count_grid: np.ndarray       # (nx, ny) int32: points per cell
    max_height_grid: np.ndarray  # (nx, ny) float32: max Z_bev in [-0.05, 0.60]m
    intensity_grid: np.ndarray   # (nx, ny) float32: mean intensity per cell
    bev_frame: BEVFrame


def create_bev_transform(
    xyz: np.ndarray,
    ground_res: Optional[GroundPlaneResult] = None,
    intensity: Optional[np.ndarray] = None,
) -> BEVFrame:
    """
    Computes orthonormal transformation into leveled BEV coordinate frame.
    
    Raw LiDAR:
      Y is negative forward: s = -y_lidar
      X is lateral right: x_lidar
      Z is vertical up: z_lidar
      
    Leveled BEV:
      X_bev: forward along track plane
      Y_bev: rightward across track plane
      Z_bev: normal to track plane (z_bev=0 is ballast level)
    """
    if ground_res is None:
        ground_res = estimate_ground_plane(xyz)

    ez = ground_res.normal  # Unit normal to plane pointing up
    v_fwd = np.array([0.0, -1.0, 0.0], dtype=np.float32)  # Raw forward direction

    # Project raw forward vector onto plane and normalize
    u_fwd = v_fwd - np.dot(v_fwd, ez) * ez
    norm_u = np.linalg.norm(u_fwd)
    if norm_u < 1e-4:
        ex = np.array([0.0, -1.0, 0.0], dtype=np.float32)
    else:
        ex = (u_fwd / norm_u).astype(np.float32)

    # Lateral vector completes right-handed orthonormal basis
    ey = np.cross(ez, ex).astype(np.float32)

    # Transform all points:
    # Origin of leveled frame placed on ballast plane directly under LiDAR: p0 = -d * ez
    # p' = p - p0 = p + d * ez
    p_prime = xyz + ground_res.d * ez

    x_bev = np.dot(p_prime, ex).astype(np.float32)
    y_bev = np.dot(p_prime, ey).astype(np.float32)
    z_bev = np.dot(p_prime, ez).astype(np.float32)

    if intensity is None:
        intensity = np.zeros(len(xyz), dtype=np.float32)

    return BEVFrame(
        x_bev=x_bev,
        y_bev=y_bev,
        z_bev=z_bev,
        intensity=intensity,
        ex=ex,
        ey=ey,
        ez=ez,
        plane_d=ground_res.d,
        ground_res=ground_res,
    )


def bev_to_raw_xyz(
    x_bev: np.ndarray,
    y_bev: np.ndarray,
    z_bev: np.ndarray,
    bev_frame: BEVFrame,
) -> np.ndarray:
    """Converts coordinates from leveled BEV frame back to raw LiDAR 3D coordinates."""
    # p = x_bev * ex + y_bev * ey + (z_bev - d) * ez
    return (
        np.outer(x_bev, bev_frame.ex)
        + np.outer(y_bev, bev_frame.ey)
        + np.outer(z_bev - bev_frame.plane_d, bev_frame.ez)
    )


def project_to_bev_grid(
    bev_frame: BEVFrame,
    frame_name: str = "frame",
    x_min: float = 2.0,
    x_max: float = 75.0,
    dx: float = 0.25,
    y_min: float = -4.0,
    y_max: float = 4.0,
    dy: float = 0.05,
    z_filter_min: float = -0.08,
    z_filter_max: float = 0.55,
) -> BEVGrid:
    """
    Rasters the leveled point cloud into a 2D BEV occupancy & max-height grid.
    """
    x_bev = bev_frame.x_bev
    y_bev = bev_frame.y_bev
    z_bev = bev_frame.z_bev
    intensity = bev_frame.intensity

    nx = int(np.ceil((x_max - x_min) / dx))
    ny = int(np.ceil((y_max - y_min) / dy))

    x_edges = np.linspace(x_min, x_max, nx + 1)
    y_edges = np.linspace(y_min, y_max, ny + 1)
    x_centers = 0.5 * (x_edges[:-1] + x_edges[1:])
    y_centers = 0.5 * (y_edges[:-1] + y_edges[1:])

    # Filter points relevant for rail surface mapping
    # Exclude points too high (catenary, trees) or deep below ground
    valid = (
        (x_bev >= x_min)
        & (x_bev < x_max)
        & (y_bev >= y_min)
        & (y_bev < y_max)
        & (z_bev >= z_filter_min)
        & (z_bev <= z_filter_max)
    )

    xv = x_bev[valid]
    yv = y_bev[valid]
    zv = z_bev[valid]
    iv = intensity[valid]

    ix = np.floor((xv - x_min) / dx).astype(int)
    iy = np.floor((yv - y_min) / dy).astype(int)

    # Clip indices just in case of edge values
    ix = np.clip(ix, 0, nx - 1)
    iy = np.clip(iy, 0, ny - 1)

    count_grid = np.zeros((nx, ny), dtype=np.int32)
    max_height_grid = np.full((nx, ny), -np.inf, dtype=np.float32)
    sum_intensity_grid = np.zeros((nx, ny), dtype=np.float32)

    # Ultra-fast vectorized binning via np.ufunc.at
    np.add.at(count_grid, (ix, iy), 1)
    np.maximum.at(max_height_grid, (ix, iy), zv)
    np.add.at(sum_intensity_grid, (ix, iy), iv)

    # Replace empty cells -inf with nan
    empty_cells = count_grid == 0
    max_height_grid[empty_cells] = np.nan

    intensity_grid = np.zeros((nx, ny), dtype=np.float32)
    non_empty = count_grid > 0
    intensity_grid[non_empty] = sum_intensity_grid[non_empty] / count_grid[non_empty]

    return BEVGrid(
        frame_name=frame_name,
        x_min=x_min,
        x_max=x_max,
        dx=dx,
        y_min=y_min,
        y_max=y_max,
        dy=dy,
        nx=nx,
        ny=ny,
        x_edges=x_edges,
        y_edges=y_edges,
        x_centers=x_centers,
        y_centers=y_centers,
        count_grid=count_grid,
        max_height_grid=max_height_grid,
        intensity_grid=intensity_grid,
        bev_frame=bev_frame,
    )


def log_bev_to_rerun(grid: BEVGrid, frame_idx: int = 0):
    """Streams BEV grid cells as 3D points and 2D images to Rerun."""
    if not HAVE_RERUN:
        return

    rr.set_time("frame", sequence=frame_idx)

    # Log 3D leveled point cloud: rails and ground in BEV coordinates
    bev = grid.bev_frame
    m_near = (bev.x_bev >= grid.x_min) & (bev.x_bev <= grid.x_max) & (np.abs(bev.y_bev) <= grid.y_max)
    pts_leveled = np.column_stack([bev.x_bev[m_near], bev.y_bev[m_near], bev.z_bev[m_near]])

    # Colorize by height above ground: 0..0.35m
    norm_h = np.clip(bev.z_bev[m_near] / 0.35, 0.0, 1.0)
    r = (np.clip(1.5 - np.abs(norm_h * 4.0 - 3.0), 0.0, 1.0) * 255).astype(np.uint8)
    g = (np.clip(1.5 - np.abs(norm_h * 4.0 - 2.0), 0.0, 1.0) * 255).astype(np.uint8)
    b = (np.clip(1.5 - np.abs(norm_h * 4.0 - 1.0), 0.0, 1.0) * 255).astype(np.uint8)
    colors = np.column_stack([r, g, b])

    rr.log(
        "bev/leveled_pointcloud",
        rr.Points3D(positions=pts_leveled, colors=colors, radii=0.03),
    )

    # Log 2D BEV height image
    h_vis = np.nan_to_num(grid.max_height_grid, nan=0.0)
    h_vis = np.clip(h_vis / 0.35, 0.0, 1.0)  # Normalize 0..35cm
    h_img = (h_vis * 255.0).astype(np.uint8)
    rr.log("bev/max_height_map", rr.Image(h_img.T))  # transpose so X is horizontal, Y vertical

    info = (
        f"BEV Projection: {grid.frame_name}\n"
        f"Grid size: {grid.nx} x {grid.ny} ({grid.dx*100:.0f}cm x {grid.dy*100:.0f}cm)\n"
        f"Range: X=[{grid.x_min:.1f}m .. {grid.x_max:.1f}m], Y=[{grid.y_min:.1f}m .. {grid.y_max:.1f}m]\n"
        f"Ground plane normal: [{bev.ez[0]:.4f}, {bev.ez[1]:.4f}, {bev.ez[2]:.4f}]\n"
        f"Non-empty cells: {np.count_nonzero(grid.count_grid):,} / {grid.nx*grid.ny:,}"
    )
    rr.log("telemetry/bev_summary", rr.TextLog(info))


def main():
    parser = argparse.ArgumentParser(description="LiDAR Bird's Eye View (BEV) Projection and Grid Generation")
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
        rr.init("nextgen_bev_projection", spawn=False)
        try:
            rr.connect_grpc(args.connect)
            print(f"Connected to Rerun server at {args.connect}")
        except Exception as e:
            print(f"Could not connect to {args.connect}: {e}. Spawning local viewer...")
            rr.spawn()

    print("\n" + "=" * 90)
    print("                     BIRD'S EYE VIEW (BEV) PROJECTION")
    print("=" * 90)
    print(f"{'Frame File':<36} | {'Grid (X x Y)':<15} | {'Non-empty':<12} | {'Max H in corridor':<18}")
    print("-" * 90)

    for idx, fpath in enumerate(files):
        fname = os.path.basename(fpath)
        data = np.load(fpath)
        xyz = data["xyz"]
        intensity = data["intensity"]

        bev_frame = create_bev_transform(xyz, intensity=intensity)
        grid = project_to_bev_grid(bev_frame, frame_name=fname)

        non_empty = np.count_nonzero(grid.count_grid)
        max_h_valid = np.nanmax(grid.max_height_grid)
        grid_dim = f"{grid.nx}x{grid.ny} ({grid.dx*100:.0f}x{grid.dy*100:.0f}cm)"

        print(f"{fname:<36} | {grid_dim:<15} | {non_empty:<12} | {max_h_valid:6.3f} m")

        if args.visualize and HAVE_RERUN:
            log_bev_to_rerun(grid, frame_idx=idx)

    print("=" * 90 + "\n")


if __name__ == "__main__":
    main()
