///=============================================================================
/// Assert.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Assert macros
///=============================================================================

#ifndef AGAVE_ASSERT_H
#define AGAVE_ASSERT_H

#include "Agave/Core/Base.h"
#include "Agave/Core/Log.h"

#if AGAVE_ENABLE_ASSERTS
    #define AGAVE_ASSERT(x) { if(!(x)) { AGAVE_ERROR("Assertion Failed: {0}\nFile: {1}\nLine:{2}", #x, __FILE__, __LINE__); __debugbreak(); } }
    #define AGAVE_CORE_ASSERT(x) { if(!(x)) { AGAVE_CORE_ERROR("Assertion Failed: {0}\nFile: {1}\nLine:{2}", #x, __FILE__, __LINE__); __debugbreak(); } }
#else
    #define AGAVE_ASSERT(x)
    #define AGAVE_CORE_ASSERT(x)
#endif // #if AGAVE_ENABLE_ASSERTS

#endif // #ifndef AGAVE_ASSERT_H