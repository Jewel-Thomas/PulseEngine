#pragma once
#include <vector>
#include "Core.h"
#include "Layer.h"

namespace Pulse {

	class Pulse_API LayerStack
	{
	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsert = 0;

	public:
		LayerStack();
		virtual ~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		inline std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		inline std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	};

}
