///=============================================================================
/// Application.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Application singleton class representing client application.
///=============================================================================

#ifndef AGAVE_APPLICATION_H
#define AGAVE_APPLICATION_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Core/Window.h"
#include "Agave/Events/ApplicationEvent.h"
#include "Agave/Core/LayerStack.h"
#include "Agave/ImGui/ImGuiLayer.h"
#include "Agave/Render/VertexBuffer.h"
#include "Agave/Render/IndexBuffer.h"
#include "Agave/Render/Shader.h"

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    class Application
    {
    public:
        ///=====================================================================
        /// Ctor/Dtor
        ///=====================================================================
        Application();
        virtual ~Application();

    public:
        ///=====================================================================
        /// Public Methods
        ///=====================================================================
        static Application& Instance() { return *ms_pInstance; }

        Window& GetWindow() { return *m_pWindow; }
        void Run();
        void OnEvent(Event& event);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        ///=====================================================================
        /// Private Methods
        ///=====================================================================
    private:
        bool OnWindowClosed(WindowClosedEvent& event);

    private:
        ///=====================================================================
        /// Private Fields
        ///=====================================================================
        std::unique_ptr<Window>     m_pWindow;
        bool                        m_running;
        LayerStack                  m_layerStack;
        ImGuiLayer*                 m_pImGuiLayer;

        u32                         m_vertexArray;
        std::unique_ptr<Shader>     m_pShader;
        std::unique_ptr<VertexBuffer> m_pVertexBuffer;
        std::unique_ptr<IndexBuffer>  m_pIndexBuffer;

        static Application*         ms_pInstance;
    };

    // Defined by client
    Application* CreateApplication();
} 

#endif // #ifndef AGAVE_APPLICATION_H