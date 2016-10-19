#pragma once
#include "ControllerComponent.h"
#include "../../Structs.h"
#include "../../Helpers.h"

class AsteroidController : public ControllerComponent {
public:
	AsteroidController() {
		_moveSpeed = 0.15f;
		_rotationSpeed = 0.02f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.15f - 0.02f)));
	}
	~AsteroidController() {}

	void Init(GameObject* gameobject) {
		Vec3<float> velocity;
		velocity.SetDirection((float)RandInt(1,360));
		velocity.SetMagnitude(_moveSpeed);
		gameobject->_velocity = sf::Vector2f{ velocity.GetX(), velocity.GetY() };
	}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
		gameobject->_sprite.rotate(_rotationSpeed * deltaTime);
	}

private:
	float _moveSpeed;
	float _rotationSpeed;
};