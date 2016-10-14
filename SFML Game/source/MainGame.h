#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "TextureManager.h"
#include "InputManager.h"
#include "Player.h"

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

	////// TEMPORARY
	InputManager* _inputManager;
	TextureManager* _textureManager;
	Player* _player;
	enum TextureName { PLAYER, CURSOR, BACKGROUND };
	//////////////////////////////////////////////////
};