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

namespace Agave {

    enum class RenderAPI
    {
        None = 0, OpenGL = 1
    };

    class Renderer
    {
    public:
        static RenderAPI GetAPI() { return ms_renderAPI; }

    private:
        static RenderAPI ms_renderAPI;
    };
}

#endif // #ifndef AGAVE_RENDERER_H