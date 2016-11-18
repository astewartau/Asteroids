#pragma once
#include "Sound.h"

class BulletSound : public Sound {
public:
	BulletSound(ResourceManager* resourceManager) : Sound(resourceManager) {
		_sound = _resourceManager->GetSound("assets/sounds/sfx_wpn_laser6.wav");
	}

	void ReceiveMessage(int message) {
		if (message == GameObject::EventCode::SHOOT) {
			Play();
		}
	}
};