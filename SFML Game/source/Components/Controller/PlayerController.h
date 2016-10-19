#pragma once
#include "../../InputManager.h"
#include "Controller.h"
#include "../../GameState.h"
#include "../Graphics/BulletGraphics.h"
#include "../Physics/AsteroidsPhysics.h"
#include "../Destroyer.h"
#define _USE_MATH_DEFINES
#include <math.h>

class PlayerController : public Controller {
public:
	PlayerController(InputManager* inputManager) {
		_inputManager = inputManager;
		_speed = 0.0025f;
	}
	~PlayerController() {}
	void Init(GameObject* gameobject) {}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
		if (_inputManager->IsKeyPressed(Key::THRUST_LEFT)) {
			gameobject->_velocity += sf::Vector2f{ -_speed * deltaTime, 0.0f };
		}
		if (_inputManager->IsKeyPressed(Key::THRUST_RIGHT)) {
			gameobject->_velocity += sf::Vector2f{ _speed * deltaTime, 0.0f };
		}
		if (_inputManager->IsKeyPressed(Key::THRUST_UP)) {
			gameobject->_velocity += sf::Vector2f{ 0.0f, -_speed * deltaTime };
		}
		if (_inputManager->IsKeyPressed(Key::THRUST_DOWN)) {
			gameobject->_velocity += sf::Vector2f{ 0.0f, _speed * deltaTime };
		}

		sf::Vector2f playerPosition = gameobject->_sprite.getPosition();
		float opposite = playerPosition.x - _inputManager->GetMousePosition().x;
		float adjacent = playerPosition.y - _inputManager->GetMousePosition().y;
		float angle = atan2(adjacent, opposite) * 180 / M_PI - 90;
		gameobject->_sprite.setRotation(angle);
	}

private:
	InputManager* _inputManager;
	float _speed;
};