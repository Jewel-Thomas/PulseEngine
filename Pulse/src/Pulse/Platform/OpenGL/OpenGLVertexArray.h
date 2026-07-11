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
		virtual void SetVertexAttribPointer(uint32_t index, uint32_t count, PLSType type, bool normalized, uint32_t stride, const void* offset) override;
	};

}
