#pragma once
#include "Pulse/Core.h"
#include "Pulse/Layer.h"

namespace Pulse {

	class Pulse_API ImguiLayer : public Layer
	{
	private:
		float m_Time = 0.0f;

	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	};

}
