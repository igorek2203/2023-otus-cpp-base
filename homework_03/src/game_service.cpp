#include <iostream>
#include <string>
#include <ctime>
#include "game_service.h"

bool is_guessed_value(int random_number, int guess_number) {
    bool result = false;
    if (random_number > guess_number) {
        std::cout << "greater than " << guess_number << std::endl;
    } else if (random_number < guess_number) {
        std::cout << "less than " << guess_number << std::endl;
    } else {
        result = true;
        std::cout << "you win!" << std::endl;
    }
    return result;
}

int start_play(int max_value) {
    std::srand(std::time(nullptr));
    int random_number = std::rand() % max_value;
    int guess_number = -1;
    int attempts = 0;
    do {
        std::cout << "Enter your guess: " << std::endl;
        std::cin >> guess_number;
        if (!std::cin.good()) {
            std::cin.clear();
            char chr;
            std::cin >> chr;
            std::cerr << "Bad char detected " << chr << std::endl;
            continue;
        }
        attempts++;
    } while (!is_guessed_value(random_number, guess_number));
    std::cout << "attempts " << attempts << std::endl;
    return attempts;
}
