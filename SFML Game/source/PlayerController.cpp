#pragma once
#include "PlayerController.h"

#define _USE_MATH_DEFINES
#include <math.h>

void PlayerController::Update(GameObject* gameobject, sf::Int32 deltaTime) {
	if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_L)) {
		gameobject->_velocity += sf::Vector2f{ -_speed * deltaTime, 0.0f };
	}
	if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_R)) {
		gameobject->_velocity += sf::Vector2f{ _speed * deltaTime, 0.0f };
	}
	if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_U)) {
		gameobject->_velocity += sf::Vector2f{ 0.0f, -_speed * deltaTime };
	}
	if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_D)) {
		gameobject->_velocity += sf::Vector2f{ 0.0f, _speed * deltaTime };
	}

	sf::Vector2f playerPosition = gameobject->_sprite.getPosition();
	float opposite = playerPosition.x - InputManager::GetInstance().GetMousePosition().x;
	float adjacent = playerPosition.y - InputManager::GetInstance().GetMousePosition().y;
	float angle = atan2(adjacent, opposite) * 180 / M_PI - 90;
	gameobject->_sprite.setRotation(angle);
}