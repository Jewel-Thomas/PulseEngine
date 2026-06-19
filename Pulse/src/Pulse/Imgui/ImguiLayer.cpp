#include "plspch.h"
#include "ImguiLayer.h"
#include "Pulse/Platform/OpenGL/ImguiOpenGLRenderer.h"
#include "Pulse/Platform/ImguiGLFW/imgui_impl_glfw.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "Pulse/Application.h"

namespace Pulse {

	static ImGuiKey GetImGuiKeyFromPulseKey(int keycode);

	ImguiLayer::ImguiLayer()
		: Layer("ImguiLayer")
	{
	}

	ImguiLayer::~ImguiLayer()
	{
	}

	void ImguiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		GLFWwindow* window = static_cast<GLFWwindow*>(
			Application::Get().GetWindow().GetNativeWindow()
		);

		ImGui_ImplGlfw_InitForOpenGL(window, false);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImguiLayer::OnDetach()
	{

	}

	void ImguiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) :  (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		if(show)
			ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImguiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<MouseButtonPressedEvent>(PLS_BIND_EVENT_FN(ImguiLayer::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(PLS_BIND_EVENT_FN(ImguiLayer::OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(PLS_BIND_EVENT_FN(ImguiLayer::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolledEvent>(PLS_BIND_EVENT_FN(ImguiLayer::OnMouseScrolled));
		dispatcher.Dispatch<KeyPressedEvent>(PLS_BIND_EVENT_FN(ImguiLayer::OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(PLS_BIND_EVENT_FN(ImguiLayer::OnKeyReleased));
		dispatcher.Dispatch<WindowResizeEvent>(PLS_BIND_EVENT_FN(ImguiLayer::OnWindowResize));
	}

	
	/* Mouse Events */
	bool ImguiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseButtonEvent(e.GetMouseButton(), true);
		return false;
	}

	bool ImguiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseButtonEvent(e.GetMouseButton(), false);
		return false;
	}

	bool ImguiLayer::OnMouseMoved(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.AddMousePosEvent(e.GetX(), e.GetY());
		return false;
	}

	bool ImguiLayer::OnMouseScrolled(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseWheelEvent(e.GetOffsetX(), e.GetOffsetY());
		return false;
	}

	/* Key Events */
	bool ImguiLayer::OnKeyPressed(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		ImGuiKey imKey = GetImGuiKeyFromPulseKey(e.GetKeyCode());

		if (imKey != ImGuiKey_None)
			io.AddKeyEvent(imKey, true);

		return false;
	}

	bool ImguiLayer::OnKeyReleased(KeyReleasedEvent& e)	
	{
		ImGuiIO& io = ImGui::GetIO();
		ImGuiKey imKey = GetImGuiKeyFromPulseKey(e.GetKeyCode());

		if (imKey != ImGuiKey_None)
			io.AddKeyEvent(imKey, false);

		return false;
	}

	/* Application Events */
	bool ImguiLayer::OnWindowResize(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)e.GetWidth(), (float)e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		return false;
	}

	static ImGuiKey GetImGuiKeyFromPulseKey(int keycode)
	{
		switch (keycode)
		{
			case GLFW_KEY_TAB: return ImGuiKey_Tab;
			case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
			case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
			case GLFW_KEY_UP: return ImGuiKey_UpArrow;
			case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;
			case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
			case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
			case GLFW_KEY_HOME: return ImGuiKey_Home;
			case GLFW_KEY_END: return ImGuiKey_End;
			case GLFW_KEY_INSERT: return ImGuiKey_Insert;
			case GLFW_KEY_DELETE: return ImGuiKey_Delete;
			case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
			case GLFW_KEY_SPACE: return ImGuiKey_Space;
			case GLFW_KEY_ENTER: return ImGuiKey_Enter;
			case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;
			case GLFW_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
			case GLFW_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
			case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
			case GLFW_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
			case GLFW_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
			case GLFW_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
			default: return ImGuiKey_None;
		}
	}

}