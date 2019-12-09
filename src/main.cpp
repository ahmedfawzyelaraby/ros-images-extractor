#include "extractor.h"

int main(int argc, char** argv) {
    std::vector<std::string> topics;
    topics.push_back("/kinect2/hd/image_color");

    std::vector<std::string> pathes;
    pathes.push_back("output");

    extractor extractFile("/home/ahmedfawzyelaraby/workspace/datasets/Kinect Testing ROSbags/depth-estimation-dataset_0.bag",
        topics, pathes);
    extractFile.extract();
}