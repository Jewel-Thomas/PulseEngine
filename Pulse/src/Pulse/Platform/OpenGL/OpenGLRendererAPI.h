#pragma once
#include "Pulse/Renderer/RendererAPI.h"

namespace Pulse {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Clear() override;
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};

}
