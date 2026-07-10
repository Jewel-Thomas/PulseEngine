#pragma once
#include "Pulse/Renderer/Shader.h"

namespace Pulse {

	class OpenGLShader : public Shader
	{
	private:
		uint32_t m_RendererID;

	public:
		OpenGLShader(std::string vertexSrc, std::string fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;
	};

}