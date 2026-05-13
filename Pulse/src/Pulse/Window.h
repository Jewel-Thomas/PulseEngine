#pragma once
#include <string>
#include "Pulse/Core.h"

namespace Pulse {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(std::string title = "Pulse", 
					unsigned int width = 1280, 
					unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}

	};

	// TODO: Include the input handling as well
	class Pulse_API Window
	{
	public:

		virtual ~Window() {}
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void OnUpdate() = 0;

		virtual void SetVsync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}