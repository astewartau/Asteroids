#pragma once
#include "SpawnerComponent.h"
#include "..\..\GameState.h"

class AsteroidSpawner : public SpawnerComponent {
public:
	AsteroidSpawner(GameState* state, ResourceManager* resourceManager);
	~AsteroidSpawner() {}
	void Init(GameObject* gameobject) {}
	void Update(GameObject* gameobject, sf::Int32 deltaTime);
private:
	const float MIN_SPEED = 0.05f;
	const float MAX_SPEED = 0.20f;
	const int NUM_SPAWNS = 5;
	const int SPAWN_INTERVAL = 3;

	ResourceManager* _resourceManager;
	sf::Clock _clock;
	GameState* _state;
	int _remainingSpawns;
	sf::Vector2u _bounds;
};