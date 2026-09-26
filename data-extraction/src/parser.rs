use std::sync::{Arc, RwLock};

use shared::error::{AppError, ErrorType};
use shared::transport::{PointCloud2, PointField};
use shared::types::{AppPointCloud, ProcessingQueue};
use tracing::warn;

#[derive(Debug, Clone, Copy)]
pub struct PointLayout {
    pub x_offset: usize,
    pub y_offset: usize,
    pub z_offset: usize,
    pub intensity_offset: Option<usize>,
    pub ring_offset: Option<usize>,
    pub timestamp_offset: Option<usize>,
}

pub fn print_cloud_fields(cloud: &PointCloud2) {
    println!("\n============================================================");
    println!("  [PointCloud2 Fields Inspector]");
    println!("============================================================");
    println!(
        "Dimensions:   {} x {} (is_dense: {})",
        cloud.width, cloud.height, cloud.is_dense
    );
    println!(
        "Point step:   {} bytes | Row step: {} bytes | Data len: {} bytes",
        cloud.point_step,
        cloud.row_step,
        cloud.data.len()
    );
    println!("Is bigendian: {}", cloud.is_bigendian);
    println!("Total fields: {}", cloud.fields.len());
    println!("------------------------------------------------------------");
    for (idx, field) in cloud.fields.iter().enumerate() {
        let dt_str = match field.datatype {
            1 => "INT8",
            2 => "UINT8",
            3 => "INT16",
            4 => "UINT16",
            5 => "INT32",
            6 => "UINT32",
            7 => "FLOAT32",
            8 => "FLOAT64",
            _ => "UNKNOWN",
        };
        println!(
            "  [{:2}] name: \"{:16}\" | offset: {:3} | type: {:7} ({}) | count: {}",
            idx, field.name, field.offset, dt_str, field.datatype, field.count
        );
        tracing::info!(
            idx = idx,
            name = %field.name,
            offset = field.offset,
            datatype = dt_str,
            count = field.count,
            "PointCloud2 Field"
        );
    }
    println!("============================================================\n");
}

/// МЕТОД ДЛЯ ОДНОКРАТНОЙ ИНИЦИАЛИЗАЦИИ И ВАЛИДАЦИИ
/// Вызывается только один раз на самом первом кадре, чтобы закэшировать смещения полей.
pub fn extract_and_validate_layout(cloud: &PointCloud2) -> Result<PointLayout, AppError> {
    // print_cloud_fields(cloud);
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
    use std::io::Write;
    let _ = std::io::stdout().flush();

    let x = find_field(message, "x").ok_or(ErrorType::NoneError("x field not found"))?;
    let y = find_field(message, "y").ok_or(ErrorType::NoneError("y field not found"))?;
    let z = find_field(message, "z").ok_or(ErrorType::NoneError("z field not found"))?;

    validate_field(x, PointField::FLOAT32)?;
    validate_field(y, PointField::FLOAT32)?;
    validate_field(z, PointField::FLOAT32)?;

    let intensity = find_field(message, "intensity");
    let intensity_offset = if let Some(int_f) = intensity {
        if int_f.datatype == PointField::FLOAT32
            || int_f.datatype == PointField::UINT8
            || int_f.datatype == PointField::UINT16
        {
            Some(int_f.offset as usize)
        } else {
            None
        }
    } else {
        None
    };

    let ring = find_field(message, "ring")
        .or_else(|| find_field(message, "channel"))
        .or_else(|| find_field(message, "laser_id"))
        .or_else(|| find_field(message, "beam_id"))
        .or_else(|| find_field(message, "line"));

    let ring_offset = if let Some(r) = ring {
        Some(r.offset as usize)
    } else {
        warn!(
            "Notice: 'ring' field is absent in PointCloud2. Computing ring from (x, y, z) geometry."
        );
        None
    };

    Ok(PointLayout {
        x_offset: x.offset as usize,
        y_offset: y.offset as usize,
        z_offset: z.offset as usize,
        intensity_offset,
        ring_offset,
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
    // tracing::info!(
    //     "Data {} of {}",
    //     message.data.len(),
    //     message.width * message.height
    // );
    let width = message.width as usize;
    let height = message.height as usize;
    let point_step = message.point_step as usize;

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

    let vertical_geometry = shared::range_image::Pandar128VerticalGeometry::new();

    let mut i = 0;
    let mut logged_points = 0;

    for point_buf in point_chunks {
        if point_buf.len() < point_step {
            break;
        }

        let x_bytes: [u8; 4] = point_buf[x_off..x_off + 4].try_into().unwrap();
        let y_bytes: [u8; 4] = point_buf[y_off..y_off + 4].try_into().unwrap();
        let z_bytes: [u8; 4] = point_buf[z_off..z_off + 4].try_into().unwrap();

        let px = u32::from_ne_bytes(x_bytes);
        let py = u32::from_ne_bytes(y_bytes);
        let pz = u32::from_ne_bytes(z_bytes);

        let (x, y, z) = if is_bigendian {
            (
                f32::from_bits(u32::from_be(px)),
                f32::from_bits(u32::from_be(py)),
                f32::from_bits(u32::from_be(pz)),
            )
        } else {
            (
                f32::from_bits(u32::from_le(px)),
                f32::from_bits(u32::from_le(py)),
                f32::from_bits(u32::from_le(pz)),
            )
        };

        let intensity = if let Some(i_off) = layout.intensity_offset {
            if i_off + 4 <= point_buf.len() {
                let i_bytes: [u8; 4] = point_buf[i_off..i_off + 4].try_into().unwrap();
                let pi = u32::from_ne_bytes(i_bytes);
                if is_bigendian {
                    f32::from_bits(u32::from_be(pi))
                } else {
                    f32::from_bits(u32::from_le(pi))
                }
            } else {
                0.0
            }
        } else {
            0.0
        };

        let ring = if let Some(r_off) = layout.ring_offset {
            if r_off + 2 <= point_buf.len() {
                let r_bytes: [u8; 2] = point_buf[r_off..r_off + 2].try_into().unwrap();
                let pr = u16::from_ne_bytes(r_bytes);
                if is_bigendian {
                    u16::from_be(pr)
                } else {
                    u16::from_le(pr)
                }
            } else {
                0
            }
        } else {
            // Геометрический расчет кольца (Pandar128 pitch)
            let r2 = x * x + y * y + z * z;
            if r2 < 0.04 {
                0
            } else {
                let r = r2.sqrt();
                let pitch = (z / r).clamp(-1.0, 1.0).asin();
                vertical_geometry.nearest_channel(pitch) as u16
            }
        };

        if logged_points < 5 && (x != 0.0 || y != 0.0 || z != 0.0) {
            let r2 = x * x + y * y + z * z;
            let pitch_deg = if r2 > 0.04 {
                (z / r2.sqrt()).asin().to_degrees()
            } else {
                0.0
            };
            logged_points += 1;
        }

        // Откидываем битые точки (NaN и Infinite)
        if x.is_finite() && y.is_finite() && z.is_finite() {
            cloud.x[write_state][i] = x;
            cloud.y[write_state][i] = y;
            cloud.z[write_state][i] = z;
            cloud.intensity[write_state][i] = intensity;
            cloud.ring[write_state][i] = ring;
            cloud.x[write_state].length += 1;
            cloud.y[write_state].length += 1;
            cloud.z[write_state].length += 1;
            cloud.intensity[write_state].length += 1;
            cloud.ring[write_state].length += 1;

            i += 1;
        }
    }

    cloud.width[write_state] = message.width;
    cloud.height[write_state] = message.height;
    cloud.timestamp[write_state] =
        message.header.stamp.sec as i64 * 1000000000 + message.header.stamp.nanosec as i64;

    // tracing::info!(
    //     "[PARSER] Frame parsed: {} total msg pts, {} points written to WRITE, swapping WRITE -> NEXT",
    //     total_points,
    //     i
    // );

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
