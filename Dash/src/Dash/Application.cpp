#include "Application.h"

#include "../Events/ApplicationEvent.h"
#include "../Dash/Log.h"


namespace Dash {
	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		DS_TRACE(e);

		while (true);
	}
}