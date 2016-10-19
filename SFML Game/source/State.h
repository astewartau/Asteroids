#pragma once
#include <SFML\Graphics.hpp>

class State {
public:
	State* Run() {
		StartLoop();
		HandleEvents();
		Update(_clock.restart().asMilliseconds());
		Draw();
		EndLoop();
		return _nextState;
	}

	virtual ~State() {}
protected:
	State(sf::RenderWindow* window) {
		_window = window;
		_nextState = this;
	}

	virtual void HandleEvents() = 0;
	virtual void Update(sf::Int32 deltaTime) = 0;
	virtual void DrawState() = 0;

	sf::RenderWindow* _window;
	State* _nextState;
private:
	sf::Clock _clock;
	void StartLoop() {

	}
	void Draw() {
		_window->clear();
		DrawState();
		_window->display();
	}
	void EndLoop() {
		sf::sleep(sf::milliseconds(10));
	}
};