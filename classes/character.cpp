#include "../character.h"

/*** CONSTRUCTORS / DESTRUCTORS ***/

Character::Character(Colored_window * _window) {

	window = _window;

	current_position = new Coordinate;
	height = window->get_max_y();
	width = window->get_max_x();
	this->reset();//set the character position to the correct height

}

Character::~Character() {

	delete current_position;//remove the elements
}

/*** OPERATOR FUNCTION -- USED FOR CONTROLLING THE ENTIRE GAME ***/

void Character::operator()(char current_input) {//this assumes that there was any input --

	char value[2];	

	this->clear();//clear the old character

	if (current_input == up_character)
		current_position->y += 1;
	else 
		current_position->y -= 2;

	input.push_back(current_input);//store this input -- this will 
	this->set_y();//set the correct new y position
	this->draw();//this will draw the correct value and set the coordiantes properly

}

/****** PUBLIC FUNCTIONS *****/

int Character::get_x() {//returns the current x position -- this should usually be the same!

	return current_position->x;//retur nteh x position 

}

int Character::get_y() {//returns the current coordinates for the game


	return current_position->y;
}

void Character::reset() {//useful for resetting the character

	multiplier = 1;
	current_position->x = window->get_max_x() * 0.5;
	current_position->y = window->get_max_y() * 0.75;
}

/******* PRIVATE FUNCTIONS ********/
void Character::clear() {//only used in testing

	char value[2] = "";
	value[0] = ' ';

	for (int i = coordinates.size() -1; i >= 0; i--)
		window->draw(coordinates[i]->x, height-coordinates[i]->y, value);

}

void Character::draw() {//this is responsible for drawing the character at the correct position on the screen

	char value[2] = "";

	coordinates.clear();//clear all of the past vectors

	window->set_color("red");

	// this following segment is recreated for each character element
	coordinates.push_back(new Coordinate());
	coordinates.back()->x = current_position->x;
	coordinates.back()->y = current_position->y;
	value[0] = '/';
	window->draw(coordinates.back()->x, height-coordinates.back()->y, value);

	coordinates.push_back(new Coordinate());
	coordinates.back()->x = current_position->x;
	coordinates.back()->y = current_position->y+1;
	value[0] = '*';
	window->draw(coordinates.back()->x, height-coordinates.back()->y, value);

	coordinates.push_back(new Coordinate());
	coordinates.back()->x = current_position->x;
	coordinates.back()->y = current_position->y+2;
	value[0] = '\\';
	window->draw(coordinates.back()->x, height-coordinates.back()->y, value);

	coordinates.push_back(new Coordinate());
	coordinates.back()->x = current_position->x+1;
	coordinates.back()->y = current_position->y+1;
	value[0] = '*';
	window->draw(coordinates.back()->x, height-coordinates.back()->y, value);

	//now we have drawn each of the proper characters and put the proper elements into the global coordinates vector to be used by other 
}

void Character::set_y() {//this is responsible for setting the new y value

	//obsolete for now


}

