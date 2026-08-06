#pragma once
#include <glm/ext/matrix_transform.hpp>

namespace Pulse {

	// Currently the camera is only capable to generate the view matrix and rotate around the target
	class Camera
	{
	private:
		glm::mat4 m_View;
		glm::mat4 m_Proj;

	public:
		Camera();

		const glm::mat4& GetViewMatrix() const;
		const glm::mat4& GetProjectionMatrix() const;

		void UpdateViewMatrix(const glm::vec3& cameraPosition, const glm::vec3& targetPosition);
		void UpdateProjMatrix(float fov, float nearPlane, float farPlane);

		void OrbitCamera(const glm::vec3& targetPosition, float radius);
	};

}
