use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointField;
use super::parser::{PointValue, ParseError};
pub trait FromPointValue: Sized {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError>;
}

impl FromPointValue for i8 {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError> {
        match value {
            PointValue::I8(value) => Ok(value),
            _ => Err(ParseError::UnexpectedDatatype {
                expected_datatype: PointField::INT8,
                actual_datatype: value.datatype(),
            }),
        }
    }
}

impl FromPointValue for u8 {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError> {
        match value {
            PointValue::U8(value) => Ok(value),
            _ => Err(ParseError::UnexpectedDatatype {
                expected_datatype: PointField::UINT8,
                actual_datatype: value.datatype(),
            }),
        }
    }
}

impl FromPointValue for i16 {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError> {
        match value {
            PointValue::I16(value) => Ok(value),
            _ => Err(ParseError::UnexpectedDatatype {
                expected_datatype: PointField::INT16,
                actual_datatype: value.datatype(),
            }),
        }
    }
}

impl FromPointValue for u16 {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError> {
        match value {
            PointValue::U16(value) => Ok(value),
            _ => Err(ParseError::UnexpectedDatatype {
                expected_datatype: PointField::UINT16,
                actual_datatype: value.datatype(),
            }),
        }
    }
}

impl FromPointValue for i32 {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError> {
        match value {
            PointValue::I32(value) => Ok(value),
            _ => Err(ParseError::UnexpectedDatatype {
                expected_datatype: PointField::INT32,
                actual_datatype: value.datatype(),
            }),
        }
    }
}

impl FromPointValue for u32 {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError> {
        match value {
            PointValue::U32(value) => Ok(value),
            _ => Err(ParseError::UnexpectedDatatype {
                expected_datatype: PointField::UINT32,
                actual_datatype: value.datatype(),
            }),
        }
    }
}

impl FromPointValue for f32 {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError> {
        match value {
            PointValue::F32(value) => Ok(value),
            _ => Err(ParseError::UnexpectedDatatype {
                expected_datatype: PointField::FLOAT32,
                actual_datatype: value.datatype(),
            }),
        }
    }
}

impl FromPointValue for f64 {
    fn from_point_value(value: PointValue) -> Result<Self, ParseError> {
        match value {
            PointValue::F64(value) => Ok(value),
            _ => Err(ParseError::UnexpectedDatatype {
                expected_datatype: PointField::FLOAT64,
                actual_datatype: value.datatype(),
            }),
        }
    }
}