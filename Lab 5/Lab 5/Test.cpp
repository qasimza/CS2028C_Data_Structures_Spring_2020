#include <iostream>
#include "ShelfOfGames.h"

using namespace std;

int getMenuOption() {
	//moditfy this based on task 2

	int input = -1;
	bool inputCheck = false;

	cout << "Please enter the corresponding number for the desired instance: " << endl;
	cout << "	1: Show " << endl;
	cout << "	2: Movie " << endl;
	cout << "	3: TV Show " << endl;
	cout << "	4: Movie declared as Show " << endl;
	cout << "	5: TV Show declared as Show " << endl;
	cout << "	6: Quit Program " << endl;
	cout << endl << "Enter Choice (1-6): ";
	cin >> input;
	cout << endl;
	while (cin.fail() || input < 1 || input > 6) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid input(1-6): ";
		cin >> input;
		cout << endl;
	}
	return input;
}


int main() {
	ShelfOfGames shelf;
	int option;
	do {
		option = getMenuOption();
		switch (option) {
		case 1:
			//Add
			break;
		case 2:
			//Remove
			break;
		case 3:
			//Get current number of boards
			break;
		case 4:
			cout << "You selected 4. Quitting program" << endl;
		default:
			cout << "CRITICAL ERROR: This should not be happening!" << endl;
		}
	} while (option != 4);