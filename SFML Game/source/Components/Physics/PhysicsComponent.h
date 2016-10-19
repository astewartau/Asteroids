#pragma once
#include "../Component.h"

class PhysicsComponent : public Component {
public:
	PhysicsComponent() {}
	~PhysicsComponent() {}
	virtual void Init(GameObject* gameobject) = 0;
	virtual void Update(GameObject* gameobject, sf::Int32 deltaTime) = 0;
};