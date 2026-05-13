#pragma once

#ifdef PLS_PLATFORM_WINDOWS

extern Pulse::Application* Pulse::CreateApplication();

int main(int argc, char** argv)
{
	Pulse::Logger::Init();
	PLS_CORE_INFO("Info from Engine Logger!");

	PLS_INFO("Info from App Logger!");

	auto app = Pulse::CreateApplication();
	app->Run();
	delete app;
}

#endif
