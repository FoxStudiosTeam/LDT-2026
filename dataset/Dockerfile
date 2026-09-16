FROM ros:jazzy

RUN apt-get update && \
    apt-get install -y \
        ros-jazzy-rosbag2 \
        ros-jazzy-rosbag2-storage-mcap \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

CMD ["ros2", "bag", "play", "/app/dataset/doubleT_platform", "--loop"]