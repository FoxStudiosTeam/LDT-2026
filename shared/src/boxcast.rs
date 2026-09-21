//! Одноосевой boxcast по облаку точек.
//!
//! Система координат — ROS (REP-103), она же используется при логировании в Rerun:
//! `X` — вперёд, `Y` — влево, `Z` — вверх. Соответствие [`BoxCastAxis`] осям
//! задано в одном месте (`BoxCastAxis::index` / `BoxCastAxis::sign`).
//!
//! Алгоритм:
//! 1. Строим прямоугольник (объём) движения: стартовый бокс, «протянутый» на
//!    `distance` вдоль оси.
//! 2. Точки вне этого объёма (сбоку, позади, дальше `distance`) отбрасываются.
//! 3. Для каждой оставшейся точки считаем, на сколько бокс может сдвинуться до
//!    касания с ней, и берём самые близкие к старту.
//! 4. `threshold` — сколько точек должно «подтвердить» столкновение. Столкновением
//!    считается касание `threshold`-й по близости точки: 1–2 шумовые точки перед
//!    стеной при `threshold >= 3` игнорируются.
//!
//! Аллокаций в рантайме нет: каждый rayon-воркер держит на стеке маленький
//! аккумулятор из `MAX_THRESHOLD` ближайших кандидатов, потом аккумуляторы
//! сливаются. Идёт чтение только трёх нужных колонок (ось + две поперечные).

use rayon::prelude::*;

use crate::types::{PointCloud, ProcessingQueue};

/// Максимальный `threshold` (размер стекового буфера кандидатов).
pub const MAX_THRESHOLD: usize = 32;

/// Минимальный размер куска для rayon — чтобы не дробить работу слишком мелко.
const PAR_MIN_LEN: usize = 16 * 1024;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BoxCastAxis {
    Left,
    Right,
    Forward,
    Backward,
    Up,
    Down,
}

impl BoxCastAxis {
    /// Индекс оси в `[x, y, z]`.
    #[inline(always)]
    pub const fn index(self) -> usize {
        match self {
            Self::Forward | Self::Backward => 1, // X
            Self::Left | Self::Right => 0,       // Y
            Self::Up | Self::Down => 2,          // Z
        }
    }

    /// Знак направления движения вдоль оси.
    #[inline(always)]
    pub const fn sign(self) -> f32 {
        match self {
            Self::Backward | Self::Left | Self::Up => 1.0,
            Self::Forward | Self::Right | Self::Down => -1.0,
        }
    }

    /// Индексы двух поперечных осей.
    #[inline(always)]
    const fn perpendicular(self) -> (usize, usize) {
        match self.index() {
            0 => (1, 2),
            1 => (0, 2),
            _ => (0, 1),
        }
    }
}

#[derive(Clone, Copy, Debug)]
pub struct BoxCastQuery {
    /// Центр стартового бокса `[x, y, z]`.
    pub center: [f32; 3],
    /// Половинные размеры стартового бокса `[x, y, z]`.
    pub half_size: [f32; 3],
    /// Дистанция, на которую двигаем бокс (отрицательная трактуется как 0).
    pub distance: f32,
    pub axis: BoxCastAxis,
    /// Минимум точек для подтверждения столкновения, `1..=MAX_THRESHOLD`.
    pub threshold: usize,
}

impl BoxCastQuery {
    #[inline]
    fn dist(&self) -> f32 {
        self.distance.max(0.0)
    }

    #[inline]
    fn cap(&self) -> usize {
        self.threshold.clamp(1, MAX_THRESHOLD)
    }

    /// Прямоугольник движения (объём, в котором ищем точки): `(центр, half_size)`.
    pub fn sweep_volume(&self) -> ([f32; 3], [f32; 3]) {
        let a = self.axis.index();
        let d = self.dist();
        let mut center = self.center;
        let mut half = self.half_size;
        center[a] += self.axis.sign() * d * 0.5;
        half[a] += d * 0.5;
        (center, half)
    }

    /// Центр бокса, сдвинутого на `travel` вдоль оси.
    pub fn box_center_at(&self, travel: f32) -> [f32; 3] {
        let mut center = self.center;
        center[self.axis.index()] += self.axis.sign() * travel;
        center
    }
}

#[derive(Clone, Copy, Debug)]
pub struct BoxCastResult {
    /// Столкновение подтверждено (в объёме движения не меньше `threshold` точек).
    pub hit: bool,
    /// Сколько бокс может пройти: расстояние до `threshold`-й точки при `hit`,
    /// иначе запрошенная `distance`.
    pub distance: f32,
    /// Сколько всего точек попало в объём движения (без фильтра по `threshold`).
    pub points_in_sweep: usize,
    /// Сколько кандидатов заполнено в `nearest*` (`min(threshold, points_in_sweep)`).
    pub nearest_len: usize,
    /// Ближайшие к старту точки (по возрастанию расстояния). При `hit == false`
    /// это отсеянный «шум».
    pub nearest: [[f32; 3]; MAX_THRESHOLD],
    /// Расстояние движения до касания каждой из точек `nearest`.
    pub nearest_distances: [f32; MAX_THRESHOLD],
}

impl BoxCastResult {
    #[inline]
    pub fn nearest_points(&self) -> &[[f32; 3]] {
        &self.nearest[..self.nearest_len]
    }
}

/// Аккумулятор `cap` ближайших кандидатов. Порядок — по `(t, idx)`, поэтому
/// результат не зависит от того, как rayon порезал работу между потоками.
#[derive(Clone, Copy)]
struct Nearest {
    cap: usize,
    len: usize,
    in_sweep: usize,
    t: [f32; MAX_THRESHOLD],
    idx: [u32; MAX_THRESHOLD],
}

impl Nearest {
    #[inline]
    fn new(cap: usize) -> Self {
        Self {
            cap,
            len: 0,
            in_sweep: 0,
            t: [0.0; MAX_THRESHOLD],
            idx: [0; MAX_THRESHOLD],
        }
    }

    #[inline(always)]
    fn before(t1: f32, i1: u32, t2: f32, i2: u32) -> bool {
        t1 < t2 || (t1 == t2 && i1 < i2)
    }

    #[inline(always)]
    fn insert(&mut self, t: f32, idx: u32) {
        if self.len == self.cap {
            let last = self.len - 1;
            if !Self::before(t, idx, self.t[last], self.idx[last]) {
                return;
            }
        } else {
            self.len += 1;
        }

        let mut pos = self.len - 1;
        while pos > 0 && Self::before(t, idx, self.t[pos - 1], self.idx[pos - 1]) {
            self.t[pos] = self.t[pos - 1];
            self.idx[pos] = self.idx[pos - 1];
            pos -= 1;
        }
        self.t[pos] = t;
        self.idx[pos] = idx;
    }

    #[inline(always)]
    fn push(mut self, t: f32, idx: u32) -> Self {
        self.in_sweep += 1;
        self.insert(t, idx);
        self
    }

    fn merge(mut self, other: Self) -> Self {
        for k in 0..other.len {
            self.insert(other.t[k], other.idx[k]);
        }
        self.in_sweep += other.in_sweep;
        self
    }
}

/// Boxcast по колонкам координат (`xs`, `ys`, `zs` одинаковой длины).
pub fn box_cast(xs: &[f32], ys: &[f32], zs: &[f32], q: &BoxCastQuery) -> BoxCastResult {
    let n = xs.len().min(ys.len()).min(zs.len());
    debug_assert!(n <= u32::MAX as usize);

    let cols: [&[f32]; 3] = [&xs[..n], &ys[..n], &zs[..n]];
    let axis = q.axis.index();
    let (u_ax, v_ax) = q.axis.perpendicular();
    let (pa, pu, pv) = (cols[axis], cols[u_ax], cols[v_ax]);

    let (ca, cu, cv) = (q.center[axis], q.center[u_ax], q.center[v_ax]);
    let (ha, hu, hv) = (q.half_size[axis], q.half_size[u_ax], q.half_size[v_ax]);
    let sign = q.axis.sign();
    let d = q.dist();
    let cap = q.cap();

    let acc = pa
        .par_iter()
        .zip(pu.par_iter())
        .zip(pv.par_iter())
        .enumerate()
        .with_min_len(PAR_MIN_LEN)
        .fold(
            || Nearest::new(cap),
            |acc, (i, ((&a, &u), &v))| {
                // Исключаем точки в начале координат (шум/пустые возвраты)
                if crate::types::is_zero_point(a, u, v) {
                    return acc;
                }
                // Отрицательная форма условий: NaN не проходит ни одну проверку.
                let along = sign * (a - ca); // координата вдоль движения
                if !(along >= -ha && along <= ha + d) {
                    return acc; // позади бокса или дальше дистанции
                }
                if !((u - cu).abs() <= hu && (v - cv).abs() <= hv) {
                    return acc; // вне поперечного сечения
                }
                // Насколько можно сдвинуться до касания; 0 — точка уже внутри бокса.
                let t = (along - ha).max(0.0);
                acc.push(t, i as u32)
            },
        )
        .reduce(|| Nearest::new(cap), Nearest::merge);

    let hit = acc.len == cap;
    let mut result = BoxCastResult {
        hit,
        distance: if hit { acc.t[cap - 1] } else { d },
        points_in_sweep: acc.in_sweep,
        nearest_len: acc.len,
        nearest: [[0.0; 3]; MAX_THRESHOLD],
        nearest_distances: [0.0; MAX_THRESHOLD],
    };
    for k in 0..acc.len {
        let i = acc.idx[k] as usize;
        result.nearest[k] = [xs[i], ys[i], zs[i]];
        result.nearest_distances[k] = acc.t[k];
    }
    result
}

impl<const SIZE: usize> PointCloud<SIZE> {
    /// Boxcast по одному из буферов облака (обычно `READ`).
    pub fn box_cast(&self, queue: ProcessingQueue, q: &BoxCastQuery) -> BoxCastResult {
        let n = self.len(queue);
        if n == 0 {
            return box_cast(&[], &[], &[], q);
        }
        box_cast(
            &self.x[queue][..n],
            &self.y[queue][..n],
            &self.z[queue][..n],
            q,
        )
    }
}
