#include "dspch.h"
#include <Dash.h>

class TestingLayer : public Dash::Layer
{
public:
	TestingLayer() : Layer("Testing") {}

	void OnUpdate() override
	{
		// DS_INFO("Updated test layer");
		if (Dash::Input::IsKeyPressed(DS_KEY_TAB))
			DS_TRACE("POLLING Tab Pressed");
	}

	void OnEvent(Dash::Event& event) override
	{
		// DS_TRACE("{0}", event);
		if (event.GetEventType() == Dash::EventType::KeyPressed)
		{
			Dash::KeyPressedEvent& e = (Dash::KeyPressedEvent&)event;
			if (e.GetKeyCode() == DS_KEY_TAB)
				DS_TRACE("EVENT Tab Pressed");
			
			DS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Game : public Dash::Application
{
public:
	Game()
	{
		PushLayer(new TestingLayer());
		PushOverlay(new Dash::ImGuiLayer());
	}

	~Game() {}
};

Dash::Application* Dash::CreateApplication()
{
	return new Game();
}
