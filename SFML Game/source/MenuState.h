#pragma once
#include "State.h"
#include "ResourceManager.h"

class MenuState : public State {
public:
	MenuState(sf::RenderWindow* window) : State(window) {
		_resourceManager = new ResourceManager();
		_resourceManager->AddFont(TITLE, "assets/fonts/FreeMono.ttf");
		_resourceManager->AddFont(BUTTON, "assets/fonts/FreeMono.ttf");

		_titleText.setCharacterSize(50);
		_titleText.setFont(*_resourceManager->GetFont(TITLE));
		_titleText.setString("Asteroids!");
		_titleText.setOrigin(_titleText.getLocalBounds().width / 2.0f, _titleText.getLocalBounds().height / 2.0f);
		_titleText.setPosition(window->getSize().x * 0.5f, window->getSize().y * 0.25f);
	}

	void HandleEvent(sf::Event evt) {
		if (evt.type == sf::Event::EventType::KeyPressed) {
			if (evt.key.code == sf::Keyboard::Return) {
				printf("Start game!");
			}
		}
	}

	void Update(sf::Int32 deltaTime) {

	}

	void Draw() {
		_window->draw(_playText);
		_window->draw(_titleText);
	}
private:
	enum FontNames { TITLE, BUTTON };

	ResourceManager* _resourceManager;

	sf::Text _titleText;
	sf::Text _playText;
};