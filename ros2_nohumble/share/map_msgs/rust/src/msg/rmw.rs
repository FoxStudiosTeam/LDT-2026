#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__msg__OccupancyGridUpdate() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__msg__OccupancyGridUpdate__init(msg: *mut OccupancyGridUpdate) -> bool;
    fn map_msgs__msg__OccupancyGridUpdate__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OccupancyGridUpdate>, size: usize) -> bool;
    fn map_msgs__msg__OccupancyGridUpdate__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OccupancyGridUpdate>);
    fn map_msgs__msg__OccupancyGridUpdate__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OccupancyGridUpdate>, out_seq: *mut rosidl_runtime_rs::Sequence<OccupancyGridUpdate>) -> bool;
}

// Corresponds to map_msgs__msg__OccupancyGridUpdate
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OccupancyGridUpdate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub width: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub height: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub data: rosidl_runtime_rs::Sequence<i8>,

}



impl Default for OccupancyGridUpdate {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__msg__OccupancyGridUpdate__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__msg__OccupancyGridUpdate__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OccupancyGridUpdate {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__OccupancyGridUpdate__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__OccupancyGridUpdate__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__OccupancyGridUpdate__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OccupancyGridUpdate {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OccupancyGridUpdate where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/msg/OccupancyGridUpdate";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__msg__OccupancyGridUpdate() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__msg__PointCloud2Update() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__msg__PointCloud2Update__init(msg: *mut PointCloud2Update) -> bool;
    fn map_msgs__msg__PointCloud2Update__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PointCloud2Update>, size: usize) -> bool;
    fn map_msgs__msg__PointCloud2Update__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PointCloud2Update>);
    fn map_msgs__msg__PointCloud2Update__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PointCloud2Update>, out_seq: *mut rosidl_runtime_rs::Sequence<PointCloud2Update>) -> bool;
}

// Corresponds to map_msgs__msg__PointCloud2Update
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PointCloud2Update {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// type of update, one of ADD or DELETE
    pub type_: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub points: sensor_msgs::msg::rmw::PointCloud2,

}

impl PointCloud2Update {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ADD: u32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DELETE: u32 = 1;

}


impl Default for PointCloud2Update {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__msg__PointCloud2Update__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__msg__PointCloud2Update__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PointCloud2Update {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__PointCloud2Update__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__PointCloud2Update__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__PointCloud2Update__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PointCloud2Update {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PointCloud2Update where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/msg/PointCloud2Update";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__msg__PointCloud2Update() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__msg__ProjectedMapInfo() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__msg__ProjectedMapInfo__init(msg: *mut ProjectedMapInfo) -> bool;
    fn map_msgs__msg__ProjectedMapInfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapInfo>, size: usize) -> bool;
    fn map_msgs__msg__ProjectedMapInfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapInfo>);
    fn map_msgs__msg__ProjectedMapInfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProjectedMapInfo>, out_seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapInfo>) -> bool;
}

// Corresponds to map_msgs__msg__ProjectedMapInfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProjectedMapInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub frame_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub width: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub height: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub min_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_z: f64,

}



impl Default for ProjectedMapInfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__msg__ProjectedMapInfo__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__msg__ProjectedMapInfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProjectedMapInfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__ProjectedMapInfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__ProjectedMapInfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__ProjectedMapInfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProjectedMapInfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProjectedMapInfo where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/msg/ProjectedMapInfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__msg__ProjectedMapInfo() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__msg__ProjectedMap() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__msg__ProjectedMap__init(msg: *mut ProjectedMap) -> bool;
    fn map_msgs__msg__ProjectedMap__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProjectedMap>, size: usize) -> bool;
    fn map_msgs__msg__ProjectedMap__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProjectedMap>);
    fn map_msgs__msg__ProjectedMap__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProjectedMap>, out_seq: *mut rosidl_runtime_rs::Sequence<ProjectedMap>) -> bool;
}

// Corresponds to map_msgs__msg__ProjectedMap
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProjectedMap {

    // This member is not documented.
    #[allow(missing_docs)]
    pub map: nav_msgs::msg::rmw::OccupancyGrid,


    // This member is not documented.
    #[allow(missing_docs)]
    pub min_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_z: f64,

}



impl Default for ProjectedMap {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__msg__ProjectedMap__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__msg__ProjectedMap__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProjectedMap {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__ProjectedMap__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__ProjectedMap__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__msg__ProjectedMap__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProjectedMap {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProjectedMap where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/msg/ProjectedMap";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__msg__ProjectedMap() }
  }
}


