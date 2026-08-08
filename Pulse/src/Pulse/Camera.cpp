#include "plspch.h"
#include "Camera.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Pulse {

	Camera::Camera()
	{
		UpdateViewMatrix(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f));
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

	void Camera::CameraMovement(const glm::vec3& cameraPosition, const glm::vec3& cameraFront, const glm::vec3& cameraUp)
	{
		// TODO : Add Movement Logic
	}

}