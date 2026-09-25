"""
Main CLI & Interactive Runner for Rail Track Detection
------------------------------------------------------
Usage:
    python main.py --frame 100                  # Process single frame & save composite
    python main.py --range 50 150              # Process range of frames
    python main.py --all --video               # Process all 249 frames and export MP4 video
    python main.py --interactive               # Interactive OpenCV GUI with slider & playback
"""

import argparse
import glob
import os
import sys
import time
import cv2
import numpy as np

sys.path.insert(0, os.path.dirname(__file__))
from geometry import LidarGeometry
from detector import RailTrackDetector
from visualizer import RailVisualizer


def get_frame_paths(frames_dir: str):
    paths = sorted(glob.glob(os.path.join(frames_dir, "frame_*.npy")))
    return paths


def process_frame(frame_path: str, detector: RailTrackDetector, visualizer: RailVisualizer):
    frame = np.load(frame_path)
    base = os.path.splitext(os.path.basename(frame_path))[0]
    frame_idx = int(base.split("_")[-1]) if "_" in base else 0
    res = detector.detect(frame, frame_idx=frame_idx)
    vis = visualizer.render_composite(frame, res)
    return frame_idx, res, vis


def run_interactive(frames_dir: str, detector: RailTrackDetector, visualizer: RailVisualizer):
    paths = get_frame_paths(frames_dir)
    if not paths:
        print(f"Error: No frame_*.npy found in {frames_dir}")
        return

    n_frames = len(paths)
    window_name = "Rail Track Detection & Trajectory (LDT-2026)"
    cv2.namedWindow(window_name, cv2.WINDOW_AUTOSIZE)

    current_idx = [0]
    is_playing = [False]

    def on_trackbar(val):
        current_idx[0] = max(0, min(val, n_frames - 1))
        detector.reset()

    cv2.createTrackbar("Frame", window_name, 0, n_frames - 1, on_trackbar)

    print("\n" + "=" * 60)
    print("Interactive Rail Tracker Controls:")
    print("  [SPACE]     : Play / Pause sequence")
    print("  [D] / [->]  : Next frame")
    print("  [A] / [<-]  : Previous frame")
    print("  [S]         : Save current frame screenshot")
    print("  [Q] / [ESC] : Quit")
    print("Extrapolation:")
    print("  [Magenta]   : Polynomial extrapolation (temporal N-frame smoothed)")
    print("=" * 60 + "\n")

    out_dir = os.path.join(os.path.dirname(__file__), "output")
    os.makedirs(out_dir, exist_ok=True)

    while True:
        idx = current_idx[0]
        cv2.setTrackbarPos("Frame", window_name, idx)

        f_idx, res, vis = process_frame(paths[idx], detector, visualizer)
        cv2.imshow(window_name, vis)

        delay = 40 if is_playing[0] else 0
        key = cv2.waitKey(max(1, delay)) & 0xFF

        if key in [ord("q"), 27]:
            break
        elif key == ord(" "):
            is_playing[0] = not is_playing[0]
        elif key in [ord("d"), 83]:  # 'd' or right arrow
            current_idx[0] = (current_idx[0] + 1) % n_frames
        elif key in [ord("a"), 81]:  # 'a' or left arrow
            current_idx[0] = (current_idx[0] - 1 + n_frames) % n_frames
        elif key == ord("s"):
            save_path = os.path.join(out_dir, f"screenshot_{f_idx:06d}.png")
            cv2.imwrite(save_path, vis)
            print(f"Saved screenshot: {save_path}")

        if is_playing[0]:
            current_idx[0] = (current_idx[0] + 1) % n_frames

    cv2.destroyAllWindows()


def run_batch(
    frames_dir: str,
    detector: RailTrackDetector,
    visualizer: RailVisualizer,
    start_frame: int,
    end_frame: int,
    export_video: bool = False,
    fps: float = 12.0,
):
    paths = get_frame_paths(frames_dir)
    if not paths:
        print(f"Error: No frame_*.npy found in {frames_dir}")
        return

    out_dir = os.path.join(os.path.dirname(__file__), "output")
    os.makedirs(out_dir, exist_ok=True)

    selected = []
    for p in paths:
        base = os.path.splitext(os.path.basename(p))[0]
        f_idx = int(base.split("_")[-1]) if "_" in base else 0
        if start_frame <= f_idx <= end_frame:
            selected.append((f_idx, p))

    if not selected:
        print(f"No frames in range [{start_frame}, {end_frame}]")
        return

    print(f"Processing {len(selected)} frames (range [{start_frame}, {end_frame}])...")

    video_writer = None
    if export_video:
        vid_path = os.path.join(out_dir, "rail_detection_trajectory.mp4")
        print(f"Exporting video to: {vid_path}")

    t0 = time.time()
    for i, (f_idx, p) in enumerate(selected):
        _, res, vis = process_frame(p, detector, visualizer)

        if video_writer is None and export_video:
            h, w = vis.shape[:2]
            fourcc = cv2.VideoWriter_fourcc(*"mp4v")
            video_writer = cv2.VideoWriter(vid_path, fourcc, fps, (w, h))

        if video_writer is not None:
            video_writer.write(vis)

        # Save sample keyframe images
        if (i % 25 == 0) or (i == len(selected) - 1):
            img_path = os.path.join(out_dir, f"frame_{f_idx:06d}_composite.png")
            cv2.imwrite(img_path, vis)
            if res:
                print(
                    f"Frame {f_idx:06d}: {res.turn_direction:12s} | R={res.turn_radius:5.0f}m | Gauge={res.gauge*100:.1f}cm | Offset={res.offset_c*100:+.1f}cm"
                )

    if video_writer is not None:
        video_writer.release()
        print(f"\n[DONE] Saved video to {vid_path}")

    elapsed = time.time() - t0
    fps_proc = len(selected) / max(elapsed, 1e-3)
    print(f"Processed {len(selected)} frames in {elapsed:.2f}s ({fps_proc:.1f} FPS).")


def main():
    parser = argparse.ArgumentParser(description="Rail Track Detection & Trajectory Prediction")
    parser.add_argument(
        "--frames-dir",
        type=str,
        default=os.path.join(os.path.dirname(__file__), "..", "frames"),
        help="Path to folder containing frame_*.npy files",
    )
    parser.add_argument("--frame", type=int, default=None, help="Single frame number to process")
    parser.add_argument(
        "--range",
        type=int,
        nargs=2,
        default=None,
        metavar=("START", "END"),
        help="Process frame range [START, END]",
    )
    parser.add_argument(
        "--all", action="store_true", help="Process all frames in frames folder"
    )
    parser.add_argument(
        "--video", action="store_true", help="Export processed sequence to MP4 video"
    )
    parser.add_argument(
        "--fps", type=float, default=12.0, help="Video playback / export FPS"
    )
    parser.add_argument(
        "--extrapolate-m",
        type=float,
        default=15.0,
        help="Extrapolation distance in meters beyond detected track",
    )
    parser.add_argument(
        "--smooth-n",
        type=int,
        default=5,
        help="Number of consecutive frames for temporal averaging (default: 5)",
    )
    parser.add_argument(
        "--interactive", action="store_true", help="Launch interactive OpenCV GUI"
    )

    args = parser.parse_args()
    paths = get_frame_paths(args.frames_dir)

    if not paths:
        print(f"Error: No frame_*.npy found in {args.frames_dir}")
        return

    sample_frame = np.load(paths[0])
    height, width = sample_frame.shape

    print(f"Loaded range image geometry: {height}x{width}")

    geo = LidarGeometry(
        height=height,
        width=width,
    )
    detector = RailTrackDetector(
        geometry=geo,
        extrapolate_m=args.extrapolate_m,
        smooth_n=args.smooth_n,
    )
    visualizer = RailVisualizer(geometry=geo, max_dist_m=200.0)

    if args.interactive:
        run_interactive(args.frames_dir, detector, visualizer)
    elif args.frame is not None:
        run_batch(
            args.frames_dir,
            detector,
            visualizer,
            start_frame=args.frame,
            end_frame=args.frame,
            export_video=False,
        )
    elif args.range is not None:
        run_batch(
            args.frames_dir,
            detector,
            visualizer,
            start_frame=args.range[0],
            end_frame=args.range[1],
            export_video=args.video,
            fps=args.fps,
        )
    elif args.all or args.video:
        run_batch(
            args.frames_dir,
            detector,
            visualizer,
            start_frame=1,
            end_frame=999999,
            export_video=True,
            fps=args.fps,
        )
    else:
        # Default: process all frames and generate video
        print("No mode specified. Running full batch with video export...")
        run_batch(
            args.frames_dir,
            detector,
            visualizer,
            start_frame=1,
            end_frame=999999,
            export_video=True,
            fps=args.fps,
        )


if __name__ == "__main__":
    main()

