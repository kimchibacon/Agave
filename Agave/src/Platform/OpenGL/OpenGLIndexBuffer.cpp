///=============================================================================
/// OpenGLIndexBuffer.cpp
/// Platform/OpenGL
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL implementation of IndexBuffer.
///=============================================================================
#include "Platform/OpenGL/OpenGLIndexBuffer.h"
#include <glad/glad.h>

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
        : m_count(count)
    {
        glCreateBuffers(1, &m_renderId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    ///=========================================================================
    ///=========================================================================
    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &m_renderId);
    }

    ///=========================================================================
    ///=========================================================================
    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderId);
    }

    ///=========================================================================
    ///=========================================================================
    void OpenGLIndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}