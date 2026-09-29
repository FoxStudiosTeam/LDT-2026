# ==============================================================================
# 🛠️ СТЕЙДЖ 1: СБОРКА
# ==============================================================================
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    pkg-config \
    libssl-dev \
    curl \
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
        test_error_listener/src \
    && echo "fn main() {}" > test_error_listener/src/main.rs \
    && echo "fn main() {}" > rust_listener/src/main.rs \
    && echo "fn main() {}" > rail_tuner_2d/src/main.rs \
    && touch \
        shared/src/lib.rs \
        data-extraction/src/lib.rs \
        rust_listener/src/lib.rs

# ⚡ Оптимизации сборки
ENV CARGO_PROFILE_RELEASE_LTO=true
ENV CARGO_PROFILE_RELEASE_CODEGEN_UNITS=1
ENV CARGO_PROFILE_RELEASE_STRIP=true
ENV CARGO_PROFILE_RELEASE_OPT_LEVEL=3

RUN cargo build --release -p test_error_listener

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
    target/release/.fingerprint/test_error_listener-* \
    || true

RUN cargo build --release -p test_error_listener

# Зачистка отладочных символов
RUN strip /app/target/release/test_error_listener

# ==============================================================================
# 🏁 СТЕЙДЖ 2: МИНИМАЛЬНЫЙ RUNTIME
# ==============================================================================
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/target/release/test_error_listener /app/test_error_listener

ENV ROS_DISTRO=humble
ENV ROS_LOCALHOST_ONLY=1
ENV ROS_ERROR_TOPIC=/rail/error

ENTRYPOINT ["/app/test_error_listener"]
