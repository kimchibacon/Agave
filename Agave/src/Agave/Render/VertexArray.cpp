///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Render/VertexArray.h"
#include "Agave/Render/Renderer.h"
#include "Agave/Core/Assert.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Agave {

    VertexArray* VertexArray::Create()
    {
        // Determine which renderer implementation we're currently using.
        switch(Renderer::GetAPI())
        {
        case RenderAPI::API::None:
            AGAVE_CORE_ASSERT(false);
            return nullptr;
        case RenderAPI::API::OpenGL:
            return new OpenGLVertexArray();
        }

        // Should never be here.
        AGAVE_CORE_ASSERT(false);
        return nullptr;
    }
}