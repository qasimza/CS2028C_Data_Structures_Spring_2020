#include "Movie.h"


//Default Constructor

Movie::Movie() :Show() {
	credits = NULL;
}


//Parameterized Constructor

Movie::Movie(string movieTitle, string movieDescription, string movieDirector, int movieYear, string * creditsPtr):Show(movieTitle, movieDescription, movieDirector, movieYear){
	credits = creditsPtr;
}


//Getters

string * Movie::getCredits() {
	return credits;
}


//Setter

void Movie::setCredits(string * ptr) {
	credits = ptr;
}


//Other functions

void Movie::play() {
	for (int i; i < (&credits->length); i++) {
		cout << &credits[i] << endl;
	}
}

//Detils does not need to be overloaded