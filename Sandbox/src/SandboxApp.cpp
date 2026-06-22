#include "plspch.h"
#include <Pulse.h>


class ExampleLayer : public Pulse::Layer
{
public:
	ExampleLayer()
		: Layer("Example") 
	{
	}

	void OnUpdate() override
	{
		if (Pulse::Input::IsKeyPressed(PLS_KEY_SPACE))
		{
			PLS_INFO("Space bar was pressed!");
		}
	}

	void OnEvent(Pulse::Event& event) override
	{
		if (event.GetEventType() == Pulse::EventType::MouseButtonPressed)
		{
			Pulse::MouseButtonPressedEvent& mouseEvent = static_cast<Pulse::MouseButtonPressedEvent&>(event);
			if (mouseEvent.GetMouseButton() == PLS_MOUSE_BUTTON_1)
				PLS_INFO("Left Mouse Button was clicked!");
		}
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



