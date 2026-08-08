#pragma once
#include <glm/ext/matrix_transform.hpp>

namespace Pulse {

	// Currently the camera is only capable to generate the view matrix and rotate around the target
	class Camera
	{
	private:
		glm::mat4 m_View;
		glm::mat4 m_Proj;

		glm::vec3 m_CameraPosition = glm::vec3(0.0f, 0.0f, 5.0f);
		glm::vec3 m_CameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

		float m_DeltaTime = 0.0f;
		float m_LastFrameTime = 0.0f;

	public:
		Camera();

		const glm::mat4& GetViewMatrix() const;
		const glm::mat4& GetProjectionMatrix() const;

		void UpdateViewMatrix(const glm::vec3& cameraPosition, const glm::vec3& targetPosition);
		void UpdateProjMatrix(float fov, float nearPlane, float farPlane);

		void OrbitCamera(const glm::vec3& targetPosition, float radius);
		void CameraMovement();
	};

}
