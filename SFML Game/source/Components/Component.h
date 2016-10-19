#pragma once
#include "../GameObject.h"

class GameObject; 
class Component {
public:
	virtual ~Component() {
		printf("Component destroyed\n");
	};
	virtual void Init(GameObject* gameobject) = 0;
	virtual void Update(GameObject* gameobject, sf::Int32 deltaTime) = 0;
private:
	
};

