#pragma once
#include "Pulse/Core.h"
#include "Pulse/Layer.h"

namespace Pulse {

	class Pulse_API ImguiLayer : public Layer
	{
	private:

	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	};

}
