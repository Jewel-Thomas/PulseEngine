#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include "Shader.h"


namespace Pulse {

	struct BufferElement
	{
		std::string Name;
		PLSType Type;
		bool Normalized;
		uint32_t Size;
		uint32_t Offset;

		BufferElement(const std::string& name, PLSType type, bool normalized = false)
			: Name(name), Type(type), Normalized(normalized), Size(GetSizeFromPLSType(type)), Offset(0)
		{
		}

		uint32_t GetSizeFromPLSType(PLSType type)
		{
			switch (type)
			{
				case PLSType::Float: return 4;
				case PLSType::Float2: return 4 * 2;
				case PLSType::Float3: return 4 * 3;
				case PLSType::Float4: return 4 * 4;
				case PLSType::Mat3: return 4 * 3 * 3;
				case PLSType::Mat4: return 4 * 4 * 4;
				case PLSType::Int: return 4;
				case PLSType::Int2: return 4 * 2;
				case PLSType::Int3: return 4 * 3;
				case PLSType::Int4: return 4 * 4;
				case PLSType::Bool: return 1;
			}

			PLS_CORE_ASSERT(false, "Unknown PLSType!");
			return 0;
		}

		uint32_t GetComponentCount()
		{
			switch (Type)
			{
				case PLSType::Float: return 1;
				case PLSType::Float2: return 2;
				case PLSType::Float3: return 3;
				case PLSType::Float4: return 4;
				case PLSType::Mat3: return 3 * 3;
				case PLSType::Mat4: return 4 * 4;
				case PLSType::Int: return 1;
				case PLSType::Int2: return 2;
				case PLSType::Int3: return 3;
				case PLSType::Int4: return 4;
				case PLSType::Bool: return 1;
			}

			PLS_CORE_ASSERT(false, "Unknown PLSType!");
			return 0;
		}
	};

	class BufferLayout
	{
	private:
		std::vector<BufferElement> m_Layout;
		uint32_t m_Stride = 0;

	public:
		BufferLayout(std::initializer_list<BufferElement> layout)
			: m_Layout(layout)
		{
			CalculateOffsetAndStride(m_Layout);
		}

		void CalculateOffsetAndStride(std::vector<BufferElement>& layout)
		{
			uint32_t offset = 0;

			for (auto& element : layout)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}

		inline uint32_t GetStride() const { return m_Stride; }

		inline std::vector<BufferElement>::iterator begin() { return m_Layout.begin(); }
		inline std::vector<BufferElement>::iterator end() { return m_Layout.end(); }

	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static VertexBuffer* Create(float* vertices, uint32_t size);
	};


	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual uint32_t GetCount() const = 0;

		static IndexBuffer* Create(unsigned int* indices, uint32_t count);
	};

}