///=============================================================================
/// Shader.cpp
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Shader abstraction
///=============================================================================

#ifndef AGAVE_SHADER_H
#define AGAVE_SHADER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include <string>

namespace Agave {

    class Shader
    {
    public:
        virtual ~Shader() {}

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
    };
}

#endif // #ifndef AGAVE_SHADER_H