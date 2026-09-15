#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to logging_demo__srv__ConfigLogger_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ConfigLogger_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub logger_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub level: std::string::String,

}



impl Default for ConfigLogger_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ConfigLogger_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ConfigLogger_Request {
  type RmwMsg = super::srv::rmw::ConfigLogger_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        logger_name: msg.logger_name.as_str().into(),
        level: msg.level.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        logger_name: msg.logger_name.as_str().into(),
        level: msg.level.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      logger_name: msg.logger_name.to_string(),
      level: msg.level.to_string(),
    }
  }
}


// Corresponds to logging_demo__srv__ConfigLogger_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ConfigLogger_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for ConfigLogger_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ConfigLogger_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ConfigLogger_Response {
  type RmwMsg = super::srv::rmw::ConfigLogger_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}






#[link(name = "logging_demo__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__logging_demo__srv__ConfigLogger() -> *const std::ffi::c_void;
}

// Corresponds to logging_demo__srv__ConfigLogger
#[allow(missing_docs, non_camel_case_types)]
pub struct ConfigLogger;

impl rosidl_runtime_rs::Service for ConfigLogger {
    type Request = ConfigLogger_Request;
    type Response = ConfigLogger_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__logging_demo__srv__ConfigLogger() }
    }
}


