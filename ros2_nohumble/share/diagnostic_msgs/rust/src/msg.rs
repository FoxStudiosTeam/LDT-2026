#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to diagnostic_msgs__msg__DiagnosticArray
/// This message is used to send diagnostic information about the state of the robot.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DiagnosticArray {
    /// for timestamp
    pub header: std_msgs::msg::Header,

    /// an array of components being reported on
    pub status: Vec<super::msg::DiagnosticStatus>,

}



impl Default for DiagnosticArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DiagnosticArray::default())
  }
}

impl rosidl_runtime_rs::Message for DiagnosticArray {
  type RmwMsg = super::msg::rmw::DiagnosticArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        status: msg.status
          .into_iter()
          .map(|elem| super::msg::DiagnosticStatus::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        status: msg.status
          .iter()
          .map(|elem| super::msg::DiagnosticStatus::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      status: msg.status
          .into_iter()
          .map(super::msg::DiagnosticStatus::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to diagnostic_msgs__msg__DiagnosticStatus
/// This message holds the status of an individual component of the robot.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DiagnosticStatus {
    /// Level of operation enumerated above.
    pub level: u8,

    /// A description of the test/component reporting.
    pub name: std::string::String,

    /// A description of the status.
    pub message: std::string::String,

    /// A hardware unique string.
    pub hardware_id: std::string::String,

    /// An array of values associated with the status.
    pub values: Vec<super::msg::KeyValue>,

}

impl DiagnosticStatus {
    /// Possible levels of operations.
    pub const OK: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const WARN: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ERROR: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STALE: u8 = 3;

}


impl Default for DiagnosticStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DiagnosticStatus::default())
  }
}

impl rosidl_runtime_rs::Message for DiagnosticStatus {
  type RmwMsg = super::msg::rmw::DiagnosticStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        level: msg.level,
        name: msg.name.as_str().into(),
        message: msg.message.as_str().into(),
        hardware_id: msg.hardware_id.as_str().into(),
        values: msg.values
          .into_iter()
          .map(|elem| super::msg::KeyValue::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      level: msg.level,
        name: msg.name.as_str().into(),
        message: msg.message.as_str().into(),
        hardware_id: msg.hardware_id.as_str().into(),
        values: msg.values
          .iter()
          .map(|elem| super::msg::KeyValue::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      level: msg.level,
      name: msg.name.to_string(),
      message: msg.message.to_string(),
      hardware_id: msg.hardware_id.to_string(),
      values: msg.values
          .into_iter()
          .map(super::msg::KeyValue::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to diagnostic_msgs__msg__KeyValue
/// What to label this value when viewing.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyValue {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: std::string::String,

    /// A value to track over time.
    pub value: std::string::String,

}



impl Default for KeyValue {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::KeyValue::default())
  }
}

impl rosidl_runtime_rs::Message for KeyValue {
  type RmwMsg = super::msg::rmw::KeyValue;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value: msg.value.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value: msg.value.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      key: msg.key.to_string(),
      value: msg.value.to_string(),
    }
  }
}


