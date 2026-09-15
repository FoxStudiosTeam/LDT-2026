#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "statistics_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__statistics_msgs__msg__MetricsMessage() -> *const std::ffi::c_void;
}

#[link(name = "statistics_msgs__rosidl_generator_c")]
extern "C" {
    fn statistics_msgs__msg__MetricsMessage__init(msg: *mut MetricsMessage) -> bool;
    fn statistics_msgs__msg__MetricsMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MetricsMessage>, size: usize) -> bool;
    fn statistics_msgs__msg__MetricsMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MetricsMessage>);
    fn statistics_msgs__msg__MetricsMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MetricsMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<MetricsMessage>) -> bool;
}

// Corresponds to statistics_msgs__msg__MetricsMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// A generic metrics message providing statistics for measurements from different sources. For example,
/// measure a system's CPU % for a given window yields the following data points over a window of time:
///
///   - average cpu %
///   - std deviation
///   - min
///   - max
///   - sample count
///
/// These are all represented as different 'StatisticDataPoint's.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MetricsMessage {
    /// Name metric measurement source, e.g., node, topic, or process name
    pub measurement_source_name: rosidl_runtime_rs::String,

    /// Name of the metric being measured, e.g. cpu_percentage, free_memory_mb, message_age, etc.
    pub metrics_source: rosidl_runtime_rs::String,

    /// Unit of measure of the metric, e.g. percent, mb, seconds, etc.
    pub unit: rosidl_runtime_rs::String,

    /// Measurement window start time
    pub window_start: builtin_interfaces::msg::rmw::Time,

    /// Measurement window end time
    pub window_stop: builtin_interfaces::msg::rmw::Time,

    /// A list of statistics data point, defined in StatisticDataPoint.msg
    pub statistics: rosidl_runtime_rs::Sequence<super::super::msg::rmw::StatisticDataPoint>,

}



impl Default for MetricsMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !statistics_msgs__msg__MetricsMessage__init(&mut msg as *mut _) {
        panic!("Call to statistics_msgs__msg__MetricsMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MetricsMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__MetricsMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__MetricsMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__MetricsMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MetricsMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MetricsMessage where Self: Sized {
  const TYPE_NAME: &'static str = "statistics_msgs/msg/MetricsMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__statistics_msgs__msg__MetricsMessage() }
  }
}


#[link(name = "statistics_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__statistics_msgs__msg__StatisticDataPoint() -> *const std::ffi::c_void;
}

#[link(name = "statistics_msgs__rosidl_generator_c")]
extern "C" {
    fn statistics_msgs__msg__StatisticDataPoint__init(msg: *mut StatisticDataPoint) -> bool;
    fn statistics_msgs__msg__StatisticDataPoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StatisticDataPoint>, size: usize) -> bool;
    fn statistics_msgs__msg__StatisticDataPoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StatisticDataPoint>);
    fn statistics_msgs__msg__StatisticDataPoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StatisticDataPoint>, out_seq: *mut rosidl_runtime_rs::Sequence<StatisticDataPoint>) -> bool;
}

// Corresponds to statistics_msgs__msg__StatisticDataPoint
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This holds the structure of a single data point of a StatisticDataType.
///
/// This message is used in MetricsStatisticsMessage, defined in MetricsStatisticsMessage.msg.
///
/// Examples of the value of data point are
/// - average size of messages received
/// - standard deviation of the period of messages published
/// - maximum age of messages published
///
/// A value of nan represents no data is available.
/// One example is that standard deviation is only available when there are two or more data points but there is only one,
/// and in this case the value would be nan.
/// +inf and -inf are not allowed.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StatisticDataPoint {
    /// The statistic type of this data point, defined in StatisticDataType.msg
    /// Default value should be StatisticDataType.STATISTICS_DATA_TYPE_UNINITIALIZED (0).
    pub data_type: u8,

    /// The value of the data point
    pub data: f64,

}



impl Default for StatisticDataPoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !statistics_msgs__msg__StatisticDataPoint__init(&mut msg as *mut _) {
        panic!("Call to statistics_msgs__msg__StatisticDataPoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StatisticDataPoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__StatisticDataPoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__StatisticDataPoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__StatisticDataPoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StatisticDataPoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StatisticDataPoint where Self: Sized {
  const TYPE_NAME: &'static str = "statistics_msgs/msg/StatisticDataPoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__statistics_msgs__msg__StatisticDataPoint() }
  }
}


#[link(name = "statistics_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__statistics_msgs__msg__StatisticDataType() -> *const std::ffi::c_void;
}

#[link(name = "statistics_msgs__rosidl_generator_c")]
extern "C" {
    fn statistics_msgs__msg__StatisticDataType__init(msg: *mut StatisticDataType) -> bool;
    fn statistics_msgs__msg__StatisticDataType__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StatisticDataType>, size: usize) -> bool;
    fn statistics_msgs__msg__StatisticDataType__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StatisticDataType>);
    fn statistics_msgs__msg__StatisticDataType__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StatisticDataType>, out_seq: *mut rosidl_runtime_rs::Sequence<StatisticDataType>) -> bool;
}

// Corresponds to statistics_msgs__msg__StatisticDataType
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This file contains the commonly used constants for the statistics data type.
///
/// The value 0 is reserved for unitialized statistic message data type.
/// Range of values: [0, 255].
/// Unallowed values: any value that is not specified in this file.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StatisticDataType {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}

impl StatisticDataType {
    /// Constant for uninitialized
    pub const STATISTICS_DATA_TYPE_UNINITIALIZED: u8 = 0;

    /// Allowed values
    pub const STATISTICS_DATA_TYPE_AVERAGE: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATISTICS_DATA_TYPE_MINIMUM: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATISTICS_DATA_TYPE_MAXIMUM: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATISTICS_DATA_TYPE_STDDEV: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATISTICS_DATA_TYPE_SAMPLE_COUNT: u8 = 5;

}


impl Default for StatisticDataType {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !statistics_msgs__msg__StatisticDataType__init(&mut msg as *mut _) {
        panic!("Call to statistics_msgs__msg__StatisticDataType__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StatisticDataType {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__StatisticDataType__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__StatisticDataType__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { statistics_msgs__msg__StatisticDataType__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StatisticDataType {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StatisticDataType where Self: Sized {
  const TYPE_NAME: &'static str = "statistics_msgs/msg/StatisticDataType";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__statistics_msgs__msg__StatisticDataType() }
  }
}


