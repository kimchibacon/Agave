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
#include "Agave/Logging/Log.h"
#include "Agave/Events/ApplicationEvent.h"

namespace Agave {
    ///=========================================================================
    ///=========================================================================
    Application::Application()
    {}

    ///=========================================================================
    ///=========================================================================
    Application::~Application()
    {}

    ///=========================================================================
    ///=========================================================================
    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
        {
            AgLogTrace(e);
        }
        
        if (e.IsInCategory(EventCategoryInput))
        {
            AgLogTrace(e);
        }

        while(true);
    }
}