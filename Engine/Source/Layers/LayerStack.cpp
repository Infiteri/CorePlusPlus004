#include "LayerStack.h"

LayerStack::LayerStack()
{
    layerInsert = layers.begin();
}

LayerStack::~LayerStack()
{
    for (Layer *layer : layers)
        delete layer;
}

void LayerStack::PushLayers(Layer *layer)
{
    layer->OnAttach();
    layerInsert = layers.emplace(layerInsert, layer);
}

void LayerStack::PopLayers(Layer *layer)
{
    layer->OnDetach();
}
