#pragma once
#include "Pulse/Window.h"
#include <GLFW/glfw3.h>

namespace Pulse {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);

		~WindowsWindow() override;

		void OnUpdate() override;

		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;

		void SetVsync(bool enabled) override;
		bool IsVsync() const override;

	private:
		void Init(const WindowsWindow& props);
		void Shutdown();

	private:

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool Vsync;
		};

		WindowData m_Data;
	};

	// TODO: Implement WindowsWindow.cpp on 13/05/2026 !!!

}
