#pragma once
#include <string>
#include "Events/Event.h"
#include "Core.h"

namespace Pulse {

	class Pulse_API Layer
	{
	protected:
		std::string m_DebugName;

	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() const { return  m_DebugName; }
	};

}
