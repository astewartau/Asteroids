#pragma once
#include "../Component.h"
#include "../../ResourceManager.h"

class GraphicsComponent : public Component {
public:
	GraphicsComponent() {}
	virtual void Update(GameObject* gameobject, sf::Int32 deltaTime) = 0;
	virtual void Init(GameObject* gameobject) = 0;
};