#pragma once
#include "GraphicsComponent.h"

class AsteroidGraphics : public GraphicsComponent {
public:
	AsteroidGraphics() { }

	void Init(GameObject* gameobject) {
		gameobject->_sprite.setTexture(*ResourceManager::GetInstance().GetTexture("assets/textures/meteorGrey_big1.png"));
		gameobject->_sprite.setOrigin(gameobject->_sprite.getLocalBounds().width / 2.0f, gameobject->_sprite.getLocalBounds().height / 2.0f);
	}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {

	}
private:

};