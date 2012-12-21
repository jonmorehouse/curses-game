#include "../main.h"

Utilities::Utilities() {//use this to initiate the srand -- should only be called once for the entire program

	time_t seconds;

	time(&seconds);

	srand((unsigned int) seconds);//initialize the time function to pass to the random function to generate different results

}


bool Utilities::compare(string input_1, string input_2) {

	if (string_to_lower(input_1) == string_to_lower(input_2))
		return true;

	else
		return false;

}

string Utilities::string_to_lower(string input) {


	for (int i = 0, z = input.length(); i < z; i++)	
		input[i] = tolower(input[i]);

	return input;
}

void Utilities::double_to_char(double input, char output[8]) {//works fine casting an int as a double

	sprintf(output, "%d", int(input));

}

