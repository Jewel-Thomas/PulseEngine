#include "plspch.h"
#include "RenderLayer.h"

RenderLayer::RenderLayer()
	: Layer("Render")
{	
}

void RenderLayer::OnAttach()
{
	float vertices[4 * 7] = {
	-0.75f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	-0.75f,  0.75f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	 0.75f,  0.75f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	 0.75f, -0.75f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f
	};

	// Vertex Array
	m_VertexArray.reset(Pulse::VertexArray::Create());

	// Vertex Buffer
	std::shared_ptr<Pulse::VertexBuffer> vertexBuffer;
	vertexBuffer.reset(Pulse::VertexBuffer::Create(vertices, sizeof(vertices)));


	Pulse::BufferLayout layout = {
		{ "a_Position", Pulse::PLSType::Float3, false},
		{ "a_Color", Pulse::PLSType::Float4 }
	};

	vertexBuffer->SetLayout(layout);
	m_VertexArray->AddVertexBuffer(vertexBuffer);

	// Index Buffer
	unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };
	std::shared_ptr<Pulse::IndexBuffer> indexBuffer;
	indexBuffer.reset(Pulse::IndexBuffer::Create(indices, sizeof(indices) / sizeof(indices[0])));

	m_VertexArray->SetIndexBuffer(indexBuffer);

	// Custom Shader
	m_Shader.reset(Pulse::Shader::Create(Pulse::ShaderSrc::SquareVertexSrc, Pulse::ShaderSrc::SquareFragmentSrc));

	// Second Shape

	float triangleVertices[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	// Vertex Array
	m_TriangleVertexArray.reset(Pulse::VertexArray::Create());

	// Vertex Buffer
	std::shared_ptr<Pulse::VertexBuffer> triangleVertexBuffer;
	triangleVertexBuffer.reset(Pulse::VertexBuffer::Create(triangleVertices, sizeof(triangleVertices)));


	Pulse::BufferLayout triangleBufferLayout = {
		{ "a_Position", Pulse::PLSType::Float3, false}
	};

	triangleVertexBuffer->SetLayout(triangleBufferLayout);
	m_TriangleVertexArray->AddVertexBuffer(triangleVertexBuffer);

	// Index Buffer
	unsigned int triangleIndices[3] = { 0, 1, 2 };
	std::shared_ptr<Pulse::IndexBuffer> triangleIndexBuffer;
	triangleIndexBuffer.reset(Pulse::IndexBuffer::Create(triangleIndices, sizeof(triangleIndices) / sizeof(triangleIndices[0])));

	m_TriangleVertexArray->SetIndexBuffer(triangleIndexBuffer);

	// Custom Shader
	m_TriangleShader.reset(Pulse::Shader::Create(Pulse::ShaderSrc::TriangleVertexSrc, Pulse::ShaderSrc::TriangleFragmentSrc));
}

void RenderLayer::OnUpdate()
{
	Pulse::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	Pulse::RenderCommand::Clear();

	Pulse::Renderer::BeginScene();

	m_Shader->Bind();
	Pulse::Renderer::Submit(m_VertexArray);

	m_TriangleShader->Bind();
	Pulse::Renderer::Submit(m_TriangleVertexArray);

	Pulse::Renderer::EndScene();
}

