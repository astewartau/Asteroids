#pragma once
#include "PhysicsComponent.h"
#include "../../Structs.h"

class AsteroidsPhysics : public PhysicsComponent {
public:
	// Setup an Asteroids physics object
	AsteroidsPhysics(sf::Vector2u bounds) {
		_bounds = bounds;
	}

	void Init(GameObject* gameobject) {
	}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
		gameobject->_sprite.move(gameobject->_velocity.x * deltaTime, gameobject->_velocity.y * deltaTime);

		auto spritePosition = gameobject->_sprite.getPosition();
		auto spriteSize = gameobject->_sprite.getLocalBounds();
		if (spritePosition.x < -spriteSize.width/2.0f) {
			gameobject->_sprite.setPosition(_bounds.x + spriteSize.width/2.0f, spritePosition.y);
		} else if (spritePosition.x > _bounds.x + spriteSize.width/2.0f) {
			gameobject->_sprite.setPosition(-spriteSize.width/2.0f, spritePosition.y);
		}

		if (spritePosition.y < -spriteSize.height/2.0f) {
			gameobject->_sprite.setPosition(spritePosition.x, _bounds.y + spriteSize.height/2.0f);
		} else if (spritePosition.y > _bounds.y + spriteSize.height/2.0f) {
			gameobject->_sprite.setPosition(spritePosition.x, -spriteSize.height/2.0f);
		}
	}

private:
	sf::Vector2u _bounds;
};