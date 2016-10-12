#pragma once
#include <SFML\Graphics.hpp>
#include <tmx\MapObject.h>

class Player {
public:
	Player(tmx::MapObject* object);
	sf::Vector2f GetPosition();
	void Update();
	void SetGrounded(bool grounded);
	tmx::MapObject* GetObject();
private:
	tmx::MapObject* _object;
	bool _grounded;
	float _xVelocity, _yVelocity;
};