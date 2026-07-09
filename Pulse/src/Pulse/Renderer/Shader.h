#pragma once
#include <cstdint>
#include <string>

namespace Pulse {

	class Shader
	{
	private:
		uint32_t m_RendererID;
		
	public:
		Shader(std::string vertexSrc, std::string fragmentSrc);
		~Shader();

		void Bind();
		void UnBind();
	};

}