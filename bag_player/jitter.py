#!/usr/bin/env python3
"""
measure_pointcloud_jitter.py

Minimal, low-overhead PointCloud2 subscriber that records arrival timestamps
and header timestamps, without doing any per-message printing (which would
itself distort timing). Writes results to a CSV after N samples, then prints
a summary of inter-arrival jitter.

Usage:
    source /opt/ros/humble/setup.bash
    python3 measure_pointcloud_jitter.py /your/pointcloud/topic [num_samples]

Compare the resulting jitter distribution to what the Rust listener reports.
- If Python shows smooth, low-jitter deltas -> the problem is in the Rust
  consumer (blocking println!, executor contention, etc).
- If Python also shows the 10ms-1000ms swings -> the problem is upstream
  (publisher rate, QoS settings, DDS/network layer), not the Rust code.
"""

import sys
import time
import csv

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from sensor_msgs.msg import PointCloud2


class JitterProbe(Node):
    def __init__(self, topic: str, num_samples: int):
        super().__init__('jitter_probe')
        self.num_samples = num_samples
        self.records = []  # (recv_monotonic, header_stamp_sec, msg_size_bytes)
        self.prev_recv = None

        # Match whatever QoS the publisher actually uses where possible.
        # Best-effort + keep-last is typical for high-rate sensor data;
        # if this doesn't match the publisher's QoS you may get zero
        # messages or subtle delivery differences, which is itself
        # useful diagnostic info.
        qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=5,
            durability=DurabilityPolicy.VOLATILE,
        )

        self.sub = self.create_subscription(
            PointCloud2, topic, self.callback, qos
        )
        self.get_logger().info(f"Subscribed to {topic}, collecting {num_samples} samples...")

    def callback(self, msg: PointCloud2):
        now = time.monotonic()
        header_sec = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        self.records.append((now, header_sec, len(msg.data)))

        if len(self.records) >= self.num_samples:
            self.dump_and_exit()

    def dump_and_exit(self):
        # Write raw data
        with open('jitter_samples.csv', 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['recv_monotonic', 'header_stamp_sec', 'msg_bytes'])
            writer.writerows(self.records)

        # Compute inter-arrival deltas (wall/recv side)
        deltas_ms = [
            (self.records[i][0] - self.records[i - 1][0]) * 1000.0
            for i in range(1, len(self.records))
        ]
        # Compute header-stamp deltas (publisher side, if stamps are populated)
        header_deltas_ms = [
            (self.records[i][1] - self.records[i - 1][1]) * 1000.0
            for i in range(1, len(self.records))
            if self.records[i][1] > 0 and self.records[i - 1][1] > 0
        ]

        def summarize(name, xs):
            if not xs:
                print(f"{name}: no data (header stamps may be unset)")
                return
            xs_sorted = sorted(xs)
            n = len(xs_sorted)
            p50 = xs_sorted[n // 2]
            p95 = xs_sorted[int(n * 0.95)]
            print(f"{name}: n={n} min={min(xs):.2f}ms max={max(xs):.2f}ms "
                  f"mean={sum(xs)/n:.2f}ms p50={p50:.2f}ms p95={p95:.2f}ms")

        print("\n=== Jitter summary ===")
        summarize("Receive-side inter-arrival (recv_monotonic)", deltas_ms)
        summarize("Publisher-side inter-arrival (header.stamp)", header_deltas_ms)
        print(f"\nRaw samples written to jitter_samples.csv ({len(self.records)} rows)")
        print("\nIf recv-side deltas are smooth but you saw 10-1000ms jitter in Rust,")
        print("the issue is in the Rust consumer loop (blocking I/O, executor")
        print("contention, etc), not the DDS/network/publisher layer.")

        rclpy.shutdown()


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 measure_pointcloud_jitter.py <topic> [num_samples]")
        sys.exit(1)

    topic = sys.argv[1]
    num_samples = int(sys.argv[2]) if len(sys.argv) > 2 else 300

    rclpy.init()
    node = JitterProbe(topic, num_samples)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()


if __name__ == '__main__':
    main()