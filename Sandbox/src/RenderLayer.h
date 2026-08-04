#pragma once
#include <Pulse.h>

class RenderLayer : public Pulse::Layer
{
private:
	std::shared_ptr<Pulse::VertexArray> m_VertexArray;
	std::shared_ptr<Pulse::Shader> m_Shader;
public:
	RenderLayer();

	virtual void OnAttach() override;
	virtual void OnUpdate() override;
};
