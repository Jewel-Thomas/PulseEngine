#pragma once
#include <cstdint>
#include <string>

namespace Pulse {

	enum class PLSType
	{
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool
	};

	class Shader
	{		
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}