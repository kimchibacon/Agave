///=============================================================================
/// IndexBuffer.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Index buffer abstraction
///=============================================================================

#ifndef AGAVE_INDEX_BUFFER_H
#define AGAVE_INDEX_BUFFER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"

namespace Agave {

    class IndexBuffer {
    public:
        virtual ~IndexBuffer() {}

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        virtual u32 GetCount() const = 0;

        static IndexBuffer* Create(u32* indices, u32 count);
    };
}

#endif // #ifndef AGAVE_INDEX_BUFFER_H