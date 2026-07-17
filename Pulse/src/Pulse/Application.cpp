#include "plspch.h"
#include "Application.h"
#include "Pulse/Logger.h"
#include "Input.h"
#include "Pulse/Renderer/Renderer.h"
#include "Pulse/Renderer/RenderCommand.h"

namespace Pulse {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		PLS_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImguiLayer = new ImguiLayer();
		PushOverlay(m_ImguiLayer);

		float vertices[4 * 7] = {
			-0.75f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.75f,  0.75f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.75f,  0.75f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.75f, -0.75f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f
		};

		// Vertex Array
		m_VertexArray.reset(VertexArray::Create());

		// Vertex Buffer
		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));


		BufferLayout layout = {
			{ "a_Position", PLSType::Float3, false},
			{ "a_Color", PLSType::Float4 }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		// Index Buffer
		unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<IndexBuffer> indexBuffer;
		indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(indices[0])));

		m_VertexArray->SetIndexBuffer(indexBuffer);

		// Custom Shader
		m_Shader.reset(Shader::Create(ShaderSrc::SquareVertexSrc, ShaderSrc::SquareFragmentSrc));




		// Second Shape

		float triangleVertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		// Vertex Array
		m_TriangleVertexArray.reset(VertexArray::Create());

		// Vertex Buffer
		std::shared_ptr<VertexBuffer> triangleVertexBuffer;
		triangleVertexBuffer.reset(VertexBuffer::Create(triangleVertices, sizeof(triangleVertices)));


		BufferLayout triangleBufferLayout = {
			{ "a_Position", PLSType::Float3, false}
		};

		triangleVertexBuffer->SetLayout(triangleBufferLayout);
		m_TriangleVertexArray->AddVertexBuffer(triangleVertexBuffer);

		// Index Buffer
		unsigned int triangleIndices[3] = { 0, 1, 2 };
		std::shared_ptr<IndexBuffer> triangleIndexBuffer;
		triangleIndexBuffer.reset(IndexBuffer::Create(triangleIndices, sizeof(triangleIndices) / sizeof(triangleIndices[0])));

		m_TriangleVertexArray->SetIndexBuffer(triangleIndexBuffer);

		// Custom Shader
		m_TriangleShader.reset(Shader::Create(ShaderSrc::TriangleVertexSrc, ShaderSrc::TriangleFragmentSrc));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(event);
			if (event.m_Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
			RenderCommand::Clear();

			Renderer::BeginScene();

			m_Shader->Bind();
			Renderer::Submit(m_VertexArray);

			m_TriangleShader->Bind();
			Renderer::Submit(m_TriangleVertexArray);

			Renderer::EndScene();

			for (auto layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_ImguiLayer->OnBegin();
			for (auto layer : m_LayerStack)
			{
				layer->OnImguiRender();
			}
			m_ImguiLayer->OnEnd();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_IsRunning = false;
		return true;
	}
}


