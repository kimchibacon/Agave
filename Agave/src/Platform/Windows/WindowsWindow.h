///=============================================================================
/// WindowsWindow.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Windows implementation of Agave display window
///=============================================================================

#ifndef AGAVE_WINDOWS_WINDOW_H
#define AGAVE_WINDOWS_WINDOW_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Window.h"
#include <GLFW/glfw3.h>

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    class WindowsWindow : public Window
    {
    private:
        ///=====================================================================
        /// Types
        ///=====================================================================
        struct WindowData
        {
            std::string m_title;
            u32 m_width;
            u32 m_height;
            bool m_isVSync;

            Gallant::Delegate<void (Event&)> m_eventCallback;
        };

    public:
        ///=====================================================================
        /// Ctor/Dtor
        ///=====================================================================
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

    public:
        ///=====================================================================
        /// Interface
        ///=====================================================================
        void OnUpdate() override;
        u32 GetWidth() const override { return m_data.m_width; }
        u32 GetHeight() const override { return m_data.m_height; }
        void SetEventCallback(Gallant::Delegate<void (Event&)> callback) override { m_data.m_eventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        ///=====================================================================
        /// Private Methods
        ///=====================================================================
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

    private:
        ///=====================================================================
        /// Private Fields
        ///=====================================================================
        GLFWwindow* m_pWindow;
        WindowData m_data;
    };
}

#endif // #ifndef AGAVE_WINDOWS_WINDOW_H