from pathlib import Path
import numpy as np
import open3d as o3d
from kiss_icp.datasets import dataset_factory
from kiss_icp.pipeline import OdometryPipeline

data_path = Path("../dataset/doubleT_platform")
topic = "/lidar_points"

# Создаем датасет (укажите ваш формат, например: "rosbag", "mcap" или "generic")
dataset = dataset_factory(dataloader="rosbag", data_dir=data_path, topic=topic)

pipeline = OdometryPipeline(dataset=dataset)

print("Запуск KISS-ICP и сборка карты...")
pipeline.run()

# Вариант А: Получить итоговую локальную карту напрямую из объекта odometry
map_cloud = pipeline.odometry.local_map.point_cloud()

pcd = o3d.geometry.PointCloud()
pcd.points = o3d.utility.Vector3dVector(map_cloud)

output_filename = "doubleT_platform_map.ply"
o3d.io.write_point_cloud(output_filename, pcd)
print(f"Карта успешно сохранена в файл: {output_filename}")