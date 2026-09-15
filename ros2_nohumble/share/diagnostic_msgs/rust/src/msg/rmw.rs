#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__msg__DiagnosticArray() -> *const std::ffi::c_void;
}

#[link(name = "diagnostic_msgs__rosidl_generator_c")]
extern "C" {
    fn diagnostic_msgs__msg__DiagnosticArray__init(msg: *mut DiagnosticArray) -> bool;
    fn diagnostic_msgs__msg__DiagnosticArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DiagnosticArray>, size: usize) -> bool;
    fn diagnostic_msgs__msg__DiagnosticArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DiagnosticArray>);
    fn diagnostic_msgs__msg__DiagnosticArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DiagnosticArray>, out_seq: *mut rosidl_runtime_rs::Sequence<DiagnosticArray>) -> bool;
}

// Corresponds to diagnostic_msgs__msg__DiagnosticArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This message is used to send diagnostic information about the state of the robot.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DiagnosticArray {
    /// for timestamp
    pub header: std_msgs::msg::rmw::Header,

    /// an array of components being reported on
    pub status: rosidl_runtime_rs::Sequence<super::super::msg::rmw::DiagnosticStatus>,

}



impl Default for DiagnosticArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !diagnostic_msgs__msg__DiagnosticArray__init(&mut msg as *mut _) {
        panic!("Call to diagnostic_msgs__msg__DiagnosticArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DiagnosticArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__DiagnosticArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__DiagnosticArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__DiagnosticArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DiagnosticArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DiagnosticArray where Self: Sized {
  const TYPE_NAME: &'static str = "diagnostic_msgs/msg/DiagnosticArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__msg__DiagnosticArray() }
  }
}


#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__msg__DiagnosticStatus() -> *const std::ffi::c_void;
}

#[link(name = "diagnostic_msgs__rosidl_generator_c")]
extern "C" {
    fn diagnostic_msgs__msg__DiagnosticStatus__init(msg: *mut DiagnosticStatus) -> bool;
    fn diagnostic_msgs__msg__DiagnosticStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DiagnosticStatus>, size: usize) -> bool;
    fn diagnostic_msgs__msg__DiagnosticStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DiagnosticStatus>);
    fn diagnostic_msgs__msg__DiagnosticStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DiagnosticStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<DiagnosticStatus>) -> bool;
}

// Corresponds to diagnostic_msgs__msg__DiagnosticStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This message holds the status of an individual component of the robot.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DiagnosticStatus {
    /// Level of operation enumerated above.
    pub level: u8,

    /// A description of the test/component reporting.
    pub name: rosidl_runtime_rs::String,

    /// A description of the status.
    pub message: rosidl_runtime_rs::String,

    /// A hardware unique string.
    pub hardware_id: rosidl_runtime_rs::String,

    /// An array of values associated with the status.
    pub values: rosidl_runtime_rs::Sequence<super::super::msg::rmw::KeyValue>,

}

impl DiagnosticStatus {
    /// Possible levels of operations.
    pub const OK: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const WARN: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ERROR: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STALE: u8 = 3;

}


impl Default for DiagnosticStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !diagnostic_msgs__msg__DiagnosticStatus__init(&mut msg as *mut _) {
        panic!("Call to diagnostic_msgs__msg__DiagnosticStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DiagnosticStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__DiagnosticStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__DiagnosticStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__DiagnosticStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DiagnosticStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DiagnosticStatus where Self: Sized {
  const TYPE_NAME: &'static str = "diagnostic_msgs/msg/DiagnosticStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__msg__DiagnosticStatus() }
  }
}


#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__msg__KeyValue() -> *const std::ffi::c_void;
}

#[link(name = "diagnostic_msgs__rosidl_generator_c")]
extern "C" {
    fn diagnostic_msgs__msg__KeyValue__init(msg: *mut KeyValue) -> bool;
    fn diagnostic_msgs__msg__KeyValue__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<KeyValue>, size: usize) -> bool;
    fn diagnostic_msgs__msg__KeyValue__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<KeyValue>);
    fn diagnostic_msgs__msg__KeyValue__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<KeyValue>, out_seq: *mut rosidl_runtime_rs::Sequence<KeyValue>) -> bool;
}

// Corresponds to diagnostic_msgs__msg__KeyValue
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// What to label this value when viewing.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyValue {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: rosidl_runtime_rs::String,

    /// A value to track over time.
    pub value: rosidl_runtime_rs::String,

}



impl Default for KeyValue {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !diagnostic_msgs__msg__KeyValue__init(&mut msg as *mut _) {
        panic!("Call to diagnostic_msgs__msg__KeyValue__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for KeyValue {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__KeyValue__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__KeyValue__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__msg__KeyValue__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for KeyValue {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for KeyValue where Self: Sized {
  const TYPE_NAME: &'static str = "diagnostic_msgs/msg/KeyValue";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__msg__KeyValue() }
  }
}


