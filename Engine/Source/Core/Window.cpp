#include "Window.h"

Window::Window(int width, int height)
{
    // State
    this->width = width;
    this->height = height;

    this->window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(this->window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

Window::~Window()
{
    glfwDestroyWindow(window);
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::Display()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Window::MoveWindow(int x, int y)
{
    glfwSetWindowPos(window, x, y);
}

void Window::FullScreen()
{
    glfwMaximizeWindow(this->window);
}
