#include <iostream>
#include <string>
#include "introduction_service.h"
#include "scores_service.h"
#include "game_service.h"

void init_args(int argc, char** argv, int &max_value, bool &only_print_results) {
    int i = 1;
    while (i < argc) {
        std::string arg_name{ argv[i] };
        if (arg_name == "-max" || arg_name == "--max") {
            max_value = std::stoi(argv[i + 1]);
            i += 2;
            continue;
        }
        if (arg_name == "-table" || arg_name == "--table") {
            only_print_results = true;
            i++;
            continue;
        }
        i++;
    }
}

int main(int argc, char** argv) {
    int max_value = 100;
    bool only_print_results = false;
    if (argc > 0) {
        init_args(argc, argv, max_value, only_print_results);
    }
    if (!only_print_results) {
        std::string user_name = introducing(max_value);
        int attempts = start_play(max_value);
        try {
            save_result(user_name, attempts);
        } catch (std::runtime_error& ex) {
            std::cerr << "Error while saving scores for user " << user_name << ". Details: " << ex.what() << std::endl;
            return -1;
        }
    }
    try {
        print_results();
    } catch (std::runtime_error& ex) {
        std::cerr << "Error while reading scores. Details: " << ex.what() << std::endl;
        return -1;
    }
    return 0;
}