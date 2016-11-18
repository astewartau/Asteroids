#pragma once
#include "GameState.h"

#include "Components\Controller\PlayerController.h"
#include "Components\Graphics\PlayerGraphics.h"
#include "Components\Physics\SpacePhysics.h"
#include "Components\Physics\TorusLimiter.h"
#include "Components\Graphics\BackgroundGraphics.h"
#include "Components\Spawner\AsteroidSpawner.h"
#include "Components\Spawner\BulletSpawner.h"

class AsteroidsGame : public GameState {
public:
	AsteroidsGame(sf::RenderWindow* window) : GameState(window) {
		srand((unsigned int)time(NULL));

		// Create background
		AddObject(new GameObject({
			new BackgroundGraphics(&_resourceManager, _window->getSize())
		}));

		// Create player
		GameObject* player = new GameObject({
			new PlayerController(&_inputManager),
			new PlayerGraphics(&_resourceManager),
			new SpacePhysics(),
			new TorusLimiter(GetBounds()),
			new BulletSpawner(this, &_resourceManager)
		});

		player->_sprite.setPosition(_window->getSize().x * 0.5f, _window->getSize().y * 0.75f);
		AddObject(player);

		// Create Asteroid Spawner
		AddObject(new GameObject({
			new AsteroidSpawner(this, &_resourceManager),
			new Destroyer(sf::seconds(15), this)
		}));
	}
};