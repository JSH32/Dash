#pragma once
#include "Application.h"

#ifdef  DS_PLATFORM_WINDOWS

extern Dash::Application* Dash::CreateApplication();

int main(int argc, char** argv) {
	auto app = Dash::CreateApplication();
	app->Run();
	delete app;
}

#endif