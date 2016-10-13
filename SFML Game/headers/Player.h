#pragma once
#include <SFML\Graphics.hpp>

class Player : public sf::Drawable {
public:
	Player(sf::Vector2f position);
	sf::Vector2f GetPosition();
	bool Grounded();
	void SetPosition(float x, float y);
	void Update();
	void SetGrounded(bool grounded);
private:
	sf::Sprite* _sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool _grounded;
	float _xVelocity, _yVelocity;
};