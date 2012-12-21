#include "../main.h"
/* IMPLEMENTATION FOR WINDOW.CPP */

/*********** CONSTRUCTOR / DESTRUCTORS *************/
Window::Window() {

	WINDOW * window;//this is useful for everywhere in the site -- we will pass a pointer to this, so that the same object is going to be used everywhere in the game

	window = initscr();

	getmaxyx(window, max_y, max_x);//set the screen height / width to max_y, max_y

}

Window::~Window() {


	endwin();//this ends the screen for curses 


}

/************* PUBLIC FUNCTIONS ******************/

	/*********** DRAWING FUNCTIONS ************/
void Window::draw_section(vector<Coordinate *>coordinates, char value) {


	for (int z = coordinates.size() - 1; z >= 0; z--)
		mvinsch(coordinates[z]->y, coordinates[z]->x, value);

	refresh();

}

void Window::draw(int x, int y, char value[2]) {

	// char input = char(value);
	// mvinsch(y, x, input);//move to x, y and insert he correct character passed

	refresh();//refresh screen and clear buffer
}

	/************** ERASING FUNCTIONS **********/
void Window::erase_section(vector<Coordinate *>coordinates) {


	// initiate the delete here by sending to the buffer
	for (int i = coordinates.size() -1; i >= 0; i--) //reverse for loop
		mvdelch(coordinates[i]->y, coordinates[i]->x);//move to the correct position and delete it

	refresh();//clear section

}

void Window::erase(int x, int y) {

	mvdelch(y, x);//move to the correct position and delete the characters

	refresh();//will delete the character


}

void Window::erase_screen() {

	clear();//clear the screen 

	refresh();//clear the screen finally!
}


/********** UTILITIES *****/

int Window::get_max_x() {


	return max_x;//essentially returns the screen width!

}

int Window::get_max_y() {

	return max_y;//returns the screen height


}