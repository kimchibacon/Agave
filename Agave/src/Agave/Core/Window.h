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
        u32 m_width;
        u32 m_height;

        WindowProps(const std::string& title = "Agave Engine",
                    u32 width = 1280,
                    u32 height = 720)
            : m_title(title)
            , m_width(width)
            , m_height(height)
        {}

    };

    ///=========================================================================
    ///=========================================================================
    class AGAVE_API Window
    {
    public:
        virtual ~Window() {}

        virtual void OnUpdate() = 0;
        virtual u32 GetWidth() const = 0;
        virtual u32 GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(Gallant::Delegate<void (Event&)> callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}

#endif // #ifndef AGAVE_WINDOW_H