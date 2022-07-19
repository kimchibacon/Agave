///=============================================================================
/// OpenGLShader.h
/// Platform/OpenGL
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL implementation of Shader
///=============================================================================

#ifndef AGAVE_OPEN_GL_SHADER_H
#define AGAVE_OPEN_GL_SHADER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Render/Shader.h"

namespace Agave {

    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
        virtual ~OpenGLShader() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;

    private:
        uint32_t m_renderId;
    };
}

#endif // #ifndef AGAVE_OPEN_GL_SHADER_H