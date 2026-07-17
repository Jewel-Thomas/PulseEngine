#include "plspch.h"
#include "RenderCommand.h"
#include "Pulse/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Pulse {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}