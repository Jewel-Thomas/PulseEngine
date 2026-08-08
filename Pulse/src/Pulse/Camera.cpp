#include "plspch.h"
#include "Camera.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Pulse {

	Camera::Camera()
	{
		UpdateViewMatrix(m_CameraPosition, glm::vec3(0.0f, 0.0f, 0.0f));
		UpdateProjMatrix(45.0f, 0.1f, 100.0f);
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

	void Camera::UpdateProjMatrix(float fov, float nearPlane, float farPlane)
	{
		int width, height;
		GLFWwindow* window = glfwGetCurrentContext();
		glfwGetFramebufferSize(window, &width, &height);
		float aspectRatio = (float)width / (float)height;

		m_Proj = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
	}

	void Camera::OrbitCamera(const glm::vec3& targetPosition, float radius)
	{
		float camX = glm::sin(glfwGetTime()) * radius;
		float camZ = glm::cos(glfwGetTime()) * radius;
		glm::vec3 cameraPosition = glm::vec3(camX, 0.0f, camZ);
		UpdateViewMatrix(cameraPosition, targetPosition);
	}

	void Camera::CameraMovement()
	{
		float currentTime = glfwGetTime();
		m_DeltaTime = currentTime - m_LastFrameTime;
		m_LastFrameTime = currentTime;

		const float cameraSpeed = 2.5f * m_DeltaTime;
		GLFWwindow* window = glfwGetCurrentContext();
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			m_CameraPosition += cameraSpeed * m_CameraFront;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			m_CameraPosition -= cameraSpeed * m_CameraFront;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			m_CameraPosition -= cameraSpeed * glm::normalize(glm::cross(m_CameraFront, m_CameraUp));
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			m_CameraPosition += cameraSpeed * glm::normalize(glm::cross(m_CameraFront, m_CameraUp));

		UpdateViewMatrix(m_CameraPosition, m_CameraPosition + m_CameraFront);
	}

}