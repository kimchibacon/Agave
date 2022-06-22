#ifndef AGAVE_ENTRY_POINT_H
#define AGAVE_ENTRY_POINT_H

#include "Application.h"

#ifdef AGAVE_PLATFORM_WINDOWS

extern Agave::Application* Agave::CreateApplication();

int main(int argc, char** argv)
{
    auto pApp = Agave::CreateApplication();
    pApp->Run();
    delete pApp;
}

#endif // #ifdef AGAVE_PLATFORM_WINDOWS

#endif // #ifndef AGAVE_ENTRY_POINT_H