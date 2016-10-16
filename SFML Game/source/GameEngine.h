#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <vector>
#include "State.h"

class GameEngine {
public:
	GameEngine();

	void Init();
	void Go();
	void SetupGame();
	void GameLoop();

	void ProcessInput();
	void Update(sf::Time deltaTime);
	void Draw();
	void StartLoop();
	void EndLoop();

	bool Running() { return _quit; }
	void Quit() { _quit = false; }

private:
	// the stack of states
	sf::RenderWindow _window;
	std::vector<State*> _states;
	sf::Clock _clock;
	bool _quit;
};