///=============================================================================
/// WindowsInput.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Windows implementation of Input manager
///=============================================================================

#ifndef AGAVE_WINDOWS_INPUT_H
#define AGAVE_WINDOWS_INPUT_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Input.h"
#include <unordered_map>

namespace Agave {

    class WindowsInput : public Input
    {
    public:
        static s32 AgaveKeyToGlfwKey(Agave::KeyCode keycode) { return m_agaveToGlfwKeyCodeMap[keycode]; }
        static Agave::KeyCode GlfwKeyToAgaveKey(s32 keycode) { return m_glfwToAgaveKeyCodeMap[keycode]; }
        static s32 AgaveMoustButtonToGlfwMouseButton(Agave::MouseButtonCode button) { return m_agaveToGlfwMouseButtonCodeMap[button]; }
        static Agave::MouseButtonCode GlfwMouseButtonToAgaveMouseButton(s32 button) { return m_glfwToAgaveMouseButtonCodeMap[button]; }

    protected:
        virtual bool IsKeyPressedImpl(Agave::KeyCode keycode) override;
        virtual bool IsMouseButtonPressedImpl(Agave::MouseButtonCode button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;

    private:
        static std::unordered_map<Agave::KeyCode, s32> m_agaveToGlfwKeyCodeMap;
        static std::unordered_map<s32, Agave::KeyCode> m_glfwToAgaveKeyCodeMap;
        static std::unordered_map<Agave::MouseButtonCode, s32> m_agaveToGlfwMouseButtonCodeMap;
        static std::unordered_map<s32, Agave::MouseButtonCode> m_glfwToAgaveMouseButtonCodeMap;
    };
}

#endif // #ifndef AGAVE_WINDOWS_INPUT_H