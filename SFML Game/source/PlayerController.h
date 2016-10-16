#pragma once
#include "InputManager.h"
#include "Controller.h"

class PlayerController : public Controller {
public:
	PlayerController() {
		_speed = 0.01f;
	}
	void Init(GameObject* gameobject) {}
	void Update(GameObject* gameobject, sf::Int32 deltaTime);
private:
	float _speed;

};