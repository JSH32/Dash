#include <Dash.h>

class Game : public Dash::Application {
public:
	Game() {

	}

	~Game() {
		
	}
};

Dash::Application* Dash::CreateApplication() {
	return new Game();
}