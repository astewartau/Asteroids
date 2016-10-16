#pragma once
#include "PlayerController.h"

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
}