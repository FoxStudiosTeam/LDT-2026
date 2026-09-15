#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Burst_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Burst_Request__init(msg: *mut Burst_Request) -> bool;
    fn rosbag2_interfaces__srv__Burst_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Burst_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Burst_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Burst_Request>);
    fn rosbag2_interfaces__srv__Burst_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Burst_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Burst_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Burst_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Burst_Request {
    /// Number of messages to burst; zero to burst the whole bag
    pub num_messages: u64,

}



impl Default for Burst_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Burst_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Burst_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Burst_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Burst_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Burst_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Burst_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Burst_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Burst_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Burst_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Burst_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Burst_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Burst_Response__init(msg: *mut Burst_Response) -> bool;
    fn rosbag2_interfaces__srv__Burst_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Burst_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Burst_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Burst_Response>);
    fn rosbag2_interfaces__srv__Burst_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Burst_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Burst_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Burst_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Burst_Response {
    /// Number of messages actually burst
    pub actually_burst: u64,

}



impl Default for Burst_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Burst_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Burst_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Burst_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Burst_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Burst_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Burst_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Burst_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Burst_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Burst_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Burst_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__GetRate_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__GetRate_Request__init(msg: *mut GetRate_Request) -> bool;
    fn rosbag2_interfaces__srv__GetRate_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetRate_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__GetRate_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetRate_Request>);
    fn rosbag2_interfaces__srv__GetRate_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetRate_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetRate_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__GetRate_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRate_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetRate_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__GetRate_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__GetRate_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetRate_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetRate_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetRate_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetRate_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetRate_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetRate_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/GetRate_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__GetRate_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__GetRate_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__GetRate_Response__init(msg: *mut GetRate_Response) -> bool;
    fn rosbag2_interfaces__srv__GetRate_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetRate_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__GetRate_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetRate_Response>);
    fn rosbag2_interfaces__srv__GetRate_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetRate_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetRate_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__GetRate_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRate_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub rate: f64,

}



impl Default for GetRate_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__GetRate_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__GetRate_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetRate_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetRate_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetRate_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetRate_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetRate_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetRate_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/GetRate_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__GetRate_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__GetSubscribedTopics_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__GetSubscribedTopics_Request__init(msg: *mut GetSubscribedTopics_Request) -> bool;
    fn rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSubscribedTopics_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSubscribedTopics_Request>);
    fn rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSubscribedTopics_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSubscribedTopics_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__GetSubscribedTopics_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSubscribedTopics_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetSubscribedTopics_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__GetSubscribedTopics_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__GetSubscribedTopics_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSubscribedTopics_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetSubscribedTopics_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSubscribedTopics_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSubscribedTopics_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/GetSubscribedTopics_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__GetSubscribedTopics_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__GetSubscribedTopics_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__GetSubscribedTopics_Response__init(msg: *mut GetSubscribedTopics_Response) -> bool;
    fn rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSubscribedTopics_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSubscribedTopics_Response>);
    fn rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSubscribedTopics_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSubscribedTopics_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__GetSubscribedTopics_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSubscribedTopics_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub topics: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for GetSubscribedTopics_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__GetSubscribedTopics_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__GetSubscribedTopics_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSubscribedTopics_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__GetSubscribedTopics_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSubscribedTopics_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSubscribedTopics_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/GetSubscribedTopics_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__GetSubscribedTopics_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__IsDiscoveryRunning_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__IsDiscoveryRunning_Request__init(msg: *mut IsDiscoveryRunning_Request) -> bool;
    fn rosbag2_interfaces__srv__IsDiscoveryRunning_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsDiscoveryRunning_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__IsDiscoveryRunning_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsDiscoveryRunning_Request>);
    fn rosbag2_interfaces__srv__IsDiscoveryRunning_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsDiscoveryRunning_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<IsDiscoveryRunning_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__IsDiscoveryRunning_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsDiscoveryRunning_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsDiscoveryRunning_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__IsDiscoveryRunning_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__IsDiscoveryRunning_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsDiscoveryRunning_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsDiscoveryRunning_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsDiscoveryRunning_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsDiscoveryRunning_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsDiscoveryRunning_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsDiscoveryRunning_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/IsDiscoveryRunning_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__IsDiscoveryRunning_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__IsDiscoveryRunning_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__IsDiscoveryRunning_Response__init(msg: *mut IsDiscoveryRunning_Response) -> bool;
    fn rosbag2_interfaces__srv__IsDiscoveryRunning_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsDiscoveryRunning_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__IsDiscoveryRunning_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsDiscoveryRunning_Response>);
    fn rosbag2_interfaces__srv__IsDiscoveryRunning_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsDiscoveryRunning_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<IsDiscoveryRunning_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__IsDiscoveryRunning_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsDiscoveryRunning_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub running: bool,

}



impl Default for IsDiscoveryRunning_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__IsDiscoveryRunning_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__IsDiscoveryRunning_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsDiscoveryRunning_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsDiscoveryRunning_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsDiscoveryRunning_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsDiscoveryRunning_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsDiscoveryRunning_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsDiscoveryRunning_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/IsDiscoveryRunning_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__IsDiscoveryRunning_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__IsPaused_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__IsPaused_Request__init(msg: *mut IsPaused_Request) -> bool;
    fn rosbag2_interfaces__srv__IsPaused_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsPaused_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__IsPaused_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsPaused_Request>);
    fn rosbag2_interfaces__srv__IsPaused_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsPaused_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<IsPaused_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__IsPaused_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsPaused_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsPaused_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__IsPaused_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__IsPaused_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsPaused_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsPaused_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsPaused_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsPaused_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsPaused_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsPaused_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/IsPaused_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__IsPaused_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__IsPaused_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__IsPaused_Response__init(msg: *mut IsPaused_Response) -> bool;
    fn rosbag2_interfaces__srv__IsPaused_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsPaused_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__IsPaused_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsPaused_Response>);
    fn rosbag2_interfaces__srv__IsPaused_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsPaused_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<IsPaused_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__IsPaused_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsPaused_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub paused: bool,

}



impl Default for IsPaused_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__IsPaused_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__IsPaused_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsPaused_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsPaused_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsPaused_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__IsPaused_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsPaused_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsPaused_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/IsPaused_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__IsPaused_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Pause_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Pause_Request__init(msg: *mut Pause_Request) -> bool;
    fn rosbag2_interfaces__srv__Pause_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Pause_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Pause_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Pause_Request>);
    fn rosbag2_interfaces__srv__Pause_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Pause_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Pause_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Pause_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Pause_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Pause_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Pause_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Pause_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Pause_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Pause_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Pause_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Pause_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Pause_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Pause_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Pause_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Pause_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Pause_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Pause_Response__init(msg: *mut Pause_Response) -> bool;
    fn rosbag2_interfaces__srv__Pause_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Pause_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Pause_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Pause_Response>);
    fn rosbag2_interfaces__srv__Pause_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Pause_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Pause_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Pause_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Pause_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Pause_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Pause_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Pause_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Pause_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Pause_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Pause_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Pause_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Pause_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Pause_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Pause_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Pause_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Play_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Play_Request__init(msg: *mut Play_Request) -> bool;
    fn rosbag2_interfaces__srv__Play_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Play_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Play_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Play_Request>);
    fn rosbag2_interfaces__srv__Play_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Play_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Play_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Play_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Play_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start_offset: builtin_interfaces::msg::rmw::Time,

    /// See rosbag2_transport::PlayOptions::playback_duration
    pub playback_duration: builtin_interfaces::msg::rmw::Duration,

    /// See rosbag2_transport::PlayOptions::playback_until_timestamp
    pub playback_until_timestamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Play_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Play_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Play_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Play_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Play_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Play_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Play_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Play_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Play_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Play_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Play_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Play_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Play_Response__init(msg: *mut Play_Response) -> bool;
    fn rosbag2_interfaces__srv__Play_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Play_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Play_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Play_Response>);
    fn rosbag2_interfaces__srv__Play_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Play_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Play_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Play_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Play_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Play_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Play_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Play_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Play_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Play_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Play_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Play_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Play_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Play_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Play_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Play_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__PlayNext_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__PlayNext_Request__init(msg: *mut PlayNext_Request) -> bool;
    fn rosbag2_interfaces__srv__PlayNext_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlayNext_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__PlayNext_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlayNext_Request>);
    fn rosbag2_interfaces__srv__PlayNext_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlayNext_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PlayNext_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__PlayNext_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlayNext_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for PlayNext_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__PlayNext_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__PlayNext_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlayNext_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__PlayNext_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__PlayNext_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__PlayNext_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlayNext_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlayNext_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/PlayNext_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__PlayNext_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__PlayNext_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__PlayNext_Response__init(msg: *mut PlayNext_Response) -> bool;
    fn rosbag2_interfaces__srv__PlayNext_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlayNext_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__PlayNext_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlayNext_Response>);
    fn rosbag2_interfaces__srv__PlayNext_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlayNext_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PlayNext_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__PlayNext_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlayNext_Response {
    /// can only play-next while playback is paused
    pub success: bool,

}



impl Default for PlayNext_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__PlayNext_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__PlayNext_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlayNext_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__PlayNext_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__PlayNext_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__PlayNext_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlayNext_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlayNext_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/PlayNext_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__PlayNext_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Record_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Record_Request__init(msg: *mut Record_Request) -> bool;
    fn rosbag2_interfaces__srv__Record_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Record_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Record_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Record_Request>);
    fn rosbag2_interfaces__srv__Record_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Record_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Record_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Record_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Record_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub uri: rosidl_runtime_rs::String,

    /// Timestamp in the future when to start recording.
    /// If empty or time in the past, recording starts immediately.
    pub start_time: builtin_interfaces::msg::rmw::Time,

}



impl Default for Record_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Record_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Record_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Record_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Record_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Record_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Record_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Record_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Record_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Record_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Record_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Record_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Record_Response__init(msg: *mut Record_Response) -> bool;
    fn rosbag2_interfaces__srv__Record_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Record_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Record_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Record_Response>);
    fn rosbag2_interfaces__srv__Record_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Record_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Record_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Record_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Record_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: rosidl_runtime_rs::String,

}



impl Default for Record_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Record_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Record_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Record_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Record_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Record_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Record_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Record_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Record_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Record_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Record_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Resume_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Resume_Request__init(msg: *mut Resume_Request) -> bool;
    fn rosbag2_interfaces__srv__Resume_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Resume_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Resume_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Resume_Request>);
    fn rosbag2_interfaces__srv__Resume_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Resume_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Resume_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Resume_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Resume_Request {
    /// Timestamp in the future when to resume recording/playback.
    /// If empty or time in the past, resumes recording/playback immediately.
    /// Note: The resume_time is not supported by player and shall be set to zero when using Resume with
    /// player.
    pub resume_time: builtin_interfaces::msg::rmw::Time,

    /// Resume mode to use for the resume_time request.
    pub resume_mode: i32,

    /// Topic name to use for timestamp-based resume evaluation.
    /// If empty, evaluate using messages from all topics.
    pub tracking_topic_name: rosidl_runtime_rs::String,

}

impl Resume_Request {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESUME_MODE_NODE_TIME: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESUME_MODE_PUBLISH_TIME: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESUME_MODE_RECEIVE_TIME: i32 = 2;

}


impl Default for Resume_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Resume_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Resume_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Resume_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Resume_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Resume_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Resume_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Resume_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Resume_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Resume_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Resume_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Resume_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Resume_Response__init(msg: *mut Resume_Response) -> bool;
    fn rosbag2_interfaces__srv__Resume_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Resume_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Resume_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Resume_Response>);
    fn rosbag2_interfaces__srv__Resume_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Resume_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Resume_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Resume_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Resume_Response {
    /// Return code. Use RETURN_CODE_SUCCESS on success; otherwise use one of the error codes.
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: rosidl_runtime_rs::String,

}

impl Resume_Response {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_SUCCESS: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_INVALID_RESUME_MODE: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_INVALID_TRACKING_TOPIC: i32 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_RESUME_FAILED: i32 = 3;

}


impl Default for Resume_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Resume_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Resume_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Resume_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Resume_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Resume_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Resume_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Resume_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Resume_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Resume_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Resume_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Seek_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Seek_Request__init(msg: *mut Seek_Request) -> bool;
    fn rosbag2_interfaces__srv__Seek_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Seek_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Seek_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Seek_Request>);
    fn rosbag2_interfaces__srv__Seek_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Seek_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Seek_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Seek_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Seek_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub time: builtin_interfaces::msg::rmw::Time,

}



impl Default for Seek_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Seek_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Seek_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Seek_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Seek_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Seek_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Seek_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Seek_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Seek_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Seek_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Seek_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Seek_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Seek_Response__init(msg: *mut Seek_Response) -> bool;
    fn rosbag2_interfaces__srv__Seek_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Seek_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Seek_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Seek_Response>);
    fn rosbag2_interfaces__srv__Seek_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Seek_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Seek_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Seek_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Seek_Response {
    /// return true if valid time in bag duration, and successful seek
    pub success: bool,

}



impl Default for Seek_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Seek_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Seek_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Seek_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Seek_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Seek_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Seek_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Seek_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Seek_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Seek_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Seek_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__SetRate_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__SetRate_Request__init(msg: *mut SetRate_Request) -> bool;
    fn rosbag2_interfaces__srv__SetRate_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetRate_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__SetRate_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetRate_Request>);
    fn rosbag2_interfaces__srv__SetRate_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetRate_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetRate_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__SetRate_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetRate_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub rate: f64,

}



impl Default for SetRate_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__SetRate_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__SetRate_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetRate_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SetRate_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SetRate_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SetRate_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetRate_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetRate_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/SetRate_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__SetRate_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__SetRate_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__SetRate_Response__init(msg: *mut SetRate_Response) -> bool;
    fn rosbag2_interfaces__srv__SetRate_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetRate_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__SetRate_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetRate_Response>);
    fn rosbag2_interfaces__srv__SetRate_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetRate_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetRate_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__SetRate_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetRate_Response {
    /// true if valid rate (> 0) was set
    pub success: bool,

}



impl Default for SetRate_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__SetRate_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__SetRate_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetRate_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SetRate_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SetRate_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SetRate_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetRate_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetRate_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/SetRate_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__SetRate_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Snapshot_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Snapshot_Request__init(msg: *mut Snapshot_Request) -> bool;
    fn rosbag2_interfaces__srv__Snapshot_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Snapshot_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Snapshot_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Snapshot_Request>);
    fn rosbag2_interfaces__srv__Snapshot_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Snapshot_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Snapshot_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Snapshot_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Snapshot_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Snapshot_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Snapshot_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Snapshot_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Snapshot_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Snapshot_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Snapshot_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Snapshot_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Snapshot_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Snapshot_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Snapshot_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Snapshot_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Snapshot_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Snapshot_Response__init(msg: *mut Snapshot_Response) -> bool;
    fn rosbag2_interfaces__srv__Snapshot_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Snapshot_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Snapshot_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Snapshot_Response>);
    fn rosbag2_interfaces__srv__Snapshot_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Snapshot_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Snapshot_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Snapshot_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Snapshot_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Snapshot_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Snapshot_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Snapshot_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Snapshot_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Snapshot_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Snapshot_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Snapshot_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Snapshot_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Snapshot_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Snapshot_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Snapshot_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__SplitBagfile_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__SplitBagfile_Request__init(msg: *mut SplitBagfile_Request) -> bool;
    fn rosbag2_interfaces__srv__SplitBagfile_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SplitBagfile_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__SplitBagfile_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SplitBagfile_Request>);
    fn rosbag2_interfaces__srv__SplitBagfile_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SplitBagfile_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SplitBagfile_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__SplitBagfile_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SplitBagfile_Request {
    /// Timestamp in the future when to split bag file.
    /// If empty or time in the past, split bag file immediately.
    pub split_time: builtin_interfaces::msg::rmw::Time,

    /// Split mode to use for the split_time request.
    pub split_mode: i32,

    /// Topic name to use for timestamp-based split evaluation.
    /// If empty, evaluate using messages from all topics.
    pub tracking_topic_name: rosidl_runtime_rs::String,

}

impl SplitBagfile_Request {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPLIT_MODE_NODE_TIME: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPLIT_MODE_PUBLISH_TIME: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPLIT_MODE_RECEIVE_TIME: i32 = 2;

}


impl Default for SplitBagfile_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__SplitBagfile_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__SplitBagfile_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SplitBagfile_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SplitBagfile_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SplitBagfile_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SplitBagfile_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SplitBagfile_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SplitBagfile_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/SplitBagfile_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__SplitBagfile_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__SplitBagfile_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__SplitBagfile_Response__init(msg: *mut SplitBagfile_Response) -> bool;
    fn rosbag2_interfaces__srv__SplitBagfile_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SplitBagfile_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__SplitBagfile_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SplitBagfile_Response>);
    fn rosbag2_interfaces__srv__SplitBagfile_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SplitBagfile_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SplitBagfile_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__SplitBagfile_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SplitBagfile_Response {
    /// Return code. Use RETURN_CODE_SUCCESS on success; otherwise use one of the error codes.
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: rosidl_runtime_rs::String,

}

impl SplitBagfile_Response {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_SUCCESS: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_NOT_RECORDING: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_INVALID_SPLIT_MODE: i32 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_INVALID_TRACKING_TOPIC: i32 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_SPLIT_FAILED: i32 = 4;

}


impl Default for SplitBagfile_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__SplitBagfile_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__SplitBagfile_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SplitBagfile_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SplitBagfile_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SplitBagfile_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__SplitBagfile_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SplitBagfile_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SplitBagfile_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/SplitBagfile_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__SplitBagfile_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__StartDiscovery_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__StartDiscovery_Request__init(msg: *mut StartDiscovery_Request) -> bool;
    fn rosbag2_interfaces__srv__StartDiscovery_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StartDiscovery_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__StartDiscovery_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StartDiscovery_Request>);
    fn rosbag2_interfaces__srv__StartDiscovery_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StartDiscovery_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<StartDiscovery_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__StartDiscovery_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StartDiscovery_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for StartDiscovery_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__StartDiscovery_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__StartDiscovery_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StartDiscovery_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StartDiscovery_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StartDiscovery_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StartDiscovery_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StartDiscovery_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StartDiscovery_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/StartDiscovery_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__StartDiscovery_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__StartDiscovery_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__StartDiscovery_Response__init(msg: *mut StartDiscovery_Response) -> bool;
    fn rosbag2_interfaces__srv__StartDiscovery_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StartDiscovery_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__StartDiscovery_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StartDiscovery_Response>);
    fn rosbag2_interfaces__srv__StartDiscovery_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StartDiscovery_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<StartDiscovery_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__StartDiscovery_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StartDiscovery_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: rosidl_runtime_rs::String,

}



impl Default for StartDiscovery_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__StartDiscovery_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__StartDiscovery_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StartDiscovery_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StartDiscovery_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StartDiscovery_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StartDiscovery_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StartDiscovery_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StartDiscovery_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/StartDiscovery_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__StartDiscovery_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Stop_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Stop_Request__init(msg: *mut Stop_Request) -> bool;
    fn rosbag2_interfaces__srv__Stop_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Stop_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Stop_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Stop_Request>);
    fn rosbag2_interfaces__srv__Stop_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Stop_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Stop_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Stop_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Stop_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Stop_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Stop_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Stop_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Stop_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Stop_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Stop_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Stop_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Stop_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Stop_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Stop_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Stop_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Stop_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__Stop_Response__init(msg: *mut Stop_Response) -> bool;
    fn rosbag2_interfaces__srv__Stop_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Stop_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__Stop_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Stop_Response>);
    fn rosbag2_interfaces__srv__Stop_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Stop_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Stop_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__Stop_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Stop_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: rosidl_runtime_rs::String,

}



impl Default for Stop_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__Stop_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__Stop_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Stop_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Stop_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Stop_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__Stop_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Stop_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Stop_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/Stop_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__Stop_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__StopDiscovery_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__StopDiscovery_Request__init(msg: *mut StopDiscovery_Request) -> bool;
    fn rosbag2_interfaces__srv__StopDiscovery_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StopDiscovery_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__StopDiscovery_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StopDiscovery_Request>);
    fn rosbag2_interfaces__srv__StopDiscovery_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StopDiscovery_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<StopDiscovery_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__StopDiscovery_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StopDiscovery_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for StopDiscovery_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__StopDiscovery_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__StopDiscovery_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StopDiscovery_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StopDiscovery_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StopDiscovery_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StopDiscovery_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StopDiscovery_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StopDiscovery_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/StopDiscovery_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__StopDiscovery_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__StopDiscovery_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__StopDiscovery_Response__init(msg: *mut StopDiscovery_Response) -> bool;
    fn rosbag2_interfaces__srv__StopDiscovery_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StopDiscovery_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__StopDiscovery_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StopDiscovery_Response>);
    fn rosbag2_interfaces__srv__StopDiscovery_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StopDiscovery_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<StopDiscovery_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__StopDiscovery_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StopDiscovery_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: rosidl_runtime_rs::String,

}



impl Default for StopDiscovery_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__StopDiscovery_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__StopDiscovery_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StopDiscovery_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StopDiscovery_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StopDiscovery_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__StopDiscovery_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StopDiscovery_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StopDiscovery_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/StopDiscovery_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__StopDiscovery_Response() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__TogglePaused_Request() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__TogglePaused_Request__init(msg: *mut TogglePaused_Request) -> bool;
    fn rosbag2_interfaces__srv__TogglePaused_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TogglePaused_Request>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__TogglePaused_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TogglePaused_Request>);
    fn rosbag2_interfaces__srv__TogglePaused_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TogglePaused_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<TogglePaused_Request>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__TogglePaused_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TogglePaused_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for TogglePaused_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__TogglePaused_Request__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__TogglePaused_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TogglePaused_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__TogglePaused_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__TogglePaused_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__TogglePaused_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TogglePaused_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TogglePaused_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/TogglePaused_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__TogglePaused_Request() }
  }
}


#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__TogglePaused_Response() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_interfaces__rosidl_generator_c")]
extern "C" {
    fn rosbag2_interfaces__srv__TogglePaused_Response__init(msg: *mut TogglePaused_Response) -> bool;
    fn rosbag2_interfaces__srv__TogglePaused_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TogglePaused_Response>, size: usize) -> bool;
    fn rosbag2_interfaces__srv__TogglePaused_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TogglePaused_Response>);
    fn rosbag2_interfaces__srv__TogglePaused_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TogglePaused_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<TogglePaused_Response>) -> bool;
}

// Corresponds to rosbag2_interfaces__srv__TogglePaused_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TogglePaused_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for TogglePaused_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_interfaces__srv__TogglePaused_Response__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_interfaces__srv__TogglePaused_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TogglePaused_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__TogglePaused_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__TogglePaused_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_interfaces__srv__TogglePaused_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TogglePaused_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TogglePaused_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_interfaces/srv/TogglePaused_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_interfaces__srv__TogglePaused_Response() }
  }
}






#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Burst() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Burst
#[allow(missing_docs, non_camel_case_types)]
pub struct Burst;

impl rosidl_runtime_rs::Service for Burst {
    type Request = Burst_Request;
    type Response = Burst_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Burst() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__GetRate() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__GetRate
#[allow(missing_docs, non_camel_case_types)]
pub struct GetRate;

impl rosidl_runtime_rs::Service for GetRate {
    type Request = GetRate_Request;
    type Response = GetRate_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__GetRate() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__GetSubscribedTopics() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__GetSubscribedTopics
#[allow(missing_docs, non_camel_case_types)]
pub struct GetSubscribedTopics;

impl rosidl_runtime_rs::Service for GetSubscribedTopics {
    type Request = GetSubscribedTopics_Request;
    type Response = GetSubscribedTopics_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__GetSubscribedTopics() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__IsDiscoveryRunning() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__IsDiscoveryRunning
#[allow(missing_docs, non_camel_case_types)]
pub struct IsDiscoveryRunning;

impl rosidl_runtime_rs::Service for IsDiscoveryRunning {
    type Request = IsDiscoveryRunning_Request;
    type Response = IsDiscoveryRunning_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__IsDiscoveryRunning() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__IsPaused() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__IsPaused
#[allow(missing_docs, non_camel_case_types)]
pub struct IsPaused;

impl rosidl_runtime_rs::Service for IsPaused {
    type Request = IsPaused_Request;
    type Response = IsPaused_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__IsPaused() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Pause() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Pause
#[allow(missing_docs, non_camel_case_types)]
pub struct Pause;

impl rosidl_runtime_rs::Service for Pause {
    type Request = Pause_Request;
    type Response = Pause_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Pause() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Play() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Play
#[allow(missing_docs, non_camel_case_types)]
pub struct Play;

impl rosidl_runtime_rs::Service for Play {
    type Request = Play_Request;
    type Response = Play_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Play() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__PlayNext() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__PlayNext
#[allow(missing_docs, non_camel_case_types)]
pub struct PlayNext;

impl rosidl_runtime_rs::Service for PlayNext {
    type Request = PlayNext_Request;
    type Response = PlayNext_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__PlayNext() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Record() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Record
#[allow(missing_docs, non_camel_case_types)]
pub struct Record;

impl rosidl_runtime_rs::Service for Record {
    type Request = Record_Request;
    type Response = Record_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Record() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Resume() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Resume
#[allow(missing_docs, non_camel_case_types)]
pub struct Resume;

impl rosidl_runtime_rs::Service for Resume {
    type Request = Resume_Request;
    type Response = Resume_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Resume() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Seek() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Seek
#[allow(missing_docs, non_camel_case_types)]
pub struct Seek;

impl rosidl_runtime_rs::Service for Seek {
    type Request = Seek_Request;
    type Response = Seek_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Seek() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__SetRate() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__SetRate
#[allow(missing_docs, non_camel_case_types)]
pub struct SetRate;

impl rosidl_runtime_rs::Service for SetRate {
    type Request = SetRate_Request;
    type Response = SetRate_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__SetRate() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Snapshot() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Snapshot
#[allow(missing_docs, non_camel_case_types)]
pub struct Snapshot;

impl rosidl_runtime_rs::Service for Snapshot {
    type Request = Snapshot_Request;
    type Response = Snapshot_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Snapshot() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__SplitBagfile() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__SplitBagfile
#[allow(missing_docs, non_camel_case_types)]
pub struct SplitBagfile;

impl rosidl_runtime_rs::Service for SplitBagfile {
    type Request = SplitBagfile_Request;
    type Response = SplitBagfile_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__SplitBagfile() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__StartDiscovery() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__StartDiscovery
#[allow(missing_docs, non_camel_case_types)]
pub struct StartDiscovery;

impl rosidl_runtime_rs::Service for StartDiscovery {
    type Request = StartDiscovery_Request;
    type Response = StartDiscovery_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__StartDiscovery() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Stop() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Stop
#[allow(missing_docs, non_camel_case_types)]
pub struct Stop;

impl rosidl_runtime_rs::Service for Stop {
    type Request = Stop_Request;
    type Response = Stop_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Stop() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__StopDiscovery() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__StopDiscovery
#[allow(missing_docs, non_camel_case_types)]
pub struct StopDiscovery;

impl rosidl_runtime_rs::Service for StopDiscovery {
    type Request = StopDiscovery_Request;
    type Response = StopDiscovery_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__StopDiscovery() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__TogglePaused() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__TogglePaused
#[allow(missing_docs, non_camel_case_types)]
pub struct TogglePaused;

impl rosidl_runtime_rs::Service for TogglePaused {
    type Request = TogglePaused_Request;
    type Response = TogglePaused_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__TogglePaused() }
    }
}


