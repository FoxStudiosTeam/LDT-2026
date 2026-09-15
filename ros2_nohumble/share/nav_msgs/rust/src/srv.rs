#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to nav_msgs__srv__GetMap_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetMap_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetMap_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetMap_Request {
  type RmwMsg = super::srv::rmw::GetMap_Request;

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


// Corresponds to nav_msgs__srv__GetMap_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub map: super::msg::OccupancyGrid,

}



impl Default for GetMap_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetMap_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetMap_Response {
  type RmwMsg = super::srv::rmw::GetMap_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: super::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Owned(msg.map)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: super::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Borrowed(&msg.map)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      map: super::msg::OccupancyGrid::from_rmw_message(msg.map),
    }
  }
}


// Corresponds to nav_msgs__srv__GetPlan_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPlan_Request {
    /// The start pose for the plan
    pub start: geometry_msgs::msg::PoseStamped,

    /// The final pose of the goal position
    pub goal: geometry_msgs::msg::PoseStamped,

    /// If the goal is obstructed, how many meters the planner can
    /// relax the constraint in x and y before failing.
    pub tolerance: f32,

}



impl Default for GetPlan_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPlan_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetPlan_Request {
  type RmwMsg = super::srv::rmw::GetPlan_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.start)).into_owned(),
        goal: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
        tolerance: msg.tolerance,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start)).into_owned(),
        goal: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      tolerance: msg.tolerance,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      start: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.start),
      goal: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.goal),
      tolerance: msg.tolerance,
    }
  }
}


// Corresponds to nav_msgs__srv__GetPlan_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPlan_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub plan: super::msg::Path,

}



impl Default for GetPlan_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPlan_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetPlan_Response {
  type RmwMsg = super::srv::rmw::GetPlan_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        plan: super::msg::Path::into_rmw_message(std::borrow::Cow::Owned(msg.plan)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        plan: super::msg::Path::into_rmw_message(std::borrow::Cow::Borrowed(&msg.plan)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      plan: super::msg::Path::from_rmw_message(msg.plan),
    }
  }
}


// Corresponds to nav_msgs__srv__LoadMap_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub map_url: std::string::String,

}



impl Default for LoadMap_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::LoadMap_Request::default())
  }
}

impl rosidl_runtime_rs::Message for LoadMap_Request {
  type RmwMsg = super::srv::rmw::LoadMap_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map_url: msg.map_url.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map_url: msg.map_url.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      map_url: msg.map_url.to_string(),
    }
  }
}


// Corresponds to nav_msgs__srv__LoadMap_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadMap_Response {
    /// Returned map is only valid if result equals RESULT_SUCCESS
    pub map: super::msg::OccupancyGrid,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: u8,

}

impl LoadMap_Response {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_SUCCESS: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_MAP_DOES_NOT_EXIST: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_INVALID_MAP_DATA: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_INVALID_MAP_METADATA: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_UNDEFINED_FAILURE: u8 = 255;

}


impl Default for LoadMap_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::LoadMap_Response::default())
  }
}

impl rosidl_runtime_rs::Message for LoadMap_Response {
  type RmwMsg = super::srv::rmw::LoadMap_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: super::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Owned(msg.map)).into_owned(),
        result: msg.result,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: super::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Borrowed(&msg.map)).into_owned(),
      result: msg.result,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      map: super::msg::OccupancyGrid::from_rmw_message(msg.map),
      result: msg.result,
    }
  }
}


// Corresponds to nav_msgs__srv__SetMap_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetMap_Request {
    /// Requested 2D map to be set.
    pub map: super::msg::OccupancyGrid,

    /// Estimated initial pose when setting new map.
    pub initial_pose: geometry_msgs::msg::PoseWithCovarianceStamped,

}



impl Default for SetMap_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetMap_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetMap_Request {
  type RmwMsg = super::srv::rmw::SetMap_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: super::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Owned(msg.map)).into_owned(),
        initial_pose: geometry_msgs::msg::PoseWithCovarianceStamped::into_rmw_message(std::borrow::Cow::Owned(msg.initial_pose)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: super::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Borrowed(&msg.map)).into_owned(),
        initial_pose: geometry_msgs::msg::PoseWithCovarianceStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.initial_pose)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      map: super::msg::OccupancyGrid::from_rmw_message(msg.map),
      initial_pose: geometry_msgs::msg::PoseWithCovarianceStamped::from_rmw_message(msg.initial_pose),
    }
  }
}


// Corresponds to nav_msgs__srv__SetMap_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetMap_Response {
    /// True if the map was successfully set, false otherwise.
    pub success: bool,

}



impl Default for SetMap_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetMap_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetMap_Response {
  type RmwMsg = super::srv::rmw::SetMap_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}






#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__GetMap() -> *const std::ffi::c_void;
}

// Corresponds to nav_msgs__srv__GetMap
#[allow(missing_docs, non_camel_case_types)]
pub struct GetMap;

impl rosidl_runtime_rs::Service for GetMap {
    type Request = GetMap_Request;
    type Response = GetMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__GetMap() }
    }
}




#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__GetPlan() -> *const std::ffi::c_void;
}

// Corresponds to nav_msgs__srv__GetPlan
#[allow(missing_docs, non_camel_case_types)]
pub struct GetPlan;

impl rosidl_runtime_rs::Service for GetPlan {
    type Request = GetPlan_Request;
    type Response = GetPlan_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__GetPlan() }
    }
}




#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__LoadMap() -> *const std::ffi::c_void;
}

// Corresponds to nav_msgs__srv__LoadMap
#[allow(missing_docs, non_camel_case_types)]
pub struct LoadMap;

impl rosidl_runtime_rs::Service for LoadMap {
    type Request = LoadMap_Request;
    type Response = LoadMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__LoadMap() }
    }
}




#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__SetMap() -> *const std::ffi::c_void;
}

// Corresponds to nav_msgs__srv__SetMap
#[allow(missing_docs, non_camel_case_types)]
pub struct SetMap;

impl rosidl_runtime_rs::Service for SetMap {
    type Request = SetMap_Request;
    type Response = SetMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__SetMap() }
    }
}


