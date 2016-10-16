#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "InputManager.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Player : public GameObject {
public:
	Player(sf::Texture* texture, sf::Vector2u playArea) : GameObject(texture, playArea) {
		_health = 10;
		_accelSpeed = 0.0075f;
		_maxSpeed = 5.0f;
		_playArea = playArea;
		_sprite.setPosition(playArea.x / 2.0f, playArea.y / 2.0f);
	}
	void Update(sf::Time deltaTime) {
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_U)) {
			if (_velocity.y > -_maxSpeed) {
				Accelerate(sf::Vector2f{ 0.0f, -_accelSpeed * deltaTime.asMilliseconds() });
			}
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_L)) {
			if (_velocity.x > -_maxSpeed) {
				Accelerate(sf::Vector2f{ -_accelSpeed * deltaTime.asMilliseconds(), 0.0f });
			}
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_D)) {
			if (_velocity.y < _maxSpeed) {
				Accelerate(sf::Vector2f{ 0.0f, _accelSpeed * deltaTime.asMilliseconds() });
			}
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_R)) {
			if (_velocity.x < _maxSpeed) {
				Accelerate(sf::Vector2f{ _accelSpeed * deltaTime.asMilliseconds(), 0.0f });
			}
		}
		LookAt(InputManager::GetInstance().GetMousePosition());
		GameObject::Update(deltaTime);
	}
private:
	int _health;
	float _maxSpeed;
	float _accelSpeed;
	void LookAt(sf::Vector2u location) {
		sf::Vector2f playerPosition = _sprite.getPosition();
		float opposite = playerPosition.x - location.x;
		float adjacent = playerPosition.y - location.y;
		float angle = atan2(adjacent, opposite) * 180 / M_PI - 90;
		_sprite.setRotation(angle);
	}
};