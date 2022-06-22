#include <Agave/Core/EntryPoint.h>
#include <Agave/Core/Application.h>

class Sandbox : public Agave::Application
{
public:
    Sandbox()
    {}

    ~Sandbox()
    {}
};

Agave::Application* Agave::CreateApplication()
{
    return new Sandbox();
}