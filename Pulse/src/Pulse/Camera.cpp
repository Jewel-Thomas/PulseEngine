#include "plspch.h"
#include "Camera.h"

#include <GLFW/glfw3.h>

namespace Pulse {

	Camera::Camera()
	{
		UpdateViewMatrix(glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f));
	}

	const glm::mat4& Camera::GetViewMatrix() const
	{
		return m_View;
	}

	void Camera::UpdateViewMatrix(const glm::vec3& cameraPosition ,const glm::vec3& targetPosition)
	{
		m_View = glm::lookAt(cameraPosition, targetPosition, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	void Camera::OrbitCamera(const glm::vec3& targetPosition, float radius)
	{
		float camX = glm::sin(glfwGetTime()) * radius;
		float camZ = glm::cos(glfwGetTime()) * radius;
		glm::vec3 cameraPosition = glm::vec3(camX, 0.0f, camZ);
		UpdateViewMatrix(cameraPosition, targetPosition);
	}

}