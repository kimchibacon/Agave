#ifndef AGAVE_OPEN_GL_RENDER_API_H
#define AGAVE_OPEN_GL_RENDER_API_H

#include "Agave/Render/RenderAPI.h"

namespace Agave {

    class OpenGLRenderAPI : public RenderAPI
    {
    public:
        virtual void SetClearColor(const glm::vec4& color) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
    };
}

#endif // #ifndef AGAVE_OPEN_GL_RENDER_API_H