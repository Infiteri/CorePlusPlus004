#include "Core.h"

class ExampleLayer : public Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnAttach() override
    {
        Logger::Log(Logger::Level::INFO, "Layer: %s was attached to the layer stack", GetName());
    }

    void OnUpdate() override
    {
    }
};

class Sandbox : public Application
{
public:
    Sandbox()
    {
        PushLayers(new ExampleLayer());
    }
    ~Sandbox() {}

    void Run()
    {
        while (true)
        {
        }
    }
};

Application *CreateApplication()
{
    return new Sandbox();
}
