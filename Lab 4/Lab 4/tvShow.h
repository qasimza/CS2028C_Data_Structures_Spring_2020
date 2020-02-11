#pragma once
#include "Show.h"

class TVShow : public Show{
	
	string **episodeList;

public:

	//Constructors
	TVShow();
	TVShow(string, string, string, int, string **);

	//Getter
	string ** getEpisodeList();

	//Setter
	void setEpisodeList(string **);

	//Other functions
	void play();
	void details();
};