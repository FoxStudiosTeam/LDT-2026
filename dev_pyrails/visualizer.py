"""
Visualization Module for Rail Track Detection
---------------------------------------------
Renders multi-panel diagnostic & HUD dashboard:
1. Perspective Range Image with projected curves & driveable corridor.
2. Top-down Bird's Eye View (BEV) map (X vs Y).
3. Telemetry HUD card (Curvature, Radius, Gauge, Offset, Heading).
"""

from typing import Optional, Tuple
import cv2
import numpy as np

from geometry import LidarGeometry
from detector import DetectionResult


def draw_dashed_polyline(
    img: np.ndarray,
    pts: np.ndarray,
    color: Tuple[int, int, int],
    thickness: int = 2,
    dash_step: int = 4,
):
    """Draws a dashed polyline along given sequential 2D points."""
    if len(pts) < 2:
        return
    for i in range(0, len(pts) - 1, dash_step):
        i_end = min(i + max(2, dash_step // 2 + 1), len(pts))
        sub = pts[i:i_end]
        if len(sub) > 1:
            cv2.polylines(img, [sub], False, color, thickness, cv2.LINE_AA)


class RailVisualizer:
    def __init__(
        self,
        geometry: Optional[LidarGeometry] = None,
        scale: int = 4,
        max_dist_m: float = 200.0,
        colormap: int = cv2.COLORMAP_TURBO,
    ):
        self.geo = geometry or LidarGeometry()
        self.scale = scale
        self.max_dist_m = max_dist_m
        self.colormap = colormap
        self._turbo_lut = cv2.applyColorMap(
            np.arange(256, dtype=np.uint8).reshape(-1, 1),
            self.colormap,
        ).reshape(256, 3)

    def render_range_view(
        self, frame: np.ndarray, res: Optional[DetectionResult]
    ) -> np.ndarray:
        h, w = frame.shape

        # float32 distance -> [0, 1]
        normalized = np.clip(
            frame / self.max_dist_m,
            0.0,
            1.0,
            )

        # Позиция внутри 256-цветной Turbo LUT
        pos = normalized * 255.0

        # Два соседних цвета
        idx0 = np.floor(pos).astype(np.int32)
        idx1 = np.minimum(idx0 + 1, 255)

        # Дробная часть между ними
        alpha = pos - idx0

        color0 = self._turbo_lut[idx0]
        color1 = self._turbo_lut[idx1]

        # Интерполируем цвет
        color_img = (
                color0 * (1.0 - alpha[..., None])
                + color1 * alpha[..., None]
        ).astype(np.uint8)

        # 0 = нет измерения
        color_img[frame <= 0.0] = 0

        # Увеличение
        vis = cv2.resize(
            color_img,
            (w * self.scale, h * self.scale),
            interpolation=cv2.INTER_NEAREST,
        )

        if res is None:
            cv2.putText(
                vis,
                "NO TRACK DETECTED",
                (30, 50),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.9,
                (0, 0, 255),
                2,
                cv2.LINE_AA,
            )
            return vis

        # Project 3D curves to 2D image coordinates
        row_c, col_c = self.geo.xyz_to_row_col(res.x_curve, res.y_center, res.z_center)
        row_l, col_l = self.geo.xyz_to_row_col(res.x_left, res.y_left, res.z_center)
        row_r, col_r = self.geo.xyz_to_row_col(res.x_right, res.y_right, res.z_center)

        def to_pts(rows: np.ndarray, cols: np.ndarray) -> np.ndarray:
            valid = (rows >= 0) & (rows < h) & (cols >= 0) & (cols < w)
            px = (cols[valid] * self.scale).astype(np.int32)
            py = (rows[valid] * self.scale).astype(np.int32)
            if len(px) == 0:
                return np.empty((0, 2), dtype=np.int32)
            return np.column_stack([px, py])

        pts_c = to_pts(row_c, col_c)
        pts_l = to_pts(row_l, col_l)
        pts_r = to_pts(row_r, col_r)

        # 1. Driveable corridor polygon
        if len(pts_l) > 1 and len(pts_r) > 1:
            corridor = np.vstack([pts_l, pts_r[::-1]])
            overlay = vis.copy()
            cv2.fillPoly(overlay, [corridor], (0, 230, 110))
            cv2.addWeighted(overlay, 0.35, vis, 0.65, 0, vis)

        # 2. Left and Right Rail Curves
        if len(pts_l) > 1:
            cv2.polylines(vis, [pts_l], False, (255, 210, 30), 2, cv2.LINE_AA)  # Cyan
        if len(pts_r) > 1:
            cv2.polylines(vis, [pts_r], False, (30, 90, 255), 2, cv2.LINE_AA)  # Orange-Red

        # 3. Centerline Trajectory
        if len(pts_c) > 1:
            cv2.polylines(vis, [pts_c], False, (0, 255, 0), 2, cv2.LINE_AA)  # Bright Green

        # 3b. Extrapolation (Purple/Magenta Polynomial, N-frame smoothed)
        row_ep, col_ep = None, None
        if res.x_ext is not None and len(res.x_ext) > 1:
            row_ep, col_ep = self.geo.xyz_to_row_col(res.x_ext, res.y_ext, res.z_ext)
            row_epl, col_epl = self.geo.xyz_to_row_col(res.x_ext_l, res.y_ext_l, res.z_ext)
            row_epr, col_epr = self.geo.xyz_to_row_col(res.x_ext_r, res.y_ext_r, res.z_ext)
            pts_ep = to_pts(row_ep, col_ep)
            pts_epl = to_pts(row_epl, col_epl)
            pts_epr = to_pts(row_epr, col_epr)
            draw_dashed_polyline(vis, pts_ep, (255, 0, 255), 2, dash_step=4)       # Poly Center (Magenta)
            draw_dashed_polyline(vis, pts_epl, (220, 60, 220), 1, dash_step=4)     # Poly Left (Magenta)
            draw_dashed_polyline(vis, pts_epr, (220, 60, 220), 1, dash_step=4)     # Poly Right (Magenta)

        # 4. Raw detected point markers
        for pt in res.points:
            cv2.circle(
                vis,
                (int(pt.col_left * self.scale), int(pt.row * self.scale)),
                2,
                (255, 255, 0),
                -1,
            )
            cv2.circle(
                vis,
                (int(pt.col_right * self.scale), int(pt.row * self.scale)),
                2,
                (0, 0, 255),
                -1,
            )

        # 5. Distance tick markers (e.g. 5m, 10m, 15m, 20m, 25m, 30m)
        for dist in [5.0, 10.0, 15.0, 20.0, 25.0, 30.0]:
            r_val, c_val = None, None
            if dist >= res.x_curve.min() and dist <= res.x_curve.max():
                idx = int(np.argmin(np.abs(res.x_curve - dist)))
                r_val, c_val = row_c[idx], col_c[idx]
            elif (
                res.x_ext is not None
                and dist >= res.x_ext.min()
                and dist <= res.x_ext.max()
                and row_ep is not None
            ):
                idx = int(np.argmin(np.abs(res.x_ext - dist)))
                r_val, c_val = row_ep[idx], col_ep[idx]

            if r_val is not None and 0 <= r_val < h and 0 <= c_val < w:
                px = int(c_val * self.scale)
                py = int(r_val * self.scale)
                cv2.circle(vis, (px, py), 4, (255, 255, 255), -1)
                cv2.putText(
                    vis,
                    f"{dist:.0f}m",
                    (px + 8, py + 4),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.38,
                    (255, 255, 255),
                    1,
                    cv2.LINE_AA,
                )

        # Viewport title badge
        cv2.putText(
            vis,
            "FORWARD RANGE VIEW",
            (12, 22),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.5,
            (220, 220, 220),
            1,
            cv2.LINE_AA,
        )

        # Top-right extrapolation legend overlay (Magenta only)
        if res.x_ext is not None:
            top_rx = int(w * self.scale) - 230
            cv2.putText(vis, f"-- Extrap (+{res.extrapolate_m:.0f}m, N={res.smooth_n})", (top_rx, 22), cv2.FONT_HERSHEY_SIMPLEX, 0.38, (255, 0, 255), 1, cv2.LINE_AA)

        return vis

    def render_bev_view(
        self, res: Optional[DetectionResult], width: int = 380, height: int = 512
    ) -> np.ndarray:
        """Renders top-down Bird's Eye View (BEV) map."""
        bev = np.full((height, width, 3), 20, dtype=np.uint8)

        # BEV Coordinate Mapping:
        # X: [0.0, 35.0] -> [height - 30, 20]
        # Y: [-2.5, +2.5] -> [width - 20, 20]
        x_max, x_min = 35.0, 0.0
        y_max, y_min = 2.5, -2.5

        def to_bev_px(x: np.ndarray, y: np.ndarray) -> Tuple[np.ndarray, np.ndarray]:
            # X forward -> up (decreasing pixel Y)
            py = height - 30 - ((x - x_min) / (x_max - x_min) * (height - 50))
            # Y lateral: negative Y is left, positive Y is right, map center is width / 2
            px = (width / 2.0) + (y / (y_max - y_min) * (width - 40))
            return px.astype(np.int32), py.astype(np.int32)

        # Grid rings (5m, 10m, 15m, 20m, 25m, 30m)
        cx, cy = int(width / 2.0), height - 30
        for d in [5.0, 10.0, 15.0, 20.0, 25.0, 30.0]:
            _, ry = to_bev_px(np.array([d]), np.array([0.0]))
            radius_px = cy - int(ry[0])
            cv2.circle(bev, (cx, cy), radius_px, (45, 45, 45), 1, cv2.LINE_AA)
            cv2.putText(
                bev,
                f"{d:.0f}m",
                (cx + 6, int(ry[0]) + 12),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.35,
                (90, 90, 90),
                1,
                cv2.LINE_AA,
            )

        # Lateral guidelines
        for lat in [-1.5, -0.75, 0.0, 0.75, 1.5]:
            px_val, _ = to_bev_px(np.array([0.0]), np.array([lat]))
            color = (60, 60, 60) if lat == 0.0 else (35, 35, 35)
            cv2.line(bev, (int(px_val[0]), 20), (int(px_val[0]), cy), color, 1)

        # Vehicle Icon at (0, 0)
        v_pts = np.array(
            [[cx, cy - 14], [cx - 7, cy + 5], [cx + 7, cy + 5]], dtype=np.int32
        )
        cv2.fillPoly(bev, [v_pts], (0, 200, 255))

        if res is not None:
            # BEV Driveable Corridor
            px_l, py_l = to_bev_px(res.x_left, res.y_left)
            px_r, py_r = to_bev_px(res.x_right, res.y_right)
            px_c, py_c = to_bev_px(res.x_curve, res.y_center)

            bev_l = np.column_stack([px_l, py_l])
            bev_r = np.column_stack([px_r, py_r])
            bev_c = np.column_stack([px_c, py_c])

            if len(bev_l) > 1 and len(bev_r) > 1:
                corridor = np.vstack([bev_l, bev_r[::-1]])
                overlay = bev.copy()
                cv2.fillPoly(overlay, [corridor], (0, 180, 80))
                cv2.addWeighted(overlay, 0.28, bev, 0.72, 0, bev)

            # Curves
            if len(bev_l) > 1:
                cv2.polylines(bev, [bev_l], False, (255, 210, 30), 2, cv2.LINE_AA)
            if len(bev_r) > 1:
                cv2.polylines(bev, [bev_r], False, (30, 90, 255), 2, cv2.LINE_AA)
            if len(bev_c) > 1:
                cv2.polylines(bev, [bev_c], False, (0, 255, 0), 2, cv2.LINE_AA)

            # Extrapolation in BEV (Purple/Magenta Polynomial, N-frame smoothed)
            if res.x_ext is not None and len(res.x_ext) > 1:
                px_ep, py_ep = to_bev_px(res.x_ext, res.y_ext)
                px_epl, py_epl = to_bev_px(res.x_ext_l, res.y_ext_l)
                px_epr, py_epr = to_bev_px(res.x_ext_r, res.y_ext_r)
                draw_dashed_polyline(bev, np.column_stack([px_ep, py_ep]), (255, 0, 255), 2, dash_step=4)
                draw_dashed_polyline(bev, np.column_stack([px_epl, py_epl]), (200, 50, 200), 1, dash_step=4)
                draw_dashed_polyline(bev, np.column_stack([px_epr, py_epr]), (200, 50, 200), 1, dash_step=4)

                # Label at tip
                if len(px_ep) > 0:
                    cv2.putText(
                        bev,
                        f"Extrap (+{res.extrapolate_m:.0f}m)",
                        (int(px_ep[-1]) + 5, int(py_ep[-1])),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.33,
                        (255, 120, 255),
                        1,
                        cv2.LINE_AA,
                    )

            # Raw detected points
            for pt in res.points:
                plx, ply = to_bev_px(np.array([pt.x_left]), np.array([pt.y_left]))
                prx, pry = to_bev_px(np.array([pt.x_right]), np.array([pt.y_right]))
                cv2.circle(bev, (int(plx[0]), int(ply[0])), 2, (255, 255, 0), -1)
                cv2.circle(bev, (int(prx[0]), int(pry[0])), 2, (0, 0, 255), -1)

        cv2.putText(
            bev,
            "BIRD'S EYE VIEW (BEV)",
            (12, 22),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.5,
            (220, 220, 220),
            1,
            cv2.LINE_AA,
        )

        return bev

    def render_hud(
        self, res: Optional[DetectionResult], width: int = 340, height: int = 512
    ) -> np.ndarray:
        """Renders dark telemetry dashboard card with metrics and status."""
        hud = np.full((height, width, 3), 15, dtype=np.uint8)

        # Header title
        cv2.putText(
            hud,
            "RAIL TRACK TELEMETRY",
            (15, 28),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.58,
            (240, 240, 240),
            1,
            cv2.LINE_AA,
        )
        cv2.line(hud, (15, 38), (width - 15, 38), (50, 50, 50), 1)

        if res is None:
            cv2.putText(
                hud,
                "STATUS: TRACK LOST",
                (15, 80),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.65,
                (0, 0, 255),
                2,
                cv2.LINE_AA,
            )
            return hud

        # Status badge box
        if res.turn_direction == "STRAIGHT":
            badge_color = (30, 160, 40)
            badge_text = "TRACK: STRAIGHT"
        elif "LEFT" in res.turn_direction:
            badge_color = (200, 130, 20)
            badge_text = "TRACK: CURVE LEFT"
        else:
            badge_color = (20, 120, 220)
            badge_text = "TRACK: CURVE RIGHT"

        cv2.rectangle(hud, (15, 52), (width - 15, 96), badge_color, -1, cv2.LINE_AA)
        cv2.putText(
            hud,
            badge_text,
            (25, 82),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.65,
            (255, 255, 255),
            2,
            cv2.LINE_AA,
        )

        # Metric items
        heading_deg = float(np.degrees(np.arctan(res.heading_b)))
        offset_cm = float(res.offset_c * 100.0)
        gauge_cm = float(res.gauge * 100.0)

        metrics = [
            ("Frame", f"{res.frame_idx:06d}"),
            ("Turn Radius", f"{res.turn_radius:.0f} m" if res.turn_radius < 5000 else "> 5000 m"),
            ("Heading Angle", f"{heading_deg:+.1f} deg"),
            ("Lateral Offset", f"{offset_cm:+.1f} cm"),
            ("Track Gauge", f"{gauge_cm:.1f} cm"),
            ("Drift @ 15m", f"{res.lateral_shift_15m:+.2f} m"),
            ("Scanlines Found", f"{len(res.points)} / 48"),
            ("Confidence", f"{res.confidence * 100:.0f} %"),
        ]

        y_offset = 135
        for label, val in metrics:
            cv2.putText(
                hud,
                label,
                (20, y_offset),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.46,
                (160, 160, 160),
                1,
                cv2.LINE_AA,
            )
            cv2.putText(
                hud,
                val,
                (width - 140, y_offset),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.48,
                (255, 255, 255),
                1,
                cv2.LINE_AA,
            )
            y_offset += 32

        # Confidence bar
        cv2.putText(
            hud,
            "TRACK QUALITY",
            (20, y_offset + 10),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.42,
            (140, 140, 140),
            1,
            cv2.LINE_AA,
        )
        bar_x = 20
        bar_y = y_offset + 20
        bar_w = width - 40
        bar_h = 10
        cv2.rectangle(hud, (bar_x, bar_y), (bar_x + bar_w, bar_y + bar_h), (40, 40, 40), -1)
        fill_w = int(bar_w * res.confidence)
        fill_col = (0, 220, 80) if res.confidence > 0.7 else (0, 180, 240)
        cv2.rectangle(hud, (bar_x, bar_y), (bar_x + fill_w, bar_y + bar_h), fill_col, -1)

        y_offset = bar_y + bar_h + 18

        # Extrapolation telemetry block (Purple/Magenta Polynomial, N-frame smoothed)
        if res.x_ext is not None and len(res.x_ext) > 0:
            cv2.line(hud, (15, y_offset - 2), (width - 15, y_offset - 2), (50, 50, 50), 1)
            cv2.putText(
                hud,
                f"EXTRAPOLATION (+{res.extrapolate_m:.0f}m)",
                (20, y_offset + 14),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.46,
                (220, 220, 220),
                1,
                cv2.LINE_AA,
            )
            y_offset += 32
            poly_y_end = res.y_ext[-1]
            cv2.circle(hud, (25, y_offset - 4), 4, (255, 0, 255), -1)
            cv2.putText(
                hud,
                f"Poly Drift:      {poly_y_end:+.2f} m",
                (36, y_offset),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.42,
                (255, 120, 255),
                1,
                cv2.LINE_AA,
            )
            y_offset += 22
            cv2.putText(
                hud,
                f"Filter Buffer:   {res.smooth_n} frame(s)",
                (36, y_offset),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.40,
                (170, 170, 170),
                1,
                cv2.LINE_AA,
            )

        # Legend at bottom
        leg_y = height - 56
        cv2.line(hud, (15, leg_y - 10), (width - 15, leg_y - 10), (50, 50, 50), 1)
        cv2.putText(hud, "Track: ", (18, leg_y + 6), cv2.FONT_HERSHEY_SIMPLEX, 0.36, (140, 140, 140), 1)
        cv2.circle(hud, (72, leg_y + 3), 4, (255, 210, 30), -1)
        cv2.putText(hud, "Left", (80, leg_y + 6), cv2.FONT_HERSHEY_SIMPLEX, 0.36, (200, 200, 200), 1)
        cv2.circle(hud, (126, leg_y + 3), 4, (30, 90, 255), -1)
        cv2.putText(hud, "Right", (134, leg_y + 6), cv2.FONT_HERSHEY_SIMPLEX, 0.36, (200, 200, 200), 1)
        cv2.circle(hud, (188, leg_y + 3), 4, (0, 255, 0), -1)
        cv2.putText(hud, "Center", (196, leg_y + 6), cv2.FONT_HERSHEY_SIMPLEX, 0.36, (200, 200, 200), 1)

        cv2.putText(hud, "Extrap:", (18, leg_y + 26), cv2.FONT_HERSHEY_SIMPLEX, 0.36, (140, 140, 140), 1)
        cv2.circle(hud, (72, leg_y + 23), 4, (255, 0, 255), -1)
        cv2.putText(hud, "Poly (Magenta)", (80, leg_y + 26), cv2.FONT_HERSHEY_SIMPLEX, 0.36, (255, 120, 255), 1)

        return hud

    def render_composite(
            self,
            frame: np.ndarray,
            res: Optional[DetectionResult],
    ) -> np.ndarray:

        range_view = self.render_range_view(frame, res)

        h = range_view.shape[0]

        bev_view = self.render_bev_view(
            res,
            width=360,
            height=h,
        )

        hud_view = self.render_hud(
            res,
            width=320,
            height=h,
        )

        composite = np.hstack([
            range_view,
            bev_view,
            hud_view,
        ])

        return composite
