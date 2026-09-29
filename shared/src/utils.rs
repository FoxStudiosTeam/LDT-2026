pub fn remap(val: f32, in_min: f32, in_max: f32, out_min: f32, out_max: f32) -> f32 {
    out_min + (val - in_min) * (out_max - out_min) / (in_max - in_min)
}

/// Линейное отображение со строгим ограничением (clamp) входного значения в диапазоне [in_min, in_max]
pub fn remap_clamped(val: f32, in_min: f32, in_max: f32, out_min: f32, out_max: f32) -> f32 {
    let (lo, hi) = if in_min <= in_max {
        (in_min, in_max)
    } else {
        (in_max, in_min)
    };
    if (hi - lo).abs() < 1e-6 {
        return out_min;
    }
    let clamped_val = val.clamp(lo, hi);
    out_min + (clamped_val - in_min) * (out_max - out_min) / (in_max - in_min)
}
