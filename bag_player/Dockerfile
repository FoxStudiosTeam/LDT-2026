FROM ros:humble

ENV DEBIAN_FRONTEND=noninteractive
ENV ROS_DOMAIN_ID=42
ENV PYTHONUNBUFFERED=1
ENV DATASET_DIR=/app/dataset

RUN apt-get update && apt-get install -y \
    python3-pip \
    ros-humble-rosbag2-py \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY req /app/req

RUN python3 -m pip install --no-cache-dir -r /app/req

COPY main.py /app/main.py

ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/humble/setup.bash && exec python3 /app/main.py \"$@\"", "--"]