from pathlib import Path

import numpy as np
import rerun as rr
from rosbags.highlevel import AnyReader
from rosbags.typesys import Stores, get_typestore


DATASET_DIR = Path("../dataset")
LIDAR_TOPIC = "/sensing/lidar/hesai128/pointcloud"


def find_replays():
    return sorted(p for p in DATASET_DIR.iterdir() if p.is_dir())


def play_replay(bag_path: Path):
    typestore = get_typestore(Stores.ROS2_HUMBLE)

    rr.init(f"lidar - {bag_path.name}", spawn=True)

    with AnyReader(
        [bag_path],
        default_typestore=typestore,
    ) as reader:
        connections = [
            c
            for c in reader.connections
            if c.topic == LIDAR_TOPIC
        ]

        for connection, timestamp, rawdata in reader.messages(
            connections=connections
        ):
            msg = reader.deserialize(rawdata, connection.msgtype)

            offsets = {
                field.name: field.offset
                for field in msg.fields
            }

            n_points = len(msg.data) // msg.point_step

            buf = np.frombuffer(
                msg.data,
                dtype=np.uint8,
            ).reshape(n_points, msg.point_step)

            x = buf[
                :, offsets["x"]:offsets["x"] + 4
            ].view(np.float32).ravel()

            y = buf[
                :, offsets["y"]:offsets["y"] + 4
            ].view(np.float32).ravel()

            z = buf[
                :, offsets["z"]:offsets["z"] + 4
            ].view(np.float32).ravel()

            xyz = np.stack([x, y, z], axis=1)

            rr.set_time("bag_time", sequence=timestamp)
            rr.log("lidar/pointcloud", rr.Points3D(xyz))


def main():
    while True:
        replays = find_replays()

        print("\n=== LiDAR Replay Viewer ===\n")

        if not replays:
            print("dataset/ is empty")
            return

        for i, replay in enumerate(replays, 1):
            print(f"{i}. {replay.name}")

        print("\nq. Quit")

        choice = input("\nSelect replay: ").strip()

        if choice.lower() == "q":
            return

        try:
            index = int(choice) - 1
            replay = replays[index]
        except (ValueError, IndexError):
            print("Invalid selection")
            continue

        print(f"\nOpening: {replay}")
        play_replay(replay)


if __name__ == "__main__":
    main()