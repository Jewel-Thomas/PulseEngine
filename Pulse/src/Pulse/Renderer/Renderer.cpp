#include "plspch.h"
#include "Renderer.h"
#include "RenderCommand.h"


namespace Pulse {

	void Renderer::BeginScene()
	{

	}

	void Renderer::EndScene()
	{

	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
	{
		RenderCommand::DrawIndexed(vertexArray);
	}

}