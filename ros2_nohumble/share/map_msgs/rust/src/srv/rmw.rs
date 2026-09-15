#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetMapROI_Request() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__GetMapROI_Request__init(msg: *mut GetMapROI_Request) -> bool;
    fn map_msgs__srv__GetMapROI_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetMapROI_Request>, size: usize) -> bool;
    fn map_msgs__srv__GetMapROI_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetMapROI_Request>);
    fn map_msgs__srv__GetMapROI_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetMapROI_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetMapROI_Request>) -> bool;
}

// Corresponds to map_msgs__srv__GetMapROI_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetMapROI_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub l_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub l_y: f64,

}



impl Default for GetMapROI_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__GetMapROI_Request__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__GetMapROI_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetMapROI_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetMapROI_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetMapROI_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetMapROI_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetMapROI_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetMapROI_Request where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/GetMapROI_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetMapROI_Request() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetMapROI_Response() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__GetMapROI_Response__init(msg: *mut GetMapROI_Response) -> bool;
    fn map_msgs__srv__GetMapROI_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetMapROI_Response>, size: usize) -> bool;
    fn map_msgs__srv__GetMapROI_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetMapROI_Response>);
    fn map_msgs__srv__GetMapROI_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetMapROI_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetMapROI_Response>) -> bool;
}

// Corresponds to map_msgs__srv__GetMapROI_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetMapROI_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sub_map: nav_msgs::msg::rmw::OccupancyGrid,

}



impl Default for GetMapROI_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__GetMapROI_Response__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__GetMapROI_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetMapROI_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetMapROI_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetMapROI_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetMapROI_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetMapROI_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetMapROI_Response where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/GetMapROI_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetMapROI_Response() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetPointMapROI_Request() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__GetPointMapROI_Request__init(msg: *mut GetPointMapROI_Request) -> bool;
    fn map_msgs__srv__GetPointMapROI_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPointMapROI_Request>, size: usize) -> bool;
    fn map_msgs__srv__GetPointMapROI_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPointMapROI_Request>);
    fn map_msgs__srv__GetPointMapROI_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPointMapROI_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPointMapROI_Request>) -> bool;
}

// Corresponds to map_msgs__srv__GetPointMapROI_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointMapROI_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f64,

    /// if != 0, circular ROI of radius r
    pub r: f64,

    /// if r == 0, length of AABB on x
    pub l_x: f64,

    /// if r == 0, length of AABB on y
    pub l_y: f64,

    /// if r == 0, length of AABB on z
    pub l_z: f64,

}



impl Default for GetPointMapROI_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__GetPointMapROI_Request__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__GetPointMapROI_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPointMapROI_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMapROI_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMapROI_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMapROI_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPointMapROI_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPointMapROI_Request where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/GetPointMapROI_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetPointMapROI_Request() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetPointMapROI_Response() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__GetPointMapROI_Response__init(msg: *mut GetPointMapROI_Response) -> bool;
    fn map_msgs__srv__GetPointMapROI_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPointMapROI_Response>, size: usize) -> bool;
    fn map_msgs__srv__GetPointMapROI_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPointMapROI_Response>);
    fn map_msgs__srv__GetPointMapROI_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPointMapROI_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPointMapROI_Response>) -> bool;
}

// Corresponds to map_msgs__srv__GetPointMapROI_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointMapROI_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sub_map: sensor_msgs::msg::rmw::PointCloud2,

}



impl Default for GetPointMapROI_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__GetPointMapROI_Response__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__GetPointMapROI_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPointMapROI_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMapROI_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMapROI_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMapROI_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPointMapROI_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPointMapROI_Response where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/GetPointMapROI_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetPointMapROI_Response() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetPointMap_Request() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__GetPointMap_Request__init(msg: *mut GetPointMap_Request) -> bool;
    fn map_msgs__srv__GetPointMap_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPointMap_Request>, size: usize) -> bool;
    fn map_msgs__srv__GetPointMap_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPointMap_Request>);
    fn map_msgs__srv__GetPointMap_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPointMap_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPointMap_Request>) -> bool;
}

// Corresponds to map_msgs__srv__GetPointMap_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetPointMap_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__GetPointMap_Request__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__GetPointMap_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPointMap_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMap_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMap_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMap_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPointMap_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPointMap_Request where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/GetPointMap_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetPointMap_Request() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetPointMap_Response() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__GetPointMap_Response__init(msg: *mut GetPointMap_Response) -> bool;
    fn map_msgs__srv__GetPointMap_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPointMap_Response>, size: usize) -> bool;
    fn map_msgs__srv__GetPointMap_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPointMap_Response>);
    fn map_msgs__srv__GetPointMap_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPointMap_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPointMap_Response>) -> bool;
}

// Corresponds to map_msgs__srv__GetPointMap_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub map: sensor_msgs::msg::rmw::PointCloud2,

}



impl Default for GetPointMap_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__GetPointMap_Response__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__GetPointMap_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPointMap_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMap_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMap_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__GetPointMap_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPointMap_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPointMap_Response where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/GetPointMap_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__GetPointMap_Response() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__ProjectedMapsInfo_Request() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__ProjectedMapsInfo_Request__init(msg: *mut ProjectedMapsInfo_Request) -> bool;
    fn map_msgs__srv__ProjectedMapsInfo_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapsInfo_Request>, size: usize) -> bool;
    fn map_msgs__srv__ProjectedMapsInfo_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapsInfo_Request>);
    fn map_msgs__srv__ProjectedMapsInfo_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProjectedMapsInfo_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapsInfo_Request>) -> bool;
}

// Corresponds to map_msgs__srv__ProjectedMapsInfo_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProjectedMapsInfo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub projected_maps_info: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ProjectedMapInfo>,

}



impl Default for ProjectedMapsInfo_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__ProjectedMapsInfo_Request__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__ProjectedMapsInfo_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProjectedMapsInfo_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__ProjectedMapsInfo_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__ProjectedMapsInfo_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__ProjectedMapsInfo_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProjectedMapsInfo_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProjectedMapsInfo_Request where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/ProjectedMapsInfo_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__ProjectedMapsInfo_Request() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__ProjectedMapsInfo_Response() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__ProjectedMapsInfo_Response__init(msg: *mut ProjectedMapsInfo_Response) -> bool;
    fn map_msgs__srv__ProjectedMapsInfo_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapsInfo_Response>, size: usize) -> bool;
    fn map_msgs__srv__ProjectedMapsInfo_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapsInfo_Response>);
    fn map_msgs__srv__ProjectedMapsInfo_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProjectedMapsInfo_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ProjectedMapsInfo_Response>) -> bool;
}

// Corresponds to map_msgs__srv__ProjectedMapsInfo_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProjectedMapsInfo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ProjectedMapsInfo_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__ProjectedMapsInfo_Response__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__ProjectedMapsInfo_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProjectedMapsInfo_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__ProjectedMapsInfo_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__ProjectedMapsInfo_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__ProjectedMapsInfo_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProjectedMapsInfo_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProjectedMapsInfo_Response where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/ProjectedMapsInfo_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__ProjectedMapsInfo_Response() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__SaveMap_Request() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__SaveMap_Request__init(msg: *mut SaveMap_Request) -> bool;
    fn map_msgs__srv__SaveMap_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SaveMap_Request>, size: usize) -> bool;
    fn map_msgs__srv__SaveMap_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SaveMap_Request>);
    fn map_msgs__srv__SaveMap_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SaveMap_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SaveMap_Request>) -> bool;
}

// Corresponds to map_msgs__srv__SaveMap_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SaveMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub filename: std_msgs::msg::rmw::String,

}



impl Default for SaveMap_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__SaveMap_Request__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__SaveMap_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SaveMap_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SaveMap_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SaveMap_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SaveMap_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SaveMap_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SaveMap_Request where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/SaveMap_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__SaveMap_Request() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__SaveMap_Response() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__SaveMap_Response__init(msg: *mut SaveMap_Response) -> bool;
    fn map_msgs__srv__SaveMap_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SaveMap_Response>, size: usize) -> bool;
    fn map_msgs__srv__SaveMap_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SaveMap_Response>);
    fn map_msgs__srv__SaveMap_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SaveMap_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SaveMap_Response>) -> bool;
}

// Corresponds to map_msgs__srv__SaveMap_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SaveMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SaveMap_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__SaveMap_Response__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__SaveMap_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SaveMap_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SaveMap_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SaveMap_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SaveMap_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SaveMap_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SaveMap_Response where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/SaveMap_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__SaveMap_Response() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__SetMapProjections_Request() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__SetMapProjections_Request__init(msg: *mut SetMapProjections_Request) -> bool;
    fn map_msgs__srv__SetMapProjections_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetMapProjections_Request>, size: usize) -> bool;
    fn map_msgs__srv__SetMapProjections_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetMapProjections_Request>);
    fn map_msgs__srv__SetMapProjections_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetMapProjections_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetMapProjections_Request>) -> bool;
}

// Corresponds to map_msgs__srv__SetMapProjections_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetMapProjections_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SetMapProjections_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__SetMapProjections_Request__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__SetMapProjections_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetMapProjections_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SetMapProjections_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SetMapProjections_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SetMapProjections_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetMapProjections_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetMapProjections_Request where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/SetMapProjections_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__SetMapProjections_Request() }
  }
}


#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__SetMapProjections_Response() -> *const std::ffi::c_void;
}

#[link(name = "map_msgs__rosidl_generator_c")]
extern "C" {
    fn map_msgs__srv__SetMapProjections_Response__init(msg: *mut SetMapProjections_Response) -> bool;
    fn map_msgs__srv__SetMapProjections_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetMapProjections_Response>, size: usize) -> bool;
    fn map_msgs__srv__SetMapProjections_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetMapProjections_Response>);
    fn map_msgs__srv__SetMapProjections_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetMapProjections_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetMapProjections_Response>) -> bool;
}

// Corresponds to map_msgs__srv__SetMapProjections_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetMapProjections_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub projected_maps_info: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ProjectedMapInfo>,

}



impl Default for SetMapProjections_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !map_msgs__srv__SetMapProjections_Response__init(&mut msg as *mut _) {
        panic!("Call to map_msgs__srv__SetMapProjections_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetMapProjections_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SetMapProjections_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SetMapProjections_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { map_msgs__srv__SetMapProjections_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetMapProjections_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetMapProjections_Response where Self: Sized {
  const TYPE_NAME: &'static str = "map_msgs/srv/SetMapProjections_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__map_msgs__srv__SetMapProjections_Response() }
  }
}






#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__GetMapROI() -> *const std::ffi::c_void;
}

// Corresponds to map_msgs__srv__GetMapROI
#[allow(missing_docs, non_camel_case_types)]
pub struct GetMapROI;

impl rosidl_runtime_rs::Service for GetMapROI {
    type Request = GetMapROI_Request;
    type Response = GetMapROI_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__GetMapROI() }
    }
}




#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__GetPointMapROI() -> *const std::ffi::c_void;
}

// Corresponds to map_msgs__srv__GetPointMapROI
#[allow(missing_docs, non_camel_case_types)]
pub struct GetPointMapROI;

impl rosidl_runtime_rs::Service for GetPointMapROI {
    type Request = GetPointMapROI_Request;
    type Response = GetPointMapROI_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__GetPointMapROI() }
    }
}




#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__GetPointMap() -> *const std::ffi::c_void;
}

// Corresponds to map_msgs__srv__GetPointMap
#[allow(missing_docs, non_camel_case_types)]
pub struct GetPointMap;

impl rosidl_runtime_rs::Service for GetPointMap {
    type Request = GetPointMap_Request;
    type Response = GetPointMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__GetPointMap() }
    }
}




#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__ProjectedMapsInfo() -> *const std::ffi::c_void;
}

// Corresponds to map_msgs__srv__ProjectedMapsInfo
#[allow(missing_docs, non_camel_case_types)]
pub struct ProjectedMapsInfo;

impl rosidl_runtime_rs::Service for ProjectedMapsInfo {
    type Request = ProjectedMapsInfo_Request;
    type Response = ProjectedMapsInfo_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__ProjectedMapsInfo() }
    }
}




#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__SaveMap() -> *const std::ffi::c_void;
}

// Corresponds to map_msgs__srv__SaveMap
#[allow(missing_docs, non_camel_case_types)]
pub struct SaveMap;

impl rosidl_runtime_rs::Service for SaveMap {
    type Request = SaveMap_Request;
    type Response = SaveMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__SaveMap() }
    }
}




#[link(name = "map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__SetMapProjections() -> *const std::ffi::c_void;
}

// Corresponds to map_msgs__srv__SetMapProjections
#[allow(missing_docs, non_camel_case_types)]
pub struct SetMapProjections;

impl rosidl_runtime_rs::Service for SetMapProjections {
    type Request = SetMapProjections_Request;
    type Response = SetMapProjections_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__map_msgs__srv__SetMapProjections() }
    }
}


