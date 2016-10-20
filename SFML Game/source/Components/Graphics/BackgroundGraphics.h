#pragma once
#include "GraphicsComponent.h"

class BackgroundGraphics : public GraphicsComponent {
public:
	BackgroundGraphics(ResourceManager* resourceManager, sf::Vector2u bounds) : GraphicsComponent(resourceManager) { 
		_bounds = bounds;
	}
	~BackgroundGraphics() {}
	void Init(GameObject* gameobject) {
		sf::Texture* texture = _resourceManager->GetTexture("assets/textures/blue.png");
		texture->setRepeated(true);
		gameobject->_sprite.setTexture(*texture);
		gameobject->_sprite.setTextureRect(sf::IntRect{ 0,0,(int)_bounds.x,(int)_bounds.y });
	}

	void Update(GameObject* gameobject, sf::Int32 deltaTime) {

	}
private:
	sf::Vector2u _bounds;
};