///=============================================================================
/// Input.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Abstract Input manager
///=============================================================================

#ifndef AGAVE_INPUT_H
#define AGAVE_INPUT_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Core/KeyCodes.h"
#include "Agave/Core/MouseButtonCodes.h"
#include <utility>
#include <unordered_map>

namespace Agave {

    class Input
    {
    public:
        ///=============================================================================
        /// Public Methods
        ///=============================================================================
        static bool IsKeyPressed(Agave::KeyCode keycode) { return ms_pInstance->IsKeyPressedImpl(keycode); }
        static bool IsMouseButtonPressed(Agave::MouseButtonCode button) { return ms_pInstance->IsMouseButtonPressedImpl(button); }
        static std::pair<float, float> GetMousePosition() { return ms_pInstance->GetMousePositionImpl(); }
        static float GetMouseX() { return ms_pInstance->GetMouseXImpl(); }
        static float GetMouseY() { return ms_pInstance->GetMouseYImpl(); }        

    protected:
        ///=============================================================================
        /// Implementation Method Declarations
        ///=============================================================================
        virtual bool IsKeyPressedImpl(Agave::KeyCode keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(Agave::MouseButtonCode button) = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;

    private:
        ///=============================================================================
        /// Singleton Instance
        ///=============================================================================
        static Input* ms_pInstance;
    };
}

#endif // #ifndef AGAVE_INPUT_H