#pragma once
#include "Pulse/Renderer/Buffer.h"


namespace Pulse {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		uint32_t m_RendererID;

	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer() = default;

		virtual void Bind() const override;
		virtual void Unbind() const override;
	};

}
