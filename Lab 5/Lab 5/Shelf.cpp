#include "Shelf.h"

//Exceptions
Shelf::ShelfOverflow::ShelfOverflow(int cShows) {
	showCount = cShows;
}

void Shelf::ShelfOverflow::error() {
	cout << "Overflow Error: Shelf is full. Cannot add another Show!" << endl;
	cout << "Maximum Shows Allowed: " << MAX_SHOWS << endl;
	cout << "Current Number Shows: " << showCount << endl;
}

void Shelf::ShelfUnderflow::error() {
	cout << "Underflow Error: Shelf is empty. Cannot remove a Show!" << endl;
}

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
	if (numShows < MAX_SHOWS) {
		showArray[numShows] = uShow;
		numShows++;
	}
	else {
		throw ShelfOverflow(numShows);
	}
}

Show Shelf::removeShow() {
	if (numShows > 0) {
		numShows--;
		return showArray[numShows];
	}
	else {
		throw ShelfUnderflow();
	}
}