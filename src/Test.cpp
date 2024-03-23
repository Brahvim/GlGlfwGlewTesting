#include <cstdlib>
#include <iostream>

#include <GL/gl.h>
// #include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    // Initialize GLFW:
    glfwInit();

    int numMonitors;
    if (GLFWmonitor **monitors = glfwGetMonitors(&numMonitors)) {
        std::cout << "Monitors list:" << std::endl;
        while (numMonitors > -1)
            std::cout << glfwGetMonitorName(monitors[--numMonitors]) << std::endl;
        std::cout << "(End of monitors list.)" << std::endl;
    } else
        std::exit(EXIT_FAILURE);

    // Create a windowed mode window and its OpenGL context:
    GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        std::cerr << "\"Nope!\", said `glfwCreateWindow()`" << std::endl;
        return -1;
    }

    // Make the window's context current:
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window:
    while (!glfwWindowShouldClose(window)) {
        // Render OpenGL graphics here:

        // Swap front and back buffers:
        glfwSwapBuffers(window);

        // Poll for and process events:
        glfwPollEvents();
    }

    // Terminate GLFW:
    glfwTerminate();
    return 0;
}
