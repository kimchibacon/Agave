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
        virtual ~IndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        virtual uint32_t GetCount() const = 0;

        static IndexBuffer* Create(uint32_t* indices, uint32_t count);
    };
}

#endif // #ifndef AGAVE_INDEX_BUFFER_H