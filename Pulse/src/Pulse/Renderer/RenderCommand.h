#pragma once
#include "VertexArray.h"
#include "RendererAPI.h"
#include <memory>


namespace Pulse {

	class RenderCommand
	{
	private:
		static RendererAPI* s_RendererAPI;

	public:
		static inline void Clear() { s_RendererAPI->Clear(); }
		static inline void SetClearColor(const glm::vec4& color) { s_RendererAPI->SetClearColor(color); }

		static inline void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) { s_RendererAPI->DrawIndexed(vertexArray); }
	};

}