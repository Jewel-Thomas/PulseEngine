#pragma once
#include "Pulse/Core.h"
#include "imgui.h"

namespace Pulse {

	class Pulse_API PulseImGui
	{
	public:
		static ImGuiContext* GetImGuiContextFromPulse();
	};

}
