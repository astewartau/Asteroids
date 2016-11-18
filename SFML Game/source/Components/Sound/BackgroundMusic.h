#pragma once
#include "Music.h"

class BackgroundMusic : public Music {
public:
	BackgroundMusic(ResourceManager* resourceManager) : Music(resourceManager) {
		_music = _resourceManager->GetMusic("assets/music/through space.ogg");
	}
};