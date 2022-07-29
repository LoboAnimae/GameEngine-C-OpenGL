cmake_minimum_required(VERSION 3.22)
project(Pong_OpenGL)

find_package(OpenGL REQUIRED)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(external)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )
add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)


add_executable(Pong_OpenGL src/main.cpp src/Screen/Screen.cpp src/Screen/Screen.h src/Misc/Misc.cpp src/Misc/Misc.h src/Screen/Layer.cpp src/Screen/Layer.h src/Console/ConsoleMessage.cpp src/Console/ConsoleMessage.h)



target_link_libraries(${PROJECT_NAME}
        ${ALL_LIBS}
        )