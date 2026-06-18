#include "plspch.h"
#include "ImguiLayer.h"
#include "Pulse/Platform/OpenGL/ImguiOpenGLRenderer.h"
#include "Pulse/Platform/ImguiGLFW/imgui_impl_glfw.h"
#include <GLFW/glfw3.h>
#include "Pulse/Application.h"
#include "Pulse/Events/MouseEvent.h"

namespace Pulse {

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
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) :  (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImguiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);

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
	}

}