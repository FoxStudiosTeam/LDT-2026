use crate::error::Error;

use ros2_interfaces_jazzy_serde::sensor_msgs::msg::{
    PointCloud2,
    PointField,
};

use super::{Header, Point, PointCloud, Time};

struct PointLayout {
    x_offset: usize,
    y_offset: usize,
    z_offset: usize,
    intensity_offset: usize,
    ring_offset: Option<usize>,
    timestamp_offset: Option<usize>,
}

pub fn parse_pointcloud(message: PointCloud2) -> Result<PointCloud, Error> {
    validate_message(&message)?;

    let layout = create_layout(&message)?;

    let points = parse_points(&message, &layout)?;

    Ok(PointCloud {
        header: Header {
            stamp: Time {
                sec: message.header.stamp.sec,
                nanosec: message.header.stamp.nanosec,
            },
            frame_id: message.header.frame_id,
        },
        width: message.width,
        height: message.height,
        points,
        is_dense: message.is_dense,
    })
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

fn parse_points(
    message: &PointCloud2,
    layout: &PointLayout,
) -> Result<Box<[Point]>, Error> {
    let width = message.width as usize;
    let height = message.height as usize;
    let point_step = message.point_step as usize;
    let row_step = message.row_step as usize;

    let point_count = width
        .checked_mul(height)
        .ok_or(Error::SizeOverflow)?;

    let mut points = vec![Point::default(); point_count]
        .into_boxed_slice();

    let data = &message.data;
    let is_bigendian = message.is_bigendian;

    let mut index = 0;

    for row in 0..height {
        let row_start = row * row_step;

        for column in 0..width {
            let point_start = row_start + column * point_step;

            points[index] = Point {
                x: read_f32(
                    data,
                    is_bigendian,
                    point_start + layout.x_offset,
                )?,

                y: read_f32(
                    data,
                    is_bigendian,
                    point_start + layout.y_offset,
                )?,

                z: read_f32(
                    data,
                    is_bigendian,
                    point_start + layout.z_offset,
                )?,

                intensity: read_f32(
                    data,
                    is_bigendian,
                    point_start + layout.intensity_offset,
                )?,

                ring: layout.ring_offset
                    .map(|offset| {
                        read_u16(
                            data,
                            is_bigendian,
                            point_start + offset,
                        )
                    })
                    .transpose()?,

                timestamp: layout.timestamp_offset
                    .map(|offset| {
                        read_f64(
                            data,
                            is_bigendian,
                            point_start + offset,
                        )
                    })
                    .transpose()?,
            };

            index += 1;
        }
    }

    Ok(points)
}

fn read_f32(
    data: &[u8],
    is_bigendian: bool,
    offset: usize,
) -> Result<f32, Error> {
    let bytes = data
        .get(offset..offset + 4)
        .ok_or(Error::DataOutOfBounds {
            field: "f32".to_string(),
            offset,
            size: 4,
            data_len: data.len(),
        })?;

    let bytes: [u8; 4] = bytes
        .try_into()
        .expect("slice length was checked");

    Ok(if is_bigendian {
        f32::from_be_bytes(bytes)
    } else {
        f32::from_le_bytes(bytes)
    })
}

fn read_u16(
    data: &[u8],
    is_bigendian: bool,
    offset: usize,
) -> Result<u16, Error> {
    let bytes = data
        .get(offset..offset + 2)
        .ok_or(Error::DataOutOfBounds {
            field: "u16".to_string(),
            offset,
            size: 2,
            data_len: data.len(),
        })?;

    let bytes: [u8; 2] = bytes
        .try_into()
        .expect("slice length was checked");

    Ok(if is_bigendian {
        u16::from_be_bytes(bytes)
    } else {
        u16::from_le_bytes(bytes)
    })
}

fn read_f64(
    data: &[u8],
    is_bigendian: bool,
    offset: usize,
) -> Result<f64, Error> {
    let bytes = data
        .get(offset..offset + 8)
        .ok_or(Error::DataOutOfBounds {
            field: "f64".to_string(),
            offset,
            size: 8,
            data_len: data.len(),
        })?;

    let bytes: [u8; 8] = bytes
        .try_into()
        .expect("slice length was checked");

    Ok(if is_bigendian {
        f64::from_be_bytes(bytes)
    } else {
        f64::from_le_bytes(bytes)
    })
}

fn find_field<'a>(
    message: &'a PointCloud2,
    name: &str,
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