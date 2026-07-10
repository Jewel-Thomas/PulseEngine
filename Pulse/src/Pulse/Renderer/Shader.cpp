#include "plspch.h"
#include "Shader.h"
#include "Renderer.h"
#include "Pulse/Platform/OpenGL/OpenGLShader.h"


namespace Pulse {

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:
				PLS_CORE_ASSERT(false, "Renderer API 'None' is not supported yet"); return nullptr;
			case RendererAPI::OpenGL:
				return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		PLS_CORE_ASSERT(false, "This Renderer API is not currently supported, try other Renderer APIs");
		return nullptr;
	}

}