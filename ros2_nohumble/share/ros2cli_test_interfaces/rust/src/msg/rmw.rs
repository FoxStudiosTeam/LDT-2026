#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__msg__ShortVaried() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__msg__ShortVaried__init(msg: *mut ShortVaried) -> bool;
    fn ros2cli_test_interfaces__msg__ShortVaried__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVaried>, size: usize) -> bool;
    fn ros2cli_test_interfaces__msg__ShortVaried__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVaried>);
    fn ros2cli_test_interfaces__msg__ShortVaried__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVaried>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVaried>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__msg__ShortVaried
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// A constant

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVaried {
    /// Bool and array of bools
    pub bool_value: bool,

    /// Comment - Nesting Level 1: 2 of 2
    pub bool_values: rosidl_runtime_rs::BoundedSequence<bool, 3>,

}

impl ShortVaried {
    /// Comment - Nesting Level 1: 1 of 2
    pub const BOOL_CONST: bool = true;

}


impl Default for ShortVaried {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__msg__ShortVaried__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__msg__ShortVaried__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVaried {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVaried__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVaried__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVaried__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVaried {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVaried where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/msg/ShortVaried";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__msg__ShortVaried() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__msg__ShortVariedMultiNested() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__msg__ShortVariedMultiNested__init(msg: *mut ShortVariedMultiNested) -> bool;
    fn ros2cli_test_interfaces__msg__ShortVariedMultiNested__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested>, size: usize) -> bool;
    fn ros2cli_test_interfaces__msg__ShortVariedMultiNested__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested>);
    fn ros2cli_test_interfaces__msg__ShortVariedMultiNested__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__msg__ShortVariedMultiNested
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// A short, varied, and nested type

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested {
    /// Comment - Nesting Level 3: 1 of 1
    pub short_varied_nested: super::super::msg::rmw::ShortVariedNested,

}



impl Default for ShortVariedMultiNested {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__msg__ShortVariedMultiNested__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__msg__ShortVariedMultiNested__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVariedMultiNested__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVariedMultiNested__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVariedMultiNested__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/msg/ShortVariedMultiNested";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__msg__ShortVariedMultiNested() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__msg__ShortVariedNested() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__msg__ShortVariedNested__init(msg: *mut ShortVariedNested) -> bool;
    fn ros2cli_test_interfaces__msg__ShortVariedNested__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedNested>, size: usize) -> bool;
    fn ros2cli_test_interfaces__msg__ShortVariedNested__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedNested>);
    fn ros2cli_test_interfaces__msg__ShortVariedNested__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedNested>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedNested>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__msg__ShortVariedNested
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// A short, varied type

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedNested {
    /// Comment - Nesting Level 2: 1 of 1
    pub short_varied: super::super::msg::rmw::ShortVaried,

}



impl Default for ShortVariedNested {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__msg__ShortVariedNested__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__msg__ShortVariedNested__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedNested {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVariedNested__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVariedNested__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__msg__ShortVariedNested__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedNested {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedNested where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/msg/ShortVariedNested";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__msg__ShortVariedNested() }
  }
}


