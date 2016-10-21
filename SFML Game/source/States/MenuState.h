#pragma once
#include "State.h"
#include "AsteroidsGame.h"
#include "Managers\ResourceManager.h"
#include "Managers\InputManager.h"

class MenuState : public State {
public:
	MenuState(sf::RenderWindow* window) : State(window) {
		_titleText.setCharacterSize(75);
		_titleText.setFont(*_resourceManager.GetFont("assets/fonts/FreeMono.ttf"));
		_titleText.setString("Asteroids!");
		_titleText.setOrigin(_titleText.getLocalBounds().width / 2.0f, _titleText.getLocalBounds().height / 2.0f);
		_titleText.setPosition(window->getSize().x * 0.5f, window->getSize().y * 0.25f);

		_playText.setFont(*_resourceManager.GetFont("assets/fonts/FreeMono.ttf"));
		_playText.setCharacterSize(35);
		_playText.setString("Press enter to begin...");
		_playText.setOrigin(_playText.getLocalBounds().width / 2.0f, _playText.getLocalBounds().height / 2.0f);
		_playText.setPosition(window->getSize().x * 0.5f, window->getSize().y * 0.65f);

		_backgroundSprite.setTexture(*_resourceManager.GetTexture("assets/textures/back.png"));
		_startGame = _inputManager.GetKeyRef(Key::RETURN);
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
		if (*_startGame) {
			_nextState = new AsteroidsGame(_window);
		}
	}

	void DrawState() {
		_window->draw(_backgroundSprite);
		_window->draw(_playText);
		_window->draw(_titleText);
	}
private:
	enum FontNames { TITLE, BUTTON };

	ResourceManager _resourceManager;
	InputManager _inputManager;
	bool* _startGame;

	sf::Sprite _backgroundSprite;
	sf::Text _titleText;
	sf::Text _playText;
};