#pragma once
#include <SFML\Graphics.hpp>

class GameObject : public sf::Drawable {
public:
	GameObject(sf::Texture* texture) {
		// Set the sprite to use the given texture
		_sprite.setTexture(*texture);

		// Set the origin to the centre of the sprite
		auto bounds = _sprite.getLocalBounds();
		_sprite.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);

		// Set the initial velocity to zero
		_xVelocity = 0.0f;
		_yVelocity = 0.0f;
	}
	virtual void Update(sf::Vector2i world) {
		_sprite.move(_xVelocity, _yVelocity);
		sf::Vector2f position = _sprite.getPosition();
		if (position.x < 0) {
			_sprite.setPosition(world.x, position.y);
		} else if (position.x > world.x) {
			_sprite.setPosition(0, position.y);
		}

		if (position.y < 0) {
			_sprite.setPosition(position.x, world.y);
		} else if (position.y > world.y) {
			_sprite.setPosition(position.x, 0);
		}
	}
	void Accelerate(float xAccel, float yAccel) {
		_xVelocity += xAccel;
		_yVelocity += yAccel;
	}
	sf::Vector2f GetPosition() {
		return _sprite.getPosition();
	}
protected:
	sf::Sprite _sprite;
	float _xVelocity, _yVelocity;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(_sprite, states);
	}
};