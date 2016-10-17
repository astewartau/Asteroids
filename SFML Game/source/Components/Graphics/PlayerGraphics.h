#pragma once
#include "GraphicsComponent.h"

class PlayerGraphics : public GraphicsComponent {
public:
	PlayerGraphics() { }

	void Init(GameObject* gameobject) {
		gameobject->_sprite.setTexture(*ResourceManager::GetInstance().GetTexture("assets/textures/playerShip1_blue.png"));
		gameobject->_sprite.setOrigin(gameobject->_sprite.getLocalBounds().width / 2.0f, gameobject->_sprite.getLocalBounds().height / 2.0f);
	}
	void Update(GameObject* gameobject, sf::Int32 deltaTime) {

	}
};