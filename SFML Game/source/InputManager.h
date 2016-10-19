#pragma once
#include <map>
#include <SFML\Window.hpp>

enum Key {
	THRUST_LEFT = sf::Keyboard::Key::A,
	THRUST_RIGHT = sf::Keyboard::Key::D,
	THRUST_UP = sf::Keyboard::Key::W,
	THRUST_DOWN = sf::Keyboard::Key::S,
	ACTION = sf::Keyboard::Key::Return
};

enum MouseButton {
	FIRE = sf::Mouse::Button::Left
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
private:
	sf::Vector2u _mousePosition;
	std::map<Key, bool> _keyStates;
	std::map<MouseButton, bool> _mouseStates;
};