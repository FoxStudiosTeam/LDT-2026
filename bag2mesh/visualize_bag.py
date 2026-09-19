from pathlib import Path
import numpy as np
import rerun as rr

# Чтение ROS2 bag без необходимости иметь установленный ROS2
from rosbags.rosbag2 import Reader
from rosbags.serde import deserialize_cdr

# Пути к вашим файлам
BAG_PATH = "/home/kaiv/LDT-2026/dataset/doubleT_platform"  # Папка с .db3 файлом и metadata.yaml
POSES_PATH = "/home/kaiv/LDT-2026/constructed_lidar/2026-09-19_15-06-06/doubleT_platform_poses.npy"
LIDAR_TOPIC = "/lidar_points"  # Замените на ваш топик с PointCloud2

def unpack_pointcloud2(msg) -> np.ndarray:
    """Извлекает координаты (X, Y, Z) из сообщения PointCloud2."""
    data = msg.data
    point_step = msg.point_step
    
    # Находим смещения полей x, y, z
    offsets = {}
    for field in msg.fields:
        if field.name in ['x', 'y', 'z']:
            offsets[field.name] = field.offset

    # Создаем структурированный dtype с правильными смещениями (offsets) и размером кадра (point_step)
    # Поля 'x', 'y', 'z' считываются как float32 по своим байтовым смещениям
    dtype = np.dtype({
        'names': ['x', 'y', 'z'],
        'formats': ['<f4', '<f4', '<f4'],
        'offsets': [offsets['x'], offsets['y'], offsets['z']],
        'itemsize': point_step
    })

    # Парсим массив через NumPy
    struct_arr = np.frombuffer(data, dtype=dtype)
    
    # Преобразуем в обычный 2D-массив N x 3
    points = np.column_stack((struct_arr['x'], struct_arr['y'], struct_arr['z']))

    # Фильтруем точки от NaN и Inf
    mask = np.isfinite(points).all(axis=1)
    return points[mask]


def main():
    # 1. Инициализация Rerun
    rr.init("bag_and_poses_visualization", spawn=False)
    rr.connect_grpc("rerun+http://192.168.0.100:9876/proxy")

    # 2. Загрузка поз
    poses = np.load(POSES_PATH)
    if poses.ndim == 2 and poses.shape == (4, 4):
        poses = [poses]

    # 3. Чтение ROS2 bag
    frame_idx = 0
    with Reader(BAG_PATH) as reader:
        # Фильтруем сообщения только по нужному топику
        connections = [x for x in reader.connections if x.topic == LIDAR_TOPIC]
        
        for connection, timestamp, rawdata in reader.messages(connections=connections):
            if frame_idx >= len(poses):
                print(f"Кадры в bag превысили количество поз в .npy ({len(poses)}). Прерывание.")
                break

            # Десериализуем сообщение
            msg = deserialize_cdr(rawdata, connection.msgtype)
            
            # Извлекаем облако точек (X, Y, Z)
            points = unpack_pointcloud2(msg)
            
            # Поза платформы для текущего кадра
            pose = poses[frame_idx]
            translation = pose[:3, 3]
            rotation_matrix = pose[:3, :3]

            # Устанавливаем текущий кадр для временной шкалы
            rr.set_time("frame_idx", sequence=frame_idx)

            # 1. Трансформация системы координат платформы (смещение + поворот)
            rr.log(
                "world/platform",
                rr.Transform3D(
                    translation=translation,
                    mat3x3=rotation_matrix,
                )
            )

            # 2. Точка траектории в абсолютных координатах world
            rr.log(
                "world/trajectory",
                rr.Points3D(
                    positions=[translation],
                    radii=0.03,
                    colors=[255, 0, 0]
                )
            )

            # 3. Логируем Облако точек КАК ДОЧЕРНИЙ ЭЛЕМЕНТ платформы
            # Привязывая к "world/platform/points", Rerun автоматически
            # применит трансформацию "world/platform" к облаку!
            rr.log(
                "world/platform/points",
                rr.Points3D(
                    positions=points,
                    radii=0.01,
                    colors=[200, 200, 200]
                )
            )

            frame_idx += 1

    print(f"Обработано {frame_idx} кадров.")

if __name__ == "__main__":
    main()