#include "plspch.h"
#include "ImguiLayer.h"
#include "Pulse/Platform/OpenGL/ImguiOpenGLRenderer.h"
#include "Pulse/Platform/ImguiGLFW/imgui_impl_glfw.h"
#include <GLFW/glfw3.h>
#include "Pulse/Application.h"
#include "Pulse/Events/MouseEvent.h"
#include "Pulse/Events/KeyEvent.h"
#include "Pulse/Events/ApplicationEvent.h"

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

		// Mouse Events
		dispatcher.Dispatch<MouseButtonPressedEvent>(
			[](MouseButtonPressedEvent& e)
			{
				ImGui::GetIO().AddMouseButtonEvent(e.GetMouseButton(), true);
				return false;
			});

		dispatcher.Dispatch<MouseButtonReleasedEvent>(
			[](MouseButtonReleasedEvent& e)
			{
				ImGui::GetIO().AddMouseButtonEvent(e.GetMouseButton(), false);
				return false;
			});

		dispatcher.Dispatch<MouseMovedEvent>(
			[](MouseMovedEvent& e)
			{
				ImGui::GetIO().AddMousePosEvent(e.GetX(), e.GetY());
				return false;
			});

		dispatcher.Dispatch<MouseScrolledEvent>(
			[](MouseScrolledEvent& e)
			{
				ImGui::GetIO().AddMouseWheelEvent(e.GetOffsetX(), e.GetOffsetY());
				return false;
			});

		// Key Events
		dispatcher.Dispatch<KeyPressedEvent>(
			[](KeyPressedEvent& e)
			{
				ImGuiKey imKey = GetImGuiKeyFromPulseKey(e.GetKeyCode());
				if (imKey != ImGuiKey_None)
					ImGui::GetIO().AddKeyEvent(imKey, true);

				return false;
			});

		dispatcher.Dispatch<KeyReleasedEvent>(
			[](KeyReleasedEvent& e)
			{
				ImGuiKey imKey = GetImGuiKeyFromPulseKey(e.GetKeyCode());
				if (imKey != ImGuiKey_None)
					ImGui::GetIO().AddKeyEvent(imKey, false);

				return false;
			});
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
			default: return ImGuiKey_None;
		}
	}

}