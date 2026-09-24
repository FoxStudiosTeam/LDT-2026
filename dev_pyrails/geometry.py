"""
3D Geometry & Spherical Projection for Hesai 128 LiDAR
------------------------------------------------------
Converts between Range Image (row, col, range) and Cartesian 3D (X, Y, Z).
"""

import numpy as np

class LidarGeometry:
    def __init__(
            self, height=321,
            width=400,
            fov_up_deg=15.0,
            fov_down_deg=-25.0,
            fov_h_deg=40.0
    ):
        self.height = height
        self.width = width
        self.fov_up_rad = np.radians(fov_up_deg)
        self.fov_down_rad = np.radians(fov_down_deg)
        self.total_fov_v = self.fov_up_rad - self.fov_down_rad
        self.fov_h_rad = np.radians(fov_h_deg)

        # Precompute pitch for each row [0..height-1] (row 0 is up, row H-1 is down)
        rows = np.arange(height, dtype=np.float32)
        self.pitch_table = self.fov_up_rad - rows * np.radians(0.125)
        self.cos_pitch = np.cos(self.pitch_table)
        self.sin_pitch = np.sin(self.pitch_table)

        # Precompute yaw for each col [0..width-1] (col W/2 is 0 rad / straight forward)
        cols = np.arange(width, dtype=np.float32)
        self.yaw_table = (cols + 0.5 - width / 2.0) / width * self.fov_h_rad
        self.cos_yaw = np.cos(self.yaw_table)
        self.sin_yaw = np.sin(self.yaw_table)

        self.dir_x = self.cos_pitch[:, None] * self.cos_yaw[None, :]
        self.dir_y = self.cos_pitch[:, None] * self.sin_yaw[None, :]
        self.dir_z = self.sin_pitch[:, None]

    def row_col_range_to_xyz(self, row, col, r):
        """Converts single or array of (row, col, r) to 3D (X, Y, Z) in meters."""

        x = r * self.dir_x[row, col]
        y = r * self.dir_y[row, col]
        z = r * self.dir_z[row, col]

        return x, y, z

    def range_image_to_xyz(self, frame):
        """Vectorized conversion of entire range image to X, Y, Z arrays."""

        X = frame * self.dir_x
        Y = frame * self.dir_y
        Z = frame * self.dir_z
        return X, Y, Z

    def xyz_to_row_col(self, x, y, z):
        """Projects 3D points (x, y, z) back onto range image (row, col)."""
        r = np.sqrt(x**2 + y**2 + z**2)
        pitch = np.arcsin(np.clip(z / np.maximum(r, 1e-6), -1.0, 1.0))
        yaw = np.arctan2(y, x)

        # row from pitch
        v_norm = (self.fov_up_rad - pitch) / self.total_fov_v
        row = v_norm * self.height - 0.5

        # col from yaw
        h_norm = yaw / self.fov_h_rad
        col = (h_norm * self.width) + (self.width / 2.0) - 0.5

        return row, col

