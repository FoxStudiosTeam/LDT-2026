//! pointcloud.rs — парсинг sensor_msgs/msg/PointCloud2

use anyhow::{anyhow, Result};
use r2r::sensor_msgs::msg::PointCloud2;
use std::collections::HashMap;

/// Статистика по облаку точек
pub struct CloudStats {
    pub n_points: usize,
    pub centroid: [f32; 3],
    pub min: [f32; 3],
    pub max: [f32; 3],
}

/// Парсим PointCloud2 → Vec<[f32;3]> (только конечные точки)
pub fn parse(msg: &PointCloud2) -> Result<Vec<[f32; 3]>> {
    if msg.data.is_empty() || msg.point_step == 0 {
        return Ok(vec![]);
    }

    // Строим карту offset-ов по имени поля
    let offsets: HashMap<&str, usize> = msg
        .fields
        .iter()
        .map(|f| (f.name.as_str(), f.offset as usize))
        .collect();

    let x_off = *offsets
        .get("x")
        .ok_or_else(|| anyhow!("No 'x' field in PointCloud2"))?;
    let y_off = *offsets
        .get("y")
        .ok_or_else(|| anyhow!("No 'y' field in PointCloud2"))?;
    let z_off = *offsets
        .get("z")
        .ok_or_else(|| anyhow!("No 'z' field in PointCloud2"))?;

    let step = msg.point_step as usize;
    let n_points = msg.data.len() / step;
    let data = &msg.data;

    let mut points = Vec::with_capacity(n_points);

    for i in 0..n_points {
        let base = i * step;

        // Проверяем, что есть достаточно байт
        if base + z_off + 4 > data.len() {
            break;
        }

        let x = f32::from_le_bytes(data[base + x_off..base + x_off + 4].try_into()?);
        let y = f32::from_le_bytes(data[base + y_off..base + y_off + 4].try_into()?);
        let z = f32::from_le_bytes(data[base + z_off..base + z_off + 4].try_into()?);

        // Пропускаем NaN / Inf
        if x.is_finite() && y.is_finite() && z.is_finite() {
            points.push([x, y, z]);
        }
    }

    Ok(points)
}

/// Вычисляем базовую статистику по облаку
pub fn compute_stats(points: &[[f32; 3]]) -> CloudStats {
    if points.is_empty() {
        return CloudStats {
            n_points: 0,
            centroid: [0.0; 3],
            min: [0.0; 3],
            max: [0.0; 3],
        };
    }

    let mut sum = [0.0f64; 3];
    let mut min = [f32::MAX; 3];
    let mut max = [f32::MIN; 3];

    for p in points {
        for i in 0..3 {
            sum[i] += p[i] as f64;
            if p[i] < min[i] {
                min[i] = p[i];
            }
            if p[i] > max[i] {
                max[i] = p[i];
            }
        }
    }

    let n = points.len() as f64;
    let centroid = [
        (sum[0] / n) as f32,
        (sum[1] / n) as f32,
        (sum[2] / n) as f32,
    ];

    CloudStats {
        n_points: points.len(),
        centroid,
        min,
        max,
    }
}
