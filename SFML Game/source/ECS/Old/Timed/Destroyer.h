#pragma once
#include "..\Component.h"
#include "States\GameState.h"

class Destroyer : public Component {
public:
	Destroyer(sf::Time life, GameState* state) { 
		_life = life;
		_state = state;
	}

	void Update(sf::Int32 deltaTime) {
		if (_clock.getElapsedTime() > _life) {
			_state->QueueDeleteObject(_gameObject);
		}
	}

	void Init() {
		_clock.restart();
	}
private:
	sf::Time _life;
	sf::Clock _clock;
	GameState* _state;
};