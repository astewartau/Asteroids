#include "MainGame.h"
#include <iostream>

using namespace std;

int main() {
	// Create a new game instance
	MainGame game;

	// Run the game
	game.Go();

	// Press any key to continue
	cout << "Press RETURN to exit\n";
	getchar();

	// Exit gracefully
	return 0;
}