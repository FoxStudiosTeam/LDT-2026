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
COPY cuda-pipeline/Cargo.toml ./cuda-pipeline/
COPY shared/Cargo.toml ./shared/
COPY data-extraction/Cargo.toml ./data-extraction/
COPY rust_listener/Cargo.toml ./rust_listener/

RUN mkdir -p \
        cuda-pipeline/src \
        shared/src \
        data-extraction/src \
        rust_listener/src \
        rust_listener/src/bin \
    && echo "fn main() {}" > rust_listener/src/main.rs \
    && echo "fn main() {}" > rust_listener/src/bin/rail_detector.rs \
    && echo "fn main() {}" > rust_listener/src/bin/rail_tuner.rs \
    && echo "fn main() {}" > rust_listener/src/bin/rail_tuner_2d.rs \
    && echo "fn main() {}" > rust_listener/src/bin/inject_db3_rings.rs \
    && echo "fn main() {}" > rust_listener/src/bin/test_error_listener.rs \
    && touch \
        cuda-pipeline/src/lib.rs \
        shared/src/lib.rs \
        data-extraction/src/lib.rs \
        rust_listener/src/lib.rs

# ⚡ Оптимизируем Cargo прямо на лету во время кэширования сборки
ENV CARGO_PROFILE_RELEASE_LTO=true
ENV CARGO_PROFILE_RELEASE_CODEGEN_UNITS=1
ENV CARGO_PROFILE_RELEASE_STRIP=true
ENV CARGO_PROFILE_RELEASE_OPT_LEVEL=3

RUN cargo build --release --bin ros2_debug_viewer --bin test_error_listener

# ──────────────────────────────────────────────────────────────────────────────
# 📦 РЕАЛЬНЫЙ ИСХОДНЫЙ КОД
# ──────────────────────────────────────────────────────────────────────────────
RUN rm -rf \
    cuda-pipeline/src \
    shared/src \
    data-extraction/src \
    rust_listener/src

COPY cuda-pipeline/ ./cuda-pipeline/
COPY shared/ ./shared/
COPY data-extraction/ ./data-extraction/
COPY rust_listener/ ./rust_listener/

RUN rm -rf \
    target/release/.fingerprint/shared-* \
    target/release/.fingerprint/cuda_pipeline-* \
    target/release/.fingerprint/ros2_data_extraction-* \
    target/release/.fingerprint/rust_listener-* \
    || true

# ⚡ Переменные для принудительного статического связывания CUDA-компонентов в Rust
ENV CUDA_STATIC=true
RUN cargo build --release --bin ros2_debug_viewer --bin test_error_listener

# Дополнительно вычищаем остаточные отладочные символы из готовых бинарников
RUN strip /app/target/release/ros2_debug_viewer /app/target/release/test_error_listener

# ==============================================================================
# 🏁 СТЕЙДЖ 2: МИНИМАЛЬНЫЙ RUNTIME
# ==============================================================================
FROM nvidia/cuda:12.2.2-runtime-ubuntu22.04

WORKDIR /app

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/target/release/ros2_debug_viewer /app/ros2_debug_viewer
COPY --from=builder /app/target/release/test_error_listener /app/test_error_listener

# Оставляем системные пути для работы NVidia контейнера через драйвер хоста
ENV LD_LIBRARY_PATH="/usr/local/cuda-12.2/lib64:${LD_LIBRARY_PATH}"

ENTRYPOINT ["/app/ros2_debug_viewer"]
