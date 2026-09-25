#!/usr/bin/env python3
"""
nextgen/view.py — Point Cloud & Intensity Snapshot Viewer in Rerun

Loads point cloud snapshots (.npz) from nextgen/frames/ and streams
3D points colored by reflection intensity to Rerun Viewer.

Usage:
    # 1. View all snapshots in nextgen/frames
    python nextgen/view.py

    # 2. View a single snapshot
    python nextgen/view.py --file nextgen/frames/frame_946685811033314943.npz

    # 3. Spawn local Rerun viewer window
    python nextgen/view.py --spawn

    # 4. Connect to remote Rerun server
    python nextgen/view.py --connect rerun+http://192.168.0.100:9876/proxy --fps 2
"""

import argparse
import glob
import os
import sys
import time
import numpy as np

try:
    import rerun_sdk as rr
except ImportError:
    print("Error: 'rerun-sdk' is not installed. Run: pip install rerun-sdk")
    sys.exit(1)

try:
    import matplotlib.pyplot as plt
    HAVE_MPL = True
except ImportError:
    HAVE_MPL = False


def intensity_to_rgb(intensity: np.ndarray, colormap: str = "turbo") -> np.ndarray:
    """
    Maps reflection intensity values (0..255) to RGB colors [0, 255] uint8.
    Uses matplotlib colormap if available, or a fast HSV-based rainbow fallback.
    """
    # Normalize intensity: 0..60 covers most ground/ballast, 60..255 covers rails, metal, and retroreflectors
    norm = np.clip(intensity / 80.0, 0.0, 1.0)
    
    if HAVE_MPL:
        cmap = plt.get_cmap(colormap)
        rgba = cmap(norm) # shape (N, 4) in [0, 1]
        rgb = (rgba[:, :3] * 255.0).astype(np.uint8)
        return rgb
    
    # Fallback without matplotlib: Turbo-like gradient
    r = np.clip(1.5 - np.abs(norm * 4.0 - 3.0), 0.0, 1.0)
    g = np.clip(1.5 - np.abs(norm * 4.0 - 2.0), 0.0, 1.0)
    b = np.clip(1.5 - np.abs(norm * 4.0 - 1.0), 0.0, 1.0)
    return np.column_stack([r * 255, g * 255, b * 255]).astype(np.uint8)


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


def log_frame(xyz: np.ndarray, intensity: np.ndarray, ts: int, meta: dict, frame_idx: int):
    """
    Logs 3D points, colorized intensity, and telemetry to Rerun.
    """
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

    # 4. Log text telemetry
    info_text = (
        f"File: {meta['file']} | Frame: {frame_idx}\n"
        f"Timestamp: {ts} ns\n"
        f"Points: {len(xyz):,} valid (raw: {meta['total_raw_points']:,})\n"
        f"Intensity: min={intensity.min():.1f}, max={intensity.max():.1f}, "
        f"mean={intensity.mean():.1f}, median={np.median(intensity):.1f}"
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
                log_frame(xyz, intensity, ts, meta, idx)
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
