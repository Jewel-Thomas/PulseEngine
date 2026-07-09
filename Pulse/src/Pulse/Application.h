#pragma once
#include "Core.h"
#include "Pulse/Events/Event.h"
#include "Pulse/Events/ApplicationEvent.h"
#include "Pulse/Window.h"
#include "Pulse/Layer.h"
#include "Pulse/LayerStack.h"
#include "Pulse/Imgui/ImguiLayer.h"

#include "Pulse/Renderer/Shader.h"

namespace Pulse {

	class Application
	{
	private:
		static Application* s_Instance;
		std::unique_ptr<Window> m_Window;
		ImguiLayer* m_ImguiLayer;
		bool m_IsRunning = true;
		LayerStack m_LayerStack;
		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;

	public:
		Application();
		virtual ~Application();
		void OnEvent(Event& event);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
		void Run();
		bool OnWindowClose(WindowCloseEvent& event);
	};

	Application* CreateApplication();

}



