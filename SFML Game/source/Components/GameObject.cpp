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
		component->Update(deltaTime);
	}
}

void GameObject::SendMessage(int message) {
	for (size_t i = 0; i < _components.size(); i++) {
		_components[i]->ReceiveMessage(message);
	}
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite);
}

GameObject::~GameObject() {
	for (size_t i = 0; i < _components.size(); i++) {
		delete _components[i];
	}
}