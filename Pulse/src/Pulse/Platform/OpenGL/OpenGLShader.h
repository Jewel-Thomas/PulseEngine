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

		inline const uint32_t GetRendererID() const { return m_RendererID; }

		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& viewMatrix) override;
	};

}