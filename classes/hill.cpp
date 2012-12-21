#include "../game_ground.h" //include the game_ground 

/******* CONSTRUCTOR / DESTRUCTORS ***********/

Hill::Hill(int _x) {//

	x = _x;//set the initial x position with the value -- this is for the first x so we go from there! -- we will assume that x-- each time!

	movement_factor = 3;
	this->dimensions();//initialize the height and width of this element
	this->create();//call the create method and create the health!
}

Hill::~Hill() {

	for (int i = coordinates.size() - 1; i >= 0; i--)
		delete coordinates[i];

	coordinates.clear();

}

/*********** PUBLIC FUNCTIONS *********/

//cos(0) = 1; sin(0) = 0
// cos(pi) = 0 sin(1) = 1

void Hill::shift_left() {

	x--;//move the left most value -1

	//for each element move the x value left once! 

	for (int i = coordinates.size() - 1; i >= 0; i--) {

		coordinates[i]->x -= movement_factor;

		if (coordinates[i]->x < 0)//this is off the screen
			coordinates.erase(coordinates.begin() + i);//erase this from the vector 
	}
}

int Hill::get_width() {

	return width;

}

int Hill::get_height() {

	return height;
}

/******* PRIVATE FUNCTIONS *******/
void Hill::create() {

	int _y;
	float current_increment;//this is a ratio of the current width to x 
	Coordinate * coordinate;//this is the temporary coordinate -- will be deleted
	// coordinate pointer means that any time you reinitialize this will recreate a new piece!
	//want to stop it half way through the loop -- so we need to take the second derivative and set it to 0! -- where the concavity changes!

	for (int _x = 1; _x < width; _x++) {//exclude the values that are first and last that would be zero

		current_increment = (PI * float(_x)) / float(width);
		_y = this->evaluate(current_increment);

		for (int current_y = _y; current_y >= 0; current_y--) {//this is the y value for this column!

			coordinate = new Coordinate;
			coordinate->x = x + _x;//this is the current x position for this small hill
			coordinate->y = current_y;//this is the current y position for this small hill!

			coordinates.push_back(coordinate);
		}
	}
}

void Hill::dimensions() {//this private function is useful for creating the height and width of the hill 

	int counter=0;

	counter++;
	this->height = rand() % 20 + 3;
	this->width = rand() % 100 + 10;

}


unsigned Hill::evaluate(float _x) {//this private function is responsible for returning an integer representation 

	float value;

	value = float(height) * sin(_x);//this will be a proportion between 0 and maximum height!

	return int(value);
}

