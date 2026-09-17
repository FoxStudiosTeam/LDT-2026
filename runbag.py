import os
import sys
import subprocess
import msvcrt

DATASET_DIR = "dataset"

def get_key():
    """Считывает нажатие клавиши в Windows, обрабатывая Ctrl+C."""
    try:
        key = msvcrt.getch()
        if key == b'\x03':
            return 'CTRL_C'
        if key in (b'\x00', b'\xe0'):
            key = msvcrt.getch()
            if key == b'H': return 'UP'
            if key == b'P': return 'DOWN'
        elif key == b'\r': return 'ENTER'
        elif key == b'\x1b': return 'ESC'
        elif key == b' ': return 'SPACE'
        elif key in (b'q', b'Q'): return 'QUIT'
    except KeyboardInterrupt:
        return 'CTRL_C'
    return None

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def get_replays(dataset_path):
    """Возвращает список доступных bag-файлов/папок в dataset."""
    if not os.path.exists(dataset_path):
        return []
    items = []
    for item in os.listdir(dataset_path):
        full_path = os.path.join(dataset_path, item)
        if os.path.isdir(full_path) or item.endswith(('.db3', '.mcap')):
            items.append(item)
    return sorted(items)

def run_bag_play(bag_path, loop=False):
    """Запускает ros2 bag play через текущую сессию PowerShell с подгрузкой окружения."""
    loop_flag = " -l" if loop else ""
    
    # Это гарантирует наличие ros2 в PATH внутри подпроцесса
    ps_cmd = f"& ./ros2/local_setup.ps1; ros2 bag play {bag_path}{loop_flag}"
    cmd = ["powershell", "-NoProfile", "-ExecutionPolicy", "Bypass", "-Command", ps_cmd]

    clear()
    print(f"=== Воспроизведение: {bag_path} {'[LOOP]' if loop else ''} ===")
    print("Управление в ROS 2: SPACE - пауза, Up/Down - скорость, Ctrl+C - прервать\n")

    try:
        subprocess.run(cmd)
    except KeyboardInterrupt:
        pass

def menu():
    replays = get_replays(DATASET_DIR)
    if not replays:
        print(f"Ошибка: Директория '{DATASET_DIR}' пуста или не найдена.")
        sys.exit(1)

    selected_idx = 0
    loop_mode = False

    try:
        while True:
            clear()
            print("=== ROS2 Bag Player TUI ===")
            print(f"Режим цикла (Loop): [{'X' if loop_mode else ' '}]  (Нажмите SPACE для вкл/выкл)")
            print("-" * 35)
            print("Выберите реплей (Стрелки ВВЕРХ/ВНИЗ, ENTER — запуск, Q / Ctrl+C — выход):\n")

            for idx, replay in enumerate(replays):
                pointer = "->" if idx == selected_idx else "  "
                print(f" {pointer} {replay}")

            key = get_key()

            if key in ('QUIT', 'ESC', 'CTRL_C'):
                clear()
                print("Выход из программы.")
                break
            elif key == 'UP':
                selected_idx = (selected_idx - 1) % len(replays)
            elif key == 'DOWN':
                selected_idx = (selected_idx + 1) % len(replays)
            elif key == 'SPACE':
                loop_mode = not loop_mode
            elif key == 'ENTER':
                selected_replay = replays[selected_idx]
                bag_full_path = os.path.join(DATASET_DIR, selected_replay)

                # Цикл повтора после завершения проигрывания
                while True:
                    run_bag_play(bag_full_path, loop=loop_mode)

                    print("\n" + "=" * 35)
                    print("Проигрывание завершено.")
                    print("[ENTER] — Повторить  |  [ESC / Ctrl+C] — Вернуться в меню")
                    print("=" * 35)

                    action = None
                    while action not in ('ENTER', 'ESC', 'CTRL_C'):
                        action = get_key()

                    if action in ('ESC', 'CTRL_C'):
                        break

    except KeyboardInterrupt:
        clear()
        print("Программа завершена через Ctrl+C.")
        sys.exit(0)

if __name__ == "__main__":
    menu()