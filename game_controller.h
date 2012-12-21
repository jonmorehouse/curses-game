#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "main.h"
#include "game_ground.h"
#include "character.h"

/*
	This is a singleton class that is used to control the game!
	
*/	
class Game_controller {

	public:
		Game_controller();//constructor
		~Game_controller();//destructor
		void operator()();//this will return itself until the game is finished!

	private:
		bool collision();//this is responsible for telling if there was a collison--this is fairly complicated--
		void set_score();//this is the scoring function -- will call the collision section for the different points and will determine the score factor
		void set_speed();//this controls how fast the game is!

	private:
		Utilities * utilities;
		Colored_window * window;//this is the game window used for interaction by all classes
		Game_ground * game_ground;//the mountains for the game
		Character * character;//this is the character
		void message();
		double distance;//this is how far one has gone in the game!
		int speed;//this is the speed of the game!
		double score;//this is the current score
};

#endif

