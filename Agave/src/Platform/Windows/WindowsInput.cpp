///=============================================================================
/// WindowsInput.cpp
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Windows implementation of Input manager
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Platform/Windows/WindowsInput.h"
#include "Agave/Core/Application.h"
#include "GLFW/glfw3.h"
#include <unordered_map>

namespace Agave {

    ///=========================================================================
    /// Singleton Instance
    ///=========================================================================
    Input* Input::ms_pInstance = new WindowsInput();

    ///=========================================================================
    ///=========================================================================
    bool WindowsInput::IsKeyPressedImpl(Agave::KeyCode keycode)
    {
        s32 glfwKeycode = AgaveKeyToGlfwKey(keycode);

        auto pWindow = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
        s32 state = glfwGetKey(pWindow, glfwKeycode);

        return (state == GLFW_PRESS) || (state == GLFW_REPEAT);
    }

    ///=========================================================================
    ///=========================================================================
    bool WindowsInput::IsMouseButtonPressedImpl(Agave::MouseButtonCode button)
    {
        auto pWindow = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
        s32 state = glfwGetMouseButton(pWindow, AgaveMoustButtonToGlfwMouseButton(button));
        
        return (state == GLFW_PRESS);
    }

    ///=========================================================================
    ///=========================================================================
    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto pWindow = static_cast< GLFWwindow* >(Application::Instance().GetWindow().GetNativeWindow());
        double xPos;
        double yPos;

        glfwGetCursorPos(pWindow, &xPos, &yPos);

        return {(float)xPos, (float)yPos};
    }

    ///=========================================================================
    ///=========================================================================
    float WindowsInput::GetMouseXImpl()
    {
        auto pWindow = static_cast< GLFWwindow* >(Application::Instance().GetWindow().GetNativeWindow());
        double xPos;
        double yPos;
        glfwGetCursorPos(pWindow, &xPos, &yPos);

        return (float)xPos;
    }

    ///=========================================================================
    ///=========================================================================
    float WindowsInput::GetMouseYImpl()
    {
        auto pWindow = static_cast< GLFWwindow* >(Application::Instance().GetWindow().GetNativeWindow());
        double xPos;
        double yPos;
        glfwGetCursorPos(pWindow, &xPos, &yPos);

        return ( float )yPos;
    }

    ///=========================================================================
    /// Key Code and Mouse Button maps
    ///=========================================================================
    std::unordered_map<Agave::KeyCode, s32> WindowsInput::m_agaveToGlfwKeyCodeMap = {
        {Agave::KeyCode::Space, GLFW_KEY_SPACE},
        {Agave::KeyCode::Apostrophe, GLFW_KEY_APOSTROPHE},
        {Agave::KeyCode::Comma, GLFW_KEY_COMMA},
        {Agave::KeyCode::Minus, GLFW_KEY_MINUS},
        {Agave::KeyCode::Period, GLFW_KEY_PERIOD},
        {Agave::KeyCode::Slash, GLFW_KEY_SLASH},
        {Agave::KeyCode::Semicolon, GLFW_KEY_SEMICOLON},
        {Agave::KeyCode::Equal, GLFW_KEY_EQUAL},
        {Agave::KeyCode::Alpha0, GLFW_KEY_0},
        {Agave::KeyCode::Alpha1, GLFW_KEY_1},
        {Agave::KeyCode::Alpha2, GLFW_KEY_2},
        {Agave::KeyCode::Alpha3, GLFW_KEY_3},
        {Agave::KeyCode::Alpha4, GLFW_KEY_4},
        {Agave::KeyCode::Alpha5, GLFW_KEY_5},
        {Agave::KeyCode::Alpha6, GLFW_KEY_6},
        {Agave::KeyCode::Alpha7, GLFW_KEY_7},
        {Agave::KeyCode::Alpha8, GLFW_KEY_8},
        {Agave::KeyCode::Alpha9, GLFW_KEY_9},
        {Agave::KeyCode::A, GLFW_KEY_A},
        {Agave::KeyCode::B, GLFW_KEY_B},
        {Agave::KeyCode::C, GLFW_KEY_C},
        {Agave::KeyCode::D, GLFW_KEY_D},
        {Agave::KeyCode::E, GLFW_KEY_E},
        {Agave::KeyCode::F, GLFW_KEY_F},
        {Agave::KeyCode::G, GLFW_KEY_G},
        {Agave::KeyCode::H, GLFW_KEY_H},
        {Agave::KeyCode::I, GLFW_KEY_I},
        {Agave::KeyCode::J, GLFW_KEY_J},
        {Agave::KeyCode::K, GLFW_KEY_K},
        {Agave::KeyCode::L, GLFW_KEY_L},
        {Agave::KeyCode::M, GLFW_KEY_M},
        {Agave::KeyCode::N, GLFW_KEY_N},
        {Agave::KeyCode::O, GLFW_KEY_O},
        {Agave::KeyCode::P, GLFW_KEY_P},
        {Agave::KeyCode::Q, GLFW_KEY_Q},
        {Agave::KeyCode::R, GLFW_KEY_R},
        {Agave::KeyCode::S, GLFW_KEY_S},
        {Agave::KeyCode::T, GLFW_KEY_T},
        {Agave::KeyCode::U, GLFW_KEY_U},
        {Agave::KeyCode::V, GLFW_KEY_V},
        {Agave::KeyCode::W, GLFW_KEY_W},
        {Agave::KeyCode::X, GLFW_KEY_X},
        {Agave::KeyCode::Y, GLFW_KEY_Y},
        {Agave::KeyCode::Z, GLFW_KEY_Z},
        {Agave::KeyCode::LeftBracket, GLFW_KEY_LEFT_BRACKET},
        {Agave::KeyCode::Backslash, GLFW_KEY_BACKSLASH},
        {Agave::KeyCode::RightBracket, GLFW_KEY_RIGHT_BRACKET},
        {Agave::KeyCode::GraveAccent, GLFW_KEY_GRAVE_ACCENT},
        {Agave::KeyCode::World1, GLFW_KEY_WORLD_1},
        {Agave::KeyCode::World2, GLFW_KEY_WORLD_2},
        {Agave::KeyCode::Escape, GLFW_KEY_ESCAPE},
        {Agave::KeyCode::Enter, GLFW_KEY_ENTER},
        {Agave::KeyCode::Tab, GLFW_KEY_TAB},
        {Agave::KeyCode::Backspace, GLFW_KEY_BACKSPACE},
        {Agave::KeyCode::Insert, GLFW_KEY_INSERT},
        {Agave::KeyCode::Delete, GLFW_KEY_DELETE},
        {Agave::KeyCode::RightArrow, GLFW_KEY_RIGHT},
        {Agave::KeyCode::LeftArrow, GLFW_KEY_LEFT},
        {Agave::KeyCode::DownArrow, GLFW_KEY_DOWN},
        {Agave::KeyCode::UpArrow, GLFW_KEY_UP},
        {Agave::KeyCode::PageUp, GLFW_KEY_PAGE_UP},
        {Agave::KeyCode::PageDown, GLFW_KEY_PAGE_DOWN},
        {Agave::KeyCode::Home, GLFW_KEY_HOME},
        {Agave::KeyCode::End, GLFW_KEY_END},
        {Agave::KeyCode::CapsLock, GLFW_KEY_CAPS_LOCK},
        {Agave::KeyCode::ScrollLock, GLFW_KEY_SCROLL_LOCK},
        {Agave::KeyCode::NumLock, GLFW_KEY_NUM_LOCK},
        {Agave::KeyCode::PrintScreen, GLFW_KEY_PRINT_SCREEN},
        {Agave::KeyCode::Pause, GLFW_KEY_PAUSE},
        {Agave::KeyCode::F1, GLFW_KEY_F1},
        {Agave::KeyCode::F2, GLFW_KEY_F2},
        {Agave::KeyCode::F3, GLFW_KEY_F3},
        {Agave::KeyCode::F4, GLFW_KEY_F4},
        {Agave::KeyCode::F5, GLFW_KEY_F5},
        {Agave::KeyCode::F6, GLFW_KEY_F6},
        {Agave::KeyCode::F7, GLFW_KEY_F7},
        {Agave::KeyCode::F8, GLFW_KEY_F8},
        {Agave::KeyCode::F9, GLFW_KEY_F9},
        {Agave::KeyCode::F10, GLFW_KEY_F10},
        {Agave::KeyCode::F11, GLFW_KEY_F11},
        {Agave::KeyCode::F12, GLFW_KEY_F12},
        {Agave::KeyCode::F13, GLFW_KEY_F13},
        {Agave::KeyCode::F14, GLFW_KEY_F14},
        {Agave::KeyCode::F15, GLFW_KEY_F15},
        {Agave::KeyCode::F16, GLFW_KEY_F16},
        {Agave::KeyCode::F17, GLFW_KEY_F17},
        {Agave::KeyCode::F18, GLFW_KEY_F18},
        {Agave::KeyCode::F19, GLFW_KEY_F19},
        {Agave::KeyCode::F20, GLFW_KEY_F20},
        {Agave::KeyCode::F21, GLFW_KEY_F21},
        {Agave::KeyCode::F22, GLFW_KEY_F22},
        {Agave::KeyCode::F23, GLFW_KEY_F23},
        {Agave::KeyCode::F24, GLFW_KEY_F24},
        {Agave::KeyCode::F25, GLFW_KEY_F25},
        {Agave::KeyCode::NumPad0, GLFW_KEY_KP_0},
        {Agave::KeyCode::NumPad1, GLFW_KEY_KP_1},
        {Agave::KeyCode::NumPad2, GLFW_KEY_KP_2},
        {Agave::KeyCode::NumPad3, GLFW_KEY_KP_3},
        {Agave::KeyCode::NumPad4, GLFW_KEY_KP_4},
        {Agave::KeyCode::NumPad5, GLFW_KEY_KP_5},
        {Agave::KeyCode::NumPad6, GLFW_KEY_KP_6},
        {Agave::KeyCode::NumPad7, GLFW_KEY_KP_7},
        {Agave::KeyCode::NumPad8, GLFW_KEY_KP_8},
        {Agave::KeyCode::NumPad9, GLFW_KEY_KP_9},
        {Agave::KeyCode::NumPadPeriod, GLFW_KEY_KP_DECIMAL},
        {Agave::KeyCode::NumPadDivide, GLFW_KEY_KP_DIVIDE},
        {Agave::KeyCode::NumPadMultiply, GLFW_KEY_KP_MULTIPLY},
        {Agave::KeyCode::NumPadMinus, GLFW_KEY_KP_SUBTRACT},
        {Agave::KeyCode::NumPadPlus, GLFW_KEY_KP_ADD},
        {Agave::KeyCode::NumPadEnter, GLFW_KEY_KP_ENTER},
        {Agave::KeyCode::NumPadEqual, GLFW_KEY_KP_EQUAL},
        {Agave::KeyCode::LeftShift, GLFW_KEY_LEFT_SHIFT},
        {Agave::KeyCode::LeftControl, GLFW_KEY_LEFT_CONTROL},
        {Agave::KeyCode::LeftAlt, GLFW_KEY_LEFT_ALT},
        {Agave::KeyCode::LeftSuper, GLFW_KEY_LEFT_SUPER},
        {Agave::KeyCode::RightShift, GLFW_KEY_RIGHT_SHIFT},
        {Agave::KeyCode::RightControl, GLFW_KEY_RIGHT_CONTROL},
        {Agave::KeyCode::RightAlt, GLFW_KEY_RIGHT_ALT},
        {Agave::KeyCode::RightSuper, GLFW_KEY_RIGHT_SUPER},
        {Agave::KeyCode::Menu, GLFW_KEY_MENU}
    };

    std::unordered_map<s32, Agave::KeyCode> WindowsInput::m_glfwToAgaveKeyCodeMap = {
        {GLFW_KEY_SPACE, Agave::KeyCode::Space},
        {GLFW_KEY_APOSTROPHE, Agave::KeyCode::Apostrophe},
        {GLFW_KEY_COMMA, Agave::KeyCode::Comma},
        {GLFW_KEY_MINUS, Agave::KeyCode::Minus},
        {GLFW_KEY_PERIOD, Agave::KeyCode::Period},
        {GLFW_KEY_SLASH, Agave::KeyCode::Slash},
        {GLFW_KEY_SEMICOLON, Agave::KeyCode::Semicolon},
        {GLFW_KEY_EQUAL, Agave::KeyCode::Equal},
        {GLFW_KEY_0, Agave::KeyCode::Alpha0},
        {GLFW_KEY_1, Agave::KeyCode::Alpha1},
        {GLFW_KEY_2, Agave::KeyCode::Alpha2},
        {GLFW_KEY_3, Agave::KeyCode::Alpha3},
        {GLFW_KEY_4, Agave::KeyCode::Alpha4},
        {GLFW_KEY_5, Agave::KeyCode::Alpha5},
        {GLFW_KEY_6, Agave::KeyCode::Alpha6},
        {GLFW_KEY_7, Agave::KeyCode::Alpha7},
        {GLFW_KEY_8, Agave::KeyCode::Alpha8},
        {GLFW_KEY_9, Agave::KeyCode::Alpha9},
        {GLFW_KEY_A, Agave::KeyCode::A},
        {GLFW_KEY_B, Agave::KeyCode::B},
        {GLFW_KEY_C, Agave::KeyCode::C},
        {GLFW_KEY_D, Agave::KeyCode::D},
        {GLFW_KEY_E, Agave::KeyCode::E},
        {GLFW_KEY_F, Agave::KeyCode::F},
        {GLFW_KEY_G, Agave::KeyCode::G},
        {GLFW_KEY_H, Agave::KeyCode::H},
        {GLFW_KEY_I, Agave::KeyCode::I},
        {GLFW_KEY_J, Agave::KeyCode::J},
        {GLFW_KEY_K, Agave::KeyCode::K},
        {GLFW_KEY_L, Agave::KeyCode::L},
        {GLFW_KEY_M, Agave::KeyCode::M},
        {GLFW_KEY_N, Agave::KeyCode::N},
        {GLFW_KEY_O, Agave::KeyCode::O},
        {GLFW_KEY_P, Agave::KeyCode::P},
        {GLFW_KEY_Q, Agave::KeyCode::Q},
        {GLFW_KEY_R, Agave::KeyCode::R},
        {GLFW_KEY_S, Agave::KeyCode::S},
        {GLFW_KEY_T, Agave::KeyCode::T},
        {GLFW_KEY_U, Agave::KeyCode::U},
        {GLFW_KEY_V, Agave::KeyCode::V},
        {GLFW_KEY_W, Agave::KeyCode::W},
        {GLFW_KEY_X, Agave::KeyCode::X},
        {GLFW_KEY_Y, Agave::KeyCode::Y},
        {GLFW_KEY_Z, Agave::KeyCode::Z},
        {GLFW_KEY_LEFT_BRACKET, Agave::KeyCode::LeftBracket},
        {GLFW_KEY_BACKSLASH, Agave::KeyCode::Backslash},
        {GLFW_KEY_RIGHT_BRACKET, Agave::KeyCode::RightBracket},
        {GLFW_KEY_GRAVE_ACCENT, Agave::KeyCode::GraveAccent},
        {GLFW_KEY_WORLD_1, Agave::KeyCode::World1},
        {GLFW_KEY_WORLD_2, Agave::KeyCode::World2},
        {GLFW_KEY_ESCAPE, Agave::KeyCode::Escape},
        {GLFW_KEY_ENTER, Agave::KeyCode::Enter},
        {GLFW_KEY_TAB, Agave::KeyCode::Tab},
        {GLFW_KEY_BACKSPACE, Agave::KeyCode::Backspace},
        {GLFW_KEY_INSERT, Agave::KeyCode::Insert},
        {GLFW_KEY_DELETE, Agave::KeyCode::Delete},
        {GLFW_KEY_RIGHT, Agave::KeyCode::RightArrow},
        {GLFW_KEY_LEFT, Agave::KeyCode::LeftArrow},
        {GLFW_KEY_DOWN, Agave::KeyCode::DownArrow},
        {GLFW_KEY_UP, Agave::KeyCode::UpArrow},
        {GLFW_KEY_PAGE_UP, Agave::KeyCode::PageUp},
        {GLFW_KEY_PAGE_DOWN, Agave::KeyCode::PageDown},
        {GLFW_KEY_HOME, Agave::KeyCode::Home},
        {GLFW_KEY_END, Agave::KeyCode::End},
        {GLFW_KEY_CAPS_LOCK, Agave::KeyCode::CapsLock},
        {GLFW_KEY_SCROLL_LOCK, Agave::KeyCode::ScrollLock},
        {GLFW_KEY_NUM_LOCK, Agave::KeyCode::NumLock},
        {GLFW_KEY_PRINT_SCREEN, Agave::KeyCode::PrintScreen},
        {GLFW_KEY_PAUSE, Agave::KeyCode::Pause},
        {GLFW_KEY_F1, Agave::KeyCode::F1},
        {GLFW_KEY_F2, Agave::KeyCode::F2},
        {GLFW_KEY_F3, Agave::KeyCode::F3},
        {GLFW_KEY_F4, Agave::KeyCode::F4},
        {GLFW_KEY_F5, Agave::KeyCode::F5},
        {GLFW_KEY_F6, Agave::KeyCode::F6},
        {GLFW_KEY_F7, Agave::KeyCode::F7},
        {GLFW_KEY_F8, Agave::KeyCode::F8},
        {GLFW_KEY_F9, Agave::KeyCode::F9},
        {GLFW_KEY_F10, Agave::KeyCode::F10},
        {GLFW_KEY_F11, Agave::KeyCode::F11},
        {GLFW_KEY_F12, Agave::KeyCode::F12},
        {GLFW_KEY_F13, Agave::KeyCode::F13},
        {GLFW_KEY_F14, Agave::KeyCode::F14},
        {GLFW_KEY_F15, Agave::KeyCode::F15},
        {GLFW_KEY_F16, Agave::KeyCode::F16},
        {GLFW_KEY_F17, Agave::KeyCode::F17},
        {GLFW_KEY_F18, Agave::KeyCode::F18},
        {GLFW_KEY_F19, Agave::KeyCode::F19},
        {GLFW_KEY_F20, Agave::KeyCode::F20},
        {GLFW_KEY_F21, Agave::KeyCode::F21},
        {GLFW_KEY_F22, Agave::KeyCode::F22},
        {GLFW_KEY_F23, Agave::KeyCode::F23},
        {GLFW_KEY_F24, Agave::KeyCode::F24},
        {GLFW_KEY_F25, Agave::KeyCode::F25},
        {GLFW_KEY_KP_0, Agave::KeyCode::NumPad0},
        {GLFW_KEY_KP_1, Agave::KeyCode::NumPad1},
        {GLFW_KEY_KP_2, Agave::KeyCode::NumPad2},
        {GLFW_KEY_KP_3, Agave::KeyCode::NumPad3},
        {GLFW_KEY_KP_4, Agave::KeyCode::NumPad4},
        {GLFW_KEY_KP_5, Agave::KeyCode::NumPad5},
        {GLFW_KEY_KP_6, Agave::KeyCode::NumPad6},
        {GLFW_KEY_KP_7, Agave::KeyCode::NumPad7},
        {GLFW_KEY_KP_8, Agave::KeyCode::NumPad8},
        {GLFW_KEY_KP_9, Agave::KeyCode::NumPad9},
        {GLFW_KEY_KP_DECIMAL, Agave::KeyCode::NumPadPeriod},
        {GLFW_KEY_KP_DIVIDE, Agave::KeyCode::NumPadDivide},
        {GLFW_KEY_KP_MULTIPLY, Agave::KeyCode::NumPadMultiply},
        {GLFW_KEY_KP_SUBTRACT, Agave::KeyCode::NumPadMinus},
        {GLFW_KEY_KP_ADD, Agave::KeyCode::NumPadPlus},
        {GLFW_KEY_KP_ENTER, Agave::KeyCode::NumPadEnter},
        {GLFW_KEY_KP_EQUAL, Agave::KeyCode::NumPadEqual},
        {GLFW_KEY_LEFT_SHIFT, Agave::KeyCode::LeftShift},
        {GLFW_KEY_LEFT_CONTROL, Agave::KeyCode::LeftControl},
        {GLFW_KEY_LEFT_ALT, Agave::KeyCode::LeftAlt},
        {GLFW_KEY_LEFT_SUPER, Agave::KeyCode::LeftSuper},
        {GLFW_KEY_RIGHT_SHIFT, Agave::KeyCode::RightShift},
        {GLFW_KEY_RIGHT_CONTROL, Agave::KeyCode::RightControl},
        {GLFW_KEY_RIGHT_ALT, Agave::KeyCode::RightAlt},
        {GLFW_KEY_RIGHT_SUPER, Agave::KeyCode::RightSuper},
        {GLFW_KEY_MENU, Agave::KeyCode::Menu}
    };

    std::unordered_map<Agave::MouseButtonCode, s32> WindowsInput::m_agaveToGlfwMouseButtonCodeMap = {
        {Agave::MouseButtonCode::Button1, GLFW_MOUSE_BUTTON_1},
        {Agave::MouseButtonCode::Button2, GLFW_MOUSE_BUTTON_2},
        {Agave::MouseButtonCode::Button3, GLFW_MOUSE_BUTTON_3},
        {Agave::MouseButtonCode::Button4, GLFW_MOUSE_BUTTON_4},
        {Agave::MouseButtonCode::Button5, GLFW_MOUSE_BUTTON_5},
        {Agave::MouseButtonCode::Button6, GLFW_MOUSE_BUTTON_6},
        {Agave::MouseButtonCode::Button7, GLFW_MOUSE_BUTTON_7},
        {Agave::MouseButtonCode::Button8, GLFW_MOUSE_BUTTON_8}
    };

    std::unordered_map<s32, Agave::MouseButtonCode> WindowsInput::m_glfwToAgaveMouseButtonCodeMap = {
        {GLFW_MOUSE_BUTTON_1, Agave::MouseButtonCode::Button1},
        {GLFW_MOUSE_BUTTON_2, Agave::MouseButtonCode::Button2},
        {GLFW_MOUSE_BUTTON_3, Agave::MouseButtonCode::Button3},
        {GLFW_MOUSE_BUTTON_4, Agave::MouseButtonCode::Button4},
        {GLFW_MOUSE_BUTTON_5, Agave::MouseButtonCode::Button5},
        {GLFW_MOUSE_BUTTON_6, Agave::MouseButtonCode::Button6},
        {GLFW_MOUSE_BUTTON_7, Agave::MouseButtonCode::Button7},
        {GLFW_MOUSE_BUTTON_8, Agave::MouseButtonCode::Button8}
    };
}