
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__init(msg: *mut ShortVariedMultiNested_Goal) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Goal>, size: usize) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Goal>);
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Goal>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Goal {
    /// Comment - Nesting Level 3: 1 of 2
    pub short_varied_nested: super::super::msg::rmw::ShortVariedNested,

}



impl Default for ShortVariedMultiNested_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/action/ShortVariedMultiNested_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_Result() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__init(msg: *mut ShortVariedMultiNested_Result) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Result>, size: usize) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Result>);
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Result>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Result {
    /// Comment - Nesting Level 3: 2 of 2
    pub bool_value: bool,

}



impl Default for ShortVariedMultiNested_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_Result where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/action/ShortVariedMultiNested_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_Result() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__init(msg: *mut ShortVariedMultiNested_Feedback) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Feedback>, size: usize) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Feedback>);
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Feedback>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: [bool; 3],

}



impl Default for ShortVariedMultiNested_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/action/ShortVariedMultiNested_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__init(msg: *mut ShortVariedMultiNested_FeedbackMessage) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_FeedbackMessage>, size: usize) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_FeedbackMessage>);
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_FeedbackMessage>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ShortVariedMultiNested_Feedback,

}



impl Default for ShortVariedMultiNested_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/action/ShortVariedMultiNested_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage() }
  }
}




#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__init(msg: *mut ShortVariedMultiNested_SendGoal_Request) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_SendGoal_Request>, size: usize) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_SendGoal_Request>);
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_SendGoal_Request>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ShortVariedMultiNested_Goal,

}



impl Default for ShortVariedMultiNested_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/action/ShortVariedMultiNested_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__init(msg: *mut ShortVariedMultiNested_SendGoal_Response) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_SendGoal_Response>, size: usize) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_SendGoal_Response>);
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_SendGoal_Response>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ShortVariedMultiNested_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/action/ShortVariedMultiNested_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__init(msg: *mut ShortVariedMultiNested_GetResult_Request) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_GetResult_Request>, size: usize) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_GetResult_Request>);
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_GetResult_Request>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ShortVariedMultiNested_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/action/ShortVariedMultiNested_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__init(msg: *mut ShortVariedMultiNested_GetResult_Response) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_GetResult_Response>, size: usize) -> bool;
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_GetResult_Response>);
    fn ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_GetResult_Response>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ShortVariedMultiNested_Result,

}



impl Default for ShortVariedMultiNested_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/action/ShortVariedMultiNested_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response() }
  }
}






#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ShortVariedMultiNested_SendGoal;

impl rosidl_runtime_rs::Service for ShortVariedMultiNested_SendGoal {
    type Request = ShortVariedMultiNested_SendGoal_Request;
    type Response = ShortVariedMultiNested_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal() }
    }
}




#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ShortVariedMultiNested_GetResult;

impl rosidl_runtime_rs::Service for ShortVariedMultiNested_GetResult {
    type Request = ShortVariedMultiNested_GetResult_Request;
    type Response = ShortVariedMultiNested_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult() }
    }
}


