#pragma once
#include <SFML\Graphics.hpp>

class State {
public:
	State(sf::RenderWindow* window) {
		_window = window;
	}

	virtual void HandleEvent(sf::Event evt) = 0;
	virtual void Update(sf::Time deltaTime) = 0;
	virtual void Draw() = 0;
protected:
	sf::RenderWindow* _window;
};