#ifndef AGAVE_CORE_H
#define AGAVE_CORE_H

#ifdef AGAVE_PLATFORM_WINDOWS
    #ifdef AGAVE_BUILD_DLL
        #define AGAVE_API __declspec(dllexport)
    #else
        #define AGAVE_API __declspec(dllimport)
    #endif
#else
    #error Agave only supports Windows!
#endif

#endif // #define AGAVE_CORE_H