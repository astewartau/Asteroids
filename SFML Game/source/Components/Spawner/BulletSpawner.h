#pragma once
#include "SpawnerComponent.h"
#include "States\GameState.h"

#include "../Graphics/BulletGraphics.h"
#include "../Physics/AsteroidsPhysics.h"
#include "../Destroyer.h"

class BulletSpawner : public SpawnerComponent {
public:
	BulletSpawner(GameState* state, ResourceManager* resourceManager) {
		_state = state;
		_resourceManager = resourceManager;
		_firstShot = true;
	}

	void Spawn() {
		if ((_clock.getElapsedTime() >= SPAWN_COOLDOWN) || (_firstShot)) {
			_clock.restart();
			_firstShot = false;

			GameObject* laser = new GameObject({
				new AsteroidsPhysics(_state->GetBounds()),
				new Destroyer(BULLET_LIFE, _state),
				new BulletGraphics(_resourceManager),
			});

			laser->_sprite.setPosition(_gameObject->_sprite.getPosition());
			laser->_sprite.setRotation(_gameObject->_sprite.getRotation());

			Vec3<float> velocity;
			velocity.SetMagnitude(BULLET_SPEED);
			velocity.SetDirection(_gameObject->_sprite.getRotation() - 90);

			laser->_velocity = { velocity.GetX(), velocity.GetY() };

			_state->AddObject(laser);
		}
	}

	void ReceiveMessage(int message) {
		if (message == GameObject::EventCode::SPAWN) {
			Spawn();
		}
	}
private:

	bool _firstShot;
	const sf::Time SPAWN_COOLDOWN = sf::seconds(0.15);
	const sf::Time BULLET_LIFE = sf::seconds(0.35);
	const float BULLET_SPEED = 1.0f;
	ResourceManager* _resourceManager;
	GameState* _state;
	sf::Clock _clock;
};