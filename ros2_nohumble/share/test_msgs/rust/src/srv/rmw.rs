#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__Arrays_Request() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__srv__Arrays_Request__init(msg: *mut Arrays_Request) -> bool;
    fn test_msgs__srv__Arrays_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Arrays_Request>, size: usize) -> bool;
    fn test_msgs__srv__Arrays_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Arrays_Request>);
    fn test_msgs__srv__Arrays_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Arrays_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Arrays_Request>) -> bool;
}

// Corresponds to test_msgs__srv__Arrays_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Arrays_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: [bool; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: [f32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: [f64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: [i8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: [i16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: [u16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: [i32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: [u32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: [i64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: [u64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values: [rosidl_runtime_rs::String; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: [super::super::msg::rmw::BasicTypes; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: [super::super::msg::rmw::Constants; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: [super::super::msg::rmw::Defaults; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: [bool; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: [f32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: [f64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: [i8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: [i16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: [u16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: [i32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: [u32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: [i64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: [u64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values_default: [rosidl_runtime_rs::String; 3],

}



impl Default for Arrays_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__srv__Arrays_Request__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__srv__Arrays_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Arrays_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Arrays_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Arrays_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Arrays_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Arrays_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Arrays_Request where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/srv/Arrays_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__Arrays_Request() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__Arrays_Response() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__srv__Arrays_Response__init(msg: *mut Arrays_Response) -> bool;
    fn test_msgs__srv__Arrays_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Arrays_Response>, size: usize) -> bool;
    fn test_msgs__srv__Arrays_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Arrays_Response>);
    fn test_msgs__srv__Arrays_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Arrays_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Arrays_Response>) -> bool;
}

// Corresponds to test_msgs__srv__Arrays_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Arrays_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: [bool; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: [f32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: [f64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: [i8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: [i16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: [u16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: [i32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: [u32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: [i64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: [u64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values: [rosidl_runtime_rs::String; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: [super::super::msg::rmw::BasicTypes; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: [super::super::msg::rmw::Constants; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: [super::super::msg::rmw::Defaults; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: [bool; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: [f32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: [f64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: [i8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: [u8; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: [i16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: [u16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: [i32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: [u32; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: [i64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: [u64; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values_default: [rosidl_runtime_rs::String; 3],

}



impl Default for Arrays_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__srv__Arrays_Response__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__srv__Arrays_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Arrays_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Arrays_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Arrays_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Arrays_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Arrays_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Arrays_Response where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/srv/Arrays_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__Arrays_Response() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__BasicTypes_Request() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__srv__BasicTypes_Request__init(msg: *mut BasicTypes_Request) -> bool;
    fn test_msgs__srv__BasicTypes_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicTypes_Request>, size: usize) -> bool;
    fn test_msgs__srv__BasicTypes_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicTypes_Request>);
    fn test_msgs__srv__BasicTypes_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicTypes_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicTypes_Request>) -> bool;
}

// Corresponds to test_msgs__srv__BasicTypes_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicTypes_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_value: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_value: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_value: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_value: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_value: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_value: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_value: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_value: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_value: i64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_value: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value: rosidl_runtime_rs::String,

}



impl Default for BasicTypes_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__srv__BasicTypes_Request__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__srv__BasicTypes_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicTypes_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__BasicTypes_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__BasicTypes_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__BasicTypes_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicTypes_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicTypes_Request where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/srv/BasicTypes_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__BasicTypes_Request() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__BasicTypes_Response() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__srv__BasicTypes_Response__init(msg: *mut BasicTypes_Response) -> bool;
    fn test_msgs__srv__BasicTypes_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicTypes_Response>, size: usize) -> bool;
    fn test_msgs__srv__BasicTypes_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicTypes_Response>);
    fn test_msgs__srv__BasicTypes_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicTypes_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicTypes_Response>) -> bool;
}

// Corresponds to test_msgs__srv__BasicTypes_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicTypes_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_value: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_value: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_value: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_value: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_value: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_value: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_value: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_value: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_value: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_value: i64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_value: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value: rosidl_runtime_rs::String,

}



impl Default for BasicTypes_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__srv__BasicTypes_Response__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__srv__BasicTypes_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicTypes_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__BasicTypes_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__BasicTypes_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__BasicTypes_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicTypes_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicTypes_Response where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/srv/BasicTypes_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__BasicTypes_Response() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__Empty_Request() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__srv__Empty_Request__init(msg: *mut Empty_Request) -> bool;
    fn test_msgs__srv__Empty_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Empty_Request>, size: usize) -> bool;
    fn test_msgs__srv__Empty_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Empty_Request>);
    fn test_msgs__srv__Empty_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Empty_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Empty_Request>) -> bool;
}

// Corresponds to test_msgs__srv__Empty_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Empty_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Empty_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__srv__Empty_Request__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__srv__Empty_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Empty_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Empty_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Empty_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Empty_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Empty_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Empty_Request where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/srv/Empty_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__Empty_Request() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__Empty_Response() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__srv__Empty_Response__init(msg: *mut Empty_Response) -> bool;
    fn test_msgs__srv__Empty_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Empty_Response>, size: usize) -> bool;
    fn test_msgs__srv__Empty_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Empty_Response>);
    fn test_msgs__srv__Empty_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Empty_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Empty_Response>) -> bool;
}

// Corresponds to test_msgs__srv__Empty_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Empty_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Empty_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__srv__Empty_Response__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__srv__Empty_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Empty_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Empty_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Empty_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__srv__Empty_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Empty_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Empty_Response where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/srv/Empty_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__srv__Empty_Response() }
  }
}






#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__Arrays() -> *const std::ffi::c_void;
}

// Corresponds to test_msgs__srv__Arrays
#[allow(missing_docs, non_camel_case_types)]
pub struct Arrays;

impl rosidl_runtime_rs::Service for Arrays {
    type Request = Arrays_Request;
    type Response = Arrays_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__Arrays() }
    }
}




#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__BasicTypes() -> *const std::ffi::c_void;
}

// Corresponds to test_msgs__srv__BasicTypes
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicTypes;

impl rosidl_runtime_rs::Service for BasicTypes {
    type Request = BasicTypes_Request;
    type Response = BasicTypes_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__BasicTypes() }
    }
}




#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__Empty() -> *const std::ffi::c_void;
}

// Corresponds to test_msgs__srv__Empty
#[allow(missing_docs, non_camel_case_types)]
pub struct Empty;

impl rosidl_runtime_rs::Service for Empty {
    type Request = Empty_Request;
    type Response = Empty_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__test_msgs__srv__Empty() }
    }
}


