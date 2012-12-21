#include <iostream>
#include <vector>
#include <time.h>
#include "game_ground.h"
#include "character.h"
#include "game_controller.h"

/* 
	This is a very basic testing function 
	in a perfect world, this function should implemented test classes for each on and return errors etc
*/

using namespace std;

bool window_test();//this will return true / false depending upon the test results
bool colored_window_test();
bool utilities_test();//this in theory should load a class which will test
bool game_ground_test();//this is the game ground test method
bool hill_test();//this is the hill test 
bool character_test();//this is useful for testing the character
bool game_controller_test();//this is useful for testing the game in its entirity

Utilities * utilities = new Utilities();
int speed = 800;//this is how often to refresh in milliseconds

int main() {

	// if (window_test()) 
		// cout << "Window Object passed tests" << endl;;

	// if(colored_window_test())
		// cout << "Colored Window Object passed tests" << endl;

	// if (utilities_test())
		// cout << "Utilities Object passed tests" << endl;

	// if (game_ground_test())
		// cout << "Game ground was run" << endl;


	// if (character_test()) 
		// cout << "The character class is working properly" << endl;

	if (game_controller_test())
		cout << "The game controller is working properly!" << endl;

	return 0;
}

bool window_test() {

	Window * window = new Window();
	vector<Coordinate *>coordinates;


	for (int i =0, z=10; i <= 10; i++) {

		coordinates.push_back(new Coordinate);
		coordinates[i]->x = i;
		coordinates[i]->y = i;

	}

	window->draw_section(coordinates, 'x');

	sleep(1);

	delete window;

	return true;
}

bool colored_window_test() {

	int max_x, max_y;
	Colored_window * window = new Colored_window(utilities);

	max_x = window->get_max_x();
	max_y = window->get_max_y();

	sleep(20);

	delete window;

	return true;
}

bool utilities_test() {

	Utilities * utilities = new Utilities();

	delete utilities;

	return true;

}

bool game_ground_test() {

	Colored_window * window = new Colored_window(utilities);
	Game_ground * test = new Game_ground(window);

	int counter = 0;

	do {

		(*test)();//run the draw function
		usleep(800);

	} while (counter < 100);



	delete test;
	delete window;

	cout << counter << endl;
	return true;

}

bool hill_test() {




}

bool character_test() {
	/*
	char input[2]; //char array for drawing elements on the screen
	bool playing = true;

	Colored_window * window = new Colored_window(utilities);//new window withcurses created
	Character * character = new Character(window);

	(*character)('q');//de-reference the object to access it 

	while (playing) {

		timeout(speed);//this is how long we will wait for input
		input[1] = getch();//test for input --

		// later on we will call the game controller section -- this will do several things

		character->move();

		if (input[1] == 'q' || !game_controller()) //this will also have some sort of scoring method to test!
			playing = false;
	}

	delete character;
	delete window;

	return true;
*/
}

bool game_controller_test() {

	Game_controller * game_controller = new Game_controller();

	(*game_controller)();

	delete game_controller;

}
