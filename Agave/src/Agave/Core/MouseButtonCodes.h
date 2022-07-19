///=============================================================================
/// MouseButtonCodes.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Agave mouse button codes
///=============================================================================

#ifndef AGAVE_MOUSE_BUTTON_CODES_H
#define AGAVE_MOUSE_BUTTON_CODES_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"

namespace Agave {
    enum class MouseButtonCode
    {
        Button1 = 0,
        Button2,
        Button3,
        Button4,
        Button5,
        Button6,
        Button7,
        Button8,
        ButtonLast = Button8,
        ButtonLeft = Button1,
        ButtonRight = Button2,
        ButtonMiddle = Button3
    };
}
#endif // #ifndef AGAVE_MOUSE_BUTTON_CODES_H