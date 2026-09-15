#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__ComplexIdl() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__msg__ComplexIdl__init(msg: *mut ComplexIdl) -> bool;
    fn rosbag2_test_msgdefs__msg__ComplexIdl__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexIdl>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__msg__ComplexIdl__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexIdl>);
    fn rosbag2_test_msgdefs__msg__ComplexIdl__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexIdl>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexIdl>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__msg__ComplexIdl
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexIdl {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: super::super::msg::rmw::BasicIdl,

}



impl Default for ComplexIdl {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__msg__ComplexIdl__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__msg__ComplexIdl__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexIdl {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexIdl__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexIdl__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexIdl__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexIdl {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexIdl where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/msg/ComplexIdl";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__ComplexIdl() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__BasicIdl() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__msg__BasicIdl__init(msg: *mut BasicIdl) -> bool;
    fn rosbag2_test_msgdefs__msg__BasicIdl__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicIdl>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__msg__BasicIdl__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicIdl>);
    fn rosbag2_test_msgdefs__msg__BasicIdl__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicIdl>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicIdl>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__msg__BasicIdl
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicIdl {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,

}



impl Default for BasicIdl {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__msg__BasicIdl__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__msg__BasicIdl__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicIdl {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__BasicIdl__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__BasicIdl__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__BasicIdl__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicIdl {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicIdl where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/msg/BasicIdl";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__BasicIdl() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__ComplexWithRelativeDep() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__init(msg: *mut ComplexWithRelativeDep) -> bool;
    fn rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexWithRelativeDep>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexWithRelativeDep>);
    fn rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexWithRelativeDep>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexWithRelativeDep>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__msg__ComplexWithRelativeDep
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexWithRelativeDep {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: super::super::msg::rmw::BasicIdl,

}



impl Default for ComplexWithRelativeDep {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexWithRelativeDep {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexWithRelativeDep {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexWithRelativeDep where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/msg/ComplexWithRelativeDep";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__ComplexWithRelativeDep() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__BasicMsg() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__msg__BasicMsg__init(msg: *mut BasicMsg) -> bool;
    fn rosbag2_test_msgdefs__msg__BasicMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__msg__BasicMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg>);
    fn rosbag2_test_msgdefs__msg__BasicMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__msg__BasicMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub c: f32,

}



impl Default for BasicMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__msg__BasicMsg__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__msg__BasicMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__BasicMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__BasicMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__BasicMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/msg/BasicMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__BasicMsg() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__AnotherBasicMsg() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__msg__AnotherBasicMsg__init(msg: *mut AnotherBasicMsg) -> bool;
    fn rosbag2_test_msgdefs__msg__AnotherBasicMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AnotherBasicMsg>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__msg__AnotherBasicMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AnotherBasicMsg>);
    fn rosbag2_test_msgdefs__msg__AnotherBasicMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AnotherBasicMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<AnotherBasicMsg>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__msg__AnotherBasicMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AnotherBasicMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub c: f32,

}



impl Default for AnotherBasicMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__msg__AnotherBasicMsg__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__msg__AnotherBasicMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AnotherBasicMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__AnotherBasicMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__AnotherBasicMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__AnotherBasicMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AnotherBasicMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AnotherBasicMsg where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/msg/AnotherBasicMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__AnotherBasicMsg() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__ComplexMsg() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__msg__ComplexMsg__init(msg: *mut ComplexMsg) -> bool;
    fn rosbag2_test_msgdefs__msg__ComplexMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexMsg>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__msg__ComplexMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexMsg>);
    fn rosbag2_test_msgdefs__msg__ComplexMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexMsg>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__msg__ComplexMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub b: super::super::msg::rmw::BasicMsg,

}



impl Default for ComplexMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__msg__ComplexMsg__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__msg__ComplexMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexMsg where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/msg/ComplexMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__ComplexMsg() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__init(msg: *mut ComplexMsgDependsOnIdl) -> bool;
    fn rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexMsgDependsOnIdl>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexMsgDependsOnIdl>);
    fn rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexMsgDependsOnIdl>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexMsgDependsOnIdl>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexMsgDependsOnIdl {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: super::super::msg::rmw::BasicIdl,

}



impl Default for ComplexMsgDependsOnIdl {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexMsgDependsOnIdl {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexMsgDependsOnIdl {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexMsgDependsOnIdl where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/msg/ComplexMsgDependsOnIdl";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl() }
  }
}


