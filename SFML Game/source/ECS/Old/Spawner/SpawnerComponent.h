#pragma once
#include "../Component.h"

class SpawnerComponent : public Component {
public:
	SpawnerComponent() {}

	virtual void Spawn() = 0;

	virtual void Update(sf::Int32 deltaTime) {};
	virtual void ReceiveMessage() {};
	virtual void Init() {};
};