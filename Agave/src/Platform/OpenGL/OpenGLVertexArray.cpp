/// ============================================================================
/// OpenGLVertexArray.cpp
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL implementation of VertexArray.
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Platform/OpenGL/OpenGLVertexArray.h"
#include "glad/glad.h"

namespace Agave{

    ///=============================================================================
    /// Defs
    ///=============================================================================
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch(type)
        {
        case ShaderDataType::Float:     return GL_FLOAT;
        case ShaderDataType::Float2:    return GL_FLOAT;
        case ShaderDataType::Float3:    return GL_FLOAT;
        case ShaderDataType::Float4:    return GL_FLOAT;
        case ShaderDataType::Mat3:      return GL_FLOAT;
        case ShaderDataType::Mat4:      return GL_FLOAT;
        case ShaderDataType::Int:       return GL_INT;
        case ShaderDataType::Int2:      return GL_INT;
        case ShaderDataType::Int3:      return GL_INT;
        case ShaderDataType::Int4:      return GL_INT;
        case ShaderDataType::Bool:      return GL_BOOL;
        }

        AGAVE_CORE_ASSERT(false);
        return 0;
    }

    ///=========================================================================
    ///=========================================================================
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &m_renderId);
    }

    ///=========================================================================
    ///=========================================================================
    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_renderId);
    }

    ///=========================================================================
    ///=========================================================================
    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_renderId);
    }

    ///=========================================================================
    ///=========================================================================
    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    ///=========================================================================
    ///=========================================================================
    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
    {
        // The vertex buffer must have a valid layout before
        // adding it to the vertex array.
        AGAVE_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size());
        
        glBindVertexArray(m_renderId);

        vertexBuffer->Bind();
        {
            uint32_t index = 0;
            const BufferLayout& layout = vertexBuffer->GetLayout();
            for(const auto& element : layout)
            {
                glEnableVertexAttribArray(index);
                glVertexAttribPointer(index,
                    element.GetComponentCount(),
                    ShaderDataTypeToOpenGLBaseType(element.m_type),
                    element.m_normalized ? GL_TRUE : GL_FALSE,
                    layout.GetStride(),
                    ( const void* )element.m_offset);
                ++index;
            }
        }
        vertexBuffer->Unbind();

        m_vertexBuffers.push_back(vertexBuffer);
    }

    ///=========================================================================
    ///=========================================================================
    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(m_renderId);
        indexBuffer->Bind();

        m_indexBuffer = indexBuffer;
    }
}