#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
#include "GameObject.h"
#include "InputManager.h"
#include "ResourceManager.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* window);
	~GameState();

	void AddObject(GameObject* object);
	sf::Vector2u GetBounds();
	void QueueDeleteObject(GameObject* object);
private:
	void HandleEvents();
	void Update(sf::Int32 deltaTime);
	void DrawState();

	std::vector<GameObject*> _objects;
	std::vector<GameObject*> _deleteQueue;

	ResourceManager _resourceManager;
	InputManager _inputManager;
};