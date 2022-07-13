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

#include "Agave/Core/Base.h"
#include <utility>

namespace Agave {
    class AGAVE_API Input
    {
    public:
        static bool IsKeyPressed(s32 keycode) { return ms_pInstance->IsKeyPressedImpl(keycode); }
        static bool IsMouseButtonPressed(s32 button) { return ms_pInstance->IsMouseButtonPressedImpl(button); }
        static std::pair<float, float> GetMousePosition() { return ms_pInstance->GetMousePositionImpl(); }
        static float GetMouseX() { return ms_pInstance->GetMouseXImpl(); }
        static float GetMouseY() { return ms_pInstance->GetMouseYImpl(); }

    protected:
        virtual bool IsKeyPressedImpl(s32 keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(s32 button) = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;

    private:
        static Input* ms_pInstance;
    };
}

#endif // #ifndef AGAVE_INPUT_H