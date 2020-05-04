#include "dspch.h"
#include <Dash.h>

class TestingLayer : public Dash::Layer
{
public:
	TestingLayer() : Layer("Testing") {}

	void OnUpdate() override
	{
		// DS_INFO("Updated test layer");
	}

	void OnEvent(Dash::Event& event) override
	{
		DS_TRACE("{0}", event);
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
