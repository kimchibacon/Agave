///=============================================================================
/// Sandbox.cpp
/// Sandbox
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Sandbox application for AgaveEngine testing.
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include <Agave/Core/EntryPoint.h>
#include <Agave/Core/Application.h>
#include <Agave/ImGui/ImGuiLayer.h>
#include <Agave/Core/Layer.h>
#include <Agave/Core/Input.h>

class ExampleLayer : public Agave::Layer
{
public:
    ExampleLayer()
        :Layer("Example")
    {}

    virtual void OnUpdate() override
    {
        if(Agave::Input::IsKeyPressed(Agave::KeyCode::Tab))
            AGAVE_TRACE("Tab key is pressed");
    }

    virtual void OnEvent(Agave::Event& event) override
    {}
};

///=============================================================================
///=============================================================================
class Sandbox : public Agave::Application
{
public:
    ///=========================================================================
    ///=========================================================================
    Sandbox()
    {
        PushOverlay(new Agave::ImGuiLayer());
        PushLayer(new ExampleLayer());
    }

    ///=========================================================================
    ///=========================================================================
    ~Sandbox()
    {}
};

///=============================================================================
/// Extern Functions
///=============================================================================
Agave::Application* Agave::CreateApplication()
{
    return new Sandbox();
}