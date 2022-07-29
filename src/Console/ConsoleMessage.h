//
// Created by yagdrassyl on 7/28/22.
//

#ifndef PONG_OPENGL_CONSOLEMESSAGE_H
#define PONG_OPENGL_CONSOLEMESSAGE_H
#include <string>
enum Color {
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    RESET = 0
};

class ConsoleMessage {
public:
    static void info(char *message);
    static void info(std::string message);

    static void warning(char *message);
    static void warning(std::string message);

    static void error(char *message);
    static void error(std::string message);

private:
    static void printMessage(char* level, char *message, Color color);

};


#endif //PONG_OPENGL_CONSOLEMESSAGE_H
