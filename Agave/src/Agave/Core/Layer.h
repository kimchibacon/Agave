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
#include "Agave/Events/Event.h"

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    class AGAVE_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {};
        virtual void OnDetach() {};
        virtual void OnUpdate() {};
        virtual void OnEvent(Event& event) {}

        const std::string& GetName() const { return m_debugName; }

    protected:
        std::string m_debugName;
    };
}

#endif // #ifndef AGAVE_LAYER_H