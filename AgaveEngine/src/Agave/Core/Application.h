#ifndef AGAVE_APPLICATION_H
#define AGAVE_APPLICATION_H

#include "Core.h"

namespace Agave {

    class AGAVE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();    
} 

#endif // #ifndef AGAVE_APPLICATION_H