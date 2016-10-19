#pragma once
#include "Component.h"
#include "../GameState.h"

class Destroyer : public Component {
public:
	Destroyer(sf::Time life, GameState* state) { 
		_life = life;
		_state = state;
	}

	~Destroyer() { }

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {
		if (_clock.getElapsedTime() > _life) {
			_state->QueueDeleteObject(gameobject);
		}
	}

	void Init(GameObject* gameobject) {
		_clock.restart();
	}
private:
	sf::Time _life;
	sf::Clock _clock;
	GameState* _state;
};