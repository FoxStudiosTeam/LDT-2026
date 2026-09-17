FROM ros:humble

# Устанавливаем пакеты ОДИН раз при сборке образа
RUN apt-get update && apt-get install -y \
    ros-humble-rosbag2 \
    ros-humble-rosbag2-storage-mcap \
    && rm -rf /var/lib/apt/lists/*

# Сразу настраиваем entrypoint, чтобы не писать source руками
ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/humble/setup.bash && \"$@\"", "--"]
