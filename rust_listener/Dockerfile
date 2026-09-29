# ==============================================================================
# 🛠️ СТЕЙДЖ 1: СБОРКА (Тяжелый образ со всеми компиляторами)
# ==============================================================================
FROM nvidia/cuda:12.2.2-devel-ubuntu22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    pkg-config \
    libclang-dev \
    cmake \
    curl \
    libssl-dev \
    libxkbcommon-dev \
    libgl1-mesa-dev \
    && rm -rf /var/lib/apt/lists/*

# Установка Rust
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"

SHELL ["/bin/bash", "-c"]
WORKDIR /app

# ──────────────────────────────────────────────────────────────────────────────
# 🛠️ КЭШ ЗАВИСИМОСТЕЙ
# ──────────────────────────────────────────────────────────────────────────────
COPY Cargo.toml Cargo.lock* ./
COPY shared/Cargo.toml ./shared/
COPY data-extraction/Cargo.toml ./data-extraction/
COPY rust_listener/Cargo.toml ./rust_listener/
COPY rail_tuner_2d/Cargo.toml ./rail_tuner_2d/
COPY test_error_listener/Cargo.toml ./test_error_listener/

RUN mkdir -p \
        shared/src \
        data-extraction/src \
        rust_listener/src \
        rail_tuner_2d/src \
    && echo "fn main() {}" > rust_listener/src/main.rs \
    && echo "fn main() {}" > rail_tuner_2d/src/main.rs \
    && echo "fn main() {}" > test_error_listener/src/main.rs \
    && touch \
        shared/src/lib.rs \
        data-extraction/src/lib.rs \
        rust_listener/src/lib.rs

# ⚡ Оптимизируем Cargo прямо на лету во время кэширования сборки
ENV CARGO_PROFILE_RELEASE_LTO=true
ENV CARGO_PROFILE_RELEASE_CODEGEN_UNITS=1
ENV CARGO_PROFILE_RELEASE_STRIP=true
ENV CARGO_PROFILE_RELEASE_OPT_LEVEL=3

RUN cargo build --release -p rust_listener --bin ros2_debug_viewer

# ──────────────────────────────────────────────────────────────────────────────
# 📦 РЕАЛЬНЫЙ ИСХОДНЫЙ КОД
# ──────────────────────────────────────────────────────────────────────────────
RUN rm -rf \
    shared/src \
    data-extraction/src \
    rust_listener/src \
    rail_tuner_2d/src \
    test_error_listener/src

COPY shared/ ./shared/
COPY data-extraction/ ./data-extraction/
COPY rust_listener/ ./rust_listener/
COPY rail_tuner_2d/ ./rail_tuner_2d/
COPY test_error_listener/ ./test_error_listener/

RUN rm -rf \
    target/release/.fingerprint/shared-* \
    target/release/.fingerprint/ros2_data_extraction-* \
    target/release/.fingerprint/rust_listener-* \
    target/release/.fingerprint/rail_tuner_2d-* \
    target/release/.fingerprint/test_error_listener-* \
    || true

RUN cargo build --release -p rust_listener --bin ros2_debug_viewer

# Дополнительно вычищаем остаточные отладочные символы из готовых бинарников
RUN strip /app/target/release/ros2_debug_viewer

# ==============================================================================
# 🏁 СТЕЙДЖ 2: МИНИМАЛЬНЫЙ RUNTIME
# ==============================================================================
FROM nvidia/cuda:12.2.2-runtime-ubuntu22.04

WORKDIR /app

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/target/release/ros2_debug_viewer /app/ros2_debug_viewer

# Оставляем системные пути для работы NVidia контейнера через драйвер хоста
ENV LD_LIBRARY_PATH="/usr/local/cuda-12.2/lib64:${LD_LIBRARY_PATH}"
ENV ROS_DISTRO=humble

ENTRYPOINT ["/app/ros2_debug_viewer"]
