#pragma once
#include <SFML\Graphics.hpp>
#include "Component.h"

class Component;
class GameObject : public sf::Drawable {
public:
	enum EventCode { SPAWN, BULLET_COLLISION, SHOOT };

	GameObject(std::vector<Component*> components);
	~GameObject();

	void Update(sf::Int32 deltaTime);
	void SendMessage(int message);

	sf::Sprite _sprite;
	sf::Vector2f _velocity;
private:
	std::vector<Component*> _components;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};