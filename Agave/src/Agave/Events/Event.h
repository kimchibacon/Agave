///=============================================================================
/// Event.h
/// Agave/Events
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Event base type
///=============================================================================

#ifndef AGAVE_EVENT_H
#define AGAVE_EVENT_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Core/Delegate.h"
#include <string>
#include <iostream>

namespace Agave {

    ///=========================================================================
    /// Types
    ///=========================================================================
    enum class EventType
    {
        None = 0,
        WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory : uint32_t
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

    ///=========================================================================
    /// Macros
    ///=========================================================================
#define DISPATCH_EVENT(agave_event, event_type, callback) Agave::Event::Dispatch<event_type>(agave_event, Gallant::Delegate<bool(event_type&)>(this, callback))
     
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type;}\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual uint32_t GetCategoryFlags() const override { return category; }

    ///=========================================================================
    ///=========================================================================
    class Event
    {
    public:
        ///=====================================================================
        /// Static Dispatch function for all event types
        ///=====================================================================
        template<typename T, typename F>
        static bool Dispatch(Event& event, const F& func)
        {
            if(event.GetEventType() == T::GetStaticType())
            {
                event.m_handled |= func(static_cast< T& >(event));
                return true;
            }

            return false;
        }

    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual uint32_t GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

    public:
        bool m_handled = false;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}

#endif // #ifndef AGAVE_EVENT_H