#pragma once
#include "../Component.h"

class Controller : public Component {
public:
	~Controller() {}
	virtual void Update(GameObject* gameobject, sf::Int32 deltaTime) = 0;
private:

};

