#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to visualization_msgs__srv__GetInteractiveMarkers_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetInteractiveMarkers_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetInteractiveMarkers_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetInteractiveMarkers_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetInteractiveMarkers_Request {
  type RmwMsg = super::srv::rmw::GetInteractiveMarkers_Request;

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


// Corresponds to visualization_msgs__srv__GetInteractiveMarkers_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetInteractiveMarkers_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence_number: u64,

    /// All interactive markers provided by the server.
    pub markers: Vec<super::msg::InteractiveMarker>,

}



impl Default for GetInteractiveMarkers_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetInteractiveMarkers_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetInteractiveMarkers_Response {
  type RmwMsg = super::srv::rmw::GetInteractiveMarkers_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sequence_number: msg.sequence_number,
        markers: msg.markers
          .into_iter()
          .map(|elem| super::msg::InteractiveMarker::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      sequence_number: msg.sequence_number,
        markers: msg.markers
          .iter()
          .map(|elem| super::msg::InteractiveMarker::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sequence_number: msg.sequence_number,
      markers: msg.markers
          .into_iter()
          .map(super::msg::InteractiveMarker::from_rmw_message)
          .collect(),
    }
  }
}






#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__visualization_msgs__srv__GetInteractiveMarkers() -> *const std::ffi::c_void;
}

// Corresponds to visualization_msgs__srv__GetInteractiveMarkers
#[allow(missing_docs, non_camel_case_types)]
pub struct GetInteractiveMarkers;

impl rosidl_runtime_rs::Service for GetInteractiveMarkers {
    type Request = GetInteractiveMarkers_Request;
    type Response = GetInteractiveMarkers_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__visualization_msgs__srv__GetInteractiveMarkers() }
    }
}


