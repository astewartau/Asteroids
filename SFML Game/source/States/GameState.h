#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
#include "Components\GameObject.h"
#include "Managers\InputManager.h"
#include "Managers\ResourceManager.h"

class GameState : public State {
public:
	~GameState();

	sf::Vector2u GetBounds();
	void AddObject(GameObject* object);
	void QueueDeleteObject(GameObject* object);
protected:
	GameState(sf::RenderWindow* window) : State(window) {}
	ResourceManager _resourceManager;
	InputManager _inputManager;
private:
	void HandleEvents();
	void Update(sf::Int32 deltaTime);
	void DrawState();

	std::vector<GameObject*> _objects;
	std::vector<GameObject*> _deleteQueue;
};