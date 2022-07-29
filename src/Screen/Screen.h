//
// Created by yagdrassyl on 7/26/22.
//

#ifndef PONG_OPENGL_SCREEN_H
#define PONG_OPENGL_SCREEN_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Game {

    struct ScreenOptions {
        int window_width;
        int window_height;
        char* window_title;
        ~ScreenOptions() = default;
    };

    struct ScreenDimensions {
        int width;
        int height;
        ~ScreenDimensions()= default;
    };

    struct ScreenData {
        ScreenDimensions* dimensions;
        char *title;

        ~ScreenData() {
            delete dimensions;
        }
    };

    class Screen {
    public:
        explicit Screen(ScreenOptions options);
        bool init();
        void run();

        GLFWwindow* getWindow();
        ~Screen();

    private:
        static void init_window_hints();
        static bool terminate_if(bool assertion, char* error);
        GLFWwindow *window;
        ScreenData *window_data;
    };

} // Game

#endif //PONG_OPENGL_SCREEN_H
