FROM rust:1.90-bookworm

WORKDIR /app

COPY Cargo.toml ./
COPY src ./src

RUN cargo build --release

CMD ["./target/release/jitter_test", "/sensing/lidar/hesai128/pointcloud", "100"]