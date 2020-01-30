#include <iostream>
#include <string>


using namespace std;

struct Book {
	string title;
	string author;
	int wordCount;
	int letterFrequency[26]; // should this be an array?
	int lineCount;
	void displayBook(){
		//Refer Homework1, requirement 4
	}
	void displayLetterFrequency() {
		//Refer Homework2, requirement 5
	}
};


void saveBook(Book book) {
	// Refer Homework1, requirement 
}


bool getQuitFlag() {
	/*
	Detrmines whether the user wants to quit the program
	Retruns boolean true if the user wants to quit and false if the user does not want to quit
	*/
	char quitChar = '*';
	cout << "Do you wish to process another book?(y/n) " << endl;
	cin >> quitChar;
	while (quitChar != 'y' && quitChar != 'n') {
		cout << "ERROR: Incorrect option. Press y to process another book, n to quit." << endl;
		cin >> quitChar;
	}
	if (quitChar == 'n') {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	string fileName;
	do {
		cout << "Provide file name for processing." << endl;
		cin >> fileName;
		// read file 
		// create book object
		// save to CardCatalog.txt
		// ask user if they want to see letter frequency
		//get quit flag will take care of processing another book
	}while (!getQuitFlag());