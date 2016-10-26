#pragma once
#include "ControllerComponent.h"
#include "Helpers\Methods.h"
#include "Helpers\Structs.h"

class AsteroidController : public ControllerComponent {
public:
	AsteroidController() {
		_rotationSpeed = RandFloat(MIN_ROTATION_SPEED, MAX_ROTATION_SPEED);
	}

	void Update(sf::Int32 deltaTime) {
		_gameObject->_sprite.rotate(_rotationSpeed * deltaTime);
	}
private:
	const float MIN_ROTATION_SPEED = 0.05f;
	const float MAX_ROTATION_SPEED = 0.20f;

	float _rotationSpeed;
};