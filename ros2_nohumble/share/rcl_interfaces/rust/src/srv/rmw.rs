#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__DescribeParameters_Request() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__DescribeParameters_Request__init(msg: *mut DescribeParameters_Request) -> bool;
    fn rcl_interfaces__srv__DescribeParameters_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DescribeParameters_Request>, size: usize) -> bool;
    fn rcl_interfaces__srv__DescribeParameters_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DescribeParameters_Request>);
    fn rcl_interfaces__srv__DescribeParameters_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DescribeParameters_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<DescribeParameters_Request>) -> bool;
}

// Corresponds to rcl_interfaces__srv__DescribeParameters_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DescribeParameters_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub names: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for DescribeParameters_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__DescribeParameters_Request__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__DescribeParameters_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DescribeParameters_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__DescribeParameters_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__DescribeParameters_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__DescribeParameters_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DescribeParameters_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DescribeParameters_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/DescribeParameters_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__DescribeParameters_Request() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__DescribeParameters_Response() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__DescribeParameters_Response__init(msg: *mut DescribeParameters_Response) -> bool;
    fn rcl_interfaces__srv__DescribeParameters_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DescribeParameters_Response>, size: usize) -> bool;
    fn rcl_interfaces__srv__DescribeParameters_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DescribeParameters_Response>);
    fn rcl_interfaces__srv__DescribeParameters_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DescribeParameters_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<DescribeParameters_Response>) -> bool;
}

// Corresponds to rcl_interfaces__srv__DescribeParameters_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DescribeParameters_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub descriptors: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ParameterDescriptor>,

}



impl Default for DescribeParameters_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__DescribeParameters_Response__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__DescribeParameters_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DescribeParameters_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__DescribeParameters_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__DescribeParameters_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__DescribeParameters_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DescribeParameters_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DescribeParameters_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/DescribeParameters_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__DescribeParameters_Response() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetParameters_Request() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__GetParameters_Request__init(msg: *mut GetParameters_Request) -> bool;
    fn rcl_interfaces__srv__GetParameters_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Request>, size: usize) -> bool;
    fn rcl_interfaces__srv__GetParameters_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Request>);
    fn rcl_interfaces__srv__GetParameters_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetParameters_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Request>) -> bool;
}

// Corresponds to rcl_interfaces__srv__GetParameters_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetParameters_Request {
    /// A list of parameter names to get.
    pub names: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for GetParameters_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__GetParameters_Request__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__GetParameters_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetParameters_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameters_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameters_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameters_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetParameters_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetParameters_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/GetParameters_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetParameters_Request() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetParameters_Response() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__GetParameters_Response__init(msg: *mut GetParameters_Response) -> bool;
    fn rcl_interfaces__srv__GetParameters_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Response>, size: usize) -> bool;
    fn rcl_interfaces__srv__GetParameters_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Response>);
    fn rcl_interfaces__srv__GetParameters_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetParameters_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Response>) -> bool;
}

// Corresponds to rcl_interfaces__srv__GetParameters_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetParameters_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub values: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ParameterValue>,

}



impl Default for GetParameters_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__GetParameters_Response__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__GetParameters_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetParameters_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameters_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameters_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameters_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetParameters_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetParameters_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/GetParameters_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetParameters_Response() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetParameterTypes_Request() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__GetParameterTypes_Request__init(msg: *mut GetParameterTypes_Request) -> bool;
    fn rcl_interfaces__srv__GetParameterTypes_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetParameterTypes_Request>, size: usize) -> bool;
    fn rcl_interfaces__srv__GetParameterTypes_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetParameterTypes_Request>);
    fn rcl_interfaces__srv__GetParameterTypes_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetParameterTypes_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetParameterTypes_Request>) -> bool;
}

// Corresponds to rcl_interfaces__srv__GetParameterTypes_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetParameterTypes_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub names: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for GetParameterTypes_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__GetParameterTypes_Request__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__GetParameterTypes_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetParameterTypes_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameterTypes_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameterTypes_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameterTypes_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetParameterTypes_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetParameterTypes_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/GetParameterTypes_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetParameterTypes_Request() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetParameterTypes_Response() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__GetParameterTypes_Response__init(msg: *mut GetParameterTypes_Response) -> bool;
    fn rcl_interfaces__srv__GetParameterTypes_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetParameterTypes_Response>, size: usize) -> bool;
    fn rcl_interfaces__srv__GetParameterTypes_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetParameterTypes_Response>);
    fn rcl_interfaces__srv__GetParameterTypes_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetParameterTypes_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetParameterTypes_Response>) -> bool;
}

// Corresponds to rcl_interfaces__srv__GetParameterTypes_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetParameterTypes_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub types: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for GetParameterTypes_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__GetParameterTypes_Response__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__GetParameterTypes_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetParameterTypes_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameterTypes_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameterTypes_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetParameterTypes_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetParameterTypes_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetParameterTypes_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/GetParameterTypes_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetParameterTypes_Response() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__ListParameters_Request() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__ListParameters_Request__init(msg: *mut ListParameters_Request) -> bool;
    fn rcl_interfaces__srv__ListParameters_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ListParameters_Request>, size: usize) -> bool;
    fn rcl_interfaces__srv__ListParameters_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ListParameters_Request>);
    fn rcl_interfaces__srv__ListParameters_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ListParameters_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ListParameters_Request>) -> bool;
}

// Corresponds to rcl_interfaces__srv__ListParameters_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ListParameters_Request {
    /// The list of parameter prefixes to query.
    pub prefixes: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// Relative depth from given prefixes to return.
    ///
    /// Use DEPTH_RECURSIVE to get the recursive parameters and prefixes for each prefix.
    pub depth: u64,

}

impl ListParameters_Request {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DEPTH_RECURSIVE: u64 = 0;

}


impl Default for ListParameters_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__ListParameters_Request__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__ListParameters_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ListParameters_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__ListParameters_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__ListParameters_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__ListParameters_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ListParameters_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ListParameters_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/ListParameters_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__ListParameters_Request() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__ListParameters_Response() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__ListParameters_Response__init(msg: *mut ListParameters_Response) -> bool;
    fn rcl_interfaces__srv__ListParameters_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ListParameters_Response>, size: usize) -> bool;
    fn rcl_interfaces__srv__ListParameters_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ListParameters_Response>);
    fn rcl_interfaces__srv__ListParameters_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ListParameters_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ListParameters_Response>) -> bool;
}

// Corresponds to rcl_interfaces__srv__ListParameters_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ListParameters_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::msg::rmw::ListParametersResult,

}



impl Default for ListParameters_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__ListParameters_Response__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__ListParameters_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ListParameters_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__ListParameters_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__ListParameters_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__ListParameters_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ListParameters_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ListParameters_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/ListParameters_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__ListParameters_Response() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetParametersAtomically_Request() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__SetParametersAtomically_Request__init(msg: *mut SetParametersAtomically_Request) -> bool;
    fn rcl_interfaces__srv__SetParametersAtomically_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetParametersAtomically_Request>, size: usize) -> bool;
    fn rcl_interfaces__srv__SetParametersAtomically_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetParametersAtomically_Request>);
    fn rcl_interfaces__srv__SetParametersAtomically_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetParametersAtomically_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetParametersAtomically_Request>) -> bool;
}

// Corresponds to rcl_interfaces__srv__SetParametersAtomically_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetParametersAtomically_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub parameters: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Parameter>,

}



impl Default for SetParametersAtomically_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__SetParametersAtomically_Request__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__SetParametersAtomically_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetParametersAtomically_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParametersAtomically_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParametersAtomically_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParametersAtomically_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetParametersAtomically_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetParametersAtomically_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/SetParametersAtomically_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetParametersAtomically_Request() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetParametersAtomically_Response() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__SetParametersAtomically_Response__init(msg: *mut SetParametersAtomically_Response) -> bool;
    fn rcl_interfaces__srv__SetParametersAtomically_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetParametersAtomically_Response>, size: usize) -> bool;
    fn rcl_interfaces__srv__SetParametersAtomically_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetParametersAtomically_Response>);
    fn rcl_interfaces__srv__SetParametersAtomically_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetParametersAtomically_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetParametersAtomically_Response>) -> bool;
}

// Corresponds to rcl_interfaces__srv__SetParametersAtomically_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetParametersAtomically_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::msg::rmw::SetParametersResult,

}



impl Default for SetParametersAtomically_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__SetParametersAtomically_Response__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__SetParametersAtomically_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetParametersAtomically_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParametersAtomically_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParametersAtomically_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParametersAtomically_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetParametersAtomically_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetParametersAtomically_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/SetParametersAtomically_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetParametersAtomically_Response() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetParameters_Request() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__SetParameters_Request__init(msg: *mut SetParameters_Request) -> bool;
    fn rcl_interfaces__srv__SetParameters_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetParameters_Request>, size: usize) -> bool;
    fn rcl_interfaces__srv__SetParameters_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetParameters_Request>);
    fn rcl_interfaces__srv__SetParameters_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetParameters_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetParameters_Request>) -> bool;
}

// Corresponds to rcl_interfaces__srv__SetParameters_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetParameters_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub parameters: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Parameter>,

}



impl Default for SetParameters_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__SetParameters_Request__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__SetParameters_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetParameters_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParameters_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParameters_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParameters_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetParameters_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetParameters_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/SetParameters_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetParameters_Request() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetParameters_Response() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__SetParameters_Response__init(msg: *mut SetParameters_Response) -> bool;
    fn rcl_interfaces__srv__SetParameters_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetParameters_Response>, size: usize) -> bool;
    fn rcl_interfaces__srv__SetParameters_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetParameters_Response>);
    fn rcl_interfaces__srv__SetParameters_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetParameters_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetParameters_Response>) -> bool;
}

// Corresponds to rcl_interfaces__srv__SetParameters_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetParameters_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub results: rosidl_runtime_rs::Sequence<super::super::msg::rmw::SetParametersResult>,

}



impl Default for SetParameters_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__SetParameters_Response__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__SetParameters_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetParameters_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParameters_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParameters_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetParameters_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetParameters_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetParameters_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/SetParameters_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetParameters_Response() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetLoggerLevels_Request() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__GetLoggerLevels_Request__init(msg: *mut GetLoggerLevels_Request) -> bool;
    fn rcl_interfaces__srv__GetLoggerLevels_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetLoggerLevels_Request>, size: usize) -> bool;
    fn rcl_interfaces__srv__GetLoggerLevels_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetLoggerLevels_Request>);
    fn rcl_interfaces__srv__GetLoggerLevels_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetLoggerLevels_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetLoggerLevels_Request>) -> bool;
}

// Corresponds to rcl_interfaces__srv__GetLoggerLevels_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetLoggerLevels_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub names: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for GetLoggerLevels_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__GetLoggerLevels_Request__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__GetLoggerLevels_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetLoggerLevels_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetLoggerLevels_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetLoggerLevels_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetLoggerLevels_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetLoggerLevels_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetLoggerLevels_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/GetLoggerLevels_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetLoggerLevels_Request() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetLoggerLevels_Response() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__GetLoggerLevels_Response__init(msg: *mut GetLoggerLevels_Response) -> bool;
    fn rcl_interfaces__srv__GetLoggerLevels_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetLoggerLevels_Response>, size: usize) -> bool;
    fn rcl_interfaces__srv__GetLoggerLevels_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetLoggerLevels_Response>);
    fn rcl_interfaces__srv__GetLoggerLevels_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetLoggerLevels_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetLoggerLevels_Response>) -> bool;
}

// Corresponds to rcl_interfaces__srv__GetLoggerLevels_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetLoggerLevels_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub levels: rosidl_runtime_rs::Sequence<super::super::msg::rmw::LoggerLevel>,

}



impl Default for GetLoggerLevels_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__GetLoggerLevels_Response__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__GetLoggerLevels_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetLoggerLevels_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetLoggerLevels_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetLoggerLevels_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__GetLoggerLevels_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetLoggerLevels_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetLoggerLevels_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/GetLoggerLevels_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__GetLoggerLevels_Response() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetLoggerLevels_Request() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__SetLoggerLevels_Request__init(msg: *mut SetLoggerLevels_Request) -> bool;
    fn rcl_interfaces__srv__SetLoggerLevels_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetLoggerLevels_Request>, size: usize) -> bool;
    fn rcl_interfaces__srv__SetLoggerLevels_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetLoggerLevels_Request>);
    fn rcl_interfaces__srv__SetLoggerLevels_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetLoggerLevels_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetLoggerLevels_Request>) -> bool;
}

// Corresponds to rcl_interfaces__srv__SetLoggerLevels_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetLoggerLevels_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub levels: rosidl_runtime_rs::Sequence<super::super::msg::rmw::LoggerLevel>,

}



impl Default for SetLoggerLevels_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__SetLoggerLevels_Request__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__SetLoggerLevels_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetLoggerLevels_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetLoggerLevels_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetLoggerLevels_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetLoggerLevels_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetLoggerLevels_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetLoggerLevels_Request where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/SetLoggerLevels_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetLoggerLevels_Request() }
  }
}


#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetLoggerLevels_Response() -> *const std::ffi::c_void;
}

#[link(name = "rcl_interfaces__rosidl_generator_c")]
extern "C" {
    fn rcl_interfaces__srv__SetLoggerLevels_Response__init(msg: *mut SetLoggerLevels_Response) -> bool;
    fn rcl_interfaces__srv__SetLoggerLevels_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetLoggerLevels_Response>, size: usize) -> bool;
    fn rcl_interfaces__srv__SetLoggerLevels_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetLoggerLevels_Response>);
    fn rcl_interfaces__srv__SetLoggerLevels_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetLoggerLevels_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetLoggerLevels_Response>) -> bool;
}

// Corresponds to rcl_interfaces__srv__SetLoggerLevels_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetLoggerLevels_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub results: rosidl_runtime_rs::Sequence<super::super::msg::rmw::SetLoggerLevelsResult>,

}



impl Default for SetLoggerLevels_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rcl_interfaces__srv__SetLoggerLevels_Response__init(&mut msg as *mut _) {
        panic!("Call to rcl_interfaces__srv__SetLoggerLevels_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetLoggerLevels_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetLoggerLevels_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetLoggerLevels_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rcl_interfaces__srv__SetLoggerLevels_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetLoggerLevels_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetLoggerLevels_Response where Self: Sized {
  const TYPE_NAME: &'static str = "rcl_interfaces/srv/SetLoggerLevels_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rcl_interfaces__srv__SetLoggerLevels_Response() }
  }
}






#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__DescribeParameters() -> *const std::ffi::c_void;
}

// Corresponds to rcl_interfaces__srv__DescribeParameters
#[allow(missing_docs, non_camel_case_types)]
pub struct DescribeParameters;

impl rosidl_runtime_rs::Service for DescribeParameters {
    type Request = DescribeParameters_Request;
    type Response = DescribeParameters_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__DescribeParameters() }
    }
}




#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__GetParameters() -> *const std::ffi::c_void;
}

// Corresponds to rcl_interfaces__srv__GetParameters
#[allow(missing_docs, non_camel_case_types)]
pub struct GetParameters;

impl rosidl_runtime_rs::Service for GetParameters {
    type Request = GetParameters_Request;
    type Response = GetParameters_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__GetParameters() }
    }
}




#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__GetParameterTypes() -> *const std::ffi::c_void;
}

// Corresponds to rcl_interfaces__srv__GetParameterTypes
#[allow(missing_docs, non_camel_case_types)]
pub struct GetParameterTypes;

impl rosidl_runtime_rs::Service for GetParameterTypes {
    type Request = GetParameterTypes_Request;
    type Response = GetParameterTypes_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__GetParameterTypes() }
    }
}




#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__ListParameters() -> *const std::ffi::c_void;
}

// Corresponds to rcl_interfaces__srv__ListParameters
#[allow(missing_docs, non_camel_case_types)]
pub struct ListParameters;

impl rosidl_runtime_rs::Service for ListParameters {
    type Request = ListParameters_Request;
    type Response = ListParameters_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__ListParameters() }
    }
}




#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__SetParametersAtomically() -> *const std::ffi::c_void;
}

// Corresponds to rcl_interfaces__srv__SetParametersAtomically
#[allow(missing_docs, non_camel_case_types)]
pub struct SetParametersAtomically;

impl rosidl_runtime_rs::Service for SetParametersAtomically {
    type Request = SetParametersAtomically_Request;
    type Response = SetParametersAtomically_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__SetParametersAtomically() }
    }
}




#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__SetParameters() -> *const std::ffi::c_void;
}

// Corresponds to rcl_interfaces__srv__SetParameters
#[allow(missing_docs, non_camel_case_types)]
pub struct SetParameters;

impl rosidl_runtime_rs::Service for SetParameters {
    type Request = SetParameters_Request;
    type Response = SetParameters_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__SetParameters() }
    }
}




#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__GetLoggerLevels() -> *const std::ffi::c_void;
}

// Corresponds to rcl_interfaces__srv__GetLoggerLevels
#[allow(missing_docs, non_camel_case_types)]
pub struct GetLoggerLevels;

impl rosidl_runtime_rs::Service for GetLoggerLevels {
    type Request = GetLoggerLevels_Request;
    type Response = GetLoggerLevels_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__GetLoggerLevels() }
    }
}




#[link(name = "rcl_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__SetLoggerLevels() -> *const std::ffi::c_void;
}

// Corresponds to rcl_interfaces__srv__SetLoggerLevels
#[allow(missing_docs, non_camel_case_types)]
pub struct SetLoggerLevels;

impl rosidl_runtime_rs::Service for SetLoggerLevels {
    type Request = SetLoggerLevels_Request;
    type Response = SetLoggerLevels_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rcl_interfaces__srv__SetLoggerLevels() }
    }
}


