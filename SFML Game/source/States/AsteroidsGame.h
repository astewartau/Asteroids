#pragma once
#include "GameState.h"

#include "Components\Controller\PlayerController.h"
#include "Components\Graphics\PlayerGraphics.h"
#include "Components\Physics\SpacePhysics.h"
#include "Components\Physics\TorusLimiter.h"
#include "Components\Graphics\BackgroundGraphics.h"
#include "Components\Spawner\AsteroidSpawner.h"
#include "Components\Spawner\BulletSpawner.h"
#include "Components\Sound\BackgroundMusic.h"

class AsteroidsGame : public GameState {
public:
	AsteroidsGame(sf::RenderWindow* window) : GameState(window) {
		srand((unsigned int)time(NULL));

		// Create background
		AddObject(new GameObject({
			new BackgroundGraphics(&_resourceManager, _window->getSize()),
			new BackgroundMusic(&_resourceManager)
		}));

		// Create player
		GameObject* player = new GameObject({
			new PlayerController(&_inputManager),
			new PlayerGraphics(&_resourceManager),
			new SpacePhysics(),
			new TorusLimiter(GetBounds()),
			new BulletSound(&_resourceManager),
			new BulletSpawner(this)
		});

		player->_sprite.setPosition(_window->getSize().x * 0.5f, _window->getSize().y * 0.75f);
		AddObject(player);

		// Create Asteroid Spawner
		AddObject(new GameObject({
			new AsteroidSpawner(this),
			new Destroyer(sf::seconds(20), this)
		}));
	}
};