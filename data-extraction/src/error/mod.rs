use std::fmt;

#[derive(Debug)]
pub enum Error {
    InvalidName(&'static str),
    NodeCreation(ros2_client::NodeCreateError),
    NoneError(&'static str),
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
    },
    SizeOverflow,
    ParseFailed {
        err: ros2_client::ros2::ReadError,
    },
    DiscoveryChannelClosed,
    InvalidChannelSize,
    LockError,
    AbstractError {
        msg: String,
    },
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::CreateError(error, msg) => {
                write!(f, "{msg}: {error}")
            }
            Self::InvalidName(msg) => {
                write!(f, "{msg}")
            }
            Self::NodeCreation(err) => {
                write!(f, "failed to create node: {err}")
            }
            Self::NoneError(msg) => {
                write!(f, "{msg}")
            }

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

            Self::MissingField { field_name } => {
                write!(f, "Missing field '{field_name}'")
            }

            Self::UnexpectedDatatype {
                expected_datatype,
                actual_datatype,
            } => {
                write!(
                    f,
                    "Unexpected data type:\
                 expected={expected_datatype}, actual={actual_datatype}"
                )
            }

            Self::SizeOverflow => {
                write!(f, "Size overflow detected")
            }

            Self::ParseFailed { err } => {
                write!(f, "Parse failed: {err}")
            }

            Self::DiscoveryChannelClosed => {
                write!(f, "Discovery channel closed")
            }

            Self::InvalidChannelSize => {
                write!(f, "Invalid channel size")
            }

            Self::LockError => {
                write!(f, "Lock error")
            }
            Self::AbstractError { msg } => {
                write!(f, "AbstractError: {msg}")
            }
        }
    }
}

impl std::error::Error for Error {}
