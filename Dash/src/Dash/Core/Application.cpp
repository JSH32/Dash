#include "dspch.h"
#include "Application.h"

#include "../Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>


namespace Dash {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}