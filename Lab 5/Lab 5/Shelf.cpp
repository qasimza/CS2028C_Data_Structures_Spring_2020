#include "Shelf.h"

//Default Constructor
Shelf::Shelf(){
	numShows = 0;
}

//Parameterized Constructor
Shelf::Shelf(int uNumShows, Show *uPtr) {
	numShows = uNumShows;
	for (int i = 0; i < uNumShows; i++) {
		showArray[i] = uPtr[i];
	}
}

//Getters
int Shelf::getMaxShows() {
	return MAX_SHOWS;
}
int Shelf::getNumShows() {
	return numShows;
}
Show * Shelf::getGameList() {
	Show *ptr = &showArray[0];
	return ptr;
}

//Setters
void Shelf::setNumShows(int uNumShows) {
	numShows = uNumShows;
}

void Shelf::setShows(Show *uPtr, int uNumShows) {
	numShows = uNumShows;
	for (int i = 0; i < uNumShows; i++) {
		showArray[i] = uPtr[i];
	}
}

//Other functions
void Shelf::addShow(Show uShow) {
	showArray[numShows] = uShow;
	numShows++;
}

Show Shelf::removeShow() {
	numShows--;
	return showArray[numShows];
}