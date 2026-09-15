#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "rmw_dds_common__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rmw_dds_common__msg__Gid() -> *const std::ffi::c_void;
}

#[link(name = "rmw_dds_common__rosidl_generator_c")]
extern "C" {
    fn rmw_dds_common__msg__Gid__init(msg: *mut Gid) -> bool;
    fn rmw_dds_common__msg__Gid__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gid>, size: usize) -> bool;
    fn rmw_dds_common__msg__Gid__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gid>);
    fn rmw_dds_common__msg__Gid__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gid>, out_seq: *mut rosidl_runtime_rs::Sequence<Gid>) -> bool;
}

// Corresponds to rmw_dds_common__msg__Gid
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gid {

    // This member is not documented.
    #[allow(missing_docs)]
    pub data: [u8; 16],

}



impl Default for Gid {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rmw_dds_common__msg__Gid__init(&mut msg as *mut _) {
        panic!("Call to rmw_dds_common__msg__Gid__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gid {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__Gid__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__Gid__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__Gid__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gid {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gid where Self: Sized {
  const TYPE_NAME: &'static str = "rmw_dds_common/msg/Gid";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rmw_dds_common__msg__Gid() }
  }
}


#[link(name = "rmw_dds_common__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rmw_dds_common__msg__NodeEntitiesInfo() -> *const std::ffi::c_void;
}

#[link(name = "rmw_dds_common__rosidl_generator_c")]
extern "C" {
    fn rmw_dds_common__msg__NodeEntitiesInfo__init(msg: *mut NodeEntitiesInfo) -> bool;
    fn rmw_dds_common__msg__NodeEntitiesInfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NodeEntitiesInfo>, size: usize) -> bool;
    fn rmw_dds_common__msg__NodeEntitiesInfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NodeEntitiesInfo>);
    fn rmw_dds_common__msg__NodeEntitiesInfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NodeEntitiesInfo>, out_seq: *mut rosidl_runtime_rs::Sequence<NodeEntitiesInfo>) -> bool;
}

// Corresponds to rmw_dds_common__msg__NodeEntitiesInfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodeEntitiesInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub node_namespace: rosidl_runtime_rs::BoundedString<256>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub node_name: rosidl_runtime_rs::BoundedString<256>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reader_gid_seq: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Gid>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub writer_gid_seq: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Gid>,

}



impl Default for NodeEntitiesInfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rmw_dds_common__msg__NodeEntitiesInfo__init(&mut msg as *mut _) {
        panic!("Call to rmw_dds_common__msg__NodeEntitiesInfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NodeEntitiesInfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__NodeEntitiesInfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__NodeEntitiesInfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__NodeEntitiesInfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NodeEntitiesInfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NodeEntitiesInfo where Self: Sized {
  const TYPE_NAME: &'static str = "rmw_dds_common/msg/NodeEntitiesInfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rmw_dds_common__msg__NodeEntitiesInfo() }
  }
}


#[link(name = "rmw_dds_common__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rmw_dds_common__msg__ParticipantEntitiesInfo() -> *const std::ffi::c_void;
}

#[link(name = "rmw_dds_common__rosidl_generator_c")]
extern "C" {
    fn rmw_dds_common__msg__ParticipantEntitiesInfo__init(msg: *mut ParticipantEntitiesInfo) -> bool;
    fn rmw_dds_common__msg__ParticipantEntitiesInfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ParticipantEntitiesInfo>, size: usize) -> bool;
    fn rmw_dds_common__msg__ParticipantEntitiesInfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ParticipantEntitiesInfo>);
    fn rmw_dds_common__msg__ParticipantEntitiesInfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ParticipantEntitiesInfo>, out_seq: *mut rosidl_runtime_rs::Sequence<ParticipantEntitiesInfo>) -> bool;
}

// Corresponds to rmw_dds_common__msg__ParticipantEntitiesInfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ParticipantEntitiesInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub gid: super::super::msg::rmw::Gid,


    // This member is not documented.
    #[allow(missing_docs)]
    pub node_entities_info_seq: rosidl_runtime_rs::Sequence<super::super::msg::rmw::NodeEntitiesInfo>,

}



impl Default for ParticipantEntitiesInfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rmw_dds_common__msg__ParticipantEntitiesInfo__init(&mut msg as *mut _) {
        panic!("Call to rmw_dds_common__msg__ParticipantEntitiesInfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ParticipantEntitiesInfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__ParticipantEntitiesInfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__ParticipantEntitiesInfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rmw_dds_common__msg__ParticipantEntitiesInfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ParticipantEntitiesInfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ParticipantEntitiesInfo where Self: Sized {
  const TYPE_NAME: &'static str = "rmw_dds_common/msg/ParticipantEntitiesInfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rmw_dds_common__msg__ParticipantEntitiesInfo() }
  }
}


