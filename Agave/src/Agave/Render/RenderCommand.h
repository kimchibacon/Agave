#ifndef AGAVE_RENDER_COMMAND_H
#define AGAVE_RENDER_COMMAND_H

#include "Agave/Render/RenderAPI.h"

namespace Agave {

    class RenderCommand
    {
    public:
        static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
        {
            ms_pRenderAPI->DrawIndexed(vertexArray);
        }

        static void SetClearColor(const glm::vec4& color)
        {
            ms_pRenderAPI->SetClearColor(color);
        }

        static void Clear()
        {
            ms_pRenderAPI->Clear();
        }

    private:
        static RenderAPI* ms_pRenderAPI;
    };
}

#endif // #ifndef AGAVE_RENDER_COMMAND_H