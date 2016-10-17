#pragma once
#include "../../InputManager.h"
#include "Controller.h"

#define _USE_MATH_DEFINES
#include <math.h>

class PlayerController : public Controller {
public:
	PlayerController(std::vector<GameObject*>* objects) {
		_speed = 0.01f;
		_objects = objects;
	}
	void Init(GameObject* gameobject) {}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_LEFT)) {
			gameobject->_velocity += sf::Vector2f{ -_speed * deltaTime, 0.0f };
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_RIGHT)) {
			gameobject->_velocity += sf::Vector2f{ _speed * deltaTime, 0.0f };
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_UP)) {
			gameobject->_velocity += sf::Vector2f{ 0.0f, -_speed * deltaTime };
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_DOWN)) {
			gameobject->_velocity += sf::Vector2f{ 0.0f, _speed * deltaTime };
		}
		if (InputManager::GetInstance().IsMousePressed((MouseButton)FIRE)) {
			
		}

		sf::Vector2f playerPosition = gameobject->_sprite.getPosition();
		float opposite = playerPosition.x - InputManager::GetInstance().GetMousePosition().x;
		float adjacent = playerPosition.y - InputManager::GetInstance().GetMousePosition().y;
		float angle = atan2(adjacent, opposite) * 180 / M_PI - 90;
		gameobject->_sprite.setRotation(angle);
	}

private:
	float _speed;
	std::vector<GameObject*>* _objects;
};