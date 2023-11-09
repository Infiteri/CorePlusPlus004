#pragma once

#include "Base.h"
#include <GLFW/glfw3.h>

namespace Dragon
{
    enum class WindowSizeConfig
    {
        None = 0,
        Maximized,
        FullScreen
    };

    struct WindowConfiguration
    {
        int X, Y = 0;
        int Width = 1024;
        int Height = 576;
        const char *Title = "";
        WindowSizeConfig SizeConfig = (WindowSizeConfig)0;
    };

    class Window
    {
    private:
        WindowConfiguration configuration;
        GLFWwindow *handle;

    public:
        Window(WindowConfiguration config);
        ~Window();

        void Update();
        bool ShouldClose();

        inline WindowConfiguration GetConfiguration() { return configuration; };
        inline GLFWwindow *GetHandle() { return handle; };
    };
}