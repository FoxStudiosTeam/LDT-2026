#!/usr/bin/env python3
"""
bag_player.py — минималистичный проигрыватель ROS2 bag (sqlite3/mcap) с полным
preload сообщений в RAM и точным по времени воспроизведением (без чтения с диска
в реальном времени), плюс зацикливание.

Убирает из уравнения диск/mcap-парсинг во время воспроизведения — если джиттер
останется, значит дело не в I/O плеера.

Usage:
    source /opt/ros/humble/setup.bash
    python3 bag_player.py /path/to/bag_dir [--loop] [--rate 1.0] [--topics /lidar_points]

Требует: rosbag2_py, rclpy (из ROS2 humble)
"""

import argparse
import sys
import time
from dataclasses import dataclass

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from rclpy.serialization import deserialize_message
from rosidl_runtime_py.utilities import get_message

import rosbag2_py


@dataclass
class Msg:
    topic: str
    t_ns: int          # исходный timestamp записи в баге (recv time на записи)
    raw: bytes
    msg_type: type


def load_bag(bag_path: str, topics_filter=None):
    """Полностью грузит бэг в память: (topic, t_ns, raw_bytes, msg_type)."""
    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id="")  # auto-detect (sqlite3/mcap)
    converter_options = rosbag2_py.ConverterOptions(
        input_serialization_format="cdr", output_serialization_format="cdr"
    )
    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)

    topic_types = reader.get_all_topics_and_types()
    type_map = {t.name: t.type for t in topic_types}

    msgs = []
    msg_type_cache = {}

    while reader.has_next():
        topic, data, t = reader.read_next()
        if topics_filter and topic not in topics_filter:
            continue
        if topic not in msg_type_cache:
            msg_type_cache[topic] = get_message(type_map[topic])
        msgs.append(Msg(topic=topic, t_ns=t, raw=bytes(data), msg_type=msg_type_cache[topic]))

    msgs.sort(key=lambda m: m.t_ns)
    return msgs, type_map


class BagPlayer(Node):
    def __init__(self, msgs, type_map, topics_filter, loop, rate, qos_override):
        super().__init__("bag_player_ram")
        self.msgs = msgs
        self.loop = loop
        self.rate = rate

        qos = qos_override or QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=5,
            durability=DurabilityPolicy.VOLATILE,
        )

        self.publishers_map = {}
        seen_topics = {m.topic for m in msgs}
        for topic in seen_topics:
            msg_type = next(m.msg_type for m in msgs if m.topic == topic)
            self.publishers_map[topic] = self.create_publisher(msg_type, topic, qos)

        self.get_logger().info(
            f"Loaded {len(msgs)} messages across {len(seen_topics)} topics into RAM. "
            f"Loop={loop} Rate={rate}"
        )

    def play_once(self):
        if not self.msgs:
            return
        base_bag_t0 = self.msgs[0].t_ns
        base_wall_t0 = time.monotonic_ns()

        for m in self.msgs:
            target_offset_ns = int((m.t_ns - base_bag_t0) / self.rate)
            target_wall_ns = base_wall_t0 + target_offset_ns
            now = time.monotonic_ns()
            sleep_ns = target_wall_ns - now
            if sleep_ns > 0:
                # busy-wait для последних <1ms точности, sleep для остального
                if sleep_ns > 2_000_000:
                    time.sleep((sleep_ns - 1_000_000) / 1e9)
                while time.monotonic_ns() < target_wall_ns:
                    pass

            pub = self.publishers_map[m.topic]
            msg = deserialize_message(m.raw, m.msg_type)
            pub.publish(msg)

    def run(self):
        try:
            while True:
                self.play_once()
                if not self.loop:
                    break
                self.get_logger().info("Loop restart")
        except KeyboardInterrupt:
            pass


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("bag_path")
    parser.add_argument("--loop", action="store_true", help="Зациклить воспроизведение")
    parser.add_argument("--rate", type=float, default=1.0, help="Множитель скорости")
    parser.add_argument("--topics", nargs="*", default=None, help="Фильтр топиков")
    args = parser.parse_args()

    print(f"Loading bag into RAM: {args.bag_path} ...")
    msgs, type_map = load_bag(args.bag_path, set(args.topics) if args.topics else None)
    if not msgs:
        print("Нет сообщений (проверь путь/фильтр топиков)")
        sys.exit(1)
    print(f"Loaded {len(msgs)} messages.")

    rclpy.init()
    node = BagPlayer(msgs, type_map, args.topics, args.loop, args.rate, qos_override=None)
    node.run()
    node.destroy_node()
    rclpy.shutdown()


def select():
    pass

if __name__ == "__main__":
    main()
