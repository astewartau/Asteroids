#pragma once
#include "PhysicsComponent.h"

class AsteroidsPhysics : public PhysicsComponent {
public:
	AsteroidsPhysics(sf::Vector2u bounds) {
		_bounds = bounds;
	}

	void Init(GameObject* gameobject) {
		gameobject->_sprite.setPosition(_bounds.x / 2.0f, _bounds.y / 2.0f);
	}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
		gameobject->_sprite.move(gameobject->_velocity);

		auto spritePosition = gameobject->_sprite.getPosition();
		if (spritePosition.x < 0) {
			gameobject->_sprite.setPosition(_bounds.x, spritePosition.y);
		} else if (spritePosition.x > _bounds.x) {
			gameobject->_sprite.setPosition(0, spritePosition.y);
		}

		if (spritePosition.y < 0) {
			gameobject->_sprite.setPosition(spritePosition.x, _bounds.y);
		} else if (spritePosition.y > _bounds.y) {
			gameobject->_sprite.setPosition(spritePosition.x, 0);
		}
	}

private:
	sf::Vector2u _bounds;
};