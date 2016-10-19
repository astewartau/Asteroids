#pragma once
#include "State.h"
#include "GameState.h"
#include "ResourceManager.h"
#include "InputManager.h"

class MenuState : public State {
public:
	MenuState(sf::RenderWindow* window) : State(window) {
		_titleText.setCharacterSize(50);
		_titleText.setFont(*_resourceManager.GetFont("assets/fonts/FreeMono.ttf"));
		_titleText.setString("Asteroids!");
		_titleText.setOrigin(_titleText.getLocalBounds().width / 2.0f, _titleText.getLocalBounds().height / 2.0f);
		_titleText.setPosition(window->getSize().x * 0.5f, window->getSize().y * 0.25f);


		_playText.setCharacterSize(25);
		_playText.setFont(*_resourceManager.GetFont("assets/fonts/FreeMono.ttf"));
		_playText.setString("Press enter to begin...");
		_playText.setOrigin(_titleText.getLocalBounds().width / 2.0f, _titleText.getLocalBounds().height / 2.0f);
		_playText.setPosition(window->getSize().x * 0.5f, window->getSize().y * 0.65f);
	}

	void HandleEvents() {
		sf::Event event;
		while (_window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::EventType::KeyPressed:
				_inputManager.PressKey((Key)event.key.code);
				break;
			}
		}
	}

	void Update(sf::Int32 deltaTime) {
		if (_inputManager.IsKeyPressed(Key::RETURN)) {
			_nextState = new GameState(_window);
		}
	}

	void DrawState() {
		_window->draw(_playText);
		_window->draw(_titleText);
	}
private:
	enum FontNames { TITLE, BUTTON };

	ResourceManager _resourceManager;
	InputManager _inputManager;

	sf::Text _titleText;
	sf::Text _playText;
};