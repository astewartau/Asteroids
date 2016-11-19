#pragma once
#include "Components\GameObject.h"

class GameObject; 
class Component {
public:
	void Init(GameObject* gameObject) {
		_gameObject = gameObject;
		Init();
	};
	virtual void Init() {}
	virtual void Update(sf::Int32 deltaTime) = 0;
	virtual void ReceiveMessage(GameObject* sender, int message) {}
	virtual ~Component() { };
protected:
	GameObject* _gameObject;
};

