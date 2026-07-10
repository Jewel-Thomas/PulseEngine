#pragma once



namespace Pulse {

	enum class RendererAPI
	{
		None = 0,
		OpenGL = 1
	};

	class Renderer
	{
	private:
		static RendererAPI s_RendererAPI;

	public:
		static inline RendererAPI GetAPI() { return  s_RendererAPI; }

	};

}
