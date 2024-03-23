#pragma region // Includes.
#include <cstdlib>
#include <iostream>

// Need this man first!
#include <GL/glew.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#pragma endregion

int main() {
    // Initialize GLFW:
    glfwInit();

    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW failed!" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    int numMonitors;
    if (GLFWmonitor **monitors = glfwGetMonitors(&numMonitors)) {
        std::cout << "Monitors list:" << std::endl;
        while (numMonitors > -1)
            std::cout << glfwGetMonitorName(monitors[--numMonitors]) << std::endl;
        std::cout << "(End of monitors list.)" << std::endl;
    } else {
        std::cerr << "No monitors! Exiting..." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // Create a windowed mode window and its OpenGL context:
    GLFWwindow *window = glfwCreateWindow(640, 480, "GL/GLFW/GLEW Test", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        std::cerr << "\"Nope!\", said `glfwCreateWindow()`" << std::endl;
        return -1;
    }

    // Make the window's context current:
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window:
    while (!glfwWindowShouldClose(window)) {
        // Swap front and back buffers:
        glfwSwapBuffers(window);

        // Poll for and process events:
        glfwPollEvents();
    }

    // Terminate GLFW:
    glfwDestroyWindow(window);
    glfwTerminate();
}
