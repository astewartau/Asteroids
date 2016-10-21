#pragma once
#include "ControllerComponent.h"
#include "Helpers\Methods.h"
#include "Helpers\Structs.h"

class AsteroidController : public ControllerComponent {
public:
	AsteroidController() {
		_moveSpeed = MOVE_SPEED;
		_rotationSpeed = RandFloat(MIN_ROTATION_SPEED, MAX_ROTATION_SPEED);
	}

	void Init() {
		Vec3<float> velocity;
		velocity.SetDirection((float)RandInt(1,360));
		velocity.SetMagnitude(_moveSpeed);
		_gameObject->_velocity = sf::Vector2f{ velocity.GetX(), velocity.GetY() };
	}

	void Update(sf::Int32 deltaTime) {
		_gameObject->_sprite.rotate(_rotationSpeed * deltaTime);
	}
private:
	const float MIN_ROTATION_SPEED = 0.05f;
	const float MAX_ROTATION_SPEED = 0.20f;
	const float MOVE_SPEED = 0.15f;

	float _moveSpeed;
	float _rotationSpeed;
};