#include <iostream>
#include <string>
#include <fstream>

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
	for (int i = 0; i < bookText.size; i++) {
		if (int(bookText[i]) == char(32)) {
			if (i != bookText.size - 1 && int(bookText[i + 1]) != char(32)){
				wordCount++;
			}
		}
	}
}

//this function calculates the frequency of each letter in the file
void Book::calculateLetterFrequency(string bookText) {
	int index_val;
	for (int i = 0; i < bookText.size; i++) {
		index_val = int(tolower(bookText[i])) - 97;
		if (index_val >= 0 || index_val < 26) {
			letterFrequency[index_val]++;
		}
	}
}

//this function displays the frequency of each letter in the file as a percentage value
void Book::displayLetterFrequency() {
	int lineCount = 0, i;
	for (i = 0; i < 26; i++) {
		lineCount += letterFrequency[i];
	}
	for (int i = 0; i < 26; i++) {
		cout << char(i + 97) << ": " << letterFrequency[i] / letterCount << "%" << endl;
	}
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

void saveBook(Book book) {
	fstream outFile;
	outFile.open("CardCatalog.txt", ios::app);
	cout << "Saving data to file: CardCatalog.txt" << endl;
	outFile << "Title: " + book.title + "\n";
	outFile << "Full Author: " + book.author + "\n";
	string firstName = book.author.substr(0, book.author.find(" "));
	string lastName = book.author.substr(book.author.rfind(" ") + 1, book.author.size());
	outFile << "Author First Name: " + firstName + "\n";
	outFile << "Author Last Name: " + firstName + "\n";
	outFile << "Word count: " + to_string(book.wordCount) + "\n";
	outFile << "Line Count: " + to_string(book.lineCount) + "\n";
	outFile << "\n";
	outFile.close();
}

void findTitleAndAuthor(Book book_OBJ, ifstream bookFile) {
	bookFile.seekg(0, ios::beg);
	getline(bookFile, book_OBJ.title);
	getline(bookFile, book_OBJ.author);
}

int main() {

	string fileName;
	string bookString;
	string letterFreqRet;
	string lineString;
	int length = 0;
	int lineCount = 0;
	ifstream bookFile;

	do {
		cout << "Provide file name for processing: " << endl;
		cin >> fileName;

		//Checking for a valid input File name
		while (true) {
			try {
				bookFile.open(fileName, ios::in);
				break;
			}
			catch(exception e) {
				cout << "Please enter a valid file name: ";
				cin >> fileName;
				cout << endl;
			}
		}
		// create book object
		Book book_OBJ;

		// The while loop is reading line by line and adding each line to a string that contains the entire text file.
		
		while (!bookFile.eof) {
			getline(bookFile, lineString);
			book_OBJ.lineCount++;
			bookString += " " + lineString;
		}

		//Finding title and author
		findTitleAndAuthor(book_OBJ, bookFile);
		//Finding Word Count
		book_OBJ.calculateWordCount(bookString);
		//Finding Line Count 
		book_OBJ.lineCount = lineCount;
		//Finding Letter Frequency
		book_OBJ.calculateLetterFrequency(bookString);
		//Saving book to CardCatalog.txt
		saveBook(book_OBJ);

		cout << "Do you wish to see the letter frequency (yes/no): ";
		cin >> letterFreqRet;
		cout << endl;
		if (letterFreqRet == "yes") {
			book_OBJ.displayLetterFrequency();
		}
		//get quit flag will take care of processing another book
	} while (!getQuitFlag());

	bookFile.close();

}