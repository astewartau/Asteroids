#pragma once
#include "Controller.h"
#include "../../Structs.h"

class BulletController : public Controller {
public:
	BulletController() {
		_speed = 10;
	}

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