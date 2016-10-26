#pragma once
#include "../Component.h"

class PhysicsComponent : public Component {
public:
	PhysicsComponent() {}
	virtual void Init() {};
	virtual void Update(sf::Int32 deltaTime) = 0;
};