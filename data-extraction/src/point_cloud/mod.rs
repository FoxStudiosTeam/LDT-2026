mod parser;
mod parser_to_rust;

use std::error::Error;
use parser::ParseError;
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;

#[derive(Debug, Clone)]
pub struct PointCloud {
    pub header: Header,
    pub width: u32,
    pub height: u32,
    pub fields: Vec<Field>,
    pub points: Vec<Point>,
    pub is_dense: bool,
}

#[derive(Debug, Clone)]
pub struct Header {
    pub stamp: Time,
    pub frame_id: String,
}

#[derive(Debug, Clone, Copy)]
pub struct Time {
    pub sec: i32,
    pub nanosec: u32,
}

#[derive(Debug, Clone)]
pub struct Field {
    pub name: String,
    pub offset: u32,
    pub datatype: u8,
    pub count: u32,
}

#[derive(Debug, Clone, Default)]
pub struct Point {
    pub x: Option<f32>,
    pub y: Option<f32>,
    pub z: Option<f32>,
    pub intensity: Option<f32>,
    pub ring: Option<u16>,
    pub timestamp: Option<f64>,
}

pub fn new(message: PointCloud2) -> Result<PointCloud, ParseError> {
    parser::parse_pointcloud(message)
}