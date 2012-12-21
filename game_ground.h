#ifndef GAME_GROUND_H
#define GAME_GROUND_H

#include <iostream>

#include "main.h"
//this will include all of the basic import libraries that are needed

using namespace std;
//this class is responsible for creating the individual hill points -- will just keep a vector of coordinates
class Hill {	

	public:
		Hill(int _x);//send this the first x value to be used to create
		~Hill();
		vector<Coordinate *>coordinates;//this will be a vector pointers -- so this is good to be in the stack of x's and y's
		void shift_left();//this will shift the x values left once
		int get_height();
		int get_width();
		int movement_factor;//this is how fast the mountains move!


	private:
		int x, height, width;//this is the current, left most element of the current hill
		void dimensions();//this is useful for creating the dimensions for this hill
		void create();//this method is called from the constructor and is responsible for remove 
		unsigned evaluate(float _x);//this is the local x value to be evaluated before returning a y
};

class Game_ground {

	public:
		Game_ground(Colored_window * _window);//send in the window object
		~Game_ground();
		// operator function -- for functor
		void operator()();
		// will be its own class later -- will be a functor that is given the coordinates and returns the collision point and which way it should go
		bool collision(int x, int y);//will return true / false for now but needs to be extended later -- to help with game _ ground collisions 
		void draw();

	public:
		vector<Hill *>hills;//this is the vector of hills which all hold coordinates
		vector<Coordinate *>master_coordinates;//master coordiantes
		vector<Coordinate *>old_master_coordinates;//old master coordinates


	private:
		Colored_window * window;
		int height, width;//height and width of the screen!

	protected:
		void init();//initialize and create all elements
		void create();//create the needed elements
		void clean();//clean out old element
		void clear();//this is to clear the screen 
};

#endif