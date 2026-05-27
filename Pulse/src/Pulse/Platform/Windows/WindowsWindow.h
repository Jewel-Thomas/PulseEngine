#pragma once
#include "Pulse/Window.h"
#include <GLFW/glfw3.h>

namespace Pulse {

	class Pulse_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);

		~WindowsWindow() override;

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.eventCallback = callback; }

		void SetVsync(bool enabled) override;
		bool IsVsync() const override;

	private:
		void Init(const WindowProps& props);
		void Shutdown();

	private:

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool Vsync;

			EventCallbackFn eventCallback;
		};

		WindowData m_Data;
	};

}
