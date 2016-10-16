#pragma once
#include "GameObject.h"

GameObject::GameObject(std::vector<Component*> components) {
	_components = components;
	for (Component* component : _components) {
		component->Init(this);
	}
}

void GameObject::Update(sf::Int32 deltaTime) {
	for (Component* component : _components) {
		component->Update(this, deltaTime);
	}
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite);
}