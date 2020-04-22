#include "dspch.h"
#include "Application.h"

#include "../Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>


namespace Dash {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void Application::OnEvent(Event& e) {
		DS_CORE_INFO("{0}", e);
	}

	Application::~Application() {}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}