#!/usr/bin/env python3

import os
import argparse
import sys
import time
import yaml
import threading
import socket
import struct
import json
import zlib
from dataclasses import dataclass

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from rclpy.serialization import deserialize_message
from rosidl_runtime_py.utilities import get_message
import rosbag2_py

DATASET_DIR = os.getenv("DATASET_DIR", "/app/dataset")

@dataclass
class Msg:
    topic: str
    t_ns: int          # исходный timestamp записи в баге (recv time на записи)
    raw: bytes
    msg_type: type


def load_bag(bag_path: str, topics_filter=None):
    """Полностью грузит бэг в память: (topic, t_ns, raw_bytes, msg_type)."""
    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id="")  # auto-detect (sqlite3/mcap)
    converter_options = rosbag2_py.ConverterOptions(
        input_serialization_format="cdr", output_serialization_format="cdr"
    )
    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)

    topic_types = reader.get_all_topics_and_types()
    type_map = {t.name: t.type for t in topic_types}

    msgs = []
    msg_type_cache = {}

    while reader.has_next():
        topic, data, t = reader.read_next()
        if topics_filter and topic not in topics_filter:
            continue
        if topic not in msg_type_cache:
            msg_type_cache[topic] = get_message(type_map[topic])
        msgs.append(Msg(topic=topic, t_ns=t, raw=bytes(data), msg_type=msg_type_cache[topic]))

    msgs.sort(key=lambda m: m.t_ns)
    return msgs, type_map


class BagPlayer(Node):
    def __init__(self, msgs, type_map, topics_filter, loop, rate, qos_override):
        super().__init__("bag_player_ram")
        self.msgs = msgs
        self.loop = loop
        self.rate = rate

        qos = qos_override or QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE,
        )

        self.publishers_map = {}
        seen_topics = {m.topic for m in msgs}
        for topic in seen_topics:
            msg_type = next(m.msg_type for m in msgs if m.topic == topic)
            self.publishers_map[topic] = self.create_publisher(msg_type, topic, qos)

        self.get_logger().info(
            f"Loaded {len(msgs)} messages across {len(seen_topics)} topics into RAM. "
            f"Loop={loop} Rate={rate}"
        )

    def play_once(self):
        if not self.msgs:
            return
        base_bag_t0 = self.msgs[0].t_ns
        base_wall_t0 = time.monotonic_ns()

        for m in self.msgs:
            target_offset_ns = int((m.t_ns - base_bag_t0) / self.rate)
            target_wall_ns = base_wall_t0 + target_offset_ns
            now = time.monotonic_ns()
            sleep_ns = target_wall_ns - now
            if sleep_ns > 0:
                # busy-wait для последних <1ms точности, sleep для остального
                if sleep_ns > 2_000_000:
                    time.sleep((sleep_ns - 1_000_000) / 1e9)
                while time.monotonic_ns() < target_wall_ns:
                    pass

            pub = self.publishers_map[m.topic]
            msg = deserialize_message(m.raw, m.msg_type)



            pub.publish(msg)

    def run(self):
        spin_thread = threading.Thread(target=rclpy.spin, args=(self,), daemon=True)
        spin_thread.start()
        try:
            while True:
                self.play_once()
                if not self.loop:
                    break
                self.get_logger().info("Loop restart")
        except KeyboardInterrupt:
            pass


class StreamReceiver(Node):
    """
    Принимает пакеты по TCP из Windows win_streamer.py и сразу публикует в ROS2.
    - 0 байт копирования на диск
    - Не требует загрузки всего датасета в RAM
    - Поддерживает zlib-сжатие на лету (разгружает сетевой мост)
    """
    def __init__(self, port=9898):
        super().__init__("bag_stream_receiver")
        self.port = port
        self.qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE,
        )
        self.publishers_map = {}
        self.msg_types = {}

    def recv_exact(self, conn, n):
        buf = bytearray(n)
        view = memoryview(buf)
        pos = 0
        while pos < n:
            nbytes = conn.recv_into(view[pos:])
            if not nbytes:
                return None
            pos += nbytes
        return bytes(buf)

    def handle_client(self, conn):
        self.get_logger().info("Windows клиент подключился! Ожидание handshake...")
        len_raw = self.recv_exact(conn, 4)
        if not len_raw:
            return
        json_len = struct.unpack(">I", len_raw)[0]
        header_json = self.recv_exact(conn, json_len)
        if not header_json:
            return

        meta = json.loads(header_json.decode("utf-8"))
        topics = meta.get("topics", [])

        for tinfo in topics:
            topic_id = tinfo["id"]
            topic_name = tinfo["name"]
            topic_type = tinfo["type"]
            msg_cls = get_message(topic_type)
            self.msg_types[topic_id] = msg_cls
            if topic_id not in self.publishers_map:
                self.publishers_map[topic_id] = self.create_publisher(msg_cls, topic_name, self.qos)
            self.get_logger().info(f"Топик #{topic_id}: {topic_name} ({topic_type})")

        conn.sendall(b'\x01')
        self.get_logger().info("► [STREAM] Приём и публикация кадров начались!")

        msg_count = 0
        t0 = time.time()

        while True:
            header_raw = self.recv_exact(conn, 15)
            if not header_raw:
                break

            topic_id, t_ns, flags, payload_len = struct.unpack(">HQBI", header_raw)
            if topic_id == 0xFFFF:
                self.get_logger().info("Получен маркер завершения потока.")
                break

            payload = self.recv_exact(conn, payload_len)
            if not payload:
                break

            if flags & 1:
                raw_cdr = zlib.decompress(payload)
            else:
                raw_cdr = payload

            if topic_id in self.publishers_map:
                msg = deserialize_message(raw_cdr, self.msg_types[topic_id])
                self.publishers_map[topic_id].publish(msg)
                msg_count += 1
                if msg_count % 50 == 0:
                    dt = time.time() - t0
                    fps = msg_count / dt if dt > 0 else 0
                    self.get_logger().info(f"Опубликовано {msg_count} кадров ({fps:.1f} кадров/сек)")

        self.get_logger().info(f"Поток завершён. Всего передано кадров: {msg_count}")

    def run_receiver(self):
        spin_thread = threading.Thread(target=rclpy.spin, args=(self,), daemon=True)
        spin_thread.start()

        target_hosts = ["127.0.0.1", "host.docker.internal"]
        self.get_logger().info(f"==================================================")
        self.get_logger().info(f"► Ожидание запуска win_streamer.py на Windows (порт {self.port})...")
        self.get_logger().info(f"  Запустите в PowerShell: python win_streamer.py <путь_к_багу>")
        self.get_logger().info(f"==================================================")

        while rclpy.ok():
            connected = False
            for host in target_hosts:
                s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                s.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 16 * 1024 * 1024)
                s.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
                s.settimeout(0.5)
                try:
                    s.connect((host, self.port))
                    s.settimeout(None)
                    self.get_logger().info(f"Подключено к Windows стримеру ({host}:{self.port})!")
                    self.handle_client(s)
                    connected = True
                except (ConnectionRefusedError, socket.timeout, OSError):
                    pass
                finally:
                    s.close()
                if connected:
                    break

            if connected:
                self.get_logger().info(f"Ожидание следующего запуска win_streamer.py...")

            time.sleep(1.0)


def get_key_blocking():
    if sys.platform == 'win32':
        import msvcrt
        key = msvcrt.getch()
        if key == b'\x03': return 'CTRL_C'
        if key in (b'\x00', b'\xe0'):
            key = msvcrt.getch()
            if key == b'H': return 'UP'
            if key == b'P': return 'DOWN'
            if key == b'K': return 'LEFT'
            if key == b'M': return 'RIGHT'
        elif key in (b'w', b'W'): return 'UP'
        elif key in (b's', b'S'): return 'DOWN'
        elif key in (b'a', b'A'): return 'LEFT'
        elif key in (b'd', b'D'): return 'RIGHT'
        elif key == b'\r': return 'ENTER'
        elif key == b'\x1b': return 'ESC'
        elif key == b' ': return 'SPACE'
        elif key in (b'q', b'Q'): return 'QUIT'
        return key.decode('ascii', errors='ignore')
    else:
        import tty, termios, select
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            ch = os.read(fd, 1)
            if ch == b'\x1b':
                rlist, _, _ = select.select([fd], [], [], 0.1)
                if not rlist: return 'ESC'
                seq = os.read(fd, 2)
                if seq in (b'[A', b'OA'): return 'UP'
                if seq in (b'[B', b'OB'): return 'DOWN'
                if seq in (b'[C', b'OC'): return 'RIGHT'
                if seq in (b'[D', b'OD'): return 'LEFT'
                return 'ESC'
            if ch == b'\x03': return 'CTRL_C'
            if ch in (b'w', b'W'): return 'UP'
            if ch in (b's', b'S'): return 'DOWN'
            if ch in (b'a', b'A'): return 'LEFT'
            if ch in (b'd', b'D'): return 'RIGHT'
            if ch in (b'\r', b'\n'): return 'ENTER'
            if ch == b' ': return 'SPACE'
            if ch in (b'q', b'Q'): return 'QUIT'
            return ch.decode('ascii', errors='ignore')
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)

# def main():
#     parser = argparse.ArgumentParser()
#     parser.add_argument("bag_path")
#     parser.add_argument("--loop", action="store_true", help="Зациклить воспроизведение")
#     parser.add_argument("--rate", type=float, default=1.0, help="Множитель скорости")
#     parser.add_argument("--topics", nargs="*", default=None, help="Фильтр топиков")
#     args = parser.parse_args()

#     print(f"Loading bag into RAM: {args.bag_path} ...")
#     msgs, type_map = load_bag(args.bag_path, set(args.topics) if args.topics else None)
#     if not msgs:
#         print("Нет сообщений (проверь путь/фильтр топиков)")
#         sys.exit(1)
#     print(f"Loaded {len(msgs)} messages.")

#     rclpy.init()
#     node = BagPlayer(msgs, type_map, args.topics, args.loop, args.rate, qos_override=None)
#     node.run()
#     node.destroy_node()
#     rclpy.shutdown()

def parse_topics_from_metadata(bag_path: str) -> set:
    """Извлекает имена топиков из файла metadata.yaml выбранного бага."""
    meta_path = bag_path if os.path.isfile(bag_path) else os.path.join(bag_path, "metadata.yaml")
    
    if not os.path.exists(meta_path) and os.path.isdir(bag_path):
        possible = os.path.join(bag_path, "metadata.yaml")
        if os.path.exists(possible):
            meta_path = possible

    if not os.path.exists(meta_path):
        return set()

    try:
        with open(meta_path, "r", encoding="utf-8") as f:
            data = yaml.safe_load(f)
        
        info = data.get("rosbag2_bagfile_information", {})
        topics_info = info.get("topics_with_message_count", [])
        
        extracted = set()
        for item in topics_info:
            topic_meta = item.get("topic_metadata", {})
            name = topic_meta.get("name")
            if name:
                extracted.add(name)
        return extracted
    except Exception as e:
        print(f"[Предупреждение] Ошибка чтения metadata.yaml: {e}")
        return set()

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def get_replays(dataset_path):
    if not os.path.exists(dataset_path):
        return []
    items = []
    for item in os.listdir(dataset_path):
        full_path = os.path.join(dataset_path, item)
        if os.path.isdir(full_path) or item.endswith(('.db3', '.mcap')):
            items.append(item)
    return sorted(items)

def play_bag_direct(bag_path, loop, rate, topics_filter):
    meta_topics = parse_topics_from_metadata(bag_path)
    
    final_topics = set()
    if topics_filter:
        final_topics.update(topics_filter)
    if meta_topics:
        final_topics.update(meta_topics)

    filter_set = final_topics if final_topics else None

    print(f"Загрузка файла: {bag_path} ...")
    msgs, type_map = load_bag(bag_path, filter_set)
    if not msgs:
        print("Ошибка: сообщения не найдены (проверьте путь и топики).")
        sys.exit(1)

    rclpy.init()
    node = BagPlayer(msgs, type_map, filter_set, loop, rate, qos_override=None)
    node.run()
    node.destroy_node()
    rclpy.shutdown()

def main():
    parser = argparse.ArgumentParser(description="ROS2 Bag RAM Player / Stream Server")
    parser.add_argument("bag_path", nargs="?", default=None, help="Путь к папке/файлу bag или --server. Если не указан — запуск TUI.")
    parser.add_argument("--server", action="store_true", help="Запустить TCP сервер приёма потока из Windows")
    parser.add_argument("--port", type=int, default=9898, help="Порт для стриминг сервера (default: 9898)")
    parser.add_argument("--loop", action="store_true", default=True, help="Зациклить воспроизведение")
    parser.add_argument("--rate", type=float, default=1.0, help="Множитель скорости (default: 1.0)")
    parser.add_argument("--topics", nargs="*", default=None, help="Фильтр топиков")
    args = parser.parse_args()

    # Запуск сервера приёма потока из Windows
    if args.server or args.bag_path in ("--server", "server") or os.getenv("STREAM_SERVER") == "1":
        rclpy.init()
        receiver = StreamReceiver(port=args.port)
        receiver.run_receiver()
        receiver.destroy_node()
        try:
            if rclpy.ok():
                rclpy.shutdown()
        except Exception:
            pass
        return

    # Запуск без TUI, если передан аргумент bag_path
    if args.bag_path:
        play_bag_direct(args.bag_path, args.loop, args.rate, set(args.topics) if args.topics else None)
        return

    # Запуск TUI-меню
    dataset_replays = get_replays(DATASET_DIR)
    replays = ["[STREAM SERVER] (Ожидание стрима из Windows, порт 9898)"] + dataset_replays

    selected_idx = 0
    loop_mode = args.loop
    current_rate = args.rate

    try:
        while True:
            clear()
            print(f"Режим цикла (Loop): [{'X' if loop_mode else ' '}]  (SPACE для переключения)")
            print("-" * 45)
            print("Вверх/Вниз/W/S — выбор, ENTER — запуск, Q/Ctrl+C — выход:\n")

            for idx, replay in enumerate(replays):
                pointer = ">" if idx == selected_idx else " "
                post = "<" if idx == selected_idx else " "
                print(f"{pointer} {replay} {post}")

            key = get_key_blocking()

            if key in ('QUIT', 'ESC', 'CTRL_C'):
                clear()
                break
            elif key == 'UP':
                selected_idx = (selected_idx - 1) % len(replays)
            elif key == 'DOWN':
                selected_idx = (selected_idx + 1) % len(replays)
            elif key == 'SPACE':
                loop_mode = not loop_mode
            elif key == 'ENTER':
                selected_replay = replays[selected_idx]
                if selected_replay.startswith("[STREAM SERVER]"):
                    clear()
                    rclpy.init()
                    receiver = StreamReceiver(port=args.port)
                    receiver.run_receiver()
                    receiver.destroy_node()
                    try:
                        if rclpy.ok():
                            rclpy.shutdown()
                    except Exception:
                        pass
                    break

                bag_full_path = os.path.join(DATASET_DIR, selected_replay)

                while True:
                    play_bag_direct(bag_full_path, loop_mode, current_rate, set(args.topics) if args.topics else None)

                    print("\n" + "=" * 45)
                    print("Проигрывание завершено.")
                    print("[ENTER] — Повторить | [ESC / Ctrl+C] — Вернуться в меню")
                    print("=" * 45)

                    action = None
                    while action not in ('ENTER', 'ESC', 'CTRL_C'):
                        action = get_key_blocking()

                    if action in ('ESC', 'CTRL_C'):
                        break

    except KeyboardInterrupt:
        clear()
        sys.exit(0)


if __name__ == "__main__":
    # import time
    # time.sleep(100000000)
    main()
