
#pragma once
// Main entry point for all application (included per application)

#ifdef CORE_WINDOWS_PLATFORM

extern Application *CreateApplication();

int main(int argc, char const *argv[])
{
    Logger::Init();

    auto application = CreateApplication();
    application->Run();
    delete application;

    return 0;
}

#endif
