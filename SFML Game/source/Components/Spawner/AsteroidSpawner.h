#pragma once
#include "SpawnerComponent.h"
#include "States/GameState.h"
#include "Managers/ResourceManager.h"

class AsteroidSpawner : public SpawnerComponent {
public:
	AsteroidSpawner(GameState* state, ResourceManager* resourceManager);
	void Update(sf::Int32 deltaTime);
	void Spawn();
private:
	const float MIN_SPEED = 0.07f;
	const float MAX_SPEED = 0.30f;
	const int NUM_SPAWNS = 20;
	const int SPAWN_INTERVAL = 1;

	ResourceManager* _resourceManager;
	sf::Clock _clock;
	GameState* _state;
	int _remainingSpawns;
	sf::Vector2u _bounds;
};