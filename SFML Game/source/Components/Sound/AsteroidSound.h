#pragma once
#include "Sound.h"

class AsteroidSound : public Sound {
public:
	AsteroidSound(ResourceManager* resourceManager) : Sound(resourceManager) {
		_sound = _resourceManager->GetSound("assets/sounds/sfx_exp_short_hard8.wav");
	}

	void ReceiveMessage(GameObject* sender, int message) {
		if (message == GameObject::EventCode::BULLET_COLLISION) {
			Play();
		}
	}
};