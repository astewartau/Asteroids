#pragma once
#include "GraphicsComponent.h"

class AsteroidGraphics : public GraphicsComponent {
public:
	AsteroidGraphics(ResourceManager* resourceManager) : GraphicsComponent(resourceManager) { }
	void Init() {
		_gameObject->_sprite.setTexture(*_resourceManager->GetTexture("assets/textures/meteorGrey_big1.png"));
		_gameObject->_sprite.setOrigin(_gameObject->_sprite.getLocalBounds().width / 2.0f, _gameObject->_sprite.getLocalBounds().height / 2.0f);
	}
};