import numpy as np
import open3d as o3d

# 1. Загружаем npy файл
points = np.load("/home/kaiv/LDT-2026/constructed_lidar/2026-09-19_14-23-43/doubleT_platform_poses.npy")  # Укажите путь к вашему файлу

# Если массив имеет форму (N, 3) или (N, 4)
if points.shape[1] >= 3:
    xyz = points[:, :3]

# 2. Создаем объект Open3D
pcd = o3d.geometry.PointCloud()
pcd.points = o3d.utility.Vector3dVector(xyz)

# 3. Сохраняем в PLY или PCD
o3d.io.write_point_cloud("map.ply", pcd)
print("Файл map.ply успешно сохранен!")