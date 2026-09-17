use std::error::Error;
use std::fmt;

use ros2_interfaces_jazzy_serde::sensor_msgs::msg::{PointCloud2, PointField};
use crate::point_cloud::parser_to_rust::FromPointValue;
use super::{Field, Header, Point, PointCloud, Time};

#[derive(Debug)]
pub enum ParseError {
    UnsupportedDatatype(u8),
    InvalidFieldCount {
        field: String,
        expected: u32,
        actual: u32,
    },
    DataOutOfBounds {
        field: String,
        offset: usize,
        size: usize,
        data_len: usize,
    },
    InvalidPointStep {
        point_step: usize,
        field: String,
        required_end: usize,
    },
    InvalidRowStep {
        row_step: usize,
        width: usize,
        point_step: usize,
    },
    MissingField {
        field_name: String,
    },
    UnexpectedDatatype {
        expected_datatype: u8,
        actual_datatype: u8,
    }
}

impl fmt::Display for ParseError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::UnsupportedDatatype(datatype) => {
                write!(f, "Unsupported PointField datatype: {datatype}")
            }

            Self::InvalidFieldCount {
                field,
                expected,
                actual,
            } => {
                write!(
                    f,
                    "Invalid count for field '{field}': expected {expected}, got {actual}"
                )
            }

            Self::DataOutOfBounds {
                field,
                offset,
                size,
                data_len,
            } => {
                write!(
                    f,
                    "Field '{field}' is out of data bounds: \
                     offset={offset}, size={size}, data_len={data_len}"
                )
            }

            Self::InvalidPointStep {
                point_step,
                field,
                required_end,
            } => {
                write!(
                    f,
                    "Field '{field}' does not fit into point_step: \
                     point_step={point_step}, required_end={required_end}"
                )
            }

            Self::InvalidRowStep {
                row_step,
                width,
                point_step,
            } => {
                write!(
                    f,
                    "Invalid row_step: row_step={row_step}, \
                     width={width}, point_step={point_step}"
                )
            }

            Self::MissingField { field_name} => {
                write!(f, "Missing field '{field_name}'")
            }

            Self::UnexpectedDatatype {
                expected_datatype,
                actual_datatype } => {
                write!(f, "Unexpected data type:\
                 expected={expected_datatype}, actual={actual_datatype}")
            }
        }
    }
}

impl Error for ParseError {}

#[derive(Debug, Clone, Copy)]
pub enum PointValue {
    I8(i8),
    U8(u8),
    I16(i16),
    U16(u16),
    I32(i32),
    U32(u32),
    F32(f32),
    F64(f64),
}

impl PointValue {
    pub fn datatype(&self) -> u8 {
        match self {
            PointValue::I8(_) => PointField::INT8,
            PointValue::U8(_) => PointField::UINT8,
            PointValue::I16(_) => PointField::INT16,
            PointValue::U16(_) => PointField::UINT16,
            PointValue::I32(_) => PointField::INT32,
            PointValue::U32(_) => PointField::UINT32,
            PointValue::F32(_) => PointField::FLOAT32,
            PointValue::F64(_) => PointField::FLOAT64,
        }
    }
}

pub fn parse_pointcloud(message: PointCloud2) -> Result<PointCloud, ParseError> {
    validate_message(&message)?;

    let fields = message
        .fields
        .iter()
        .map(|field| Field {
            name: field.name.clone(),
            offset: field.offset,
            datatype: field.datatype,
            count: field.count,
        })
        .collect();

    let points = parse_points(&message)?;

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
        fields,
        points,
        is_dense: message.is_dense,
    })
}

fn validate_message(message: &PointCloud2) -> Result<(), ParseError> {
    let point_step = message.point_step as usize;
    let row_step = message.row_step as usize;
    let width = message.width as usize;

    let minimum_row_step = width * point_step;

    if row_step < minimum_row_step {
        return Err(ParseError::InvalidRowStep {
            row_step,
            width,
            point_step,
        });
    }

    for field in &message.fields {
        let datatype_size = datatype_size(field.datatype)?;

        let field_size = datatype_size * field.count as usize;

        let required_end = field.offset as usize + field_size;

        if required_end > point_step {
            return Err(ParseError::InvalidPointStep {
                point_step,
                field: field.name.clone(),
                required_end,
            });
        }
    }

    Ok(())
}

fn parse_points(message: &PointCloud2) -> Result<Vec<Point>, ParseError> {
    let width = message.width as usize;
    let height = message.height as usize;
    let point_step = message.point_step as usize;
    let row_step = message.row_step as usize;

    let point_count = width * height;

    let x_field = find_field(message, "x");
    let y_field = find_field(message, "y");
    let z_field = find_field(message, "z");
    let intensity_field = find_field(message, "intensity");
    let ring_field = find_field(message, "ring");
    let timestamp_field = find_field(message, "timestamp");

    let data = &message.data;
    let is_bigendian = message.is_bigendian;

    let mut points = Vec::with_capacity(point_count);

    for row in 0..height {
        let row_start = row * row_step;

        for column in 0..width {
            let point_start = row_start + column * point_step;

            let point = Point {
                x: x_field.map(|field| {
                    read_field_as::<f32>(
                        data,
                        is_bigendian,
                        point_start,
                        field,
                    )
                }).transpose()?,

                y: y_field.map(|field| {
                    read_field_as::<f32>(
                        data,
                        is_bigendian,
                        point_start,
                        field,
                    )
                }).transpose()?,

                z: z_field.map(|field| {
                    read_field_as::<f32>(
                        data,
                        is_bigendian,
                        point_start,
                        field,
                    )
                }).transpose()?,

                intensity: intensity_field.map(|field| {
                    read_field_as::<f32>(
                        data,
                        is_bigendian,
                        point_start,
                        field,
                    )
                }).transpose()?,

                ring: ring_field.map(|field| {
                    read_field_as::<u16>(
                        data,
                        is_bigendian,
                        point_start,
                        field,
                    )
                }).transpose()?,

                timestamp: timestamp_field.map(|field| {
                    read_field_as::<f64>(
                        data,
                        is_bigendian,
                        point_start,
                        field,
                    )
                }).transpose()?,
            };

            points.push(point);
        }
    }

    Ok(points)
}

fn find_field<'a>(
    message: &'a PointCloud2,
    name: &str,
) -> Option<&'a PointField> {
    message.fields.iter().find(|field| field.name == name)
}

pub fn read_field_as<T: FromPointValue>(
    data: &[u8],
    is_bigendian: bool,
    point_start: usize,
    field: &PointField,
) -> Result<T, ParseError> {
    let value = read_field(
        data,
        is_bigendian,
        point_start,
        field,
    )?;

    T::from_point_value(value)
}
fn read_field(
    data: &[u8],
    is_bigendian: bool,
    point_start: usize,
    field: &PointField,
) -> Result<PointValue, ParseError> {

    if field.count != 1 {
        return Err(ParseError::InvalidFieldCount {
            field: field.name.clone(),
            expected: 1,
            actual: field.count,
        });
    }

    let offset = point_start + field.offset as usize;

    match field.datatype {
        PointField::INT8 => {
            let bytes = get_bytes::<1>(
                data,
                field,
                offset,
            )?;

            Ok(PointValue::I8(bytes[0] as i8))
        }

        PointField::UINT8 => {
            let bytes = get_bytes::<1>(
                data,
                field,
                offset,
            )?;

            Ok(PointValue::U8(bytes[0]))
        }

        PointField::INT16 => {
            let bytes = get_bytes::<2>(
                data,
                field,
                offset,
            )?;

            let value = if is_bigendian {
                i16::from_be_bytes(bytes)
            } else {
                i16::from_le_bytes(bytes)
            };

            Ok(PointValue::I16(value))
        }

        PointField::UINT16 => {
            let bytes = get_bytes::<2>(
                data,
                field,
                offset,
            )?;

            let value = if is_bigendian {
                u16::from_be_bytes(bytes)
            } else {
                u16::from_le_bytes(bytes)
            };

            Ok(PointValue::U16(value))
        }

        PointField::INT32 => {
            let bytes = get_bytes::<4>(
                data,
                field,
                offset,
            )?;

            let value = if is_bigendian {
                i32::from_be_bytes(bytes)
            } else {
                i32::from_le_bytes(bytes)
            };

            Ok(PointValue::I32(value))
        }

        PointField::UINT32 => {
            let bytes = get_bytes::<4>(
                data,
                field,
                offset,
            )?;

            let value = if is_bigendian {
                u32::from_be_bytes(bytes)
            } else {
                u32::from_le_bytes(bytes)
            };

            Ok(PointValue::U32(value))
        }

        PointField::FLOAT32 => {
            let bytes = get_bytes::<4>(
                data,
                field,
                offset,
            )?;

            let value = if is_bigendian {
                f32::from_be_bytes(bytes)
            } else {
                f32::from_le_bytes(bytes)
            };

            Ok(PointValue::F32(value))
        }

        PointField::FLOAT64 => {
            let bytes = get_bytes::<8>(
                data,
                field,
                offset,
            )?;

            let value = if is_bigendian {
                f64::from_be_bytes(bytes)
            } else {
                f64::from_le_bytes(bytes)
            };

            Ok(PointValue::F64(value))
        }

        datatype => {
            Err(ParseError::UnsupportedDatatype(datatype))
        }
    }
}

fn get_bytes<const N: usize>(
    data: &[u8],
    field: &PointField,
    offset: usize,
) -> Result<[u8; N], ParseError> {
    let bytes = data
        .get(offset..offset + N)
        .ok_or_else(|| ParseError::DataOutOfBounds {
            field: field.name.clone(),
            offset,
            size: N,
            data_len: data.len(),
        })?;

    Ok(bytes.try_into().unwrap())
}

fn datatype_size(datatype: u8) -> Result<usize, ParseError> {
    match datatype {
        PointField::INT8 => Ok(1),
        PointField::UINT8 => Ok(1),
        PointField::INT16 => Ok(2),
        PointField::UINT16 => Ok(2),
        PointField::INT32 => Ok(4),
        PointField::UINT32 => Ok(4),
        PointField::FLOAT32 => Ok(4),
        PointField::FLOAT64 => Ok(8),
        datatype => Err(ParseError::UnsupportedDatatype(datatype)),
    }
}