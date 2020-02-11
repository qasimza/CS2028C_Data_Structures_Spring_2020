#include "TVShow.h"


//Default Constructor

TVShow::TVShow():Show() {
	episodeList = NULL;
}


//Parameterized Constructor

TVShow::TVShow(string tvTitle, string tvDescription, string tvDirector, int tvYear, string **tvPtr):Show(tvTitle, tvDescription, tvDirector, tvYear) {
	episodeList = tvPtr;
}


//Getter

string ** TVShow::getEpisodeList() {
	return episodeList;
}


//Setter

void TVShow::setEpisodeList(string ** tvPtr) {
	episodeList = tvPtr;
}


//Other functions

void TVShow::play() {
	unsigned int seasonNum; 
	cout << "Enter the season number: ";
	cin >> seasonNum;
	cout << endl;
	while (seasonNum < 1 || seasonNum > sizeof(&episodeList) / sizeof(&episodeList[0])) {
		cout << "Season does not exist. This series has " << sizeof(&episodeList) / sizeof(&episodeList[0]) << " season(s)." << endl;
		cout << "Enter the season number: ";
		cin >> seasonNum;
		cout << endl;
	}
	cout << "Season: " << seasonNum;
	for (int i = 0; i < sizeof(&episodeList[seasonNum]); i++) {
		cout << "Episode " << i << ": " << &episodeList[seasonNum][i] << endl;
	}
}

void TVShow::details() {
	cout << "Title:" << getTitle() << endl;
	cout << "Description: " << endl << getDescription() << endl;
	cout << "Director: " + getDirector() << endl;
	cout << "Release Year: " + getYear() << endl;
	cout << "Number of seasons: " << sizeof(&episodeList) / sizeof(&episodeList[0]) << endl;
}

