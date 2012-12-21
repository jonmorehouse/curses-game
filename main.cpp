#include "game_controller.h"

int main() {

	Game_controller * game_controller = new Game_controller();

	(*game_controller)();//run the game!

	delete game_controller;
	return 0;
}