#include "plspch.h"
#include "Application.h"
#include "Pulse/Logger.h"

namespace Pulse {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (isRunning)
		{
			m_Window->OnUpdate();
		}
	}
}


