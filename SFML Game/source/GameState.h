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

	void HandleEvents() {
		sf::Event event;
		while (_window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::EventType::Closed:
				_nextState = nullptr;
				break;
			case sf::Event::EventType::KeyPressed:
				InputManager::GetInstance().PressKey((Key)event.key.code);
				break;
			case sf::Event::EventType::KeyReleased:
				InputManager::GetInstance().ReleaseKey((Key)event.key.code);
				break;
			case sf::Event::EventType::MouseMoved:
				InputManager::GetInstance().MoveMouse(sf::Vector2u{ (unsigned int)event.mouseMove.x, (unsigned int)event.mouseMove.y });
				break;
			}
		}
	}

	void Update(sf::Int32 deltaTime) {
		for (GameObject* object : _objects) {
			object->Update(deltaTime);
		}
	}

	void DrawState() {
		for (GameObject* object : _objects) {
			_window->draw(*object);
		}
	}
private:
	std::vector<GameObject*> _objects;
};