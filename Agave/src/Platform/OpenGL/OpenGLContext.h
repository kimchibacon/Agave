///=============================================================================
/// RenderContext.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL render context
///=============================================================================

#ifndef AGAVE_OPEN_GL_CONTEXT_H
#define AGAVE_OPEN_GL_CONTEXT_H

///=============================================================================
/// Forward Declarations
///=============================================================================
struct GLFWwindow;

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Render/RenderContext.h"

namespace Agave {

    class OpenGLContext : public RenderContext
    {
    public:
        OpenGLContext(GLFWwindow* pWindowHandle);
        virtual void Init() override;
        virtual void SwapBuffers() override;

    private:
        GLFWwindow* m_pWindowHandle;
    };
}

#endif // #ifndef AGAVE_OPEN_GL_CONTEXT_H