#include "StateRunner.h"
#include "States\MenuState.h"

void StateRunner::Go() {
	Init();
	SetupGame();
	GameLoop();
	CleanUp();
}

void StateRunner::Init() {
	_window.create(sf::VideoMode(800, 600), "Game", sf::Style::Close);
}

void StateRunner::SetupGame() {
	_currentState = new MenuState(&_window);
}

void StateRunner::GameLoop() {
	while (_currentState != nullptr) {
		_currentState = _currentState->Run();
	}
}

void StateRunner::CleanUp() {
	_window.close();
}