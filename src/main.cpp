
#include "./Screen/Screen.h"
#include "Console/ConsoleMessage.h"

int main() {
    // Initialise GLFW
    auto screen = new Game::Screen(Game::ScreenOptions{
            .window_width = 600,
            .window_height = 800,
            .window_title = (char *) "My Game",
    });

    screen->init();
    screen->run();

    ConsoleMessage::info("All done");
    return 0;
}