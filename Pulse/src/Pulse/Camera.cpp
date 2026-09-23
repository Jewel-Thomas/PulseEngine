#include "plspch.h"
#include "Camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Pulse {

	Camera::Camera()
	{
		UpdateViewMatrix(m_CameraPosition, m_CameraPosition + m_CameraFront);
		UpdateProjMatrix(45.0f, 0.1f, 100.0f);
		m_Yaw = -90.0f;
		m_Pitch = 0.0f;
		m_LastXMousePosition = m_ViewWidth / 2.0f;
		m_LastYMousePosition = m_ViewHeight / 2.0f;
		ToggleCameraLock();
	}

	const glm::mat4& Camera::GetViewMatrix() const
	{
		return m_View;
	}

	const glm::mat4& Camera::GetProjectionMatrix() const
	{
		return m_Proj;
	}

	void Camera::UpdateViewMatrix(const glm::vec3& cameraPosition ,const glm::vec3& targetPosition)
	{
		m_View = glm::lookAt(cameraPosition, targetPosition, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	void Camera::UpdateProjMatrix(float fov, float nearPlane, float farPlane, int viewWidth, int viewHeight)
	{
		GLFWwindow* window = glfwGetCurrentContext();

		if (viewWidth || viewHeight)
			glViewport(0, 0, viewWidth, viewHeight);

		glfwGetFramebufferSize(window, &m_ViewWidth, &m_ViewHeight);
		float aspectRatio = (float)m_ViewWidth / (float)m_ViewHeight;

		m_Proj = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
	}

	void Camera::CameraMovement()
	{
		float currentTime = glfwGetTime();
		m_DeltaTime = currentTime - m_LastFrameTime;
		m_LastFrameTime = currentTime;

		const float cameraSpeed = 2.5f * m_DeltaTime;

		glm::vec3 cameraRight = glm::normalize(glm::cross(m_CameraFront, m_WorldUp));
		glm::vec3 cameraUp = glm::normalize(glm::cross(m_CameraFront, cameraRight));

		GLFWwindow* window = glfwGetCurrentContext();

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			m_CameraPosition += cameraSpeed * m_CameraFront;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			m_CameraPosition -= cameraSpeed * m_CameraFront;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			m_CameraPosition -= cameraSpeed * cameraRight;
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			m_CameraPosition += cameraSpeed * cameraRight;
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
			m_CameraPosition -= cameraSpeed * cameraUp;
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
			m_CameraPosition += cameraSpeed * cameraUp; 

		UpdateViewMatrix(m_CameraPosition, m_CameraPosition + m_CameraFront);
	}

	void Camera::UpdateCameraFrontCallBack(float xPos, float yPos)
	{
		if (m_IsFirstMousePosition)
		{
			m_LastXMousePosition = xPos;
			m_LastYMousePosition = yPos;
			m_IsFirstMousePosition = false;
			return;
		}

		float xOffset = xPos - m_LastXMousePosition;
		float yOffset = m_LastYMousePosition - yPos;
		m_LastXMousePosition = xPos;
		m_LastYMousePosition = yPos;

		m_Yaw += xOffset * m_Sensitivity;
		m_Pitch += yOffset * m_Sensitivity;

		if (m_Pitch > 89.0f)
			m_Pitch = 89.0f;
		if (m_Pitch < -89.0f)
			m_Pitch = -89.0f;

		glm::vec3 forwardDirection;
		forwardDirection.x = glm::cos(glm::radians(m_Yaw)) * glm::cos(glm::radians(m_Pitch));
		forwardDirection.y = glm::sin(glm::radians(m_Pitch));
		forwardDirection.z = glm::sin(glm::radians(m_Yaw)) * glm::cos(glm::radians(m_Pitch));

		m_CameraFront = forwardDirection;
	}

	void Camera::ToggleCameraLock()
	{
		m_IsMouseLocked = !m_IsMouseLocked;
		GLFWwindow* window = glfwGetCurrentContext();

		m_IsMouseLocked ? glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED) :
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		double currentMouseX, currentMouseY;
		glfwGetCursorPos(window, &currentMouseX, &currentMouseY);
		m_LastXMousePosition = currentMouseX;
		m_LastYMousePosition = currentMouseY;
	}

}