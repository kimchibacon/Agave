///=============================================================================
/// Shader.cpp
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Shader abstraction
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Render/Shader.h"
#include "Agave/Render/Renderer.h"
#include "Agave/Core/Assert.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include <glad/glad.h>
#include <vector>

namespace Agave {

    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        // Determine which renderer implementation we're currently using.
        switch(Renderer::GetAPI())
        {
        case RenderAPI::None:
            AGAVE_CORE_ASSERT(false);
            return nullptr;
        case RenderAPI::OpenGL:
            return new OpenGLShader(vertexSrc, fragmentSrc);
        }

        // Should never be here.
        AGAVE_CORE_ASSERT(false);
        return nullptr;
    }
}