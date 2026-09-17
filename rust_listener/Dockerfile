# === ЭТАП 1: СБОРКА (Остается тяжелым) ===
FROM nvidia/cuda:12.2.2-devel-ubuntu22.04 AS builder
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y locales curl gnupg2 lsb-release && \
    locale-gen en_US en_US.UTF-8 && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
ENV LANG=en_US.UTF-8

# 2. Настраиваем официальный репозиторий ROS 2 Humble
RUN apt-get update && apt-get install -y curl gnupg2 lsb-release && \
    curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Устанавливаем системные зависимости, ROS 2 и библиотеки разработки
RUN apt-get update && apt-get install -y \
    ros-humble-ros-base \
    ros-dev-tools \
    build-essential \
    pkg-config \
    libclang-dev \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# 3. Устанавливаем стабильную версию Rust
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"
SHELL ["/bin/bash", "-c"]

WORKDIR /app
COPY Cargo.toml ./
COPY cuda-pipeline/ ./cuda-pipeline/
COPY rust_listener/ ./rust_listener/

RUN source /opt/ros/humble/setup.bash && cargo build --release

# === ЭТАП 2: МИНИМАЛЬНЫЙ РАНТАЙМ ROS 2 ===
FROM ros:humble-ros-core

WORKDIR /app

# 1. Добавляем официальный репозиторий NVIDIA CUDA для Ubuntu 22.04
RUN apt-get update && apt-get install -y wget && \
    wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.1-1_all.deb && \
    dpkg -i cuda-keyring_1.1-1_all.deb && \
    rm cuda-keyring_1.1-1_all.deb

# 2. Устанавливаем ТОЛЬКО рантайм CUDA (без компиляторов и тяжелых весов)
# И обязательно чистим за собой кэш apt
RUN apt-get update && apt-get install -y \
    cuda-cudart-12-2 \
    libcublas-12-2 \
    && rm -rf /var/lib/apt/lists/*

# Копируем бинарник из первого этапа
COPY --from=builder /app/target/release/ros2_debug_viewer .

# Прописываем пути к библиотекам CUDA, чтобы бинарник их увидел
ENV LD_LIBRARY_PATH=/usr/local/cuda-12.2/lib64:$LD_LIBRARY_PATH

ENTRYPOINT [ "/bin/bash", "-c", "source /opt/ros/humble/setup.bash && exec ./ros2_debug_viewer" ]
