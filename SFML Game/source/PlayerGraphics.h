#pragma once
#include "GraphicsComponent.h"
#include "ResourceManager.h"
class PlayerGraphics : public GraphicsComponent {
public:
	PlayerGraphics() {
	}
	void Init(GameObject* gameobject) {
		ResourceManager::GetInstance().GetTexture("assets/textures/playerShip1_blue.png");
		gameobject->_sprite.setTexture(*ResourceManager::GetInstance().GetTexture("assets/textures/playerShip1_blue.png"));
	}
	void Update(GameObject* gameobject, sf::Int32 deltaTime) {

	}
};