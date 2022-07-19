///=============================================================================
/// IndexBuffer.cpp
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Index buffer abstraction
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Render/IndexBuffer.h"
#include "Agave/Render/Renderer.h"
#include "Agave/Core/Assert.h"
#include "Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Agave {

    ///=============================================================================
    ///=============================================================================
    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        // Determine which renderer implementation we're currently using.
        switch(Renderer::GetAPI())
        {
        case RenderAPI::None:
            AGAVE_CORE_ASSERT(false);
            return nullptr;
        case RenderAPI::OpenGL:
            return new OpenGLIndexBuffer(indices, count);
        }

        // Should never be here.
        AGAVE_CORE_ASSERT(false);
        return nullptr;
    }
}