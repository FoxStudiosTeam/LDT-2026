#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__BasicSrv_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__srv__BasicSrv_Request__init(msg: *mut BasicSrv_Request) -> bool;
    fn rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicSrv_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicSrv_Request>);
    fn rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicSrv_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicSrv_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__srv__BasicSrv_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicSrv_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub req: rosidl_runtime_rs::String,

}



impl Default for BasicSrv_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__srv__BasicSrv_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__srv__BasicSrv_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicSrv_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicSrv_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicSrv_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/srv/BasicSrv_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__BasicSrv_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__BasicSrv_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__srv__BasicSrv_Response__init(msg: *mut BasicSrv_Response) -> bool;
    fn rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicSrv_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicSrv_Response>);
    fn rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicSrv_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicSrv_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__srv__BasicSrv_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicSrv_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub resp: rosidl_runtime_rs::String,

}



impl Default for BasicSrv_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__srv__BasicSrv_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__srv__BasicSrv_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicSrv_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicSrv_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicSrv_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/srv/BasicSrv_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__BasicSrv_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__init(msg: *mut ComplexSrvMsg_Request) -> bool;
    fn rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvMsg_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvMsg_Request>);
    fn rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexSrvMsg_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvMsg_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexSrvMsg_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub req: super::super::msg::rmw::BasicMsg,

}



impl Default for ComplexSrvMsg_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexSrvMsg_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexSrvMsg_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexSrvMsg_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/srv/ComplexSrvMsg_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__init(msg: *mut ComplexSrvMsg_Response) -> bool;
    fn rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvMsg_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvMsg_Response>);
    fn rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexSrvMsg_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvMsg_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexSrvMsg_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub resp: super::super::msg::rmw::BasicMsg,

}



impl Default for ComplexSrvMsg_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexSrvMsg_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexSrvMsg_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexSrvMsg_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/srv/ComplexSrvMsg_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__init(msg: *mut ComplexSrvIdl_Request) -> bool;
    fn rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvIdl_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvIdl_Request>);
    fn rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexSrvIdl_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvIdl_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexSrvIdl_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub req: super::super::msg::rmw::BasicIdl,

}



impl Default for ComplexSrvIdl_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexSrvIdl_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexSrvIdl_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexSrvIdl_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/srv/ComplexSrvIdl_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__init(msg: *mut ComplexSrvIdl_Response) -> bool;
    fn rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvIdl_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvIdl_Response>);
    fn rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexSrvIdl_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexSrvIdl_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexSrvIdl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub resp: super::super::msg::rmw::BasicIdl,

}



impl Default for ComplexSrvIdl_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexSrvIdl_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexSrvIdl_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexSrvIdl_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/srv/ComplexSrvIdl_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response() }
  }
}






#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__BasicSrv() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__srv__BasicSrv
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicSrv;

impl rosidl_runtime_rs::Service for BasicSrv {
    type Request = BasicSrv_Request;
    type Response = BasicSrv_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__BasicSrv() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvMsg() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvMsg
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexSrvMsg;

impl rosidl_runtime_rs::Service for ComplexSrvMsg {
    type Request = ComplexSrvMsg_Request;
    type Response = ComplexSrvMsg_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvMsg() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvIdl() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__srv__ComplexSrvIdl
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexSrvIdl;

impl rosidl_runtime_rs::Service for ComplexSrvIdl {
    type Request = ComplexSrvIdl_Request;
    type Response = ComplexSrvIdl_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__srv__ComplexSrvIdl() }
    }
}


