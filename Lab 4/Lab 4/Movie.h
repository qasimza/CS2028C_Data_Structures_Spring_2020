#pragma once
#include "Show.h"

class Movie : public Show{
	
	string * credits;

public:
	// Constructors
	Movie();
	Movie(string, string, string, int, int);

	// Getters
	string getCredits();

	// Settters
	void setCredits();

	// Other Functions
	void play();
};

