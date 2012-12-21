#include "../game_ground.h"

/*********** CONSTRUCTOR / DESTRUCTOR ***********/

Game_ground::Game_ground(Colored_window * _window) {

	window = _window;//initialize the window for the element
	height = window->get_max_y();//grab the window maximum height
	width = window->get_max_x();//grab the window maximum width

	this->init();//initiate the hills
	this->draw();//draw hills
	
}

Game_ground::~Game_ground() {



}

/********** FUNCTOR OPERATOR FUNCTION ******/

void Game_ground::operator() () {//this is responsible for running the game ground -- will call the objects to check if the screen is full

	this->draw();

}

/********** PUBLIC FUNCTIONS *********/


// this is essentially responsible for looping throught the coordinates and drawing out the elementsa
void Game_ground::draw() {//this is responsible for filling the screen

	Coordinate * temp_coordinates;//this is just a pointer that has not been initialized -- used to work with teh loop
	int _height;
	int _width;
	char insert_character[2] = "";
	insert_character[0] = '*';

	this->clear();
	this->create();//initiate the drawings

	window->set_color("red");

	for (int i = hills.size() - 1; i >= 0; i--) {//loop through each hill

		for (int j = hills[i]->coordinates.size() -1; j >= 0; j--) {//now for each hill, loop through each coordinate!
		
			temp_coordinates = hills[i]->coordinates[j];
			window->draw(temp_coordinates->x, height - temp_coordinates->y, insert_character);//draw in the block
		}
	}

	this->clean();//clean up any old objects
}

bool Game_ground::collision(int x, int y) {


	return true;
	/* 

	This function is going to go through the elements and see if there was a colision at any point of the hills

	*/

}

/*********** PROTECTED FUNCTIONS ********/
void Game_ground::init() {

	int x = 0;
	do {

		hills.push_back(new Hill(x));//create a new hill--on the end

		x += hills.back()->get_width();//add the width of this on


	} while (x <= width);
}

void Game_ground::create() {//this element is responsible for creating the proper hill objects 
	//loop through all of the hills and shift them left by 1
	
	int x = 0;
	for (int i = hills.size() -1; i >= 0; i--) {

		hills[i]->shift_left();//shift the hill left once! -- will also ensure that no negative numbers exist
		x += hills[i]->get_width();//append the width
	}
		
	do {

		hills.push_back(new Hill(x));
		x += hills.back()->get_width();
	} while (x < width);

}

void Game_ground::clear() {//this is responsible for clearing all of the elements so that that the screen is clear

	//needs to call the highest in the row -- method to clear!

	// need to loop through each of the elements and erase them

	//loop through each of my vectors and remove them!
	/*bool flag;
	char value[2] = "";
	int movement_factor = hills[0]->movement_factor;
	Coordinate single;
	vector<Coordinate>temp;

	for (int i = hills.size() -1; i >=0; i--) {

		for (int j = hills[i]->coordinates.size() -1; j >=0; j--) {

			single.x = hills[i]->coordinates[j]->x + movement_factor;
			single.y = hills[i]->coordinates[j]->y;
			temp.push_back(single);
		}
	}

	for (int i = temp.size() -1; i >= 0; i--) {

		int x = temp[i].x;
		int y = temp[i].y;

		flag = false;
		for (int j = hills.size() -1; j >= 0; j--) {

			for (int k = hills[j]->coordinates.size() -1; k >= 0; k--) {

				if (hills[j]->coordinates[k]->x == x && hills[j]->coordinates[k]->y == y) {
					flag = true;
					break;//break this loop
				}
			}

			if (flag) break;

			else
				window->draw(x, y, value);

		}

	}
	*/
	char value[2] = "";

	Coordinate * temp;
	value[0] = ' ';

	for (int i = hills.size()-1; i >= 0; i--) {//loop through each hill

		for (int j = hills[i]->coordinates.size() -1; j >= 0; j--) {//loop through each coordinate

			temp = hills[i]->coordinates[j];//this is the specific coordiantes!

			window->draw(temp->x, height - temp->y, value);//now erase the section!
		}
	}

}

void Game_ground::clean() {//this is responsible for looping through the hills and removing hills where they are not currently in the correct place -- since the hills are self containing this is done by checking length!

	for (int i = hills.size() -1; i >= 0; i--) {

		// delete it first and then remove from the vectory

		if (hills[i]->coordinates.size() == 0) {

			delete hills[i];//delete the hill object
			hills.erase(hills.begin() + i);//erase the pointer to the object
		}
	}
}

