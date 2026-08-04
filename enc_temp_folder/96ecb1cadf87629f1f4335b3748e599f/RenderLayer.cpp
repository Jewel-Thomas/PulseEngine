#include "plspch.h"
#include "RenderLayer.h"

RenderLayer::RenderLayer()
	: Layer("Render")
{	
}

void RenderLayer::OnAttach()
{
	float vertices[8 * 7] = {
	-0.75f, -0.75f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	-0.75f,  0.75f,  0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	 0.75f,  0.75f,  0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	 0.75f, -0.75f,  0.0f, 0.5f, 0.5f, 0.5f, 1.0f,
	-0.75f, -0.75f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
	-0.75f,  0.75f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
	 0.75f,  0.75f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
	 0.75f, -0.75f, -0.5f, 0.5f, 0.5f, 0.5f, 1.0f
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
	unsigned int indices[36] = { 0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4, 6, 2, 3, 3, 7, 6, 1, 5, 4, 4, 0, 1, 1, 5, 6, 6, 2, 1, 0, 3, 7, 7, 4, 0};
	std::shared_ptr<Pulse::IndexBuffer> indexBuffer;
	indexBuffer.reset(Pulse::IndexBuffer::Create(indices, sizeof(indices) / sizeof(indices[0])));

	m_VertexArray->SetIndexBuffer(indexBuffer);

	// Custom Shader
	m_Shader.reset(Pulse::Shader::Create(Pulse::ShaderSrc::SquareVertexSrc, Pulse::ShaderSrc::SquareFragmentSrc));
}

void RenderLayer::OnUpdate()
{
	Pulse::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	Pulse::RenderCommand::Clear();

	Pulse::Renderer::BeginScene();

	m_Shader->Bind();
	Pulse::Renderer::Submit(m_VertexArray);

	Pulse::Renderer::EndScene();
}

