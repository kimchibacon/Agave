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
    class WindowResizedEvent : public Event
    {
    public:
        WindowResizedEvent(const uint32_t width, const uint32_t height)
            : m_width(width)
            , m_height(height)
        {}

        uint32_t GetWidth() const { return m_width; }
        uint32_t GetHeight() const { return m_height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_width << ", " << m_height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResized)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        uint32_t m_width;
        uint32_t m_height;
    };

    ///=========================================================================
    /// WindowResizeEvent
    ///=========================================================================
    class WindowClosedEvent : public Event
    {
    public:
        WindowClosedEvent() {}

        EVENT_CLASS_TYPE(WindowClosed)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}



#endif AGAVE_APPLICATION_EVENT_H