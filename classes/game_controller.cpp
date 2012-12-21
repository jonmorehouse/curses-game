#include "../game_controller.h"

//this is the game controller object -- this controls the entire game!

//this is a singleton class -IE THERE WILL ONLY BE ONE OF THESE!
Game_controller::Game_controller(){

	speed = 50;//initial speed = 0
	distance = 0;//initialize the distance to 0
	utilities = new Utilities();//this is the default utilities
	window = new Colored_window(utilities);//send them teh utilities for this class
	game_ground = new Game_ground(window);
	character = new Character(window);

}

Game_controller::~Game_controller() {

	delete character;
	delete game_ground;
	delete window;
	delete utilities;
	
}

/******** PUBLIC FUNCTIONS ********/

void Game_controller::operator()() {//will return itself until the game is over!

	bool playing = true;
	int counter = 0;

	(*character)(' ');
	while (playing) {

		timeout(speed);//this is how long the user has to react!
		char input = getch();//get the input character
		distance += 3;
		counter++;

		this->set_score();//set the on screen score!
		this->set_speed();//set the speed accordingly!

		if (counter % 3 == 0)
			(*game_ground)();//this is responsible for moving the game ground underneath the object

		(*character)(input);//this is responsible for moving the character above the mountains

		bool status = this->collision();//this is

		if (input == 'q' || !status)//exit conditions for the game
			playing = false;
	}

	this->message();
	sleep(5);

}

/******* PRIVATE FUNCTIONS *******/

bool Game_controller::collision() {//will return true or false depending upon whether or not the character collided with ground

	bool flag = true;//this will return false if there was a collision anywhere

	Coordinate * character_temp;
	Coordinate * ground_temp;



	for (int i = character->coordinates.size() -1; i >= 0; i-- ) {

		character_temp = character->coordinates[i];

		if (character_temp->y > window->get_max_y()) {
			flag = false;
			break;
		}

		for (int j = game_ground->hills.size() -1; j >= 0; j--) {

			for (int k = game_ground->hills[j]->coordinates.size()-1; k >=0; k--) {

				ground_temp = game_ground->hills[j]->coordinates[k];//the current temp coordinates!

				if (ground_temp->x == character_temp->x && ground_temp->y == character_temp->y) {
					flag = false;
					break;
				}
			}
		}
	} 



	// this is going to check for collisions and will then determine whether or not the user is dead!
	return flag;
}

void Game_controller::set_score() {

	char message[8] = "Score: ";
	char data[10];

	window->draw(0, 0, message);
	utilities->double_to_char(distance, data);

	window->draw(10,0,data);

}

void Game_controller::set_speed() {//this is how fast the game goes depending upon the distance

	//need to set the element to speed!

	if (distance < 100)
		speed = 280;

	else if (distance < 200)
		speed = 240;

	else if (distance < 300)
		speed = 200;

	else
		speed = 190;

}

void Game_controller::message() {

	int x, y;

	char message[30] = "Game Over. Final Score: ";
	char score[10];

	window->set_background("");

	x = window->get_max_x() * 0.5 - 15;
	y = window->get_max_y() * 0.5;
	window->draw(x, y, message);

	utilities->double_to_char(distance, score);
	window->draw(window->get_max_x() * 0.5 -3, y + 2, score);
}



