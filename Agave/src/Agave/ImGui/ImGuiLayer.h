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

namespace Agave {
    class AGAVE_API ImGuiLayer : public Layer
    {
    public:
        ///=====================================================================
        /// Ctor/Dtor
        ///=====================================================================
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

        ///=====================================================================
        /// Private Members
        ///=====================================================================
    private:
        float m_time;
    };
}

#endif // #ifndef AGAVE_IMGUI_LAYER_H