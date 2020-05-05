#pragma once

#include "Core.h"
#include "LayerStack.h"
#include "Window.h"
#include "../Events/ApplicationEvent.h"
#include "../Events/Event.h"
#include "Dash/ImGui/ImGuiLayer.h"

namespace Dash
{
	class DASH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// Defined in client
	Application* CreateApplication();
}