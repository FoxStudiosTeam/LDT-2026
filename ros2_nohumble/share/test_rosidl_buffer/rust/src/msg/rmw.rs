#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "test_rosidl_buffer__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_rosidl_buffer__msg__ByteArray() -> *const std::ffi::c_void;
}

#[link(name = "test_rosidl_buffer__rosidl_generator_c")]
extern "C" {
    fn test_rosidl_buffer__msg__ByteArray__init(msg: *mut ByteArray) -> bool;
    fn test_rosidl_buffer__msg__ByteArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ByteArray>, size: usize) -> bool;
    fn test_rosidl_buffer__msg__ByteArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ByteArray>);
    fn test_rosidl_buffer__msg__ByteArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ByteArray>, out_seq: *mut rosidl_runtime_rs::Sequence<ByteArray>) -> bool;
}

// Corresponds to test_rosidl_buffer__msg__ByteArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Minimal payload message used by the pub/sub launch tests.
/// The `data` field is generated as rosidl::Buffer<uint8_t>, which is the
/// feature under test.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ByteArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub seq: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub data: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for ByteArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_rosidl_buffer__msg__ByteArray__init(&mut msg as *mut _) {
        panic!("Call to test_rosidl_buffer__msg__ByteArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ByteArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__ByteArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__ByteArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__ByteArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ByteArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ByteArray where Self: Sized {
  const TYPE_NAME: &'static str = "test_rosidl_buffer/msg/ByteArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_rosidl_buffer__msg__ByteArray() }
  }
}


#[link(name = "test_rosidl_buffer__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_rosidl_buffer__msg__ByteArrayList() -> *const std::ffi::c_void;
}

#[link(name = "test_rosidl_buffer__rosidl_generator_c")]
extern "C" {
    fn test_rosidl_buffer__msg__ByteArrayList__init(msg: *mut ByteArrayList) -> bool;
    fn test_rosidl_buffer__msg__ByteArrayList__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ByteArrayList>, size: usize) -> bool;
    fn test_rosidl_buffer__msg__ByteArrayList__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ByteArrayList>);
    fn test_rosidl_buffer__msg__ByteArrayList__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ByteArrayList>, out_seq: *mut rosidl_runtime_rs::Sequence<ByteArrayList>) -> bool;
}

// Corresponds to test_rosidl_buffer__msg__ByteArrayList
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Minimal nested payload used by the pub/sub launch tests.
/// Each ByteArray item contains a uint8[] field generated as rosidl::Buffer<uint8_t>.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ByteArrayList {

    // This member is not documented.
    #[allow(missing_docs)]
    pub items: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ByteArray>,

}



impl Default for ByteArrayList {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_rosidl_buffer__msg__ByteArrayList__init(&mut msg as *mut _) {
        panic!("Call to test_rosidl_buffer__msg__ByteArrayList__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ByteArrayList {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__ByteArrayList__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__ByteArrayList__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__ByteArrayList__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ByteArrayList {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ByteArrayList where Self: Sized {
  const TYPE_NAME: &'static str = "test_rosidl_buffer/msg/ByteArrayList";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_rosidl_buffer__msg__ByteArrayList() }
  }
}


#[link(name = "test_rosidl_buffer__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__test_rosidl_buffer__msg__TestBufferDescriptor() -> *const std::ffi::c_void;
}

#[link(name = "test_rosidl_buffer__rosidl_generator_c")]
extern "C" {
    fn test_rosidl_buffer__msg__TestBufferDescriptor__init(msg: *mut TestBufferDescriptor) -> bool;
    fn test_rosidl_buffer__msg__TestBufferDescriptor__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TestBufferDescriptor>, size: usize) -> bool;
    fn test_rosidl_buffer__msg__TestBufferDescriptor__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TestBufferDescriptor>);
    fn test_rosidl_buffer__msg__TestBufferDescriptor__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TestBufferDescriptor>, out_seq: *mut rosidl_runtime_rs::Sequence<TestBufferDescriptor>) -> bool;
}

// Corresponds to test_rosidl_buffer__msg__TestBufferDescriptor
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Wire descriptor used by the in-tree test buffer backend.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TestBufferDescriptor {
    /// number of elements in the original buffer
    pub size: u64,

    /// FNV-1a hash of the element bytes
    pub data_hash: u64,

    /// raw element bytes (size * sizeof(T))
    pub data: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for TestBufferDescriptor {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !test_rosidl_buffer__msg__TestBufferDescriptor__init(&mut msg as *mut _) {
        panic!("Call to test_rosidl_buffer__msg__TestBufferDescriptor__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TestBufferDescriptor {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__TestBufferDescriptor__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__TestBufferDescriptor__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { test_rosidl_buffer__msg__TestBufferDescriptor__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TestBufferDescriptor {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TestBufferDescriptor where Self: Sized {
  const TYPE_NAME: &'static str = "test_rosidl_buffer/msg/TestBufferDescriptor";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__test_rosidl_buffer__msg__TestBufferDescriptor() }
  }
}


