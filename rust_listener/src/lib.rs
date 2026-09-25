pub mod debug;
pub mod engine;

kaiv_utils::env_config! {
    ".env" => pub ENV = pub Env {
        RERUN_URL : String = "rerun+http://host.docker.internal:9876/proxy".to_string(),
        ROS_DOMAIN_ID : u16 = 42,
        PROCESS_START_TIMESTAMP : u64 = 0,
        TOTAL_FRAMES : u64 = u64::MAX,
        TEST_RERUN : bool = false,
        BEGIN_TIMESTAMP : i64 = 0,
        PREVIEW_FOV_X_DEG : f32 = 180.0,
        RENDER_PATH : String = "".to_string()
    }
}
