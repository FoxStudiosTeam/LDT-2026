FROM ros:humble

RUN apt-get update && apt-get install -y \
    ros-humble-rosbag2 \
    ros-humble-rosbag2-storage-mcap \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app/dataset

ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/humble/setup.bash && exec \"$@\"", "--"]
