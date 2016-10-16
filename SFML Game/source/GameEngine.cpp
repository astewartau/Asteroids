#include "GameEngine.h"
#include "GameState.h"
#include <cstdio>

GameEngine::GameEngine() {
	_quit = false;
}

void GameEngine::Go() {
	Init();
	SetupGame();
	GameLoop();
}

void GameEngine::Init() {
	_window.create(sf::VideoMode(800, 600), "Game", sf::Style::Close);
}

void GameEngine::SetupGame() {
	_states.push_back(new GameState(&_window));
}

void GameEngine::GameLoop() {
	while (!_quit) {
		StartLoop();
		ProcessInput();
		Update(_clock.restart().asMilliseconds());
		Draw();
		EndLoop();
	}
}

void GameEngine::StartLoop() {

}

void GameEngine::Update(sf::Int32 deltaTime) {
	_states.back()->Update(deltaTime);
}

void GameEngine::Draw() {
	_window.clear();
	_states.back()->Draw();
	_window.display();
}

void GameEngine::EndLoop() {
	sf::sleep(sf::Time(sf::milliseconds(5)));
}

void GameEngine::ProcessInput() {
	sf::Event evt;
	while (_window.pollEvent(evt)) {
		switch (evt.type) {
		case sf::Event::Closed:
			_window.close();
			_quit = true;
			break;
		default:
			if (_window.hasFocus()) {
				_states.back()->HandleEvent(evt);
			}
			break;
		}
	}
}