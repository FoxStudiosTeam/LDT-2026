#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to nav_msgs__msg__Goals
/// An array of navigation goals

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Goals {
    /// This header will store the time at which the poses were computed (not to be confused with the stamps of the poses themselves)
    /// In the case that individual poses do not have their frame_id set or their timetamp set they will use the default value here.
    pub header: std_msgs::msg::Header,

    /// An array of goals to for navigation to achieve.
    /// The goals should be executed in the order of the array.
    /// The header and stamp are intended to be used for computing the position of the goals.
    /// They may vary to support cases of goals that are moving with respect to the robot.
    pub goals: Vec<geometry_msgs::msg::PoseStamped>,

}



impl Default for Goals {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Goals::default())
  }
}

impl rosidl_runtime_rs::Message for Goals {
  type RmwMsg = super::msg::rmw::Goals;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        goals: msg.goals
          .into_iter()
          .map(|elem| geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        goals: msg.goals
          .iter()
          .map(|elem| geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      goals: msg.goals
          .into_iter()
          .map(geometry_msgs::msg::PoseStamped::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to nav_msgs__msg__GridCells
/// An array of cells in a 2D grid

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GridCells {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Width of each cell
    pub cell_width: f32,

    /// Height of each cell
    pub cell_height: f32,

    /// Each cell is represented by the Point at the center of the cell
    pub cells: Vec<geometry_msgs::msg::Point>,

}



impl Default for GridCells {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GridCells::default())
  }
}

impl rosidl_runtime_rs::Message for GridCells {
  type RmwMsg = super::msg::rmw::GridCells;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        cell_width: msg.cell_width,
        cell_height: msg.cell_height,
        cells: msg.cells
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      cell_width: msg.cell_width,
      cell_height: msg.cell_height,
        cells: msg.cells
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      cell_width: msg.cell_width,
      cell_height: msg.cell_height,
      cells: msg.cells
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to nav_msgs__msg__MapMetaData
/// This hold basic information about the characteristics of the OccupancyGrid

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MapMetaData {
    /// The time at which the map was loaded
    pub map_load_time: builtin_interfaces::msg::Time,

    /// The map resolution
    pub resolution: f32,

    /// Map width
    pub width: u32,

    /// Map height
    pub height: u32,

    /// The origin of the map [m, m, rad].  This is the real-world pose of the
    /// bottom left corner of cell (0,0) in the map.
    pub origin: geometry_msgs::msg::Pose,

}



impl Default for MapMetaData {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MapMetaData::default())
  }
}

impl rosidl_runtime_rs::Message for MapMetaData {
  type RmwMsg = super::msg::rmw::MapMetaData;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map_load_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.map_load_time)).into_owned(),
        resolution: msg.resolution,
        width: msg.width,
        height: msg.height,
        origin: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.origin)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        map_load_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.map_load_time)).into_owned(),
      resolution: msg.resolution,
      width: msg.width,
      height: msg.height,
        origin: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.origin)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      map_load_time: builtin_interfaces::msg::Time::from_rmw_message(msg.map_load_time),
      resolution: msg.resolution,
      width: msg.width,
      height: msg.height,
      origin: geometry_msgs::msg::Pose::from_rmw_message(msg.origin),
    }
  }
}


// Corresponds to nav_msgs__msg__OccupancyGrid
/// This represents a 2-D grid map

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OccupancyGrid {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// MetaData for the map
    pub info: super::msg::MapMetaData,

    /// The map data, in row-major order, starting with (0,0).
    /// Cell (1, 0) will be listed second, representing the next cell in the x direction.
    /// Cell (0, 1) will be at the index equal to info.width, followed by (1, 1).
    /// The values inside are application dependent, but frequently,
    /// 0 represents unoccupied, 1 represents definitely occupied, and
    /// -1 represents unknown.
    pub data: Vec<i8>,

}



impl Default for OccupancyGrid {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OccupancyGrid::default())
  }
}

impl rosidl_runtime_rs::Message for OccupancyGrid {
  type RmwMsg = super::msg::rmw::OccupancyGrid;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        info: super::msg::MapMetaData::into_rmw_message(std::borrow::Cow::Owned(msg.info)).into_owned(),
        data: msg.data.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        info: super::msg::MapMetaData::into_rmw_message(std::borrow::Cow::Borrowed(&msg.info)).into_owned(),
        data: msg.data.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      info: super::msg::MapMetaData::from_rmw_message(msg.info),
      data: msg.data.into(),
    }
  }
}


// Corresponds to nav_msgs__msg__Odometry
/// This represents an estimate of a position and velocity in free space.
/// The pose in this message should be specified in the coordinate frame given by header.frame_id
/// The twist in this message should be specified in the coordinate frame given by the child_frame_id

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Odometry {
    /// Includes the frame id of the pose parent.
    pub header: std_msgs::msg::Header,

    /// Frame id the pose points to. The twist is in this coordinate frame.
    pub child_frame_id: std::string::String,

    /// Estimated pose that is typically relative to a fixed world frame.
    pub pose: geometry_msgs::msg::PoseWithCovariance,

    /// Estimated linear and angular velocity relative to child_frame_id.
    pub twist: geometry_msgs::msg::TwistWithCovariance,

}



impl Default for Odometry {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Odometry::default())
  }
}

impl rosidl_runtime_rs::Message for Odometry {
  type RmwMsg = super::msg::rmw::Odometry;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        child_frame_id: msg.child_frame_id.as_str().into(),
        pose: geometry_msgs::msg::PoseWithCovariance::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        twist: geometry_msgs::msg::TwistWithCovariance::into_rmw_message(std::borrow::Cow::Owned(msg.twist)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        child_frame_id: msg.child_frame_id.as_str().into(),
        pose: geometry_msgs::msg::PoseWithCovariance::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
        twist: geometry_msgs::msg::TwistWithCovariance::into_rmw_message(std::borrow::Cow::Borrowed(&msg.twist)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      child_frame_id: msg.child_frame_id.to_string(),
      pose: geometry_msgs::msg::PoseWithCovariance::from_rmw_message(msg.pose),
      twist: geometry_msgs::msg::TwistWithCovariance::from_rmw_message(msg.twist),
    }
  }
}


// Corresponds to nav_msgs__msg__Path
/// An array of poses that represents a Path for a robot to follow.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Path {
    /// Indicates the frame_id of the path.
    pub header: std_msgs::msg::Header,

    /// Array of poses to follow.
    pub poses: Vec<geometry_msgs::msg::PoseStamped>,

}



impl Default for Path {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Path::default())
  }
}

impl rosidl_runtime_rs::Message for Path {
  type RmwMsg = super::msg::rmw::Path;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        poses: msg.poses
          .into_iter()
          .map(|elem| geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        poses: msg.poses
          .iter()
          .map(|elem| geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      poses: msg.poses
          .into_iter()
          .map(geometry_msgs::msg::PoseStamped::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to nav_msgs__msg__Trajectory
/// An array of trajectory points that represents a trajectory for a robot to follow.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Trajectory {
    /// Indicates the frame_id in which the planner ran and timestamp represents when the trajectory was generated.
    pub header: std_msgs::msg::Header,

    /// Array of trajectory points to follow.
    pub points: Vec<super::msg::TrajectoryPoint>,

}



impl Default for Trajectory {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Trajectory::default())
  }
}

impl rosidl_runtime_rs::Message for Trajectory {
  type RmwMsg = super::msg::rmw::Trajectory;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        points: msg.points
          .into_iter()
          .map(|elem| super::msg::TrajectoryPoint::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        points: msg.points
          .iter()
          .map(|elem| super::msg::TrajectoryPoint::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      points: msg.points
          .into_iter()
          .map(super::msg::TrajectoryPoint::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to nav_msgs__msg__TrajectoryPoint
/// Trajectory point state

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrajectoryPoint {
    /// Absolute time and frame of reference of the point along a trajectory
    pub header: std_msgs::msg::Header,

    /// Pose of the trajectory sample.
    pub pose: geometry_msgs::msg::Pose,

    /// Velocity of the trajectory sample.
    pub velocity: geometry_msgs::msg::Twist,

    /// Acceleration of the trajectory (optional, linear.x component is NaN if not set).
    pub acceleration: geometry_msgs::msg::Accel,

    /// Force/Torque to apply at trajectory sample (optional, force.x component is NaN if not set).
    pub effort: geometry_msgs::msg::Wrench,

}



impl Default for TrajectoryPoint {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TrajectoryPoint::default())
  }
}

impl rosidl_runtime_rs::Message for TrajectoryPoint {
  type RmwMsg = super::msg::rmw::TrajectoryPoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        velocity: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Owned(msg.velocity)).into_owned(),
        acceleration: geometry_msgs::msg::Accel::into_rmw_message(std::borrow::Cow::Owned(msg.acceleration)).into_owned(),
        effort: geometry_msgs::msg::Wrench::into_rmw_message(std::borrow::Cow::Owned(msg.effort)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
        velocity: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Borrowed(&msg.velocity)).into_owned(),
        acceleration: geometry_msgs::msg::Accel::into_rmw_message(std::borrow::Cow::Borrowed(&msg.acceleration)).into_owned(),
        effort: geometry_msgs::msg::Wrench::into_rmw_message(std::borrow::Cow::Borrowed(&msg.effort)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
      velocity: geometry_msgs::msg::Twist::from_rmw_message(msg.velocity),
      acceleration: geometry_msgs::msg::Accel::from_rmw_message(msg.acceleration),
      effort: geometry_msgs::msg::Wrench::from_rmw_message(msg.effort),
    }
  }
}


