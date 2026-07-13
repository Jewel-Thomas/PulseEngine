#include "plspch.h"
#include "OpenGLVertexArray.h"
#include <glad/glad.h>


namespace Pulse {

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
		glBindVertexArray(m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}


	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	static GLenum PLSTypeToGLType(PLSType type)
	{
		switch (type)
		{
			case PLSType::Float: return GL_FLOAT;
			case PLSType::Float2: return GL_FLOAT;
			case PLSType::Float3: return GL_FLOAT;
			case PLSType::Float4: return GL_FLOAT;
			case PLSType::Int:   return GL_INT;
			case PLSType::Int2:   return GL_INT;
			case PLSType::Int3:   return GL_INT;
			case PLSType::Int4:   return GL_INT;
			case PLSType::Bool:  return GL_BOOL;
		}

		PLS_CORE_ASSERT(false, "Unknown DataType!");
		return 0;
	}

	void OpenGLVertexArray::SetVertexAttribPointer(uint32_t index, uint32_t count, PLSType type, bool normalized, uint32_t stride, const void* offset)
	{
		GLenum glType = PLSTypeToGLType(type);
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, 
			count, 
			glType, 
			normalized, 
			stride,
			offset);
	}

}

