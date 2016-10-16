#pragma once
#include <SFML\Graphics.hpp>

class GameObject : public sf::Drawable {
public:
	GameObject(sf::Texture* texture, sf::Vector2u playArea) {
		_playArea = playArea;

		// Set the sprite to use the given texture
		_sprite.setTexture(*texture);

		// Set the origin to the centre of the sprite
		auto bounds = _sprite.getLocalBounds();
		_sprite.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);

		// Set the initial velocity to zero
		_velocity.x = 0;
		_velocity.y = 0;
	}
	virtual void Update(sf::Time deltaTime) {
		_sprite.move(_velocity);
		sf::Vector2f position = _sprite.getPosition();
		if (position.x < 0) {
			_sprite.setPosition(_playArea.x, position.y);
		} else if (position.x > _playArea.x) {
			_sprite.setPosition(0, position.y);
		}

		if (position.y < 0) {
			_sprite.setPosition(position.x, _playArea.y);
		} else if (position.y > _playArea.y) {
			_sprite.setPosition(position.x, 0);
		}
	}
	void Accelerate(sf::Vector2f accel) {
		_velocity += accel;
	}
	sf::Vector2f GetPosition() {
		return _sprite.getPosition();
	}
protected:
	sf::Vector2u _playArea;
	sf::Sprite _sprite;
	sf::Vector2f _velocity;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(_sprite, states);
	}
};