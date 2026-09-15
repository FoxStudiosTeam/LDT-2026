#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to tf2_msgs__srv__FrameGraph_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrameGraph_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for FrameGraph_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::FrameGraph_Request::default())
  }
}

impl rosidl_runtime_rs::Message for FrameGraph_Request {
  type RmwMsg = super::srv::rmw::FrameGraph_Request;

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


// Corresponds to tf2_msgs__srv__FrameGraph_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrameGraph_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub frame_yaml: std::string::String,

}



impl Default for FrameGraph_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::FrameGraph_Response::default())
  }
}

impl rosidl_runtime_rs::Message for FrameGraph_Response {
  type RmwMsg = super::srv::rmw::FrameGraph_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        frame_yaml: msg.frame_yaml.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        frame_yaml: msg.frame_yaml.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      frame_yaml: msg.frame_yaml.to_string(),
    }
  }
}






#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__tf2_msgs__srv__FrameGraph() -> *const std::ffi::c_void;
}

// Corresponds to tf2_msgs__srv__FrameGraph
#[allow(missing_docs, non_camel_case_types)]
pub struct FrameGraph;

impl rosidl_runtime_rs::Service for FrameGraph {
    type Request = FrameGraph_Request;
    type Response = FrameGraph_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__tf2_msgs__srv__FrameGraph() }
    }
}


