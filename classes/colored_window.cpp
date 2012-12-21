#include "../main.h"

Colored_window::Colored_window(Utilities * _utilities) {

	//whenever you create a child class, the parent constructor is also called
	//initialize variables
	utilities = _utilities;
	foreground_color = 0;//basic foreground color
	background_color = 0;//basic background color

	noecho();//turn off echoing for the element

	if (has_colors()) {
		color_compatible = true;//set the global colors enabled section
		start_color();
		set_background("gray");
		set_color("red");
	}
	else
		color_compatible = false;

}

Colored_window::~Colored_window() {

	attroff(COLOR_PAIR(1));

}

void Colored_window::set_background(string color) {//set the global background color and change the terminal to this color

	background_color = color_convert(color);

	init_pair(1, foreground_color, background_color);//initialize the color pair
	attron(COLOR_PAIR(1));//turn the colors on

	// do a reverse loop to loop through and change all the boxes so the background looks correct
	for (int y = max_y; y >= 0; y--) {

		for (int x = max_x; x >= 0; x-- )
			mvprintw(y, x, " ");
	}

	refresh();

}

void Colored_window::set_color(string color) {//this will set the color by using a switch


	int _background_color, _foreground_color;
		
	foreground_color = color_convert(color);

	init_pair(1, foreground_color, background_color);

	attron(COLOR_PAIR(1));	

	refresh();
}

void Colored_window::draw_section(vector<Coordinate *>coordinates, char value) {

	if (color_compatible) {

		for (int z = coordinates.size() - 1; z >= 0; z--)
			mvprintw(coordinates[z]->y, coordinates[z]->x, "%s", value);

		refresh();
	}

	else
		Window::draw_section(coordinates, value);
}

void Colored_window::draw(int x, int y, char value[100]) {


	mvprintw(y, x, "%s", value);

	refresh();

}

/****** PRIVATE FUNCTIONS ******/

int Colored_window::color_convert(string color) {

	int color_code;

	if (utilities->compare("red", color))
		color_code = 1;

	else if (utilities->compare("green", color))
		color_code = 2;

	else if (utilities->compare("yellow", color))
		color_code = 3;

	else if (utilities->compare("blue", color))
		color_code = 4;

	else if (utilities->compare("magenta", color))
		color_code = 5;

	else if (utilities->compare("cyan", color))
		color_code = 6;

	else 
		color_code = 7;//color white

	return color_code;

}
