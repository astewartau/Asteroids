#pragma once
#include <SFML\Graphics.hpp>
#include "States\State.h"

class StateRunner {
public:
	void Init();
	void Go();
	void SetupGame();
	void GameLoop();
	void CleanUp();
private:
	sf::RenderWindow _window;
	State* _currentState;
};