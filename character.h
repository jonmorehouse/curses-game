#ifndef CHARACTER_H
#define CHARACTER_H

#include "main.h"

using namespace std;

class Character{

	// we need to check whether or not the space bar is hit -- whether or not it moves up or down
	// how long it has been determines the speed

	public://constructor / destructor
		Character(Colored_window * _window);
		~Character();
		void operator()(char current_input);//functor operation -- will take in the c++ object  -- calling this will move the character and do everything that is needed 

	public://accessible functions
		int get_x();//this will return the coordinates of the position
		int get_y();//this will return the y coordinate of the character
		void reset();//this is useful for resetting the position of the character after a collision!

	public://varaible
		vector<Coordinate *>coordinates;//this is all of the available coordinates -- this is useful for predicting which spots are--these 

	private://variables -- 
		Colored_window * window;//this is the curses library that we are using!
		vector<char>input;//this is all of the last several elements -- this will be used for calculating speed etc--thisi is hte character input history
		Coordinate * current_position;//these are the current coordinates -- this will be changed later -- this is the center of the object!
		const static char up_character = ' ';//space bar is up!
		int multiplier;//this is a multiplier to show which way the element should go -- this will be used with a x ^ 0.5 to calculate the correct y
		int height, width;//this is the screen width / height

	private://functions --  
		void clear();//useful for clearing the character from the screen
		void draw();//draw the character with the correct elements on teh screen at the given position
		void set_y();//this will set the y by using our loop
};

#endif