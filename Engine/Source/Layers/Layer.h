#pragma once

#include "Core/EngineCore.h"
#include <string>

class CORE_API Layer
{
private:
    std::string name;

public:
    Layer(const std::string &name = "Layer");
    ~Layer();

    virtual void OnAttach();
    virtual void OnDetach();
    virtual void OnUpdate();

    inline const std::string &GetName() { return name; };
};
