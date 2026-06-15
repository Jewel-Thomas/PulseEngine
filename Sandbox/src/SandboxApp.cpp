#include "plspch.h"
#include <Pulse.h>

class ExampleLayer : public Pulse::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		PLS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Pulse::Event& event) override
	{
		PLS_TRACE("{0}", event);
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



