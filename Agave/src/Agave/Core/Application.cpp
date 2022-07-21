///=============================================================================
/// Application.cpp
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Singleton class representing client application.
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Application.h"
#include "Agave/Core/Delegate.h"
#include "Agave/Core/Assert.h"
#include "Agave/Core/Timestep.h"
#include "Agave/Render/Renderer.h"

#include <GLFW/glfw3.h>

namespace Agave {

    Application* Application::ms_pInstance = nullptr;

    ///=========================================================================
    ///=========================================================================
    Application::Application()
        : m_running(true)
        , m_lastFrameTime(0.0f)
    {
        AGAVE_CORE_ASSERT(ms_pInstance == nullptr);
        ms_pInstance = this;

        m_pWindow = std::unique_ptr<Window>(Window::Create());

        Gallant::Delegate<void (Event&)> callback;
        callback.Bind(this, &Application::OnEvent);
        m_pWindow->SetEventCallback(callback);

        m_pImGuiLayer = new ImGuiLayer();
        PushOverlay(m_pImGuiLayer);
    }

    ///=========================================================================
    ///=========================================================================
    Application::~Application()
    {}

    ///=========================================================================
    ///=========================================================================
    void Application::Run()
    {
        while (m_running)
        {
            float time = (float)glfwGetTime();
            Timestep deltaTime = time - m_lastFrameTime;
            m_lastFrameTime = time;

            m_layerStack.OnUpdate(deltaTime);

            // Render ImGui on all layers
            m_pImGuiLayer->Begin();
            for(Layer* layer : m_layerStack)
                layer->OnImGuiRender();
            m_pImGuiLayer->End();

            m_pWindow->OnUpdate();
        }
    }

    ///=========================================================================
    ///=========================================================================
    void Application::OnEvent(Event& event)
    {
        DISPATCH_EVENT(event, WindowClosedEvent, &Application::OnWindowClosed);

        m_layerStack.OnEvent(event);
    }

    ///=========================================================================
    ///=========================================================================
    void Application::PushLayer(Layer* layer)
    {
        m_layerStack.PushLayer(layer);
    }

    ///=========================================================================
    ///=========================================================================
    void Application::PushOverlay(Layer* overlay)
    {
        m_layerStack.PushOverlay(overlay);
    }

    ///=========================================================================
    ///=========================================================================
    bool Application::OnWindowClosed(WindowClosedEvent& event)
    {
        event.m_handled = true;
        m_running = false;
        return true;
    }
}