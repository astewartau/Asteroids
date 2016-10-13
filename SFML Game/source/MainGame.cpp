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
	sf::Image Icon;
	Icon.loadFromFile("assets/textures/tochLit.png");
	_window.setIcon(70, 70, Icon.getPixelsPtr());
	printf("Done!\n");
}

void MainGame::SetupGame() {
	printf("Setting up game...");

	// Load map
	_mapLoader = new tmx::MapLoader("assets/maps");
	_mapLoader->load("map5.tmx");

	std::vector<tmx::MapLayer>& layers = _mapLoader->getLayers();
	for (auto& layer : layers) {
		if (layer.type == tmx::MapLayerType::ObjectGroup) {
			for (auto& obj : layer.objects) {
				if (layer.name == "Characters") {
					_player = new Player(sf::Vector2f{obj.getCentre().x, obj.getAABB().top + obj.getAABB().height});
				}
			}
		}
	}

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
		}
	}
}

void MainGame::Update() {
	_player->Update();

	if (!_player->Grounded()) {
		std::vector<tmx::MapLayer>& layers = _mapLoader->getLayers();
		for (auto& layer : layers) {
			if (layer.type == tmx::ObjectGroup) {
				for (auto& obj : layer.objects) {
					if (layer.name == "Collisions") {
						auto playerPosition = _player->GetPosition();
						if (obj.contains(playerPosition)) {
							_player->SetGrounded(true);
							_player->SetPosition(_player->GetPosition().x, obj.getAABB().top);
							break;
						}
					}
				}
			}
		}
	}
}

void MainGame::Draw() {
	// Start by clearing the window to black
	_window.clear(sf::Color::Black);

	// Draw map to screen
	_mapLoader->drawLayer(_window, tmx::MapLayer::All, false);
	_window.draw(*_player);

	// Display current frame in window
	_window.display();
}

void MainGame::EndLoop() {
	sf::sleep(sf::milliseconds(10));
}
