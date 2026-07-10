#pragma once
#include <string>


namespace Pulse::ShaderSrc {

	static inline const std::string VertexSrc = R"(
			
				#version 330 core
				layout(location = 0) in vec3 a_Position;
			
				out vec3 v_Position;

				void main()
				{
					v_Position = a_Position;
					gl_Position = vec4(a_Position, 1.0);
				}
		
			)";

	static inline const std::string FragmentSrc = R"(
			
				#version 330 core
				layout(location = 0) out vec4 color;

				in vec3 v_Position;

				void main()
				{
					color = vec4(v_Position * 0.5 + 0.5, 1.0);   
				}

			)";

}

