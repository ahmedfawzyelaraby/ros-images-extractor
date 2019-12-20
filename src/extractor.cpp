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
        boost::filesystem::path current_topic_path(this->output_pathes[i]);
        boost::filesystem::create_directories(current_topic_path);

        std::vector<std::string> current_topic;
        current_topic.push_back(this->search_topics[i]);

        rosbag::View ros_bag_query(this->ros_bag_data_file, rosbag::TopicQuery(current_topic));

        int counter = 0;
        BOOST_FOREACH(rosbag::MessageInstance const current_message, ros_bag_query) {
            sensor_msgs::Image::ConstPtr current_message_ptr = current_message.instantiate<sensor_msgs::Image>();
            if(current_message_ptr != NULL){
                cv_bridge::CvImagePtr ros_ptr_to_opencv_image = cv_bridge::toCvCopy(current_message_ptr,
                    current_message_ptr->encoding);
                cv::Mat current_image = ros_ptr_to_opencv_image->image;
                cv::imwrite(this->output_pathes[i] + this->directory_separator + std::to_string(counter)
                + this->image_format, current_image);
                counter++;
            }
        }
    }
}