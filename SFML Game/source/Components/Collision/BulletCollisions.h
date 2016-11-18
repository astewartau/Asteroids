#pragma once
#include "States\GameState.h"
#include "..\Component.h"

class BulletCollisions : public Component {
public:
	BulletCollisions(GameState* state) {
		_state = state;
	}

	void Init() {
	}
	
	void Update(sf::Int32 deltaTime) {
		auto collisions = _state->GetCollisions();

		auto it = std::find_if(collisions.begin(), collisions.end(), 
			[this](const std::pair<GameObject*, GameObject*>& element) { 
				return element.first == _gameObject || element.second == _gameObject;
			}
		);

		if (it != collisions.end()) {
			it->first->SendMessage(GameObject::EventCode::BULLET_COLLISION);
			it->second->SendMessage(GameObject::EventCode::BULLET_COLLISION);
		}
	}

	void ReceiveMessage(int message) {

	}

	~BulletCollisions() {

	}
private:
	GameState* _state;
};