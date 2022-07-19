///=============================================================================
/// OpenGLVertexBuffer.cpp
/// Platform/OpenGL
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL implementation of VertexBuffer.
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Platform/OpenGL/OpenGLVertexBuffer.h"
#include <glad/glad.h>

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, u32 size)        
    {
        glCreateBuffers(1, &m_renderId);
        glBindBuffer(GL_ARRAY_BUFFER, m_renderId);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }
    ///=========================================================================
    ///=========================================================================
    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &m_renderId);
    }

    ///=========================================================================
    ///=========================================================================
    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_renderId);
    }

    ///=========================================================================
    ///=========================================================================
    void OpenGLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}