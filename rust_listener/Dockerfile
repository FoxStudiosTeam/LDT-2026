FROM nvidia/cuda:12.2.2-devel-ubuntu22.04 AS builder
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y locales curl gnupg2 lsb-release && \
    locale-gen en_US en_US.UTF-8 && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
ENV LANG=en_US.UTF-8

RUN apt-get update && apt-get install -y curl gnupg2 lsb-release && \
    curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null

RUN apt-get update && apt-get install -y \
    ros-humble-ros-base \
    ros-dev-tools \
    build-essential \
    pkg-config \
    libclang-dev \
    cmake \
    && rm -rf /var/lib/apt/lists/*

RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"
SHELL ["/bin/bash", "-c"]
WORKDIR /app


# ──────────────────────────────────────────────────────────────────────────────
# 🛠️ СЛОЙ КЭШИРОВАНИЯ ЗАВИСИМОСТЕЙ
# ──────────────────────────────────────────────────────────────────────────────

COPY Cargo.toml Cargo.lock* ./
COPY cuda-pipeline/Cargo.toml ./cuda-pipeline/
COPY shared/Cargo.toml ./shared/
COPY data-extraction/Cargo.toml ./data-extraction/
COPY rust_listener/Cargo.toml ./rust_listener/

RUN mkdir -p cuda-pipeline/src shared/src data-extraction/src rust_listener/src && \
    echo "fn main() {}" > rust_listener/src/main.rs && \
    touch cuda-pipeline/src/lib.rs shared/src/lib.rs data-extraction/src/lib.rs

RUN source /opt/ros/humble/setup.bash && cargo build --release

# ──────────────────────────────────────────────────────────────────────────────
# 📦 СБОРКА РЕАЛЬНОГО ИСХОДНОГО КОДА
# ──────────────────────────────────────────────────────────────────────────────

RUN rm -rf cuda-pipeline/src shared/src data-extraction/src rust_listener/src

COPY cuda-pipeline/ ./cuda-pipeline/
COPY shared/ ./shared/
COPY data-extraction/ ./data-extraction/
COPY rust_listener/ ./rust_listener/

RUN rm -rf target/release/.fingerprint/shared-* \
           target/release/.fingerprint/cuda_pipeline-* \
           target/release/.fingerprint/ros2_data_extraction-* \
           target/release/.fingerprint/rust_listener-* \
    || true

RUN source /opt/ros/humble/setup.bash && cargo build --release

FROM ros:humble-ros-core

WORKDIR /app


RUN apt-get update && apt-get install -y wget && \
    wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.1-1_all.deb && \
    dpkg -i cuda-keyring_1.1-1_all.deb && \
    rm cuda-keyring_1.1-1_all.deb


RUN apt-get update && apt-get install -y \
    cuda-cudart-12-2 \
    libcublas-12-2 \
    && rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/target/release/ros2_debug_viewer .

ENV LD_LIBRARY_PATH=/usr/local/cuda-12.2/lib64:$LD_LIBRARY_PATH

ENTRYPOINT [ "/bin/bash", "-c", "source /opt/ros/humble/setup.bash && exec ./ros2_debug_viewer" ]
