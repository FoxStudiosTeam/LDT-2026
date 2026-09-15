#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Request {
    /// Comment - Nesting Level 3: 1 of 2
    pub short_varied_nested: super::msg::ShortVariedNested,

}



impl Default for ShortVariedMultiNested_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ShortVariedMultiNested_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Request {
  type RmwMsg = super::srv::rmw::ShortVariedMultiNested_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        short_varied_nested: super::msg::ShortVariedNested::into_rmw_message(std::borrow::Cow::Owned(msg.short_varied_nested)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        short_varied_nested: super::msg::ShortVariedNested::into_rmw_message(std::borrow::Cow::Borrowed(&msg.short_varied_nested)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      short_varied_nested: super::msg::ShortVariedNested::from_rmw_message(msg.short_varied_nested),
    }
  }
}


// Corresponds to ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Response {
    /// Comment - Nesting Level 3: 2 of 2
    pub bool_value: bool,

}



impl Default for ShortVariedMultiNested_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ShortVariedMultiNested_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Response {
  type RmwMsg = super::srv::rmw::ShortVariedMultiNested_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_value: msg.bool_value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      bool_value: msg.bool_value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_value: msg.bool_value,
    }
  }
}






#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__srv__ShortVariedMultiNested() -> *const std::ffi::c_void;
}

// Corresponds to ros2cli_test_interfaces__srv__ShortVariedMultiNested
#[allow(missing_docs, non_camel_case_types)]
pub struct ShortVariedMultiNested;

impl rosidl_runtime_rs::Service for ShortVariedMultiNested {
    type Request = ShortVariedMultiNested_Request;
    type Response = ShortVariedMultiNested_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__srv__ShortVariedMultiNested() }
    }
}


