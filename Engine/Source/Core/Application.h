#pragma once

#include "EngineCore.h"
#include "Layers/LayerStack.h"
#include "Layers/Layer.h"
#include "Window.h"

class CORE_API Application
{

public:
    Application();
    virtual ~Application();

    void Run();

    void PushLayers(Layer *layer);
    void PopLayers(Layer *layer);

    Window *window;

private:
    LayerStack layerStack;
};
