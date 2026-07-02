#pragma once
#include <string>
#include "Events/Event.h"
#include "Core.h"

namespace Pulse {

	class Layer
	{
	protected:
		std::string m_DebugName;

	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnImguiRender() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() const { return  m_DebugName; }
	};

}
