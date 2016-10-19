#pragma once
#include "../Component.h"

class SpawnerComponent : public Component {
public:
	SpawnerComponent() {}
	~SpawnerComponent() {}
	virtual void Update(GameObject* gameobject, sf::Int32 deltaTime) = 0;
	virtual void Init(GameObject* gameobject) = 0;
};