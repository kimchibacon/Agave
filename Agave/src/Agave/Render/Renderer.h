#ifndef AGAVE_RENDERER_H
#define AGAVE_RENDERER_H

namespace Agave {

    enum class RenderAPI
    {
        None = 0, OpenGL = 1
    };

    class Renderer
    {
    public:
        static RenderAPI GetAPI() { return ms_renderAPI; }

    private:
        static RenderAPI ms_renderAPI;
    };
}

#endif // #ifndef AGAVE_RENDERER_H