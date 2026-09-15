#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to tf2_msgs__msg__TF2Error

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TF2Error {

    // This member is not documented.
    #[allow(missing_docs)]
    pub error: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error_string: std::string::String,

}

impl TF2Error {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NO_ERROR: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LOOKUP_ERROR: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONNECTIVITY_ERROR: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const EXTRAPOLATION_ERROR: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INVALID_ARGUMENT_ERROR: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TIMEOUT_ERROR: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSFORM_ERROR: u8 = 6;

}


impl Default for TF2Error {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TF2Error::default())
  }
}

impl rosidl_runtime_rs::Message for TF2Error {
  type RmwMsg = super::msg::rmw::TF2Error;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        error: msg.error,
        error_string: msg.error_string.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      error: msg.error,
        error_string: msg.error_string.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      error: msg.error,
      error_string: msg.error_string.to_string(),
    }
  }
}


// Corresponds to tf2_msgs__msg__TFMessage

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TFMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transforms: Vec<geometry_msgs::msg::TransformStamped>,

}



impl Default for TFMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TFMessage::default())
  }
}

impl rosidl_runtime_rs::Message for TFMessage {
  type RmwMsg = super::msg::rmw::TFMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transforms: msg.transforms
          .into_iter()
          .map(|elem| geometry_msgs::msg::TransformStamped::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transforms: msg.transforms
          .iter()
          .map(|elem| geometry_msgs::msg::TransformStamped::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      transforms: msg.transforms
          .into_iter()
          .map(geometry_msgs::msg::TransformStamped::from_rmw_message)
          .collect(),
    }
  }
}


