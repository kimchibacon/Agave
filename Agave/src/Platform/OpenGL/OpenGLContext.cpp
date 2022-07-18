///=============================================================================
/// RenderContext.cpp
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL render context
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Platform/OpenGL/OpenGLContext.h"
#include "Agave/Core/Assert.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace Agave {

    OpenGLContext::OpenGLContext(GLFWwindow* pWindowHandle)
        : m_pWindowHandle(pWindowHandle)
    {
        AGAVE_CORE_ASSERT(m_pWindowHandle != nullptr);
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_pWindowHandle);
        int status = gladLoadGLLoader(( GLADloadproc )glfwGetProcAddress);
        AGAVE_CORE_ASSERT(status);
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_pWindowHandle);

        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}