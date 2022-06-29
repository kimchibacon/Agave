///=============================================================================
/// WindowsWindow.cpp
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Windows implementation of Agave display window
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Platform/Windows/WindowsWindow.h"
#include "Agave/Core/Log.h"
#include "Agave/Core/Assert.h"

namespace Agave {

    ///=========================================================================
    /// Defs
    ///=========================================================================
    static bool s_GLFWInitialized = false;

    ///=========================================================================
    ///=========================================================================
    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    ///=========================================================================
    ///=========================================================================
    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }

    ///=========================================================================
    ///=========================================================================
    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    ///=========================================================================
    ///=========================================================================
    void WindowsWindow::Init(const WindowProps& props)
    {
        m_data.m_title = props.m_title;
        m_data.m_width = props.m_width;
        m_data.m_height = props.m_height;

        AgCoreLogInfo("Creating window {0} ({1}, {2})", props.m_title, props.m_width, props.m_height);

        if (!s_GLFWInitialized)
        {
            s32 success = glfwInit();
            AGAVE_CORE_ASSERT(success == GLFW_TRUE);

            s_GLFWInitialized = true;
        }

        m_pWindow = glfwCreateWindow((s32)props.m_width, (s32)props.m_height, props.m_title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_pWindow);
        glfwSetWindowUserPointer(m_pWindow, &m_data);
        SetVSync(true);
    }

    ///=========================================================================
    ///=========================================================================
    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_pWindow);
    }

    ///=========================================================================
    ///=========================================================================
    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_pWindow);
    }

    ///=========================================================================
    ///=========================================================================
    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_data.m_isVSync = enabled;
    }

    ///=========================================================================
    ///=========================================================================
    bool WindowsWindow::IsVSync() const
    {
        return m_data.m_isVSync;
    }
}