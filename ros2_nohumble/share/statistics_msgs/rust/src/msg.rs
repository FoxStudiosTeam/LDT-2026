#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to statistics_msgs__msg__MetricsMessage
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

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MetricsMessage {
    /// Name metric measurement source, e.g., node, topic, or process name
    pub measurement_source_name: std::string::String,

    /// Name of the metric being measured, e.g. cpu_percentage, free_memory_mb, message_age, etc.
    pub metrics_source: std::string::String,

    /// Unit of measure of the metric, e.g. percent, mb, seconds, etc.
    pub unit: std::string::String,

    /// Measurement window start time
    pub window_start: builtin_interfaces::msg::Time,

    /// Measurement window end time
    pub window_stop: builtin_interfaces::msg::Time,

    /// A list of statistics data point, defined in StatisticDataPoint.msg
    pub statistics: Vec<super::msg::StatisticDataPoint>,

}



impl Default for MetricsMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MetricsMessage::default())
  }
}

impl rosidl_runtime_rs::Message for MetricsMessage {
  type RmwMsg = super::msg::rmw::MetricsMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        measurement_source_name: msg.measurement_source_name.as_str().into(),
        metrics_source: msg.metrics_source.as_str().into(),
        unit: msg.unit.as_str().into(),
        window_start: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.window_start)).into_owned(),
        window_stop: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.window_stop)).into_owned(),
        statistics: msg.statistics
          .into_iter()
          .map(|elem| super::msg::StatisticDataPoint::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        measurement_source_name: msg.measurement_source_name.as_str().into(),
        metrics_source: msg.metrics_source.as_str().into(),
        unit: msg.unit.as_str().into(),
        window_start: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.window_start)).into_owned(),
        window_stop: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.window_stop)).into_owned(),
        statistics: msg.statistics
          .iter()
          .map(|elem| super::msg::StatisticDataPoint::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      measurement_source_name: msg.measurement_source_name.to_string(),
      metrics_source: msg.metrics_source.to_string(),
      unit: msg.unit.to_string(),
      window_start: builtin_interfaces::msg::Time::from_rmw_message(msg.window_start),
      window_stop: builtin_interfaces::msg::Time::from_rmw_message(msg.window_stop),
      statistics: msg.statistics
          .into_iter()
          .map(super::msg::StatisticDataPoint::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to statistics_msgs__msg__StatisticDataPoint
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

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::StatisticDataPoint::default())
  }
}

impl rosidl_runtime_rs::Message for StatisticDataPoint {
  type RmwMsg = super::msg::rmw::StatisticDataPoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        data_type: msg.data_type,
        data: msg.data,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      data_type: msg.data_type,
      data: msg.data,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      data_type: msg.data_type,
      data: msg.data,
    }
  }
}


// Corresponds to statistics_msgs__msg__StatisticDataType
/// This file contains the commonly used constants for the statistics data type.
///
/// The value 0 is reserved for unitialized statistic message data type.
/// Range of values: [0, 255].
/// Unallowed values: any value that is not specified in this file.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::StatisticDataType::default())
  }
}

impl rosidl_runtime_rs::Message for StatisticDataType {
  type RmwMsg = super::msg::rmw::StatisticDataType;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


