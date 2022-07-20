#include "Agave/Render/RenderCommand.h"
#include "Platform/OpenGL/OpenGLRenderAPI.h"

namespace Agave {

    RenderAPI* RenderCommand::ms_pRenderAPI = new OpenGLRenderAPI();
}