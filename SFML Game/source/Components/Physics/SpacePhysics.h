#pragma once
#include "PhysicsComponent.h"
#include "Helpers\Structs.h"

class SpacePhysics : public PhysicsComponent {
public:
	SpacePhysics() { }

	void Update(sf::Int32 deltaTime) {
		_gameObject->_sprite.move(_gameObject->_velocity.x * deltaTime, _gameObject->_velocity.y * deltaTime);
	}
};