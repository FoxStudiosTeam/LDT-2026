# 1. Используем официальный образ NVIDIA с CUDA и компилятором nvcc на Ubuntu 22.04
FROM nvidia/cuda:12.2.2-devel-ubuntu22.04

# Отключаем интерактивные диалоги при установке пакетов
ENV DEBIAN_FRONTEND=noninteractive

# Устанавливаем локали (обязательно для ROS 2)
RUN apt-get update && apt-get install -y locales && \
    locale-gen en_US en_US.UTF-8 && \
    update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
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

# Переключаем shell на bash, чтобы работал командный сорсинг ROS 2
SHELL ["/bin/bash", "-c"]

WORKDIR /app

# Копируем файлы воркспейса (контекстом должен выступать корень репозитория)
COPY Cargo.toml ./
COPY cuda-pipeline/ ./cuda-pipeline/
COPY rust_listener/ ./rust_listener/

# Активируем окружение ROS 2 и компилируем воркспейс в релиз-моде
RUN source /opt/ros/humble/setup.bash && cargo build --release

# Точка входа: подгружаем либы ROS 2 и запускаем итоговый бинарник
ENTRYPOINT [ "/bin/bash", "-c", "source /opt/ros/humble/setup.bash && exec ./target/release/ros2_debug_viewer" ]
