///=============================================================================
/// OpenGLVertexBuffer.h
/// Platform/OpenGL
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL implementation of VertexBuffer.
///=============================================================================

#ifndef AGAVE_OPEN_GL_VERTEX_BUFFER_H
#define AGAVE_OPEN_GL_VERTEX_BUFFER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Render/VertexBuffer.h"

namespace Agave {

    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, u32 size);
        virtual ~OpenGLVertexBuffer() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;

    private:
        u32 m_renderId;
    };
}

#endif // #ifndef AGAVE_OPEN_GL_VERTEX_BUFFER_H