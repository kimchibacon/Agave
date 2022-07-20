///=============================================================================
/// Renderer.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Renderer abstraction
///=============================================================================

#include "Agave/Render/Renderer.h"

namespace Agave {

    Renderer::SceneData* Renderer::ms_pSceneData = new Renderer::SceneData;

    ///=========================================================================
    ///=========================================================================
    void Renderer::BeginScene(OrthographicCamera& camera)
    {
        ms_pSceneData->m_viewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    ///=========================================================================
    ///=========================================================================
    void Renderer::EndScene()
    {

    }

    ///=========================================================================
    ///=========================================================================
    void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray)
    {
        shader->Bind();
        shader->UploadUniformMat4("u_ViewProjection", ms_pSceneData->m_viewProjectionMatrix);
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
}