FROM rust:1.89-bookworm

WORKDIR /app

COPY Cargo.toml Cargo.lock ./
COPY src ./src

RUN cargo build --release

CMD ["./target/release/ros2_data_extraction"]