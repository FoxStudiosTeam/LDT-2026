import os
import pickle
from pathlib import Path
import sqlite3
import time
from contextlib import contextmanager

import numpy as np
import open3d as o3d
import rerun as rr
import matplotlib.pyplot as plt
from rosbags.typesys import Stores, get_typestore
from scipy.spatial.transform import Rotation as R
import random
from scipy.interpolate import Rbf, griddata
from scipy.ndimage import distance_transform_edt
from PIL import Image
from typing import Tuple


def r():
    return random.random()

@contextmanager
def timer(name: str):
    """Контекстный менеджер для замера времени выполнения блока кода."""
    start_time = time.perf_counter()
    try:
        yield
    finally:
        elapsed = (time.perf_counter() - start_time) * 1000  # переводим в ms
        print(f"[TIME] {name}: {elapsed:.2f} ms")

def rotate_points_around_axis(points: np.ndarray, axis: list | np.ndarray, angle_degrees: float) -> np.ndarray:
    axis_normalized = np.array(axis, dtype=np.float64) / np.linalg.norm(axis)
    rotation = R.from_rotvec(axis_normalized * np.radians(angle_degrees))
    return rotation.apply(points)

def cache_entire_bag(db_path: Path, cache_dir: Path, lodar_topic: str) -> Path:
    cache_dir.mkdir(parents=True, exist_ok=True)
    cache_file = cache_dir / f"{db_path.stem}_full.npz"

    if cache_file.exists():
        print(f"[CACHE] Полный кэш уже существует: {cache_file.name}")
        return cache_file

    print(f"[DB3] Начинаем полную конвертацию {db_path.name} в NPZ...")
    typestore = get_typestore(Stores.ROS2_HUMBLE)
    
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()

    # Получаем topic_id и msg_type
    cursor.execute("SELECT id, type FROM topics WHERE name = ?", (lodar_topic,))
    topic_row = cursor.fetchone()
    if not topic_row:
        conn.close()
        raise ValueError(f"Топик {lodar_topic} не найден")
    topic_id, msg_type = topic_row

    # Читаем сразу ВСЕ сообщения за один последовательный запрос (без OFFSET)
    cursor.execute(
        "SELECT timestamp, data FROM messages WHERE topic_id = ? ORDER BY timestamp ASC",
        (topic_id,)
    )
    rows = cursor.fetchall()
    conn.close()

    timestamps = []
    frames_dict = {}

    with timer(f"Десериализация {len(rows)} кадров"):
        for idx, (timestamp, rawdata) in enumerate(rows):
            msg = typestore.deserialize_cdr(rawdata, msg_type)
            
            # Быстрый парсинг координат
            offsets = {field.name: field.offset for field in msg.fields}
            n_points = len(msg.data) // msg.point_step
            buf = np.frombuffer(msg.data, dtype=np.uint8).reshape(n_points, msg.point_step)
            
            x = buf[:, offsets["x"] : offsets["x"] + 4].view(np.float32).ravel()
            y = buf[:, offsets["y"] : offsets["y"] + 4].view(np.float32).ravel()
            z = buf[:, offsets["z"] : offsets["z"] + 4].view(np.float32).ravel()
            
            points = np.stack([x, y, z], axis=1)

            timestamps.append(timestamp)
            frames_dict[f"frame_{idx}"] = points

    # Сохраняем все массивы + временные метки в один сжатый файл
    np.savez_compressed(cache_file, timestamps=np.array(timestamps), **frames_dict)
    print(f"[CACHE] Сохранено в {cache_file}")
    return cache_file

class CachedReplay:
    def __init__(self, npz_path: Path):
        with timer("Загрузка NPZ кэша в память"):
            # readinto/mmap позволяет мгновенно обращаться к кадрам
            self.data = np.load(npz_path)
            self.timestamps = self.data["timestamps"]
            self.num_frames = len(self.timestamps)

    def get_frame(self, idx: int) -> tuple[np.ndarray, int]:
        points = self.data[f"frame_{idx}"]
        timestamp = self.timestamps[idx]
        return points, timestamp

def filter_by_height(points: np.ndarray, y_max: float) -> np.ndarray:
    """Оставляем только точки с высотой (ось AXIS_UP = y) меньше y_max."""
    mask = points[:, 2] < y_max
    return points[mask]


def project_points_to_depth_map(
    points: np.ndarray,
    resolution: Tuple[int, int] = (128, 128),
    method: str = "rbf",
) -> np.ndarray:
    """Проецирует 3D-точки на плоскость XZ и генерирует гладкую карту глубин (Y).

    :param points: NumPy массив формы (N, 3) с координатами (x, y, z) в диапазоне
      [-2, 2].
    :param resolution: Кортеж (width, height) — ширина (X) и высота (Z)
      выходного изображения.
    :param method: Метод интерполяции: 'rbf' (максимально гладкий) или 'hybrid'
      (linear + nearest, быстрее).
    :return: 2D NumPy массив uint8 формы (height, width).
    """
    if points.ndim != 2 or points.shape[1] != 3:
        raise ValueError("Массив points должен иметь форму (N, 3)")

    width, height = resolution

    x = points[:, 0]
    y = points[:, 1]
    z = points[:, 2]

    # 1. Масштабирование координат под независимые width (X) и height (Z)
    px = np.clip(((x + 2) / 4 * (width - 1)).astype(np.int32), 0, width - 1)
    pz = np.clip(((z + 2) / 4 * (height - 1)).astype(np.int32), 0, height - 1)

    # 2. Нормализация глубины Y в диапазон [0, 255]
    depth_intensity = np.clip((y + 2) / 4 * 255, 0, 255).astype(np.float32)

    # 3. Дедупликация пикселей: при совпадении координат берем максимальное значение глубины
    pixel_coords = np.column_stack((px, pz))
    unique_coords, inverse_indices = np.unique(
        pixel_coords, axis=0, return_inverse=True
    )

    unique_depths = np.full(len(unique_coords), -np.inf, dtype=np.float32)
    np.maximum.at(unique_depths, inverse_indices, depth_intensity)

    known_x = unique_coords[:, 0]
    known_z = unique_coords[:, 1]

    # 4. Сетка для интерполяции (строки = height/Z, столбцы = width/X)
    grid_x, grid_z = np.meshgrid(np.arange(width), np.arange(height))

    # 5. Интерполяция
    if method == "rbf":
        rbf = Rbf(
            known_x,
            known_z,
            unique_depths,
            function="multiquadric",
            smooth=0.1,
        )
        interpolated_array = rbf(grid_x, grid_z)
    elif method == "hybrid":
        linear_grid = griddata(
            (known_x, known_z),
            unique_depths,
            (grid_x, grid_z),
            method="linear",
        )
        nearest_grid = griddata(
            (known_x, known_z),
            unique_depths,
            (grid_x, grid_z),
            method="nearest",
        )
        interpolated_array = np.where(
            np.isnan(linear_grid), nearest_grid, linear_grid
        )
    else:
        raise ValueError("Метод должен быть 'rbf' или 'hybrid'")

    # 6. Ограничение значений и приведение к uint8 (формат: [height, width])
    return np.clip(interpolated_array, 0, 255).astype(np.uint8)

import numpy as np

def perform_boxcast_fast(points: np.ndarray, origin: np.ndarray, direction: np.ndarray, box_size: np.ndarray, max_dist: float, step: float = 0.05):
    direction = direction / np.linalg.norm(direction)
    half_size = box_size * 0.5

    # 1. Быстрый Crop по всей траектории (AABB)
    p_end = origin + direction * max_dist
    sweep_min = np.minimum(origin, p_end) - half_size
    sweep_max = np.maximum(origin, p_end) + half_size

    crop_mask = np.all((points >= sweep_min) & (points <= sweep_max), axis=1)
    sub_points = points[crop_mask]

    if len(sub_points) == 0:
        return None, max_dist, None

    # 2. Перенос начала координат в origin
    rel_points = sub_points - origin

    # 3. Строим локальную систему координат, где Z совпадает с direction
    z_axis = direction
    # Находим вектор, не коллинеарный Z
    temp = np.array([1.0, 0.0, 0.0]) if abs(z_axis[0]) < 0.9 else np.array([0.0, 1.0, 0.0])
    x_axis = np.cross(temp, z_axis)
    x_axis /= np.linalg.norm(x_axis)
    y_axis = np.cross(z_axis, x_axis)

    # Матрица поворота: Перевод из мировой СК в СК луча
    R = np.vstack([x_axis, y_axis, z_axis])
    local_points = rel_points @ R.T

    # 4. Векторный фильтр по хитбоксу
    in_box_mask = (
        (np.abs(local_points[:, 0]) <= half_size[0]) &
        (np.abs(local_points[:, 1]) <= half_size[1]) &
        (local_points[:, 2] >= 0) &
        (local_points[:, 2] <= max_dist)
    )

    valid_points = sub_points[in_box_mask]
    valid_distances = local_points[in_box_mask, 2]

    if len(valid_points) == 0:
        return None, max_dist, None

    # 5. Находим минимальное расстояние и округляем до шага `step`
    min_idx = np.argmin(valid_distances)
    raw_dist = valid_distances[min_idx]
    
    # Квантование дистанции под ваш step (если требуется точное соответствие шагу)
    hit_dist = np.floor(raw_dist / step) * step
    center = origin + direction * hit_dist

    # Получаем все точки, попавшие в первичное сечение
    hit_mask = np.abs(valid_distances - hit_dist) <= (step / 2)
    return center, hit_dist, valid_points[hit_mask]
