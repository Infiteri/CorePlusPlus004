#include "Dragon.h"
#include "Memory/DagMemory.h"

namespace Dragon
{
    DragonOSState *state;

    bool Launch()
    {
        state = new DragonOSState;
        state->running = true;

        WindowConfiguration config;
        config.Title = "Window";
        config.SizeConfig = WindowSizeConfig::FullScreen;
        state->window = new Window(config);

        return true;
    }

    void Run()
    {
        while (state->running)
        {
            state->window->Update();
            state->running = !state->window->ShouldClose();
        }

        state->running = false;
    }

    void Shutdown()
    {
        delete state->window;
        Memo::Free(state);
    }
}