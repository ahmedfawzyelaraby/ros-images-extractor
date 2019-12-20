#ifndef CLI_PARSER
#define CLI_PARSER

#include <string>
#include <iostream>

#include <boost/program_options.hpp>

class cli_parser {
    public:
        cli_parser();
        ~cli_parser();
        void parse(int args_count, char** args_list);
        std::string getFilePath();
        std::string getTopicName();
        std::string getOutputPath();

    private:
        boost::program_options::options_description available_options_map;
        boost::program_options::variables_map parsed_options_map;
        const std::string options_separator = ",";
        const std::string help_option = "h";
        const std::string help_option_long = "help";
        const std::string help_option_description = "print help message";
        const std::string file_option = "f";
        const std::string file_option_long = "file";
        const std::string file_option_description = "set the ROS bag file to extract images from";
        const std::string topic_option = "t";
        const std::string topic_option_long = "topic";
        const std::string topic_option_description = "set the ROS topic on which images are loaded";
        const std::string output_option = "o";
        const std::string output_option_long = "output";
        const std::string output_option_description = "set the path to which images are saved";
};

#endif