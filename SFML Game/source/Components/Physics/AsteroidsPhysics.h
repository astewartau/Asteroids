#pragma once
#include "PhysicsComponent.h"

class AsteroidsPhysics : public PhysicsComponent {
public:
	// Setup an Asteroids physics object at the given location
	AsteroidsPhysics(sf::Vector2u bounds, sf::Vector2f startPosition) {
		_bounds = bounds;
		_startPosition = startPosition;
	}

	// Setup an Asteroids physics object at a random location outside the screen
	AsteroidsPhysics(sf::Vector2u bounds) {
		_bounds = bounds;

		Vec3<float> position;
		position.SetMagnitude(hypot(_bounds.x / 2.0f, _bounds.y / 2.0f));
		position.SetDirection(rand() % 360 + 1);

		_startPosition = {position.GetX(), position.GetY()};
	}

	void Init(GameObject* gameobject) {
		gameobject->_sprite.setPosition(_startPosition);
	}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
		gameobject->_sprite.move(gameobject->_velocity);

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
	sf::Vector2f _startPosition;
};