#include "plspch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Pulse/Platform/OpenGL/OpenGLVertexArray.h"


namespace Pulse {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:
				PLS_CORE_ASSERT(false, "Renderer API 'None' is not supported yet"); return nullptr;
			case RendererAPI::OpenGL:
				return new OpenGLVertexArray();
		}

		PLS_CORE_ASSERT(false, "This Renderer API is not currently supported, try other Renderer APIs");
		return nullptr;
	}

}