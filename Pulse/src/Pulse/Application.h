#pragma once
#include "Core.h"

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



