#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const std::string scores_file_name = "scores.csv";

void save_result(const std::string &user_name, int attempts) {
    std::ofstream o_scores_file(scores_file_name, std::ios_base::app);
    if (!o_scores_file.is_open()) {
        std::string err_msg = "";
        err_msg.append("Can't open file ")
            .append(scores_file_name)
            .append(". State = ")
            .append(std::to_string(o_scores_file.rdstate()));
        throw std::runtime_error(err_msg);
    }
    o_scores_file << "\"" << user_name << "\"," << attempts << std::endl;
    o_scores_file.close();
}

void print_results() {
    std::ifstream i_scores_file(scores_file_name);
    if (!i_scores_file.is_open()) {
        std::string err_msg = "";
        err_msg.append("Can't open file ")
            .append(scores_file_name)
            .append(". State = ")
            .append(std::to_string(i_scores_file.rdstate()));
        throw std::runtime_error(err_msg);
    }
    std::cout << "High scores table:" << std::endl;
    std::string text_line;
    while(std::getline(i_scores_file, text_line)) {
        std::istringstream str_stream(text_line);
        std::string substring{};
        while (std::getline(str_stream, substring, ',')) {
            std::cout << substring << " ";
        }
        std::cout << "\r\n";
    }
    i_scores_file.close();
}
