use ddl::AppPointCloud;

use crate::engine::types::{Engine};

pub struct CPUEngine<'a> {
    point_cloud : &'a AppPointCloud
}

impl<'a> CPUEngine<'a> {
    pub fn new(point_cloud : &'a AppPointCloud) -> Self {
        Self {
            point_cloud : point_cloud
        }
    }
}

impl<'a> Engine<> for CPUEngine<'a> {
    fn check(&self) -> Result<bool, anyhow::Error> {



        Ok(false)
    }
}