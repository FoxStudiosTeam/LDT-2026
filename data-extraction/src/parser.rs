use std::sync::{Arc, RwLock};

use crate::error::Error;

use ddl::AppPointCloud;
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::{
    PointCloud2,
    PointField,
};

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
pub fn extract_and_validate_layout(message: &PointCloud2) -> Result<PointLayout, Error> {
    validate_message(message)?;
    create_layout(message)
}

fn validate_message(message: &PointCloud2) -> Result<(), Error> {
    let point_step = message.point_step as usize;
    let row_step = message.row_step as usize;
    let width = message.width as usize;

    let minimum_row_step = width
        .checked_mul(point_step)
        .ok_or(Error::SizeOverflow)?;

    if row_step < minimum_row_step {
        return Err(Error::InvalidRowStep {
            row_step,
            width,
            point_step,
        });
    }

    for field in &message.fields {
        let size = datatype_size(field.datatype)?;

        let field_size = size
            .checked_mul(field.count as usize)
            .ok_or(Error::SizeOverflow)?;

        let required_end = (field.offset as usize)
            .checked_add(field_size)
            .ok_or(Error::SizeOverflow)?;

        if required_end > point_step {
            return Err(Error::InvalidPointStep {
                point_step,
                field: field.name.clone(),
                required_end,
            });
        }
    }

    Ok(())
}

fn create_layout(message: &PointCloud2) -> Result<PointLayout, Error> {
    let x = find_field(message, "x")
        .ok_or(Error::NoneError("x field not found"))?;

    let y = find_field(message, "y")
        .ok_or(Error::NoneError("y field not found"))?;

    let z = find_field(message, "z")
        .ok_or(Error::NoneError("z field not found"))?;

    let intensity = find_field(message, "intensity")
        .ok_or(Error::NoneError("intensity field not found"))?;

    validate_field(x, PointField::FLOAT32)?;
    validate_field(y, PointField::FLOAT32)?;
    validate_field(z, PointField::FLOAT32)?;
    validate_field(intensity, PointField::FLOAT32)?;

    let ring = find_field(message, "ring");

    if let Some(field) = ring {
        validate_field(field, PointField::UINT16)?;
    }

    let timestamp = find_field(message, "timestamp");

    if let Some(field) = timestamp {
        validate_field(field, PointField::FLOAT64)?;
    }

    Ok(PointLayout {
        x_offset: x.offset as usize,
        y_offset: y.offset as usize,
        z_offset: z.offset as usize,
        intensity_offset: intensity.offset as usize,
        ring_offset: ring.map(|field| field.offset as usize),
        timestamp_offset: timestamp.map(|field| field.offset as usize),
    })
}

fn validate_field(
    field: &PointField,
    expected_datatype: u8,
) -> Result<(), Error> {
    if field.count != 1 {
        return Err(Error::InvalidFieldCount {
            field: field.name.clone(),
            expected: 1,
            actual: field.count,
        });
    }

    if field.datatype != expected_datatype {
        return Err(Error::UnexpectedDatatype {
            expected_datatype,
            actual_datatype: field.datatype,
        });
    }

    Ok(())
}

pub fn parse_coords(message: &PointCloud2, cloud: &mut AppPointCloud, layout: &PointLayout) -> Result<(), Error> {
    let width = message.width as usize;
    let height = message.height as usize;
    let point_step = message.point_step as usize;

    let total_points = width
        .checked_mul(height)
        .ok_or(Error::SizeOverflow)?;

    if total_points > AppPointCloud::CAP {
        return Err(Error::SizeOverflow);
    }

    let is_bigendian = message.is_bigendian;
    let data = &message.data;

    let point_chunks = data.chunks_exact(point_step).take(total_points);
    let mut valid_count = 0;

    let x_off = layout.x_offset;
    let y_off = layout.y_offset;
    let z_off = layout.z_offset;
    let i_off = layout.intensity_offset;

    for point_buf in point_chunks {
        if point_buf.len() < point_step { 
            break; 
        }

        // Высокопроизводительное чтение памяти по сырым указателям через регистры CPU
        let (x, y, z, intensity) = unsafe {
            let px = *(point_buf.as_ptr().add(x_off) as *const u32);
            let py = *(point_buf.as_ptr().add(y_off) as *const u32);
            let pz = *(point_buf.as_ptr().add(z_off) as *const u32);
            let pi = *(point_buf.as_ptr().add(i_off) as *const u32);

            if is_bigendian {
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
            }
        };

        if x.is_finite() && y.is_finite() && z.is_finite() {
            cloud.x[valid_count] = x;
            cloud.y[valid_count] = y;
            cloud.z[valid_count] = z;
            cloud.intensity[valid_count] = intensity;
            
            valid_count += 1;
        }

        if let Some(offset) = layout.ring_offset {
            if let Some(bytes) = point_buf.get(offset..offset + 2) {
                let r = if is_bigendian {
                    u16::from_be_bytes(bytes.try_into().unwrap())
                } else {
                    u16::from_le_bytes(bytes.try_into().unwrap())
                };
                cloud.ring = r;
            }
        }

        if let Some(offset) = layout.timestamp_offset {
            if let Some(bytes) = point_buf.get(offset..offset + 8) {
                let t = if is_bigendian {
                    f64::from_be_bytes(bytes.try_into().unwrap())
                } else {
                    f64::from_le_bytes(bytes.try_into().unwrap())
                };
                cloud.timestamp = t;
            }
        }
    }

    cloud.length = valid_count;

    Ok(())
}

fn find_field<'a>(
    message: &'a PointCloud2,
    name: &'a str,
) -> Option<&'a PointField> {
    message.fields.iter().find(|field| field.name == name)
}

fn datatype_size(datatype: u8) -> Result<usize, Error> {
    match datatype {
        PointField::INT8 | PointField::UINT8 => Ok(1),

        PointField::INT16 | PointField::UINT16 => Ok(2),

        PointField::INT32
        | PointField::UINT32
        | PointField::FLOAT32 => Ok(4),

        PointField::FLOAT64 => Ok(8),

        datatype => Err(Error::UnsupportedDatatype(datatype)),
    }
}
