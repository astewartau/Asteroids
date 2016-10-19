#pragma once
#include "../Component.h"
#include "../../ResourceManager.h"

class GraphicsComponent : public Component {
public:
	GraphicsComponent(ResourceManager* resourceManager) {
		_resourceManager = resourceManager;
	}
	~GraphicsComponent() {}
	virtual void Update(GameObject* gameobject, sf::Int32 deltaTime) = 0;
	virtual void Init(GameObject* gameobject) = 0;
protected:
	ResourceManager* _resourceManager;
};