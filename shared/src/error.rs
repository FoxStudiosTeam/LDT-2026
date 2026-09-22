use std::fmt;
use std::panic::Location;
use thiserror::Error;

#[derive(Error, Debug)]
pub enum ErrorType {
    #[error("Ros2 create error: {0}")]
    CreateError(#[from] ros2_client::ros2::CreateError),
    #[error("{0}")]
    InvalidName(&'static str),
    #[error("{0}")]
    NoneError(&'static str),
    #[error("Rerun connection timed out")]
    RerunConnectionTimeout,
    #[error("Unsupported PointField datatype: {0}")]
    UnsupportedDatatype(u8),
    #[error("Unexpected data type: expected={expected_datatype}, actual={actual_datatype}")]
    UnexpectedDatatype {
        expected_datatype: u8,
        actual_datatype: u8,
    },
    #[error("Invalid count for field '{field}': expected {expected}, got {actual}")]
    InvalidFieldCount {
        field: String,
        expected: u32,
        actual: u32,
    },
    #[error("Invalid row_step: row_step={row_step}, width={width}, point_step={point_step}")]
    InvalidRowStep {
        row_step: usize,
        width: usize,
        point_step: usize,
    },
    #[error(
        "Field '{field}' does not fit into point_step: point_step={point_step}, required_end={required_end}"
    )]
    InvalidPointStep {
        point_step: usize,
        field: String,
        required_end: usize,
    },
    #[error("Message Error {0}")]
    MessageError(String),
    #[error("{0}")]
    ExternalError(Box<dyn std::error::Error + Send + Sync>),
    #[error("Cuda error {0}")]
    CudaError(i32),
}

impl ErrorType {
    pub fn message<T: ToString>(msg: T) -> Self {
        Self::MessageError(msg.to_string())
    }
}

pub struct AppError {
    pub kind: ErrorType,
    pub location: &'static Location<'static>,
}

impl fmt::Display for AppError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "{} ({}:{})",
            self.kind,
            self.location.file(),
            self.location.line()
        )
    }
}

impl fmt::Debug for AppError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "{:?} ({}:{})",
            self.kind,
            self.location.file(),
            self.location.line()
        )
    }
}

impl std::error::Error for AppError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        Some(&self.kind)
    }
}

impl<E> From<E> for AppError
where
    ErrorType: From<E>,
{
    #[track_caller]
    fn from(e: E) -> Self {
        AppError {
            kind: ErrorType::from(e),
            location: Location::caller(),
        }
    }
}

pub trait ErrCtx<T> {
    fn app_error(self) -> Result<T, AppError>;
}

impl<T, E> ErrCtx<T> for Result<T, E>
where
    E: std::error::Error + Send + Sync + 'static,
{
    #[track_caller]
    fn app_error(self) -> Result<T, AppError> {
        let location = Location::caller();
        self.map_err(|e| AppError {
            kind: ErrorType::ExternalError(Box::new(e)),
            location,
        })
    }
}

impl ErrorType {
    /// 🤘
    #[track_caller]
    pub fn err<T>(self) -> Result<T, AppError> {
        Err(AppError {
            kind: self,
            location: Location::caller(),
        })
    }
}
