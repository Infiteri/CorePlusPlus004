#include "Logger.h"
#include <windows.h>
#include <stdio.h>

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::Init()
{
    SetConsoleTitleA("Core Engine Console");
}

void Logger::Log(Level level, const char *message, ...)
{
    const char *levels[4] = {"INFO", "WARN", "ERROR", "FATAL"};

    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    // Format original message.
    // NOTE: Oddly enough, MS's headers override the GCC/Clang va_list type with a "typedef char* va_list" in some
    // cases, and as a result throws a strange error here. The workaround for now is to just use __builtin_va_list,
    // which is the type GCC/Clang's va_start expects.
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);

    printf("[LOG %s]: %s\n", levels[level], out_message);
}
