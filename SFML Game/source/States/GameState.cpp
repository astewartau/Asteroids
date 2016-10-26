#include "GameState.h"

#include "Helpers\Structs.h"
#include "Managers\InputManager.h"

sf::Vector2u GameState::GetBounds() {
	return _window->getSize();
}

void GameState::HandleEvents() {
	sf::Event event;
	while (_window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::EventType::Closed:
			_nextState = nullptr;
			break;
		case sf::Event::EventType::KeyPressed:
			_inputManager.PressKey((Key)event.key.code);
			break;
		case sf::Event::EventType::KeyReleased:
			_inputManager.ReleaseKey((Key)event.key.code);
			break;
		case sf::Event::EventType::MouseMoved:
			_inputManager.MoveMouse(sf::Vector2u{ (unsigned int)event.mouseMove.x, (unsigned int)event.mouseMove.y });
			break;
		case sf::Event::EventType::MouseButtonPressed:
			_inputManager.PressMouse((MouseButton)event.mouseButton.button);
			break;
		case sf::Event::EventType::MouseButtonReleased:
			_inputManager.ReleaseMouse((MouseButton)event.mouseButton.button);
			break;
		}
	}
}

void GameState::Update(sf::Int32 deltaTime) {
}

void GameState::DrawState() {
}

GameState::~GameState() {
}