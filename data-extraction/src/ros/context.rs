use ros2_client::Context;

pub fn create_context() -> Result<Context, ros2_client::ros2::CreateError> {
    Context::new()
}