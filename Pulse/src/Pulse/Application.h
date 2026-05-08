#pragma once
#include "Core.h"
#include "Pulse/Events/Event.h"

namespace Pulse {

	class Pulse_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();

}



