#include "cli_parser.h"

cli_parser::cli_parser() {
    this->available_options_map.add_options()(
        (this->help_option_long + this->options_separator + 
        this->help_option).c_str(), this->help_option_description.c_str())(
        (this->file_option_long + this->options_separator + 
        this->file_option).c_str(), boost::program_options::value<std::string>()
        ,this->file_option_description.c_str())(
        (this->topic_option_long + this->options_separator + 
        this->topic_option).c_str(), boost::program_options::value<std::string>(),
        this->topic_option_description.c_str())(
        (this->output_option_long + this->options_separator + 
        this->output_option).c_str(), boost::program_options::value<std::string>(),
        this->output_option_description.c_str());
}

cli_parser::~cli_parser() {}

void cli_parser::parse(int args_count, char** args_list) {
    boost::program_options::store(boost::program_options::parse_command_line(
        args_count, args_list, this->available_options_map), this->parsed_options_map);
    boost::program_options::notify(this->parsed_options_map);

    if(this->parsed_options_map.count(this->help_option_long)){
        std::cout << this->available_options_map << std::endl;
        exit(EXIT_SUCCESS);
    }

    if(!(this->parsed_options_map.count(this->file_option_long))){
        std::cout << "Please specify the file you want to extract images from" << std::endl << std::endl;
        std::cout << this->available_options_map << std::endl;
        exit(EXIT_SUCCESS);
    }

    if(!(this->parsed_options_map.count(this->topic_option_long))){
        std::cout << "Please specify the topic from which you want to extract images" << std::endl << std::endl;
        std::cout << this->available_options_map << std::endl;
        exit(EXIT_SUCCESS);
    }

    if(!(this->parsed_options_map.count(this->output_option_long))){
        std::cout << "Please specify the path you want to extract images to" << std::endl << std::endl;
        std::cout << this->available_options_map << std::endl;
        exit(EXIT_SUCCESS);
    }
}

std::string cli_parser::getFilePath() {
    return this->parsed_options_map[this->file_option_long].as<std::string>();
}

std::string cli_parser::getTopicName() {
    return this->parsed_options_map[this->topic_option_long].as<std::string>();
}

std::string cli_parser::getOutputPath() {
    return this->parsed_options_map[this->output_option_long].as<std::string>();
}