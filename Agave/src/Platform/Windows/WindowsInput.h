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
#include "Agave/Core/Base.h"
#include "Agave/Core/Input.h"
#include <unordered_map>

namespace Agave {

    class WindowsInput : public Input
    {
    public:
        ///=====================================================================
        /// Public Methods
        ///=====================================================================
        static int AgaveKeyToGlfwKey(Agave::KeyCode keycode) { return m_agaveToGlfwKeyCodeMap[keycode]; }
        static Agave::KeyCode GlfwKeyToAgaveKey(int keycode) { return m_glfwToAgaveKeyCodeMap[keycode]; }
        static int AgaveMoustButtonToGlfwMouseButton(Agave::MouseButtonCode button) { return m_agaveToGlfwMouseButtonCodeMap[button]; }
        static Agave::MouseButtonCode GlfwMouseButtonToAgaveMouseButton(int button) { return m_glfwToAgaveMouseButtonCodeMap[button]; }

    protected:
        ///=====================================================================
        /// Base Class Implementations
        ///=====================================================================
        virtual bool IsKeyPressedImpl(Agave::KeyCode keycode) override;
        virtual bool IsMouseButtonPressedImpl(Agave::MouseButtonCode button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;

    private:
        ///=====================================================================
        /// Private Members
        ///=====================================================================
        static std::unordered_map<Agave::KeyCode, int> m_agaveToGlfwKeyCodeMap;
        static std::unordered_map<int, Agave::KeyCode> m_glfwToAgaveKeyCodeMap;
        static std::unordered_map<Agave::MouseButtonCode, int> m_agaveToGlfwMouseButtonCodeMap;
        static std::unordered_map<int, Agave::MouseButtonCode> m_glfwToAgaveMouseButtonCodeMap;
    };
}

#endif // #ifndef AGAVE_WINDOWS_INPUT_H