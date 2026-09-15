#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to type_description_interfaces__srv__GetTypeDescription_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetTypeDescription_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub type_name: std::string::String,

    /// REP-2011 RIHS hash string.
    pub type_hash: std::string::String,

    /// Whether to return the original idl/msg/etc. source file(s) in the response.
    pub include_type_sources: bool,

}



impl Default for GetTypeDescription_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetTypeDescription_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetTypeDescription_Request {
  type RmwMsg = super::srv::rmw::GetTypeDescription_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_name: msg.type_name.as_str().into(),
        type_hash: msg.type_hash.as_str().into(),
        include_type_sources: msg.include_type_sources,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_name: msg.type_name.as_str().into(),
        type_hash: msg.type_hash.as_str().into(),
      include_type_sources: msg.include_type_sources,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_name: msg.type_name.to_string(),
      type_hash: msg.type_hash.to_string(),
      include_type_sources: msg.include_type_sources,
    }
  }
}


// Corresponds to type_description_interfaces__srv__GetTypeDescription_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetTypeDescription_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successful: bool,

    /// If `successful` is false, contains a reason for failure.
    /// If `successful` is true, this is left empty.
    pub failure_reason: std::string::String,

    /// The parsed type description which can be used programmatically.
    pub type_description: super::msg::TypeDescription,

    /// A list containing the interface definition source text of the requested type,
    /// plus all types it recursively depends on.
    /// Each source text is a copy of the original contents of the
    /// .msg, .srv, .action, .idl, or other file if it exists, including comments and whitespace.
    /// Sources can be matched with IndividualTypeDescriptions by their `type_name`.
    /// The `encoding` field of each entry informs how to interpret its contents.
    pub type_sources: Vec<super::msg::TypeSource>,

    /// Key-value pairs of extra information.
    pub extra_information: Vec<super::msg::KeyValue>,

}



impl Default for GetTypeDescription_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetTypeDescription_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetTypeDescription_Response {
  type RmwMsg = super::srv::rmw::GetTypeDescription_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successful: msg.successful,
        failure_reason: msg.failure_reason.as_str().into(),
        type_description: super::msg::TypeDescription::into_rmw_message(std::borrow::Cow::Owned(msg.type_description)).into_owned(),
        type_sources: msg.type_sources
          .into_iter()
          .map(|elem| super::msg::TypeSource::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        extra_information: msg.extra_information
          .into_iter()
          .map(|elem| super::msg::KeyValue::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successful: msg.successful,
        failure_reason: msg.failure_reason.as_str().into(),
        type_description: super::msg::TypeDescription::into_rmw_message(std::borrow::Cow::Borrowed(&msg.type_description)).into_owned(),
        type_sources: msg.type_sources
          .iter()
          .map(|elem| super::msg::TypeSource::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        extra_information: msg.extra_information
          .iter()
          .map(|elem| super::msg::KeyValue::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successful: msg.successful,
      failure_reason: msg.failure_reason.to_string(),
      type_description: super::msg::TypeDescription::from_rmw_message(msg.type_description),
      type_sources: msg.type_sources
          .into_iter()
          .map(super::msg::TypeSource::from_rmw_message)
          .collect(),
      extra_information: msg.extra_information
          .into_iter()
          .map(super::msg::KeyValue::from_rmw_message)
          .collect(),
    }
  }
}






#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__type_description_interfaces__srv__GetTypeDescription() -> *const std::ffi::c_void;
}

// Corresponds to type_description_interfaces__srv__GetTypeDescription
#[allow(missing_docs, non_camel_case_types)]
pub struct GetTypeDescription;

impl rosidl_runtime_rs::Service for GetTypeDescription {
    type Request = GetTypeDescription_Request;
    type Response = GetTypeDescription_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__type_description_interfaces__srv__GetTypeDescription() }
    }
}


