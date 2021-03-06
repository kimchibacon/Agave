///=============================================================================
/// EntryPoint.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Entry point for client application.
///=============================================================================

#ifndef AGAVE_ENTRY_POINT_H
#define AGAVE_ENTRY_POINT_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include "Agave/Core/Application.h"
#include "Agave/Core/Log.h"

#ifdef AGAVE_PLATFORM_WINDOWS

// Defined by client
extern Agave::Application* Agave::CreateApplication();

///=============================================================================
///=============================================================================
int main(int argc, char** argv)
{
    Agave::Log::Init();
    AGAVE_CORE_ERROR("Initialized CORE logger");
    int a = 5;
    AGAVE_INFO("Initialized CLIENT logger, Var={0}", a);

    auto pApp = Agave::CreateApplication();
    pApp->Run();
    delete pApp;

    return 0;
}

#endif // #ifdef AGAVE_PLATFORM_WINDOWS

#endif // #ifndef AGAVE_ENTRY_POINT_H