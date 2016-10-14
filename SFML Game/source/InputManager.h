#pragma once
#include <map>
#include <SFML\Window.hpp>

enum Key {
	THRUST_L = sf::Keyboard::Key::A,
	THRUST_R = sf::Keyboard::Key::D,
	THRUST_U = sf::Keyboard::Key::W,
	THRUST_D = sf::Keyboard::Key::S,
	ACTION = sf::Keyboard::Key::Return
};

enum Mouse {
	FIRE = sf::Mouse::Button::Left
};

class InputManager {
public:
	sf::Vector2i GetMousePosition();
	void MoveMouse(sf::Vector2i position);
	void PressKey(Key key);
	void ReleaseKey(Key key);
	void ReleaseAllKeys();
	bool IsKeyPressed(Key key);
private:
	sf::Vector2i _mousePosition;
	std::map<Key, bool> _inputStates;


// SINGLETON
public:
	static InputManager& GetInstance() {
		static InputManager instance;
		return instance;
	}
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;
private:
	InputManager() {
		_mousePosition = sf::Vector2i{ 0,0 };
	}
};