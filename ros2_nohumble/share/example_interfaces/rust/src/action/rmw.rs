
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_Goal() -> *const std::ffi::c_void;
}

#[link(name = "example_interfaces__rosidl_generator_c")]
extern "C" {
    fn example_interfaces__action__Fibonacci_Goal__init(msg: *mut Fibonacci_Goal) -> bool;
    fn example_interfaces__action__Fibonacci_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Goal>, size: usize) -> bool;
    fn example_interfaces__action__Fibonacci_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Goal>);
    fn example_interfaces__action__Fibonacci_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Fibonacci_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Goal>) -> bool;
}

// Corresponds to example_interfaces__action__Fibonacci_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Fibonacci_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub order: i32,

}



impl Default for Fibonacci_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_interfaces__action__Fibonacci_Goal__init(&mut msg as *mut _) {
        panic!("Call to example_interfaces__action__Fibonacci_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Fibonacci_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Fibonacci_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Fibonacci_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "example_interfaces/action/Fibonacci_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_Goal() }
  }
}


#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_Result() -> *const std::ffi::c_void;
}

#[link(name = "example_interfaces__rosidl_generator_c")]
extern "C" {
    fn example_interfaces__action__Fibonacci_Result__init(msg: *mut Fibonacci_Result) -> bool;
    fn example_interfaces__action__Fibonacci_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Result>, size: usize) -> bool;
    fn example_interfaces__action__Fibonacci_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Result>);
    fn example_interfaces__action__Fibonacci_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Fibonacci_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Result>) -> bool;
}

// Corresponds to example_interfaces__action__Fibonacci_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Fibonacci_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for Fibonacci_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_interfaces__action__Fibonacci_Result__init(&mut msg as *mut _) {
        panic!("Call to example_interfaces__action__Fibonacci_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Fibonacci_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Fibonacci_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Fibonacci_Result where Self: Sized {
  const TYPE_NAME: &'static str = "example_interfaces/action/Fibonacci_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_Result() }
  }
}


#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "example_interfaces__rosidl_generator_c")]
extern "C" {
    fn example_interfaces__action__Fibonacci_Feedback__init(msg: *mut Fibonacci_Feedback) -> bool;
    fn example_interfaces__action__Fibonacci_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Feedback>, size: usize) -> bool;
    fn example_interfaces__action__Fibonacci_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Feedback>);
    fn example_interfaces__action__Fibonacci_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Fibonacci_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_Feedback>) -> bool;
}

// Corresponds to example_interfaces__action__Fibonacci_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Fibonacci_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for Fibonacci_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_interfaces__action__Fibonacci_Feedback__init(&mut msg as *mut _) {
        panic!("Call to example_interfaces__action__Fibonacci_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Fibonacci_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Fibonacci_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Fibonacci_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "example_interfaces/action/Fibonacci_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_Feedback() }
  }
}


#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "example_interfaces__rosidl_generator_c")]
extern "C" {
    fn example_interfaces__action__Fibonacci_FeedbackMessage__init(msg: *mut Fibonacci_FeedbackMessage) -> bool;
    fn example_interfaces__action__Fibonacci_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_FeedbackMessage>, size: usize) -> bool;
    fn example_interfaces__action__Fibonacci_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_FeedbackMessage>);
    fn example_interfaces__action__Fibonacci_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Fibonacci_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_FeedbackMessage>) -> bool;
}

// Corresponds to example_interfaces__action__Fibonacci_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Fibonacci_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Fibonacci_Feedback,

}



impl Default for Fibonacci_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_interfaces__action__Fibonacci_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to example_interfaces__action__Fibonacci_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Fibonacci_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Fibonacci_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Fibonacci_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "example_interfaces/action/Fibonacci_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_FeedbackMessage() }
  }
}




#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "example_interfaces__rosidl_generator_c")]
extern "C" {
    fn example_interfaces__action__Fibonacci_SendGoal_Request__init(msg: *mut Fibonacci_SendGoal_Request) -> bool;
    fn example_interfaces__action__Fibonacci_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_SendGoal_Request>, size: usize) -> bool;
    fn example_interfaces__action__Fibonacci_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_SendGoal_Request>);
    fn example_interfaces__action__Fibonacci_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Fibonacci_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_SendGoal_Request>) -> bool;
}

// Corresponds to example_interfaces__action__Fibonacci_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Fibonacci_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Fibonacci_Goal,

}



impl Default for Fibonacci_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_interfaces__action__Fibonacci_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to example_interfaces__action__Fibonacci_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Fibonacci_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Fibonacci_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Fibonacci_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "example_interfaces/action/Fibonacci_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_SendGoal_Request() }
  }
}


#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "example_interfaces__rosidl_generator_c")]
extern "C" {
    fn example_interfaces__action__Fibonacci_SendGoal_Response__init(msg: *mut Fibonacci_SendGoal_Response) -> bool;
    fn example_interfaces__action__Fibonacci_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_SendGoal_Response>, size: usize) -> bool;
    fn example_interfaces__action__Fibonacci_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_SendGoal_Response>);
    fn example_interfaces__action__Fibonacci_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Fibonacci_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_SendGoal_Response>) -> bool;
}

// Corresponds to example_interfaces__action__Fibonacci_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Fibonacci_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Fibonacci_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_interfaces__action__Fibonacci_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to example_interfaces__action__Fibonacci_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Fibonacci_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Fibonacci_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Fibonacci_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "example_interfaces/action/Fibonacci_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_SendGoal_Response() }
  }
}


#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "example_interfaces__rosidl_generator_c")]
extern "C" {
    fn example_interfaces__action__Fibonacci_GetResult_Request__init(msg: *mut Fibonacci_GetResult_Request) -> bool;
    fn example_interfaces__action__Fibonacci_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_GetResult_Request>, size: usize) -> bool;
    fn example_interfaces__action__Fibonacci_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_GetResult_Request>);
    fn example_interfaces__action__Fibonacci_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Fibonacci_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_GetResult_Request>) -> bool;
}

// Corresponds to example_interfaces__action__Fibonacci_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Fibonacci_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Fibonacci_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_interfaces__action__Fibonacci_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to example_interfaces__action__Fibonacci_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Fibonacci_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Fibonacci_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Fibonacci_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "example_interfaces/action/Fibonacci_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_GetResult_Request() }
  }
}


#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "example_interfaces__rosidl_generator_c")]
extern "C" {
    fn example_interfaces__action__Fibonacci_GetResult_Response__init(msg: *mut Fibonacci_GetResult_Response) -> bool;
    fn example_interfaces__action__Fibonacci_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_GetResult_Response>, size: usize) -> bool;
    fn example_interfaces__action__Fibonacci_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_GetResult_Response>);
    fn example_interfaces__action__Fibonacci_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Fibonacci_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Fibonacci_GetResult_Response>) -> bool;
}

// Corresponds to example_interfaces__action__Fibonacci_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Fibonacci_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Fibonacci_Result,

}



impl Default for Fibonacci_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_interfaces__action__Fibonacci_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to example_interfaces__action__Fibonacci_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Fibonacci_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_interfaces__action__Fibonacci_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Fibonacci_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Fibonacci_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "example_interfaces/action/Fibonacci_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_interfaces__action__Fibonacci_GetResult_Response() }
  }
}






#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__example_interfaces__action__Fibonacci_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to example_interfaces__action__Fibonacci_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Fibonacci_SendGoal;

impl rosidl_runtime_rs::Service for Fibonacci_SendGoal {
    type Request = Fibonacci_SendGoal_Request;
    type Response = Fibonacci_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__example_interfaces__action__Fibonacci_SendGoal() }
    }
}




#[link(name = "example_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__example_interfaces__action__Fibonacci_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to example_interfaces__action__Fibonacci_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Fibonacci_GetResult;

impl rosidl_runtime_rs::Service for Fibonacci_GetResult {
    type Request = Fibonacci_GetResult_Request;
    type Response = Fibonacci_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__example_interfaces__action__Fibonacci_GetResult() }
    }
}


