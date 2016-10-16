#include "InputManager.h"

sf::Vector2u InputManager::GetMousePosition() {
	return _mousePosition;
}

void InputManager::MoveMouse(sf::Vector2u position) {
	_mousePosition = position;
}

void InputManager::PressKey(Key key) {
	_inputStates[key] = true;
}

void InputManager::ReleaseKey(Key key) {
	_inputStates[key] = false;
}

void InputManager::ReleaseAllKeys() {
	for (auto it = _inputStates.begin(); it != _inputStates.end(); ++it) {
		it->second = false;
	}
}

bool InputManager::IsKeyPressed(Key key) {
	if (_inputStates.find(key) == _inputStates.end()) {
		_inputStates[key] = false;
	}
	return _inputStates[key];
}