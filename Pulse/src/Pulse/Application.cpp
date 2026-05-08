#include "Application.h"
#include "Pulse/Logger.h"
#include "Pulse/Events/ApplicationEvent.h"
#include "Pulse/Events/Event.h"

namespace Pulse {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		PLS_CORE_TRACE(e);

		while (true);
	}
}


