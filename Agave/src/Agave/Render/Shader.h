#ifndef AGAVE_SHADER_H
#define AGAVE_SHADER_H

#include <Agave/Core/Base.h>
#include <string>

namespace Agave {

    class Shader
    {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();

        void Bind() const;
        void Unbind() const;

    private:
        u32 m_renderId;
    };
}

#endif // #ifndef AGAVE_SHADER_H