#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__srv__GetTypeDescription_Request() -> *const std::ffi::c_void;
}

#[link(name = "type_description_interfaces__rosidl_generator_c")]
extern "C" {
    fn type_description_interfaces__srv__GetTypeDescription_Request__init(msg: *mut GetTypeDescription_Request) -> bool;
    fn type_description_interfaces__srv__GetTypeDescription_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetTypeDescription_Request>, size: usize) -> bool;
    fn type_description_interfaces__srv__GetTypeDescription_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetTypeDescription_Request>);
    fn type_description_interfaces__srv__GetTypeDescription_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetTypeDescription_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetTypeDescription_Request>) -> bool;
}

// Corresponds to type_description_interfaces__srv__GetTypeDescription_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetTypeDescription_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub type_name: rosidl_runtime_rs::String,

    /// REP-2011 RIHS hash string.
    pub type_hash: rosidl_runtime_rs::String,

    /// Whether to return the original idl/msg/etc. source file(s) in the response.
    pub include_type_sources: bool,

}



impl Default for GetTypeDescription_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !type_description_interfaces__srv__GetTypeDescription_Request__init(&mut msg as *mut _) {
        panic!("Call to type_description_interfaces__srv__GetTypeDescription_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetTypeDescription_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__srv__GetTypeDescription_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__srv__GetTypeDescription_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__srv__GetTypeDescription_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetTypeDescription_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetTypeDescription_Request where Self: Sized {
  const TYPE_NAME: &'static str = "type_description_interfaces/srv/GetTypeDescription_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__srv__GetTypeDescription_Request() }
  }
}


#[link(name = "type_description_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__srv__GetTypeDescription_Response() -> *const std::ffi::c_void;
}

#[link(name = "type_description_interfaces__rosidl_generator_c")]
extern "C" {
    fn type_description_interfaces__srv__GetTypeDescription_Response__init(msg: *mut GetTypeDescription_Response) -> bool;
    fn type_description_interfaces__srv__GetTypeDescription_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetTypeDescription_Response>, size: usize) -> bool;
    fn type_description_interfaces__srv__GetTypeDescription_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetTypeDescription_Response>);
    fn type_description_interfaces__srv__GetTypeDescription_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetTypeDescription_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetTypeDescription_Response>) -> bool;
}

// Corresponds to type_description_interfaces__srv__GetTypeDescription_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetTypeDescription_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successful: bool,

    /// If `successful` is false, contains a reason for failure.
    /// If `successful` is true, this is left empty.
    pub failure_reason: rosidl_runtime_rs::String,

    /// The parsed type description which can be used programmatically.
    pub type_description: super::super::msg::rmw::TypeDescription,

    /// A list containing the interface definition source text of the requested type,
    /// plus all types it recursively depends on.
    /// Each source text is a copy of the original contents of the
    /// .msg, .srv, .action, .idl, or other file if it exists, including comments and whitespace.
    /// Sources can be matched with IndividualTypeDescriptions by their `type_name`.
    /// The `encoding` field of each entry informs how to interpret its contents.
    pub type_sources: rosidl_runtime_rs::Sequence<super::super::msg::rmw::TypeSource>,

    /// Key-value pairs of extra information.
    pub extra_information: rosidl_runtime_rs::Sequence<super::super::msg::rmw::KeyValue>,

}



impl Default for GetTypeDescription_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !type_description_interfaces__srv__GetTypeDescription_Response__init(&mut msg as *mut _) {
        panic!("Call to type_description_interfaces__srv__GetTypeDescription_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetTypeDescription_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__srv__GetTypeDescription_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__srv__GetTypeDescription_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { type_description_interfaces__srv__GetTypeDescription_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetTypeDescription_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetTypeDescription_Response where Self: Sized {
  const TYPE_NAME: &'static str = "type_description_interfaces/srv/GetTypeDescription_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__type_description_interfaces__srv__GetTypeDescription_Response() }
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


