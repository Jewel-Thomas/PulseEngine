#include "plspch.h"
#include "Buffer.h"
#include "Renderer.h"
#include "Pulse/Platform/OpenGL/OpenGLBuffer.h"

namespace Pulse {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:
				PLS_CORE_ASSERT(false, "Renderer API 'None' is not supported yet"); return nullptr;
			case RendererAPI::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
		}

		PLS_CORE_ASSERT(false, "This Renderer API is not currently supported, try other Renderer APIs");
		return nullptr;
	}

}