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

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		PLS_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer Layout was not set!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		int index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				PLSTypeToGLType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);

			index++;
		}


		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}

