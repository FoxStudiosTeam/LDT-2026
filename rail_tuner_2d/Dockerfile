# ==============================================================================
# 🛠️ СТЕЙДЖ 1: СБОРКА
# ==============================================================================
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    pkg-config \
    libssl-dev \
    libxkbcommon-dev \
    libgl1-mesa-dev \
    libxcursor-dev \
    libxi-dev \
    libxinerama-dev \
    libxrandr-dev \
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
    && echo "fn main() {}" > rail_tuner_2d/src/main.rs \
    && echo "fn main() {}" > rust_listener/src/main.rs \
    && echo "fn main() {}" > test_error_listener/src/main.rs \
    && touch \
        shared/src/lib.rs \
        data-extraction/src/lib.rs \
        rust_listener/src/lib.rs

# ⚡ Оптимизации Cargo
ENV CARGO_PROFILE_RELEASE_LTO=true
ENV CARGO_PROFILE_RELEASE_CODEGEN_UNITS=1
ENV CARGO_PROFILE_RELEASE_STRIP=true
ENV CARGO_PROFILE_RELEASE_OPT_LEVEL=3

RUN cargo build -p rail_tuner_2d --release 

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
    target/release/.fingerprint/rail_tuner_2d-* \
    target/release/.fingerprint/test_error_listener-* \
    || true

RUN cargo build --release -p rail_tuner_2d

# Зачистка отладочных символов
RUN strip /app/target/release/rail_tuner_2d

# ==============================================================================
# 🏁 СТЕЙДЖ 2: RUNTIME С noVNC WEB ПАНЕЛЬЮ
# ==============================================================================
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    xvfb \
    x11vnc \
    novnc \
    websockify \
    x11-utils \
    libx11-6 \
    libx11-xcb1 \
    libxcursor1 \
    libxi6 \
    libxinerama1 \
    libxrandr2 \
    libxrender1 \
    libxext6 \
    libxfixes3 \
    libsm6 \
    libice6 \
    libxkbcommon0 \
    libxkbcommon-x11-0 \
    libgl1-mesa-glx \
    libgl1-mesa-dri \
    mesa-vulkan-drivers \
    libfontconfig1 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/target/release/rail_tuner_2d /app/rail_tuner_2d
COPY rail_tuner_2d/entrypoint.sh /app/entrypoint.sh
RUN chmod +x /app/entrypoint.sh && mkdir -p /tmp/runtime-root && chmod 0700 /tmp/runtime-root

ENV DISPLAY=:99
ENV XDG_RUNTIME_DIR=/tmp/runtime-root
ENV WINIT_UNIX_BACKEND=x11
ENV LIBGL_ALWAYS_SOFTWARE=1


# Web-порт для noVNC панели
EXPOSE 6080
# VNC порт (опционально для прямого VNC клиента)
EXPOSE 5900

ENTRYPOINT ["/app/entrypoint.sh"]
