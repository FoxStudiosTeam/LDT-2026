use std::path::{Path, PathBuf};
use std::time::Instant;

use anyhow::{Result, anyhow};
use nalgebra::{Rotation3, Unit, Vector3};
use rusqlite::Connection;
use serde::{Deserialize, Serialize};

use crate::cdr::{extract_xyz, parse_point_cloud2};

/// Замер времени блока — грубый аналог python-контекстного менеджера `timer`.
/// Использование: `let _t = Timer::new("название");` — лог печатается при Drop.
pub struct Timer {
    name: String,
    start: Instant,
}

impl Timer {
    pub fn new(name: impl Into<String>) -> Self {
        Self {
            name: name.into(),
            start: Instant::now(),
        }
    }
}

impl Drop for Timer {
    fn drop(&mut self) {
        let elapsed = self.start.elapsed().as_secs_f64() * 1000.0;
        println!("[TIME] {}: {:.2} ms", self.name, elapsed);
    }
}

/// Функция-обёртка для замера времени работы другой функции (аналог `timer_decorator`).
pub fn timed<T>(name: &str, f: impl FnOnce() -> T) -> T {
    let start = Instant::now();
    let result = f();
    let elapsed = start.elapsed().as_secs_f64() * 1000.0;
    println!("[TIME FUNC] {}: {:.2} ms", name, elapsed);
    result
}

pub fn rotate_points_around_axis(
    points: &[[f32; 3]],
    axis: Vector3<f64>,
    angle_degrees: f64,
) -> Vec<[f32; 3]> {
    let axis_n = Unit::new_normalize(axis);
    let rot = Rotation3::from_axis_angle(&axis_n, angle_degrees.to_radians());
    points
        .iter()
        .map(|p| {
            let v = Vector3::new(p[0] as f64, p[1] as f64, p[2] as f64);
            let r = rot * v;
            [r.x as f32, r.y as f32, r.z as f32]
        })
        .collect()
}

// ---------------------------------------------------------------------
// Кэширование всего бага в один бинарный файл (аналог cache_entire_bag +
// .npz, только через bincode вместо numpy .npz).
// ---------------------------------------------------------------------

#[derive(Serialize, Deserialize)]
pub struct BagCache {
    pub timestamps: Vec<i64>,
    pub frames: Vec<Vec<[f32; 3]>>,
}

pub fn cache_entire_bag(db_path: &Path, cache_dir: &Path, lidar_topic: &str) -> Result<PathBuf> {
    std::fs::create_dir_all(cache_dir)?;
    let stem = db_path.file_stem().unwrap().to_string_lossy();
    let cache_file = cache_dir.join(format!("{stem}_full.bin"));

    if cache_file.exists() {
        println!(
            "[CACHE] Полный кэш уже существует: {}",
            cache_file.display()
        );
        return Ok(cache_file);
    }

    println!(
        "[DB3] Начинаем полную конвертацию {} в bin...",
        db_path.display()
    );
    let conn = Connection::open(db_path)?;

    let (topic_id, _msg_type): (i64, String) = conn
        .query_row(
            "SELECT id, type FROM topics WHERE name = ?1",
            [lidar_topic],
            |row| Ok((row.get(0)?, row.get(1)?)),
        )
        .map_err(|_| anyhow!("Топик {lidar_topic} не найден"))?;

    let mut stmt = conn.prepare(
        "SELECT timestamp, data FROM messages WHERE topic_id = ?1 ORDER BY timestamp ASC",
    )?;
    let rows = stmt.query_map([topic_id], |row| {
        let ts: i64 = row.get(0)?;
        let data: Vec<u8> = row.get(1)?;
        Ok((ts, data))
    })?;

    let mut timestamps = Vec::new();
    let mut frames = Vec::new();

    let _t = Timer::new("Десериализация кадров");
    for row in rows {
        let (ts, raw) = row?;
        let (header, body) = parse_point_cloud2(&raw)?;
        let points = extract_xyz(&header, body)?;
        timestamps.push(ts);
        frames.push(points);
    }
    drop(_t);

    let cache = BagCache { timestamps, frames };
    let encoded = bincode::serialize(&cache)?;
    std::fs::write(&cache_file, encoded)?;
    println!("[CACHE] Сохранено в {}", cache_file.display());
    Ok(cache_file)
}

pub struct CachedReplay {
    cache: BagCache,
}

impl CachedReplay {
    pub fn load(path: &Path) -> Result<Self> {
        let _t = Timer::new("Загрузка кэша в память");
        let bytes = std::fs::read(path)?;
        let cache: BagCache = bincode::deserialize(&bytes)?;
        Ok(Self { cache })
    }

    pub fn num_frames(&self) -> usize {
        self.cache.timestamps.len()
    }

    pub fn get_frame(&self, idx: usize) -> Result<(&[[f32; 3]], i64)> {
        let points = self
            .cache
            .frames
            .get(idx)
            .ok_or_else(|| anyhow!("кадр {idx} не найден в кэше"))?;
        let ts = self.cache.timestamps[idx];
        Ok((points, ts))
    }
}

pub fn filter_by_height(points: &[[f32; 3]], z_max: f32) -> Vec<[f32; 3]> {
    points.iter().copied().filter(|p| p[2] < z_max).collect()
}

// ---------------------------------------------------------------------
// Boxcast: медленная (наивная) и быстрая (векторизованная через локальную
// систему координат) версии, аналог perform_boxcast / perform_boxcast_fast.
// ---------------------------------------------------------------------

pub struct HitResult {
    pub center: Vector3<f32>,
    pub dist: f32,
    pub points: Vec<[f32; 3]>,
}

/// Наивная версия: последовательный шаг вдоль луча, на каждом шаге проверяем
/// AABB-хитбокс. Прямой порт python `perform_boxcast`.
pub fn perform_boxcast(
    points: &[[f32; 3]],
    origin: Vector3<f32>,
    direction: Vector3<f32>,
    box_size: Vector3<f32>,
    max_dist: f32,
    step: f32,
) -> Option<HitResult> {
    let dir = direction.normalize();
    let half = box_size * 0.5;

    let p_end = origin + dir * max_dist;
    let sweep_min = origin.inf(&p_end) - half;
    let sweep_max = origin.sup(&p_end) + half;

    let sub_points: Vec<[f32; 3]> = points
        .iter()
        .copied()
        .filter(|p| {
            let v = Vector3::new(p[0], p[1], p[2]);
            v.x >= sweep_min.x
                && v.x <= sweep_max.x
                && v.y >= sweep_min.y
                && v.y <= sweep_max.y
                && v.z >= sweep_min.z
                && v.z <= sweep_max.z
        })
        .collect();

    if sub_points.is_empty() {
        return None;
    }

    let mut curr_dist = 0.0f32;
    while curr_dist <= max_dist {
        let center = origin + dir * curr_dist;
        let min_b = center - half;
        let max_b = center + half;

        let hit: Vec<[f32; 3]> = sub_points
            .iter()
            .copied()
            .filter(|p| {
                p[0] >= min_b.x
                    && p[0] <= max_b.x
                    && p[1] >= min_b.y
                    && p[1] <= max_b.y
                    && p[2] >= min_b.z
                    && p[2] <= max_b.z
            })
            .collect();

        if !hit.is_empty() {
            return Some(HitResult {
                center,
                dist: curr_dist,
                points: hit,
            });
        }
        curr_dist += step;
    }
    None
}

/// Быстрая версия: переводим точки в локальную систему координат луча
/// (Z вдоль направления) одним матричным умножением и ищем минимальную
/// дистанцию среди точек, попавших в хитбокс. Прямой порт `perform_boxcast_fast`.
pub fn perform_boxcast_fast(
    points: &[[f32; 3]],
    origin: Vector3<f32>,
    direction: Vector3<f32>,
    box_size: Vector3<f32>,
    max_dist: f32,
    step: f32,
) -> Option<HitResult> {
    let dir = direction.normalize();
    let half = box_size * 0.5;

    let p_end = origin + dir * max_dist;
    let sweep_min = origin.inf(&p_end) - half;
    let sweep_max = origin.sup(&p_end) + half;

    let sub_points: Vec<Vector3<f32>> = points
        .iter()
        .map(|p| Vector3::new(p[0], p[1], p[2]))
        .filter(|v| {
            v.x >= sweep_min.x
                && v.x <= sweep_max.x
                && v.y >= sweep_min.y
                && v.y <= sweep_max.y
                && v.z >= sweep_min.z
                && v.z <= sweep_max.z
        })
        .collect();

    if sub_points.is_empty() {
        return None;
    }

    // Локальный базис: z_axis = dir
    let z_axis = dir;
    let temp = if z_axis.x.abs() < 0.9 {
        Vector3::new(1.0, 0.0, 0.0)
    } else {
        Vector3::new(0.0, 1.0, 0.0)
    };
    let x_axis = temp.cross(&z_axis).normalize();
    let y_axis = z_axis.cross(&x_axis);

    let mut best: Option<(f32, Vector3<f32>)> = None; // (distance, world point)
    let mut hit_candidates: Vec<(f32, Vector3<f32>)> = Vec::new();

    for &v in &sub_points {
        let rel = v - origin;
        let lx = rel.dot(&x_axis);
        let ly = rel.dot(&y_axis);
        let lz = rel.dot(&z_axis);

        if lx.abs() <= half.x && ly.abs() <= half.y && lz >= 0.0 && lz <= max_dist {
            hit_candidates.push((lz, v));
            if best.map_or(true, |(bd, _)| lz < bd) {
                best = Some((lz, v));
            }
        }
    }

    let (raw_dist, _) = best?;
    let hit_dist = (raw_dist / step).floor() * step;
    let center = origin + dir * hit_dist;

    let valid_points: Vec<[f32; 3]> = hit_candidates
        .iter()
        .filter(|(d, _)| (*d - hit_dist).abs() <= step / 2.0)
        .map(|(_, v)| [v.x, v.y, v.z])
        .collect();

    Some(HitResult {
        center,
        dist: hit_dist,
        points: valid_points,
    })
}
