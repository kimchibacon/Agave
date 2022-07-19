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
#include "Agave/Render/IndexBuffer.h"

namespace Agave {

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(u32* indices, u32 count);
        virtual ~OpenGLIndexBuffer() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;
        virtual u32 GetCount() const override { return m_count; }

    private:
        u32 m_renderId;
        u32 m_count;
    };
}

#endif // #ifndef AGAVE_OPEN_GL_INDEX_BUFFER_H