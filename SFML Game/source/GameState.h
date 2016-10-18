#pragma once
#include <SFML\Graphics.hpp>
#include "Structs.h"
#include "State.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Components\Controller\PlayerController.h"
#include "Components\Controller\AsteroidController.h"
#include "Components\Graphics\PlayerGraphics.h"
#include "Components\Graphics\AsteroidGraphics.h"
#include "Components\Physics\AsteroidsPhysics.h"




class GameState : public State {
public:
	GameState(sf::RenderWindow* window) : State(window) {
		srand(time(NULL));

		_objects.push_back(new GameObject({
			new PlayerController(),
			new PlayerGraphics(),
			new AsteroidsPhysics(_window->getSize(), sf::Vector2f{ _window->getSize().x / 2.0f, 
																  _window->getSize().y / 2.0f })
		}));

		for (int i = 0; i < 5; i++) {
			_objects.push_back(new GameObject({
				new AsteroidGraphics(),
				new AsteroidsPhysics(_window->getSize()),
				new AsteroidController()
			}));
		}
		
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
			case sf::Event::EventType::MouseButtonPressed:
				InputManager::GetInstance().PressMouse((MouseButton)event.mouseButton.button);
				break;
			case sf::Event::EventType::MouseButtonReleased:
				InputManager::GetInstance().ReleaseMouse((MouseButton)event.mouseButton.button);
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