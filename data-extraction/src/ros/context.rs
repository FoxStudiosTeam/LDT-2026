use std::env;
use ros2_client::{Context, ContextOptions};

pub fn create_context() -> Result<Context, ros2_client::ros2::CreateError> {
    let opt = ContextOptions::new().domain_id(
        env::var("ROS_DOMAIN_ID")
        .ok()
        .and_then(|value| value.parse::<u16>().ok())
        .unwrap_or(0)
    );
    Context::with_options(opt)
}