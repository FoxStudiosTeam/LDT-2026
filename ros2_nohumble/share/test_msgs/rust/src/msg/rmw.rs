#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__KeyedLong() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__KeyedLong__init(msg: *mut KeyedLong) -> bool;
    fn test_msgs__msg__KeyedLong__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<KeyedLong>, size: usize) -> bool;
    fn test_msgs__msg__KeyedLong__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<KeyedLong>);
    fn test_msgs__msg__KeyedLong__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<KeyedLong>, out_seq: *mut rosidl_runtime_rs::Sequence<KeyedLong>) -> bool;
}

// Corresponds to test_msgs__msg__KeyedLong
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyedLong {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: i32,

}



impl Default for KeyedLong {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__KeyedLong__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__KeyedLong__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for KeyedLong {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__KeyedLong__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__KeyedLong__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__KeyedLong__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for KeyedLong {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for KeyedLong where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/KeyedLong";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__KeyedLong() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__KeyedString() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__KeyedString__init(msg: *mut KeyedString) -> bool;
    fn test_msgs__msg__KeyedString__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<KeyedString>, size: usize) -> bool;
    fn test_msgs__msg__KeyedString__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<KeyedString>);
    fn test_msgs__msg__KeyedString__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<KeyedString>, out_seq: *mut rosidl_runtime_rs::Sequence<KeyedString>) -> bool;
}

// Corresponds to test_msgs__msg__KeyedString
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyedString {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: rosidl_runtime_rs::String,

}



impl Default for KeyedString {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__KeyedString__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__KeyedString__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for KeyedString {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__KeyedString__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__KeyedString__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__KeyedString__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for KeyedString {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for KeyedString where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/KeyedString";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__KeyedString() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__NonKeyedWithNestedKey() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__NonKeyedWithNestedKey__init(msg: *mut NonKeyedWithNestedKey) -> bool;
    fn test_msgs__msg__NonKeyedWithNestedKey__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NonKeyedWithNestedKey>, size: usize) -> bool;
    fn test_msgs__msg__NonKeyedWithNestedKey__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NonKeyedWithNestedKey>);
    fn test_msgs__msg__NonKeyedWithNestedKey__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NonKeyedWithNestedKey>, out_seq: *mut rosidl_runtime_rs::Sequence<NonKeyedWithNestedKey>) -> bool;
}

// Corresponds to test_msgs__msg__NonKeyedWithNestedKey
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NonKeyedWithNestedKey {

    // This member is not documented.
    #[allow(missing_docs)]
    pub nested_data: super::super::msg::rmw::KeyedString,


    // This member is not documented.
    #[allow(missing_docs)]
    pub some_int: i32,

}



impl Default for NonKeyedWithNestedKey {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__NonKeyedWithNestedKey__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__NonKeyedWithNestedKey__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NonKeyedWithNestedKey {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__NonKeyedWithNestedKey__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__NonKeyedWithNestedKey__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__NonKeyedWithNestedKey__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NonKeyedWithNestedKey {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NonKeyedWithNestedKey where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/NonKeyedWithNestedKey";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__NonKeyedWithNestedKey() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__ComplexNestedKey() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__ComplexNestedKey__init(msg: *mut ComplexNestedKey) -> bool;
    fn test_msgs__msg__ComplexNestedKey__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComplexNestedKey>, size: usize) -> bool;
    fn test_msgs__msg__ComplexNestedKey__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComplexNestedKey>);
    fn test_msgs__msg__ComplexNestedKey__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComplexNestedKey>, out_seq: *mut rosidl_runtime_rs::Sequence<ComplexNestedKey>) -> bool;
}

// Corresponds to test_msgs__msg__ComplexNestedKey
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexNestedKey {

    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_key: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub nested_keys: super::super::msg::rmw::NonKeyedWithNestedKey,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_value: f64,

}



impl Default for ComplexNestedKey {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__ComplexNestedKey__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__ComplexNestedKey__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComplexNestedKey {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__ComplexNestedKey__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__ComplexNestedKey__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__ComplexNestedKey__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComplexNestedKey {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComplexNestedKey where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/ComplexNestedKey";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__ComplexNestedKey() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Arrays() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__Arrays__init(msg: *mut Arrays) -> bool;
    fn test_msgs__msg__Arrays__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Arrays>, size: usize) -> bool;
    fn test_msgs__msg__Arrays__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Arrays>);
    fn test_msgs__msg__Arrays__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Arrays>, out_seq: *mut rosidl_runtime_rs::Sequence<Arrays>) -> bool;
}

// Corresponds to test_msgs__msg__Arrays
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Arrays of different types

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Arrays {

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

    /// Regression test: check alignment of basic field after an array field is correct
    pub alignment_check: i32,

}



impl Default for Arrays {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__Arrays__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__Arrays__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Arrays {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Arrays__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Arrays__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Arrays__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Arrays {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Arrays where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/Arrays";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Arrays() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__BasicTypes() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__BasicTypes__init(msg: *mut BasicTypes) -> bool;
    fn test_msgs__msg__BasicTypes__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BasicTypes>, size: usize) -> bool;
    fn test_msgs__msg__BasicTypes__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BasicTypes>);
    fn test_msgs__msg__BasicTypes__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BasicTypes>, out_seq: *mut rosidl_runtime_rs::Sequence<BasicTypes>) -> bool;
}

// Corresponds to test_msgs__msg__BasicTypes
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicTypes {

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

}



impl Default for BasicTypes {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__BasicTypes__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__BasicTypes__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BasicTypes {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BasicTypes__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BasicTypes__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BasicTypes__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BasicTypes {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BasicTypes where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/BasicTypes";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__BasicTypes() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__BoundedPlainSequences() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__BoundedPlainSequences__init(msg: *mut BoundedPlainSequences) -> bool;
    fn test_msgs__msg__BoundedPlainSequences__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BoundedPlainSequences>, size: usize) -> bool;
    fn test_msgs__msg__BoundedPlainSequences__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BoundedPlainSequences>);
    fn test_msgs__msg__BoundedPlainSequences__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BoundedPlainSequences>, out_seq: *mut rosidl_runtime_rs::Sequence<BoundedPlainSequences>) -> bool;
}

// Corresponds to test_msgs__msg__BoundedPlainSequences
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Bounded sequences of different POD types

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundedPlainSequences {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: rosidl_runtime_rs::BoundedSequence<bool, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: rosidl_runtime_rs::BoundedSequence<f32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: rosidl_runtime_rs::BoundedSequence<i8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: rosidl_runtime_rs::BoundedSequence<i16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: rosidl_runtime_rs::BoundedSequence<u16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: rosidl_runtime_rs::BoundedSequence<i32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: rosidl_runtime_rs::BoundedSequence<u32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: rosidl_runtime_rs::BoundedSequence<i64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: rosidl_runtime_rs::BoundedSequence<u64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::BasicTypes, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::Constants, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::Defaults, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: rosidl_runtime_rs::BoundedSequence<bool, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: rosidl_runtime_rs::BoundedSequence<f32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: rosidl_runtime_rs::BoundedSequence<i8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: rosidl_runtime_rs::BoundedSequence<i16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: rosidl_runtime_rs::BoundedSequence<u16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: rosidl_runtime_rs::BoundedSequence<i32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: rosidl_runtime_rs::BoundedSequence<u32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: rosidl_runtime_rs::BoundedSequence<i64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: rosidl_runtime_rs::BoundedSequence<u64, 3>,

    /// Regression test: check alignment of basic field after a sequence field is correct
    pub alignment_check: i32,

}



impl Default for BoundedPlainSequences {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__BoundedPlainSequences__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__BoundedPlainSequences__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BoundedPlainSequences {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BoundedPlainSequences__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BoundedPlainSequences__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BoundedPlainSequences__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BoundedPlainSequences {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BoundedPlainSequences where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/BoundedPlainSequences";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__BoundedPlainSequences() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__BoundedSequences() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__BoundedSequences__init(msg: *mut BoundedSequences) -> bool;
    fn test_msgs__msg__BoundedSequences__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BoundedSequences>, size: usize) -> bool;
    fn test_msgs__msg__BoundedSequences__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BoundedSequences>);
    fn test_msgs__msg__BoundedSequences__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BoundedSequences>, out_seq: *mut rosidl_runtime_rs::Sequence<BoundedSequences>) -> bool;
}

// Corresponds to test_msgs__msg__BoundedSequences
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Bounded sequences of different types

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundedSequences {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: rosidl_runtime_rs::BoundedSequence<bool, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: rosidl_runtime_rs::BoundedSequence<f32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: rosidl_runtime_rs::BoundedSequence<i8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: rosidl_runtime_rs::BoundedSequence<i16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: rosidl_runtime_rs::BoundedSequence<u16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: rosidl_runtime_rs::BoundedSequence<i32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: rosidl_runtime_rs::BoundedSequence<u32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: rosidl_runtime_rs::BoundedSequence<i64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: rosidl_runtime_rs::BoundedSequence<u64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values: rosidl_runtime_rs::BoundedSequence<rosidl_runtime_rs::String, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::BasicTypes, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::Constants, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::Defaults, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: rosidl_runtime_rs::BoundedSequence<bool, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: rosidl_runtime_rs::BoundedSequence<f32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: rosidl_runtime_rs::BoundedSequence<i8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: rosidl_runtime_rs::BoundedSequence<u8, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: rosidl_runtime_rs::BoundedSequence<i16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: rosidl_runtime_rs::BoundedSequence<u16, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: rosidl_runtime_rs::BoundedSequence<i32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: rosidl_runtime_rs::BoundedSequence<u32, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: rosidl_runtime_rs::BoundedSequence<i64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: rosidl_runtime_rs::BoundedSequence<u64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values_default: rosidl_runtime_rs::BoundedSequence<rosidl_runtime_rs::String, 3>,

    /// Regression test: check alignment of basic field after a sequence field is correct
    pub alignment_check: i32,

}



impl Default for BoundedSequences {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__BoundedSequences__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__BoundedSequences__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BoundedSequences {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BoundedSequences__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BoundedSequences__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__BoundedSequences__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BoundedSequences {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BoundedSequences where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/BoundedSequences";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__BoundedSequences() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Constants() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__Constants__init(msg: *mut Constants) -> bool;
    fn test_msgs__msg__Constants__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Constants>, size: usize) -> bool;
    fn test_msgs__msg__Constants__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Constants>);
    fn test_msgs__msg__Constants__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Constants>, out_seq: *mut rosidl_runtime_rs::Sequence<Constants>) -> bool;
}

// Corresponds to test_msgs__msg__Constants
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Constants {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}

impl Constants {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BOOL_CONST: bool = true;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BYTE_CONST: u8 = 50;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CHAR_CONST: u8 = 100;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FLOAT32_CONST: f32 = 1.125;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FLOAT64_CONST: f64 = 1.125;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INT8_CONST: i8 = -50;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UINT8_CONST: u8 = 200;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INT16_CONST: i16 = -1000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UINT16_CONST: u16 = 2000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INT32_CONST: i32 = -30000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UINT32_CONST: u32 = 60000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INT64_CONST: i64 = -40000000;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UINT64_CONST: u64 = 50000000;

}


impl Default for Constants {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__Constants__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__Constants__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Constants {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Constants__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Constants__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Constants__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Constants {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Constants where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/Constants";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Constants() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Defaults() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__Defaults__init(msg: *mut Defaults) -> bool;
    fn test_msgs__msg__Defaults__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Defaults>, size: usize) -> bool;
    fn test_msgs__msg__Defaults__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Defaults>);
    fn test_msgs__msg__Defaults__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Defaults>, out_seq: *mut rosidl_runtime_rs::Sequence<Defaults>) -> bool;
}

// Corresponds to test_msgs__msg__Defaults
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Defaults {

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

}



impl Default for Defaults {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__Defaults__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__Defaults__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Defaults {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Defaults__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Defaults__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Defaults__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Defaults {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Defaults where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/Defaults";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Defaults() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Empty() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__Empty__init(msg: *mut Empty) -> bool;
    fn test_msgs__msg__Empty__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Empty>, size: usize) -> bool;
    fn test_msgs__msg__Empty__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Empty>);
    fn test_msgs__msg__Empty__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Empty>, out_seq: *mut rosidl_runtime_rs::Sequence<Empty>) -> bool;
}

// Corresponds to test_msgs__msg__Empty
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Empty {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Empty {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__Empty__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__Empty__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Empty {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Empty__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Empty__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Empty__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Empty {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Empty where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/Empty";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Empty() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__MultiNested() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__MultiNested__init(msg: *mut MultiNested) -> bool;
    fn test_msgs__msg__MultiNested__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MultiNested>, size: usize) -> bool;
    fn test_msgs__msg__MultiNested__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MultiNested>);
    fn test_msgs__msg__MultiNested__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MultiNested>, out_seq: *mut rosidl_runtime_rs::Sequence<MultiNested>) -> bool;
}

// Corresponds to test_msgs__msg__MultiNested
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Mulitple levels of nested messages

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MultiNested {

    // This member is not documented.
    #[allow(missing_docs)]
    pub array_of_arrays: [super::super::msg::rmw::Arrays; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub array_of_bounded_sequences: [super::super::msg::rmw::BoundedSequences; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub array_of_unbounded_sequences: [super::super::msg::rmw::UnboundedSequences; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_sequence_of_arrays: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::Arrays, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_sequence_of_bounded_sequences: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::BoundedSequences, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_sequence_of_unbounded_sequences: rosidl_runtime_rs::BoundedSequence<super::super::msg::rmw::UnboundedSequences, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unbounded_sequence_of_arrays: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Arrays>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unbounded_sequence_of_bounded_sequences: rosidl_runtime_rs::Sequence<super::super::msg::rmw::BoundedSequences>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unbounded_sequence_of_unbounded_sequences: rosidl_runtime_rs::Sequence<super::super::msg::rmw::UnboundedSequences>,

}



impl Default for MultiNested {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__MultiNested__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__MultiNested__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MultiNested {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__MultiNested__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__MultiNested__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__MultiNested__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MultiNested {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MultiNested where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/MultiNested";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__MultiNested() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Nested() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__Nested__init(msg: *mut Nested) -> bool;
    fn test_msgs__msg__Nested__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Nested>, size: usize) -> bool;
    fn test_msgs__msg__Nested__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Nested>);
    fn test_msgs__msg__Nested__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Nested>, out_seq: *mut rosidl_runtime_rs::Sequence<Nested>) -> bool;
}

// Corresponds to test_msgs__msg__Nested
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Nested {

    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_value: super::super::msg::rmw::BasicTypes,

}



impl Default for Nested {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__Nested__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__Nested__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Nested {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Nested__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Nested__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Nested__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Nested {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Nested where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/Nested";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Nested() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Strings() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__Strings__init(msg: *mut Strings) -> bool;
    fn test_msgs__msg__Strings__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Strings>, size: usize) -> bool;
    fn test_msgs__msg__Strings__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Strings>);
    fn test_msgs__msg__Strings__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Strings>, out_seq: *mut rosidl_runtime_rs::Sequence<Strings>) -> bool;
}

// Corresponds to test_msgs__msg__Strings
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Strings {

    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default1: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default2: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default3: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default4: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_value_default5: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default1: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default2: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default3: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default4: rosidl_runtime_rs::BoundedString<22>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_string_value_default5: rosidl_runtime_rs::BoundedString<22>,

}

impl Strings {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STRING_CONST: &'static str = "Hello world!";

}


impl Default for Strings {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__Strings__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__Strings__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Strings {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Strings__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Strings__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Strings__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Strings {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Strings where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/Strings";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Strings() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__UnboundedSequences() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__UnboundedSequences__init(msg: *mut UnboundedSequences) -> bool;
    fn test_msgs__msg__UnboundedSequences__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UnboundedSequences>, size: usize) -> bool;
    fn test_msgs__msg__UnboundedSequences__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UnboundedSequences>);
    fn test_msgs__msg__UnboundedSequences__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UnboundedSequences>, out_seq: *mut rosidl_runtime_rs::Sequence<UnboundedSequences>) -> bool;
}

// Corresponds to test_msgs__msg__UnboundedSequences
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Unbounded sequences of different types

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UnboundedSequences {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: rosidl_runtime_rs::Sequence<bool>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values: rosidl_runtime_rs::Sequence<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values: rosidl_runtime_rs::Sequence<i8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values: rosidl_runtime_rs::Sequence<i16>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values: rosidl_runtime_rs::Sequence<u16>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values: rosidl_runtime_rs::Sequence<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values: rosidl_runtime_rs::Sequence<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values: rosidl_runtime_rs::Sequence<i64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values: rosidl_runtime_rs::Sequence<u64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub basic_types_values: rosidl_runtime_rs::Sequence<super::super::msg::rmw::BasicTypes>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub constants_values: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Constants>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub defaults_values: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Defaults>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values_default: rosidl_runtime_rs::Sequence<bool>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte_values_default: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub char_values_default: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float32_values_default: rosidl_runtime_rs::Sequence<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float64_values_default: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int8_values_default: rosidl_runtime_rs::Sequence<i8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint8_values_default: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int16_values_default: rosidl_runtime_rs::Sequence<i16>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint16_values_default: rosidl_runtime_rs::Sequence<u16>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int32_values_default: rosidl_runtime_rs::Sequence<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint32_values_default: rosidl_runtime_rs::Sequence<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int64_values_default: rosidl_runtime_rs::Sequence<i64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub uint64_values_default: rosidl_runtime_rs::Sequence<u64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_values_default: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// Regression test: check alignment of basic field after a sequence field is correct
    pub alignment_check: i32,

}



impl Default for UnboundedSequences {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__UnboundedSequences__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__UnboundedSequences__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UnboundedSequences {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__UnboundedSequences__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__UnboundedSequences__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__UnboundedSequences__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UnboundedSequences {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UnboundedSequences where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/UnboundedSequences";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__UnboundedSequences() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__WStrings() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__WStrings__init(msg: *mut WStrings) -> bool;
    fn test_msgs__msg__WStrings__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<WStrings>, size: usize) -> bool;
    fn test_msgs__msg__WStrings__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<WStrings>);
    fn test_msgs__msg__WStrings__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<WStrings>, out_seq: *mut rosidl_runtime_rs::Sequence<WStrings>) -> bool;
}

// Corresponds to test_msgs__msg__WStrings
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct WStrings {

    // This member is not documented.
    #[allow(missing_docs)]
    pub wstring_value: rosidl_runtime_rs::WString,


    // This member is not documented.
    #[allow(missing_docs)]
    pub wstring_value_default1: rosidl_runtime_rs::WString,


    // This member is not documented.
    #[allow(missing_docs)]
    pub wstring_value_default2: rosidl_runtime_rs::WString,


    // This member is not documented.
    #[allow(missing_docs)]
    pub wstring_value_default3: rosidl_runtime_rs::WString,

    /// wstring WSTRING_CONST="Hello world!"
    /// wstring<=22 bounded_wstring_value
    /// wstring<=22 bounded_wstring_value_default1 "Hello world!"
    pub array_of_wstrings: [rosidl_runtime_rs::WString; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub bounded_sequence_of_wstrings: rosidl_runtime_rs::BoundedSequence<rosidl_runtime_rs::WString, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unbounded_sequence_of_wstrings: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::WString>,

}



impl Default for WStrings {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__WStrings__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__WStrings__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for WStrings {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__WStrings__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__WStrings__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__WStrings__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for WStrings {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for WStrings where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/WStrings";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__WStrings() }
  }
}


#[link(name = "test_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Builtins() -> *const std::ffi::c_void;
}

#[link(name = "test_msgs__rosidl_generator_c")]
extern "C" {
    fn test_msgs__msg__Builtins__init(msg: *mut Builtins) -> bool;
    fn test_msgs__msg__Builtins__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Builtins>, size: usize) -> bool;
    fn test_msgs__msg__Builtins__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Builtins>);
    fn test_msgs__msg__Builtins__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Builtins>, out_seq: *mut rosidl_runtime_rs::Sequence<Builtins>) -> bool;
}

// Corresponds to test_msgs__msg__Builtins
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Builtins {

    // This member is not documented.
    #[allow(missing_docs)]
    pub duration_value: builtin_interfaces::msg::rmw::Duration,


    // This member is not documented.
    #[allow(missing_docs)]
    pub time_value: builtin_interfaces::msg::rmw::Time,

}



impl Default for Builtins {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_msgs__msg__Builtins__init(&mut msg as *mut _) {
        panic!("Call to test_msgs__msg__Builtins__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Builtins {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Builtins__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Builtins__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_msgs__msg__Builtins__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Builtins {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Builtins where Self: Sized {
  const TYPE_NAME: &'static str = "test_msgs/msg/Builtins";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_msgs__msg__Builtins() }
  }
}


