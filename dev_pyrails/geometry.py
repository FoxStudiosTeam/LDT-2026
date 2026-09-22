"""
3D Geometry & Spherical Projection for Hesai 128 LiDAR
------------------------------------------------------
Converts between Range Image (row, col, range) and Cartesian 3D (X, Y, Z).
"""

import numpy as np

class LidarGeometry:
    def __init__(self, height=128, width=167, fov_up_deg=15.0, fov_down_deg=-25.0, fov_h_deg=25.0):
        self.height = height
        self.width = width
        self.fov_up_rad = np.radians(fov_up_deg)
        self.fov_down_rad = np.radians(fov_down_deg)
        self.total_fov_v = self.fov_up_rad - self.fov_down_rad
        self.fov_h_rad = np.radians(fov_h_deg)

        # Precompute pitch for each row [0..height-1] (row 0 is up, row H-1 is down)
        rows = np.arange(height, dtype=np.float32)
        self.pitch_table = self.fov_up_rad - (rows + 0.5) / height * self.total_fov_v
        self.cos_pitch = np.cos(self.pitch_table)
        self.sin_pitch = np.sin(self.pitch_table)

        # Precompute yaw for each col [0..width-1] (col W/2 is 0 rad / straight forward)
        cols = np.arange(width, dtype=np.float32)
        self.yaw_table = (cols + 0.5 - width / 2.0) / width * self.fov_h_rad
        self.cos_yaw = np.cos(self.yaw_table)
        self.sin_yaw = np.sin(self.yaw_table)

    def row_col_range_to_xyz(self, row, col, r):
        """Converts single or array of (row, col, r) to 3D (X, Y, Z) in meters."""
        p = self.pitch_table[row]
        y = self.yaw_table[col]
        x = r * np.cos(p) * np.cos(y)
        y_coord = r * np.cos(p) * np.sin(y)
        z = r * np.sin(p)
        return x, y_coord, z

    def range_image_to_xyz(self, frame):
        """Vectorized conversion of entire range image to X, Y, Z arrays."""
        P = self.pitch_table[:, None]
        Y = self.yaw_table[None, :]

        cos_p = np.cos(P)
        sin_p = np.sin(P)
        cos_y = np.cos(Y)
        sin_y = np.sin(Y)

        X = frame * (cos_p * cos_y)
        Y_coord = frame * (cos_p * sin_y)
        Z = frame * sin_p
        return X, Y_coord, Z

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

