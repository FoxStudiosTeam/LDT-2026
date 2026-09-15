#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__init(msg: *mut ShortVariedMultiNested_Request) -> bool;
    fn ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Request>, size: usize) -> bool;
    fn ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Request>);
    fn ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Request>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Request {
    /// Comment - Nesting Level 3: 1 of 2
    pub short_varied_nested: super::super::msg::rmw::ShortVariedNested,

}



impl Default for ShortVariedMultiNested_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/srv/ShortVariedMultiNested_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request() }
  }
}


#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response() -> *const std::ffi::c_void;
}

#[link(name = "ros2cli_test_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__init(msg: *mut ShortVariedMultiNested_Response) -> bool;
    fn ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Response>, size: usize) -> bool;
    fn ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Response>);
    fn ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ShortVariedMultiNested_Response>) -> bool;
}

// Corresponds to ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Response {
    /// Comment - Nesting Level 3: 2 of 2
    pub bool_value: bool,

}



impl Default for ShortVariedMultiNested_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__init(&mut msg as *mut _) {
        panic!("Call to ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ShortVariedMultiNested_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ShortVariedMultiNested_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ros2cli_test_interfaces/srv/ShortVariedMultiNested_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response() }
  }
}






#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__srv__ShortVariedMultiNested() -> *const std::ffi::c_void;
}

// Corresponds to ros2cli_test_interfaces__srv__ShortVariedMultiNested
#[allow(missing_docs, non_camel_case_types)]
pub struct ShortVariedMultiNested;

impl rosidl_runtime_rs::Service for ShortVariedMultiNested {
    type Request = ShortVariedMultiNested_Request;
    type Response = ShortVariedMultiNested_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__srv__ShortVariedMultiNested() }
    }
}


