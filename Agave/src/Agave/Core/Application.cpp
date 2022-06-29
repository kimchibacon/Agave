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

namespace Agave {
    ///=========================================================================
    ///=========================================================================
    Application::Application()
        : m_running(true)
    {
        m_window = std::unique_ptr<Window>(Window::Create());

        Gallant::Delegate<void (Event&)> callback;
        callback.Bind(this, &Application::OnEvent);
        m_window->SetEventCallback(callback);
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
            m_window->OnUpdate();
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
    }

    ///=========================================================================
    ///=========================================================================
    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_running = false;
        return true;
    }
}