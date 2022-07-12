///=============================================================================
/// LayerStack.cpp
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Collection for application Layers
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/LayerStack.h"

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_layers)
        {
            layer->OnDetach();
            delete layer;
        }
    }

    ///=========================================================================
    ///=========================================================================
    void LayerStack::PushLayer(Layer* layer)
    {
        m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
        m_layerInsertIndex++;

        layer->OnAttach();
    }

    ///=========================================================================
    ///=========================================================================
    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_layers.emplace_back(overlay);
    }

    ///=========================================================================
    ///=========================================================================
    void LayerStack::PopLayer(Layer* layer)
    {
        auto it = std::find(m_layers.begin(), m_layers.begin() + m_layerInsertIndex, layer);
        if (it != m_layers.begin() + m_layerInsertIndex)
        {
            layer->OnDetach();
            m_layers.erase(it);
            m_layerInsertIndex--;
        }
    }

    ///=========================================================================
    ///=========================================================================
    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto it = std::find(m_layers.begin() + m_layerInsertIndex, m_layers.end(), overlay);
        if (it != m_layers.end())
        {
            overlay->OnDetach();
            m_layers.erase(it);
        }
    }

    ///=========================================================================
    ///=========================================================================
    void LayerStack::OnEvent(Event& event)
    {
        for(auto it = m_layers.rbegin(); it != m_layers.rend();)
        {
            (*it)->OnEvent(event);
            if(event.m_handled)
            {
                break;
            }
            ++it;
        }
    }

    ///=========================================================================
    ///=========================================================================
    void LayerStack::OnUpdate()
    {
        for(Layer* layer : m_layers)
        {
            layer->OnUpdate();
        }
    }
}