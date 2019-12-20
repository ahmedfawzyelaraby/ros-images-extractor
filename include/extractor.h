#ifndef EXTRACTOR
#define EXTRACTOR

#include <string>
#include <vector>

#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>

class extractor {
    private:
        rosbag::Bag ros_bag_data_file;
        std::vector<std::string> search_topics;
        std::vector<std::string> output_pathes;
        const std::string directory_separator = "/";
        const std::string image_format = ".png";

    public:
        extractor(std::string path_to_ros_bag_data_file, std::vector<std::string> input_search_topics,
            std::vector<std::string> input_output_pathes);
        ~extractor();
        void extract();
};

#endif