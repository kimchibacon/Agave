///=============================================================================
/// Application.cpp
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Application class representing client application.
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Application.h"
#include "Agave/Core/Log.h"
#include "Agave/Core/Delegate.h"
#include <glad/glad.h>

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    Application::Application()
        : m_running(true)
    {
        m_pWindow = std::unique_ptr<Window>(Window::Create());

        Gallant::Delegate<void (Event&)> callback;
        callback.Bind(this, &Application::OnEvent);
        m_pWindow->SetEventCallback(callback);
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
            m_pWindow->OnUpdate();
            m_layerStack.OnUpdate();
        }
    }

    ///=========================================================================
    ///=========================================================================
    void Application::OnEvent(Event& event)
    {
        Gallant::Delegate<bool (WindowCloseEvent&)> winCloseCallback;
        winCloseCallback.Bind(this, &Application::OnWindowClose);

        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(winCloseCallback);

        AgCoreLogTrace("{0}", event);

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
    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        event.m_handled = true;
        m_running = false;
        return true;
    }
}