#pragma once
#include "Core.h"
#include "Pulse/Events/Event.h"
#include "Pulse/Events/ApplicationEvent.h"
#include "Pulse/Window.h"
#include "Pulse/Layer.h"
#include "Pulse/LayerStack.h"

namespace Pulse {

	class Pulse_API Application
	{
	private:
		static Application* s_Instance;
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
		LayerStack m_LayerStack;

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



