#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to shape_msgs__msg__Mesh
/// Definition of a mesh.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Mesh {
    /// List of triangles; the index values refer to positions in vertices[].
    pub triangles: Vec<super::msg::MeshTriangle>,

    /// The actual vertices that make up the mesh.
    pub vertices: Vec<geometry_msgs::msg::Point>,

}



impl Default for Mesh {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Mesh::default())
  }
}

impl rosidl_runtime_rs::Message for Mesh {
  type RmwMsg = super::msg::rmw::Mesh;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        triangles: msg.triangles
          .into_iter()
          .map(|elem| super::msg::MeshTriangle::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        vertices: msg.vertices
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        triangles: msg.triangles
          .iter()
          .map(|elem| super::msg::MeshTriangle::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        vertices: msg.vertices
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      triangles: msg.triangles
          .into_iter()
          .map(super::msg::MeshTriangle::from_rmw_message)
          .collect(),
      vertices: msg.vertices
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to shape_msgs__msg__MeshTriangle
/// Definition of a triangle's vertices.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MeshTriangle {

    // This member is not documented.
    #[allow(missing_docs)]
    pub vertex_indices: [u32; 3],

}



impl Default for MeshTriangle {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MeshTriangle::default())
  }
}

impl rosidl_runtime_rs::Message for MeshTriangle {
  type RmwMsg = super::msg::rmw::MeshTriangle;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        vertex_indices: msg.vertex_indices,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        vertex_indices: msg.vertex_indices,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      vertex_indices: msg.vertex_indices,
    }
  }
}


// Corresponds to shape_msgs__msg__Plane
/// Representation of a plane, using the plane equation ax + by + cz + d = 0.
///
/// a := coef[0]
/// b := coef[1]
/// c := coef[2]
/// d := coef[3]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Plane {

    // This member is not documented.
    #[allow(missing_docs)]
    pub coef: [f64; 4],

}



impl Default for Plane {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Plane::default())
  }
}

impl rosidl_runtime_rs::Message for Plane {
  type RmwMsg = super::msg::rmw::Plane;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        coef: msg.coef,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        coef: msg.coef,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      coef: msg.coef,
    }
  }
}


// Corresponds to shape_msgs__msg__SolidPrimitive
/// Defines box, sphere, cylinder, cone and prism.
/// All shapes are defined to have their bounding boxes centered around 0,0,0.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SolidPrimitive {
    /// The type of the shape
    pub type_: u8,

    /// The dimensions of the shape
    /// At no point will dimensions have a length > 3.
    pub dimensions: rosidl_runtime_rs::BoundedSequence<f64, 3>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub polygon: geometry_msgs::msg::Polygon,

}

impl SolidPrimitive {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BOX: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPHERE: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CYLINDER: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONE: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PRISM: u8 = 5;

    /// The meaning of the shape dimensions: each constant defines the index in the 'dimensions' array.
    /// For type BOX, the X, Y, and Z dimensions are the length of the corresponding sides of the box.
    pub const BOX_X: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BOX_Y: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BOX_Z: u8 = 2;

    /// For the SPHERE type, only one component is used, and it gives the radius of the sphere.
    pub const SPHERE_RADIUS: u8 = 0;

    /// For the CYLINDER and CONE types, the center line is oriented along the Z axis.
    /// Therefore the CYLINDER_HEIGHT (CONE_HEIGHT) component of dimensions gives the
    /// height of the cylinder (cone).
    /// The CYLINDER_RADIUS (CONE_RADIUS) component of dimensions gives the radius of
    /// the base of the cylinder (cone).
    /// Cone and cylinder primitives are defined to be circular. The tip of the cone
    /// is pointing up, along +Z axis.
    pub const CYLINDER_HEIGHT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CYLINDER_RADIUS: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONE_HEIGHT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONE_RADIUS: u8 = 1;

    /// For the type PRISM, the center line is oriented along Z axis.
    /// The PRISM_HEIGHT component of dimensions gives the
    /// height of the prism.
    /// The polygon defines the Z axis centered base of the prism.
    /// The prism is constructed by extruding the base in +Z and -Z
    /// directions by half of the PRISM_HEIGHT
    /// Only x and y fields of the points are used in the polygon.
    /// Points of the polygon are ordered counter-clockwise.
    pub const PRISM_HEIGHT: u8 = 0;

}


impl Default for SolidPrimitive {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SolidPrimitive::default())
  }
}

impl rosidl_runtime_rs::Message for SolidPrimitive {
  type RmwMsg = super::msg::rmw::SolidPrimitive;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_: msg.type_,
        dimensions: msg.dimensions,
        polygon: geometry_msgs::msg::Polygon::into_rmw_message(std::borrow::Cow::Owned(msg.polygon)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      type_: msg.type_,
        dimensions: msg.dimensions.clone(),
        polygon: geometry_msgs::msg::Polygon::into_rmw_message(std::borrow::Cow::Borrowed(&msg.polygon)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_: msg.type_,
      dimensions: msg.dimensions,
      polygon: geometry_msgs::msg::Polygon::from_rmw_message(msg.polygon),
    }
  }
}


