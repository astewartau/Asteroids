#include "Player.h"

Player::Player(tmx::MapObject * object) {
	_object = object;
}

sf::Vector2f Player::GetPosition() {
	auto aabb = _object->GetPosition();
	return sf::Vector2f{ aabb.x + 16, aabb.y + 32 };
}

void Player::SetGrounded(bool grounded) {
	_grounded = grounded;
	_yVelocity = 0;
}

tmx::MapObject * Player::GetObject() {
	return _object;
}

void Player::Update() {
	_object->Move(_xVelocity, _yVelocity);
	if (!_grounded && _yVelocity <= 10) {
		_yVelocity += 1;
	}
}
