#pragma once
#include "SpawnerComponent.h"
#include "States\GameState.h"

#include "../Graphics/BulletGraphics.h"
#include "../Physics/SpacePhysics.h"
#include "../Physics/TorusLimiter.h"
#include "../Collision/BulletCollisions.h"
#include "../Sound/BulletSound.h"
#include "../Timed/Destroyer.h"

class BulletSpawner : public SpawnerComponent {
public:
	BulletSpawner(GameState* state, ResourceManager* resourceManager) {
		_state = state;
		_resourceManager = resourceManager;
	}

	void Spawn() {
		GameObject* laser = new GameObject({
			new Destroyer(BULLET_LIFE, _state),
			new SpacePhysics(),
			new BulletCollisions(_state),
			new TorusLimiter(_state->GetBounds()),
			new BulletGraphics(_resourceManager),
		});

		laser->_sprite.setPosition(_gameObject->_sprite.getPosition());
		laser->_sprite.setRotation(_gameObject->_sprite.getRotation());

		Vec2<float> velocity;
		velocity.SetMagnitude(BULLET_SPEED);
		velocity.SetDirection(_gameObject->_sprite.getRotation() - 90);

		laser->_velocity = { velocity.GetX(), velocity.GetY() };
		_state->AddObject(laser);
	}

	void ReceiveMessage(int message) {
		if (message == GameObject::EventCode::SHOOT) {
			Spawn();
		}
	}
private:
	const sf::Time BULLET_LIFE = sf::seconds(0.35f);
	const float BULLET_SPEED = 1.0f;
	ResourceManager* _resourceManager;
	GameState* _state;
};