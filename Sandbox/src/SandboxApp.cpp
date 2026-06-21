#include "plspch.h"
#include <Pulse.h>

class ExampleLayer : public Pulse::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		if (Pulse::Input::IsKeyPressed(PLS_KEY_SPACE))
		{
			PLS_INFO("Space bar was pressed!");
		}
	}

	void OnEvent(Pulse::Event& event) override
	{

	}
};

class Sandbox : public Pulse::Application
{
public:

	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Pulse::ImguiLayer);
	}

	~Sandbox()
	{

	}
};

Pulse::Application* Pulse::CreateApplication()
{
	return new Sandbox();
}



