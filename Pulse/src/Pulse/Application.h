#pragma once
#include "Core.h"
#include "Pulse/Events/Event.h"
#include "Pulse/Window.h"

namespace Pulse {

	class Pulse_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
	public:
		Application();
		virtual ~Application();
		void OnEvent(Event& event);
		void Run();
	};

	Application* CreateApplication();

}



