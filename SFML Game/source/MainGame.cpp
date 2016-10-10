#include "MainGame.h"
#include <cstdio>

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
	_shootSoundBuffer.loadFromFile("assets/sounds/sfx_wpn_laser6.wav");
	_shootSound.setBuffer(_shootSoundBuffer);
	_music.openFromFile("assets/music/through space.ogg");
	_music.play();

	_playerTexture.loadFromFile("assets/textures/playerShip1_blue.png");
	_player.setTexture(_playerTexture);
	_player.setOrigin(_player.getGlobalBounds().width/2, _player.getGlobalBounds().height/2);
	_player.setPosition(0.50f * WINDOW_WIDTH, 0.85f * WINDOW_HEIGHT);

	_backgroundTexture.loadFromFile("assets/textures/blue.png");
	_backgroundTexture.setRepeated(true);
	_background.setTextureRect(sf::IntRect{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});
	_background.setTexture(_backgroundTexture);
	////////////////////////////

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
			// TEMPORARY
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Right) {
					_player.move(10, 0);
				} else if (event.key.code == sf::Keyboard::Left) {
					_player.move(-10, 0);
				} else if (event.key.code == sf::Keyboard::Up) {
					_player.move(0, -10);
				} else if (event.key.code == sf::Keyboard::Down) {
					_player.move(0, 10);
				} else if (event.key.code == sf::Keyboard::Space) {
					_shootSound.play();
				}
				break;
			////////////////
		}
	}
}

void MainGame::Update() {

}

void MainGame::Draw() {
	// Start by clearing the window to black
	_window.clear(sf::Color::Black);

	// Draw player to window
	// TEMPORARY
	_window.draw(_background);
	_window.draw(_player);
	////////////////

	// Display current frame in window
	_window.display();
}

void MainGame::EndLoop() {
	sf::sleep(sf::milliseconds(10));
}
