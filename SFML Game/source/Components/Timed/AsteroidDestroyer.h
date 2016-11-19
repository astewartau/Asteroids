#pragma once
#include "..\Component.h"
#include "States\GameState.h"

#include "../Physics/SpacePhysics.h"
#include "../Physics/TorusLimiter.h"
#include "../Graphics/AsteroidGraphics.h"
#include "../Controller/AsteroidController.h"
#include "../Timed/AsteroidDestroyer.h"
#include "../Sound/AsteroidSound.h"

class AsteroidDestroyer : public Component {
public:
	AsteroidDestroyer(GameState* state) {
		_state = state;
	}

	void Update(sf::Int32 deltaTime) {

	}

	void ReceiveMessage(GameObject* sender, int message) {
		if (message == GameObject::EventCode::BULLET_COLLISION) {
			if (_gameObject->_sprite.getScale().x > 0.2) {
				Spawn();
			}

			_state->QueueDeleteObject(_gameObject);
			_state->QueueDeleteObject(sender);
		}
	}

private:
	GameState* _state;

	void Spawn() {
		sf::Vector2u bounds = _state->GetBounds();

		// Create asteroid object
		GameObject* newAsteroid = new GameObject({
			new AsteroidDestroyer(_state),
			new AsteroidSound(_state->GetResourceManager()),
			new AsteroidController(),
			new SpacePhysics(),
			new TorusLimiter(bounds),
			new AsteroidGraphics(_state->GetResourceManager())
		});

		// Generate random initial velocity
		Vec2<float> velocity;
		velocity.SetMagnitude(RandFloat(0.1, 0.1));
		velocity.SetDirection((float)RandInt(1, 360));

		// Set asteroid position and velocity
		newAsteroid->_sprite.setPosition(_gameObject->_sprite.getPosition());
		newAsteroid->_sprite.setScale(sf::Vector2f{ _gameObject->_sprite.getScale().x * 0.5f, _gameObject->_sprite.getScale().y * 0.5f });
		newAsteroid->_velocity = { velocity.GetX(), velocity.GetY() };

		// Add object to game state
		_state->AddObject(newAsteroid);
	}
};
