#pragma once
#include <string>


namespace Pulse::ShaderSrc {

	// Square Shaders
	static inline const std::string SquareVertexSrc = R"(
			
				#version 330 core
				layout(location = 0) in vec3 a_Position;
				layout(location = 1) in vec4 a_Color;
			
				out vec3 v_Position;
				out vec4 v_Color;

				void main()
				{
					v_Position = a_Position;
					v_Color = a_Color;
					gl_Position = vec4(a_Position, 1.0);
				}
		
			)";

	static inline const std::string SquareFragmentSrc = R"(
			
				#version 330 core
				layout(location = 0) out vec4 color;

				in vec4 v_Color;

				void main()
				{
					color = v_Color;   
				}

			)";

	// Triangle Shaders
	static inline const std::string TriangleVertexSrc = R"(
				#version 330 core
				layout(location = 0) in vec3 a_Position;
				
				out vec3 v_Position;				

				void main()
				{
					v_Position = a_Position;
					gl_Position = vec4(a_Position, 1.0f);
				}

			)";

	static inline const std::string TriangleFragmentSrc = R"(
				#version 330 core
				layout(location = 0) out vec4 color;
				
				in vec3 v_Position;				

				void main()
				{
					color = vec4(v_Position * 0.5f + 0.5f, 1.0f);
				}

			)";

}

