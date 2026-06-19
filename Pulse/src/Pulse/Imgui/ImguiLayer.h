#pragma once
#include "Pulse/Core.h"
#include "Pulse/Layer.h"
#include "Pulse/Events/MouseEvent.h"
#include "Pulse/Events/KeyEvent.h"
#include "Pulse/Events/ApplicationEvent.h"

namespace Pulse {

	class Pulse_API ImguiLayer : public Layer
	{
	private:
		float m_Time = 0.0f;

	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool OnMouseMoved(MouseMovedEvent& e);
		bool OnMouseScrolled(MouseScrolledEvent& e);

		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnKeyReleased(KeyReleasedEvent& e);
		bool OnKeyTyped(KeyTypedEvent& e);

		bool OnWindowResize(WindowResizeEvent& e);
	};

}
