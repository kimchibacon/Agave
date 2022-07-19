///=============================================================================
/// Window.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Display window base class
///=============================================================================

#ifndef AGAVE_WINDOW_H
#define AGAVE_WINDOW_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Events/Event.h"
#include "Agave/Core/Delegate.h"

namespace Agave {

    ///=========================================================================
    /// Types
    ///=========================================================================
    struct WindowProps
    {
        std::string m_title;
        uint32_t m_width;
        uint32_t m_height;

        WindowProps(const std::string& title = "Agave Engine",
            uint32_t width = 1280,
            uint32_t height = 720)
            : m_title(title)
            , m_width(width)
            , m_height(height)
        {}

    };

    ///=========================================================================
    ///=========================================================================
    class Window
    {
    public:
        virtual ~Window() {}

        virtual void OnUpdate() = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        virtual void* GetNativeWindow() const = 0;

        // Window attributes
        virtual void SetEventCallback(Gallant::Delegate1<Event&> callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}

#endif // #ifndef AGAVE_WINDOW_H