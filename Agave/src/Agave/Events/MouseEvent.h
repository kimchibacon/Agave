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
#include <sstream>

namespace Agave {

    ///=========================================================================
    /// MouseMovedEvent
    ///=========================================================================
    class AGAVE_API MouseMovedEvent : public Event
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
            : m_offsetX(xOffset)
            , m_offsetY(yOffset)
        {}

        float GetXOffset() const { return m_offsetX; }
        float GetYOffset() const { return m_offsetY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_offsetX;
        float m_offsetY;
    };

    ///=========================================================================
    /// MouseButtonEvent base class
    ///=========================================================================
    class AGAVE_API MouseButtonEvent : public Event
    {
    public:
        s32 GetMouseButton() const { return m_button; }
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        MouseButtonEvent(const s32 button)
            : m_button(button) 
        {}

        s32 m_button;
    };

    ///=========================================================================
    /// MouseButtonPressedEvent
    ///=========================================================================
    class AGAVE_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const s32 button)
            : MouseButtonEvent(button) 
        {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    ///=========================================================================
    /// MouseButtonReleasedEvent
    ///=========================================================================
    class AGAVE_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(s32 button)
            : MouseButtonEvent(button) 
        {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif // #ifndef AGAVE_MOUSE_EVENT_H