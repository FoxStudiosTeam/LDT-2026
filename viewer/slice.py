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

DB3_PATH = Path("../dataset/doubleT_obstacle/doubleT_obstacle_0.db3")
LIDAR_TOPIC = "/sensing/lidar/hesai128/pointcloud"
CACHE_DIR = Path(".cache")
FRAME_INDEX = 100

TRAIN_SIZE = np.array([2.1, 2.0, 3.0]) * 0.5
BOTTOM_HIT_OFFSET = np.array([0, 0, 0.1])

# Система координат точек: x, z, y -> индекс 0 = x (вправо), 1 = z (вперёд), 2 = y (вверх).
# Т.е. "высота" - это points[:, 2] (y), а плоскость top-view - это (x, z) = (points[:,0], points[:,1]).
AXIS_X = 0
AXIS_FWD = 1   # z
AXIS_UP = 2    # y

# Порог по высоте: оставляем только точки ниже этого уровня (убираем провода/потолок/шум над составом)
Y_MAX = 2.0

# Параметры heightmap
HEIGHTMAP_RESOLUTION = 0.05  # м/пиксель
HEIGHTMAP_X_RANGE = (-10.0, 10.0)   # диапазон по x
HEIGHTMAP_FWD_RANGE = (-5.0, 15.0)  # диапазон по z (вперёд)


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

    p_end = origin + direction * max_dist
    sweep_min = np.minimum(origin, p_end) - half_size
    sweep_max = np.maximum(origin, p_end) + half_size

    crop_mask = np.all((points >= sweep_min) & (points <= sweep_max), axis=1)
    sub_points = points[crop_mask]

    if len(sub_points) == 0:
        return None, max_dist, None

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


def filter_by_height(points: np.ndarray, y_max: float) -> np.ndarray:
    """Оставляем только точки с высотой (ось AXIS_UP = y) меньше y_max."""
    mask = points[:, AXIS_UP] < y_max
    return points[mask]


@timer_decorator
def build_heightmap(
    points: np.ndarray,
    resolution: float = HEIGHTMAP_RESOLUTION,
    x_range: tuple[float, float] = HEIGHTMAP_X_RANGE,
    fwd_range: tuple[float, float] = HEIGHTMAP_FWD_RANGE,
) -> tuple[np.ndarray, tuple[float, float, float, float]]:
    """
    Строит heightmap top-down (вид сверху вдоль оси y).
    Плоскость - (x, z), значение ячейки - максимальная высота (y) среди точек в ней.
    Возвращает (grid, extent) для использования с plt.imshow(..., extent=extent).
    """
    x_min, x_max = x_range
    fwd_min, fwd_max = fwd_range

    n_cols = int(np.ceil((x_max - x_min) / resolution))
    n_rows = int(np.ceil((fwd_max - fwd_min) / resolution))

    grid = np.full((n_rows, n_cols), np.nan, dtype=np.float32)

    xs = points[:, AXIS_X]
    fs = points[:, AXIS_FWD]
    hs = points[:, AXIS_UP]

    in_range = (xs >= x_min) & (xs < x_max) & (fs >= fwd_min) & (fs < fwd_max)
    xs, fs, hs = xs[in_range], fs[in_range], hs[in_range]

    col_idx = ((xs - x_min) / resolution).astype(np.int32)
    row_idx = ((fs - fwd_min) / resolution).astype(np.int32)

    # Заполняем ячейки максимальной высотой (для точек, попадающих в одну ячейку)
    flat_idx = row_idx * n_cols + col_idx
    order = np.argsort(hs)  # последний записанный (max) переживёт дубли
    flat_idx_sorted = flat_idx[order]
    hs_sorted = hs[order]
    grid.ravel()[flat_idx_sorted] = hs_sorted  # берёт max, т.к. отсортировано по возрастанию

    extent = (x_min, x_max, fwd_min, fwd_max)
    return grid, extent


def show_heightmap(grid: np.ndarray, extent: tuple[float, float, float, float]):
    fig, ax = plt.subplots(figsize=(8, 8))
    im = ax.imshow(
        grid,
        extent=extent,
        origin="lower",
        cmap="viridis",
        interpolation="nearest",
    )
    ax.set_xlabel("x, м")
    ax.set_ylabel("z (вперёд), м")
    ax.set_title("Heightmap (top-down view)")
    fig.colorbar(im, ax=ax, label="высота (y), м")
    plt.tight_layout()
    plt.show()


def main():
    with timer("Rerun Init"):
        rr.init("lidar_single_frame_debug", spawn=True)
        rr.log("world", rr.Clear(recursive=True))

    # Чтение кадра с кэшированием
    points, timestamp = get_frame_cached(DB3_PATH, target_idx=FRAME_INDEX)

    with timer("Rotate Points"):
        points = rotate_points_around_axis(points, axis=[0.0, 1.0, 0.0], angle_degrees=-4.0)

    with timer("Filter by height"):
        points = filter_by_height(points, Y_MAX)

    with timer("Rerun Setup Logs"):
        rr.set_time("bag_time", sequence=FRAME_INDEX)
        rr.log("world/train", rr.Boxes3D(centers=[0, -4, 0], half_sizes=[TRAIN_SIZE], colors=[[20, 255, 20]]))
        rr.log("world/points", rr.Points3D(points, radii=0.02, colors=[200, 200, 200]))
        # Сюда позже будут добавлены линии рельс, найденные по heightmap:
        # rr.log("world/rails/left", rr.LineStrips3D([...]))
        # rr.log("world/rails/right", rr.LineStrips3D([...]))

    grid, extent = build_heightmap(points)
    show_heightmap(grid, extent)


if __name__ == "__main__":
    main()