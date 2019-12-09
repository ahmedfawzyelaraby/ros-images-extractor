#include "extractor.h"

extractor::extractor(std::string path_to_ros_bag_data_file, std::vector<std::string> input_search_topics,
            std::vector<std::string> input_output_pathes) {
    this->search_topics = input_search_topics;
    this->output_pathes = input_output_pathes;
    this->ros_bag_data_file.open(path_to_ros_bag_data_file, rosbag::bagmode::Read);
}

extractor::~extractor() {
    this->ros_bag_data_file.close();
}

void extractor::extract() {
    for(int i = 0; i < this->search_topics.size(); i++) {
        std::vector<std::string> current_topic;
        current_topic.push_back(this->search_topics[i]);

        rosbag::View ros_bag_query(this->ros_bag_data_file, rosbag::TopicQuery(current_topic));

        BOOST_FOREACH(rosbag::MessageInstance const current_message, ros_bag_query) {
            sensor_msgs::Image::ConstPtr current_message_ptr = current_message.instantiate<sensor_msgs::Image>();
            if(current_message_ptr != NULL)
                std::cout << "Image Found" << std::endl;
        }
    }
}