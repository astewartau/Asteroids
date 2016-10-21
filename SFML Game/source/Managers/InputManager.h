#pragma once
#include <map>
#include <SFML\Window.hpp>

enum Key {
	A = sf::Keyboard::Key::A,
	D = sf::Keyboard::Key::D,
	W = sf::Keyboard::Key::W,
	S = sf::Keyboard::Key::S,
	RETURN = sf::Keyboard::Key::Return
};

enum MouseButton {
	LEFT = sf::Mouse::Button::Left
};

class InputManager {
public:
	InputManager() {}
	sf::Vector2u GetMousePosition();
	void MoveMouse(sf::Vector2u position);
	void PressMouse(MouseButton button);
	void ReleaseMouse(MouseButton button);
	void PressKey(Key key);
	void ReleaseKey(Key key);
	void ReleaseAllKeys();
	bool IsKeyPressed(Key key);
	bool IsMousePressed(MouseButton button);
	bool* GetKeyRef(Key key);
private:
	sf::Vector2u _mousePosition;
	std::map<Key, bool> _keyStates;
	std::map<MouseButton, bool> _mouseStates;
};