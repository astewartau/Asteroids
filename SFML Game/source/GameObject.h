#pragma once
#include <SFML\Graphics.hpp>
#include "Components\Component.h"

class Component;
class GameObject : public sf::Drawable {
public:
	GameObject(std::vector<Component*> components);
	~GameObject() {
		for (int i = 0; i < _components.size(); i++) {
			delete _components[i];
		}
	}

	void Update(sf::Int32 deltaTime);

	sf::Sprite _sprite;
	sf::Vector2f _velocity;
private:
	std::vector<Component*> _components;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};