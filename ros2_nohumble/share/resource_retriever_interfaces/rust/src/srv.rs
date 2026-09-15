#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to resource_retriever_interfaces__srv__GetResource_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetResource_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub path: std::string::String,

    /// HTTP-style ETag value for the requested resource.
    /// See: https://en.wikipedia.org/wiki/HTTP_ETag
    ///
    /// If this value is empty, then the server shall respond with the current
    /// version of the resource and the ETag value, if it can be loaded.
    /// If this value is not-empty, then the server may respond with a new resource
    /// and ETag value.
    /// However, if the ETag value for the resource has not changed, then the server
    /// may respond with NOT_MODIFIED as the status_code, similar to
    /// "HTTP 304: Not Modified".
    /// See: https://en.wikipedia.org/wiki/List_of_HTTP_status_codes#304
    /// The server may also ignore this value and always send the current version
    /// of the resource and its ETag value, if caching is not implemented.
    pub etag: std::string::String,

}



impl Default for GetResource_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetResource_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetResource_Request {
  type RmwMsg = super::srv::rmw::GetResource_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        path: msg.path.as_str().into(),
        etag: msg.etag.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        path: msg.path.as_str().into(),
        etag: msg.etag.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      path: msg.path.to_string(),
      etag: msg.etag.to_string(),
    }
  }
}


// Corresponds to resource_retriever_interfaces__srv__GetResource_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetResource_Response {
    /// Status code for the request, can be one of the above options.
    pub status_code: i32,

    /// Optionally set error reason string.
    pub error_reason: std::string::String,

    /// Expanded path, which may or may not be different from the given path.
    /// The Service may expand, extend, or otherwise further qualify the path as it
    /// resolves it, any of which would be reflected in this expanded path.
    pub expanded_path: std::string::String,

    /// HTTP-style ETag value for the requested resource.
    /// See: https://en.wikipedia.org/wiki/HTTP_ETag
    ///
    /// As with the HTTP ETag, the value is unspecified, but it is described as:
    ///
    /// > Common methods of ETag generation include using a collision-resistant hash
    /// > function of the resource's content, a hash of the last modification
    /// > timestamp, or even just a revision number.
    ///
    /// This value may be empty if the server does not implement cache checking.
    ///
    /// This can be sent on subsequent requests to avoid getting the same unchanged
    /// resource multiple times.
    pub etag: std::string::String,

    /// Opaque value of the resource.
    pub body: Vec<u8>,

}

impl GetResource_Response {
    /// An unspecified error occurred, check the error_reason string.
    pub const ERROR: i32 = 0;

    /// The request was successful, etag and body will be set with valid values,
    /// though etag may be empty.
    /// The error_reason will be empty.
    pub const OK: i32 = 1;

    /// The request was successful, but the etag value has not changed.
    /// The etag value will be set to the requested etag value, but the body value
    /// will be empty.
    /// The error_reason should also be empty.
    pub const NOT_MODIFIED: i32 = 2;

}


impl Default for GetResource_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetResource_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetResource_Response {
  type RmwMsg = super::srv::rmw::GetResource_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status_code: msg.status_code,
        error_reason: msg.error_reason.as_str().into(),
        expanded_path: msg.expanded_path.as_str().into(),
        etag: msg.etag.as_str().into(),
        body: msg.body.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status_code: msg.status_code,
        error_reason: msg.error_reason.as_str().into(),
        expanded_path: msg.expanded_path.as_str().into(),
        etag: msg.etag.as_str().into(),
        body: msg.body.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status_code: msg.status_code,
      error_reason: msg.error_reason.to_string(),
      expanded_path: msg.expanded_path.to_string(),
      etag: msg.etag.to_string(),
      body: msg.body.into(),
    }
  }
}






#[link(name = "resource_retriever_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__resource_retriever_interfaces__srv__GetResource() -> *const std::ffi::c_void;
}

// Corresponds to resource_retriever_interfaces__srv__GetResource
#[allow(missing_docs, non_camel_case_types)]
pub struct GetResource;

impl rosidl_runtime_rs::Service for GetResource {
    type Request = GetResource_Request;
    type Response = GetResource_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__resource_retriever_interfaces__srv__GetResource() }
    }
}


