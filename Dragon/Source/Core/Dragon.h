#pragma once

#include "Window.h"

namespace Dragon
{
    struct DragonOSState
    {
        bool running;
        Window* window;
    };

    bool Launch();
    void Run();
    void Shutdown();
}