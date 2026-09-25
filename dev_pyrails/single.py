"""
Visualization and Range Analysis for a Single LiDAR Frame
---------------------------------------------------------
Loads a .npy range image (default: frames/frame_000001.npy),
calculates and prints statistical range metrics to stdout,
and renders an interactive matplotlib visualization.

Usage:
    python dev_pyrails/single.py
    python dev_pyrails/single.py frames/frame_000001.npy
    python dev_pyrails/single.py --frame 1
"""

import argparse
import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors


def find_default_frame(specified_path: str = None) -> str:
    """Finds the frame file path with robust fallback logic."""
    if specified_path:
        if os.path.exists(specified_path):
            return specified_path
        # Check if specified as a number like '1' or '000001'
        if specified_path.isdigit():
            idx = int(specified_path)
            candidates = [
                os.path.join("frames", f"frame_{idx:06d}.npy"),
                os.path.join("..", "frames", f"frame_{idx:06d}.npy"),
            ]
            for c in candidates:
                if os.path.exists(c):
                    return c
        raise FileNotFoundError(f"Frame file not found: {specified_path}")

    # Default search for frame_000001.npy
    possible_paths = [
        os.path.join("frames", "frame_000001.npy"),
        os.path.join("..", "frames", "frame_000001.npy"),
        os.path.join(os.path.dirname(__file__), "..", "frames", "frame_000001.npy"),
        os.path.join(os.path.dirname(__file__), "frames", "frame_000001.npy"),
    ]

    for path in possible_paths:
        if os.path.exists(path):
            return os.path.abspath(path)

    raise FileNotFoundError(
        "Could not locate 'frames/frame_000001.npy'. "
        "Please provide the path as an argument: python single.py <path_to_frame.npy>"
    )


def print_frame_statistics(frame: np.ndarray, file_path: str):
    """Computes and prints detailed value ranges and statistics."""
    total_elements = frame.size
    zero_count = np.count_nonzero(frame == 0.0)
    zero_pct = (zero_count / total_elements) * 100.0

    nan_count = int(np.isnan(frame).sum())
    inf_count = int(np.isinf(frame).sum())

    valid_mask = (frame > 0.0) & ~np.isnan(frame) & ~np.isinf(frame)
    valid_values = frame[valid_mask]

    print("=" * 65)
    print(" " * 18 + "FRAME RANGE & METRICS")
    print("=" * 65)
    print(f"File:            {os.path.abspath(file_path)}")
    print(f"Dimensions:      {frame.shape[0]} rows x {frame.shape[1]} cols ({total_elements:,} points)")
    print(f"Data type:       {frame.dtype}")
    print("-" * 65)
    print(f"Absolute range:  [{np.min(frame):.4f}, {np.max(frame):.4f}] m")
    print(f"Zero values (0): {zero_count:,} ({zero_pct:.2f}%)")
    print(f"NaN / Inf:       NaN={nan_count}, Inf={inf_count}")
    print("-" * 65)

    if len(valid_values) > 0:
        val_min = np.min(valid_values)
        val_max = np.max(valid_values)
        val_mean = np.mean(valid_values)
        val_std = np.std(valid_values)
        val_median = np.median(valid_values)

        p1, p5, p25, p50, p75, p90, p95, p99 = np.percentile(
            valid_values, [1, 5, 25, 50, 75, 90, 95, 99]
        )

        print("Valid range (> 0):")
        print(f"  Min:           {val_min:.4f} m")
        print(f"  Max:           {val_max:.4f} m")
        print(f"  Mean:          {val_mean:.4f} m (+/- {val_std:.4f})")
        print(f"  Median:        {val_median:.4f} m")
        print("-" * 65)
        print("Percentiles (valid distances):")
        print(f"   1%:  {p1:6.2f} m      |   50% (Median): {p50:6.2f} m")
        print(f"   5%:  {p5:6.2f} m      |   75%:          {p75:6.2f} m")
        print(f"  25%:  {p25:6.2f} m      |   90%:          {p90:6.2f} m")
        print(f"                         |   95%:          {p95:6.2f} m")
        print(f"                         |   99%:          {p99:6.2f} m")
    else:
        print("Warning: No valid non-zero values found in frame!")
    print("=" * 65 + "\n")


def visualize_frame(
    frame: np.ndarray, file_path: str, save_path: str = None, no_show: bool = False
):
    """Renders multi-view matplotlib figure for the range image."""
    fig = plt.figure(figsize=(14, 9))
    try:
        fig.canvas.manager.set_window_title(f"LiDAR Frame Viewer - {os.path.basename(file_path)}")
    except Exception:
        pass

    # Colormap setup: set invalid / 0 distance to distinct dark charcoal color
    cmap_full = plt.cm.turbo.copy()
    cmap_full.set_bad(color="#1a1a1a")

    masked_full = np.ma.masked_equal(frame, 0.0)

    # 1. Full Dynamic Range View
    ax1 = plt.subplot(2, 2, 1)
    im1 = ax1.imshow(masked_full, cmap=cmap_full, aspect="auto", interpolation="nearest")
    cbar1 = plt.colorbar(im1, ax=ax1, orientation="vertical", pad=0.02)
    cbar1.set_label("Дистанция (м)", fontsize=10)
    ax1.set_title(
        f"1. Полный диапазон дальностей (Full Range)\n"
        f"[{np.min(frame):.2f} .. {np.max(frame):.2f} м] | 0.0 = Нет отражения (черный)",
        fontsize=10,
    )
    ax1.set_xlabel("Столбец (Col / Азимут)")
    ax1.set_ylabel("Строка (Row / Угол места)")

    # 2. Near-Range Detail (Operational Track Zone: 0..30m)
    ax2 = plt.subplot(2, 2, 2)
    cmap_near = plt.cm.turbo.copy()
    cmap_near.set_bad(color="#1a1a1a")
    clipped_near = np.ma.masked_equal(np.clip(frame, 0.0, 30.0), 0.0)
    im2 = ax2.imshow(
        clipped_near,
        cmap=cmap_near,
        aspect="auto",
        vmin=0.0,
        vmax=30.0,
        interpolation="nearest",
    )
    cbar2 = plt.colorbar(im2, ax=ax2, orientation="vertical", pad=0.02)
    cbar2.set_label("Дистанция до 30м", fontsize=10)
    ax2.set_title(
        "2. Ближняя зона рельсового полотна (0 .. 30 м)\n"
        "Контрастно выделяет профиль рельсов, шпал и балласта",
        fontsize=10,
    )
    ax2.set_xlabel("Столбец (Col / Азимут)")
    ax2.set_ylabel("Строка (Row / Угол места)")

    # 3. Horizontal Profile at center row (Ray slice)
    ax3 = plt.subplot(2, 2, 3)
    valid_points = frame[frame > 0.0]
    mid_row = frame.shape[0] // 2
    row_slice = frame[mid_row, :]
    ax3.plot(row_slice, color="#007acc", lw=1.5, label=f"Строка {mid_row} (горизонт)")
    ax3.set_title(f"3. Горизонтальный срез дальности (Строка {mid_row})", fontsize=10)
    ax3.set_xlabel("Столбец (Col)")
    ax3.set_ylabel("Дистанция (м)")
    ax3.set_ylim(0, max(35.0, np.percentile(valid_points, 90) if len(valid_points) else 50))
    ax3.grid(True, linestyle="--", alpha=0.5)
    ax3.legend(loc="upper right", fontsize=9)

    # 4. Histogram & Value Distribution
    ax4 = plt.subplot(2, 2, 4)
    if len(valid_points) > 0:
        counts, bins, patches = ax4.hist(
            valid_points, bins=80, range=(0, min(100.0, np.max(valid_points))),
            color="#2ca02c", edgecolor="#1b611b", alpha=0.75
        )
        med = np.median(valid_points)
        p95 = np.percentile(valid_points, 95)
        ax4.axvline(med, color="red", linestyle="--", lw=1.5, label=f"Медиана: {med:.1f} м")
        ax4.axvline(p95, color="orange", linestyle=":", lw=1.5, label=f"95% перцентиль: {p95:.1f} м")
        ax4.legend(loc="upper right", fontsize=9)
    ax4.set_title("4. Распределение дистанций (> 0 м)", fontsize=10)
    ax4.set_xlabel("Дистанция (м)")
    ax4.set_ylabel("Количество точек")
    ax4.grid(True, linestyle="--", alpha=0.5)

    plt.suptitle(
        f"LDT-2026: Анализ Range Image — {os.path.basename(file_path)} "
        f"[{frame.shape[0]}x{frame.shape[1]}]",
        fontsize=13,
        fontweight="bold",
    )
    plt.tight_layout()

    if save_path:
        plt.savefig(save_path, dpi=150, bbox_inches="tight")
        print(f"Visualization saved to: {os.path.abspath(save_path)}")

    if not no_show:
        plt.show()
    else:
        plt.close(fig)


def main():
    parser = argparse.ArgumentParser(
        description="Visualize a single LiDAR range frame with matplotlib and display range metrics."
    )
    parser.add_argument(
        "path",
        nargs="?",
        default=None,
        help="Path to .npy frame (default: frames/frame_000001.npy)",
    )
    parser.add_argument(
        "--frame",
        type=int,
        default=None,
        help="Frame index number (e.g. 1 for frame_000001.npy)",
    )
    parser.add_argument(
        "--save",
        type=str,
        default=None,
        help="Optional path to save plot as image (PNG/PDF)",
    )
    parser.add_argument(
        "--no-show",
        action="store_true",
        help="Do not display interactive matplotlib window (useful for headless/scripts)",
    )

    args = parser.parse_args()

    target_spec = args.path
    if args.frame is not None:
        target_spec = str(args.frame)

    frame_path = find_default_frame(target_spec)
    frame = np.load(frame_path)

    # 1. Print metrics
    print_frame_statistics(frame, frame_path)

    # 2. Show visualization
    visualize_frame(frame, frame_path, save_path=args.save, no_show=args.no_show)


if __name__ == "__main__":
    main()
