#include "plspch.h"
#include <Pulse.h>
#include <imgui.h>
#include "Pulse/EntryPoint.h"

#include "RenderLayer.h"

class Sandbox : public Pulse::Application
{
public:

	Sandbox()
	{
		PushLayer(new RenderLayer());
	}

	~Sandbox()
	{

	}
};

Pulse::Application* Pulse::CreateApplication()
{
	return new Sandbox();
}



