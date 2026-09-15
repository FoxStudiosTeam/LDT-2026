#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "resource_retriever_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__resource_retriever_interfaces__srv__GetResource_Request() -> *const std::ffi::c_void;
}

#[link(name = "resource_retriever_interfaces__rosidl_generator_c")]
extern "C" {
    fn resource_retriever_interfaces__srv__GetResource_Request__init(msg: *mut GetResource_Request) -> bool;
    fn resource_retriever_interfaces__srv__GetResource_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetResource_Request>, size: usize) -> bool;
    fn resource_retriever_interfaces__srv__GetResource_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetResource_Request>);
    fn resource_retriever_interfaces__srv__GetResource_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetResource_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetResource_Request>) -> bool;
}

// Corresponds to resource_retriever_interfaces__srv__GetResource_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetResource_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub path: rosidl_runtime_rs::String,

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
    pub etag: rosidl_runtime_rs::String,

}



impl Default for GetResource_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !resource_retriever_interfaces__srv__GetResource_Request__init(&mut msg as *mut _) {
        panic!("Call to resource_retriever_interfaces__srv__GetResource_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetResource_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { resource_retriever_interfaces__srv__GetResource_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { resource_retriever_interfaces__srv__GetResource_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { resource_retriever_interfaces__srv__GetResource_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetResource_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetResource_Request where Self: Sized {
  const TYPE_NAME: &'static str = "resource_retriever_interfaces/srv/GetResource_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__resource_retriever_interfaces__srv__GetResource_Request() }
  }
}


#[link(name = "resource_retriever_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__resource_retriever_interfaces__srv__GetResource_Response() -> *const std::ffi::c_void;
}

#[link(name = "resource_retriever_interfaces__rosidl_generator_c")]
extern "C" {
    fn resource_retriever_interfaces__srv__GetResource_Response__init(msg: *mut GetResource_Response) -> bool;
    fn resource_retriever_interfaces__srv__GetResource_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetResource_Response>, size: usize) -> bool;
    fn resource_retriever_interfaces__srv__GetResource_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetResource_Response>);
    fn resource_retriever_interfaces__srv__GetResource_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetResource_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetResource_Response>) -> bool;
}

// Corresponds to resource_retriever_interfaces__srv__GetResource_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetResource_Response {
    /// Status code for the request, can be one of the above options.
    pub status_code: i32,

    /// Optionally set error reason string.
    pub error_reason: rosidl_runtime_rs::String,

    /// Expanded path, which may or may not be different from the given path.
    /// The Service may expand, extend, or otherwise further qualify the path as it
    /// resolves it, any of which would be reflected in this expanded path.
    pub expanded_path: rosidl_runtime_rs::String,

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
    pub etag: rosidl_runtime_rs::String,

    /// Opaque value of the resource.
    pub body: rosidl_runtime_rs::Sequence<u8>,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !resource_retriever_interfaces__srv__GetResource_Response__init(&mut msg as *mut _) {
        panic!("Call to resource_retriever_interfaces__srv__GetResource_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetResource_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { resource_retriever_interfaces__srv__GetResource_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { resource_retriever_interfaces__srv__GetResource_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { resource_retriever_interfaces__srv__GetResource_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetResource_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetResource_Response where Self: Sized {
  const TYPE_NAME: &'static str = "resource_retriever_interfaces/srv/GetResource_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__resource_retriever_interfaces__srv__GetResource_Response() }
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


