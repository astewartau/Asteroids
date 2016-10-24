#include "StateRunner.h"
#include <iostream>

using namespace std;

int main() {
	// Create a new StateRunner
	StateRunner* stateRunner = new StateRunner();

	// Run the StateRunner
	stateRunner->Go();

	// Delete the StateRunner
	delete stateRunner;

	// Press any key to continue
	cout << "Press RETURN to exit\n";
	getchar();

	// Exit gracefully
	return 0;
}