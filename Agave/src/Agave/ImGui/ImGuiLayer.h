///=============================================================================
/// ImGuiLayer.h
/// Agave/ImGuiLayer
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Debug GUI layer
///=============================================================================

#ifndef AGAVE_IMGUI_LAYER_H
#define AGAVE_IMGUI_LAYER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Layer.h"
#include "Agave/Events/MouseEvent.h"
#include "Agave/Events/KeyEvent.h"
#include "Agave/Events/ApplicationEvent.h"

namespace Agave {
    class AGAVE_API ImGuiLayer : public Layer
    {
    public:
        ///=====================================================================
        /// Ctor/Dtor
        ///=====================================================================
        ImGuiLayer();
        ~ImGuiLayer();

        ///=====================================================================
        /// Public Methods
        ///=====================================================================
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

        ///=====================================================================
        /// Private Methods
        ///=====================================================================
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizedEvent(WindowResizedEvent& e);

        ///=====================================================================
        /// Private Members
        ///=====================================================================
    private:
        float m_time;
    };
}

#endif // #ifndef AGAVE_IMGUI_LAYER_H