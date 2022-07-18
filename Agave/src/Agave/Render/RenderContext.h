///=============================================================================
/// RenderContext.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Render context abstraction
///=============================================================================

#ifndef AGAVE_RENDER_CONTEXT
#define AGAVE_RENDER_CONTEXT

///=============================================================================
/// Includes
///=============================================================================

namespace Agave {

    class RenderContext
    {
    public:
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };
}

#endif // #ifndef AGAVE_RENDER_CONTEXT