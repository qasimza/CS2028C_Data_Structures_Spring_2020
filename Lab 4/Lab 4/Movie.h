#pragma once
#include "Show.h"

class Movie : public Show {

	string * credits;

public:
	// Constructors
	Movie();
	Movie(string, string, string, int, string *);

	// Getters
	string * getCredits();

	// Settters
	void setCredits(string *);

	// Other Functions
	void play();
};

