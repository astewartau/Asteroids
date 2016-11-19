#include "GameState.h"

#include "Helpers\Structs.h"
#include "Managers\InputManager.h"
#include "Managers\Collision.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {
	_collisions = std::map<GameObject*, GameObject*>();
}

void GameState::AddObject(GameObject* object) {
	_objects.push_back(object);
}

sf::Vector2u GameState::GetBounds() {
	return _window->getSize();
}

ResourceManager *GameState::GetResourceManager() {
	return &_resourceManager;
}

std::map<GameObject*, GameObject*> GameState::GetCollisions() {
	return _collisions;
}

void GameState::QueueDeleteObject(GameObject * object) {
	if (std::find(_deleteQueue.begin(), _deleteQueue.end(), object) == _deleteQueue.end()) {
		_deleteQueue.push_back(object);
	}
}

void GameState::UpdateCollisions() {
	_collisions.clear();

	for (unsigned int i = 0; i < _objects.size(); i++) {
		for (unsigned int j = i + 1; j < _objects.size(); j++) {
			if (Collision::CircleTest(_objects[i]->_sprite, _objects[j]->_sprite)) {
				_collisions.insert(std::make_pair(_objects[i], _objects[j]));
			}
		}
	}
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
	UpdateCollisions();

	for (size_t i = 0; i < _objects.size(); i++) {
		_objects[i]->Update(deltaTime);
	}

	for (GameObject* object : _deleteQueue) {
		_objects.erase(std::remove(_objects.begin(), _objects.end(), object), _objects.end());
		delete object;
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