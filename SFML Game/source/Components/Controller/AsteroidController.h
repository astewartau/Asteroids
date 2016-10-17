#pragma once
#include "Controller.h"
#include "../../Structs.h"

class AsteroidController : public Controller {
public:
	AsteroidController() {
		_moveSpeed = 1;
		_rotationSpeed = 0.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.0f - 0.1f)));
	}

	void Init(GameObject* gameobject) {
		Vec3<float> velocity;
		velocity.SetDirection(rand() % 360 + 1);
		velocity.SetMagnitude(_moveSpeed);
		gameobject->_velocity = sf::Vector2f{ velocity.GetX(), velocity.GetY() };
	}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
		gameobject->_sprite.rotate(_rotationSpeed);
	}

private:
	float _moveSpeed;
	float _rotationSpeed;
};