#pragma once
#include <glm/ext/matrix_transform.hpp>

namespace Pulse {

	// Currently the camera is only capable to generate the view matrix and rotate around the target
	class Camera
	{
	private:
		glm::mat4 m_View;

	public:
		Camera();

		const glm::mat4& GetViewMatrix() const;
		void UpdateViewMatrix(const glm::vec3& cameraPosition, const glm::vec3& targetPosition);
		void OrbitCamera(const glm::vec3& targetPosition, float radius);
	};

}
