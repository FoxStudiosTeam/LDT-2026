#!/usr/bin/env python3
"""
test_error_listener.py — ROS2 subscriber and diagnostic test service for /rail/error.

Usage:
    # Run in Docker with ROS2:
    docker compose run --rm -v ${PWD}:/app -w /app ros2_dataset_player python3 test_error_listener.py

    # Or run in native ROS2 environment:
    python3 test_error_listener.py
"""

import os
import sys
import json
from datetime import datetime

try:
    import rclpy
    from rclpy.node import Node
    from std_msgs.msg import String
except ImportError:
    print("\n❌ [ERROR] 'rclpy' or 'std_msgs' is not installed in the current Python environment.")
    print("💡 To run this test service:")
    print("   1) In Docker: docker compose run --rm -v ${PWD}:/app -w /app ros2_dataset_player python3 test_error_listener.py")
    print("   2) Or run the Rust subscriber directly on Windows:")
    print("      cargo run --bin test_error_listener\n")
    sys.exit(1)


class RailErrorListener(Node):
    def __init__(self, topic_name: str = None):
        super().__init__("rail_error_test_service")
        self.topic_name = topic_name or os.environ.get("ROS_ERROR_TOPIC", "/rail/error")
        self.msg_count = 0
        self.last_error = None

        from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy
        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )

        self.subscription = self.create_subscription(
            String,
            self.topic_name,
            self.error_callback,
            qos
        )
        self.get_logger().info(
            f"🚀 [SERVICE STARTED] Subscribed to topic '{self.topic_name}' "
            f"(ROS_DOMAIN_ID={os.environ.get('ROS_DOMAIN_ID', 'default')})"
        )
        self.get_logger().info("⏳ Waiting for obstacle / track error messages...")

    def error_callback(self, msg: String):
        self.msg_count += 1
        now_str = datetime.now().strftime("%H:%M:%S.%f")[:-3]

        try:
            data = json.loads(msg.data)
            self.last_error = data
            status = data.get("status", "UNKNOWN")
            frame_id = data.get("frame_id", "?")
            message = data.get("message", "")
            closest = data.get("closest_distance_m", None)
            crit_count = data.get("critical_count", 0)
            warn_count = data.get("warning_count", 0)
            gauge = data.get("gauge", None)
            radius = data.get("turn_radius", None)
            obstacles = data.get("obstacles", [])

            # Colored console prefix based on severity
            if status == "CRITICAL_OBSTACLE":
                color_prefix = "\033[91m🛑 [CRITICAL]\033[0m"
            elif status == "CLEARANCE_INTRUSION":
                color_prefix = "\033[93m⚠️  [WARNING]\033[0m"
            elif status == "TRACK_LOST":
                color_prefix = "\033[95m❌ [TRACK LOST]\033[0m"
            else:
                color_prefix = "\033[94mℹ️  [INFO]\033[0m"

            print(f"\n{color_prefix} [{now_str}] Frame #{frame_id} | Status: {status}")
            print(f"   ► Message: {message}")
            if closest is not None:
                print(f"   ► Closest Obstacle: {closest:.2f} m | Critical: {crit_count} | Clearance: {warn_count}")
            if gauge is not None and radius is not None:
                rad_str = "∞ (straight)" if (radius > 9999 or radius < -9999) else f"{radius:.1f} m"
                print(f"   ► Track: Gauge = {gauge:.3f} m, Turn Radius = {rad_str}")

            if obstacles:
                print(f"   ► Detected Objects ({len(obstacles)}):")
                for i, obs in enumerate(obstacles, 1):
                    tag = "🚨 IN GAUGE" if obs.get("is_critical") else "⚠️ CLEARANCE"
                    dist = obs.get("distance_along_track", 0.0)
                    lat = obs.get("lateral_offset", 0.0)
                    h = obs.get("height_above_rail", 0.0)
                    pts = obs.get("points_count", 0)
                    print(f"      [{i}] {tag} @ {dist:.2f}m (lat: {lat:+.2f}m, h: {h:.2f}m, pts: {pts})")

        except json.JSONDecodeError:
            print(f"[{now_str}] Raw message received: {msg.data}")


def main():
    topic = os.environ.get("ROS_ERROR_TOPIC", "/rail/error")
    rclpy.init()
    node = RailErrorListener(topic)
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, rclpy.executors.ExternalShutdownException):
        print("\n🛑 Stopped.")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
