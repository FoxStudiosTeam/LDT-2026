#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to map_msgs__srv__GetMapROI_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetMapROI_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetMapROI_Request {
  type RmwMsg = super::srv::rmw::GetMapROI_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        l_x: msg.l_x,
        l_y: msg.l_y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      l_x: msg.l_x,
      l_y: msg.l_y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      l_x: msg.l_x,
      l_y: msg.l_y,
    }
  }
}


// Corresponds to map_msgs__srv__GetMapROI_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetMapROI_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sub_map: nav_msgs::msg::OccupancyGrid,

}



impl Default for GetMapROI_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetMapROI_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetMapROI_Response {
  type RmwMsg = super::srv::rmw::GetMapROI_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sub_map: nav_msgs::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Owned(msg.sub_map)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sub_map: nav_msgs::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Borrowed(&msg.sub_map)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sub_map: nav_msgs::msg::OccupancyGrid::from_rmw_message(msg.sub_map),
    }
  }
}


// Corresponds to map_msgs__srv__GetPointMapROI_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPointMapROI_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetPointMapROI_Request {
  type RmwMsg = super::srv::rmw::GetPointMapROI_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        z: msg.z,
        r: msg.r,
        l_x: msg.l_x,
        l_y: msg.l_y,
        l_z: msg.l_z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      z: msg.z,
      r: msg.r,
      l_x: msg.l_x,
      l_y: msg.l_y,
      l_z: msg.l_z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      z: msg.z,
      r: msg.r,
      l_x: msg.l_x,
      l_y: msg.l_y,
      l_z: msg.l_z,
    }
  }
}


// Corresponds to map_msgs__srv__GetPointMapROI_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointMapROI_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sub_map: sensor_msgs::msg::PointCloud2,

}



impl Default for GetPointMapROI_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPointMapROI_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetPointMapROI_Response {
  type RmwMsg = super::srv::rmw::GetPointMapROI_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sub_map: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Owned(msg.sub_map)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sub_map: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Borrowed(&msg.sub_map)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sub_map: sensor_msgs::msg::PointCloud2::from_rmw_message(msg.sub_map),
    }
  }
}


// Corresponds to map_msgs__srv__GetPointMap_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetPointMap_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPointMap_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetPointMap_Request {
  type RmwMsg = super::srv::rmw::GetPointMap_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to map_msgs__srv__GetPointMap_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPointMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub map: sensor_msgs::msg::PointCloud2,

}



impl Default for GetPointMap_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPointMap_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetPointMap_Response {
  type RmwMsg = super::srv::rmw::GetPointMap_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Owned(msg.map)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Borrowed(&msg.map)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      map: sensor_msgs::msg::PointCloud2::from_rmw_message(msg.map),
    }
  }
}


// Corresponds to map_msgs__srv__ProjectedMapsInfo_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProjectedMapsInfo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub projected_maps_info: Vec<super::msg::ProjectedMapInfo>,

}



impl Default for ProjectedMapsInfo_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ProjectedMapsInfo_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ProjectedMapsInfo_Request {
  type RmwMsg = super::srv::rmw::ProjectedMapsInfo_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        projected_maps_info: msg.projected_maps_info
          .into_iter()
          .map(|elem| super::msg::ProjectedMapInfo::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        projected_maps_info: msg.projected_maps_info
          .iter()
          .map(|elem| super::msg::ProjectedMapInfo::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      projected_maps_info: msg.projected_maps_info
          .into_iter()
          .map(super::msg::ProjectedMapInfo::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to map_msgs__srv__ProjectedMapsInfo_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProjectedMapsInfo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ProjectedMapsInfo_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ProjectedMapsInfo_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ProjectedMapsInfo_Response {
  type RmwMsg = super::srv::rmw::ProjectedMapsInfo_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to map_msgs__srv__SaveMap_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SaveMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub filename: std_msgs::msg::String,

}



impl Default for SaveMap_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SaveMap_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SaveMap_Request {
  type RmwMsg = super::srv::rmw::SaveMap_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        filename: std_msgs::msg::String::into_rmw_message(std::borrow::Cow::Owned(msg.filename)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        filename: std_msgs::msg::String::into_rmw_message(std::borrow::Cow::Borrowed(&msg.filename)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      filename: std_msgs::msg::String::from_rmw_message(msg.filename),
    }
  }
}


// Corresponds to map_msgs__srv__SaveMap_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SaveMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SaveMap_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SaveMap_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SaveMap_Response {
  type RmwMsg = super::srv::rmw::SaveMap_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to map_msgs__srv__SetMapProjections_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetMapProjections_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SetMapProjections_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetMapProjections_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetMapProjections_Request {
  type RmwMsg = super::srv::rmw::SetMapProjections_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to map_msgs__srv__SetMapProjections_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetMapProjections_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub projected_maps_info: Vec<super::msg::ProjectedMapInfo>,

}



impl Default for SetMapProjections_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetMapProjections_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetMapProjections_Response {
  type RmwMsg = super::srv::rmw::SetMapProjections_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        projected_maps_info: msg.projected_maps_info
          .into_iter()
          .map(|elem| super::msg::ProjectedMapInfo::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        projected_maps_info: msg.projected_maps_info
          .iter()
          .map(|elem| super::msg::ProjectedMapInfo::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      projected_maps_info: msg.projected_maps_info
          .into_iter()
          .map(super::msg::ProjectedMapInfo::from_rmw_message)
          .collect(),
    }
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


