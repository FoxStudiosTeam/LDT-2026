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
    && touch \
        cuda-pipeline/src/lib.rs \
        shared/src/lib.rs \
        data-extraction/src/lib.rs

# ⚡ Оптимизируем Cargo прямо на лету во время кэширования сборки
ENV CARGO_PROFILE_RELEASE_LTO=true
ENV CARGO_PROFILE_RELEASE_CODEGEN_UNITS=1
ENV CARGO_PROFILE_RELEASE_STRIP=true
ENV CARGO_PROFILE_RELEASE_OPT_LEVEL=3

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

RUN rm -rf \
    target/release/.fingerprint/shared-* \
    target/release/.fingerprint/cuda_pipeline-* \
    target/release/.fingerprint/ros2_data_extraction-* \
    target/release/.fingerprint/rust_listener-* \
    || true

# ⚡ Переменные для принудительного статического связывания CUDA-компонентов в Rust
ENV CUDA_STATIC=true
RUN cargo build --release

# Дополнительно вычищаем остаточные отладочные символы из готового бинарника
RUN strip /app/target/release/ros2_debug_viewer

# ==============================================================================
# 🏁 СТЕЙДЖ 2: МИНИМАЛЬНЫЙ RUNTIME (Образ похудеет на ~1.5 ГБ)
# ==============================================================================
FROM nvidia/cuda:12.2.2-base-ubuntu22.04

WORKDIR /app

# Копируем только ОДИН бинарник. Никаких лишних тяжелых .so
COPY --from=builder /app/target/release/ros2_debug_viewer /app/ros2_debug_viewer

# Оставляем системные пути для работы NVidia контейнера через драйвер хоста
ENV LD_LIBRARY_PATH="/usr/local/cuda-12.2/lib64:${LD_LIBRARY_PATH}"

ENTRYPOINT ["/app/ros2_debug_viewer"]
