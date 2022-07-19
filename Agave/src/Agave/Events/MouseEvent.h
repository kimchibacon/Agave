///=============================================================================
/// MouseEvent.h
/// Agave/Events
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Mouse events
///=============================================================================

#ifndef AGAVE_MOUSE_EVENT_H
#define AGAVE_MOUSE_EVENT_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Events/Event.h"
#include "Agave/Core/MouseButtonCodes.h"
#include <sstream>

namespace Agave {

    ///=========================================================================
    /// MouseMovedEvent
    ///=========================================================================
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(const float x, const float y)
            : m_mouseX(x)
            , m_mouseY(y) 
        {}

        float GetX() const { return m_mouseX; }
        float GetY() const { return m_mouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_mouseX;
        float m_mouseY;
    };

    ///=========================================================================
    /// MouseScrolledEvent
    ///=========================================================================
    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(const float xOffset, const float yOffset)
            : m_xOffset(xOffset)
            , m_yOffset(yOffset)
        {}

        float GetXOffset() const { return m_xOffset; }
        float GetYOffset() const { return m_yOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_xOffset;
        float m_yOffset;
    };

    ///=========================================================================
    /// MouseButtonEvent base class
    ///=========================================================================
    class MouseButtonEvent : public Event
    {
    public:
        Agave::MouseButtonCode GetMouseButton() const { return m_button; }
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        MouseButtonEvent(const Agave::MouseButtonCode button)
            : m_button(button) 
        {}

        Agave::MouseButtonCode m_button;
    };

    ///=========================================================================
    /// MouseButtonPressedEvent
    ///=========================================================================
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const Agave::MouseButtonCode button)
            : MouseButtonEvent(button) 
        {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << (int)m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    ///=========================================================================
    /// MouseButtonReleasedEvent
    ///=========================================================================
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(Agave::MouseButtonCode button)
            : MouseButtonEvent(button) 
        {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << (int)m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif // #ifndef AGAVE_MOUSE_EVENT_H