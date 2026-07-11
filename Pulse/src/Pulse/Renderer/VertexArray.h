#pragma once


namespace Pulse {

	enum class PLSType
	{
		Float,
		Int,
		Bool
	};

	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetVertexAttribPointer(uint32_t index, uint32_t count, PLSType type, bool normalized, uint32_t stride, const void* offset) = 0;

		static VertexArray* Create();
	};


}
