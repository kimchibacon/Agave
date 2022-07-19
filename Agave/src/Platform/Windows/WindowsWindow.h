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
/// Forward Declarations
///=============================================================================
class RenderContext;
struct GLFWwindow;

///=============================================================================
/// Includes
///=============================================================================
#include "windows.h"
#include "Agave/Core/Base.h"
#include "Agave/Core/Window.h"
#include "Agave/Render/RenderContext.h"

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
            uint32_t m_width;
            uint32_t m_height;
            bool m_isVSync;
            Gallant::Delegate<void (Event&)> m_eventCallback;

            WindowData()
                : m_width(0)
                , m_height(0)
                , m_isVSync(false)
            {}
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
        virtual void OnUpdate() override;
        virtual uint32_t GetWidth() const override { return m_data.m_width; }
        virtual uint32_t GetHeight() const override { return m_data.m_height; }
        virtual void* GetNativeWindow() const override { return m_pWindow; };
        virtual void SetEventCallback(Gallant::Delegate1<Event&> callback) override { m_data.m_eventCallback = callback; }
        virtual void SetVSync(bool enabled) override;
        virtual bool IsVSync() const override;

    private:
        ///=====================================================================
        /// Private Methods
        ///=====================================================================
        virtual void Init(const WindowProps& props);
        virtual void RegisterEventCallbacks();
        virtual void Shutdown();

    private:
        ///=====================================================================
        /// Private Fields
        ///=====================================================================
        GLFWwindow* m_pWindow;
        WindowData m_data;
        RenderContext* m_pContext;
    };
}

#endif // #ifndef AGAVE_WINDOWS_WINDOW_H