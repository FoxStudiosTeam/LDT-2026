"""
Rail Track Detector for 3D LiDAR Range Images
---------------------------------------------
Detects left/right rails, fits 3D trajectory curves (including curves/turns),
and computes track geometry metrics (turn radius, heading, lateral offset, gauge).
"""

from dataclasses import dataclass, field
from typing import List, Optional, Tuple, Dict, Any
import numpy as np
from geometry import LidarGeometry


@dataclass
class RailPoint:
    row: int
    col_left: int
    col_right: int
    x_left: float
    y_left: float
    z_left: float
    x_right: float
    y_right: float
    z_right: float
    x_center: float
    y_center: float
    z_center: float
    gauge: float


@dataclass
class DetectionResult:
    frame_idx: int
    points: List[RailPoint]
    gauge: float
    curvature_a: float
    heading_b: float
    offset_c: float
    turn_radius: float
    turn_direction: str  # "STRAIGHT", "CURVE LEFT", "CURVE RIGHT"
    lateral_shift_15m: float
    poly_y: np.ndarray
    poly_z: np.ndarray
    # Resampled 3D curves
    x_curve: np.ndarray
    y_center: np.ndarray
    z_center: np.ndarray
    x_left: np.ndarray
    y_left: np.ndarray
    x_right: np.ndarray
    y_right: np.ndarray
    confidence: float


class RailTrackDetector:
    """
    Detects railway tracks in spherical LiDAR range frames.
    
    Exploits:
    1. Ground range step: positive jump into the inter-rail trough on the left,
       negative jump out of the trough on the right.
    2. Physical gauge consistency: ~0.38m for narrow gauge tracks.
    3. Spatial continuity: scanlines are tracked from vehicle front (near) to distance (far).
    4. 3D polynomial fitting: quadratic model Y(X) = a*X^2 + b*X + c in Bird's Eye View.
    """

    def __init__(
        self,
        geometry: Optional[LidarGeometry] = None,
        nominal_gauge: float = 0.38,
        min_gauge: float = 0.28,
        max_gauge: float = 0.52,
        depth_step_thresh: float = 0.10,
        row_start: int = 124,
        row_end: int = 74,
        max_lateral_jump: float = 0.35,
    ):
        self.geo = geometry or LidarGeometry()
        self.nominal_gauge = nominal_gauge
        self.min_gauge = min_gauge
        self.max_gauge = max_gauge
        self.depth_step_thresh = depth_step_thresh
        self.row_start = row_start
        self.row_end = row_end
        self.max_lateral_jump = max_lateral_jump

    def detect(self, frame: np.ndarray, frame_idx: int = 0) -> Optional[DetectionResult]:
        """
        Analyzes a single range frame and returns DetectionResult or None if no track is found.
        """
        h, w = frame.shape
        X, Y, Z = self.geo.range_image_to_xyz(frame)

        candidates: List[RailPoint] = []
        prev_y_center: Optional[float] = None

        # Scan rows from near (row_start) to far (row_end)
        for row in range(self.row_start, self.row_end, -1):
            r_row = frame[row, :]
            diff_r = np.diff(r_row)

            pos_steps = np.where(diff_r > self.depth_step_thresh)[0]
            neg_steps = np.where(diff_r < -self.depth_step_thresh)[0]

            pairs = []
            for p in pos_steps:
                for n in neg_steps:
                    if n > p:
                        col_l = p
                        col_r = min(n + 1, w - 1)

                        xl, yl, zl = X[row, col_l], Y[row, col_l], Z[row, col_l]
                        xr, yr, zr = X[row, col_r], Y[row, col_r], Z[row, col_r]

                        gauge = np.sqrt((xr - xl) ** 2 + (yr - yl) ** 2)
                        if self.min_gauge <= gauge <= self.max_gauge:
                            xm = 0.5 * (xl + xr)
                            ym = 0.5 * (yl + yr)
                            zm = 0.5 * (zl + zr)

                            pairs.append(
                                RailPoint(
                                    row=row,
                                    col_left=col_l,
                                    col_right=col_r,
                                    x_left=xl,
                                    y_left=yl,
                                    z_left=zl,
                                    x_right=xr,
                                    y_right=yr,
                                    z_right=zr,
                                    x_center=xm,
                                    y_center=ym,
                                    z_center=zm,
                                    gauge=gauge,
                                )
                            )

            if not pairs:
                continue

            # Prioritize continuity from previous scanline
            if prev_y_center is not None:
                pairs.sort(key=lambda item: abs(item.y_center - prev_y_center))
            else:
                # First valid scanline: select pair closest to centerline Y ~ 0
                pairs.sort(key=lambda item: abs(item.y_center))

            best = pairs[0]

            # Reject sudden lateral discontinuities
            if prev_y_center is not None and abs(best.y_center - prev_y_center) > self.max_lateral_jump:
                continue

            prev_y_center = best.y_center
            candidates.append(best)

        # Require a minimum number of valid scanlines
        if len(candidates) < 6:
            return None

        # Extract coordinate arrays
        xm = np.array([pt.x_center for pt in candidates])
        ym = np.array([pt.y_center for pt in candidates])
        zm = np.array([pt.z_center for pt in candidates])
        gauges = np.array([pt.gauge for pt in candidates])
        median_gauge = float(np.median(gauges))

        # Fit quadratic curve for centerline: Y(X) = a*X^2 + b*X + c
        poly_y = np.polyfit(xm, ym, 2)
        # Fit elevation profile: Z(X) = d*X + e
        poly_z = np.polyfit(xm, zm, 1)

        a, b, c = poly_y

        # Radius of curvature: R = 1 / (2 * |a|)
        turn_radius = 1.0 / (2.0 * abs(a)) if abs(a) > 1e-6 else 99999.0
        lateral_shift_15m = float(a * (15.0 ** 2) + b * 15.0)

        # Turn direction classification
        if abs(lateral_shift_15m) < 0.20 and abs(a) < 0.0003:
            turn_direction = "STRAIGHT"
        elif lateral_shift_15m < 0 or a < 0:
            turn_direction = "CURVE LEFT"
        else:
            turn_direction = "CURVE RIGHT"

        # Resample fine curve points in 3D
        x_min = max(3.5, float(xm.min()))
        x_max = max(float(xm.max()), 18.0)
        x_curve = np.linspace(x_min, x_max, 120)
        y_center = np.polyval(poly_y, x_curve)
        z_center = np.polyval(poly_z, x_curve)

        # Exact parallel rail offsets via tangent angle normal
        dy_dx = 2 * a * x_curve + b
        theta = np.arctan(dy_dx)

        half_w = 0.5 * median_gauge
        x_left = x_curve + half_w * np.sin(theta)
        y_left = y_center - half_w * np.cos(theta)

        x_right = x_curve - half_w * np.sin(theta)
        y_right = y_center + half_w * np.cos(theta)

        total_checked_rows = abs(self.row_start - self.row_end) + 1
        confidence = min(1.0, len(candidates) / float(total_checked_rows))

        return DetectionResult(
            frame_idx=frame_idx,
            points=candidates,
            gauge=median_gauge,
            curvature_a=float(a),
            heading_b=float(b),
            offset_c=float(c),
            turn_radius=float(turn_radius),
            turn_direction=turn_direction,
            lateral_shift_15m=lateral_shift_15m,
            poly_y=poly_y,
            poly_z=poly_z,
            x_curve=x_curve,
            y_center=y_center,
            z_center=z_center,
            x_left=x_left,
            y_left=y_left,
            x_right=x_right,
            y_right=y_right,
            confidence=confidence,
        )
