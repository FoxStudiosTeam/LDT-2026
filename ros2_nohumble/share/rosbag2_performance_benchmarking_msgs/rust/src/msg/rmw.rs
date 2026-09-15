#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "rosbag2_performance_benchmarking_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rosbag2_performance_benchmarking_msgs__msg__ByteArray() -> *const std::ffi::c_void;
}

#[link(name = "rosbag2_performance_benchmarking_msgs__rosidl_generator_c")]
extern "C" {
    fn rosbag2_performance_benchmarking_msgs__msg__ByteArray__init(msg: *mut ByteArray) -> bool;
    fn rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ByteArray>, size: usize) -> bool;
    fn rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ByteArray>);
    fn rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ByteArray>, out_seq: *mut rosidl_runtime_rs::Sequence<ByteArray>) -> bool;
}

// Corresponds to rosbag2_performance_benchmarking_msgs__msg__ByteArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ByteArray {
    /// array of data
    pub data: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for ByteArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rosbag2_performance_benchmarking_msgs__msg__ByteArray__init(&mut msg as *mut _) {
        panic!("Call to rosbag2_performance_benchmarking_msgs__msg__ByteArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ByteArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ByteArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ByteArray where Self: Sized {
  const TYPE_NAME: &'static str = "rosbag2_performance_benchmarking_msgs/msg/ByteArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rosbag2_performance_benchmarking_msgs__msg__ByteArray() }
  }
}


