#include <iostream>
#include "Shelf.h"

using namespace std;

const string THIN_LINE = "---------------------------------------------------------------";
const string THICK_LINE = "===============================================================";

int getMenuOption() {

	int input = -1;
	bool inputCheck = false;

	cout << THICK_LINE << endl;
	cout << "	MENU: " << endl;
	cout << "	1: Add a Show " << endl;
	cout << "	2: Remove a Show " << endl;
	cout << "	3: Display number of Shows " << endl;
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
	Shelf shelf;
	int option;
	Show *show = NULL;
	string x, title, description, director;
	int year;
	do {
		option = getMenuOption();
		switch (option) {
		case 1: //Add
			cout << "ADD A SHOW:" << endl;
			getline(cin, x);
			cout << "	Enter Title: ";
			getline(cin, title);
			cout << "	Enter Description: ";
			getline(cin, description);
			cout << "	Enter Director: ";
			getline(cin, director);
			cout << "	Enter Year: ";
			cin >> year;
			try {
				show = new Show(title, description, director, year);
				shelf.addShow(*show);
			}
			catch (Shelf::ShelfOverflow e) {
				cout << "CAUGHT EXCEPTION: " << endl;
				e.error();
			}
			break;
		case 2: //Remove
			cout << "REMOVE A SHOW" << endl;
			try {
				*show = shelf.removeShow();
				cout << "Removed Show:" << endl;
				show->details();
			}
			catch (Shelf::ShelfUnderflow e) {
				cout << "CAUGHT EXCEPTION: " << endl;
				e.error();
			}
			break;
		case 3: //Get current number of shows
			cout << "DISPLAY CURRENT NUMBER OF SHOWS" << endl;
			cout << "	Number of shows on shelf: " << shelf.getNumShows() << endl;
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