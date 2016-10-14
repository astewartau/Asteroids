#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "InputManager.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Player : public GameObject {
public:
	Player(sf::Texture* texture) : GameObject(texture) {
		_health = 10;
	}
	void Update(sf::Vector2i world) {
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_U)) {
			Accelerate(0, -0.1);
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_L)) {
			Accelerate(-0.1, 0);
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_D)) {
			Accelerate(0, 0.1);
		}
		if (InputManager::GetInstance().IsKeyPressed(Key::THRUST_R)) {
			Accelerate(0.1, 0);
		}
		LookAt(InputManager::GetInstance().GetMousePosition());
		GameObject::Update(world);
	}
private:
	int _health;

	void LookAt(sf::Vector2i location) {
		sf::Vector2f playerPosition = _sprite.getPosition();
		float opposite = playerPosition.x - location.x;
		float adjacent = playerPosition.y - location.y;
		float angle = atan2(adjacent, opposite) * 180 / M_PI - 90;
		_sprite.setRotation(angle);
	}
};