#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>


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


	///////////////// TEMPORARY
	sf::Texture _playerTexture;
	sf::Sprite _player;

	sf::Texture _backgroundTexture;
	sf::Sprite _background;

	sf::SoundBuffer _shootSoundBuffer;
	sf::Sound _shootSound;
	sf::Music _music;
	//////////////////////////////////////////////
};