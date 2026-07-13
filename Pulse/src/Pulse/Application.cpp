#include "plspch.h"
#include "Application.h"
#include "Pulse/Logger.h"
#include "glad/glad.h"
#include "Input.h"

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
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f
		};

		// Vertex Array
		m_VertexArray.reset(VertexArray::Create());

		// Vertex Buffer
		m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		BufferLayout layout = {
			{ "a_Position", PLSType::Float3, false},
			{ "a_Color", PLSType::Float4 }
		};

		int index = 0;
		for (auto& element : layout)
		{
			m_VertexArray->SetVertexAttribPointer(index, 
											      element.GetComponentCount(), 
												  element.Type, 
												  element.Normalized, 
											      layout.GetStride(), 
												  (const void*)element.Offset);
			index++;
		}


		// Index Buffer
		unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };

		m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(indices[0])));

		// Custom Shader
		m_Shader.reset(Shader::Create(ShaderSrc::VertexSrc, ShaderSrc::FragmentSrc));
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
			glClearColor(0.1, 0.1, 0.1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			m_VertexArray->Bind();
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr); // nullptr implicitly gets converted to 0th byte

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


