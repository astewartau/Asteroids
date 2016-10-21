#pragma once
#include "../Component.h"
#include "Managers\ResourceManager.h"

class GraphicsComponent : public Component {
public:
	GraphicsComponent(ResourceManager* resourceManager) {
		_resourceManager = resourceManager;
	}
	virtual void Update(sf::Int32 deltaTime) {};
	virtual void Init() {};
protected:
	ResourceManager* _resourceManager;
};