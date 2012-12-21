#ifndef MAIN_H
#define MAIN_H

// C++ Libraries
#include <iostream>//standard input / output -- implemented in gnu
#include <vector>//standard c++ vector -- implemented in gnu
#include <string>//standard c++ string library --implemented in gnu


// C Libraries
#include <ncurses.h>
#include <cstring>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.141592653589793238462//this is a global definition -- just cast for accuracy where needed


// DEFINITIONS


/* Class window will assume that the explicit drawing is done by passing in a vector of x/y elements */

using namespace std;


class Utilities {

	public:
		Utilities();
		bool compare(string input_1, string input_2);//this utility function is going to be responsible for comparing two strings and returning true / false
		string string_to_lower(string input); //convert string to lower!
		void double_to_char(double input, char output[8]);//convert double to char
};

// this is the coordinates for the section
struct Coordinate {

	int x, y;

};

class Window {

	// CONSTRUCTORS / DESTRUCTORS
	public:
		Window();//constructor -- initiates the curses screen section
		~Window();//destructor -- responsible for ending the curses screen section

	//PUBLIC ACCESS FUNCTIONS

	public:	

		// DRAW SECTIONS
		void draw_section(vector<Coordinate *>coordinates, char value);//this method will 
		void draw(int x, int y, char value[10]);

		// ERASE SECTIONS
		void erase_section(vector<Coordinate*>coordinates);
		void erase(int x, int y);
		void erase_screen();//this is to erase the screen

		// BASIC INFORMATION SCREENS!
		int get_max_x();//this will return the screen width
		int get_max_y();//this will return the screen height

	protected:

		WINDOW * window;//this is the current window -- to be used by the document
		int max_x, max_y;//this corresponds to window height/width and current position of the cursor

};

class Colored_window: public Window {

	public:
		Colored_window(Utilities * _utilities);//constructor 
		~Colored_window();//constructor

		void set_color(string color);
		void set_background(string color);

		void draw_section(vector<Coordinate *>coordinates, char value);//this replaces the parent draw function!
		void draw(int x, int y, char value[2]);

	private:
		int color_convert(string color);

		bool color_compatible;//whether or not colors are supported in this terminal
		int background_color;//this will be set as a default for now i nthe constructor
		int foreground_color;//when set_color is called, this will be changed globally!
		Utilities * utilities;//this is the utilities pointer that is passed in the constructor

};


#endif