/// ============================================================================
/// OpenGLVertexArray.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL implementation of VertexArray.
///=============================================================================

#ifndef AGAVE_OPEN_GL_VERTEX_ARRAY_H
#define AGAVE_OPEN_GL_VERTEX_ARRAY_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Render/VertexArray.h"

namespace Agave {

    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;
        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& pBuffer);
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& pBuffer);
        virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return m_vertexBuffers; }
        virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return m_indexBuffer; }

    private:
        std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
        std::shared_ptr<IndexBuffer> m_indexBuffer;
        uint32_t m_renderId;
        BufferLayout m_layout;
    };
}

#endif // #ifndef AGAVE_OPEN_GL_VERTEX_ARRAY_H