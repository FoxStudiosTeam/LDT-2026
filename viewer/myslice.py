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
from utils import *


DB3_PATH = Path("../dataset/doubleT_obstacle/doubleT_obstacle_0.db3")
LIDAR_TOPIC = "/sensing/lidar/hesai128/pointcloud"
CACHE_DIR = Path(".cache")

def main():
    full_cache_path = cache_entire_bag(DB3_PATH, CACHE_DIR, LIDAR_TOPIC)
    with timer("Cached Replay"):
        replay = CachedReplay(full_cache_path)
        points, timestamp = replay.get_frame(1)

    points = filter_by_height(points, -1)

    with timer("Rerun Init"):
        rr.init("lidar_single_frame_debug", spawn=True)
        rr.log("world", rr.Clear(recursive=True))
        rr.log("world/points", rr.Points3D(points, radii=0.02, colors=[100, 100, 100]))

    with timer("Render"):
        from PIL import Image

        depth_map = project_points_to_depth_map(
            points, resolution=(512, 2560), method="rbf"
        )

        img = Image.fromarray(depth_map, mode="L")
        img.save("depth_map_rect.png")





if __name__ == "__main__":
    main()