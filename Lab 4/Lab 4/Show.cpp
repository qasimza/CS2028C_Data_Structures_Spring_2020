#include "Show.h"


//Default constructor

Show::Show()
{
	title = "undefined";
	description = "n/a";
	director = "undefined";
	year = -1;
}


// Parameterized constructor

Show::Show(string showTitle, string showDescription, string showDirector, int showYear)
{
	title = showTitle;
	description = showDescription;
	director = showDirector;
	year = showYear;
}

//Getters 

string Show::getTitle() {
	return title;
}

string Show::getDescription() {
	return description;
}
string Show::getDirector() {
	return director;
}
int Show::getYear() {
	return year;
}


//Setters

void Show::setTitle(string showTitle) {
	title = showTitle;
}

void Show::setDescription(string showDescription) {
	description = showDescription;
}

void Show::setDirector(string showDirector) {
	director = showDirector;
}

void Show::setYear(int showYear) {
	year = showYear;
}


//Other function

void Show::play() {
}


void Show::details() {
	cout << "Title:" << title << endl;
	cout << "Description: " << endl << description << endl;
	cout << "Director: " + director << endl;
	cout << "Release Year: " + year << endl;
}