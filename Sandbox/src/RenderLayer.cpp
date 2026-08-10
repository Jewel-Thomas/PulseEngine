#include "plspch.h"
#include "RenderLayer.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

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
	unsigned int indices[36] = { 
		0, 1, 2, 2, 3, 0, 
		4, 5, 6, 6, 7, 4, 
		6, 2, 3, 3, 7, 6, 
		1, 5, 4, 4, 0, 1, 
		1, 5, 6, 6, 2, 1, 
		0, 3, 7, 7, 4, 0 
	};

	std::shared_ptr<Pulse::IndexBuffer> indexBuffer;
	indexBuffer.reset(Pulse::IndexBuffer::Create(indices, sizeof(indices) / sizeof(indices[0])));

	m_VertexArray->SetIndexBuffer(indexBuffer);

	PLS_INFO("Constructed Camera View Matrix : {0} ", glm::to_string(m_Camera.GetViewMatrix()));
	PLS_INFO("Constructed Projection Matrix : {0} ", glm::to_string(m_Camera.GetProjectionMatrix()));

	// Custom Shader
	m_Shader.reset(Pulse::Shader::Create(Pulse::ShaderSrc::SquareVertexSrc, Pulse::ShaderSrc::SquareFragmentSrc));
}

void RenderLayer::OnUpdate()
{
	Pulse::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	Pulse::RenderCommand::Clear();

	Pulse::Renderer::BeginScene();

	m_Camera.CameraMovement();

	m_Shader->Bind();
	m_Shader->UploadUniformMat4("u_View", m_Camera.GetViewMatrix());
	m_Shader->UploadUniformMat4("u_Proj", m_Camera.GetProjectionMatrix());

	Pulse::Renderer::Submit(m_VertexArray);

	Pulse::Renderer::EndScene();
}

void RenderLayer::OnEvent(Pulse::Event& event)
{
	if (event.GetEventType() == Pulse::EventType::MouseMoved)
	{
		Pulse::MouseMovedEvent& mouseMovedEvent = static_cast<Pulse::MouseMovedEvent&>(event);
		m_Camera.UpdateCameraFrontCallBack(mouseMovedEvent.GetX(), mouseMovedEvent.GetY());
	}
}

//void OnEvent(Pulse::Event& event) override
//{
//	if (event.GetEventType() == Pulse::EventType::MouseButtonPressed)
//	{
//		Pulse::MouseButtonPressedEvent& mouseEvent = static_cast<Pulse::MouseButtonPressedEvent&>(event);
//		if (mouseEvent.GetMouseButton() == PLS_MOUSE_BUTTON_1)
//			PLS_INFO("Left Mouse Button was clicked!");
//	}
//}
