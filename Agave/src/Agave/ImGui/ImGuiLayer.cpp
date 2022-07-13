///=============================================================================
/// ImGuiLayer.cpp
/// Agave/ImGuiLayer
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Debug GUI layer
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/ImGui/ImGuiLayer.h"
#include "Agave/Core/AgaveTypes.h"
#include "Agave/Core/Application.h"
#include "Agave/Core/KeyCodes.h"
#include "Agave/Core/Delegate.h"
#include "Agave/Core/Log.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

// Temporary
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Agave {

    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
        , m_time(0.0f)
    {}

    ImGuiLayer::~ImGuiLayer()
    {}

    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        io.KeyMap[ImGuiKey_Tab] = (s32)Agave::KeyCode::Tab;
        io.KeyMap[ImGuiKey_LeftArrow] = (s32)Agave::KeyCode::LeftArrow;
        io.KeyMap[ImGuiKey_RightArrow] = (s32)Agave::KeyCode::RightArrow;
        io.KeyMap[ImGuiKey_UpArrow] = (s32)Agave::KeyCode::UpArrow;
        io.KeyMap[ImGuiKey_DownArrow] = (s32)Agave::KeyCode::DownArrow;
        io.KeyMap[ImGuiKey_PageUp] = (s32)Agave::KeyCode::PageUp;
        io.KeyMap[ImGuiKey_PageDown] = (s32)Agave::KeyCode::PageDown;
        io.KeyMap[ImGuiKey_Home] = (s32)Agave::KeyCode::Home;
        io.KeyMap[ImGuiKey_End] = (s32)Agave::KeyCode::End;
        io.KeyMap[ImGuiKey_Insert] = (s32)Agave::KeyCode::Insert;
        io.KeyMap[ImGuiKey_Delete] = (s32)Agave::KeyCode::Delete;
        io.KeyMap[ImGuiKey_Backspace] = (s32)Agave::KeyCode::Backspace;
        io.KeyMap[ImGuiKey_Space] = (s32)Agave::KeyCode::Space;
        io.KeyMap[ImGuiKey_Enter] = (s32)Agave::KeyCode::Enter;
        io.KeyMap[ImGuiKey_Escape] = (s32)Agave::KeyCode::Escape;
        io.KeyMap[ImGuiKey_A] = (s32)Agave::KeyCode::A;
        io.KeyMap[ImGuiKey_C] = (s32)Agave::KeyCode::C;
        io.KeyMap[ImGuiKey_V] = (s32)Agave::KeyCode::V;
        io.KeyMap[ImGuiKey_X] = (s32)Agave::KeyCode::X;
        io.KeyMap[ImGuiKey_Y] = (s32)Agave::KeyCode::Y;
        io.KeyMap[ImGuiKey_Z] = (s32)Agave::KeyCode::Z;

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {

    }

    void ImGuiLayer::OnUpdate()
    {
        Application& app = Application::Instance();
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

        float time = (float)glfwGetTime();
        io.DeltaTime = m_time > 0.0 ? (time - m_time) : (1.0f / 60.0f);
        m_time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<MouseButtonPressedEvent>(Gallant::Delegate<bool(MouseButtonPressedEvent&)>(this, &ImGuiLayer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleasedEvent>(Gallant::Delegate<bool(MouseButtonReleasedEvent&)>(this, &ImGuiLayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(Gallant::Delegate<bool(MouseMovedEvent&)>(this, &ImGuiLayer::OnMouseMovedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(Gallant::Delegate<bool(MouseScrolledEvent&)>(this, &ImGuiLayer::OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(Gallant::Delegate<bool(KeyPressedEvent&)>(this, &ImGuiLayer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(Gallant::Delegate<bool(KeyReleasedEvent&)>(this, &ImGuiLayer::OnKeyReleasedEvent));
        dispatcher.Dispatch<KeyTypedEvent>(Gallant::Delegate<bool(KeyTypedEvent&)>(this, &ImGuiLayer::OnKeyTypedEvent));
        dispatcher.Dispatch<WindowResizedEvent>(Gallant::Delegate<bool(WindowResizedEvent&)>(this, &ImGuiLayer::OnWindowResizedEvent));
    }
   
    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[(s32)e.GetMouseButton()] = true;

        return false;
    }

    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[(s32)e.GetMouseButton()] = false;

        return false;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(e.GetX(), e.GetY());

        return false;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheel += e.GetYOffset();
        io.MouseWheelH += e.GetXOffset();

        return false;
    }

    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[(s32)e.GetKeyCode()] = true;

        io.KeyCtrl = io.KeysDown[(s32)Agave::KeyCode::LeftControl] || io.KeysDown[(s32)Agave::KeyCode::RightControl];
        io.KeyShift = io.KeysDown[(s32)Agave::KeyCode::LeftShift] || io.KeysDown[(s32)Agave::KeyCode::RightShift];
        io.KeyAlt = io.KeysDown[(s32)Agave::KeyCode::LeftAlt] || io.KeysDown[(s32)Agave::KeyCode::RightAlt];
        io.KeySuper = io.KeysDown[(s32)Agave::KeyCode::LeftSuper] || io.KeysDown[(s32)Agave::KeyCode::RightSuper];

        return false;
    }

    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[(s32)e.GetKeyCode()] = false;

        return false;
    }

    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
    {
        u32 keyCode = (u32)e.GetKeyCode();
        ImGuiIO& io = ImGui::GetIO();
        if (keyCode > 0 && keyCode < 0x10000)
            io.AddInputCharacter((u16)keyCode);

        return false;
    }

    bool ImGuiLayer::OnWindowResizedEvent(WindowResizedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2((float)e.GetWidth(), (float)e.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, e.GetWidth(), e.GetHeight());

        return false;
    }
}