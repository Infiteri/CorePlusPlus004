#include "Console.h"
#include "Memory/DagMemory.h"

#include <stdio.h>
#include <string>
#include <windows.h>
#include <cstdarg>

namespace Dragon
{
    namespace Console
    {

        void SetConsoleColor(ConsoleColors color)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            WORD colorAttribute = FOREGROUND_INTENSITY; // Default to high-intensity (bright) text

            switch (color)
            {
            case ColorWhite:
                colorAttribute |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
                break;

            case ColorGray:
                colorAttribute |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
                break;

            case ColorRed:
                colorAttribute |= FOREGROUND_RED;
                break;

            case ColorDarkRed:
                colorAttribute |= FOREGROUND_RED;
                break;

            case ColorBlue:
                colorAttribute |= FOREGROUND_BLUE;
                break;

            case ColorGreen:
                colorAttribute |= FOREGROUND_GREEN;
                break;

            case ColorYellow:
                colorAttribute |= FOREGROUND_RED | FOREGROUND_GREEN;
                break;

            default:
                // Default to white if an unsupported color is specified
                colorAttribute |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
                break;
            }

            SetConsoleTextAttribute(hConsole, colorAttribute);
        }

        void Initialize()
        {
        }

        void Log(ConsoleColors color, const char *fmt, ...)
        {
            // Setup
            char OutMessage[DAG_MAX_CONSOLE_MESSAGE_LENGTH];
            Memo::Zero(&OutMessage, DAG_MAX_CONSOLE_MESSAGE_LENGTH);

            // Perform string pending
            __builtin_va_list arg_ptr;
            va_start(arg_ptr, fmt);
            vsnprintf(OutMessage, DAG_MAX_CONSOLE_MESSAGE_LENGTH, fmt, arg_ptr);
            va_end(arg_ptr);
            snprintf(OutMessage, DAG_MAX_CONSOLE_MESSAGE_LENGTH, "%s\n", OutMessage);

            SetConsoleColor(color);

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD bytesWritten;
            OutputDebugStringA(OutMessage);
            WriteConsoleA(hConsole, OutMessage, strlen(OutMessage), &bytesWritten, NULL);
        }

        void Shutdown()
        {
        }
    }
}