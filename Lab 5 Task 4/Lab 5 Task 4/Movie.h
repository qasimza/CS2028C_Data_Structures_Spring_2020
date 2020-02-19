#ifndef MOVIE
#define MOVIE

#include "Show.h"

class Movie : public Show {
	const static int MAX_CREDITS = 100; //Set a limit since arrays are not dynamic
	int num_credits;
	string credits[MAX_CREDITS];

public:
	// Constructors
	Movie();
	Movie(string, string, string, int, string *, int);

	// Getters
	string * getCredits();
	int getNumCredits();

	// Settters
	void setCredits(string *, int);
	void setNumCredits(int);

	// Other Functions
	void play();
};


#endif
