///=============================================================================
/// VertexBuffer.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Vertex buffer abstraction
///=============================================================================

#ifndef AGAVE_VERTEX_BUFFER_H
#define AGAVE_VERTEX_BUFFER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Render/BufferLayout.h"

namespace Agave {

    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        virtual void SetLayout(const BufferLayout& layout) = 0;
        virtual const BufferLayout& GetLayout() const = 0;

        static VertexBuffer* Create(float* vertices, uint32_t size);
    };
}

#endif // #ifndef AGAVE_VERTEX_BUFFER_H