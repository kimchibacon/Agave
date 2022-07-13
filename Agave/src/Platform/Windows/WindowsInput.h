///=============================================================================
/// WindowsInput.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Windows implementation of Input manager
///=============================================================================

#ifndef AGAVE_WINDOWS_INPUT_H
#define AGAVE_WINDOWS_INPUT_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Input.h"

namespace Agave {

    class WindowsInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(s32 keycode) override;
        virtual bool IsMouseButtonPressedImpl(s32 button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };
}

#endif // #ifndef AGAVE_WINDOWS_INPUT_H