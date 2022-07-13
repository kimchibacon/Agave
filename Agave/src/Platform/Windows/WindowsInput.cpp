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

namespace Agave {

    Input* Input::ms_pInstance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(s32 keycode)
    {
        auto pWindow = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
        s32 state = glfwGetKey(pWindow, keycode);

        return (state == GLFW_PRESS) || (state == GLFW_REPEAT);
    }

    bool WindowsInput::IsMouseButtonPressedImpl(s32 button)
    {
        auto pWindow = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
        s32 state = glfwGetMouseButton(pWindow, button);
        
        return (state == GLFW_PRESS);
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto pWindow = static_cast< GLFWwindow* >(Application::Instance().GetWindow().GetNativeWindow());
        double xPos;
        double yPos;

        glfwGetCursorPos(pWindow, &xPos, &yPos);

        return {(float)xPos, (float)yPos};
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto pWindow = static_cast< GLFWwindow* >(Application::Instance().GetWindow().GetNativeWindow());
        double xPos;
        double yPos;
        glfwGetCursorPos(pWindow, &xPos, &yPos);

        return (float)xPos;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto pWindow = static_cast< GLFWwindow* >(Application::Instance().GetWindow().GetNativeWindow());
        double xPos;
        double yPos;
        glfwGetCursorPos(pWindow, &xPos, &yPos);

        return (float)yPos;
    }
}