#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <vector>
#include "State.h"

class Engine {
public:
	Engine();

	void Init();
	void Go();
	void SetupGame();
	void GameLoop();
	void CleanUp();
private:
	sf::RenderWindow _window;
	State* _currentState;
};