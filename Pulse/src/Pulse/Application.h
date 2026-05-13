#pragma once
#include "Core.h"
#include "Pulse/Events/Event.h"
#include "Pulse/Window.h"

namespace Pulse {

	class Pulse_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool isRunning = true;
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();

}



