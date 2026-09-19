import os
import sys
import glob
import argparse
import subprocess
from pathlib import Path
import yaml
import numpy as np
import rerun as rr
import shutil, tempfile, copy
from rosbags.rosbag2 import Reader
from rosbags.rosbag2.reader import ReaderSqlite3
from rosbags.serde import deserialize_cdr
import sqlite3
import json
from kiss_icp.pipeline import OdometryPipeline
from kiss_icp.config import KISSConfig

LAST_SELECTION_FILE = os.path.expanduser(".cache/bag_player_last_selection.json")
DATASET_DIRS = [
    "../dataset",
    # "/big/dataset_pizdy"
]



class StreamingRosbagDataset:
    """Минимальный Dataset для kiss-icp, питающийся напрямую из открытого Reader,
    без записи чего-либо на диск."""

    def __init__(self, bag_path: Path, topic: str):
        self.bag_path = bag_path
        self.topic = topic

        if bag_path.is_file() and bag_path.suffix == ".db3":
            self._reader = ReaderSqlite3(bag_path)
        else:
            self._reader = Reader(bag_path)
        self._reader.open()

        connections = [c for c in self._reader.connections if c.topic == topic]
        self._connections = connections
        self._length = sum(c.msgcount for c in connections)  # реальное число сообщений
        self._iter = self._reader.messages(connections=connections)

    def __len__(self):
        return self._length

    def __getitem__(self, idx):
        # kiss-icp обращается по возрастающему idx последовательно — используем это
        connection, timestamp, rawdata = next(self._iter)
        msg = deserialize_cdr(rawdata, connection.msgtype)
        points = unpack_pointcloud2(msg)
        timestamps = np.zeros(len(points))  # если нет per-point timestamps
        return points, timestamps

    def close(self):
        self._reader.close()


def generate_poses_streaming(bag_path: str, topic: str, output_path: Path) -> str:
    bag_path_obj = Path(bag_path).resolve()
    dataset = StreamingRosbagDataset(bag_path_obj, topic)

    try:
        pipeline = OdometryPipeline(
            dataset=dataset,
            config=KISSConfig(),  # либо путь к дефолтному конфигу, сверьте сигнатуру
        )
        pipeline.run()
    finally:
        dataset.close()

    poses = np.asarray(pipeline.poses)
    np.save(output_path, poses)
    return str(output_path)


def save_last_selected(path: str):
    try:
        with open(LAST_SELECTION_FILE, "w", encoding="utf-8") as f:
            json.dump({"last_path": os.path.abspath(path)}, f)
    except Exception:
        pass


def load_last_selected() -> str | None:
    try:
        with open(LAST_SELECTION_FILE, "r", encoding="utf-8") as f:
            return json.load(f).get("last_path")
    except Exception:
        return None



def get_actual_message_counts(db3_path: Path) -> dict:
    """Читает реальное кол-во сообщений по каждому топику из конкретного .db3 файла."""
    counts = {}
    conn = sqlite3.connect(str(db3_path))
    try:
        cur = conn.cursor()
        cur.execute("""
            SELECT topics.name, COUNT(messages.id)
            FROM messages
            JOIN topics ON messages.topic_id = topics.id
            GROUP BY topics.name
        """)
        for name, cnt in cur.fetchall():
            counts[name] = cnt
    finally:
        conn.close()
    return counts


def prepare_single_segment_dir(bag_path_obj: Path) -> Path:
    """Создаёт временную папку с одним .db3 и корректно подогнанным metadata.yaml
    (с реальным message_count именно для этого сегмента)."""
    tmp_dir = Path(tempfile.mkdtemp(prefix="kiss_icp_seg_"))
    shutil.copy2(bag_path_obj, tmp_dir / bag_path_obj.name)

    src_meta = bag_path_obj.parent / "metadata.yaml"
    actual_counts = get_actual_message_counts(bag_path_obj)

    if src_meta.exists():
        with open(src_meta, "r", encoding="utf-8") as f:
            meta = yaml.safe_load(f)

        info = meta.get("rosbag2_bagfile_information", {})
        info["relative_file_paths"] = [bag_path_obj.name]

        topics_info = info.get("topics_with_message_count", [])
        new_topics_info = []
        total_count = 0

        for item in topics_info:
            topic_meta = item.get("topic_metadata", {})
            topic_name = topic_meta.get("name")
            real_count = actual_counts.get(topic_name, 0)

            # Оставляем в metadata только топики, реально присутствующие в сегменте
            if real_count > 0:
                item = copy.deepcopy(item)
                item["message_count"] = real_count
                new_topics_info.append(item)
                total_count += real_count

        info["topics_with_message_count"] = new_topics_info
        info["message_count"] = total_count

        with open(tmp_dir / "metadata.yaml", "w", encoding="utf-8") as f:
            yaml.safe_dump(meta, f, allow_unicode=True)

    return tmp_dir

def clear():
    """Очистка терминала."""
    os.system('cls' if sys.platform == 'win32' else 'clear')


def get_key_blocking():
    """Считывание нажатия клавиши в сыром режиме."""
    if sys.platform == 'win32':
        import msvcrt
        key = msvcrt.getch()
        if key == b'\x03': return 'CTRL_C'
        if key == b'\x08': return 'BACKSPACE'
        if key in (b'\x00', b'\xe0'):
            key = msvcrt.getch()
            if key == b'H': return 'UP'
            if key == b'P': return 'DOWN'
            if key == b'K': return 'LEFT'
            if key == b'M': return 'RIGHT'
        elif key == b'\r': return 'ENTER'
        elif key == b'\x1b': return 'ESC'
        elif key == b'\t': return 'TAB'
        
        try:
            return key.decode('utf-8')
        except UnicodeDecodeError:
            return None
    else:
        import tty, termios, select
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            ch = os.read(fd, 1)
            if ch == b'\x1b':
                rlist, _, _ = select.select([fd], [], [], 0.05)
                if not rlist: return 'ESC'
                seq = os.read(fd, 2)
                if seq in (b'[A', b'OA'): return 'UP'
                if seq in (b'[B', b'OB'): return 'DOWN'
                if seq in (b'[C', b'OC'): return 'RIGHT'
                if seq in (b'[D', b'OD'): return 'LEFT'
                return 'ESC'
            if ch == b'\x03': return 'CTRL_C'
            if ch in (b'\x7f', b'\x08'): return 'BACKSPACE'
            if ch in (b'\r', b'\n'): return 'ENTER'
            if ch == b'\t': return 'TAB'
            
            bytes_to_read = 0
            first_byte = ord(ch)
            if (first_byte & 0xE0) == 0xC0:
                bytes_to_read = 1
            elif (first_byte & 0xF0) == 0xE0:
                bytes_to_read = 2
            elif (first_byte & 0xF8) == 0xF0:
                bytes_to_read = 3

            if bytes_to_read > 0:
                ch += os.read(fd, bytes_to_read)

            return ch.decode('utf-8', errors='ignore')
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)


def get_replays(dataset_dirs: list) -> list:
    """Поиск бэгов: как полных папок, так и встроенных/изолированных .db3 файлов."""
    replays = []

    for ddir in dataset_dirs:
        if not os.path.exists(ddir):
            continue

        for entry in os.listdir(ddir):
            full_path = os.path.abspath(os.path.join(ddir, entry))

            if os.path.isdir(full_path):
                has_meta = os.path.exists(os.path.join(full_path, "metadata.yaml"))
                db3_files = sorted(glob.glob(os.path.join(full_path, "*.db3")))
                mcap_files = sorted(glob.glob(os.path.join(full_path, "*.mcap")))

                # 1. Добавляем всю папку как ПОЛНЫЙ бэг
                if has_meta or db3_files or mcap_files:
                    replays.append(full_path)

                # 2. Если есть несколько файлов сегментов — добавляем каждый сегмент отдельно
                all_chunks = db3_files + mcap_files
                if len(all_chunks) > 0:
                    for chunk in all_chunks:
                        replays.append(chunk)

            elif entry.endswith((".db3", ".mcap")):
                replays.append(full_path)

    return sorted(list(set(replays)))


def parse_topics_from_metadata(bag_path: str) -> dict:
    """Извлекает словарь {topic_name: msg_type} из metadata.yaml росбага."""
    bag_path_obj = Path(bag_path)
    
    if bag_path_obj.is_file():
        meta_path = bag_path_obj.parent / "metadata.yaml"
    else:
        meta_path = bag_path_obj / "metadata.yaml"

    if not meta_path.exists():
        return {}

    raw_content = None
    for enc in ["utf-8", "latin-1", "cp1251"]:
        try:
            with open(meta_path, "r", encoding=enc, errors="ignore") as f:
                raw_content = f.read()
                break
        except Exception:
            continue

    if not raw_content:
        return {}

    try:
        data = yaml.safe_load(raw_content)
        if not isinstance(data, dict):
            return {}

        info = data.get("rosbag2_bagfile_information", {})
        topics_info = info.get("topics_with_message_count", [])

        extracted = {}
        for item in topics_info:
            topic_meta = item.get("topic_metadata", {})
            name = topic_meta.get("name")
            type_name = topic_meta.get("type")
            if name and type_name:
                extracted[name] = type_name
        return extracted
    except Exception as e:
        print(f"[Предупреждение] Ошибка парсинга metadata.yaml: {e}")
        return {}


def detect_pointcloud_topic(bag_path: str) -> str:
    """Ищет топик с типом sensor_msgs/msg/PointCloud2."""
    topics_map = parse_topics_from_metadata(bag_path)
    for topic_name, msg_type in topics_map.items():
        if "PointCloud2" in msg_type or "point_cloud_2" in msg_type.lower():
            print(f"[Инфо] Автоматически найден PointCloud2 топик: {topic_name}")
            return topic_name

    for topic_name in topics_map.keys():
        if "lidar" in topic_name.lower() or "point" in topic_name.lower():
            print(f"[Инфо] Использован эвристический топик: {topic_name}")
            return topic_name

    default_topic = "/lidar_points"
    print(f"[Инфо] Топик не определен из метаданных. Использован по умолчанию: {default_topic}")
    return default_topic


def get_or_generate_poses(bag_path: str, topic: str, output_dir: str = "../constructed_lidar") -> str:
    """Проверяет наличие сгенерированного файла *_poses.npy или запускает kiss_icp_pipeline."""
    bag_path_obj = Path(bag_path).resolve()
    
    bag_name = bag_path_obj.stem if bag_path_obj.is_file() else bag_path_obj.name

    out_dir_path = Path(output_dir).resolve()
    out_dir_path.mkdir(parents=True, exist_ok=True)

    pattern = str(out_dir_path / "**" / f"{bag_name}_poses.npy")
    found_files = glob.glob(pattern, recursive=True)

    if found_files:
        poses_file = found_files[0]
        print(f"[Кэш] Найден готовый файл поз: {poses_file}")
        return poses_file

    print(f"[KISS-ICP] Файл поз не найден. Запуск генерации...")
    
    env = os.environ.copy()
    env["KISS_ICP_SAVE_MAP"] = "TRUE"

    # kiss_icp_pipeline ожидает ПАПКУ бэга (с metadata.yaml), а не отдельный .db3-файл.
    # Если нам передали конкретный файл сегмента — используем его родительскую директорию.
    if bag_path_obj.is_file():
        kiss_icp_target = prepare_single_segment_dir(bag_path_obj)
    else:
        kiss_icp_target = bag_path_obj

    cmd = [
        "kiss_icp_pipeline",
        "--topic", topic,
        str(kiss_icp_target)
    ]
    try:
        subprocess.run(cmd, env=env, cwd=str(out_dir_path), check=True)
    except subprocess.CalledProcessError as e:
        raise RuntimeError(f"Ошибка при выполнении kiss_icp_pipeline: {e}")

    found_files = glob.glob(pattern, recursive=True)
    if not found_files:
        fallback_pattern = str(out_dir_path / "**" / "*_poses.npy")
        found_files = glob.glob(fallback_pattern, recursive=True)

    if not found_files:
        raise FileNotFoundError("kiss_icp_pipeline завершился, но файл *_poses.npy не был найден!")

    poses_file = found_files[0]
    print(f"[KISS-ICP] Успешно сгенерирован файл поз: {poses_file}")
    return poses_file


def unpack_pointcloud2(msg) -> np.ndarray:
    """Извлекает координаты (X, Y, Z) из сообщения PointCloud2."""
    data = msg.data
    point_step = msg.point_step

    offsets = {}
    for field in msg.fields:
        if field.name in ['x', 'y', 'z']:
            offsets[field.name] = field.offset

    dtype = np.dtype({
        'names': ['x', 'y', 'z'],
        'formats': ['<f4', '<f4', '<f4'],
        'offsets': [offsets['x'], offsets['y'], offsets['z']],
        'itemsize': point_step
    })

    struct_arr = np.frombuffer(data, dtype=dtype)
    points = np.column_stack((struct_arr['x'], struct_arr['y'], struct_arr['z']))

    mask = np.isfinite(points).all(axis=1)
    return points[mask]



def play_bag_direct(bag_path: str, topic: str = None, accumulate: bool = False, out_dir: str = "../constructed_lidar", rerun_addr: str = None):
    """Основной цикл воспроизведения bag (папки или фрагмента) в Rerun."""
    lidar_topic = topic if topic else detect_pointcloud_topic(bag_path)
    poses_path = get_or_generate_poses(bag_path, lidar_topic, output_dir=out_dir)

    rr.init("lidar_bag_player", spawn=(rerun_addr is None))
    if rerun_addr:
        rr.connect_grpc(rerun_addr)

    poses = np.load(poses_path)
    if poses.ndim == 2 and poses.shape == (4, 4):
        poses = [poses]

    frame_idx = 0
    accumulated_world_points = []

    bag_target = Path(bag_path)

    # Динамический выбор ридера: ReaderSqlite3 для отдельного .db3 или Reader для папки
    if bag_target.is_file() and bag_target.suffix == ".db3":
        reader_instance = ReaderSqlite3(bag_target)
    else:
        reader_instance = Reader(bag_target)

    with reader_instance as reader:
        connections = [x for x in reader.connections if x.topic == lidar_topic]

        for connection, timestamp, rawdata in reader.messages(connections=connections):
            if frame_idx >= len(poses):
                print(f"\n[Предупреждение] Кадры в bag превысили количество поз в .npy ({len(poses)}). Завершение.")
                break

            msg = deserialize_cdr(rawdata, connection.msgtype)
            points = unpack_pointcloud2(msg)

            pose = poses[frame_idx]
            translation = pose[:3, 3]
            rotation_matrix = pose[:3, :3]

            rr.set_time("frame_idx", sequence=frame_idx)

            rr.log(
                "world/platform",
                rr.Transform3D(
                    translation=translation,
                    mat3x3=rotation_matrix,
                )
            )

            rr.log(
                "world/trajectory",
                rr.Points3D(
                    positions=[translation],
                    radii=0.03,
                    colors=[255, 0, 0]
                )
            )

            if accumulate:
                points_hom = np.hstack([points, np.ones((points.shape[0], 1))])
                world_points = (pose @ points_hom.T).T[:, :3]

                # Создаем булеву маску для фильтрации по X
                mask = (world_points[:, 1] - translation[1]) < 1.0
                filtered_world_points = world_points[mask]

                # Добавляем только отфильтрованные точки
                accumulated_world_points.append(filtered_world_points)

                all_points = np.vstack(accumulated_world_points)

                rr.log(
                    "world/accumulated_map",
                    rr.Points3D(
                        positions=all_points,
                        radii=0.01,
                        colors=[200, 200, 200]
                    )
                )
            else:
                rr.log(
                    "world/platform/points",
                    rr.Points3D(
                        positions=points,
                        radii=0.01,
                        colors=[200, 200, 200]
                    )
                )

            frame_idx += 1

    print(f"\n[Успешно] Обработано кадров: {frame_idx}.")


def main():
    parser = argparse.ArgumentParser(description="ROS2 Bag LiDAR & Pose Player for Rerun")
    parser.add_argument("bag_path", nargs="?", default=None, help="Путь к папке/файлу bag.")
    parser.add_argument("--topic", type=str, default=None, help="Имя топика PointCloud2")
    parser.add_argument("--accumulate", action="store_true", default=False, help="Накапливать облака точек")
    parser.add_argument("--out-dir", type=str, default="../constructed_lidar", help="Директория для сохранения/поиска .npy карт")
    parser.add_argument("--rerun-addr", type=str, default=None, help="Адрес Rerun сервера")

    args = parser.parse_args()

    if args.bag_path:
        play_bag_direct(
            bag_path=args.bag_path,
            topic=args.topic,
            accumulate=args.accumulate,
            out_dir=args.out_dir,
            rerun_addr=args.rerun_addr
        )
        return

    all_replays = get_replays(DATASET_DIRS)
    last_selected = load_last_selected()
    if last_selected and last_selected in all_replays:
        all_replays.remove(last_selected)
        all_replays.insert(0, last_selected)
    if not all_replays:
        print(f"Ошибка: Ни в одной из директорий {DATASET_DIRS} не найдены бэги.")
        sys.exit(1)

    selected_idx = 0
    accumulate_mode = args.accumulate
    search_query = ""

    try:
        while True:
            filtered_replays = [
                path for path in all_replays 
                if search_query.lower() in os.path.basename(path).lower() or search_query.lower() in path.lower()
            ]

            if selected_idx >= len(filtered_replays):
                selected_idx = max(0, len(filtered_replays) - 1)

            clear()
            print("=" * 60)
            print("                ROS2 Bag Rerun Player")
            print("=" * 60)
            print(f" Поиск: {search_query}_")
            print(f" Накопление точек: [{'X' if accumulate_mode else ' '}]  (Нажмите TAB для переключения)")
            print("-" * 60)
            print(" Навигация: СТРЕЛКИ ВВЕРХ/ВНИЗ (или W/S)")
            print(" Выбор: ENTER | Очистить поиск: ESC | Выход: CTRL+C")
            print("-" * 60)

            if not filtered_replays:
                print("   [Ничего не найдено]")
            else:
                max_display = 12
                start_page = max(0, selected_idx - max_display // 2)
                end_page = min(len(filtered_replays), start_page + max_display)

                for idx in range(start_page, end_page):
                    full_path = filtered_replays[idx]
                    
                    # Визуальное выделение: папка (полный бэг) или отдельный файл
                    is_dir = os.path.isdir(full_path)
                    type_label = "[DIR]" if is_dir else "[FILE]"
                    display_name = f"{type_label} {os.path.basename(full_path)}"
                    
                    pointer = ">" if idx == selected_idx else " "
                    post = "<" if idx == selected_idx else " "
                    print(f" {pointer} {display_name:<50} {post}")

                if len(filtered_replays) > max_display:
                    print(f"\n   ... Показано {end_page - start_page} из {len(filtered_replays)} элементов ...")

            key = get_key_blocking()

            if key == 'CTRL_C':
                clear()
                break
            elif key == 'ESC':
                if search_query:
                    search_query = ""
                else:
                    clear()
                    break
            elif key in ('UP', 'w', 'W'):
                if filtered_replays:
                    selected_idx = (selected_idx - 1) % len(filtered_replays)
            elif key in ('DOWN', 's', 'S'):
                if filtered_replays:
                    selected_idx = (selected_idx + 1) % len(filtered_replays)
            elif key == 'TAB':
                accumulate_mode = not accumulate_mode
            elif key == 'BACKSPACE':
                search_query = search_query[:-1]
            elif key == 'ENTER':
                if not filtered_replays:
                    continue

                selected_replay_path = filtered_replays[selected_idx]
                save_last_selected(selected_replay_path)

                clear()
                print(f"Запуск воспроизведения: {os.path.basename(selected_replay_path)}...\n")
                
                play_bag_direct(
                    bag_path=selected_replay_path,
                    topic=args.topic,
                    accumulate=accumulate_mode,
                    out_dir=args.out_dir,
                    rerun_addr=args.rerun_addr
                )

                print("\n" + "=" * 60)
                print("Проигрывание завершено.")
                print("[ENTER] — Повторить | [ESC / Ctrl+C] — Вернуться в меню")
                print("=" * 60)

                action = None
                while action not in ('ENTER', 'ESC', 'CTRL_C'):
                    action = get_key_blocking()

                if action in ('ESC', 'CTRL_C'):
                    continue

            elif key and len(key) == 1 and key.isprintable():
                search_query += key
                selected_idx = 0

    except KeyboardInterrupt:
        clear()
        sys.exit(0)


if __name__ == "__main__":
    main()