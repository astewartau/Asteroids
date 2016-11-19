#pragma once
#include "ControllerComponent.h"

#include "Managers\InputManager.h"
#include "States\GameState.h"

#define _USE_MATH_DEFINES
#include <math.h>

class PlayerController : public ControllerComponent {
public:
	PlayerController(InputManager* inputManager) {
		_inputManager = inputManager;
		_firstShot = true;
	}

	void Init() {
		_thrustLeft = _inputManager->GetKeyRef(Key::A);
		_thrustRight = _inputManager->GetKeyRef(Key::D);
		_thrustUp = _inputManager->GetKeyRef(Key::W);
		_thrustDown = _inputManager->GetKeyRef(Key::S);
	}

	void Update(sf::Int32 deltaTime) {
		if (*_thrustLeft) {
			_gameObject->_velocity += sf::Vector2f{ -ACCEL_SPEED * deltaTime, 0.0f };
		} else if (*_thrustRight) {
			_gameObject->_velocity += sf::Vector2f{ ACCEL_SPEED * deltaTime, 0.0f };
		}

		if (*_thrustUp) {
			_gameObject->_velocity += sf::Vector2f{ 0.0f, -ACCEL_SPEED * deltaTime };
		} else if (*_thrustDown) {
			_gameObject->_velocity += sf::Vector2f{ 0.0f, ACCEL_SPEED * deltaTime };
		}

		if (_inputManager->IsMousePressed(MouseButton::LEFT)) {
			if ((_clock.getElapsedTime() >= SPAWN_COOLDOWN) || (_firstShot)) {
				_clock.restart();
				_firstShot = false;
				_gameObject->SendMessage(_gameObject, GameObject::EventCode::SHOOT);
			}
		}

		sf::Vector2f playerPosition = _gameObject->_sprite.getPosition();
		float opposite = playerPosition.x - _inputManager->GetMousePosition().x;
		float adjacent = playerPosition.y - _inputManager->GetMousePosition().y;
		float angle = atan2(adjacent, opposite) * (float)(180 / M_PI) - 90.0f;
		_gameObject->_sprite.setRotation(angle);
	}

private:
	bool *_thrustLeft, *_thrustRight, *_thrustUp, *_thrustDown;

	InputManager* _inputManager;
	const float ACCEL_SPEED = 0.002f;

	bool _firstShot;
	const sf::Time SPAWN_COOLDOWN = sf::seconds(0.15f);
	sf::Clock _clock;

};