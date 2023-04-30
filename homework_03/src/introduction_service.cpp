#include <iostream>
#include "introduction_service.h"

std::string introducing(int max_value) {
    std::string user_name = "";
    std::cout << "Enter your name:" << std::endl;
    std::getline(std::cin, user_name);
    std::string msg = "";
    msg.append("Hi, ")
        .append(user_name)
        .append("!\r\n")
        .append("Let's play!\r\n")
        .append("I'm thiking of a number from 0 to ")
        .append(std::to_string(max_value))
        .append("\r\n")
        .append("You need to guess this number.\r\n");
    std::cout << msg << std::endl;
    return user_name;
}