#include "GameState.h"

#include "Helpers\Structs.h"
#include "Managers\InputManager.h"

void GameState::AddObject(GameObject* object) {
	_objects.push_back(object);
}

sf::Vector2u GameState::GetBounds() {
	return _window->getSize();
}

void GameState::QueueDeleteObject(GameObject * object) {
	_deleteQueue.push_back(object);
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
	for (size_t i = 0; i < _objects.size(); i++) {
		_objects[i]->Update(deltaTime);
	}

	for (size_t i = 0; i < _deleteQueue.size(); i++) {
		_objects.erase(std::remove(_objects.begin(), _objects.end(), _deleteQueue[i]), _objects.end());
		delete _deleteQueue[i];
	}
	_deleteQueue.clear();
}

void GameState::DrawState() {
	for (GameObject* object : _objects) {
		_window->draw(*object);
	}
}

GameState::~GameState() {
	for (size_t i = 0; i < _objects.size(); i++) {
		delete _objects[i];
	}

	for (size_t i = 0; i < _deleteQueue.size(); i++) {
		delete _deleteQueue[i];
	}
}