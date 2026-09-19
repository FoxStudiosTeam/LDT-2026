import numpy as np
from rosbag2_py import SequentialReader, StorageOptions, ConverterOptions
from rclpy.serialization import deserialize_message
from rosidl_runtime_py.utilities import get_message
from sensor_msgs_py import point_cloud2

from kiss_icp.kiss_icp import KissICP
from kiss_icp.config import KISSConfig

def read_pointclouds(bag_path, topic_name='/lidar_points'):
    storage_options = StorageOptions(uri=bag_path, storage_id='sqlite3')
    converter_options = ConverterOptions('', '')
    reader = SequentialReader()
    reader.open(storage_options, converter_options)

    type_map = {t.name: t.type for t in reader.get_all_topics_and_types()}

    while reader.has_next():
        topic, data, t = reader.read_next()
        if topic != topic_name:
            continue
        msg_type = get_message(type_map[topic])
        msg = deserialize_message(data, msg_type)

        points = point_cloud2.read_points_numpy(
            msg, field_names=('x', 'y', 'z'), skip_nans=True
        )
        yield t, points.astype(np.float64)


config = KISSConfig()
odometry = KissICP(config=config)

trajectory = []  # список 4x4 матриц поз
timestamps = []

for t, points in read_pointclouds('../dataset/doubleT_platform'):
    # Преобразование временной метки ROS (нс) в секунды (float)
    timestamps_sec = t / 1e9
    
    # register_frame принимает массив точек и метку времени
    odometry.register_frame(points, timestamps=timestamps_sec)
    
    # Получение текущей зарегистрированной позы (4x4)
    pose = odometry.pose
    trajectory.append(pose)
    timestamps.append(t)

# Извлечь x, y, z траектории
xyz = np.array([T[:3, 3] for T in trajectory])