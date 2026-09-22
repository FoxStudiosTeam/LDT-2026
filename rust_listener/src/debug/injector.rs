//! injector.rs — Инжектор виртуальных препятствий в реальное облако точек лидара.
//!
//! Предоставляет удобный программный API в стиле Builder / ООП для создания объектов,
//! настройки их траектории (keyframes), физических свойств и прямого взаимодействия из кода.

use std::f32::consts::PI;
use std::fs::File;
use std::io::BufReader;
use std::path::Path;

use serde::{Deserialize, Serialize};
use shared::types::{AppPointCloud, ProcessingQueue, is_zero_point};
use tracing::{debug, info, warn};

use super::helper::DebugBox3D;

// ─── Программный объект препятствия (Obstacle) ───────────────────────────────

#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct Obstacle {
    pub id: String,
    /// Размеры бокса [длина (dx), ширина (dy), высота (dz)] в метрах
    pub size: [f32; 3],
    /// Отражательная способность (интенсивность) лидара: 0.0 .. 255.0
    #[serde(default = "default_reflectivity")]
    pub reflectivity: f32,
    /// Гауссов шум дальности лидара в метрах (например 0.015 = 1.5 см)
    #[serde(default = "default_noise_sigma")]
    pub noise_sigma: f32,
    /// Ключевые кадры траектории во времени
    pub keyframes: Vec<Keyframe>,
}

fn default_reflectivity() -> f32 {
    180.0
}

fn default_noise_sigma() -> f32 {
    0.01
}

impl Obstacle {
    /// Создание нового объекта с размерами [dx, dy, dz]
    pub fn new(id: impl Into<String>, size: [f32; 3]) -> Self {
        Self {
            id: id.into(),
            size,
            reflectivity: 180.0,
            noise_sigma: 0.01,
            keyframes: Vec::new(),
        }
    }

    /// Статичное препятствие с фиксированной позицией (один кейфрейм)
    pub fn stationary(id: impl Into<String>, size: [f32; 3], pos: [f32; 3]) -> Self {
        Self::new(id, size).add_pos_keyframe(0.0, pos)
    }

    /// Куб с ребром `edge_m`
    pub fn cube(id: impl Into<String>, edge_m: f32) -> Self {
        Self::new(id, [edge_m, edge_m, edge_m])
    }

    /// Задать отражательную способность (интенсивность возврата лидара 0..255)
    pub fn with_reflectivity(mut self, reflectivity: f32) -> Self {
        self.reflectivity = reflectivity;
        self
    }

    /// Задать стандартное отклонение шума измерения дальности в метрах
    pub fn with_noise(mut self, noise_sigma: f32) -> Self {
        self.noise_sigma = noise_sigma;
        self
    }

    /// Добавить ключевую точку во времени: время `time_sec`, позиция [x, y, z], поворот [r, p, y] в градусах
    pub fn add_keyframe(mut self, time_sec: f64, pos: [f32; 3], rot_rpy_deg: [f32; 3]) -> Self {
        self.keyframes.push(Keyframe {
            time_sec,
            pos,
            rot_rpy_deg,
        });
        // Гарантируем сортировку по времени
        self.keyframes.sort_by(|a, b| a.time_sec.partial_cmp(&b.time_sec).unwrap_or(std::cmp::Ordering::Equal));
        self
    }

    /// Добавить ключевую точку во времени только с позицией [x, y, z] (без поворота)
    pub fn add_pos_keyframe(self, time_sec: f64, pos: [f32; 3]) -> Self {
        self.add_keyframe(time_sec, pos, [0.0, 0.0, 0.0])
    }

    /// Задать равномерное движение навстречу поезду по оси -Y
    /// (или вдоль указанного вектора скорости [vx, vy, vz])
    pub fn with_linear_motion(
        mut self,
        start_time_sec: f64,
        start_pos: [f32; 3],
        end_time_sec: f64,
        end_pos: [f32; 3],
    ) -> Self {
        self.keyframes.retain(|k| k.time_sec < start_time_sec || k.time_sec > end_time_sec);
        self.keyframes.push(Keyframe {
            time_sec: start_time_sec,
            pos: start_pos,
            rot_rpy_deg: [0.0, 0.0, 0.0],
        });
        self.keyframes.push(Keyframe {
            time_sec: end_time_sec,
            pos: end_pos,
            rot_rpy_deg: [0.0, 0.0, 0.0],
        });
        self.keyframes.sort_by(|a, b| a.time_sec.partial_cmp(&b.time_sec).unwrap_or(std::cmp::Ordering::Equal));
        self
    }
}

#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct Keyframe {
    /// Время в секундах от начала реплея
    pub time_sec: f64,
    /// Координаты центра бокса [x, y, z] в системе координат лидара
    pub pos: [f32; 3],
    /// Углы Эйлера [roll, pitch, yaw] в градусах
    #[serde(default)]
    pub rot_rpy_deg: [f32; 3],
}

// ─── Быстрый генератор псевдослучайных чисел (Xorshift32) ───────────────────

struct FastRng {
    state: u32,
}

impl FastRng {
    #[inline(always)]
    fn new(seed: u32) -> Self {
        Self {
            state: if seed == 0 { 0x12345678 } else { seed },
        }
    }

    #[inline(always)]
    fn next_u32(&mut self) -> u32 {
        let mut x = self.state;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        self.state = x;
        x
    }

    #[inline(always)]
    fn gen_bipolar(&mut self) -> f32 {
        let val = (self.next_u32() & 0x00FFFFFF) as f32 / 16777216.0;
        val * 2.0 - 1.0
    }

    #[inline(always)]
    fn gen_gaussian(&mut self, sigma: f32) -> f32 {
        let sum = self.gen_bipolar() + self.gen_bipolar() + self.gen_bipolar();
        sum * sigma * 0.577
    }
}

// ─── Интерполированное состояние объекта на текущий кадр ─────────────────────

#[derive(Clone, Debug)]
pub struct ActiveObstacle {
    pub id: String,
    pub center: [f32; 3],
    pub half_size: [f32; 3],
    pub full_size: [f32; 3],
    pub rot_mat: [[f32; 3]; 3],
    pub inv_rot_mat: [[f32; 3]; 3],
    pub quat: [f32; 4],
    pub reflectivity: f32,
    pub noise_sigma: f32,
}

impl ActiveObstacle {
    /// Тест пересечения луча с OBB (Slabs). Возвращает наименьшее t_hit > 0.
    #[inline(always)]
    pub fn intersect_ray(&self, ray_dir: &[f32; 3]) -> Option<f32> {
        let ox = -(self.inv_rot_mat[0][0] * self.center[0]
            + self.inv_rot_mat[0][1] * self.center[1]
            + self.inv_rot_mat[0][2] * self.center[2]);
        let oy = -(self.inv_rot_mat[1][0] * self.center[0]
            + self.inv_rot_mat[1][1] * self.center[1]
            + self.inv_rot_mat[1][2] * self.center[2]);
        let oz = -(self.inv_rot_mat[2][0] * self.center[0]
            + self.inv_rot_mat[2][1] * self.center[1]
            + self.inv_rot_mat[2][2] * self.center[2]);

        let dx = self.inv_rot_mat[0][0] * ray_dir[0]
            + self.inv_rot_mat[0][1] * ray_dir[1]
            + self.inv_rot_mat[0][2] * ray_dir[2];
        let dy = self.inv_rot_mat[1][0] * ray_dir[0]
            + self.inv_rot_mat[1][1] * ray_dir[1]
            + self.inv_rot_mat[1][2] * ray_dir[2];
        let dz = self.inv_rot_mat[2][0] * ray_dir[0]
            + self.inv_rot_mat[2][1] * ray_dir[1]
            + self.inv_rot_mat[2][2] * ray_dir[2];

        let mut t_min = f32::NEG_INFINITY;
        let mut t_max = f32::INFINITY;

        if dx.abs() > 1e-6 {
            let inv = 1.0 / dx;
            let mut t0 = (-self.half_size[0] - ox) * inv;
            let mut t1 = (self.half_size[0] - ox) * inv;
            if inv < 0.0 {
                std::mem::swap(&mut t0, &mut t1);
            }
            t_min = t_min.max(t0);
            t_max = t_max.min(t1);
            if t_max < t_min {
                return None;
            }
        } else if ox.abs() > self.half_size[0] {
            return None;
        }

        if dy.abs() > 1e-6 {
            let inv = 1.0 / dy;
            let mut t0 = (-self.half_size[1] - oy) * inv;
            let mut t1 = (self.half_size[1] - oy) * inv;
            if inv < 0.0 {
                std::mem::swap(&mut t0, &mut t1);
            }
            t_min = t_min.max(t0);
            t_max = t_max.min(t1);
            if t_max < t_min {
                return None;
            }
        } else if oy.abs() > self.half_size[1] {
            return None;
        }

        if dz.abs() > 1e-6 {
            let inv = 1.0 / dz;
            let mut t0 = (-self.half_size[2] - oz) * inv;
            let mut t1 = (self.half_size[2] - oz) * inv;
            if inv < 0.0 {
                std::mem::swap(&mut t0, &mut t1);
            }
            t_min = t_min.max(t0);
            t_max = t_max.min(t1);
            if t_max < t_min {
                return None;
            }
        } else if oz.abs() > self.half_size[2] {
            return None;
        }

        if t_max < 0.0 {
            return None;
        }

        let hit_t = if t_min > 0.0 { t_min } else { t_max };
        if hit_t > 0.0 { Some(hit_t) } else { None }
    }
}

// ─── Главный класс инжектора (ObstacleInjector) ───────────────────────────────

#[derive(Clone, Debug, Default)]
pub struct ObstacleInjector {
    pub obstacles: Vec<Obstacle>,
    first_timestamp_ns: Option<i64>,
}

impl ObstacleInjector {
    /// Создание пустого инжектора
    pub fn new() -> Self {
        Self {
            obstacles: Vec::new(),
            first_timestamp_ns: None,
        }
    }

    /// Добавление объекта в инжектор
    pub fn add_obstacle(&mut self, obstacle: Obstacle) -> &mut Self {
        self.obstacles.push(obstacle);
        self
    }

    /// Быстрое создание дефолтного тестового сценария (куб 1х1х1м на рельсах перед поездом)
    pub fn default_track_scenario() -> Self {
        let mut injector = Self::new();
        injector.add_obstacle(
            Obstacle::cube("track_cube", 1.0)
                .with_reflectivity(200.0)
                .with_noise(0.015)
                // Движется навстречу лидару (поезд едет вперед по -Y)
                .add_keyframe(0.0, [0.0, -50.0, -0.4], [0.0, 0.0, 0.0])
                .add_keyframe(5.0, [0.0, -25.0, -0.4], [0.0, 0.0, 15.0])
                .add_keyframe(10.0, [0.0, -4.0, -0.4], [0.0, 0.0, 30.0]),
        );
        injector
    }
}

/// Пользовательская функция настройки объектов в коде.
/// Здесь можно создавать любые препятствия как объекты в Rust.
pub fn setup_obstacles() -> ObstacleInjector {
    let mut injector = ObstacleInjector::new();

    // Пример добавления препятствия объектом:
    // Задаем явный начальный поворот (например yaw = 25°), чтобы куб сразу был повернут
    injector.add_obstacle(
        Obstacle::cube("cube_on_track", 1.0)
            .with_reflectivity(200.0)
            .with_noise(0.015)
            // Траектория навстречу сенсору лидара:
            .add_keyframe(0.0, [0.0, -40.0, -0.4], [0.0, 0.0, 25.0])
            .add_keyframe(5.0, [0.0, -20.0, -0.4], [0.0, 0.0, 45.0])
            .add_keyframe(10.0, [0.0, -4.0, -0.4], [0.0, 0.0, 70.0]),
    );

    injector
}

impl ObstacleInjector {

    /// Проверка, пуст ли инжектор
    pub fn is_empty(&self) -> bool {
        self.obstacles.is_empty()
    }

    /// Количество зарегистрированных объектов
    pub fn len(&self) -> usize {
        self.obstacles.len()
    }

    /// Очистка всех объектов
    pub fn clear(&mut self) {
        self.obstacles.clear();
        self.first_timestamp_ns = None;
    }

    /// Опциональная загрузка объектов из JSON (для обратной совместимости с файлами)
    pub fn load_from_path<P: AsRef<Path>>(path: P) -> Option<Self> {
        let path = path.as_ref();
        if path.as_os_str().is_empty() {
            return None;
        }

        let file = match File::open(path) {
            Ok(f) => f,
            Err(e) => {
                warn!("Не удалось открыть конфигурацию препятствий {:?}: {}", path, e);
                return None;
            }
        };

        let reader = BufReader::new(file);
        #[derive(Deserialize)]
        struct ScenarioFile {
            #[serde(default)]
            obstacles: Vec<Obstacle>,
        }

        match serde_json::from_reader::<_, ScenarioFile>(reader) {
            Ok(scenario) => {
                info!(
                    "Загружено {} препятствий из файла '{}'",
                    scenario.obstacles.len(),
                    path.display()
                );
                Some(Self {
                    obstacles: scenario.obstacles,
                    first_timestamp_ns: None,
                })
            }
            Err(e) => {
                warn!("Ошибка парсинга сценария препятствий {:?}: {}", path, e);
                None
            }
        }
    }

    /// Вычисление активных препятствий на текущий временной срез кадра
    pub fn get_active_obstacles(&mut self, timestamp_ns: i64, frame_id: u64) -> Vec<ActiveObstacle> {
        let time_sec = if timestamp_ns > 0 {
            let first_t = *self.first_timestamp_ns.get_or_insert(timestamp_ns);
            if timestamp_ns < first_t || timestamp_ns - first_t > 300_000_000_000 {
                self.first_timestamp_ns = Some(timestamp_ns);
                0.0
            } else {
                (timestamp_ns - first_t) as f64 / 1_000_000_000.0
            }
        } else {
            // Если в пакетах rosbag stamp не проставлен — используем номер кадра (10 FPS)
            frame_id as f64 * 0.1
        };

        let mut active = Vec::with_capacity(self.obstacles.len());

        for obs in &self.obstacles {
            if obs.keyframes.is_empty() {
                continue;
            }

            let (pos, rpy) = interpolate_keyframes(&obs.keyframes, time_sec);
            let rot_mat = euler_to_matrix(rpy[0], rpy[1], rpy[2]);
            let inv_rot_mat = transpose_3x3(&rot_mat);
            let quat = euler_to_quaternion(rpy[0], rpy[1], rpy[2]);

            active.push(ActiveObstacle {
                id: obs.id.clone(),
                center: pos,
                half_size: [obs.size[0] * 0.5, obs.size[1] * 0.5, obs.size[2] * 0.5],
                full_size: obs.size,
                rot_mat,
                inv_rot_mat,
                quat,
                reflectivity: obs.reflectivity,
                noise_sigma: obs.noise_sigma,
            });
        }

        active
    }

    /// Инъекция препятствий в буфер облака точек (Queue: READ) на лету.
    /// Возвращает Ground Truth 3D боксы для Rerun с учетом ориентации (кватерниона).
    pub fn inject(
        &mut self,
        cloud: &mut AppPointCloud,
        queue: ProcessingQueue,
        timestamp_ns: i64,
        frame_id: u64,
    ) -> Vec<DebugBox3D> {
        let active = self.get_active_obstacles(timestamp_ns, frame_id);
        if active.is_empty() {
            return Vec::new();
        }

        let total_pts = cloud.len(queue);
        let mut rng = FastRng::new((timestamp_ns as u32) ^ (frame_id as u32) ^ 0x9E3779B9);

        let mut modified_count = 0usize;

        let xs = &mut cloud.x[queue];
        let ys = &mut cloud.y[queue];
        let zs = &mut cloud.z[queue];
        let ints = &mut cloud.intensity[queue];

        for i in 0..total_pts {
            let x = xs[i];
            let y = ys[i];
            let z = zs[i];

            // Отсеиваем нулевые точки и битые возвраты:
            // НЕ генерируем фиктивные лучи [0, -1, 0], чтобы не создавать полосу по центру!
            if is_zero_point(x, y, z) || (y.abs() < 1e-4 && z.abs() < 1e-4) {
                continue;
            }

            let r2 = x * x + y * y + z * z;
            if r2 < 0.04 {
                continue;
            }
            let orig_dist = r2.sqrt();
            let inv_r = 1.0 / orig_dist;
            let dir = [x * inv_r, y * inv_r, z * inv_r];

            let mut nearest_hit = f32::INFINITY;
            let mut hit_obstacle_idx = None;

            for (idx, obs) in active.iter().enumerate() {
                if let Some(t_hit) = obs.intersect_ray(&dir) {
                    if t_hit < nearest_hit {
                        nearest_hit = t_hit;
                        hit_obstacle_idx = Some(idx);
                    }
                }
            }

            if let Some(obs_idx) = hit_obstacle_idx {
                if nearest_hit < orig_dist {
                    let obs = &active[obs_idx];
                    let noise = if obs.noise_sigma > 0.0 {
                        rng.gen_gaussian(obs.noise_sigma)
                    } else {
                        0.0
                    };
                    let dist = (nearest_hit + noise).max(0.01);

                    xs[i] = dir[0] * dist;
                    ys[i] = dir[1] * dist;
                    zs[i] = dir[2] * dist;
                    ints[i] = obs.reflectivity;

                    modified_count += 1;
                }
            }
        }

        debug!(
            "[INJECTOR] Кадр t={:.2}с: подменено {} точек фона (окклюзия)",
            if timestamp_ns > 0 {
                (timestamp_ns - self.first_timestamp_ns.unwrap_or(timestamp_ns)) as f64 / 1e9
            } else {
                frame_id as f64 * 0.1
            },
            modified_count
        );

        active
            .into_iter()
            .map(|obs| {
                DebugBox3D::new(obs.center, obs.full_size)
                    .with_rotation(obs.quat)
                    .with_label(format!("GT: {}", obs.id))
                    .with_color([255, 60, 60])
            })
            .collect()
    }
}

// ─── Вспомогательная математика ───────────────────────────────────────────────

fn interpolate_keyframes(keyframes: &[Keyframe], t: f64) -> ([f32; 3], [f32; 3]) {
    if keyframes.is_empty() {
        return ([0.0, 0.0, 0.0], [0.0, 0.0, 0.0]);
    }
    if keyframes.len() == 1 || t <= keyframes[0].time_sec {
        return (keyframes[0].pos, keyframes[0].rot_rpy_deg);
    }
    if t >= keyframes.last().unwrap().time_sec {
        let last = keyframes.last().unwrap();
        return (last.pos, last.rot_rpy_deg);
    }

    for i in 0..keyframes.len() - 1 {
        let k0 = &keyframes[i];
        let k1 = &keyframes[i + 1];
        if t >= k0.time_sec && t <= k1.time_sec {
            let span = (k1.time_sec - k0.time_sec).max(1e-6);
            let u = ((t - k0.time_sec) / span) as f32;

            let pos = [
                k0.pos[0] + (k1.pos[0] - k0.pos[0]) * u,
                k0.pos[1] + (k1.pos[1] - k0.pos[1]) * u,
                k0.pos[2] + (k1.pos[2] - k0.pos[2]) * u,
            ];
            let rpy = [
                k0.rot_rpy_deg[0] + (k1.rot_rpy_deg[0] - k0.rot_rpy_deg[0]) * u,
                k0.rot_rpy_deg[1] + (k1.rot_rpy_deg[1] - k0.rot_rpy_deg[1]) * u,
                k0.rot_rpy_deg[2] + (k1.rot_rpy_deg[2] - k0.rot_rpy_deg[2]) * u,
            ];
            return (pos, rpy);
        }
    }

    (keyframes[0].pos, keyframes[0].rot_rpy_deg)
}

fn euler_to_matrix(roll_deg: f32, pitch_deg: f32, yaw_deg: f32) -> [[f32; 3]; 3] {
    let r = roll_deg * PI / 180.0;
    let p = pitch_deg * PI / 180.0;
    let y = yaw_deg * PI / 180.0;

    let (sr, cr) = r.sin_cos();
    let (sp, cp) = p.sin_cos();
    let (sy, cy) = y.sin_cos();

    [
        [cy * cp, cy * sp * sr - sy * cr, cy * sp * cr + sy * sr],
        [sy * cp, sy * sp * sr + cy * cr, sy * sp * cr - cy * sr],
        [-sp, cp * sr, cp * cr],
    ]
}

fn euler_to_quaternion(roll_deg: f32, pitch_deg: f32, yaw_deg: f32) -> [f32; 4] {
    let roll = (roll_deg * PI / 180.0) * 0.5;
    let pitch = (pitch_deg * PI / 180.0) * 0.5;
    let yaw = (yaw_deg * PI / 180.0) * 0.5;

    let (sr, cr) = roll.sin_cos();
    let (sp, cp) = pitch.sin_cos();
    let (sy, cy) = yaw.sin_cos();

    // R = Rz(yaw) * Ry(pitch) * Rx(roll) -> quaternion [x, y, z, w]
    let qx = sr * cp * cy - cr * sp * sy;
    let qy = cr * sp * cy + sr * cp * sy;
    let qz = cr * cp * sy - sr * sp * cy;
    let qw = cr * cp * cy + sr * sp * sy;

    [qx, qy, qz, qw]
}

fn transpose_3x3(m: &[[f32; 3]; 3]) -> [[f32; 3]; 3] {
    [
        [m[0][0], m[1][0], m[2][0]],
        [m[0][1], m[1][1], m[2][1]],
        [m[0][2], m[1][2], m[2][2]],
    ]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_programmatic_obstacle_builder() {
        let mut injector = ObstacleInjector::new();
        injector.add_obstacle(
            Obstacle::cube("box1", 1.2)
                .with_reflectivity(220.0)
                .with_noise(0.02)
                .add_keyframe(0.0, [0.0, -30.0, 0.0], [0.0, 0.0, 0.0])
                .add_keyframe(5.0, [0.0, -5.0, 0.0], [0.0, 0.0, 45.0]),
        );

        assert_eq!(injector.len(), 1);
        let active = injector.get_active_obstacles(0, 0);
        assert_eq!(active.len(), 1);
        assert_eq!(active[0].id, "box1");
        assert!((active[0].full_size[0] - 1.2).abs() < 1e-4);
        assert!((active[0].center[1] - (-30.0)).abs() < 1e-4);
    }
}
