#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct Book {
	string title;
	string author;
	int wordCount;
	int letterCount;
	int letterFrequency[26];
	int lineCount;
	Book();
	void calculateLetterFrequency(string bookText);
	void calculateWordCount(string bookText);
	void displayLetterFrequency();
};

Book::Book() {
	title = "undefined";
	author = "undefined";
	wordCount = 0;
	letterCount = 0;
	for (int i = 0; i < 26; i++) {
		letterFrequency[i] = 0;
	}
	lineCount = 0;
}

//this function calculates the number of words there are in the file
void Book::calculateWordCount(string bookText) {
	if (bookText.length() > 0) {
		wordCount++;
	}
	for (int i = 0; i < bookText.length(); i++) {
		if (int(bookText[i]) == char(32)) {
			if (i != bookText.length() - 1 && int(bookText[i + 1]) != char(32)){
				wordCount++;
			}
		}
	}
}

//this function calculates the frequency of each letter in the file
void Book::calculateLetterFrequency(string bookText) {
	int index_val;
	for (int i = 0; i < bookText.length(); i++) {
		index_val = int(tolower(bookText[i])) - 97;
		if (index_val >= 0 && index_val < 26) {
			letterFrequency[index_val]++;
		}
	}
}

//this function displays the frequency of each letter in the file as a percentage value
void Book::displayLetterFrequency() {
	int letterCount = 0, i;
	for (i = 0; i < 26; i++) {
		letterCount += letterFrequency[i];
	}
	for (int i = 0; i < 26; i++) {
		cout << char(i + 97) << ": " << double(letterFrequency[i]) * 100 / double(letterCount) << "%" << endl;
	}
}

/*
Detrmines whether the user wants to quit the program
Retruns boolean true if the user wants to quit and false if the user does not want to quit
*/
bool getQuitFlag() {
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

void saveBook(Book book) {
	fstream outFile;
	outFile.open("CardCatalog.txt", ios::app);
	cout << "Saving data to file: CardCatalog.txt" << endl;
	outFile << "Title: " + book.title + "\n";
	outFile << "Full Author: " + book.author + "\n";
	string firstName = book.author.substr(0, book.author.find(" "));
	string lastName = book.author.substr(book.author.rfind(" ") + 1, book.author.size());
	outFile << "Author First Name: " + firstName + "\n";
	outFile << "Author Last Name: " + lastName + "\n";
	outFile << "Word count: " + to_string(book.wordCount) + "\n";
	outFile << "Line Count: " + to_string(book.lineCount) + "\n";
	outFile << "\n";
	outFile.close();
}

int main() {

	string fileName;
	string contentsString;
	string seeFrequencyflag;
	string lineString;
	int length = 0;
	bool contentsFlag = false;

	do {

		cout << "Provide file name for processing: ";
		cin >> fileName;
		cout << endl;

		//Creating ifstream object
		ifstream bookFile;

		//Checking for a valid input File name
		while (true) {
			bookFile.open(fileName, ios::in);
			if (bookFile.is_open()){
				break;
			}else{
				cout << "Please enter a valid file name: ";
				cin >> fileName;
				cout << endl;
			}
		}

		//Create book object
		Book bookObj;

		// The while loop is reading line by line and adding each line to a string that contains the entire text file.
		while (!bookFile.eof()) {
			getline(bookFile, lineString);
			if (bookObj.title == "undefined" && lineString.length() > 0) {
			//Finding title 
			bookObj.title = lineString;
			}
			else if (bookObj.author == "undefined" && lineString.length() > 0) {
				//Finding author
				bookObj.author = lineString;
			}
			else if (contentsFlag) {
				//Finding Line Count (in contents section)
				bookObj.lineCount++;
				//Finding Letter Frequency (in contents section)
				bookObj.calculateLetterFrequency(lineString);
				//Finding Word Count (in contents section)
				bookObj.calculateWordCount(lineString);
			}
			else if (lineString.find("Contents:") != string::npos) {
				contentsFlag = true;
			}
			else {
				cout << "Blank line before contents section (omitted for calculation) " << lineString << endl;
			}
		}

		//Saving book to CardCatalog.txt
		saveBook(bookObj);

		cout << "Do you wish to see the letter frequency (y/n): ";
		cin >> seeFrequencyflag;
		cout << endl;
		while (seeFrequencyflag != "y" && seeFrequencyflag != "n") {
			cout << "ERROR: Incorrect selection. Press y for yes/n for no: ";
			cin >> seeFrequencyflag;
			cout << endl;
		}
		if (seeFrequencyflag == "y") {
			bookObj.displayLetterFrequency();
		}
	
		bookFile.close();
	} while (!getQuitFlag());

}