import os
import pickle
from pathlib import Path
import sqlite3
import time
from contextlib import contextmanager

import numpy as np
import open3d as o3d
import rerun as rr
from rosbags.typesys import Stores, get_typestore
from scipy.spatial.transform import Rotation as R
import random

DB3_PATH = Path("../dataset/roundT_doubleT/roundT_doubleT_0.db3")
LIDAR_TOPIC = "/lidar_points"
CACHE_DIR = Path(".cache")
FRAME_INDEX = 90

TRAIN_SIZE = np.array([2.1, 2.0, 3.0]) * 0.5
BOTTOM_HIT_OFFSET = np.array([0, 0, 0.1])

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


def timer_decorator(func):
    """Декоратор для замера времени работы функции."""
    def wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        result = func(*args, **kwargs)
        elapsed = (time.perf_counter() - start_time) * 1000
        print(f"[TIME FUNC] {func.__name__}: {elapsed:.2f} ms")
        return result
    return wrapper


def rotate_points_around_axis(points: np.ndarray, axis: list | np.ndarray, angle_degrees: float) -> np.ndarray:
    axis_normalized = np.array(axis, dtype=np.float64) / np.linalg.norm(axis)
    rotation = R.from_rotvec(axis_normalized * np.radians(angle_degrees))
    return rotation.apply(points)


def perform_boxcast(points: np.ndarray, origin: np.ndarray, direction: np.ndarray, box_size: np.ndarray, max_dist: float, step: float = 0.05):
    direction = direction / np.linalg.norm(direction)
    half_size = box_size * 0.5

    # 1. Быстрый Crop: оставляем только точки в туннеле движения raycast
    # Вычисляем AABB для всего луча от 0 до max_dist
    p_end = origin + direction * max_dist
    sweep_min = np.minimum(origin, p_end) - half_size
    sweep_max = np.maximum(origin, p_end) + half_size

    crop_mask = np.all((points >= sweep_min) & (points <= sweep_max), axis=1)
    sub_points = points[crop_mask]

    if len(sub_points) == 0:
        return None, max_dist, None

    # 2. Ищем пересечение только по усеченному облаку точек
    curr_dist = 0.0
    while curr_dist <= max_dist:
        center = origin + direction * curr_dist
        min_bound = center - half_size
        max_bound = center + half_size

        mask = np.all((sub_points >= min_bound) & (sub_points <= max_bound), axis=1)
        if np.any(mask):
            return center, curr_dist, sub_points[mask]

        curr_dist += step

    return None, max_dist, None


def read_single_frame_raw(db_path: Path, target_idx: int):
    """Прямое чтение кадра из файла DB3 (без кэша)."""
    with timer("Read DB3 (total raw)"):
        with timer("  1. SQLite Connect & Query"):
            typestore = get_typestore(Stores.ROS2_HUMBLE)
            conn = sqlite3.connect(db_path)
            cursor = conn.cursor()

            cursor.execute("SELECT id, type FROM topics WHERE name = ?", (LIDAR_TOPIC,))
            topic_row = cursor.fetchone()
            if not topic_row:
                conn.close()
                raise ValueError(f"Топик {LIDAR_TOPIC} не найден")
            topic_id, msg_type = topic_row

            cursor.execute(
                """
                SELECT timestamp, data 
                FROM messages 
                WHERE topic_id = ? 
                ORDER BY timestamp ASC 
                LIMIT 1 OFFSET ?
                """,
                (topic_id, target_idx),
            )
            msg_row = cursor.fetchone()
            conn.close()

            if not msg_row:
                raise IndexError(f"Кадр с индексом {target_idx} не найден в {db_path.name}")

            timestamp, rawdata = msg_row

        with timer("  2. CDR Deserialization"):
            msg = typestore.deserialize_cdr(rawdata, msg_type)

        with timer("  3. Point Cloud NumPy Parsing"):
            offsets = {field.name: field.offset for field in msg.fields}
            n_points = len(msg.data) // msg.point_step

            buf = np.frombuffer(msg.data, dtype=np.uint8).reshape(n_points, msg.point_step)
            x = buf[:, offsets["x"] : offsets["x"] + 4].view(np.float32).ravel()
            y = buf[:, offsets["y"] : offsets["y"] + 4].view(np.float32).ravel()
            z = buf[:, offsets["z"] : offsets["z"] + 4].view(np.float32).ravel()

            points = np.stack([x, y, z], axis=1)

    return points, timestamp


def get_frame_cached(db_path: Path, target_idx: int, cache_dir: Path = CACHE_DIR):
    cache_dir.mkdir(parents=True, exist_ok=True)
    cache_file = cache_dir / f"{db_path.stem}_frame_{target_idx}.pkl"

    if cache_file.exists():
        with timer("Cache Read (Pickle)"):
            print(f"[CACHE] Загрузка кадра #{target_idx} из кэша: {cache_file.name}")
            with open(cache_file, "rb") as f:
                data = pickle.load(f)
                return data["points"], data["timestamp"]

    print(f"[DB3] Чтение кадра #{target_idx} из базы данных...")
    points, timestamp = read_single_frame_raw(db_path, target_idx)

    with timer("Cache Write (Pickle)"):
        with open(cache_file, "wb") as f:
            pickle.dump({"points": points, "timestamp": timestamp}, f)

    return points, timestamp


@timer_decorator
def train_shapecast(points):
    col_first = [255, 230, 230]
    col_sec = [255, 180, 180]
    STEP = 5.0
    offset = np.array([0.0, 0.0, 0.0])

    with timer("Train Shapecast"):
        # find start pos
        origin = np.array([-0.9, -5.0, 1.0])
        direction = np.array([0.0, 0.0, -1.0])
        y_box_size = np.array([0.3, 5.0, 0.2])
        x_box_size = np.array([0.2, 5.0, 0.3])

        for i in range(30):
            origin = origin + np.array([0.0, -STEP, 0.0])
            # cast top
            hit_center, hit_dist, hit_points = perform_boxcast(points, origin, direction, y_box_size, max_dist=5.0)
            if hit_center is None:
                exit("No hit")
            rr.log(f"world/start{r()}", rr.Boxes3D(centers=[hit_center], half_sizes=[y_box_size / 2], colors=[col_first]))
            rr.log(f"world/start{r()}", rr.Points3D(hit_points, radii=0.05, colors=col_first))
            top_pos = origin + hit_dist * direction + BOTTOM_HIT_OFFSET

            left_pos = top_pos - np.array([-0.25, 0.0, 0.12])
            # cast left
            direction = np.array([-1.0, 0.0, 0.0])
            hit_center, hit_dist, hit_points = perform_boxcast(points, left_pos, direction, y_box_size, max_dist=15.0)

            if hit_center is None:
                continue
                # exit("No hit")
            rr.log(f"world/start{r()}", rr.Boxes3D(centers=[hit_center], half_sizes=[x_box_size / 2], colors=[col_first]))
            rr.log(f"world/start{r()}", rr.Points3D(hit_points, radii=0.05, colors=col_first))
            left_pos = left_pos + hit_dist * direction + BOTTOM_HIT_OFFSET
            left_pos = left_pos + np.array([0.0, -STEP, 0.0])


def main():
    with timer("Rerun Init"):
        rr.init("lidar_single_frame_debug", spawn=True)
        rr.log("world", rr.Clear(recursive=True))

    # Чтение кадра с кэшированием
    points, timestamp = get_frame_cached(DB3_PATH, target_idx=FRAME_INDEX)
    
    # with timer("Rotate Points"):
    #     points = rotate_points_around_axis(points, axis=[0.0, 1.0, 0.0], angle_degrees=-4.0)

    with timer("Rerun Setup Logs"):
        rr.set_time("bag_time", sequence=FRAME_INDEX)
        rr.log("world/train", rr.Boxes3D(centers=[0, -4, 0], half_sizes=[TRAIN_SIZE], colors=[[20, 255, 20]]))
        rr.log("world/points", rr.Points3D(points, radii=0.02, colors=[200, 200, 200]))

    # Запуск логики кастинга
    train_shapecast(points)


if __name__ == "__main__":
    main()