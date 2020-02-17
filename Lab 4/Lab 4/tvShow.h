#pragma once
#include "Show.h"

class TVShow : public Show{
	const static int MAX_SEASONS = 20;
	const static int MAX_EPISODES = 100;
	int numSeasons;
	int numEpisodes;
	string episodeList[MAX_SEASONS][MAX_EPISODES];

public:

	//Constructors
	TVShow();
	TVShow(string, string, string, int, string [MAX_SEASONS][MAX_EPISODES], int, int);

	//Getters
	string * getEpisodeList();
	int getNumSeasons();
	int getNumEpisodes();

	//Setters
	void setEpisodeList(string[MAX_SEASONS][MAX_EPISODES], int, int);
	void setNumSeasons(int);
	void setNumEpisodes(int);

	//Other functions
	void play();
	void details();
};