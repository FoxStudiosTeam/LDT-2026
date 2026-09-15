#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "logging_demo__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__logging_demo__srv__ConfigLogger_Request() -> *const std::ffi::c_void;
}

#[link(name = "logging_demo__rosidl_generator_c")]
extern "C" {
    fn logging_demo__srv__ConfigLogger_Request__init(msg: *mut ConfigLogger_Request) -> bool;
    fn logging_demo__srv__ConfigLogger_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ConfigLogger_Request>, size: usize) -> bool;
    fn logging_demo__srv__ConfigLogger_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ConfigLogger_Request>);
    fn logging_demo__srv__ConfigLogger_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ConfigLogger_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ConfigLogger_Request>) -> bool;
}

// Corresponds to logging_demo__srv__ConfigLogger_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ConfigLogger_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub logger_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub level: rosidl_runtime_rs::String,

}



impl Default for ConfigLogger_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !logging_demo__srv__ConfigLogger_Request__init(&mut msg as *mut _) {
        panic!("Call to logging_demo__srv__ConfigLogger_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ConfigLogger_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { logging_demo__srv__ConfigLogger_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { logging_demo__srv__ConfigLogger_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { logging_demo__srv__ConfigLogger_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ConfigLogger_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ConfigLogger_Request where Self: Sized {
  const TYPE_NAME: &'static str = "logging_demo/srv/ConfigLogger_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__logging_demo__srv__ConfigLogger_Request() }
  }
}


#[link(name = "logging_demo__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__logging_demo__srv__ConfigLogger_Response() -> *const std::ffi::c_void;
}

#[link(name = "logging_demo__rosidl_generator_c")]
extern "C" {
    fn logging_demo__srv__ConfigLogger_Response__init(msg: *mut ConfigLogger_Response) -> bool;
    fn logging_demo__srv__ConfigLogger_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ConfigLogger_Response>, size: usize) -> bool;
    fn logging_demo__srv__ConfigLogger_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ConfigLogger_Response>);
    fn logging_demo__srv__ConfigLogger_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ConfigLogger_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ConfigLogger_Response>) -> bool;
}

// Corresponds to logging_demo__srv__ConfigLogger_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ConfigLogger_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for ConfigLogger_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !logging_demo__srv__ConfigLogger_Response__init(&mut msg as *mut _) {
        panic!("Call to logging_demo__srv__ConfigLogger_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ConfigLogger_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { logging_demo__srv__ConfigLogger_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { logging_demo__srv__ConfigLogger_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { logging_demo__srv__ConfigLogger_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ConfigLogger_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ConfigLogger_Response where Self: Sized {
  const TYPE_NAME: &'static str = "logging_demo/srv/ConfigLogger_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__logging_demo__srv__ConfigLogger_Response() }
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


