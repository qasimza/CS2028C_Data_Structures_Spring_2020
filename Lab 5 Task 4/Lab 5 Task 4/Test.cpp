#include <iostream>
#include <string>
#include "EntertainmentCollection.h"
#include "EntertainmentCollection.cpp"
#include "Show.h"
#include "Movie.h"


using namespace std;

const string THIN_LINE = "---------------------------------------------------------------";
const string THICK_LINE = "===============================================================";


int getMenuOption() {

	int input = -1;
	bool inputCheck = false;

	cout << THICK_LINE << endl;
	cout << "	MENU: " << endl;
	cout << "	1: Add an Item " << endl;
	cout << "	2: Remove an Item " << endl;
	cout << "	3: Display number of Items " << endl;
	cout << "	4: Quit " << endl;
	cout << THIN_LINE << endl;
	cout << "Enter Choice (1-4): ";
	cin >> input;
	while (cin.fail() || input < 1 || input > 4) {
		cin.clear();
		cin.ignore();
		cout << THIN_LINE << endl;
		cout << "Please enter a valid input(1-4): ";
		cin >> input;
	}
	cout << THICK_LINE << endl;
	return input;
}

int main() {
	EntertainmentCollection<Movie> collection;
	int option, numCredits;
	Movie *movie = NULL;
	string x, title, description, director, credits[100], *ptr = &credits[0];
	int year;
	do {
		option = getMenuOption();
		switch (option) {
		case 1: //Add
			cout << "ADD AN ITEM:" << endl;
			getline(cin, x);
			cout << "	Enter Title: ";
			getline(cin, title);
			cout << "	Enter Description: ";
			getline(cin, description);
			cout << "	Enter Director: ";
			getline(cin, director);
			cout << "	Enter Year: ";
			cin >> year;
			cout << "Enter the number of Credits: " << endl;
			cin >> numCredits;
			getline(cin, x);
			if (numCredits < 0) {
				cout << "ERROR: Invalid number of credits. Setting number of credits to 0" << endl;
				numCredits = 0;
			}
			else if (numCredits > 100) {
				cout << "ERROR: Invalid number of credits. Setting number of credits to 100 (max limit)" << endl;
				numCredits = 100;
			}
			for (int i = 0; i < numCredits; i++) {
				cout << "Enter credit " << i + 1 << ": ";
				getline(cin, credits[i]);
			}
			try {
				movie = new Movie(title, description, director, year, ptr, numCredits);;
				collection.addItem(*movie);
			}
			catch (EntertainmentCollection<Movie>::EntertainmentCollectionOverflow e) {
				cout << "CAUGHT EXCEPTION: " << endl;
				e.error();
			}
			break;
		case 2: //Remove
			cout << "REMOVE AN ITEM" << endl;
			try {
				*movie = collection.removeItem();
				cout << "Removed Item:" << endl;
				movie->details();
			}
			catch (EntertainmentCollection<Movie>::EntertainmentCollectionUnderflow e) {
				cout << "CAUGHT EXCEPTION: " << endl;
				e.error();
			}
			break;
		case 3: //Get current number of shows
			cout << "DISPLAY CURRENT NUMBER OF ITEMS" << endl;
			cout << "	Number of items in collection: " << collection.getNumItems() << endl;
			break;
		case 4: //Quit
			cout << "QUITTING PROGRAM" << endl;
		default:
			cout << "CRITICAL ERROR: This should not be happening!" << endl;
		}
		cout << THICK_LINE << endl;
	} while (option != 4);
	return 0;
}