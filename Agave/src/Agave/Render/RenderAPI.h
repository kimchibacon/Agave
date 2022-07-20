#ifndef AGAVE_RENDER_API_H
#define AGAVE_RENDER_API_H

#include "Agave/Render/VertexArray.h"
#include <glm/glm.hpp>

namespace Agave {

    class RenderAPI
    {
    public:
        enum class API
        {
            None = 0, OpenGL = 1
        };

    public:
        virtual void SetClearColor(const glm::vec4& color) = 0;
        virtual void Clear() = 0;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

        static API GetAPI() { return ms_api; }

    private:
        static API ms_api;
    };
}

#endif // #ifndef AGAVE_RENDER_API_H