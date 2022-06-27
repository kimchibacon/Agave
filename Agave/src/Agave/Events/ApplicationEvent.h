///=============================================================================
/// ApplicationEvent.h
/// Agave/Events
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Application events
///=============================================================================

#ifndef AGAVE_APPLICATION_EVENT_H
#define AGAVE_APPLICATION_EVENT_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Events/Event.h"
#include <sstream>

namespace Agave {

    ///=========================================================================
    /// WindowResizeEvent
    ///=========================================================================
    class AGAVE_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(const u32 width, const u32 height)
            : m_width(width)
            , m_height(height)
        {}

        u32 GetWidth() const { return m_width; }
        u32 GetHeight() const { return m_height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_width << ", " << m_height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        u32 m_width;
        u32 m_height;
    };

    ///=========================================================================
    /// WindowResizeEvent
    ///=========================================================================
    class AGAVE_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}



#endif AGAVE_APPLICATION_EVENT_H