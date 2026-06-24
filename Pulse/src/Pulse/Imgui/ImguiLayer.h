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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImguiRender() override;

		void OnBegin();
		void OnEnd();
	};

}
