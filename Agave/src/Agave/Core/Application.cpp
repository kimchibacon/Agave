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

        // TRIANGLE
        m_pTriangleVA.reset(VertexArray::Create());

        float vertices[3 * 7]{
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
            0.5f, -0.5f, 0.0f, 0.2f, 0.2f, 0.8f, 1.0f,
            0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        std::shared_ptr<VertexBuffer> triangleVB;
        triangleVB.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

        BufferLayout layout = {
            {ShaderDataType::Float3, "a_Position"},
            {ShaderDataType::Float4, "a_Color"}
        };
        triangleVB->SetLayout(layout);

        m_pTriangleVA->AddVertexBuffer(triangleVB);

        uint32_t indices[3] = { 0, 1, 2 };
        std::shared_ptr<IndexBuffer> triangleIB;
        triangleIB.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_pTriangleVA->SetIndexBuffer(triangleIB);

        std::string vertexSrc = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;
            
            out vec3 v_Position;
            out vec4 v_Color;

            void main()
            {
                v_Position = a_Position + 0.5;
                v_Color = a_Color;
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentSrc = R"(
            #version 330 core
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;
            in vec4 v_Color;

            void main()
            {
                color = vec4((v_Position * 0.5 + 0.5), 1.0);
                color = v_Color;
            }
        )";

        m_pTriangleShader.reset(Shader::Create(vertexSrc, fragmentSrc));


        // SQUARE 
        m_pSquareVA.reset(VertexArray::Create());

        float squareVertices[3 * 4]{
            -0.75f, -0.75f, 0.0f,
            0.75f, -0.75f, 0.0f,
            0.75f, 0.75f, 0.0f,
            -0.75f, 0.75f, 0.0f
        };

        std::shared_ptr<VertexBuffer> squareVB;
        squareVB.reset(VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

        BufferLayout squareLayout = {
            {ShaderDataType::Float3, "a_Position"}
        };

        squareVB->SetLayout(squareLayout);
        m_pSquareVA->AddVertexBuffer(squareVB);

        uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
        std::shared_ptr<IndexBuffer> squareIB;
        squareIB.reset(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
        m_pSquareVA->SetIndexBuffer(squareIB);

        std::string vertex2Src = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
            
            out vec3 v_Position;

            void main()
            {
                v_Position = a_Position + 0.5;
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string fragment2Src = R"(
            #version 330 core
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;

            void main()
            {
                color = vec4(0.2, 0.2, 0.8, 1.0);
            }
        )";

        m_pSquareShader2.reset(Shader::Create(vertex2Src, fragment2Src));
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
            m_pSquareShader2->Bind();
            m_pSquareVA->Bind();
            glDrawElements(GL_TRIANGLES, m_pSquareVA->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
            m_pSquareVA->Unbind();
            m_pSquareShader2->Unbind();

            m_pTriangleShader->Bind();
            m_pTriangleVA->Bind();
            glDrawElements(GL_TRIANGLES, m_pTriangleVA->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
            m_pTriangleVA->Unbind();
            m_pTriangleShader->Unbind();

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