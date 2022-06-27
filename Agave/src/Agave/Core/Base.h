///=============================================================================
/// Base.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Defines for Agave
///=============================================================================

#ifndef AGAVE_BASE_H
#define AGAVE_BASE_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/AgaveTypes.h"

///=============================================================================
/// Defs
///=============================================================================
#ifdef AGAVE_PLATFORM_WINDOWS
    // Export DLL if this is Agave, otherwise import (client application)
    #ifdef AGAVE_BUILD_DLL
        #define AGAVE_API __declspec(dllexport)
    #else
        #define AGAVE_API __declspec(dllimport)
    #endif
#else
    #error Agave only supports Windows!
#endif

#define BIT(x) (1 << x)

#endif // #define AGAVE_BASE_H