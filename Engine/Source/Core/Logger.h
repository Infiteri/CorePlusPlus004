#pragma once

#include <memory>
#include "EngineCore.h"

class CORE_API Logger
{
public:
    Logger();
    ~Logger();

    enum Level
    {
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    static void Init();
    static void Log(Level level, const char *message, ...);
};
