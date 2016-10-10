#pragma once
#include <SFML\Graphics.hpp>


class MainGame {
public:
	MainGame();

	void Go();

	void InitSystems();
	void SetupGame();

	void GameLoop();

	void StartLoop();
	void ProcessInput();
	void Update();
	void Draw();
	void EndLoop();
private:
	const std::string WINDOW_TITLE = "My game";
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	bool _quit;
	sf::RenderWindow _window;
	sf::Texture _playerTexture;
	sf::Texture _backgroundTexture;
	sf::Sprite _player;
	sf::Sprite _background;
};