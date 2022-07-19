///=============================================================================
/// OpenGLIndexBuffer.h
/// Platform/OpenGL
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL implementation of IndexBuffer.
///=============================================================================

#ifndef AGAVE_OPEN_GL_INDEX_BUFFER_H
#define AGAVE_OPEN_GL_INDEX_BUFFER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Render/IndexBuffer.h"

namespace Agave {

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
        virtual ~OpenGLIndexBuffer() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;
        virtual uint32_t GetCount() const override { return m_count; }

    private:
        uint32_t m_renderId;
        uint32_t m_count;
    };
}

#endif // #ifndef AGAVE_OPEN_GL_INDEX_BUFFER_H