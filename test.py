import time
import numpy as np
import rerun as rr

# Обязательно указываем схему rerun+http:// и путь /proxy
RERUN_HOST = "rerun+http://192.168.0.100:9876/proxy"

def main():
    print(f"[1/3] Инициализация Rerun (назначение: {RERUN_HOST})...")
    
    rr.init("python_rerun_test", spawn=False)
    
    # Подключение с указанием полного URI
    rr.connect_grpc(RERUN_HOST)

    print("[2/3] Отправка данных...")

    positions = np.random.uniform(-5.0, 5.0, size=(100, 3))
    colors = np.random.randint(0, 255, size=(100, 3))
    radii = np.random.uniform(0.1, 0.5, size=(100,))

    rr.log(
        "world/random_points",
        rr.Points3D(positions, colors=colors, radii=radii),
    )

    for frame_id in range(100):
        rr.set_time_sequence("frame", frame_id)

        val = np.sin(frame_id * 0.1)
        rr.log("metrics/sin_wave", rr.Scalar(val))

        spiral_point = np.array(
            [[np.cos(frame_id * 0.1) * 3, np.sin(frame_id * 0.1) * 3, frame_id * 0.05]]
        )
        rr.log("world/moving_point", rr.Points3D(spiral_point, radii=[0.3]))

        time.sleep(0.02)

    rr.log("logs", rr.TextLog("Успешно отправлено 100 фреймов!"))
    print("[3/3] Готово!")

if __name__ == "__main__":
    main()