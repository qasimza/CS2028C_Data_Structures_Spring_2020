#include "TVShow.h"


//Default Constructor

TVShow::TVShow():Show() {
	numSeasons = 0;
	numEpisodes = 0;
	episodeList[0][0] = "None";
}


//Parameterized Constructor

TVShow::TVShow(string tvTitle, string tvDescription, string tvDirector, int tvYear, string tvPtr[MAX_SEASONS][MAX_EPISODES], int tvSeasons, int tvEpisodes):Show(tvTitle, tvDescription, tvDirector, tvYear) {
	if (tvSeasons > MAX_SEASONS) {
		numSeasons = MAX_SEASONS;
	}
	else if (tvSeasons < 0) {
		numSeasons = 0;
	}
	else {
		numSeasons = tvSeasons;
	}
	if (tvEpisodes > MAX_EPISODES) {
		numEpisodes = MAX_EPISODES;
	}
	else if (tvEpisodes < 0) {
		numEpisodes = 0;
	}
	else {
		numEpisodes = tvEpisodes;
	}

	for (int i = 0; i < numSeasons; i++) {
		for (int j = 0; j < numEpisodes; j++) {
			episodeList[i][j] = tvPtr[i][j];
		}
	}
}


//Getters

string * TVShow::getEpisodeList() {
	string *ptr;
	ptr = &episodeList[0][0];
	return ptr;
}


int TVShow::getNumSeasons() {
	return numSeasons;
}

int TVShow::getNumEpisodes() {
	return numEpisodes;
}


//Setters

void TVShow::setEpisodeList(string tvPtr[MAX_SEASONS][MAX_EPISODES], int tvSeasons, int tvEpisodes) {
	if (tvSeasons > MAX_SEASONS) {
		numSeasons = MAX_SEASONS;
	}
	else if (tvSeasons < 0) {
		numSeasons = 0;
	}
	else {
		numSeasons = tvSeasons;
	}
	if (tvEpisodes > MAX_EPISODES) {
		numEpisodes = MAX_EPISODES;
	}
	else if (tvEpisodes < 0) {
		numEpisodes = 0;
	}
	else {
		numEpisodes = tvEpisodes;
	}

	for (int i = 0; i < numSeasons; i++) {
		for (int j = 0; j < numEpisodes; j++) {
			episodeList[i][j] = tvPtr[i][j];
		}
	}
}


void TVShow::setNumSeasons(int tvSeasons) {
	if (tvSeasons > MAX_SEASONS) {
		numSeasons = MAX_SEASONS;
	}
	else if (tvSeasons < 0) {
		numSeasons = 0;
	}
	else {
		numSeasons = tvSeasons;
	}
}

void TVShow::setNumEpisodes(int tvEpisodes) {
	if (tvEpisodes > MAX_EPISODES) {
		numEpisodes = MAX_EPISODES;
	}
	else if (tvEpisodes < 0) {
		numEpisodes = 0;
	}
	else {
		numEpisodes = tvEpisodes;
	}
}


//Other functions

void TVShow::play() {
	if (numSeasons == 0) {
		cout << "No seasons or episodes to display. " << endl;
	}
	else if (numEpisodes == 0) {
		cout << "Seasons exist, however no epiosdes defined. " << endl;
	}
	else {
		int seasonSelection;
		cout << "Enter season(1-" << numSeasons << "): ";
		cin >> seasonSelection;
		cout << endl;
		while (seasonSelection < 1 || seasonSelection > numSeasons) {
			cout << "ERROR: Season does not exist. Please select a season (1-" << numSeasons << "): ";
			cin >> seasonSelection;
			cout << endl;
		}
		cout << "Season " << seasonSelection << "Episode List: " << endl;
		for (int i = 0; i < numEpisodes; i++) {
			cout << "Episode " << i + 1 << ": " << episodeList[seasonSelection][i] << endl;
		}
	}
}

void TVShow::details() {
	cout << "Title:" << getTitle() << endl;
	cout << "Description: " << endl << getDescription() << endl;
	cout << "Director: " + getDirector() << endl;
	cout << "Release Year: " + getYear() << endl;
	cout << "Number of seasons: " << numSeasons << endl;
}
