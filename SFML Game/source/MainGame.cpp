#include "MainGame.h"
#include <cstdio>

#define _USE_MATH_DEFINES
#include <math.h>

MainGame::MainGame() {
	_quit = false;
}

void MainGame::Go() {
	InitSystems();
	SetupGame();
	GameLoop();
}

void MainGame::InitSystems() {
	printf("Creating window...");
	_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close);
	printf("Done!\n");
}

void MainGame::SetupGame() {
	printf("Setting up game...");

	/////// TEMPORARY
	//_window.setMouseCursorVisible(false);

	_textureManager = new TextureManager();
	_textureManager->AddTexture(PLAYER, "assets/textures/playerShip1_blue.png");
	_textureManager->AddTexture(CURSOR, "assets/textures/Ardentryst-target2.png");
	_textureManager->AddTexture(BACKGROUND, "assets/textures/blue.png");

	// Load player
	_player = new Player(_textureManager->GetTexture(PLAYER));

	printf("Done!\n");
}

void MainGame::GameLoop() {
	printf("Success! Game running\n");
	while (!_quit) {
		StartLoop();
		ProcessInput();
		Update();
		Draw();
		EndLoop();
	}
	printf("Game quit\n");
}

void MainGame::StartLoop() {

}

void MainGame::ProcessInput() {
	sf::Event event;
	while (_window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				_window.close();
				_quit = true;
				break;
			case sf::Event::KeyPressed:
				InputManager::GetInstance().PressKey((Key)event.key.code);
				break;
			case sf::Event::KeyReleased:
				InputManager::GetInstance().ReleaseKey((Key)event.key.code);
				break;
			case sf::Event::MouseMoved:
				InputManager::GetInstance().MoveMouse(sf::Vector2i{ event.mouseMove.x, event.mouseMove.y });
				break;
		}
	}
}

void MainGame::Update() {
	_player->Update(sf::Vector2i{WINDOW_WIDTH, WINDOW_HEIGHT});
}

void MainGame::Draw() {
	// Start by clearing the window to black
	_window.clear(sf::Color::Black);

	// Draw player to window
	_window.draw(*_player);

	// Display current frame in window
	_window.display();
}

void MainGame::EndLoop() {
	sf::sleep(sf::milliseconds(10));
}
