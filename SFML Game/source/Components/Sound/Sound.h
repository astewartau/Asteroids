#pragma once
#include "../Component.h"
#include "Managers/ResourceManager.h"

class Sound : public Component {
public:
	Sound(ResourceManager* resourceManager) {
		_resourceManager = resourceManager;
	}

	void Init() {}
	void Update(sf::Int32 deltaTime) {}
	virtual void ReceiveMessage(GameObject* sender, int message) {}

	~Sound() {}
protected:
	void Play() {
		_sound->play();
	}
	ResourceManager* _resourceManager;
	sf::Sound* _sound;
};