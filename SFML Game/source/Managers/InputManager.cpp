#include "InputManager.h"

sf::Vector2u InputManager::GetMousePosition() {
	return _mousePosition;
}

void InputManager::MoveMouse(sf::Vector2u position) {
	_mousePosition = position;
}

void InputManager::PressMouse(MouseButton button) {
	_mouseStates[button] = true;
}

void InputManager::ReleaseMouse(MouseButton button) {
	_mouseStates[button] = false;
}

void InputManager::PressKey(Key key) {
	_keyStates[key] = true;
}

void InputManager::ReleaseKey(Key key) {
	_keyStates[key] = false;
}

void InputManager::ReleaseAllKeys() {
	for (auto it = _keyStates.begin(); it != _keyStates.end(); ++it) {
		it->second = false;
	}
}

bool InputManager::IsKeyPressed(Key key) {
	if (_keyStates.find(key) == _keyStates.end()) {
		_keyStates[key] = false;
	}
	return _keyStates[key];
}

bool InputManager::IsMousePressed(MouseButton button) {
	if (_mouseStates.find(button) == _mouseStates.end()) {
		_mouseStates[button] = false;
	}
	return _mouseStates[button];
}

bool* InputManager::GetKeyRef(Key key) {
	if (_keyStates.find(key) == _keyStates.end()) {
		return &_keyStates[key];
	}
	return nullptr;
}
