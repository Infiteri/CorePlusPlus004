// This file checks for specific stuff for the engine (Core.h is for imports)
#pragma once

#ifdef CORE_WINDOWS_PLATFORM

// Define declspec dllexport
#ifdef CORE_BUILD_DLL
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

#else
#error Windows Only sorry loser
#endif

#define BIT(x) (1 << x)