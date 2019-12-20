#include "extractor.h"
#include "cli_parser.h"

int main(int argc, char** argv) {
    cli_parser parser;
    parser.parse(argc, argv);

    std::vector<std::string> topics;
    topics.push_back(parser.getTopicName());

    std::vector<std::string> pathes;
    pathes.push_back(parser.getOutputPath());

    extractor extractFile(parser.getFilePath(),
        topics, pathes);
    extractFile.extract();
    
}