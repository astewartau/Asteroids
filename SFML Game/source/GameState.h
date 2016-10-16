#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
#include "Player.h"
#include "InputManager.h"
#include "ResourceManager.h"


class GameState : public State {
public:
	GameState(sf::RenderWindow* window) : State(window) {
		_textureManager = new ResourceManager();
		_textureManager->AddTexture(PLAYER, "assets/textures/playerShip1_blue.png");
		_textureManager->AddTexture(CURSOR, "assets/textures/Ardentryst-target2.png");
		_textureManager->AddTexture(BACKGROUND, "assets/textures/blue.png");

		_objects.push_back(new Player(_textureManager->GetTexture(PLAYER), _window->getSize()));
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

	void Update(sf::Time deltaTime) {
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
	enum TextureName { PLAYER, CURSOR, BACKGROUND };
	std::vector<GameObject*> _objects;
	ResourceManager* _textureManager;
};