#include "Window.h"
#include "Console.h"

namespace Dragon
{
    Window::Window(WindowConfiguration config)
    {
        configuration.X = config.X;
        configuration.Y = config.Y;
        configuration.Width = config.Width;
        configuration.Height = config.Height;
        configuration.Title = config.Title;
        configuration.SizeConfig = config.SizeConfig;

        glfwInit();
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

        GLFWmonitor *monitor = NULL;
        if (config.SizeConfig == WindowSizeConfig::FullScreen)
            monitor = glfwGetPrimaryMonitor();

        handle = glfwCreateWindow(config.Width, config.Height, config.Title, monitor, NULL);
        glfwMakeContextCurrent(handle);
        glfwShowWindow(handle);

        // TODO: Bind Events
        switch (config.SizeConfig)
        {
        case WindowSizeConfig::None:
        default:
            glfwSetWindowPos(handle, config.X, config.Y);
            break;

        case WindowSizeConfig::Maximized:
            glfwMaximizeWindow(handle);
            glfwGetWindowSize(handle, &configuration.Width, &configuration.Height);
            break;

        case WindowSizeConfig::FullScreen:
            break;
        }

        Console::Log(Console::ColorWhite, "Created window '%s'", config.Title);
    }

    Window::~Window()
    {
        glfwDestroyWindow(handle);
    }

    void Window::Update()
    {
        glfwPollEvents();
        glfwSwapBuffers(handle);
    }

    bool Window::ShouldClose()
    {
        return glfwWindowShouldClose(handle);
    }
}