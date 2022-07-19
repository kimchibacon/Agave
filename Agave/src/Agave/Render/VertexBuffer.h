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

namespace Agave {

    class VertexBuffer {
    public:
        virtual ~VertexBuffer() {}

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static VertexBuffer* Create(float* vertices, u32 size);
    };
}

#endif // #ifndef AGAVE_VERTEX_BUFFER_H