//
// Created by yagdrassyl on 7/26/22.
//

#include "Screen.h"
#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../Misc/Misc.h"
#include "../Console/ConsoleMessage.h"
#include <string>

namespace Game {


    void Screen::init_window_hints() {

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    Screen::Screen(ScreenOptions options) {
        init_window_hints();

        auto screen_dims = new ScreenDimensions{
                .width = Misc::firstOrDefault<int>(options.window_width, 800),
                .height = Misc::firstOrDefault<int>(options.window_height, 600)
        };


        window_data = new ScreenData{
                .dimensions = screen_dims,
                .title = Misc::firstOrDefault<char *>(options.window_title, (char *) "New Window")
        };

        std::string info = "Started a new window with title \"";
        info += window_data->title;
        info += "\"";
        ConsoleMessage::info(info);
        window = nullptr;
    }

    Screen::~Screen() {
        delete window_data;
        glfwTerminate();
    }

    bool Screen::terminate_if(bool assertion, char *error) {
        if (assertion) {
            ConsoleMessage::error(error);
            fprintf(stderr, "%s\n", error);
            getchar();
            glfwTerminate();
            throw;
        }
        return assertion;
    }

    bool Screen::init() {

        terminate_if(!glfwInit(), (char*)"Failed to initialize GLFW");

        window = glfwCreateWindow(window_data->dimensions->width, window_data->dimensions->height, window_data->title,
                                  nullptr, nullptr);

        terminate_if(window == nullptr, (char *) "Failed to open GLFW window.");

        glfwMakeContextCurrent(window);

        terminate_if(glewInit() != GLEW_OK, (char *) "Failed to initialize GLEW");
        return true;
    }

    GLFWwindow* Screen::getWindow() {
        if (!window) {
            ConsoleMessage::warning("Trying to access window while it doesn't exist");
        }
        return window;
    }

    void Screen::run() {
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        do {
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            glfwPollEvents();

        } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
                 glfwWindowShouldClose(window) == 0);
    }
} // Game