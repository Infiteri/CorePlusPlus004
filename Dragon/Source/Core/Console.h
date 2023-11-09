#pragma once

#include "Base.h"

#define DAG_MAX_CONSOLE_MESSAGE_LENGTH 32000

namespace Dragon
{
    namespace Console
    {
        enum ConsoleColors
        {
            ColorWhite,
            ColorRed,
            ColorDarkRed,
            ColorBlue,
            ColorGray,
            ColorGreen,
            ColorYellow,
        };

        void Initialize();
        void Log(ConsoleColors color, const char *fmt, ...);
        void Shutdown();
    }
}