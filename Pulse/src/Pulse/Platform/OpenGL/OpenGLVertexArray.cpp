#include "plspch.h"
#include "OpenGLVertexArray.h"
#include <glad/glad.h>


namespace Pulse {

	Pulse::OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
		glBindVertexArray(m_RendererID);
	}

	Pulse::OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void Pulse::OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void Pulse::OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

}

