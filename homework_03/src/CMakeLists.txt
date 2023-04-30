cmake_minimum_required(VERSION 3.12)

project(guess_number_game)

add_executable(guess_number_game 
    guess_number_game.cpp
    introduction_service.h
    introduction_service.cpp
    scores_service.h
    scores_service.cpp
    game_service.h
    game_service.cpp)

set_target_properties(guess_number_game PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)