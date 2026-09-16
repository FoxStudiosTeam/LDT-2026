FROM ros:humble

ENV DEBIAN_FRONTEND=noninteractive

# Устанавливаем зависимости для сборки биндингов r2r
RUN apt-get update && apt-get install -y \
    curl \
    build-essential \
    pkg-config \
    libclang-dev \
    && rm -rf /var/lib/apt/lists/*

# Ставим стабильный Rust
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"

SHELL ["/bin/bash", "-c"]

WORKDIR /app
COPY Cargo.toml ./
COPY src ./src

# Компилируем проект, предварительно загрузив окружение ROS2
RUN source /opt/ros/humble/setup.bash && cargo build --release

# Точка входа с обязательным сорсингом библиотек
ENTRYPOINT [ "/bin/bash", "-c", "source /opt/ros/humble/setup.bash && exec ./target/release/ros2_debug_viewer" ]
