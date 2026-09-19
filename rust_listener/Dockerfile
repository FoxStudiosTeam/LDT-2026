FROM nvidia/cuda:12.2.2-devel-ubuntu22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    pkg-config \
    libclang-dev \
    cmake \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Rust
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
    && echo "fn main() {}" > rust_listener/src/main.rs \
    && touch \
        cuda-pipeline/src/lib.rs \
        shared/src/lib.rs \
        data-extraction/src/lib.rs

RUN cargo build --release

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

# Чтобы Cargo точно пересобрал изменившиеся workspace crates
RUN rm -rf \
    target/release/.fingerprint/shared-* \
    target/release/.fingerprint/cuda_pipeline-* \
    target/release/.fingerprint/ros2_data_extraction-* \
    target/release/.fingerprint/rust_listener-* \
    || true

RUN cargo build --release

# ──────────────────────────────────────────────────────────────────────────────
# 🏁 RUNTIME
# ──────────────────────────────────────────────────────────────────────────────

FROM nvidia/cuda:12.2.2-runtime-ubuntu22.04

WORKDIR /app

RUN apt-get update && apt-get install -y \
    libcublas-12-2 \
    && rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/target/release/ros2_debug_viewer /app/ros2_debug_viewer

ENV LD_LIBRARY_PATH="/usr/local/cuda-12.2/lib64:${LD_LIBRARY_PATH}"

# Запускаем Rust-приложение
ENTRYPOINT ["/app/ros2_debug_viewer"]