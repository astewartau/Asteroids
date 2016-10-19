#pragma once
#include "ControllerComponent.h"
#include "../../Structs.h"

class BulletController : public ControllerComponent {
public:
	BulletController() {
		_speed = 10;
	}
	~BulletController() { }

	void Init(GameObject* gameobject) {
		Vec3<float> velocity;
		velocity.SetDirection(rand() % 360 + 1);
		velocity.SetMagnitude(_speed);
		gameobject->_velocity = sf::Vector2f{ velocity.GetX(), velocity.GetY() };
	}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
	}

private:
	float _speed;

};