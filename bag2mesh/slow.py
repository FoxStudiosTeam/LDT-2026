import rosbag2_py
from sensor_msgs_py import point_cloud2
from rclpy.serialization import deserialize_message
from sensor_msgs.msg import PointCloud2
import numpy as np
import open3d as o3d

def read_frames(bag_path, topic_name):
    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id='sqlite3')
    converter_options = rosbag2_py.ConverterOptions('', '')
    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)

    frames = []
    a = False
    while reader.has_next():
        topic, data, t = reader.read_next()
        if topic == topic_name:
            msg = deserialize_message(data, PointCloud2)
            if not a:
                print([f.name for f in msg.fields], [f.datatype for f in msg.fields])
                a = True

            # structured array вместо read_points_numpy
            cloud_arr = point_cloud2.read_points(
                msg, field_names=("x", "y", "z"), skip_nans=True
            )

            # structured array -> обычный (N,3) float массив
            pts = np.column_stack([
                cloud_arr['x'].astype(np.float32),
                cloud_arr['y'].astype(np.float32),
                cloud_arr['z'].astype(np.float32),
            ])

            if pts.shape[0] > 0:
                frames.append(pts)
    return frames

frames = read_frames("../dataset/roundT_doubleT/", "/lidar_points")
print(f"Найдено кадров: {len(frames)}")

def to_pcd(points, voxel=0.05):
    pcd = o3d.geometry.PointCloud()
    pcd.points = o3d.utility.Vector3dVector(points)
    pcd = pcd.voxel_down_sample(voxel)
    pcd.estimate_normals(
        search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=voxel*3, max_nn=30)
    )
    return pcd

def register_sequence(frames, voxel=0.05, max_corr_dist=0.5):
    pcds = [to_pcd(f, voxel) for f in frames]

    global_pose = np.eye(4)
    accumulated = o3d.geometry.PointCloud()
    accumulated += pcds[0]
    poses = [global_pose.copy()]

    for i in range(1, len(pcds)):
        source = pcds[i]
        target = pcds[i-1]

        # Point-to-plane ICP — хорошо работает на "трубчатых" структурах
        reg = o3d.pipelines.registration.registration_icp(
            source, target, max_corr_dist,
            np.eye(4),
            o3d.pipelines.registration.TransformationEstimationPointToPlane(),
            o3d.pipelines.registration.ICPConvergenceCriteria(max_iteration=50)
        )

        global_pose = global_pose @ reg.transformation
        poses.append(global_pose.copy())

        transformed = pcds[i].transform(global_pose)
        accumulated += transformed

        if i % 20 == 0:
            print(f"Кадр {i}/{len(pcds)}, fitness={reg.fitness:.3f}")

    return accumulated, poses

merged_cloud, poses = register_sequence(frames)
merged_cloud = merged_cloud.voxel_down_sample(0.03)
o3d.io.write_point_cloud("tunnel_merged.ply", merged_cloud)

pcd = o3d.io.read_point_cloud("tunnel_merged.ply")
pcd, _ = pcd.remove_statistical_outlier(nb_neighbors=20, std_ratio=2.0)

pcd.estimate_normals(
    search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=0.15, max_nn=30)
)
pcd.orient_normals_consistent_tangent_plane(k=30)

mesh, densities = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(
    pcd, depth=10
)

densities = np.asarray(densities)
mask = densities < np.quantile(densities, 0.03)
mesh.remove_vertices_by_mask(mask)

mesh = mesh.filter_smooth_simple(number_of_iterations=2)
mesh.compute_vertex_normals()

o3d.io.write_triangle_mesh("tunnel_mesh.obj", mesh)
