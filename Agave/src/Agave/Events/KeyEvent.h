///=============================================================================
/// KeyEvent.h
/// Agave/Events
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Keyboard events
///=============================================================================

#ifndef AGAVE_KEY_EVENT_H
#define AGAVE_KEY_EVENT_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Events/Event.h"
#include <sstream>

namespace Agave {

    ///=========================================================================
    /// KeyEvent base class
    ///=========================================================================
    class AGAVE_API KeyEvent : public Event
    {
    public:
        s32 GetKeyCode() const { return m_keyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(const s32 keyCode)
            : m_keyCode(keyCode)
        {}
        
    protected:
        s32 m_keyCode;
    };

    ///=========================================================================
    /// KeyPressedEvent
    ///=========================================================================
    class AGAVE_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const s32 keyCode, const bool isRepeat = false)
            : KeyEvent(keyCode)
            , m_isRepeat(isRepeat)
        {}

        bool IsRepeat() const { return m_isRepeat; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_keyCode << " (repeat=" << m_isRepeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        bool m_isRepeat;
    };

    ///=========================================================================
    /// KeyReleasedEvent
    ///=========================================================================
    class AGAVE_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(const s32 keyCode)
            : KeyEvent(keyCode)
        {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}

#endif // #ifndef AGAVE_KEY_EVENT_H