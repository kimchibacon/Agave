///=============================================================================
/// Sandbox.cpp
/// Sandbox
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Sandbox application for AgaveEngine testing.
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Core/Log.h"
#include <Agave/Core/EntryPoint.h>
#include <Agave/Core/Application.h>
#include <Agave/Core/Layer.h>
#include <Agave/Core/Timestep.h>
#include <Agave/Core/Input.h>

#include <Agave/Render/Renderer.h>
#include <Agave/Render/OrthographicCamera.h>

class ExampleLayer : public Agave::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {}

    virtual void OnUpdate(Agave::Timestep dt) override
    {
        if(Agave::Input::IsKeyPressed(Agave::KeyCode::Tab))
            AGAVE_TRACE("Tab key is pressed");
    }

    virtual void OnEvent(Agave::Event& event) override
    {}
};

class RenderLayer : public Agave::Layer 
{
public:
    RenderLayer()
        : Layer("Render")
        , m_camera(-1.6f, 1.6f, -0.9f, 0.9f)
        , m_cameraPosition(m_camera.GetPosition())
        , m_cameraSpeed(10.0f)
        , m_cameraRotation(0.0f)
        , m_cameraRotationSpeed(180.0f)
    {
        // TRIANGLE
        m_pTriangleVA.reset(Agave::VertexArray::Create());

        float vertices[3 * 7]{
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
            0.5f, -0.5f, 0.0f, 0.2f, 0.2f, 0.8f, 1.0f,
            0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        std::shared_ptr<Agave::VertexBuffer> triangleVB;
        triangleVB.reset(Agave::VertexBuffer::Create(vertices, sizeof(vertices)));

        Agave::BufferLayout layout = {
            {Agave::ShaderDataType::Float3, "a_Position"},
            {Agave::ShaderDataType::Float4, "a_Color"}
        };
        triangleVB->SetLayout(layout);

        m_pTriangleVA->AddVertexBuffer(triangleVB);

        uint32_t indices[3] = { 0, 1, 2 };
        std::shared_ptr<Agave::IndexBuffer> triangleIB;
        triangleIB.reset(Agave::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_pTriangleVA->SetIndexBuffer(triangleIB);

        std::string vertexSrc = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;
            
            out vec3 v_Position;
            out vec4 v_Color;

            void main()
            {
                v_Position = a_Position + 0.5;
                v_Color = a_Color;
                gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

        m_pTriangleShader.reset(Agave::Shader::Create(vertexSrc, fragmentSrc));


        // SQUARE 
        m_pSquareVA.reset(Agave::VertexArray::Create());

        float squareVertices[3 * 4]{
            -0.75f, -0.75f, 0.0f,
            0.75f, -0.75f, 0.0f,
            0.75f, 0.75f, 0.0f,
            -0.75f, 0.75f, 0.0f
        };

        std::shared_ptr<Agave::VertexBuffer> squareVB;
        squareVB.reset(Agave::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

        Agave::BufferLayout squareLayout = {
            {Agave::ShaderDataType::Float3, "a_Position"}
        };

        squareVB->SetLayout(squareLayout);
        m_pSquareVA->AddVertexBuffer(squareVB);

        uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
        std::shared_ptr<Agave::IndexBuffer> squareIB;
        squareIB.reset(Agave::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
        m_pSquareVA->SetIndexBuffer(squareIB);

        std::string vertex2Src = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;

            uniform mat4 u_ViewProjection;            

            out vec3 v_Position;

            void main()
            {
                v_Position = a_Position + 0.5;
                gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

        m_pSquareShader.reset(Agave::Shader::Create(vertex2Src, fragment2Src));
    }

    virtual void OnUpdate(Agave::Timestep dt) override
    {
        if (Agave::Input::IsKeyPressed(Agave::KeyCode::LeftArrow))
        {
            m_cameraPosition.x -= m_cameraSpeed * dt;
        }
        else if (Agave::Input::IsKeyPressed(Agave::KeyCode::RightArrow))
        {
            m_cameraPosition.x += m_cameraSpeed * dt;
        }

        if (Agave::Input::IsKeyPressed(Agave::KeyCode::UpArrow))
        {
            m_cameraPosition.y += m_cameraSpeed * dt;
        }
        else if (Agave::Input::IsKeyPressed(Agave::KeyCode::DownArrow))
        {
            m_cameraPosition.y -= m_cameraSpeed * dt;
        }

        if (Agave::Input::IsKeyPressed(Agave::KeyCode::A))
        {
            m_cameraRotation += m_cameraRotationSpeed * dt;
        }
        else if (Agave::Input::IsKeyPressed(Agave::KeyCode::D))
        {
            m_cameraRotation -= m_cameraRotationSpeed * dt;
        }

        Agave::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
        Agave::RenderCommand::Clear();

        m_camera.SetPosition(m_cameraPosition);
        m_camera.SetRotation(m_cameraRotation);

        Agave::Renderer::BeginScene(m_camera);
        {
            Agave::Renderer::Submit(m_pSquareShader, m_pSquareVA);
            Agave::Renderer::Submit(m_pTriangleShader, m_pTriangleVA);
        }
        Agave::Renderer::EndScene();
    }

private:
    std::shared_ptr<Agave::Shader>         m_pTriangleShader;
    std::shared_ptr<Agave::VertexArray>    m_pTriangleVA;
    std::shared_ptr<Agave::Shader>         m_pSquareShader;
    std::shared_ptr<Agave::VertexArray>    m_pSquareVA;
    Agave::OrthographicCamera m_camera;

    glm::vec3 m_cameraPosition;
    float m_cameraSpeed;
    float m_cameraRotation;
    float m_cameraRotationSpeed;
};

///=============================================================================
///=============================================================================
class Sandbox : public Agave::Application
{
public:
    ///=========================================================================
    ///=========================================================================
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushLayer(new RenderLayer());
    }

    ///=========================================================================
    ///=========================================================================
    ~Sandbox()
    {}
};

///=============================================================================
/// Extern Functions
///=============================================================================
Agave::Application* Agave::CreateApplication()
{
    return new Sandbox();
}