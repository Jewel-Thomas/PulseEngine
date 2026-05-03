#pragma once

#ifdef PLS_PLATFORM_WINDOWS

extern Pulse::Application* Pulse::CreateApplication();

int main(int argc, char** argv)
{
	Pulse::Logger::Init();
	PLS_CORE_INFO("Info from Engine Logger!");
	PLS_CORE_DEBUG("Debugging something!");
	PLS_CORE_ERROR("Sarcastic error!");
	PLS_CORE_WARN("Warn from Application Logger!");
	PLS_CORE_FATAL("Something may not be critical!");
	PLS_CORE_TRACE("Sample Trace");

	PLS_INFO("Info from App Logger!");
	PLS_DEBUG("Debugging something!");
	PLS_ERROR("Sarcastic error!");
	PLS_WARN("Warn from Application Logger!");
	PLS_FATAL("Something may not be critical!");
	PLS_TRACE("Sample Trace");

	auto app = Pulse::CreateApplication();
	app->Run();
	delete app;
}

#endif
