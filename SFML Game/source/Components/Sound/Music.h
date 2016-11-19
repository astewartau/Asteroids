#pragma once
#include "../Component.h"
#include "Managers/ResourceManager.h"

class Music : public Component {
public:
	Music(ResourceManager* resourceManager) {
		_resourceManager = resourceManager;
	}

	virtual void Init() {
		Play();
	}

	void Update(sf::Int32 deltaTime) {}
	virtual void ReceiveMessage(GameObject* sender, int message) {}

	~Music() {}
protected:
	void Play() {
		_music->play();
	}
	ResourceManager* _resourceManager;
	sf::Music* _music;
};