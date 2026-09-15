#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to map_msgs__msg__OccupancyGridUpdate

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OccupancyGridUpdate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    pub data: Vec<i8>,

}



impl Default for OccupancyGridUpdate {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OccupancyGridUpdate::default())
  }
}

impl rosidl_runtime_rs::Message for OccupancyGridUpdate {
  type RmwMsg = super::msg::rmw::OccupancyGridUpdate;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        x: msg.x,
        y: msg.y,
        width: msg.width,
        height: msg.height,
        data: msg.data.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      x: msg.x,
      y: msg.y,
      width: msg.width,
      height: msg.height,
        data: msg.data.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      x: msg.x,
      y: msg.y,
      width: msg.width,
      height: msg.height,
      data: msg.data.into(),
    }
  }
}


// Corresponds to map_msgs__msg__PointCloud2Update

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PointCloud2Update {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// type of update, one of ADD or DELETE
    pub type_: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub points: sensor_msgs::msg::PointCloud2,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PointCloud2Update::default())
  }
}

impl rosidl_runtime_rs::Message for PointCloud2Update {
  type RmwMsg = super::msg::rmw::PointCloud2Update;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        type_: msg.type_,
        points: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Owned(msg.points)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      type_: msg.type_,
        points: sensor_msgs::msg::PointCloud2::into_rmw_message(std::borrow::Cow::Borrowed(&msg.points)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      type_: msg.type_,
      points: sensor_msgs::msg::PointCloud2::from_rmw_message(msg.points),
    }
  }
}


// Corresponds to map_msgs__msg__ProjectedMapInfo

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProjectedMapInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub frame_id: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ProjectedMapInfo::default())
  }
}

impl rosidl_runtime_rs::Message for ProjectedMapInfo {
  type RmwMsg = super::msg::rmw::ProjectedMapInfo;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        frame_id: msg.frame_id.as_str().into(),
        x: msg.x,
        y: msg.y,
        width: msg.width,
        height: msg.height,
        min_z: msg.min_z,
        max_z: msg.max_z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        frame_id: msg.frame_id.as_str().into(),
      x: msg.x,
      y: msg.y,
      width: msg.width,
      height: msg.height,
      min_z: msg.min_z,
      max_z: msg.max_z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      frame_id: msg.frame_id.to_string(),
      x: msg.x,
      y: msg.y,
      width: msg.width,
      height: msg.height,
      min_z: msg.min_z,
      max_z: msg.max_z,
    }
  }
}


// Corresponds to map_msgs__msg__ProjectedMap

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProjectedMap {

    // This member is not documented.
    #[allow(missing_docs)]
    pub map: nav_msgs::msg::OccupancyGrid,


    // This member is not documented.
    #[allow(missing_docs)]
    pub min_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_z: f64,

}



impl Default for ProjectedMap {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ProjectedMap::default())
  }
}

impl rosidl_runtime_rs::Message for ProjectedMap {
  type RmwMsg = super::msg::rmw::ProjectedMap;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: nav_msgs::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Owned(msg.map)).into_owned(),
        min_z: msg.min_z,
        max_z: msg.max_z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map: nav_msgs::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Borrowed(&msg.map)).into_owned(),
      min_z: msg.min_z,
      max_z: msg.max_z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      map: nav_msgs::msg::OccupancyGrid::from_rmw_message(msg.map),
      min_z: msg.min_z,
      max_z: msg.max_z,
    }
  }
}


