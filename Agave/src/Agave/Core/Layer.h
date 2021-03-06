///=============================================================================
/// Layer.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Application layer
///=============================================================================

#ifndef AGAVE_LAYER_H
#define AGAVE_LAYER_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Core/Timestep.h"
#include "Agave/Events/Event.h"

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {};
        virtual void OnDetach() {};
        virtual void OnUpdate(Timestep dt) {};
        virtual void OnEvent(Event& event) {}
        virtual void OnImGuiRender() {};

        const std::string& GetName() const { return m_debugName; }

    protected:
        std::string m_debugName;
    };
}

#endif // #ifndef AGAVE_LAYER_H