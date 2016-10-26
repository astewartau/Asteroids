#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
#include "Managers\InputManager.h"
#include "Managers\ResourceManager.h"

class GameState : public State {
public:
	~GameState();
	sf::Vector2u GetBounds();
protected:
	GameState(sf::RenderWindow* window) : State(window) {}
	ResourceManager _resourceManager;
	InputManager _inputManager;
private:
	void HandleEvents();
	void Update(sf::Int32 deltaTime);
	void DrawState();
};