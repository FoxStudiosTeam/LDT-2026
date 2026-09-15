#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tf2_msgs__srv__FrameGraph_Request() -> *const std::ffi::c_void;
}

#[link(name = "tf2_msgs__rosidl_generator_c")]
extern "C" {
    fn tf2_msgs__srv__FrameGraph_Request__init(msg: *mut FrameGraph_Request) -> bool;
    fn tf2_msgs__srv__FrameGraph_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FrameGraph_Request>, size: usize) -> bool;
    fn tf2_msgs__srv__FrameGraph_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FrameGraph_Request>);
    fn tf2_msgs__srv__FrameGraph_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FrameGraph_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<FrameGraph_Request>) -> bool;
}

// Corresponds to tf2_msgs__srv__FrameGraph_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrameGraph_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for FrameGraph_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tf2_msgs__srv__FrameGraph_Request__init(&mut msg as *mut _) {
        panic!("Call to tf2_msgs__srv__FrameGraph_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FrameGraph_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__srv__FrameGraph_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__srv__FrameGraph_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__srv__FrameGraph_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FrameGraph_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FrameGraph_Request where Self: Sized {
  const TYPE_NAME: &'static str = "tf2_msgs/srv/FrameGraph_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tf2_msgs__srv__FrameGraph_Request() }
  }
}


#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tf2_msgs__srv__FrameGraph_Response() -> *const std::ffi::c_void;
}

#[link(name = "tf2_msgs__rosidl_generator_c")]
extern "C" {
    fn tf2_msgs__srv__FrameGraph_Response__init(msg: *mut FrameGraph_Response) -> bool;
    fn tf2_msgs__srv__FrameGraph_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FrameGraph_Response>, size: usize) -> bool;
    fn tf2_msgs__srv__FrameGraph_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FrameGraph_Response>);
    fn tf2_msgs__srv__FrameGraph_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FrameGraph_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<FrameGraph_Response>) -> bool;
}

// Corresponds to tf2_msgs__srv__FrameGraph_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrameGraph_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub frame_yaml: rosidl_runtime_rs::String,

}



impl Default for FrameGraph_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tf2_msgs__srv__FrameGraph_Response__init(&mut msg as *mut _) {
        panic!("Call to tf2_msgs__srv__FrameGraph_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FrameGraph_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__srv__FrameGraph_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__srv__FrameGraph_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tf2_msgs__srv__FrameGraph_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FrameGraph_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FrameGraph_Response where Self: Sized {
  const TYPE_NAME: &'static str = "tf2_msgs/srv/FrameGraph_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tf2_msgs__srv__FrameGraph_Response() }
  }
}






#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__tf2_msgs__srv__FrameGraph() -> *const std::ffi::c_void;
}

// Corresponds to tf2_msgs__srv__FrameGraph
#[allow(missing_docs, non_camel_case_types)]
pub struct FrameGraph;

impl rosidl_runtime_rs::Service for FrameGraph {
    type Request = FrameGraph_Request;
    type Response = FrameGraph_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__tf2_msgs__srv__FrameGraph() }
    }
}


