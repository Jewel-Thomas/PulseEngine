#pragma once

#ifdef PLS_PLATFORM_WINDOWS

extern Pulse::Application* Pulse::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Pulse::CreateApplication();
	app->Run();
	delete app;
}

#endif
