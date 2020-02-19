#pragma once
#include "Show.h"

class Shelf{

	const static int MAX_SHOWS = 10;
	int numShows;
	Show showArray[10];

public:
	//Exceptions
	class ShelfOverflow{
		int showCount;
	public:
		ShelfOverflow(int);
		void error();
	};
	class ShelfUnderflow{
	public:
		void error();
	};
	
	//Constructor
	Shelf();
	Shelf(int, Show *);
	
	//Getters
	int getMaxShows();
	int getNumShows();
	Show * getGameList();
	
	//Setters
	void setNumShows(int);
	void setShows(Show *, int);

	//Other functions
	void addShow(Show); //Adds a Show
	Show removeShow(); //Returns Last Show


};

