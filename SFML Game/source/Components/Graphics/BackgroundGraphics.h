#pragma once
#include "GraphicsComponent.h"

class BackgroundGraphics : public GraphicsComponent {
public:
	BackgroundGraphics(ResourceManager* resourceManager, sf::Vector2u bounds) : GraphicsComponent(resourceManager) { 
		_bounds = bounds;
	}

	void Init() {
		sf::Texture* texture = _resourceManager->GetTexture("assets/textures/back.png");
		texture->setRepeated(true);
		_gameObject->_sprite.setTexture(*texture);
		_gameObject->_sprite.setTextureRect(sf::IntRect{ 0,0,(int)_bounds.x,(int)_bounds.y });
	}
private:
	sf::Vector2u _bounds;
};