#include "Engine.h"
#include <iostream>

using namespace std;

int main() {
	// Create a new game instance
	Engine* game = new Engine();

	// Run the game
	game->Go();

	// Delete the game
	delete game;

	// Press any key to continue
	cout << "Press RETURN to exit\n";
	getchar();

	// Exit gracefully
	return 0;
}