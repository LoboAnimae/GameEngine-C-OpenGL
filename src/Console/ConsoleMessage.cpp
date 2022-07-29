//
// Created by yagdrassyl on 7/28/22.
//

#include "ConsoleMessage.h"
#include <iostream>

void ConsoleMessage::printMessage(char* level, char *message, Color color) {
    std::cout << "\033[" << color << "m" << level << "\033[" << RESET << "m" << message << std::endl;
}

void ConsoleMessage::info(char *message) {
    ConsoleMessage::printMessage((char*)"[ INFO ] ", message, BLUE);
}

void ConsoleMessage::warning(char *message) {
    ConsoleMessage::printMessage((char*)"[ WARNING ] ", message, YELLOW);

}

void ConsoleMessage::error(char *message) {
    ConsoleMessage::printMessage((char*)"[ ERROR ] ", message, RED);
}

void ConsoleMessage::info(std::string message) {
    ConsoleMessage::printMessage((char*)"[ INFO ] ", (char *)message.c_str(), BLUE);
}

void ConsoleMessage::warning(std::string message) {
    ConsoleMessage::printMessage((char*)"[ WARNING ] ", (char*)message.c_str(), YELLOW);

}

void ConsoleMessage::error(std::string message) {
    ConsoleMessage::printMessage((char*)"[ ERROR ] ", (char*)message.c_str(), RED);
}