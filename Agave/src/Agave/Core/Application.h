///=============================================================================
/// Application.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Application class representing client application.
///=============================================================================

#ifndef AGAVE_APPLICATION_H
#define AGAVE_APPLICATION_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Core/Window.h"
#include "Agave/Events/ApplicationEvent.h"

///=============================================================================
/// Forward Declarations
///=============================================================================
class WindowCloseEvent;

namespace Agave {
    ///=========================================================================
    ///=========================================================================
    class AGAVE_API Application
    {
    public:
        ///=====================================================================
        /// Ctor/Dtor
        ///=====================================================================
        Application();
        virtual ~Application();

    public:
        ///=====================================================================
        /// Public Methods
        ///=====================================================================
        void Run();
        void OnEvent(Event& event);
        bool OnWindowClose(WindowCloseEvent& event);

    private:
        ///=====================================================================
        /// Private Fields
        ///=====================================================================
        std::unique_ptr<Window> m_window;
        bool                    m_running;
    };

    // Defined by client
    Application* CreateApplication();
} 

#endif // #ifndef AGAVE_APPLICATION_H