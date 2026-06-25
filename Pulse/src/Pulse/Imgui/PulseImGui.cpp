#include "plspch.h"
#include "PulseImGui.h"

namespace Pulse {

	ImGuiContext* PulseImGui::GetImGuiContextFromPulse()
	{
		return ImGui::GetCurrentContext();
	}

}