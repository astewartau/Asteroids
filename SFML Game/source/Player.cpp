#include "Player.h"

Player::Player(sf::Vector2f position) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("assets/textures/p1_front.png");
	_sprite = new sf::Sprite(*texture);
	_sprite->setOrigin(_sprite->getGlobalBounds().width / 2.0f, _sprite->getGlobalBounds().height);
	_sprite->setPosition(position);
}

sf::Vector2f Player::GetPosition() {
	return _sprite->getPosition();
}

bool Player::Grounded() {
	return _grounded;
}

void Player::SetPosition(float x, float y) {
	_sprite->setPosition(x, y);
}

void Player::SetGrounded(bool grounded) {
	_grounded = grounded;
	_yVelocity = 0;
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(*_sprite);
}

void Player::Update() {
	_sprite->move(_xVelocity, _yVelocity);
	if (!_grounded && _yVelocity <= 10) {
		_yVelocity += 1;
	} else if (_grounded) {
		_yVelocity = 0;
	}
}
