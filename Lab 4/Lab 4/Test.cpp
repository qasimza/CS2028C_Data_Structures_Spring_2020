# include <iostream>
# include <string>
#include "Show.h"
#include "Movie.h"
#include "TVShow.h"

using namespace std;

void callFunctions(Show s) {
	cout << "DETAILS: " << endl;
	s.details();
	cout << "PLAY: " << endl;
	s.play();
}


int getMenuOption() {
	
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

	int year, selection;
	string title, description, director;
	char pConstructorFlag;
	string x;
	do {
		
		selection = getMenuOption();
		
		if (selection != 6) {
			getline(cin, title);
			cout << "Use parameterized constructor? (Enter y for yes):";
			cin >> pConstructorFlag;
			getline(cin, x);

			if (pConstructorFlag == 'y') {
				cout << "Enter Title: ";
				getline(cin, title);
				cout << "Enter Description: ";
				getline(cin, description);
				cout << "Enter Director: ";
				getline(cin, director);
				cout << "Enter Release Year: ";
				cin >> year;
			}

			//Show
			if (selection == 1) {
				if (pConstructorFlag == 'y') {
					Show show(title, description, director, year);
					cout << endl << "Calling play and details fuction for Show object (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					show.details();
					cout << "PLAY: " << endl;
					show.play();
					cout << endl << "Calling function outside class (Task 3.1.c):" << endl;
					callFunctions(show);
				}
				else {
					Show show;
					cout << endl << "Calling play and details fuction for Show object (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					show.details();
					cout << "PLAY: " << endl;
					show.play();
					cout << endl << "Calling function outside class (Task 3.1.c): " << endl;
					callFunctions(show);
				}
				
			}
			//Movie
			else if (selection == 2) {
				if (pConstructorFlag == 'y') {
					cout << "Enter number of credits (0-100): ";
					int numCredits;
					cin >> numCredits;
					getline(cin, x);
					if (numCredits < 0){
						cout << "ERROR: Invalid number of credits. Setting number of credits to 0" << endl;
						numCredits = 0;
					}
					else if (numCredits > 100) {
						cout << "ERROR: Invalid number of credits. Setting number of credits to 100 (max limit)" << endl;
						numCredits = 100;
					}
					string *ptr;
					string credits[100];
					ptr = &credits[0];
					for (int i = 0; i < numCredits; i++) {
						cout << "Enter credit " << i + 1 << ": ";
						getline(cin, credits[i]);
					}
					Movie movie(title, description, director, year, ptr, numCredits);
					cout << endl << "Calling play and details fuction for Movie object (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					movie.details();
					cout << "PLAY: " << endl;
					movie.play();
					cout << endl << "Calling function outside class (Task 3.1.c):" << endl;
					callFunctions(movie);
				}
				else {
					Movie movie;
					cout << endl << "Calling play and details fuction for Movie object (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					movie.details();
					cout << "PLAY: " << endl;
					movie.play();
					cout << endl << "Calling function outside class (Task 3.1.c):" << endl;
					callFunctions(movie);
				}
			}
			//TV Show
			else if (selection == 3) {
				if (pConstructorFlag == 'y') {
					cout << "Enter number of seasons (0-20): " << endl;
					int numSeasons;
					cin >> numSeasons;
					if (numSeasons < 0) {
						cout << "ERROR: Invalid number of seasons. Setting number of seasons to 0" << endl;
						numSeasons = 0;
					}
					else if (numSeasons > 20) {
						cout << "ERROR: Invalid number of seasons. Setting number of seasons to 20 (max limit)" << endl;
						numSeasons = 20;
					}
					cout << "Enter number of episodes (0-20)" << endl;
					int numEpisodes;
					cin >> numEpisodes;
					if (numEpisodes < 0) {
						cout << "ERROR: Invalid number of episodes. Setting number of episodes to 0" << endl;
						numEpisodes = 0;
					}
					else if (numEpisodes > 100) {
						cout << "ERROR: Invalid number of episodes. Setting number of episodes to 100 (max limit)" << endl;
						numEpisodes = 100;
					}
					string episodeList[20][100];
					if (numSeasons == 0) {
						cout << "There are 0 seasons. Cannot accept episodes" << endl;
					}

					else {
						getline(cin, x);
						for (int i = 0; i < numSeasons; i++) {
							cout << "Enter episodes for Season " << i + 1 << ": " << endl;
							for (int j = 0; j < numEpisodes; j++) {
								cout << "Enter episode " << j + 1 << ": ";
								getline(cin, episodeList[i][j]);
							}
						}
					}
					TVShow tvShow(title, description, director, year, episodeList, numSeasons, numEpisodes);
					cout << endl << "Calling play and details fuction for Movie object (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					tvShow.details();
					cout << "PLAY: " << endl;
					tvShow.play();
					cout << endl << "Calling function outside class (Task 3.1.c): " << endl;
					callFunctions(tvShow);
				}
				else {
					TVShow tvShow;
					cout << endl << "Calling play and details fuction for TVShow object (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					tvShow.details();
					cout << "PLAY: " << endl;
					tvShow.play();
					cout << endl << "Calling function outside class (Task 3.1.c): " << endl;
					callFunctions(tvShow);
				}
			}
			//Moivie declared as Show
			else if (selection == 4) {
				if (pConstructorFlag == 'y') {
					cout << "Enter number of credits (0-100): ";
					int num_credits;
					cin >> num_credits;
					if (num_credits < 0) {
						cout << "ERROR: Invalid number of credits. Setting number of credits to 0" << endl;
						num_credits = 0;
					}
					else if (num_credits > 100) {
						cout << "ERROR: Invalid number of credits. Setting number of credits to 100 (max limit)" << endl;
						num_credits = 100;
					}
					string *ptr;
					string credits[100];
					ptr = &credits[0];
					getline(cin, x);
					for (int i = 0; i < num_credits; i++) {
						cout << "Enter credit: " << i + 1 << ": ";
						getline(cin, credits[i]);
					}
					Show *movie = new Movie(title, description, director, year, ptr, num_credits);
					cout << endl << "Calling play and details fuction for Movie object (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					movie->details();
					cout << "PLAY: " << endl;
					movie->play();
					cout << endl << "Calling function outside class (Task 3.1.c): " << endl;
					callFunctions(*movie);
				}
				else {
					Show *movie = new Movie;
					cout << endl << "Calling play and details fuction for Movie object declared as Show (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					movie->details();
					cout << "PLAY: " << endl;
					movie->play();
					cout << endl << "Calling function outside class (Task 3.1.c): " << endl;
					callFunctions(*movie);
				}
			}
			//TV Show Declared as show
			else if (selection == 5) {
				if (pConstructorFlag == 'y') {
					cout << "Enter number of seasons (0-20): ";
					int numSeasons;
					cin >> numSeasons;
					if (numSeasons < 0) {
						cout << "ERROR: Invalid number of seasons. Setting number of seasons to 0" << endl;
						numSeasons = 0;
					}
					else if (numSeasons > 20) {
						cout << "ERROR: Invalid number of seasons. Setting number of seasons to 20 (max limit)" << endl;
						numSeasons = 20;
					}
					cout << "Enter number of episodes (0-20): ";
					int numEpisodes;
					cin >> numEpisodes;
					if (numEpisodes < 0) {
						cout << "ERROR: Invalid number of episodes. Setting number of episodes to 0" << endl;
						numEpisodes = 0;
					}
					else if (numEpisodes > 100) {
						cout << "ERROR: Invalid number of episodes. Setting number of episodes to 100 (max limit)" << endl;
						numEpisodes = 100;
					}
					string episodeList[20][100];
					if (numSeasons == 0) {
						cout << "There are 0 seasons. Cannot accept episodes" << endl;
					}
					else {
						getline(cin, x);
						for (int i = 0; i < numSeasons; i++) {
							cout << "Enter episodes for Season " << i + 1 << ": " << endl;
							for (int j = 0; j < numEpisodes; j++) {
								cout << "Enter episode " << j + 1 << ": ";
								getline(cin, episodeList[i][j]);
							}
						}
					}
					Show *tvShow = new TVShow(title, description, director, year, episodeList, numSeasons, numEpisodes);
					cout << endl << "Calling play and details fuction for Movie object (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					tvShow->details();
					cout << "PLAY: " << endl;
					tvShow->play();
					cout << endl << "Calling function outside class (Task 3.1.c): " << endl;
					callFunctions(*tvShow);

				}
				else {
					Show *tvShow = new TVShow;
					cout << endl << "Calling play and details fuction for TVShow object declared as Show (Task 3.1.b):" << endl;
					cout << "DETAILS: " << endl;
					tvShow->details();
					cout << "PLAY: " << endl;
					tvShow->play();
					cout << endl << "Calling function outside class (Task 3.1.c): " << endl;
					callFunctions(*tvShow);
				}
			}
			//Default output
			else {
				cout << "CRITICAL ERROR: This should not happen!" << endl;
			}
		}
		else {
			cout << "You selected 6. Quitting program..." << endl;
		}
		cout << "\n--------------------------------------------------\n";
	}while (selection!=6);
	return 0;
}