#ifndef AGAVE_ENTRY_POINT_H
#define AGAVE_ENTRY_POINT_H

#include "Agave/Core/Application.h"
#include "Agave/Logging/Log.h"

#ifdef AGAVE_PLATFORM_WINDOWS

extern Agave::Application* Agave::CreateApplication();

int main(int argc, char** argv)
{
    Agave::Log::Init();
    AgCoreLogError("Initialized CORE logger");
    int a = 5;
    AgLogInfo("Initialized CLIENT logger, Var={0}", a);

    auto pApp = Agave::CreateApplication();
    pApp->Run();
    delete pApp;
}

#endif // #ifdef AGAVE_PLATFORM_WINDOWS

#endif // #ifndef AGAVE_ENTRY_POINT_H