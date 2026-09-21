use std::sync::{Arc, RwLock};

use shared::error::{AppError, ErrorType};
use shared::transport::{PointCloud2, PointField};
use shared::types::{AppPointCloud, ProcessingQueue};

#[derive(Debug, Clone, Copy)]
pub struct PointLayout {
    pub x_offset: usize,
    pub y_offset: usize,
    pub z_offset: usize,
    pub intensity_offset: usize,
    pub ring_offset: Option<usize>,
    pub timestamp_offset: Option<usize>,
}

/// МЕТОД ДЛЯ ОДНОКРАТНОЙ ИНИЦИАЛИЗАЦИИ И ВАЛИДАЦИИ
/// Вызывается только один раз на самом первом кадре, чтобы закэшировать смещения полей.
pub fn extract_and_validate_layout(cloud: &PointCloud2) -> Result<PointLayout, AppError> {
    validate_message(cloud)?;
    create_layout(cloud)
}

fn validate_message(message: &PointCloud2) -> Result<(), AppError> {
    let point_step = message.point_step as usize;
    let row_step = message.row_step as usize;
    let width = message.width as usize;

    let d = width * point_step;

    let minimum_row_step = width
        .checked_mul(point_step)
        .ok_or(ErrorType::message(format!("current size: {d}").to_string()))?;

    if row_step < minimum_row_step {
        return ErrorType::InvalidRowStep {
            row_step,
            width,
            point_step,
        }
        .err();
    }

    for field in &message.fields {
        let size = datatype_size(field.datatype)?;

        let field_size = size
            .checked_mul(field.count as usize)
            .ok_or(ErrorType::message(format!("current size: {d}")))?;

        let required_end = (field.offset as usize)
            .checked_add(field_size)
            .ok_or(ErrorType::message(format!("current size: {d}")))?;

        if required_end > point_step {
            return ErrorType::InvalidPointStep {
                point_step,
                field: field.name.clone(),
                required_end,
            }
            .err();
        }
    }

    Ok(())
}

fn find_field<'a>(message: &'a PointCloud2, name: &'a str) -> Option<&'a PointField> {
    message.fields.iter().find(|field| field.name == name)
}

fn create_layout(message: &PointCloud2) -> Result<PointLayout, AppError> {
    let x = find_field(message, "x").ok_or(ErrorType::NoneError("x field not found"))?;

    let y = find_field(message, "y").ok_or(ErrorType::NoneError("y field not found"))?;

    let z = find_field(message, "z").ok_or(ErrorType::NoneError("z field not found"))?;

    let intensity = find_field(message, "intensity")
        .ok_or(ErrorType::NoneError("intensity field not found"))?;

    validate_field(x, PointField::FLOAT32)?;
    validate_field(y, PointField::FLOAT32)?;
    validate_field(z, PointField::FLOAT32)?;
    validate_field(intensity, PointField::FLOAT32)?;

    Ok(PointLayout {
        x_offset: x.offset as usize,
        y_offset: y.offset as usize,
        z_offset: z.offset as usize,
        intensity_offset: intensity.offset as usize,
        ring_offset: None,
        timestamp_offset: None,
    })
}

fn validate_field(field: &PointField, expected_datatype: u8) -> Result<(), AppError> {
    if field.count != 1 {
        return ErrorType::InvalidFieldCount {
            field: field.name.clone(),
            expected: 1,
            actual: field.count,
        }
        .err();
    }

    if field.datatype != expected_datatype {
        return ErrorType::UnexpectedDatatype {
            expected_datatype,
            actual_datatype: field.datatype,
        }
        .err();
    }

    Ok(())
}

pub fn parse_coords(
    message: &PointCloud2,
    cloud: Arc<RwLock<AppPointCloud>>,
    layout: &PointLayout,
) -> Result<(), AppError> {
    tracing::info!(
        "Data {} of {}",
        message.data.len(),
        message.width * message.height
    );
    let width = message.width as usize;
    let height = message.height as usize;
    let point_step = message.point_step as usize;

    // тут короче мутекс пойзон 👉👈 который не sync+send потому что гард держит, поэтому моя synd+send app_error не работает 💔
    let mut cloud = cloud.write().map_err(
        |e: std::sync::PoisonError<
            std::sync::RwLockWriteGuard<'_, shared::types::PointCloud<2000000>>,
        >| { ErrorType::message(e) },
    )?;

    if !cloud.can_write {
        return Ok(());
    }


    if width == 0 || height == 0 || message.data.is_empty() {
        return Ok(());
    }
    let d = width * height;

    let write_state = ProcessingQueue::WRITE;

    cloud.clear(write_state);

    let total_points = width
        .checked_mul(height)
        .ok_or(ErrorType::message(format!("current size: {d}").to_string()))?;

    if total_points > AppPointCloud::CAP {
        return ErrorType::message(format!("current size: {d}").to_string()).err();
    }

    let is_bigendian = message.is_bigendian;
    let data = &message.data;

    let point_chunks = data.chunks_exact(point_step).take(total_points);

    let x_off = layout.x_offset;
    let y_off = layout.y_offset;
    let z_off = layout.z_offset;
    let i_off = layout.intensity_offset;

    let mut i = 0;

    let mut logged_points = 0;

    for point_buf in point_chunks {
        if point_buf.len() < point_step {
            break;
        }
        
        // Безопасное чтение 4-байтовых кусков, устойчивое к невыровненному point_step = 26
        let x_bytes: [u8; 4] = point_buf[x_off..x_off + 4].try_into().unwrap();
        let y_bytes: [u8; 4] = point_buf[y_off..y_off + 4].try_into().unwrap();
        let z_bytes: [u8; 4] = point_buf[z_off..z_off + 4].try_into().unwrap();
        let i_bytes: [u8; 4] = point_buf[i_off..i_off + 4].try_into().unwrap();

        // Превращаем байты в u32 с учетом родного порядка байт процессора (Native Endian)
        let px = u32::from_ne_bytes(x_bytes);
        let py = u32::from_ne_bytes(y_bytes);
        let pz = u32::from_ne_bytes(z_bytes);
        let pi = u32::from_ne_bytes(i_bytes);

        let (x, y, z, intensity) = if is_bigendian {
            (
                f32::from_bits(u32::from_be(px)),
                f32::from_bits(u32::from_be(py)),
                f32::from_bits(u32::from_be(pz)),
                f32::from_bits(u32::from_be(pi)),
            )
        } else {
            (
                f32::from_bits(u32::from_le(px)),
                f32::from_bits(u32::from_le(py)),
                f32::from_bits(u32::from_le(pz)),
                f32::from_bits(u32::from_le(pi)),
            )
        };
        
        if logged_points < 5 && (x != 0.0 || y != 0.0 || z != 0.0) {
            tracing::info!(
                "POINT {}:\n  \
                X: bytes={:X?}, parsed={}, finite={}\n  \
                Y: bytes={:X?}, parsed={}, finite={}\n  \
                Z: bytes={:X?}, parsed={}, finite={}\n  \
                I: bytes={:X?}, parsed={}, finite={}", 
                i, 
                x_bytes, x, x.is_finite(),
                y_bytes, y, y.is_finite(),
                z_bytes, z, z.is_finite(),
                i_bytes, intensity, intensity.is_finite()
            );
            logged_points+=1;
        }

        // Откидываем битые точки (NaN и Infinite)
        if x.is_finite() && y.is_finite() && z.is_finite() {
            cloud.x[write_state][i] = x;
            cloud.y[write_state][i] = y;
            cloud.z[write_state][i] = z;
            cloud.intensity[write_state][i] = intensity;
            cloud.x[write_state].length += 1;
            cloud.y[write_state].length += 1;
            cloud.z[write_state].length += 1;
            cloud.intensity[write_state].length += 1;

            i+=1;
        }
    }


    cloud.width[write_state] = message.width;
    cloud.height[write_state] = message.height;
    cloud.timestamp[write_state] = message.header.stamp.sec as i64 * 1000000000 + message.header.stamp.nanosec as i64;

    cloud.change_state(write_state, ProcessingQueue::NEXT);

    Ok(())
}

fn datatype_size(datatype: u8) -> Result<usize, AppError> {
    match datatype {
        PointField::INT8 | PointField::UINT8 => Ok(1),

        PointField::INT16 | PointField::UINT16 => Ok(2),

        PointField::INT32 | PointField::UINT32 | PointField::FLOAT32 => Ok(4),

        PointField::FLOAT64 => Ok(8),

        datatype => ErrorType::UnsupportedDatatype(datatype).err(),
    }
}
