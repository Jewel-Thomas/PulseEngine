#pragma once
#include <cstdint>
#include "Pulse/Renderer/VertexArray.h"


namespace Pulse {

	class OpenGLVertexArray : public VertexArray
	{
	private:
		uint32_t m_RendererID;

	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;
	};

}
