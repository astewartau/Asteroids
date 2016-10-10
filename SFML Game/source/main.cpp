#include "MainGame.h"
#include <iostream>

using namespace std;

int main() {
	MainGame game;
	game.Go();

	// Press any key to continue
	getchar();

	// Exit gracefully
	return 0;
}