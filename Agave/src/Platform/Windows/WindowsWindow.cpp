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
#include "Platform/Windows/WindowsInput.h"
#include "Agave/Core/Log.h"
#include "Agave/Core/Assert.h"
#include "Agave/Events/ApplicationEvent.h"
#include "Agave/Events/KeyEvent.h"
#include "Agave/Events/MouseEvent.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include <GLFW/glfw3.h>

namespace Agave {

    ///=========================================================================
    /// Defs
    ///=========================================================================
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* desc)
    {
        AGAVE_CORE_ERROR("GLFW ERROR ({0}): {1}", error, desc);
    }

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

        AGAVE_CORE_INFO("Creating window {0} ({1}, {2})", props.m_title, props.m_width, props.m_height);

        if (!s_GLFWInitialized)
        {
            s32 success = glfwInit();
            AGAVE_CORE_ASSERT(success == GLFW_TRUE);
            glfwSetErrorCallback(GLFWErrorCallback);

            s_GLFWInitialized = true;
        }

        m_pWindow = glfwCreateWindow((s32)props.m_width, (s32)props.m_height, props.m_title.c_str(), nullptr, nullptr);
        m_pContext = new OpenGLContext(m_pWindow);
        m_pContext->Init();

        glfwSetWindowUserPointer(m_pWindow, &m_data);
        SetVSync(true);

        RegisterEventCallbacks();
    }

    ///=========================================================================
    ///=========================================================================
    void WindowsWindow::RegisterEventCallbacks()
    {
        glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow* pWindow, int width, int height)
            {
                WindowData* pData = (WindowData*)glfwGetWindowUserPointer(pWindow);
                pData->m_width = width;
                pData->m_height = height;

                WindowResizedEvent event(width, height);
                pData->m_eventCallback(event);
            });

        glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* pWindow)
            {
                WindowData* pData = (WindowData*)glfwGetWindowUserPointer(pWindow);

                WindowClosedEvent event;
                pData->m_eventCallback(event);
            });

        glfwSetKeyCallback(m_pWindow, [](GLFWwindow* pWindow, int keycode, int scancode, int action, int mods)
            {
                WindowData* pData = ( WindowData* )glfwGetWindowUserPointer(pWindow);

                switch (action)
                {
                    case GLFW_PRESS:
                    {
                        KeyPressedEvent event(WindowsInput::GlfwKeyToAgaveKey(keycode));
                        pData->m_eventCallback(event);
                        break;
                    }
                    case GLFW_RELEASE:
                    {
                        KeyReleasedEvent event(WindowsInput::GlfwKeyToAgaveKey(keycode));
                        pData->m_eventCallback(event);
                        break;
                    }
                    case GLFW_REPEAT:
                    {
                        KeyPressedEvent event(WindowsInput::GlfwKeyToAgaveKey(keycode), true);
                        pData->m_eventCallback(event);
                        break;
                    }
                }
            });

        glfwSetCharCallback(m_pWindow, [](GLFWwindow* pWindow, u32 keycode)
            {
                WindowData* pData = ( WindowData* )glfwGetWindowUserPointer(pWindow);
                KeyTypedEvent event(WindowsInput::GlfwKeyToAgaveKey(keycode));
                pData->m_eventCallback(event);
      
            });

        glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* pWindow, int button, int action, int mods)
            {
                WindowData* pData = ( WindowData* )glfwGetWindowUserPointer(pWindow);

                switch (action)
                {
                    case GLFW_PRESS:
                    {
                        MouseButtonPressedEvent event(WindowsInput::GlfwMouseButtonToAgaveMouseButton(button));
                        pData->m_eventCallback(event);
                        break;

                    }
                    case GLFW_RELEASE:
                    {
                        MouseButtonReleasedEvent event(WindowsInput::GlfwMouseButtonToAgaveMouseButton(button));
                        pData->m_eventCallback(event);
                        break;
                    }
                }
            });

        glfwSetScrollCallback(m_pWindow, [](GLFWwindow* pWindow, double xOffset, double yOffset)
            {
                WindowData* pData = ( WindowData* )glfwGetWindowUserPointer(pWindow);

                MouseScrolledEvent event((float)xOffset, (float)yOffset);
                pData->m_eventCallback(event);
            });

        glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow* pWindow, double xPos, double yPos)
            {
                WindowData* pData = ( WindowData* )glfwGetWindowUserPointer(pWindow);

                MouseMovedEvent event((float)xPos, (float)yPos);
                pData->m_eventCallback(event);
            });
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
        m_pContext->SwapBuffers();
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