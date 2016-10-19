#pragma once
#include "../Component.h"

class ControllerComponent : public Component {
public:
	~ControllerComponent() {}
	virtual void Update(GameObject* gameobject, sf::Int32 deltaTime) = 0;
private:

};

