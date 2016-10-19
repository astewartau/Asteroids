#pragma once
#include "GraphicsComponent.h"

class BulletGraphics : public GraphicsComponent {
public:
	BulletGraphics(ResourceManager* resourceManager) : GraphicsComponent(resourceManager) {}
	~BulletGraphics() { }
	void Init(GameObject* gameobject) {
		gameobject->_sprite.setTexture(*_resourceManager->GetTexture("assets/textures/laserBlue01.png"));
		gameobject->_sprite.setOrigin(gameobject->_sprite.getLocalBounds().width / 2.0f, gameobject->_sprite.getLocalBounds().height / 2.0f);
	}
	void Update(GameObject* gameobject, sf::Int32 deltaTime) {

	}
};