#pragma once
#include "..\Component.h"
#include "States\GameState.h"

class AsteroidDestroyer : public Component {
public:
	AsteroidDestroyer(GameState* state) {
		_state = state;
	}

	void Update(sf::Int32 deltaTime) {}

	void ReceiveMessage(int message) {
		if (message == GameObject::EventCode::BULLET_COLLISION) {
			_state->QueueDeleteObject(_gameObject);
		}
	}
private:
	GameState* _state;
};
