# Воспроизведение датасетов в ROS2

В проекте реализовано **два быстрых способа** работы с датасетами:

| Критерий | ⚡ Способ 1: Стример из Windows (`win_streamer.py`) | 💾 Способ 2: Docker-том (`bag_data`) |
| :--- | :--- | :--- |
| **Рекомендуемый размер** | **Любой (особенно 5 – 80+ ГБ)** | Небольшие датасеты (1 – 4 ГБ) |
| **Расход свободного диска**| **0 байт** (читается на месте на диске `R:\`) | Дублирует размер датасета внутри WSL/Docker |
| **Расход оперативной памяти** | **~50 МБ** (потоковое чтение по 1 кадру) | Загрузка всего датасета в RAM (при RAM-плеере) |
| **Скорость чтения с диска** | **~1500 МБ/с** (нативное NVMe чтение в Windows) | **>2000 МБ/с** (внутри ext4 диска WSL2) |
| **Сжатие данных** | **zlib level 1 на лету (сжатие в 6.2 раза)** | Без сжатия |
| **Перезапуск Docker** | **Не требуется** (реплеи запускаются на лету) | Требуется смена пути в `compose.yml` |

---

## ⚡ Способ 1: Стример из Windows (`win_streamer.py`)
> **Рекомендуется для датасетов от 5 до 80+ ГБ.**

### Архитектура:
```
[ Диск R:\ (NTFS, 80 ГБ) ]
          │ (чтение со скоростью 1500 МБ/с)
          ▼
[ win_streamer.py (Windows PowerShell) ]
  • Потоковая выборка кадров из SQLite .db3 (ОЗУ: ~50 МБ)
  • Сжатие PointCloud2 на лету: 24 МБ -> 3.6 МБ (zlib level 1)
  • Соблюдение частоты 10 Гц по оригинальным timestamp записи
          │
          │ (TCP localhost:9898, поток ~36 МБ/с)
          ▼
[ ros2_stream_player (Docker / ROS2 Humble) ]
  • Приём кадров по сокету
  • Распаковка (декомпрессия ~50 мс)
  • Публикация в /sensing/lidar/hesai128/pointcloud
          │
          ▼
[ rust_viewer (CUDA + Rerun) ]
```

### Как пользоваться:

1. **Запусти сервис стрима в Docker:**
   ```powershell
   docker compose up -d ros2_stream_player rust_viewer
   ```

2. **Запусти стример в Windows PowerShell:**
   Скрипт работает на стандартном Python 3 (не требует установки ROS2 или внешних библиотек):
   ```powershell
   # Проиграть датасет 1 раз со скоростью 1.0x:
   python win_streamer.py R:\path\to\huge_dataset.db3

   # Проигрывание в бесконечном цикле (loop):
   python win_streamer.py R:\path\to\huge_dataset.db3 --loop

   # Воспроизведение с ускорением (например, 2x):
   python win_streamer.py R:\path\to\huge_dataset.db3 --rate 2.0 --loop

   # Можно передавать путь к папке (найдет все .db3 внутри):
   python win_streamer.py dataset\doubleT_obstacle --loop
   ```

3. **Параметры командной строки `win_streamer.py`:**
   * `bag_path` — путь к файлу `.db3` или к папке с бэгом (поддерживает составные мульти-файловые бэги).
   * `--loop` — зациклить воспроизведение.
   * `--rate <float>` — множитель скорости (по умолчанию `1.0`).
   * `--no-compress` — отключить zlib-сжатие (передавать сырой CDR).
   * `--topics <name> ...` — фильтр только нужных топиков.
   * `--port <int>` — TCP-порт для связи с контейнером (по умолчанию `9898`).

> [!TIP]
> Контейнер `ros2_stream_player` после завершения стрима не останавливается, а снова переходит в ожидание. Вы можете в любой момент нажать `Ctrl+C` в PowerShell и запустить другой датасет или сменить скорость — Docker перезапускать не нужно.

---

## 💾 Способ 2: Использование Docker-тома `bag_data`
> **Подходит для небольших датасетов (1–4 ГБ), если нужно полностью автономное воспроизведение внутри Docker без участия хоста Windows.**

### Зачем нужен отдельный том?
Лидар Hesai 128 генерирует ~**240 МБ/с** данных (24 МБ $\times$ 10 Гц).
При прямом пробросе папки из Windows (`./dataset:/app/dataset`) виртуальный мост WSL2 (VirtioFS / 9P) выдаёт максимум **~140 МБ/с**, из-за чего плеер заикается (`Message queue starved`).
Внутри тома **`bag_data`** (нативный ext4 диск Linux) скорость чтения составляет **>2000 МБ/с (2 ГБ/с)**, поэтому буфер никогда не голодает.

---

### 1. Просмотр содержимого тома
```powershell
docker run --rm -v bag_data:/data alpine ls -lh /data
```

---

### 2. Копирование датасета в том

#### Скопировать один датасет:
```powershell
docker run --rm -v bag_data:/to -v "${PWD}/dataset/doubleT_obstacle:/from:ro" alpine sh -c "mkdir -p /to/doubleT_obstacle && cp -rv /from/* /to/doubleT_obstacle/"
```

#### Скопировать сразу все датасеты из папки `dataset/`:
```powershell
docker run --rm -v bag_data:/to -v "${PWD}/dataset:/from:ro" alpine sh -c "cp -rnu /from/* /to/ && rm -rf /to/Dockerfile /to/convert_to_mcap.py /to/.gitkeep"
```

---

### 3. Быстрая конвертация в MCAP прямо внутри тома
Внутри тома конвертация 3–5 ГБ занимает всего **~5–10 секунд**:

#### Сконвертировать конкретный датасет в томе:
```powershell
docker run --rm -v bag_data:/app/dataset -v "${PWD}/dataset/convert_to_mcap.py:/convert.py:ro" ldt-2026-ros2_dataset_player python3 /convert.py doubleT_obstacle
```

#### Сконвертировать все доступные `.db3` датасеты в томе:
```powershell
docker run --rm -v bag_data:/app/dataset -v "${PWD}/dataset/convert_to_mcap.py:/convert.py:ro" ldt-2026-ros2_dataset_player python3 /convert.py
```

---

### 4. Настройка `compose.yml` для воспроизведения из тома

В [`compose.yml`](compose.yml) том `bag_data` уже подключен:
```yaml
volumes:
  bag_data:
    external: true
```

#### Вариант А: Быстрый RAM-плеер (`ros2_fast_player`)
Загрузит файл из тома в память за 1–2 секунды:
```yaml
  ros2_fast_player:
    ...
    volumes:
      - bag_data:/app/dataset:ro
    command: ["/app/dataset/dataset/roundT_doubleT"]
```

#### Вариант Б: Стандартный плеер ROS2 (`ros2_dataset_player`)
Стримит напрямую с диска тома на скорости 2 ГБ/с:
```yaml
  ros2_dataset_player:
    ...
    volumes:
      - bag_data:/app/dataset:ro
    command: >
      bash -c "
        echo '► [DATASET] Поехали!' &&
        ros2 bag play /app/dataset/doubleT_platform_mcap --loop --read-ahead-queue-size 30
      "
```

---

### 5. Очистка и удаление датасетов из тома

#### Удалить один датасет:
```powershell
docker run --rm -v bag_data:/data alpine rm -rf /data/doubleT_obstacle
```

#### Полностью удалить/пересоздать том:
```powershell
docker volume rm bag_data
docker volume create bag_data
```
