#include "Movie.h"


//Default Constructor

Movie::Movie() :Show() {
	num_credits = 0;
	credits[0] = "None";
}


//Parameterized Constructor

Movie::Movie(string movieTitle, string movieDescription, string movieDirector, int movieYear, string *movieCredits, int movieNumCredits):Show(movieTitle, movieDescription, movieDirector, movieYear){
	if (movieNumCredits > MAX_CREDITS) {
		num_credits = MAX_CREDITS;
	}
	else if (movieNumCredits < 0) {
		num_credits = 0;
	}
	else {
		num_credits = movieNumCredits;
	}
	for (int i = 0; i < num_credits; i++) {
		credits[i] = movieCredits[i];
	}
}


//Getters

string * Movie::getCredits() {
	string * ptr;
	ptr = &credits[0];
	return ptr;
}

int Movie::getNumCredits() {
	return num_credits;
}

//Setter

void Movie::setCredits(string * movieCredits, int movieNumCredits) {
	if (movieNumCredits > MAX_CREDITS) {
		num_credits = MAX_CREDITS;
	}
	else if (movieNumCredits < 0) {
		num_credits = 0;
	}
	else {
		num_credits = movieNumCredits;
	}
	for (int i = 0; i < num_credits; i++) {
		credits[i] = movieCredits[i];
	}
}

void Movie::setNumCredits(int movieNumCredits) {
	if (movieNumCredits > MAX_CREDITS) {
		num_credits = MAX_CREDITS;
	}
	else if (movieNumCredits <= 0) {
		num_credits = 0;
		credits[0] = "None";
	}
	else {
		num_credits = movieNumCredits;
	}
}


//Other functions

void Movie::play() {
	cout << "Credits: " << endl;
	if (num_credits == 0) {
		cout << credits[0] << endl;
	}
	for (int i = 0; i < num_credits; i++) {
		cout << credits[i] << endl;
	}
}

//Detils does not need to be overloaded