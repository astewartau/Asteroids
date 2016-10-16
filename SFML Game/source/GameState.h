#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
#include "InputManager.h"
#include "GameObject.h"
#include "PlayerController.h"
#include "PlayerGraphics.h"
#include "AsteroidsPhysics.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* window) : State(window) {
		_objects.push_back(new GameObject({
			new PlayerController(),
			new PlayerGraphics(),
			new AsteroidsPhysics(window->getSize())
		}));
	}

	void HandleEvent(sf::Event evt) {
		switch (evt.type) {
		case sf::Event::EventType::KeyPressed:
			InputManager::GetInstance().PressKey((Key)evt.key.code);
			break;
		case sf::Event::EventType::KeyReleased:
			InputManager::GetInstance().ReleaseKey((Key)evt.key.code);
			break;
		case sf::Event::EventType::MouseMoved:
			InputManager::GetInstance().MoveMouse(sf::Vector2u{ (unsigned int)evt.mouseMove.x, (unsigned int)evt.mouseMove.y });
			break;
		}
	}

	void Update(sf::Int32 deltaTime) {
		for (GameObject* object : _objects) {
			object->Update(deltaTime);
		}
	}

	void Draw() {
		for (GameObject* object : _objects) {
			_window->draw(*object);
		}
	}
private:
	std::vector<GameObject*> _objects;
};