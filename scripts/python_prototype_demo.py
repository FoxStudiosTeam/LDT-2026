#!/usr/bin/env python3
"""
python_prototype_demo.py

Демонстрационный скрипт для прототипирования алгоритмов на Python с использованием
сырых кадров (без интерполяции), сохранённых Rust Viewer в RENDER_PATH.

Использование:
    python scripts/python_prototype_demo.py [--dir ./frames]
"""

import argparse
import glob
import os
import sys

try:
    import numpy as np
except ImportError:
    print("Требуется numpy: pip install numpy")
    sys.exit(1)


def process_frame(file_path: str):
    """
    Загрузка и обработка одного сырого кадра дальности.
    Матрица имеет форму [128, crop_w], dtype=float32.
    Каждое значение — дальность в метрах (0.0 — отсутствие возврата).
    """
    raw = np.load(file_path)
    if raw.ndim == 3:
        depth = raw[:, :, 0]
        intensity = raw[:, :, 1]
    else:
        depth = raw
        intensity = None

    height, width = depth.shape
    valid_mask = depth > 0.0
    valid_points = depth[valid_mask]

    min_range = valid_points.min() if len(valid_points) > 0 else 0.0
    max_range = valid_points.max() if len(valid_points) > 0 else 0.0

    print(f"Кадр {os.path.basename(file_path)}:")
    chan_str = f" x 2 (range + intensity)" if intensity is not None else ""
    print(f"  Разрешение: {width}x{height}{chan_str} (колонок x колец)")
    print(f"  Число валидных точек: {len(valid_points)} из {depth.size} ({len(valid_points)/depth.size*100:.1f}%)")
    print(f"  Диапазон дальности: [{min_range:.2f}м .. {max_range:.2f}м]")
    if intensity is not None:
        valid_i = intensity[valid_mask]
        print(f"  Диапазон intensity: [{intensity.min():.1f} .. {intensity.max():.1f}], среднее: {valid_i.mean():.1f}")

    # ── Пример алгоритма: поиск ближайшего объекта в колее ──
    # Берем центральный сектор по ширине (колея) и нижние кольца (дорожное полотно / препятствие)
    center_x = width // 2
    track_half_w = int(width * 0.15)
    roi_depth = depth[height//3:height, center_x - track_half_w : center_x + track_half_w]
    roi_valid = roi_depth[roi_depth > 0.5]

    if len(roi_valid) > 0:
        closest_obstacle = roi_valid.min()
        print(f"  [ROI Габарит] Ближайшая точка в полосе: {closest_obstacle:.2f}м")
    else:
        print("  [ROI Габарит] Препятствий в полосе не обнаружено")


def main():
    parser = argparse.ArgumentParser(description="Python Prototyping on raw LiDAR frames")
    parser.add_argument("--dir", default="./frames", help="Директория с .npy кадрами (RENDER_PATH)")
    args = parser.parse_args()

    files = sorted(glob.glob(os.path.join(args.dir, "*.npy")))
    if not files:
        print(f"Кадры не найдены в '{args.dir}'.")
        print("Убедитесь, что в .env задан RENDER_PATH, например:")
        print("    RENDER_PATH = \"./frames\"")
        return

    print(f"Найдено {len(files)} кадров в '{args.dir}'.")
    for f in files[:5]:
        process_frame(f)
        print("-" * 50)


if __name__ == "__main__":
    main()

