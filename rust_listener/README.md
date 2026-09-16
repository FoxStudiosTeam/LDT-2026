# rust_listener — ROS2 → Rerun Debug Viewer

Слушает топик `/sensing/lidar/hesai128/pointcloud` из ROS2 Humble,
парсит `PointCloud2` и отправляет данные в Rerun viewer (по TCP).

## Что отображается в Rerun

| Путь сущности            | Описание                        | Цвет            |
|--------------------------|---------------------------------|-----------------|
| `lidar/raw`              | Исходное облако точек           | 🔵 голубовато-белый |
| `lidar/debug/centroid`   | Центр масс облака               | 🟢 зелёный (крупный) |
| `lidar/debug/bbox`       | Wireframe bounding box (12 рёбер) | 🟡 жёлтый     |
| `lidar/debug/near_range` | Точки < 1 м от сенсора         | 🔴 красный (крупный) |
| `lidar/debug/high_z`     | Точки выше 2 м                  | 🩵 бирюзовый   |

Два таймлайна: `ros_time` (ns из header) и `frame` (порядковый номер).

## Stdout

```
[FRAME    1] pts= 65536 | t=1788354623110040384 ns | bbox x=[ -50.2,  80.1] y=[ -40.0,  40.5] z=[  -2.1,   5.3] | centroid=(1.23,0.45,0.12)
```

## Запуск

### 1. Открыть Rerun viewer на Windows

```powershell
# На Windows (хост), порт 9876 по умолчанию
rerun --serve   # или просто запустить rerun.exe
```

Viewer будет слушать входящие TCP-соединения на `0.0.0.0:9876`.

### 2. Проиграть bag-файл (WSL, терминал 1)

```bash
source /opt/ros/humble/setup.bash
ros2 bag play dataset/doubleT_obstacle -l
```

### 3. Запустить listener (WSL, терминал 2)

```bash
source /opt/ros/humble/setup.bash
./target/debug/ros2_debug_viewer
# или release-сборка (быстрее):
cargo build -p rust_listener --release
./target/release/ros2_debug_viewer
```

### Конфигурация

В [`src/main.rs`](src/main.rs):
```rust
const LIDAR_TOPIC: &str = "/sensing/lidar/hesai128/pointcloud";
const RERUN_ADDR:  &str = "192.168.0.100:9876";
```

В [`src/debug_viz.rs`](src/debug_viz.rs):
```rust
const NEAR_RANGE_M: f32 = 1.0;  // порог "близкие точки" (м)
const HIGH_Z_M:     f32 = 2.0;  // порог "высокие точки" (м)
```

## Сборка

```bash
source /opt/ros/humble/setup.bash
cargo build -p rust_listener
```

> **Примечание**: r2r требует `source /opt/ros/humble/setup.bash` перед сборкой
> (линкуется с нативными библиотеками ROS2).

## Структура

```
rust_listener/src/
├── main.rs          # Точка входа, ROS2 нода, main loop
├── pointcloud.rs    # Парсинг PointCloud2 → Vec<[f32;3]>, статистика
└── debug_viz.rs     # Rerun-визуализация (raw + debug оверлеи)
```
