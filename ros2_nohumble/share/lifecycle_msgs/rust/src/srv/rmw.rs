#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__ChangeState_Request() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__srv__ChangeState_Request__init(msg: *mut ChangeState_Request) -> bool;
    fn lifecycle_msgs__srv__ChangeState_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ChangeState_Request>, size: usize) -> bool;
    fn lifecycle_msgs__srv__ChangeState_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ChangeState_Request>);
    fn lifecycle_msgs__srv__ChangeState_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ChangeState_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ChangeState_Request>) -> bool;
}

// Corresponds to lifecycle_msgs__srv__ChangeState_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ChangeState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transition: super::super::msg::rmw::Transition,

}



impl Default for ChangeState_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__srv__ChangeState_Request__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__srv__ChangeState_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ChangeState_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__ChangeState_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__ChangeState_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__ChangeState_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ChangeState_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ChangeState_Request where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/srv/ChangeState_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__ChangeState_Request() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__ChangeState_Response() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__srv__ChangeState_Response__init(msg: *mut ChangeState_Response) -> bool;
    fn lifecycle_msgs__srv__ChangeState_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ChangeState_Response>, size: usize) -> bool;
    fn lifecycle_msgs__srv__ChangeState_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ChangeState_Response>);
    fn lifecycle_msgs__srv__ChangeState_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ChangeState_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ChangeState_Response>) -> bool;
}

// Corresponds to lifecycle_msgs__srv__ChangeState_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ChangeState_Response {
    /// Indicates whether the service was able to initiate the state transition
    pub success: bool,

}



impl Default for ChangeState_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__srv__ChangeState_Response__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__srv__ChangeState_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ChangeState_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__ChangeState_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__ChangeState_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__ChangeState_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ChangeState_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ChangeState_Response where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/srv/ChangeState_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__ChangeState_Response() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetAvailableStates_Request() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__srv__GetAvailableStates_Request__init(msg: *mut GetAvailableStates_Request) -> bool;
    fn lifecycle_msgs__srv__GetAvailableStates_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetAvailableStates_Request>, size: usize) -> bool;
    fn lifecycle_msgs__srv__GetAvailableStates_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetAvailableStates_Request>);
    fn lifecycle_msgs__srv__GetAvailableStates_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetAvailableStates_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetAvailableStates_Request>) -> bool;
}

// Corresponds to lifecycle_msgs__srv__GetAvailableStates_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetAvailableStates_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetAvailableStates_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__srv__GetAvailableStates_Request__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__srv__GetAvailableStates_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetAvailableStates_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableStates_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableStates_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableStates_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetAvailableStates_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetAvailableStates_Request where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/srv/GetAvailableStates_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetAvailableStates_Request() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetAvailableStates_Response() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__srv__GetAvailableStates_Response__init(msg: *mut GetAvailableStates_Response) -> bool;
    fn lifecycle_msgs__srv__GetAvailableStates_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetAvailableStates_Response>, size: usize) -> bool;
    fn lifecycle_msgs__srv__GetAvailableStates_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetAvailableStates_Response>);
    fn lifecycle_msgs__srv__GetAvailableStates_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetAvailableStates_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetAvailableStates_Response>) -> bool;
}

// Corresponds to lifecycle_msgs__srv__GetAvailableStates_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetAvailableStates_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub available_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::State>,

}



impl Default for GetAvailableStates_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__srv__GetAvailableStates_Response__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__srv__GetAvailableStates_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetAvailableStates_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableStates_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableStates_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableStates_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetAvailableStates_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetAvailableStates_Response where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/srv/GetAvailableStates_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetAvailableStates_Response() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetAvailableTransitions_Request() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__srv__GetAvailableTransitions_Request__init(msg: *mut GetAvailableTransitions_Request) -> bool;
    fn lifecycle_msgs__srv__GetAvailableTransitions_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetAvailableTransitions_Request>, size: usize) -> bool;
    fn lifecycle_msgs__srv__GetAvailableTransitions_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetAvailableTransitions_Request>);
    fn lifecycle_msgs__srv__GetAvailableTransitions_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetAvailableTransitions_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetAvailableTransitions_Request>) -> bool;
}

// Corresponds to lifecycle_msgs__srv__GetAvailableTransitions_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetAvailableTransitions_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetAvailableTransitions_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__srv__GetAvailableTransitions_Request__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__srv__GetAvailableTransitions_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetAvailableTransitions_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableTransitions_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableTransitions_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableTransitions_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetAvailableTransitions_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetAvailableTransitions_Request where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/srv/GetAvailableTransitions_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetAvailableTransitions_Request() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetAvailableTransitions_Response() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__srv__GetAvailableTransitions_Response__init(msg: *mut GetAvailableTransitions_Response) -> bool;
    fn lifecycle_msgs__srv__GetAvailableTransitions_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetAvailableTransitions_Response>, size: usize) -> bool;
    fn lifecycle_msgs__srv__GetAvailableTransitions_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetAvailableTransitions_Response>);
    fn lifecycle_msgs__srv__GetAvailableTransitions_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetAvailableTransitions_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetAvailableTransitions_Response>) -> bool;
}

// Corresponds to lifecycle_msgs__srv__GetAvailableTransitions_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetAvailableTransitions_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub available_transitions: rosidl_runtime_rs::Sequence<super::super::msg::rmw::TransitionDescription>,

}



impl Default for GetAvailableTransitions_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__srv__GetAvailableTransitions_Response__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__srv__GetAvailableTransitions_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetAvailableTransitions_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableTransitions_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableTransitions_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetAvailableTransitions_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetAvailableTransitions_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetAvailableTransitions_Response where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/srv/GetAvailableTransitions_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetAvailableTransitions_Response() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetState_Request() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__srv__GetState_Request__init(msg: *mut GetState_Request) -> bool;
    fn lifecycle_msgs__srv__GetState_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetState_Request>, size: usize) -> bool;
    fn lifecycle_msgs__srv__GetState_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetState_Request>);
    fn lifecycle_msgs__srv__GetState_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetState_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetState_Request>) -> bool;
}

// Corresponds to lifecycle_msgs__srv__GetState_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetState_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__srv__GetState_Request__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__srv__GetState_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetState_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetState_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetState_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetState_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetState_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetState_Request where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/srv/GetState_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetState_Request() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetState_Response() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__srv__GetState_Response__init(msg: *mut GetState_Response) -> bool;
    fn lifecycle_msgs__srv__GetState_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetState_Response>, size: usize) -> bool;
    fn lifecycle_msgs__srv__GetState_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetState_Response>);
    fn lifecycle_msgs__srv__GetState_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetState_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetState_Response>) -> bool;
}

// Corresponds to lifecycle_msgs__srv__GetState_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_state: super::super::msg::rmw::State,

}



impl Default for GetState_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__srv__GetState_Response__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__srv__GetState_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetState_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetState_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetState_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__srv__GetState_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetState_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetState_Response where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/srv/GetState_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__srv__GetState_Response() }
  }
}






#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__ChangeState() -> *const std::ffi::c_void;
}

// Corresponds to lifecycle_msgs__srv__ChangeState
#[allow(missing_docs, non_camel_case_types)]
pub struct ChangeState;

impl rosidl_runtime_rs::Service for ChangeState {
    type Request = ChangeState_Request;
    type Response = ChangeState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__ChangeState() }
    }
}




#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetAvailableStates() -> *const std::ffi::c_void;
}

// Corresponds to lifecycle_msgs__srv__GetAvailableStates
#[allow(missing_docs, non_camel_case_types)]
pub struct GetAvailableStates;

impl rosidl_runtime_rs::Service for GetAvailableStates {
    type Request = GetAvailableStates_Request;
    type Response = GetAvailableStates_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetAvailableStates() }
    }
}




#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetAvailableTransitions() -> *const std::ffi::c_void;
}

// Corresponds to lifecycle_msgs__srv__GetAvailableTransitions
#[allow(missing_docs, non_camel_case_types)]
pub struct GetAvailableTransitions;

impl rosidl_runtime_rs::Service for GetAvailableTransitions {
    type Request = GetAvailableTransitions_Request;
    type Response = GetAvailableTransitions_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetAvailableTransitions() }
    }
}




#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetState() -> *const std::ffi::c_void;
}

// Corresponds to lifecycle_msgs__srv__GetState
#[allow(missing_docs, non_camel_case_types)]
pub struct GetState;

impl rosidl_runtime_rs::Service for GetState {
    type Request = GetState_Request;
    type Response = GetState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetState() }
    }
}


