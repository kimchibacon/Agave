///=============================================================================
/// VertexBuffer.cpp
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Vertex buffer abstraction
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Render/VertexBuffer.h"
#include "Agave/Render/Renderer.h"
#include "Agave/Core/Assert.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Agave {

    ///=============================================================================
    ///=============================================================================
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        // Determine which renderer implementation we're currently using.
        switch (Renderer::GetAPI())
        {
        case RenderAPI::None:
            AGAVE_CORE_ASSERT(false);
            return nullptr;
        case RenderAPI::OpenGL:
            return new OpenGLVertexBuffer(vertices, size);
        }

        // Should never be here.
        AGAVE_CORE_ASSERT(false);
        return nullptr;
    }
}