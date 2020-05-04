#pragma once

#include "Application.h"

#ifdef  DS_PLATFORM_WINDOWS

extern Dash::Application* Dash::CreateApplication();

int main(int argc, char** argv)
{
	Dash::Log::Init();
	DS_CORE_WARN("Logging service initialized!");
	DS_INFO("Hello there :)");

	auto app = Dash::CreateApplication();
	app->Run();
	delete app;
}

#endif