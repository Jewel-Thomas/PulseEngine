#include "plspch.h"
#include "WindowsWindow.h"

namespace Pulse {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		PLS_CORE_INFO("Creating Window {0} engine ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();

			if (!success)
			{
				PLS_CORE_ASSERT(success, "GLFW could not Initialize!");
				return;
			}

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVsync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVsync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
		m_Data.Vsync = enabled;
	}

	bool WindowsWindow::IsVsync() const
	{
		return m_Data.Vsync;
	}



}

