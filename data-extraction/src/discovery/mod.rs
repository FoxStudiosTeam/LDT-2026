use ros2_client::Context;

pub struct Topic {
    pub name: String,
    pub msg_type: String,
}

pub fn discover_topics(context: &Context) -> Result<Vec<Topic>, String> {
    let raw_topics = context.discovered_topics();

    let topics: Vec<Topic> = raw_topics.into_iter()
        // .filter(|r| r.type_name().contains("2"))
        .map(|raw_topic| {
            Topic {
                name: raw_topic.topic_name().to_string(),
                msg_type: raw_topic.type_name().to_string()
            }
        }).collect();

    if topics.is_empty() {
        return Err("No topics found.".to_string())
    }
    Ok(topics)
}