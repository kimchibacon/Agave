///=============================================================================
/// LayerStack.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Collection for application Layers
///=============================================================================

#ifndef AGAVE_LAYER_STACK_H
#define AGAVE_LAYER_STACK_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Core/Layer.h"
#include <vector>

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    class LayerStack
    {
    public:
        LayerStack() = default;
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);
        void OnEvent(Event& event);
        void OnUpdate();

        std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_layers.end(); }
        std::vector<Layer*>::reverse_iterator rbegin() { return m_layers.rbegin(); }
        std::vector<Layer*>::reverse_iterator rend() { return m_layers.rend(); }

        std::vector<Layer*>::const_iterator begin() const { return m_layers.begin(); }
        std::vector<Layer*>::const_iterator end() const { return m_layers.end(); }
        std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_layers.rbegin(); }
        std::vector<Layer*>::const_reverse_iterator rend() const { return m_layers.rend(); }

    private:
        std::vector<Layer*> m_layers;
        uint32_t m_layerInsertIndex = 0;
    };
}

#endif // #ifndef AGAVE_LAYER_STACK_H