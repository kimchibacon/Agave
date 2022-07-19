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
#include "Agave/Core/Base.h"
#include "Agave/Render/VertexBuffer.h"

namespace Agave {

    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;
        virtual void SetLayout(const BufferLayout& layout) override { m_layout = layout; }
        virtual const BufferLayout& GetLayout() const override { return m_layout; }

    private:
        uint32_t m_renderId;
        BufferLayout m_layout;
    };
}

#endif // #ifndef AGAVE_OPEN_GL_VERTEX_BUFFER_H