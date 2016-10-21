#pragma once
#include "../Component.h"

class ControllerComponent : public Component {
public:
	virtual void Update(sf::Int32 deltaTime) {};
	virtual void Init() {};
};