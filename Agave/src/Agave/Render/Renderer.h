///=============================================================================
/// Renderer.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Renderer abstraction
///=============================================================================

#ifndef AGAVE_RENDERER_H
#define AGAVE_RENDERER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Render/RenderCommand.h"
#include "Agave/Render/Shader.h"
#include "Agave/Render/VertexBuffer.h"
#include "Agave/Render/IndexBuffer.h"
#include "Agave/Render/VertexArray.h"
#include "Agave/Render/BufferLayout.h"

namespace Agave {

    class Renderer
    {
    public:
        static void BeginScene();
        static void EndScene();
        static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

        static RenderAPI::API GetAPI() { return RenderAPI::GetAPI(); }
    };
}

#endif // #ifndef AGAVE_RENDERER_H