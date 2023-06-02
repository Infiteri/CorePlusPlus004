#pragma once

#include "EngineCore.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class CORE_API Window
{
private:
    int width;
    int height;

public:
    Window(int width, int height);
    ~Window();

    bool ShouldClose();
    void Display();

    void MoveWindow(int x, int y);
    void FullScreen();

    GLFWwindow *window;
};
