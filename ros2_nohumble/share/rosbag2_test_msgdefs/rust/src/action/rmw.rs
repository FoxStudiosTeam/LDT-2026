
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_Goal() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicAction_Goal__init(msg: *mut BasicAction_Goal) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Goal>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Goal>);
    fn rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicAction_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Goal>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: rosidl_runtime_rs::String,

}



impl Default for BasicAction_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicAction_Goal__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicAction_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicAction_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicAction_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicAction_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicAction_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_Goal() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_Result() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicAction_Result__init(msg: *mut BasicAction_Result) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Result>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Result>);
    fn rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicAction_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Result>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: rosidl_runtime_rs::String,

}



impl Default for BasicAction_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicAction_Result__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicAction_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicAction_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicAction_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicAction_Result where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicAction_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_Result() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicAction_Feedback__init(msg: *mut BasicAction_Feedback) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Feedback>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Feedback>);
    fn rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicAction_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicAction_Feedback>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: rosidl_runtime_rs::String,

}



impl Default for BasicAction_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicAction_Feedback__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicAction_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicAction_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicAction_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicAction_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicAction_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_Feedback() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__init(msg: *mut BasicAction_FeedbackMessage) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_FeedbackMessage>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_FeedbackMessage>);
    fn rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicAction_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicAction_FeedbackMessage>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::BasicAction_Feedback,

}



impl Default for BasicAction_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicAction_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicAction_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicAction_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicAction_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_Goal() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicMsg_Goal__init(msg: *mut BasicMsg_Goal) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Goal>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Goal>);
    fn rosbag2_test_msgdefs__action__BasicMsg_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Goal>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: rosidl_runtime_rs::String,

}



impl Default for BasicMsg_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicMsg_Goal__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicMsg_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicMsg_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_Goal() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_Result() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicMsg_Result__init(msg: *mut BasicMsg_Result) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Result>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Result>);
    fn rosbag2_test_msgdefs__action__BasicMsg_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Result>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: rosidl_runtime_rs::String,

}



impl Default for BasicMsg_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicMsg_Result__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicMsg_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg_Result where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicMsg_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_Result() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicMsg_Feedback__init(msg: *mut BasicMsg_Feedback) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Feedback>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Feedback>);
    fn rosbag2_test_msgdefs__action__BasicMsg_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_Feedback>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: rosidl_runtime_rs::String,

}



impl Default for BasicMsg_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicMsg_Feedback__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicMsg_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicMsg_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_Feedback() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__init(msg: *mut BasicMsg_FeedbackMessage) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_FeedbackMessage>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_FeedbackMessage>);
    fn rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_FeedbackMessage>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::BasicMsg_Feedback,

}



impl Default for BasicMsg_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicMsg_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_Goal() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__init(msg: *mut ComplexActionMsg_Goal) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Goal>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Goal>);
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionMsg_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Goal>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::msg::rmw::BasicMsg,

}



impl Default for ComplexActionMsg_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionMsg_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionMsg_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionMsg_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_Goal() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_Result() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Result__init(msg: *mut ComplexActionMsg_Result) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Result>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Result>);
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionMsg_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Result>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::msg::rmw::BasicMsg,

}



impl Default for ComplexActionMsg_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionMsg_Result__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionMsg_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionMsg_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionMsg_Result where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionMsg_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_Result() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__init(msg: *mut ComplexActionMsg_Feedback) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Feedback>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Feedback>);
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionMsg_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_Feedback>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::msg::rmw::BasicMsg,

}



impl Default for ComplexActionMsg_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionMsg_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionMsg_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionMsg_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__init(msg: *mut ComplexActionMsg_FeedbackMessage) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_FeedbackMessage>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_FeedbackMessage>);
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionMsg_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_FeedbackMessage>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ComplexActionMsg_Feedback,

}



impl Default for ComplexActionMsg_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionMsg_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionMsg_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionMsg_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_Goal() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__init(msg: *mut ComplexActionIdl_Goal) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Goal>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Goal>);
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionIdl_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Goal>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::msg::rmw::BasicIdl,

}



impl Default for ComplexActionIdl_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionIdl_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionIdl_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionIdl_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_Goal() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_Result() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Result__init(msg: *mut ComplexActionIdl_Result) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Result>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Result>);
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionIdl_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Result>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::msg::rmw::BasicIdl,

}



impl Default for ComplexActionIdl_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionIdl_Result__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionIdl_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionIdl_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionIdl_Result where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionIdl_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_Result() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__init(msg: *mut ComplexActionIdl_Feedback) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Feedback>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Feedback>);
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionIdl_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_Feedback>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::msg::rmw::BasicIdl,

}



impl Default for ComplexActionIdl_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionIdl_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionIdl_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionIdl_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__init(msg: *mut ComplexActionIdl_FeedbackMessage) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_FeedbackMessage>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_FeedbackMessage>);
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionIdl_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_FeedbackMessage>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ComplexActionIdl_Feedback,

}



impl Default for ComplexActionIdl_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionIdl_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionIdl_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionIdl_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage() }
  }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__init(msg: *mut BasicAction_SendGoal_Request) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_SendGoal_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_SendGoal_Request>);
    fn rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicAction_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicAction_SendGoal_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::BasicAction_Goal,

}



impl Default for BasicAction_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicAction_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicAction_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicAction_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicAction_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__init(msg: *mut BasicAction_SendGoal_Response) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_SendGoal_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_SendGoal_Response>);
    fn rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicAction_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicAction_SendGoal_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for BasicAction_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicAction_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicAction_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicAction_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicAction_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__init(msg: *mut BasicAction_GetResult_Request) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_GetResult_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_GetResult_Request>);
    fn rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicAction_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicAction_GetResult_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for BasicAction_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicAction_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicAction_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicAction_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicAction_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_GetResult_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__init(msg: *mut BasicAction_GetResult_Response) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_GetResult_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicAction_GetResult_Response>);
    fn rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicAction_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicAction_GetResult_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::BasicAction_Result,

}



impl Default for BasicAction_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicAction_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicAction_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicAction_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicAction_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_GetResult_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__init(msg: *mut BasicMsg_SendGoal_Request) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_SendGoal_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_SendGoal_Request>);
    fn rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_SendGoal_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::BasicMsg_Goal,

}



impl Default for BasicMsg_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicMsg_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__init(msg: *mut BasicMsg_SendGoal_Response) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_SendGoal_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_SendGoal_Response>);
    fn rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_SendGoal_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for BasicMsg_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicMsg_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__init(msg: *mut BasicMsg_GetResult_Request) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_GetResult_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_GetResult_Request>);
    fn rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_GetResult_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for BasicMsg_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicMsg_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__init(msg: *mut BasicMsg_GetResult_Response) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_GetResult_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_GetResult_Response>);
    fn rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicMsg_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicMsg_GetResult_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::BasicMsg_Result,

}



impl Default for BasicMsg_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicMsg_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicMsg_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/BasicMsg_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__init(msg: *mut ComplexActionMsg_SendGoal_Request) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_SendGoal_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_SendGoal_Request>);
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionMsg_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_SendGoal_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ComplexActionMsg_Goal,

}



impl Default for ComplexActionMsg_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionMsg_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionMsg_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionMsg_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__init(msg: *mut ComplexActionMsg_SendGoal_Response) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_SendGoal_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_SendGoal_Response>);
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionMsg_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_SendGoal_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ComplexActionMsg_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionMsg_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionMsg_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionMsg_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__init(msg: *mut ComplexActionMsg_GetResult_Request) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_GetResult_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_GetResult_Request>);
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionMsg_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_GetResult_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ComplexActionMsg_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionMsg_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionMsg_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionMsg_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__init(msg: *mut ComplexActionMsg_GetResult_Response) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_GetResult_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_GetResult_Response>);
    fn rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionMsg_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionMsg_GetResult_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ComplexActionMsg_Result,

}



impl Default for ComplexActionMsg_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionMsg_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionMsg_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionMsg_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__init(msg: *mut ComplexActionIdl_SendGoal_Request) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_SendGoal_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_SendGoal_Request>);
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionIdl_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_SendGoal_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ComplexActionIdl_Goal,

}



impl Default for ComplexActionIdl_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionIdl_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionIdl_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionIdl_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__init(msg: *mut ComplexActionIdl_SendGoal_Response) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_SendGoal_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_SendGoal_Response>);
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionIdl_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_SendGoal_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ComplexActionIdl_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionIdl_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionIdl_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionIdl_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__init(msg: *mut ComplexActionIdl_GetResult_Request) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_GetResult_Request>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_GetResult_Request>);
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionIdl_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_GetResult_Request>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ComplexActionIdl_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionIdl_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionIdl_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionIdl_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request() }
  }
}


#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_test_msgdefs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__init(msg: *mut ComplexActionIdl_GetResult_Response) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_GetResult_Response>, size: usize) -> bool;
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_GetResult_Response>);
    fn rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexActionIdl_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexActionIdl_GetResult_Response>) -> bool;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ComplexActionIdl_Result,

}



impl Default for ComplexActionIdl_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexActionIdl_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexActionIdl_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_test_msgdefs/action/ComplexActionIdl_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response() }
  }
}






#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicAction_SendGoal;

impl rosidl_runtime_rs::Service for BasicAction_SendGoal {
    type Request = BasicAction_SendGoal_Request;
    type Response = BasicAction_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_SendGoal() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicAction_GetResult;

impl rosidl_runtime_rs::Service for BasicAction_GetResult {
    type Request = BasicAction_GetResult_Request;
    type Response = BasicAction_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_GetResult() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicMsg_SendGoal;

impl rosidl_runtime_rs::Service for BasicMsg_SendGoal {
    type Request = BasicMsg_SendGoal_Request;
    type Response = BasicMsg_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_SendGoal() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicMsg_GetResult;

impl rosidl_runtime_rs::Service for BasicMsg_GetResult {
    type Request = BasicMsg_GetResult_Request;
    type Response = BasicMsg_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_GetResult() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionMsg_SendGoal;

impl rosidl_runtime_rs::Service for ComplexActionMsg_SendGoal {
    type Request = ComplexActionMsg_SendGoal_Request;
    type Response = ComplexActionMsg_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionMsg_GetResult;

impl rosidl_runtime_rs::Service for ComplexActionMsg_GetResult {
    type Request = ComplexActionMsg_GetResult_Request;
    type Response = ComplexActionMsg_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionIdl_SendGoal;

impl rosidl_runtime_rs::Service for ComplexActionIdl_SendGoal {
    type Request = ComplexActionIdl_SendGoal_Request;
    type Response = ComplexActionIdl_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionIdl_GetResult;

impl rosidl_runtime_rs::Service for ComplexActionIdl_GetResult {
    type Request = ComplexActionIdl_GetResult_Request;
    type Response = ComplexActionIdl_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult() }
    }
}


