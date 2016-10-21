#pragma once
#include "GraphicsComponent.h"

class BulletGraphics : public GraphicsComponent {
public:
	BulletGraphics(ResourceManager* resourceManager) : GraphicsComponent(resourceManager) {}
	void Init() {
		_gameObject->_sprite.setTexture(*_resourceManager->GetTexture("assets/textures/laserBlue01.png"));
		_gameObject->_sprite.setOrigin(_gameObject->_sprite.getLocalBounds().width / 2.0f, _gameObject->_sprite.getLocalBounds().height / 2.0f);
	}
};