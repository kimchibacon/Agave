/// ============================================================================
/// VertexArray.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Vertex array abstraction
///=============================================================================

#ifndef AGAVE_VERTEX_ARRAY_H
#define AGAVE_VERTEX_ARRAY_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Render/VertexBuffer.h"
#include "Agave/Render/IndexBuffer.h"
#include <memory>

namespace Agave {

    class VertexArray 
    {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& pBuffer) = 0;
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& pBuffer) = 0;

        virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
        virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;

        static VertexArray* Create();
    };
}

#endif // #ifndef AGAVE_VERTEX_ARRAY_H