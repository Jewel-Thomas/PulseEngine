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

	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;

	public:
		OpenGLIndexBuffer(unsigned int* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer() = default;

		inline virtual uint32_t GetCount() const override { return m_Count; }
		virtual void Bind() const override;
		virtual void Unbind() const override;
	};

}
