///=============================================================================
/// ImGuiLayer.h
/// Agave/ImGui
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
#include "Agave/Core/Base.h"
#include "Agave/Core/Layer.h"
#include "Agave/Events/MouseEvent.h"
#include "Agave/Events/KeyEvent.h"
#include "Agave/Events/ApplicationEvent.h"

namespace Agave {
    class ImGuiLayer : public Layer
    {
    public:
        ///=====================================================================
        /// Ctor/Dtor
        ///=====================================================================
        ImGuiLayer();
        ~ImGuiLayer();

    public:
        ///=====================================================================
        /// Public Methods
        ///=====================================================================
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    };
}

#endif // #ifndef AGAVE_IMGUI_LAYER_H