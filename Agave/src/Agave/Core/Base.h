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

#endif // #define AGAVE_BASE_H