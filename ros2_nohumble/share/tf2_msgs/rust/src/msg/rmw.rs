#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tf2_msgs__msg__TF2Error() -> *const std::ffi::c_void;
}

#[link(name = "tf2_msgs__rosidl_generator_c")]
extern "C" {
    fn tf2_msgs__msg__TF2Error__init(msg: *mut TF2Error) -> bool;
    fn tf2_msgs__msg__TF2Error__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TF2Error>, size: usize) -> bool;
    fn tf2_msgs__msg__TF2Error__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TF2Error>);
    fn tf2_msgs__msg__TF2Error__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TF2Error>, out_seq: *mut rosidl_runtime_rs::Sequence<TF2Error>) -> bool;
}

// Corresponds to tf2_msgs__msg__TF2Error
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TF2Error {

    // This member is not documented.
    #[allow(missing_docs)]
    pub error: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error_string: rosidl_runtime_rs::String,

}

impl TF2Error {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NO_ERROR: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LOOKUP_ERROR: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONNECTIVITY_ERROR: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const EXTRAPOLATION_ERROR: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INVALID_ARGUMENT_ERROR: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TIMEOUT_ERROR: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSFORM_ERROR: u8 = 6;

}


impl Default for TF2Error {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tf2_msgs__msg__TF2Error__init(&mut msg as *mut _) {
        panic!("Call to tf2_msgs__msg__TF2Error__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TF2Error {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__msg__TF2Error__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__msg__TF2Error__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__msg__TF2Error__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TF2Error {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TF2Error where Self: Sized {
  const TYPE_NAME: &'static str = "tf2_msgs/msg/TF2Error";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tf2_msgs__msg__TF2Error() }
  }
}


#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tf2_msgs__msg__TFMessage() -> *const std::ffi::c_void;
}

#[link(name = "tf2_msgs__rosidl_generator_c")]
extern "C" {
    fn tf2_msgs__msg__TFMessage__init(msg: *mut TFMessage) -> bool;
    fn tf2_msgs__msg__TFMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TFMessage>, size: usize) -> bool;
    fn tf2_msgs__msg__TFMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TFMessage>);
    fn tf2_msgs__msg__TFMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TFMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<TFMessage>) -> bool;
}

// Corresponds to tf2_msgs__msg__TFMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TFMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transforms: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::TransformStamped>,

}



impl Default for TFMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tf2_msgs__msg__TFMessage__init(&mut msg as *mut _) {
        panic!("Call to tf2_msgs__msg__TFMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TFMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__msg__TFMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__msg__TFMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__msg__TFMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TFMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TFMessage where Self: Sized {
  const TYPE_NAME: &'static str = "tf2_msgs/msg/TFMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tf2_msgs__msg__TFMessage() }
  }
}


