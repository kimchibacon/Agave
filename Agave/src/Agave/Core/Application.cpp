///=============================================================================
/// Application.cpp
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Singleton class representing client application.
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Application.h"
#include "Agave/Core/Log.h"
#include "Agave/Core/Delegate.h"
#include "Agave/Core/Assert.h"
#include <glad/glad.h>

namespace Agave {

    Application* Application::ms_pInstance = nullptr;

    ///=========================================================================
    ///=========================================================================
    Application::Application()
        : m_running(true)
    {
        AGAVE_CORE_ASSERT(ms_pInstance == nullptr);
        ms_pInstance = this;

        m_pWindow = std::unique_ptr<Window>(Window::Create());

        Gallant::Delegate<void (Event&)> callback;
        callback.Bind(this, &Application::OnEvent);
        m_pWindow->SetEventCallback(callback);

        m_pImGuiLayer = new ImGuiLayer();
        PushOverlay(m_pImGuiLayer);

        glGenVertexArrays(1, &m_vertexArray);
        glBindVertexArray(m_vertexArray);

        float vertices[3 * 3]{
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
        };

        m_pVertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3 * sizeof(float)), nullptr);

        u32 indices[3] = { 0, 1, 2 };
        m_pIndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(u32)));

        std::string vertexSrc = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
            
            out vec3 v_Position;

            void main()
            {
                v_Position = a_Position + 0.5;
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentSrc = R"(
            #version 330 core
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;

            void main()
            {
                color = vec4(v_Position * 0.5 + 0.5, 1.0);
            }
        )";

        m_pShader = std::make_unique<Shader>(vertexSrc, fragmentSrc);
    }

    ///=========================================================================
    ///=========================================================================
    Application::~Application()
    {}

    ///=========================================================================
    ///=========================================================================
    void Application::Run()
    {
        while (m_running)
        {
            m_pShader->Bind();
            {
                glBindVertexArray(m_vertexArray);
                glDrawElements(GL_TRIANGLES, m_pIndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);
            }
            m_pShader->Unbind();

            m_layerStack.OnUpdate();

            // Render ImGui on all layers
            m_pImGuiLayer->Begin();
            for(Layer* layer : m_layerStack)
                layer->OnImGuiRender();
            m_pImGuiLayer->End();

            m_pWindow->OnUpdate();
        }
    }

    ///=========================================================================
    ///=========================================================================
    void Application::OnEvent(Event& event)
    {
        DISPATCH_EVENT(event, WindowClosedEvent, &Application::OnWindowClosed);

        m_layerStack.OnEvent(event);
    }

    ///=========================================================================
    ///=========================================================================
    void Application::PushLayer(Layer* layer)
    {
        m_layerStack.PushLayer(layer);
    }

    ///=========================================================================
    ///=========================================================================
    void Application::PushOverlay(Layer* overlay)
    {
        m_layerStack.PushOverlay(overlay);
    }

    ///=========================================================================
    ///=========================================================================
    bool Application::OnWindowClosed(WindowClosedEvent& event)
    {
        event.m_handled = true;
        m_running = false;
        return true;
    }
}